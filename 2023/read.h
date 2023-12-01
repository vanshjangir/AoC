#include<stdio.h>

void readfile(FILE*,char*);

void readfile(FILE *fp, char *line){
    int i=0;
    while(1){
        char ch = fgetc(fp);
        *(line+i) = ch;
        if(ch == '\n')
            break;
        i++;
    }
}
