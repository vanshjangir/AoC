#include <stdio.h>
#include "read.h"
#define ll long long

int main(){
    FILE *fp;
    fp = fopen("input/inputday6.txt","r");

    char line[100];
    ll time;
    ll distance;
    ll lc;
    ll num;
    
    lc = -1;
    num=0;
    readfile(fp,line);
    while(line[++lc]!=':');
    while(line[++lc] != '\0'){
        if(line[lc]>=48 && line[lc] <= 58)
            num = num*10 +line[lc]-48;
    }
    time = num;
   
    lc = -1;
    num=0;
    readfile(fp,line);
    while(line[++lc]!=':');
    while(line[++lc] != '\0'){
        if(line[lc]>=48 && line[lc] <= 58)
            num = num*10 +line[lc]-48;
    }
    distance = num;


    ll ans=0;
    for(ll j=14; j<=time; j++){
        if(j*(time-j) > distance){
            ans++;
        }
    }
    printf("%lld", ans);

}
