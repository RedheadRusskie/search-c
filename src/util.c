#define _POSIX_C_SOURCE 200809L
#include "util.h"

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

bool build_joined_path(char* output_buffer, size_t buffer_size,
                       const char* base_path, const char* child_name) {
  if (!output_buffer || !base_path || !child_name) return false;

  int needed =
      snprintf(output_buffer, buffer_size, "%s/%s", base_path, child_name);

  if (needed < 0 || (size_t)needed >= buffer_size) return false;

  return true;
}

bool names_equal_case_insensitive(const char* a, const char* b) {
  if (!a || !b) return false;

  return strcasecmp(a, b) == 0;
}

const char* normalise_path(const char* input_path, char* output_buffer,
                           size_t buffer_size) {
  if (!input_path || !output_buffer || buffer_size == 0) return NULL;

  if (realpath(input_path, output_buffer) != NULL) return output_buffer;

  strncpy(output_buffer, input_path, buffer_size - 1);
  output_buffer[buffer_size - 1] = '\0';

  return output_buffer;
}
