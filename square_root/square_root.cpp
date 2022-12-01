#include <iostream>
using namespace std;

int floorSqrt(int x)
{
	if (x == 0 || x == 1)
		throw x;

	int i = 1, result = 1;
	while (result <= x) {
		i++;
		result = i * i;
	}
	return i - 1;
}

int main()
{
	int x;
    cout<<"Enter Number: \n"
    cin>>x;

    try
    {
        cout << floorSqrt(x) << endl;
    }
    catch(int x)
    {
        cout << "Number "<< x <<" Exception caugth \n";
    }
    
	
	return 0;
}
