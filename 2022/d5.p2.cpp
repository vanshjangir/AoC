#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int i;
    int nos, fs, ss;
    ifstream fin;
    vector<vector<char>> input;
    vector <char> temp;
    string line;
    
    fin.open("inputday5.txt");

    for(int j = 0; j < 9; j++){

        fin.seekg(0);
        for(i = 0; i < 8; i++){
            getline(fin,line);
            if(line[4*j + 1] >= 65 && line[4*j + 1] <= 90)
                temp.push_back(line[4*j + 1]);}

        reverse(temp.begin() , temp.end());
        input.push_back(temp);
        temp.clear();}

        getline(fin,line);
        getline(fin,line);


        while(!fin.eof()){
            getline(fin,line);

            if(line[6] == ' '){
                nos = line[5] - 48;
                fs = line[12] - 48;
                ss = line[17] - 48;}
            else{
                nos = (line[5] - 48)*10 + line[6] - 48;
                fs = line[13] - 48;
                ss = line[18] - 48;}

            for(i = 0; i < nos; i++)
                input[ss-1].push_back(input[fs-1][input[fs-1].size() - nos + i]);

            for(i = 0; i < nos; i++)
                input[fs-1].pop_back();
            }

        for(i = 0; i < 9; i++)
            cout << input[i][input[i].size() - 1];

    return 0;
}   