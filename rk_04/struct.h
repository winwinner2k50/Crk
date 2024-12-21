#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#ifndef WORD_STRUCT_H
#define WORD_STRUCT_H

struct Node
{
  char *s;
  struct Node *next;
};

typedef struct words
{
  struct Node *first;
  size_t count;
} words;

#endif