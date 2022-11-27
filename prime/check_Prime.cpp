#include <iostream>
#include <assert.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

int main()
{
    assert(isPrime(11));
    assert(isPrime(12));
    return 0;
}