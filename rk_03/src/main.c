#include "struct.h"
#include "io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

int main(void)
{
    name *a = NULL;
    size_t n = 0;
    name_input(&a, &n, "in.txt");
    name_sort(&a, n);
    name_count(&a, n);
    names_dell(&a, &n);
    name_output_file(a, n, "out.txt");
    // names_clear(&a, n);
    return 0;
}