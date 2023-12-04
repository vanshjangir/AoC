#include <stdio.h>
#include "read.h"
#define M 208 

int main(){
    FILE *fp;
    int total = 0;
    char line[300];
    int copy[300];
    int ori[300]={1};
    int nc=0;
    fp = fopen("input/inputday4.txt","r");
    for(int i=0; i<M; i++){
        readfile(fp,line);
    
        int j=-1;
        int sum=0;
        int nw=0, nyh=0;
        int w[200],y[200];
        while(line[++j] != ':');
        
        j++;
        int num=0;
        for(;line[j] != '|'; j++){
            if(line[j]>=48 && line[j]<=58){
                num = num*10+(line[j]-48);
            }else if(num != 0){
                w[nw++] = num;
                num=0;
            }
        }
        if(num != 0) w[nw++] = num;
        
        num = 0;        
        for(;line[j] != '\0'; j++){
            if(line[j]>=48 && line[j]<=58){
                num = num*10+(line[j]-48);
            }else if(num != 0){
                y[nyh++] = num;
                num=0;
            }
        }
        if(num != 0) y[nyh++] = num;

        for(int l=0;l<nw; l++)
            for(int k=0; k<nyh; k++)
                if(y[k] == w[l])
                    sum++;

        copy[nc++] = sum;

    }
    for(int i=0; i<nc; i++)
        ori[i] = 1;
    for(int i=0; i<nc; i++){
        for(int j=i+1; j<i+1+copy[i]; j++){
            ori[j]+=ori[i];            
        }
    }
    for(int i=0; i<nc; i++)
        total += ori[i];


    printf("%d",total);

}
