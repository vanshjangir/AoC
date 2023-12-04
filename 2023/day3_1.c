#include <stdio.h>
#include "read.h"

int isnear(char line[140][140], int i, int j){


    if(i>0 && (line[i-1][j] < 48 || line[i-1][j] > 58) && line[i-1][j] != '.')
        return 1;
    else if(i<139 && (line[i+1][j] < 48 || line[i+1][j] > 58) && line[i+1][j] != '.' )
        return 1;
    else if(j>0 && (line[i][j-1] < 48 || line[i][j-1] > 58) && line[i][j-1] != '.')
        return 1;
    else if(j<139 && (line[i][j+1] < 48 || line[i][j+1] > 58) && line[i][j+1] != '.')
        return 1;
    else if(i>0 && j>0 && (line[i-1][j-1] < 48 || line[i-1][j-1] > 58) && line[i-1][j-1] != '.')
        return 1;
    else if(i<139 && j<139 && (line[i+1][j+1] < 48 || line[i+1][j+1] > 58) && line[i+1][j+1] != '.')
        return 1;
    else if(i>0 && j<139 && (line[i-1][j+1] < 48 || line[i-1][j+1] > 58) && line[i-1][j+1] != '.')
        return 1;
    else if(i<139 && j>0 && (line[i+1][j-1] < 48 || line[i+1][j-1] > 58) && line[i+1][j-1] != '.')
        return 1;
    else 
        return 0;
}

int main(){
    FILE *fp;
    char line[140][140];
    int i = 0;
    int ans = 0;

    fp = fopen("input/inputday3.txt", "r");

    while(i<140){
        readfile(fp,line[i]);
        i++;
    }

    for(i=0; i<140; i++){
        int num = 0;
        int flag = 0;

        for(int j=0; j<140; j++){
            if(line[i][j] <=58 && line[i][j]>=48){
               num = num*10 +(line[i][j]-48);
               if(isnear(line,i,j) == 1){
                   flag = 1;
               }
            }
            else{
                if(flag == 1){
                    ans += num;
                    printf("%d ",num);
                }
                num = 0;
                flag = 0;
            }
        }
        if(flag == 1){
            ans += num;
        }

    }
    printf("%d", ans);
}
