#include "struct.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void str_init(char *str) 
{
    size_t len = strcspn(str, "\n"); 
    str[len] = '\0';              
}

int strread(char **s, FILE *f)
{
    size_t len;
    if (getline(s, &len, f) == -1)
        return 1;
    // printf("%s\n", s);
    str_init(*s);
    return 0;
}

int name_output(name *a, size_t n)
{
    for (size_t i = 0; i < n; i++) 
        printf("%s\n", a[i].s); 
    return 0;
}


int name_input(name **a, size_t *n, char file_name[])
{
    FILE *f = fopen(file_name, "r");
    if (f == NULL)
       return 1;
    char *el = NULL;
    while(!strread(&el, f))
    {
        (*n)++;
        *a = realloc(*a, (*n) * sizeof(name));
        // printf("%s\n", el);
        (*a)[(*n) - 1].s = strdup(el);
        // printf("---\n");
        // name_output(*a, *n);
        // printf("%s\n", (*a)[(*n) - 1].s);
    }
    return 0;
}

void name_copy(name *a, name b)
{
    (*a).s = strdup(b.s);
    (*a).count = b.count;
}

void name_swap(name *a, name *b)
{
    name el;
    name_copy(&el, *a);
    name_copy(a, *b);
    name_copy(b, el);
}



int name_sort(struct name **a, size_t n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - 1 - i; j++)
        {
            // printf("-\n");
            // name_output(*a, n);
            if (strcmp((*a)[j].s, (*a)[j + 1].s) > 0)
            {
                name_swap(&(*a)[j], &(*a)[j + 1]);
            }
                
        }
    }
    return 0;
}

int name_count(struct name **a, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        (*a)[i].count = 0;
        for (size_t j = 0; j < n; j++)
        {
            if (strcmp((*a)[i].s, (*a)[j].s) == 0)
                (*a)[i].count++;
        }
    }
    return 0;
}

int name_dell(struct name **a, size_t *n, size_t pos)
{
    for (size_t i = pos; i < (*n) - 1; i++)
        name_swap(&(*a)[i], &(*a)[i + 1]);
    (*n)--;
    return 0;
}

int names_dell(struct name **a, size_t *n)
{
    for (size_t i = 0; i < *n; i++)
    {
        if ((*a)[i].count > 1)
        {
            for (size_t j = 0; j < *n; j++)
            {
                if (strcmp((*a)[i].s, (*a)[j].s) == 0)
                    name_dell(a, n, j);
            }
                
        }
    }
    return 0;
}


int name_output_file(name *a, size_t n, char file_name[])
{
    FILE *f = fopen(file_name, "w");
    if (f == NULL)
        return 1;

    for (size_t i = 0; i < n; i++)
        fprintf(f, "%s: %zu\n", a[i].s, a[i].count); 

    fclose(f);
    return 0;
}

int name_clear(name *a)
{
    free((*a).s);
    return 0;
}

void names_clear(name **a, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        name_clear(&(*a)[i]);
        free(&(*a)[i]);
    }
        
}