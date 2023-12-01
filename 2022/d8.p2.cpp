#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int i, j, l;
    int right, left, top, bottom;
    int fscore = 0, cscore;
    ifstream fin;
    string line[99];

    fin.open("inputday8.txt");

    for(i = 0; i < 99; i++)
        getline(fin , line[i]);

    for(i = 1; i < 98; i++){
        for(j = 1; j < 98; j++){

            right = 98 - j;
            left = j;
            bottom = 98 - i;
            top = i;

            for(l = j-1; l >= 0; l--)
                if(line[i][j] <= line[i][l]){
                    left = j - l;
                    break;}

            for(l = j+1; l < 98; l++)
                if(line[i][j] <= line[i][l]){
                    right = l - j;
                    break;}

            for(l = i-1; l >= 0; l--)
                if(line[i][j] <= line[l][j]){
                    top = i - l;
                    break;}

            for(l = i+1; l < 98; l++)
                if(line[i][j] <= line[l][j]){
                    bottom = l - i;
                    break;}

            cscore = bottom*top*left*right;
            if(fscore < cscore)
                fscore = cscore;

        }
    }
    cout << fscore;               
    return 0;
}   