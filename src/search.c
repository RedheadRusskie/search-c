#define _POSIX_C_SOURCE 200809L
#include "search.h"

#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "util.h"

static void recurse_directory(const char* directory_path,
                              const char* search_name,
                              search_kind_t search_kind);

void search_directory_recursively(const char* root_directory_path,
                                  const char* search_name,
                                  search_kind_t search_kind) {
  recurse_directory(root_directory_path, search_name, search_kind);
}

static void recurse_directory(const char* directory_path,
                              const char* search_name,
                              search_kind_t search_kind) {
  DIR* directory_handle = opendir(directory_path);

  if (!directory_handle) {
    fprintf(stderr, "opendir('%s') failed: %s\n", directory_path,
            strerror(errno));

    return;
  }

  struct dirent* directory_entry;

  while ((directory_entry = readdir(directory_handle)) != NULL) {
    const char* entry_name = directory_entry->d_name;

    if (strcmp(entry_name, ".") == 0 || strcmp(entry_name, "..") == 0) continue;

    char full_entry_path[PATH_MAX];

    if (!build_joined_path(full_entry_path, sizeof(full_entry_path),
                           directory_path, entry_name))
      continue;

    struct stat entry_stat;

    if (lstat(full_entry_path, &entry_stat) == -1) continue;

    if (S_ISREG(entry_stat.st_mode)) {
      if (search_kind != SEARCH_KIND_FILE) continue;

      if (!names_equal_case_insensitive(entry_name, search_name)) continue;

      printf("[FILE] %s\n", full_entry_path);

      continue;
    }

    if (S_ISDIR(entry_stat.st_mode)) {
      if (search_kind == SEARCH_KIND_DIRECTORY &&
          names_equal_case_insensitive(entry_name, search_name)) {
        printf("[DIR]  %s\n", full_entry_path);
      }

      if (S_ISLNK(entry_stat.st_mode)) continue;

      recurse_directory(full_entry_path, search_name, search_kind);
    }
  }

  closedir(directory_handle);
}
