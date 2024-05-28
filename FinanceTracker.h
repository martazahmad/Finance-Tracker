#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>
#include <fstream>
#include <sstream>
#pragma warning(disable : 4996)

using namespace std;

class Transaction{
	public:
		string type;
		string category;
		double amount;
		string description;
		int persons;
		vector<string> personNames;
		map<string, double> personAmounts;
		
		Transaction(string& type, string& category, double amount, string& description, int persons):
			type(type), category(category), amount(amount), description(description), persons(persons){
				personNames.resize(persons);
			}
			
		Transaction() : amount(0), persons(0) {} // Default constructor for loading from file

    	string toString() const {
    	    ostringstream oss;
    	    oss << type << "|" << category << "|" << amount << "|" << description << "|" << persons;
    	    for (const auto& name : personNames) {
    	        oss << "|" << name;
    	    }
    	    for (const auto& pa : personAmounts) {
     	       oss << "|" << pa.first << ":" << pa.second;
    	    }
    	    return oss.str();
   		}

    	static Transaction fromString(const string& str) {
    	    istringstream iss(str);
    	    string type, category, description;
    	    double amount;
    	    int persons;
    	    string token;
        
    	    getline(iss, type, '|');
    	    getline(iss, category, '|');
    	    iss >> amount;
    	    iss.ignore();
    	    getline(iss, description, '|');
    	    iss >> persons;
    	    iss.ignore();

    	    Transaction t(type, category, amount, description, persons);
    	    for (int i = 0; i < persons; ++i) {
    	        getline(iss, t.personNames[i], '|');
    	    }

    	    while (getline(iss, token, '|')) {
    	        size_t pos = token.find(':');
    	        string name = token.substr(0, pos);
    	        double amount = stod(token.substr(pos + 1));
    	        t.personAmounts[name] = amount;
    	    }

    	    return t;
    	}
};

class FinanceTracker{
	public:
		vector<Transaction> transactions;
		
		void exportSpendingReport(const string&);
		void exportSpendingCategoryReport(const string&);
		void exportSpendingPersonReport(const string&);
		void exportAllTransactionsReport(const string&);

		void addTransaction(string& type, string& category, double amount, string& description, int persons){
			transactions.push_back(Transaction(type, category, amount, description, persons));
			if (persons>1){
				string name;
				for (int i=0 ; i<persons ; i++){
					cout << "Person " << i+1 << " Name: ";
					cin >> name;
					transactions[transactions.size()-1].personNames[i] = name;
					transactions[transactions.size()-1].personAmounts[name] = 0.0;
				}
				cout << endl;
				char choice;
				cout << "Do you want to distribute the amount to mentioned persons equally? (Y/N): ";
A:				cin >> choice;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (choice=='Y'){
					for (auto& p : transactions[transactions.size()-1].personNames ){
						transactions[transactions.size()-1].personAmounts[p] = amount/persons;
					}
				} else if (choice=='N'){
					cout << endl;
B:					for (auto& p : transactions[transactions.size()-1].personNames ){
						double personAmount;
						cout << "Enter the amount for " << p << ": ";
						cin >> personAmount;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						transactions[transactions.size()-1].personAmounts[p] = personAmount;
					}
					double totalAmount = 0.0;
					for (auto& p : transactions[transactions.size()-1].personNames ){
						totalAmount += transactions[transactions.size()-1].personAmounts[p];
					}
					if (totalAmount!=amount){
						cout << endl;
						cout << "Error! The distibuted amount is not equal to the total amount of transaction!" << endl;
						cout << "Please Try Again:" << endl;
						cin.clear();
		                cin.ignore(numeric_limits<streamsize>::max(), '\n');
						goto B;
					}
				} else {
					cout << "Invalid Input! Input must be \'Y\' or \'N\'\nTry Again: ";
					cin.clear();
		            cin.ignore(numeric_limits<streamsize>::max(), '\n');
					goto A;
				}
			cout << "Transaction Added Successfully!" << endl << endl;
			for (auto& p : transactions[transactions.size() - 1].personNames) {
				cout << p << " has to pay Rs." << transactions[transactions.size() - 1].personAmounts[p] << endl;
			}
			cout << endl;
			system("pause");
			system("cls");
			} else if (persons==1){
				string name;
				cout << "Your Name: ";
				cin >> name;
				transactions[transactions.size()-1].personNames[0] = name;
				transactions[transactions.size()-1].personAmounts[name] = amount;
				cout << "Transaction Added Successfully!" << endl;
				system("pause");
				system("cls");
			}
		}
		
		void displayTransactions(){
			if (transactions.empty()){
				cout << endl << "Nothing to Show!" << endl;
				cout << "Please Add Some Transactions!" << endl;
			} else {
				cout << endl << "All Transactions:" << endl;
				cout << "--------------------------------" << endl;
				for (Transaction& t : transactions){
					cout << "Type: " << t.type << endl;
					cout << "Category: " << t.category << endl;
					cout << "Amount: " << t.amount << endl;
					cout << "Persons: " << t.persons << endl;
					cout << "Description: " << t.description << endl;
					cout << "--------------------------------" << endl;
				}
				char choice;
				cout << "Do you want to Export the results as txt file? (Y/N): ";
				cin >> choice;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (choice == 'Y') {
					char* userName = getenv("USERNAME");
					string name;
					string username(userName);
					cout << "Enter the name of txt file: ";
					cin >> name;
					exportAllTransactionsReport("C:\\users\\" + username + "\\Desktop\\" + name + ".txt");
					exportAllTransactionsReport("C:\\users\\" + username + "\\Onedrive\\Desktop\\" + name + ".txt");
					cout << "Successfully Exported " + name + ".txt"+" on Desktop!" << endl;
				}
			}
			
			system("pause");
			system("cls");
		}
		
