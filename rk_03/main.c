#include "struct.h"
#include "io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

int main(void)
{
    struct Node *a;
    Nodes_file_input(&a, "in.txt");
    f(&a);
    words_output(a, "out.txt");
    return 0;
}