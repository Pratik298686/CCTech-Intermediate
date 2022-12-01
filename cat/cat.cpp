#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        ifstream file(argv[i]);
        if (file.fail())
        {
            cerr << "Error opening file.\n";
            return 1;
        }
        string tp;
        while (getline(file, tp))
        {
            cout << tp;
        }
        cout<<" "<<endl;
    }
    return 0;
}