#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int n;
    int v , cycle = 0 , x = 1;
    ifstream fin;
    string line;
    
    fin.open("inputday10.txt");
    cout << '#';

    while(!fin.eof()){

        getline(fin , line);
        n = line.size();

        if(line == "noop")
        {
            cycle += 1;
            if(cycle%40 == 0){cout << endl; x += 40;}
            if(x == cycle || x+1 == cycle || x-1 == cycle)
                cout << '#';
            else
                cout << '.';
            
        }
        else
        {
            cycle += 1;
            if(cycle%40 == 0){cout << endl; x += 40;}
            if(x == cycle || x+1 == cycle || x-1 == cycle)
                cout << '#';
            else
                cout << '.';

            cycle += 1;

            if(line[5] == '-'){
                if(n == 8){
                    v = (line[6] - 48)*10 + (line[7] - 48);
                    v = v*(-1);}
                else{
                    v = line[6] - 48;
                    v = v*(-1);}}
            else{
                if(n == 7)
                    v = (line[5] - 48)*10 + (line[6] - 48);
                else
                    v = line[5] - 48;}

            x += v;
            
            if(cycle%40 == 0){cout << endl; x += 40;}
            if(x == cycle || x+1 == cycle || x-1 == cycle)
                cout << '#';
            else
                cout << '.';

        }
    }
    return 0;
}   