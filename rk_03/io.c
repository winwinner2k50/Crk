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
    str_init(*s);
    return 0;
}


int Nodes_file_input(struct Node **a, char file_name[])
{
    FILE *f = fopen(file_name, "r");
    if (f == NULL)
       return 1;
    char *str = NULL;
    *a = malloc(sizeof(struct Node));
    struct Node *el = *a;
    int ok = 0; 
    while(!strread(&str, f))
    {
        // printf("ok");   
        if (ok)
            el = el->next;
        else
            ok = 1;
        el->s = strdup(str);
        // printf("%s\n", el->s);
        el->next = malloc(sizeof(struct Node));
        
    }
    // printf("%sqqqq", a->s);
    el->next = NULL;
    return 0;
}




int words_output(struct Node *a, char file_name[])
{
    FILE *f = fopen(file_name, "w");
    if (f == NULL)
       return 1;
    struct Node *el = a;
    while(el)
    {
        fprintf(f, "%s\n", el->s);
        if (el->next != NULL)
            el = el->next;
        else
            break;
    }
    return 0;
}

int f(struct Node **a)
{
    struct Node *el = *a;
    while (el)
    {
        char *str = strdup(el->s);
        if (!str)
            return 1;
        char *word = strtok(str, " ");
        struct Node *next = el->next;

        struct Node *go = el;
        int ok = 0;
        if (strcmp(word, el->s) == 0) 
        {
            int n = 0;
            while (n < strlen(str))
            {
                if (n > 0) 
                {
                    go->next = malloc(sizeof(struct Node));
                    if (!go->next)
                    {
                        free(str);
                        return 1;
                    }
                    go = go->next;
                }
                go->s = malloc(2 * sizeof(char)); 
                if (!go->s)
                {
                    free(str);
                    return 1;
                }
                go->s[0] = str[n];
                go->s[1] = '\0';
                n++;
            }
        }
        else 
        {
            while (word != NULL)
            {
                if (ok)
                {
                    go->next = malloc(sizeof(struct Node));
                    if (!go->next)
                    {
                        free(str);
                        return 1;
                    }
                    go = go->next;
                }
                else
                    ok = 1;
                go->s = strdup(word);
                if (!go->s)
                {
                    free(str);
                    return 1;
                }
                word = strtok(NULL, " ");
            }
        }
        go->next = next;
        free(str);      
        el = next;      
    }
    return 0;
}

