#ifndef SEARCH_H
#define SEARCH_H

typedef enum { SEARCH_KIND_FILE, SEARCH_KIND_DIRECTORY } search_kind_t;

/* Search recursively starting at root_directory_path for entries named
 * search_name. Prints matches prefixed with "[FILE]" or "[DIR]".
 * Case-insensitive match.
 */
void search_directory_recursively(const char* root_directory_path,
                                  const char* search_name,
                                  search_kind_t search_kind);

#endif