
int a;
class cashRegister
{
private:
	int cashOnHand;

public:
	cashRegister();					 // Constructor Sets the cash in the register to a default amount.
	cashRegister(int cashIn);		 // Constructor Sets the cash in the register to a specific amount.
	int getCurrentBalance();		 // The value of cashOnHand is returned.
	void acceptAmount(int amountIn); // Function to receive the amount deposited by the customer
									 // and update amount in the register.
};

class dispenserType
{
private:
	int numberOfItems; // variable to store the number of items in the dispenser
	double cost;	   // variable to store the cost of an item
public:
	dispenserType();								 // Constructor Sets the cost and number of items in the dispenser to the default
	dispenserType(int setNoOfItems, double setCost); // Constructor Sets to the values specified
	int getNoOfItems();								 // The value of numberOfItems is returned.
	double getCost();								 // Function to show the cost of the item. The value of cost is returned.
	void makeSale();								 // Function to reduce the number of items by 1.
};

cashRegister::cashRegister()
{
	cashOnHand = 500;
}

cashRegister::cashRegister(int cashIn)
{
	cashOnHand = cashIn;
}

int cashRegister::getCurrentBalance()
{
	return cashOnHand;
}

void cashRegister::acceptAmount(int amountIn)
{

	cashOnHand = cashOnHand + amountIn;
}

dispenserType::dispenserType()
{
	numberOfItems = 50;
	cost = 50;
}

dispenserType::dispenserType(int setNoOfItems, double setCost)
{
	numberOfItems = setNoOfItems;
	cost = setCost;
}

int dispenserType::getNoOfItems()
{
	return numberOfItems;
}

double dispenserType::getCost()
{
	return cost;
}

void dispenserType::makeSale()
{
	numberOfItems--;
}

#include <iostream>
using namespace std;

void showSelection();
void sellProduct(dispenserType &product, cashRegister &pCounter);
int main()
{
	cashRegister counter;
	dispenserType cola(5, 1.00);
	dispenserType candy(5, 0.50);
	dispenserType chips(5, 0.65);
	int choice;
	showSelection();
	cin >> choice;
	while (choice != 4)
	{
		switch (choice)
		{
		case 1:
			sellProduct(cola, counter);
			break;
		case 2:
			sellProduct(chips, counter);
			break;
		case 3:
			sellProduct(candy, counter);
			break;
		default:
			cout << "Invalid selection." << endl;
		}
		showSelection();
		cin >> choice;
	}
	return 0;
}
void showSelection()
{
	cout << "*** Welcome to Candy Shop ***" << endl;
	cout << "To select an item, enter " << endl;
	cout << "1 for Cola" << endl;
	cout << "2 for Chips" << endl;
	cout << "3 for Candy" << endl;
	cout << "4 to exit" << endl;
}

void sellProduct(dispenserType &product, cashRegister &pCounter)
{
	int amount;	 // variable to hold the amount entered
	int amount2; // variable to hold the extra amount needed
	string yesno;
	if (product.getNoOfItems() > 0) // if the dispenser is not empty
	{
		cout << "Please deposit " << product.getCost() << "$" << endl;
		cin >> amount;
		a = amount;
		cout << "Are you sure you want to continue this process(y/n) : " << endl;
		cin >> yesno;
		if (yesno == "y")
		{
			if(pCounter.getCurrentBalance() == 0)
			{
				cout << "Please Insert Exact Change Only. "<<endl;
			}
			if (amount < product.getCost())
			{
				cout << "Please deposit another " << product.getCost() - amount << "$" << endl;
				cin >> amount2;
				amount = amount + amount2;
			}

			if (amount >= product.getCost())
			{
				pCounter.acceptAmount(amount);
				product.makeSale();
				cout << "Your remaining ammount : " << amount - product.getCost() << "$"<<endl;
				cout << "Collect your item at the bottom and "
					 << "enjoy." << endl;
			}

			else
			{
				cout << "The amount is not enough. "
					 << "Collect what you deposited." << endl;
			}
			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl
				 << endl;
		}
		else if (yesno == "n")
		{
			cout << "Return Coin : " << a << "$"<<endl;
		}
	}
	else
		cout << "Sorry, this item is sold out." << endl;
}