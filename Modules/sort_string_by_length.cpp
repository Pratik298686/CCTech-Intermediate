#include<string>
#include "sort_string_by_length.h"
using namespace std;
bool compare(string first, string second)
{
    return first.length() < second.length();
}