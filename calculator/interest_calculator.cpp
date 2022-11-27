#include <iostream>
#include <assert.h>
using namespace std;

class SimpleInterest
{

public:
  void getSimpleInterest(float principle, float rate, float time_period)
  {

    float interest, amount;
    interest = (principle * rate * time_period) / 100;
    amount = interest + principle;

    cout << "Simple Interest: " << interest << endl;

    cout << "Total Amount: " << amount << endl;
  }
};

int main()
{
  SimpleInterest S;
  float principle, rate, time_period;
  int t;

  cout << "Enter No of test cases: ";
  cin >> t;

  while (t != 0)
  {
    cout << "Enter Principle: ";
    cin >> principle;

    cout << "Enter Rate: ";
    cin >> rate;

    cout << "Enter Time: ";
    cin >> time_period;

    S.getSimpleInterest(principle, rate, time_period);
    t--;
  }

  return 0;
}