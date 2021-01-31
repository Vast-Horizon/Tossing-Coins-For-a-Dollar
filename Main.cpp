#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <cstdlib>
using namespace std;

class Coin {
private:
	string sideUp;

public:
	Coin();
	void toss(int r);
	string getSideUp()const;
	~Coin() {cout << "\n***DONE***" << endl; system("pause");}

};
//default constructor
Coin::Coin() {
	int defRand = 0;
	srand(time(0));
	defRand = rand() % 2;
	if (defRand == 1) {
		sideUp = "heads";
	}
	else {
		sideUp = "tails";
	}
}
//mutator
void Coin::toss(int r) {
	if (r== 1) {
		sideUp = "heads";
	}
	else {
		sideUp = "tails";
	}
}
//accessor
string Coin::getSideUp()const {return sideUp;}

int main() {
	cout << "The game is over when your balence reaches 100 cent($1) or more\n"
		<< "You win if your balence is exactly $1\n" << endl;
	cout << "---Game Start---" << endl;
	//create three Coin instances
	Coin quarter, dime, nickel;
	//initialize the balance to 0
	int balance = 0;

	int i = 1; int randomN = 0;
	srand(time(0));

	cout << "Balance: " << balance << " cent" << endl << endl;
	while (balance <= 100) {
		//tossing coins
		randomN = rand() % 2;
		quarter.toss(randomN);
		randomN = rand() % 2;
		dime.toss(randomN);
		randomN = rand() % 2;
		nickel.toss(randomN);
		//output the facing
		cout << "Quarter: "<< quarter.getSideUp()<< endl;
		cout << "Dime: " <<dime.getSideUp()<< endl;
		cout << "Nickel: " <<nickel.getSideUp()<<endl;
		//reflash the balance
		if (quarter.getSideUp() == "heads") {
			balance += 25;
		}
		if (dime.getSideUp() == "heads") {
			balance += 10;
		}
		if (nickel.getSideUp() == "heads") {
			balance += 5;
		}
		//output the new balence then ask the user to press enter
		cout << "Balance: " << balance <<" cent"<< endl;
		cout << "Please press Enter to continue..." << endl;
		cin.get();
		//win 
		if (balance == 100) {
			cout << endl;
			cout << "Your final balence is exactly 100 cent ($1)" << endl;
			cout << "******\n";
			cout << "| WIN |";
			cout << "\n******";
			break;
		}
	}
	//lose
	if (balance > 100) {
		cout << "Your final balence is exceeds 100 cent ($1)" << endl;
		cout << "*******\n";
		cout << "| Lose |";
		cout << "\n*******";
	}
	return 0;
}