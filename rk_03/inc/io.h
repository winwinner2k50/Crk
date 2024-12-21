#include "struct.h"
#include <stddef.h>

int name_input(struct name **a, size_t *n, char file_name[]);
int name_sort(struct name **a, size_t n);
int name_output_file(name *a, size_t n, char file_name[]); 
int name_count(struct name **a, size_t n); 
int names_dell(struct name **a, size_t *n);