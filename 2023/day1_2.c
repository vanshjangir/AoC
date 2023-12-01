#include <stdio.h>

void checknum(char line[], int n){
    
    char nums[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char sss[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int aaa[10] = {4,3,3,5,4,4,3,5,5,4};

    for(int i=0; i<10; i++){
        int j=0;
        int k=n;
        int count=0;
        while(line[k]!='\n' && nums[i][j]!='\n'){
            if(line[k] == nums[i][j])
                count++;
            else
                break;
            k++;
            j++;
        }
        if(count == aaa[i]){
            line[n] = sss[i];
            return;
        }
    }
}


int main(){
    FILE  *fp;
    fp = fopen("inputday1.txt", "r");

    int ans = 0;
    int i = 0;
    while(i++<1000){
        char ch = ' ';
        char start = '\0';
        char last = '\0';
        char line[100];
        int j = 0;

        while(1){
            ch = fgetc(fp);
            line[j] = ch;
            if(ch == '\n')
                break;
            j++;
        }
        for(int k=0; line[k] != '\n'; k++){
            checknum(line,k);
        }
        for(int k=0; line[k] != '\n'; k++){
            if(line[k] <= 58 && line[k] >= 48){
                if(start == '\0'){
                    start = line[k];
                }
                last = line[k];
            }
        }

        ans += (start-48)*10 + (last-48);

    }
    printf("%d",ans);
}
