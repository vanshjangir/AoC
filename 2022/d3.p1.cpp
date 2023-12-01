#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int n1, n2, n3;
	int j, l, k, m, total = 0;
	string line1 , line2, line3;
	char ch[50];
	ifstream fin;

	fin.open("inputday3.txt");

	while (!fin.eof())
	{
		k = 0;
			getline(fin , line1);
			getline(fin , line2);
			getline(fin , line3);

			n1 = line1.size();
			n2 = line2.size();
			n3 = line3.size();

			for(j = 0; j < n1; j++)
				for(l = 0; l < n2; l++)
					if(line1[j] == line2[l]){
						ch[k] = line1[j];
						k++;
						for(m = 0; m < n2; m++)
							if(line1[j] == line2[m])
								line2[m] = '0';
					}


			cout << ch << "and k is " << k << endl;


			for(j = 0; j < k; j++)
				for(l = 0; l < n3; l++)
					if(ch[j] == line3[l]){
						if(ch[j] >= 65 && ch[j] <= 90)
							total += ch[j] - 38;
						else
							total += ch[j] - 96;

						for(m = 0; m < n3; m++)
							if(ch[j] == line3[m])
								line3[m] = '0';
					}

			cout << line3 << endl;

		
	}
	cout << total;
}