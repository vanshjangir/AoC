#include <stdio.h>
#include "read.h"
#define M 140

int isgear(char line[M][M], int i, int j, int aaaa[M][M]){
    int fff[8] = {0};
    int cnt=0;
    int ans = 1;
    if(i>0){
        if(line[i-1][j] <= 58 && line[i-1][j] >= 48){
            fff[1] = aaaa[i-1][j];
        }else{
            if(j>0) fff[0] = aaaa[i-1][j-1];
            if(j<M-1) fff[2] = aaaa[i-1][j+1];
        }
    }
    if(i<M-1){
        if(line[i+1][j] <= 58 && line[i+1][j] >= 48){
            fff[6] = aaaa[i+1][j];
        }else{
            if(j>0) fff[5] = aaaa[i+1][j-1];
            if(j<M-1) fff[7] = aaaa[i+1][j+1];
        }

    }
    if(j>0) fff[3]=aaaa[i][j-1];
    if(j<M-1) fff[4]=aaaa[i][j+1];

    for(int k=0; k<8; k++){
        if(fff[k] != 0) cnt++;
        else fff[k] = 1;
    }   
    
    if(cnt != 2) 
        return 0;

    for(int k=0; k<8; k++){
        printf("%d\t", fff[k]);
        ans *= fff[k];
    }
    printf("\n");
    return ans;

}

int main(){
    FILE *fp;
    char line[M][M];
    int aaaa[M][M] = {0};
    int ans = 0;

    fp = fopen("input/inputday3.txt", "r");

    for(int i=0; i<M; i++)
        readfile(fp,line[i]);
    

    for(int i=0; i<M; i++){
        int num = 0;
        int start=0;

        for(int j=0; j<M; j++){
            if(line[i][j]<=58 && line[i][j]>=48){
                start++; 
                num = num*10 +(line[i][j]-48);
            }
            else{
                if(num != 0)
                    for(int k=j-start; k<j; k++){
                        aaaa[i][k] = num;
                    }
                num = 0;
                start = 0;
            }
        }
        if(num != 0)
            for(int k=M-start; k<M; k++)
                aaaa[i][k] = num;
            
    }

    for(int i=0; i<M; i++)
        for(int j=0; j<M; j++)
            if(line[i][j] == '*')
                ans += isgear(line,i,j,aaaa); 

    printf("%d", ans);
}
