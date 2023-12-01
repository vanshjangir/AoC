#include <stdio.h>

int main(){
    FILE  *fp;
    fp = fopen("inputday1.txt", "r");

    int ans = 0;
    int i = 0;
    while(i++<1000){
        char ch = ' ';
        char start = '\0';
        char last = '\0';

        while(1){
            ch = fgetc(fp);
            if(ch == '\n')
                break;
            if(ch <= 58 && ch >= 48){
                if(start == '\0'){
                    start = ch;
                }
                last = ch;
            }
        }

        ans += (start-48)*10 + (last-48);
        printf("%d ", ans);

    }
    printf("%d",ans);
}
