#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int i, j, l, n;
    ifstream fin;
    string line;
    char ch[4];

    fin.open("inputday6.txt");
    getline(fin , line);
    n = line.size();

    for(i = 0; i < n-4; i++)
    {
        ch[0] = line[i];
        ch[1] = line[i+1];
        ch[2] = line[i+2];
        ch[3] = line[i+3];

        int count = 0;

        for(j = 0; j < 4; j++)
            for(l = j+1; l < 4; l++)
                if(ch[j] == ch[l])
                    count++;

        if(count == 0)
            break;
    }   
     
    cout << i + 4 ;
    return 0;

}