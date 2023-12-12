#include <stdio.h>
#include "read.h"
#define ll long long

int main(){
    FILE *fp;
    fp = fopen("input/inputday6.txt","r");

    char line[100];
    ll time[10], ti=0;
    ll distance[10], di=0;
    ll lc=-1;
    ll num;
    
    lc = -1;
    num=0;
    readfile(fp,line);
    while(line[++lc] != ':');
    while(line[++lc] != '\0'){
        if(line[lc]>=48 && line[lc] <= 58)
            num = num*10 +line[lc]-48;
        else if(num!=0){
            time[ti++] = num;
            num=0;
        }
    }
    if(num!=0) time[ti++] = num;
   
    lc = -1;
    num=0;
    readfile(fp,line);
    while(line[++lc] != ':');
    while(line[++lc] != '\0'){
        if(line[lc]>=48 && line[lc] <= 58)
            num = num*10 +line[lc]-48;
        else if(num!=0){
            distance[di++] = num;
            num=0;
        }
    }
    if(num!=0) distance[di++] = num;


    ll ans=1;
    for(int i=0; i<ti; i++){
        ll count=0;
        for(int j=0; j<=time[i]; j++){
            if(j*(time[i]-j) > distance[i]){
                count++;
            }
        }
        if(count != 0) ans *= count;
    }

    printf("%lld", ans);

}
