#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "sort_string_by_length.h"
#include "sort_string_by_length.cpp"
using namespace std;

int main(int argc, char *argv[])
{
    string name;
    vector<string> lines;
    int Num, i = 0;
    cout<<"Enter No of string: ";
    cin >> Num;

    while(i != Num)
    {
      getline(cin, name);

      lines.push_back(name);
      i++;
    }

    sort(lines.begin(), lines.end(), compare);

    for(auto name : lines)
    {
        cout << name <<endl;
    }

    return EXIT_SUCCESS;
}