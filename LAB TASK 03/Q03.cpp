#include<iostream>
using namespace std;
class Glass {
	public:
	int LiquidLevel;
	
	void Refill(){
		LiquidLevel=200;
		cout<<"Glass has been Refilled to 200ml"<<endl;
	}
	void Drink(int milliliters){
		LiquidLevel=LiquidLevel-milliliters;
		cout << "Liquid level is now :" << LiquidLevel  << "ml\n" << endl;
            if (LiquidLevel < 100) {
                cout << "Juice in glass is less than 100 ml.Refilling....\n" << endl;
                Refill();
            }
	}
};
int main(){
	Glass Juice;
	Juice.LiquidLevel=200;
	int drink;
	int choice=0;
	while(true){
		cout << "Press 1 to Display current Level:"<< endl;
		cout << "Press 2 to Drink:" << endl;
		cout << "Press 3 to Exit:" << endl;
		
		
		cin >> choice;
		
		if(choice == 1){
			cout << "Current Level: " << Juice.LiquidLevel << endl;
		}else if(choice == 2){
			cout << "Enter amount to drink (ml): ";
			cin >> drink;
			Juice.Drink(drink);
			cout << "Current Level: " << Juice.LiquidLevel << endl;
		}else if(choice == 3){
			cout<<"Exiting...."<<endl;
			break;
		}
		else{
			cout << "Invalid Entry! Please enter a valid choice.";
		}
		
	}
}