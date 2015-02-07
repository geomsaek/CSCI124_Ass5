#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

char fingGen();



int main()
{
	double position;
	double speed;
	int energy;
	long int amount;
	char datafile[50];
	int decimal1,decimal2;
	char fingerPrint[8] = {'\0'};
	srand(time(NULL));
	 
	cout<<"How many records would you like? "<<endl;
	cin>>amount;
	cout<<"Specify the datafile"<<endl;
	cin>>datafile;
	
	ofstream outfile;
	outfile.open(datafile);
	
	outfile<<'#'<<endl;
	int count=0;
	
	for(int i=0;i<=amount;i++)
	{
		position = rand()% 1000000 + 1;
		decimal1 = rand()% 100;
		decimal2 = rand()% 100;
		speed = rand() % 10000 +1;
		energy = rand() % 10000 + 1;
		
		for(int k=0;k<8;k++)
		{
			fingerPrint[k]= fingGen();
		}
			
		outfile<<position<<'.'<<decimal1<<endl;
		outfile<<speed<<'.'<<decimal2<<endl;
		outfile<<energy<<endl;
		outfile<<fingerPrint<<endl;
		count++;
	}
	
	outfile<<'#'<<endl;
	cout<<count<<endl;
	cout<<"Done"<<endl;

return 0;

}


char fingGen()
{
	char x;
	
	x = rand()% 121 + 1;
		
	while(x < 48 || (x >57 && x < 65) || (x > 90 && x < 97))
		x = rand() % 121 + 1; 

	return x;
}




