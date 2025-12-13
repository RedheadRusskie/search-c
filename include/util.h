#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stddef.h>

bool build_joined_path(char* output_buffer, size_t buffer_size,
                       const char* base_path, const char* child_name);

bool names_equal_case_insensitive(const char* a, const char* b);

/* Normalise an input path into output_buffer (absolute). Returns pointer to
 * buffer on success, otherwise copies input_path into buffer and returns
 * buffer.
 */
const char* normalize_path(const char* input_path, char* output_buffer,
                           size_t buffer_size);

#endif
