#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "macro_handler.h"

#define MAX_MACROS 100

typedef struct
{
    char name[100];
    char value[500];
} Macro;

Macro macros[MAX_MACROS];
int macro_count = 0;

void substitute_macros(char *line)
{
    for (int i = 0; i < macro_count; i++)
    {
        char *pos;
        while ((pos = strstr(line, macros[i].name)))
        {
            char temp[1024];
            strcpy(temp, pos + strlen(macros[i].name));
            *pos = '\0';
            strcat(line, macros[i].value);
            strcat(line, temp);
            printf("%d\n",pos);
        }
    }
}

void process_macros(FILE *input, FILE *output)
{
    char line[1024];

    while (fgets(line, sizeof(line), input))
    {
        if (strncmp(line, "#define", 7) == 0)
        {
            sscanf(line, "#define %s %[^\n]",
                   macros[macro_count].name,
                   macros[macro_count].value);
            macro_count++;
        }
        else
        {
            substitute_macros(line);
            fputs(line, output);
        }
    }
}
