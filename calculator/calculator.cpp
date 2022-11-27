#include <iostream>
using namespace std;

double calculatorfunction(double a, double b, char op)
{
    double result = 0.0;
    if (op == '+')
    {
        result = a + b;
    }
    else if (op == '-')
    {
        result = a - b;
    }
    else if (op == '*')
    {
        result = a * b;
    }
    else if (op == '/')
    {
        result = a / b;
    }
    else
    {
        cout << "None";
    }
    return result;
}

int main()
{
    char choice = '+';
    double num1, num2;

    cout << "Please input two number and an operator (+,-,*,/); ";
    cout << "Enter Number1: ";
    cin >> num1;
    cout << "Enter Number2: ";
    cin >> num2;
    cout << "Enter Operator(+,-,*,/,q for quit): ";
    cin >> choice;

    while (choice != 'Q')
    {
        cout << calculatorfunction(num1, num2, choice) << endl;
        cout << "Please input two number and an operator (+,-,*,/); ";
        cout << "Enter Number1: ";
        cin >> num1;
        cout << "Enter Number2: ";
        cin >> num2;
        cout << "Enter Operator(+,-,*,/,q for quit): ";
        cin >> choice;
    }
    return 0;
}