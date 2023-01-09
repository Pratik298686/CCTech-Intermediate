#include <iostream>
#include "converter.h"
using namespace std;

void printcurr(string Path)
{
	ifstream file(Path);
	string str, curr1,curr2;
	double rate;


	while (getline(file, str))
	{
		file >> curr1 >> curr2 >>rate;
		cout << curr1 <<" "<< curr2 <<endl;
	}
	file.close();
}

void addConversion(string Path, string curr1, string curr2)
{
    ofstream os;
	os.open(Path, ios_base::app | ios_base::out);
	double rate = 0;
	string my_str;

	cout << "Enter rate: "<<endl;
	cin >> rate;

	os << curr1 <<" "<< curr2 <<" "<<rate;
	os << endl;
	cout << curr1 <<" "<< curr2 <<" added!";
    

}

void convert(string Path, string curr1, string curr2)
{
   ifstream file(Path);
	string str, temp1,temp2;
	double rate = 0, amount = 0; 


	while (getline(file, str))
	{
		file >> temp1 >> temp2 >> rate;
		if(!(temp1.compare(curr1)) && !(temp2.compare(curr2)))
		{
              cout<<"Enter the amount: ";
			  cin >> amount ;
			  cout << amount <<" "<< curr1 <<" would be "<< amount * rate <<" "<<curr2;
			  file.close();
			  return;

		}
	}
	
	cout << "Invalid input "<<endl;
	cout << "Do you want to add a new conversion? y/n "<<endl;
	char c = 0;
	cin >> c;

    file.close();
	
	if(c == 'y' || c == 'Y')
	{
        addConversion(Path, curr1, curr2);
	}
}