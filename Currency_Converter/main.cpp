#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "converter.h"
using namespace std;



int main(int argc, char *argv[])
{
    string Path = argv[1];
	char choice = 0;

	do
	{
	cout << "Welcome to CCTech Currency converter:"<<endl;
	printcurr(Path);
	string curr1, curr2;
    cout << "Enter Currency 1: "<<endl;
	cin >> curr1;
	cout << "Enter Currency 2: "<<endl;
	cin >> curr2;

	convert(Path, curr1, curr2);

	cout << "\n\n Convert Again? y/n: /n";
	cin >> choice;
	cout <<endl;
	}while (choice == 'y' || choice == 'Y');
	

	return EXIT_SUCCESS;
}