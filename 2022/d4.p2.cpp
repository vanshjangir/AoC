#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int i, j, n, total = 0;
    int fr1, fr2, sr1, sr2;
    ifstream fin;
    string line;
    char input[2] = {'0' , '0'};

    fin.open("inputday4.txt");

    while(!fin.eof()){

        getline(fin,line);
        n = line.size();

        i = 0;

        fr1 = line[i] - 48;
        if(line[i+1] != '-'){
            fr1 = (fr1*10) + (line[i+1] - 48);
            i++;}
        i += 2;

        fr2 = line[i] - 48;
        if(line[i+1] != ','){
            fr2 = (fr2*10) + (line[i+1] - 48);
            i++;}
        i += 2;

        sr1 = line[i] - 48;
        if(line[i+1] != '-'){
            sr1 = (sr1*10) + (line[i+1] - 48);
            i++;}
        i += 2;

        sr2 = line[i] - 48;
        if(i+1 != n){
            sr2 = (sr2*10) + (line[i+1] - 48);
            i++;}
        i += 2;

        cout << fr1 << " " << fr2 << " " << sr1 << " " << sr2 << endl;

        if(fr2 >= sr1 && sr2 >= fr1)
            total++;

    }
    cout << total ;
    return 0;

}