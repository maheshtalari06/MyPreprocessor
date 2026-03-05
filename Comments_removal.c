#include<stdio.h>
#include<string.h>
void removal_comments(FILE *in,FILE *out)
{
        char line[1024],*ptr;
        while(fgets(line,sizeof(line),in))
        {
                if(ptr=strstr(line,"//"))
                {
                        *ptr='\0';
                }
                if(ptr=strstr(line,"/*"))
                {
                        *ptr='\0';
                        while(!strstr(line, "*/"))
                        {
                                fgets(line,sizeof(line),in);
                        }
                }
                else
                {
                        fputs(line,out);
                }
        }
}
