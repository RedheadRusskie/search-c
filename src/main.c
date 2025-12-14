#define _POSIX_C_SOURCE 200809L
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "search.h"
#include "util.h"

static void print_usage(const char* program_name) {
  fprintf(
      stderr,
      "Usage: %s -f <name> [start_path]\n"
      "       %s -d <name> [start_path]\n"
      "\nSearches recursively from start_path (default /) and prints matches "
      "with prefixes.\n",
      program_name, program_name);
}

int main(int argument_count, char** argument_values) {
  if (argument_count < 3) {
    print_usage(argument_values[0] ? argument_values[0] : "search");

    return 2;
  }

  search_kind_t search_kind;

  if (strcmp(argument_values[1], "-f") == 0) {
    search_kind = SEARCH_KIND_FILE;
  } else if (strcmp(argument_values[1], "-d") == 0) {
    search_kind = SEARCH_KIND_DIRECTORY;
  } else {
    print_usage(argument_values[0] ? argument_values[0] : "search");

    return 2;
  }

  const char* search_name = argument_values[2];
  const char* start_path_input =
      (argument_count >= 4) ? argument_values[3] : "/";
  char normalised_start[PATH_MAX];
  const char* root_directory_path = normalise_path(
      start_path_input, normalised_start, sizeof(normalised_start));

  struct stat stat_info;

  if (lstat(root_directory_path, &stat_info) == -1 ||
      !S_ISDIR(stat_info.st_mode)) {
    fprintf(stderr, "start path '%s' is not a directory or not accessible\n",
            root_directory_path);

    return 3;
  }

  search_directory_recursively(root_directory_path, search_name, search_kind);

  return 0;
}
