#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#ifndef NAME_STRUCT_H
#define NAME_STRUCT_H

typedef struct name
{
  char *s;
  size_t count;
} name;

#endif