		void analyzeSpending(){
			double totalIncome = 0.0;
			double totalExpense = 0.0;
			for (Transaction& t : transactions){
				if (t.type == "income"){
					totalIncome += t.amount;
				} else if (t.type == "expense"){
					totalExpense += t.amount;
				}
			}
			cout << endl;
			cout << "Total Income: " << totalIncome << endl;
			cout << "Total Expenses: " << totalExpense << endl;
			cout << "--------------------------------" << endl;
			char choice;
			cout << "Do you want to Export the results as txt file? (Y/N): ";
			cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (choice == 'Y') {
				char* userName = getenv("USERNAME");
				string name;
				string username(userName);
				cout << "Enter the name of txt file: ";
				cin >> name;
				exportSpendingReport("C:\\users\\"+username+"\\Desktop\\"+name+".txt");
				exportSpendingReport("C:\\users\\"+username+"\\Onedrive\\Desktop\\"+name+".txt");
				cout << "Successfully Exported " + name + ".txt" + " on Desktop!" << endl;
			}
			
			system("pause");
			system("cls");
		}
				
		void analyzeSpendingCategory(){
			map<string, double> categoryTotals;
			for (Transaction& t : transactions){
				if (t.type == "expense"){
					categoryTotals[t.category] += t.amount;	
				}
			}
			cout << endl;
			for (auto& cat : categoryTotals){
				cout << "Category: " << cat.first << ", " << "Amount: " << cat.second << endl;
			}
			cout << "--------------------------------" << endl;
			char choice;
			cout << "Do you want to Export the results as txt file? (Y/N): ";
			cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (choice == 'Y') {
				char* userName = getenv("USERNAME");
				string name;
				string username(userName);
				cout << "Enter the name of txt file: ";
				cin >> name;
				exportSpendingCategoryReport("C:\\users\\" + username + "\\Desktop\\" + name + ".txt");
				exportSpendingCategoryReport("C:\\users\\" + username + "\\Onedrive\\Desktop\\" + name + ".txt");
				cout << "Successfully Exported " + name + ".txt" + " on Desktop!" << endl;
			}

			system("pause");
			system("cls");
		}
		
		void analyzeSpendingPerson(){
			map<string, double> personTotals;
			for (Transaction& t : transactions){
				if (t.type == "expense"){
					for (string& p : t.personNames){
						personTotals[p] += t.personAmounts[p];
					}
				}
			}
			cout << endl;
			for (auto& p : personTotals){
				cout << "Person: " << p.first << ", " << "Amount: " << p.second << endl;
			}
			cout << "--------------------------------" << endl;
			char choice;
			cout << "Do you want to Export the results as txt file? (Y/N): ";
			cin >> choice;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (choice == 'Y') {
				char* userName = getenv("USERNAME");
				string name;
				string username(userName);
				cout << "Enter the name of txt file: ";
				cin >> name;
				exportSpendingReport("C:\\users\\" + username + "\\Desktop\\" + name + ".txt");
				exportSpendingReport("C:\\users\\" + username + "\\Onedrive\\Desktop\\" + name + ".txt");
				cout << "Successfully Exported " + name + ".txt" + " on Desktop!" << endl;
			}

			system("pause");
			system("cls");
		}
		
		void saveToFile(const string& filename) {
	        ofstream outFile(filename);
	        for (const auto& transaction : transactions) {
	            outFile << transaction.toString() << endl;
	        }
	    }
	
	    void loadFromFile(const string& filename) {
	        ifstream inFile(filename);
	        string line;
	        while (getline(inFile, line)) {
	            transactions.push_back(Transaction::fromString(line));
	        }
	    }
};

void FinanceTracker::exportSpendingReport(const string& filename) {
	ofstream outFile(filename);
	double totalIncome = 0.0;
	double totalExpense = 0.0;

	for (const Transaction& t : transactions) {
		if (t.type == "income") {
			totalIncome += t.amount;
		}
		else if (t.type == "expense") {
			totalExpense += t.amount;
		}
	}

	outFile << "Total Income: " << totalIncome << endl;
	outFile << "Total Expenses: " << totalExpense << endl;
	outFile << "--------------------------------" << endl;
}

void FinanceTracker::exportSpendingCategoryReport(const string& filename) {
	ofstream outFile(filename);
	map<string, double> categoryTotals;

	for (const Transaction& t : transactions) {
		if (t.type == "expense") {
			categoryTotals[t.category] += t.amount;
		}
	}

	for (const auto& cat : categoryTotals) {
		outFile << "Category: " << cat.first << ", Amount: " << cat.second << endl;
	}
	outFile << "--------------------------------" << endl;
}

void FinanceTracker::exportSpendingPersonReport(const string& filename) {
	ofstream outFile(filename);
	map<string, double> personTotals;

	for (const Transaction& t : transactions) {
		if (t.type == "expense") {
			for (const string& p : t.personNames) {
				personTotals[p] += t.personAmounts.at(p);
			}
		}
	}

	for (const auto& p : personTotals) {
		outFile << "Person: " << p.first << ", Amount: " << p.second << endl;
	}
	outFile << "--------------------------------" << endl;
}

void FinanceTracker::exportAllTransactionsReport(const string& filename) {
	ofstream outfile(filename);
	if (!transactions.empty()) {
		outfile << endl << "All Transactions:" << endl;
		outfile << "--------------------------------" << endl;
		for (Transaction& t : transactions) {
			outfile << "Type: " << t.type << endl;
			outfile << "Category: " << t.category << endl;
			outfile << "Amount: " << t.amount << endl;
			outfile << "Persons: " << t.persons << endl;
			outfile << "Description: " << t.description << endl;
			outfile << "--------------------------------" << endl;
		}
	}
}