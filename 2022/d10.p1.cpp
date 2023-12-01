#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int i, n;
    int cycle = 0 , x = 1 , v , total = 0;
    ifstream fin;
    string line;
    
    fin.open("inputday10.txt");

    while(!fin.eof()){

        getline(fin , line);
        n = line.size();

        if(line == "noop")
        {
            cycle += 1;
            if(cycle == 20 || cycle == 60 || cycle == 100 || cycle ==  140 || cycle == 180 || cycle == 220){
                total += x*cycle;}
        }
        else
        {
            cycle += 1;
            if(cycle == 20 || cycle == 60 || cycle == 100 || cycle ==  140 || cycle == 180 || cycle == 220){
                total += x*cycle;}

            cycle += 1;
            if(cycle == 20 || cycle == 60 || cycle == 100 || cycle ==  140 || cycle == 180 || cycle == 220){
                total += x*cycle;}

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

        }
    }

    cout << "total is " << total;
    return 0;
}   