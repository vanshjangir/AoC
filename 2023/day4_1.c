#include <stdio.h>
#include "read.h"
#define M 208

int main(){
    FILE *fp;
    int total = 0;
    char line[300];
    fp = fopen("input/inputday4.txt","r");
    for(int i=0; i<M; i++){
        readfile(fp,line);
    
        int j=-1;
        int sum=1;
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

        for(int l=0;l<nw; l++){
            for(int k=0; k<nyh; k++){
                if(y[k] == w[l]){
                    sum *= 2;
                }
            }
        }
        total += sum/2;
        

    }
    printf("%d",total);

}
