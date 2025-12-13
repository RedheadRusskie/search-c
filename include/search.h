#ifndef SEARCH_H
#define SEARCH_H

typedef enum { SEARCH_KIND_FILE, SEARCH_KIND_DIRECTORY } search_kind_t;

void search_directory_recursively(const char* root_directory_path,
                                  const char* search_name,
                                  search_kind_t search_kind);

#endif  // SEARCH_H
