#include <stdio.h>
#include <string.h>
void header_inclution(FILE *in, FILE *out)
{
    char line[256], fname[128],path[50];
    FILE *fp;
    int ch;
    while (fgets(line, sizeof(line), in))
    {

        if (sscanf(line, "#include <%[^>]>", fname) == 1)
        {
                strcpy(path,"/usr/include/");
                strcat(path,fname);
                printf("%s",path);
            fp = fopen(path,"r");
            if (fp == NULL)
            {
                printf("Cannot open file: %s\n", fname);
                continue;
            }

            while ((ch = fgetc(fp)) != EOF)
            {
                fputc(ch, out);
            }

            fclose(fp);
        }
        else
        {
            fputs(line, out);
        }
    }
}
