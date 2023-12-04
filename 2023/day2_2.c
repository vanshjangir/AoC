#include <stdio.h>
#include "read.h"

int main(){
    FILE *fp;
    fp = fopen("input/inputday2.txt", "r");

    long long ans=0;
    int i=0;
    while(i<100){
        char line[200];
        readfile(fp,line);

        int n;
        for(n=0; line[n] != '\0'; n++);

        int j=0;
        int red = 0;
        int green = 0;
        int blue = 0;
        while(1){
            if(line[j] == ':')
                break;
            ++j;
        }
        ++j;
        ++j;

        while(j<n){

            int num = 0;
            while(1){
                if(line[j] == ' ')
                    break;
                num = num*10 +(line[j]-48);
                ++j;
            }
            ++j;

            if(line[j] == 'r'){
                red = red>num?red:num;
                j += 4;
            }
            else if(line[j] == 'b'){
                blue = blue>num?blue:num;
                j += 5;
            }
            else if(line[j] == 'g'){
                green = green>num?green:num;
                j += 6;
            }
            ++j;

        }
        ans += red*green*blue;
        i++;
    }

    printf("%lld", ans);
}
