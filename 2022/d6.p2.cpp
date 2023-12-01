#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int i, j, l, n;
    ifstream fin;
    string line;
    char ch[14];

    fin.open("inputday6.txt");
    getline(fin , line);
    n = line.size();

    for(i = 0; i < n-14; i++)
    {
        ch[0] = line[i];
        ch[1] = line[i+1];
        ch[2] = line[i+2];
        ch[3] = line[i+3];
        ch[4] = line[i+4];
        ch[5] = line[i+5];
        ch[6] = line[i+6];
        ch[7] = line[i+7];
        ch[8] = line[i+8];
        ch[9] = line[i+9];
        ch[10] = line[i+10];
        ch[11] = line[i+11];
        ch[12] = line[i+12];
        ch[13] = line[i+13];

        int count = 0;

        for(j = 0; j < 14; j++)
            for(l = j+1; l < 14; l++)
                if(ch[j] == ch[l])
                    count++;

        if(count == 0)
            break;
    }   
     
    cout << i + 14 ;
    return 0;

}