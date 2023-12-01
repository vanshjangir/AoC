#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int i, j, l;
    int right, left, top, bottom, total = 0;
    ifstream fin;
    string line[99];

    fin.open("inputday8.txt");

    for(i = 0; i < 99; i++)
        getline(fin , line[i]);

    for(i = 1; i < 98; i++){
        for(j = 1; j < 98; j++){

            left = 0;
            right = 0; 
            top = 0;
            bottom = 0; 

            for(l = 0; l < j; l++)
                if(line[i][j] <= line[i][l]){
                    left = 1;
                    break;}

            for(l = j+1; l < 99; l++)
                if(line[i][j] <= line[i][l]){
                    right = 1;
                    break;}
            
            for(l = 0; l < i; l++)
                if(line[i][j] <= line[l][j]){
                    top = 1;
                    break;}

            for(l = i+1; l < 99; l++)
                if(line[i][j] <= line[l][j]){
                    bottom = 1;
                    break;}

            if(right == 0 || left == 0 || top == 0 || bottom == 0)
                total += 1;

        }
    }
    total += 392;
    cout << total;               
    return 0;
}   