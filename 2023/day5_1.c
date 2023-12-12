#include <stdio.h>
#include "read.h"
#define M 190
#define ll long long

int isnum(char x){
    if(x>=48 && x<=58)
        return 1;
    else 
        return 0;
}

int main(){

    FILE *fp;
    fp = fopen("input/inputday5.txt","r");

    char line[300];
    readfile(fp,line);
    ll lc = -1;
    ll num;
    ll seeds[100];
    ll si=0;

    while(line[++lc]!=':');
    lc++;
    
    num=0;
    while(line[++lc] != '\0'){
        if(isnum(line[lc]) == 1)
            num = num*10+line[lc]-48;
        else if(num != 0){
            seeds[si++] = num;
            num = 0;
        }
    }
    if(num != 0)seeds[si++]=num;

    readfile(fp,line);
    readfile(fp,line);
    ll c=3;
    ll fff[200];
    
    for(int i=0; i<si; i++)
        fff[i] = seeds[i];

    while(c++<M){
        readfile(fp,line);
        if(isnum(line[0]) == 0){
            readfile(fp,line);
            for(int i=0; i<si; i++)
                seeds[i] = fff[i];
            continue;
        }


        ll dsr[3],di=0;
        num=0;
        lc = -1;
        while(line[++lc] != '\0'){
            if(isnum(line[lc]) == 1)
                num = num*10+line[lc]-48;
            else{
                dsr[di++] = num;
                num = 0;
            }
        }
        if(num != 0)dsr[di++]=num;

        ll diff = dsr[0]-dsr[1];
        for(ll i=0; i<si; i++){
            if(seeds[i] >= dsr[1] && seeds[i]<dsr[1]+dsr[2])
                fff[i] = seeds[i]+diff;
        }

    }

    ll mm;
    ll f;
    for(int i=0; i<si; i++){
        f = fff[i];
        if(i==0)mm=f;
        if(mm>f)mm=f;
    }
    printf("%lld",mm);


}
