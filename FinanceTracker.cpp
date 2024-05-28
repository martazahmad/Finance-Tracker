#include "FinanceTracker.h"

int main(){
	FinanceTracker tracker;
	
	// Load transactions from file
    tracker.loadFromFile("transactions.txt");
	
	short choice;
	
	cout << "Welcome to Finance Tracker Application!" << endl;
	do{
		cout << endl << "Choose an Operation:" << endl;
		cout << "[1] Add Transaction" << endl;
		cout << "[2] Display all Transactions" << endl;
		cout << "[3] Analyse Spending" << endl;
		cout << "[4] Analyze Spending by Category" << endl;
		cout << "[5] Analyze Spending by Person" << endl;
		cout << "[0] Exit" << endl;
		
		cout << "Choice: ";
F:		cin >> choice;
		
		if (choice == 1){
			string type, category="No Category", description = "";
			double amount;
			int persons=1;
			cout << endl;
			cout << "Enter Transaction Details:" << endl;
			cout << "Type (income/expense): ";
C:			cin >> type;
			if ( type!="income" && type!="expense" ){
				cout << "Invalid Input! Input must be \"income\" or \"expense\"" << endl;
				cout << "Try Again: ";
				cin.clear();
		        cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto C;
			}
			if (type == "income")
				goto H;
			cout << "Category: ";
			cin >> category;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
H:			cout << "Amount: ";
D:			cin >> amount;
			if (amount<=0){
				cout << "Error! Please enter a valid Amount: ";
				cin.clear();
		        cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto D;
			}
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (type == "income")
				goto G;
			cout << "Description: ";
			cin >> description;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Number of Persons involved: ";
E:			cin >> persons;
			if (amount<=0){
				cout << "Error! Please enter a valid number of Persons: ";
				cin.clear();
	        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto E;
			}
G:			tracker.addTransaction(type, category, amount, description, persons);
		} else if (choice==2){
			tracker.displayTransactions();
		} else if (choice==3){
			tracker.analyzeSpending();
		} else if (choice==4){
			tracker.analyzeSpendingCategory();
		} else if (choice==5){
			tracker.analyzeSpendingPerson();
		} else if (choice!=0){
			cout << "Invalid Choice!\nTry Again: ";
			cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
			goto F;
		}
	} while (choice!=0);
	
	// Save transactions to file
    tracker.saveToFile("transactions.txt");
	
	cout << endl << "Good Bye! :)" << endl;
	
	system("pause");

	return 0;
}
