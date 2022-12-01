#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
    vector<string> the_args;
    if (argc > 1)
    {
        the_args.reserve(argc - 1);
    }

    for (int i = 1; i < argc; i++)
    {
        the_args.push_back(argv[i]);
    }

    sort(the_args.begin(), the_args.end());

    for (auto x : the_args)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}