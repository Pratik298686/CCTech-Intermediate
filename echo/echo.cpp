#include <iostream>
using namespace std;

void echo(int argc, char *argv[])
{
    for(int i = 1; i< argc; i++)
    {
        cout<<argv[i]<<" ";
    }
    cout<<"\n";
}

int main(int argc, char *argv[])
{
    echo(argc, argv);
    return 0;
}