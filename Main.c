#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"removal_comments.h"
#include"header_inclution.h"
#include"macro_handler.h"
#include"file_inclusion.h"
int main(int argc,char **argv)
{
        if(argc<2)
        {
                printf("./mypreprocessor filename.c");
                return 1;
        }
        char output_file[256];
        generate_output_filename(argv[1], output_file);

        char str[1024];
        FILE *in=fopen(argv[1],"r");
        FILE *t1=fopen("t1.txt","w+");
        FILE *t2=fopen("t2.txt","w+");
        if (in == NULL || t1 == NULL || t2 == NULL)
        {
                printf("File open error\n");
                printf("main");
                return 1;
        }
        removal_comments(in,t1);
        rewind(t1);
        header_inclution(t1,t2);
        rewind(t2);

        FILE *output = fopen(output_file, "w");
        process_macros(t2, output);


        while(fgets(str,sizeof(str),t2))
        printf("%s",str);

        fclose(in);
        fclose(t1);
        fclose(t2);
        fclose(output);
        return 0;
}
