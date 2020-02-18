#define _CRT_SECURE_NO_WARNINGS

#include<math.h>
#include<iostream>
#include<list>
#include<string>

#define SIZE 5

using namespace std;

double transaction[SIZE][3];
int tnum = 0;

class Account {
public:
	int CHECKING = 0;
	int SAVINGS = 1;
	int MAXI_SAVINGS = 2;
	int type = 0;
	double amount = 0;

	Account() {};
	Account(int input_type) {
		this->type = input_type;
	}

	string deposit(double num, int accountId) {
		string output = "";
		if (num <= 0) {
			output = "amount must be greater than zero";
		}
		else {
			amount += num;
			transaction[tnum][0] = accountId;
			transaction[tnum][1] = 1;
			transaction[tnum][2] = num;
			tnum++;
		}
		return output;
	}
	string  withdraw(double num, int accountId) {
		string output = "";
		if (num <= 0) {
			output = "amount must be greater than zero";
		}
		else if (num > amount) {
			output = "sumTransactions must be greater than zero";
		}
		else {
			amount -= num;

			char t[] = "withdrwal";
			char* tr_name = t;
			transaction[tnum][0] = accountId;
			transaction[tnum][1] = 2;
			transaction[tnum][2] = num;
			tnum++;
		}
		return output;
	}
	double getInterest() {
		double amount = sumTransactions();
		double result = 0;
		if (type == 0) {
			result = amount * 0.001;
		}
		else if (type == 1) {
			if (amount > 1000) {
				result = 1000 * 0.001 + (amount - 1000)*0.002;
			}
			else {
				result = amount * 0.001;
			}

		}
		else if (type == 2) {
			if (amount > 2000) {
				result = 1000 * 0.02 + 1000 * 0.05 + (amount - 2000)*0.1;
			}
			else if (amount > 1000 && amount <= 2000) {
				result = 1000 * 0.02 + (amount - 1000)*0.05;
			}
			else {
				result = amount * 0.02;
			}
		}
		return result;
	}
	double sumTransactions() {
		return amount;
	}
	int getType() {
		return type;
	}
};

class Customer {
public:
	char* name;
	list<Account*> accounts;

	Customer() {};
	Customer(char* input_name) {
		this->name = input_name;
	}

	char* getName() {
		return name;
	}

	void addAccount(Account* account) {
		accounts.push_back(account);
	}
	int getNumOfAccounts() {
		return accounts.size();
	}
	double totalInterestEarned() {
		double sum = 0;
		for (auto itr = accounts.begin(); itr != accounts.end(); itr++) {
			sum += (*itr)->getInterest();
		}
		return sum;
	}
	string getStatement() {
		double sum = 0;
		string output = "";
		string sname = name;
		output = "Statement for " + sname + "\n\n";
		for (auto itr = accounts.begin(); itr != accounts.end(); itr++) {
			if ((*itr)->getType() == 0) {
				output += "Checking Account\n";
				double total = 0;
				for (int i = 0; i < tnum; i++) {
					if (transaction[i][0] == 0) {
						if (transaction[i][1] == 1) {
							output += "  deposit $" + my_format(transaction[i][2]) + "\n";
							total += transaction[i][2];
						}
						if (transaction[i][1] == 2) {
							output += "  withdrawal $" + my_format(transaction[i][2]) + "\n";
							total -= transaction[i][2];
						}
					}
				}
				output += "Total $" + my_format(total) + "\n\n";
				sum += total;
			}
			else if ((*itr)->getType() == 1) {
				output += "Savings Account\n";
				double total = 0;
				for (int i = 0; i < tnum; i++) {
					if (transaction[i][0] == 1) {
						if (transaction[i][1] == 1) {
							output += "  deposit $" + my_format(transaction[i][2]) + "\n";
							total += transaction[i][2];
						}
						if (transaction[i][1] == 2) {
							output += "  withdrawal $" + my_format(transaction[i][2]) + "\n";
							total -= transaction[i][2];
						}
					}
				}
				output += "Total $" + my_format(total) + "\n\n";
				sum += total;
			}		
		}
		output += "Total In All Accounts $" + my_format(sum);
		return output;
	}

	string my_format(double num) {
		num = floor(num*10.f + 0.5) / 10.f;
		string result = to_string(num);
		result = result.substr(0, result.length() - 4);
		return result;
	}
};

class Bank {
public:
	list<Customer*> bankOfCustomers;
	list<Account*> bankOfAccounts;
	Bank() {};
	void createCustomer(Customer* customer) {
		bankOfCustomers.push_back(customer);
	}
	void createAccount(Account* account) {
		bankOfAccounts.push_back(account);
	}
	string customsum() {
		string output = "";
		output += "Customer Summary\n";
		for (auto itr = bankOfCustomers.begin(); itr != bankOfCustomers.end(); itr++) {
			int num = (*itr)->getNumOfAccounts();
			string sname = (*itr)->getName();
			output += " - " + sname + " (" + to_string(num);
			if (num > 1) {
				output += " accounts)\n";
			}
			else {
				output += " account)\n";
			}
		}
		output = output.substr(0, output.length() - 1);
		return output;
	}
	double banktotalInserstPaid() {
		double sum = 0;
		for (auto itr = bankOfCustomers.begin(); itr != bankOfCustomers.end(); itr++) {
			sum += (*itr)->totalInterestEarned();
		}
		return sum;
	}
};

int main() {
	char* operation = new char[50];
	string s = "start";
	strcpy(operation, s.c_str());
	Account* account = new Account();
	Customer* customer = new Customer();
	Bank* bank = new Bank();
	string result = "";

	while (strcmp(operation, "end")) {
		cin >> operation;
		if (strcmp(operation, "createCustomer") == 0) {
			char* name = new char[10];
			cin >> name;
			customer = new Customer(name);
			bank->createCustomer(customer);
		}
		else if (strcmp(operation, "createAccount") == 0) {
			int type;
			cin >> type;
			account = new Account(type);
			bank->createAccount(account);
		}
		else if (strcmp(operation, "addToCustomer") == 0) {
			int index;
			char* name = new char[10];
			cin >> index >> name;
			list<Account*> alist = bank->bankOfAccounts;
			list<Customer*> clist = bank->bankOfCustomers;
			int i = 0;
			for (auto itr = alist.begin(); itr != alist.end(); itr++) {
				if (i == index) {
					for (auto it = clist.begin(); it != clist.end();it++) {
						if (strcmp(name, (*it)->getName()) == 0) {
							(*it)->addAccount(*itr);
						}
					}
				}
				i++;
			}
		}
		else if (strcmp(operation,"accountDeposit") == 0) {
			int index;
			double amount;
			cin >> index >> amount;
			int i = 0;
			list<Account*> alist = bank->bankOfAccounts;
			for (auto itr = alist.begin(); itr != alist.end(); itr++) {
				if (i == index) {
					result = (*itr)->deposit(amount, index);
				}
				i++;
			}
		}
		else if (strcmp(operation, "accountWithdraw") == 0) {
			int index;
			double amount;
			cin >> index >> amount;
			int i = 0;
			list<Account*> alist = bank->bankOfAccounts;
			for (auto itr = alist.begin(); itr != alist.end(); itr++) {
				if (i == index) {
					result = (*itr)->withdraw(amount, index);
				}
				i++;
			}
		}
		else if (strcmp(operation, "sumTransactions") == 0) {
			int index;
			cin >> index;
			int i = 0;
			list<Account*> alist = bank->bankOfAccounts;
			for (auto itr = alist.begin(); itr != alist.end(); itr++) {
				if (i == index) {
					double num = (*itr)->sumTransactions();
					double fnum = floor(num*10.f + 0.5) / 10.f;
					result = to_string(fnum);
					result = result.substr(0, result.length() - 5);
				}
				i++;
			}
		}
		else if (strcmp(operation, "numberOfAccount") == 0) {
			char* name = new char[10];
			cin >> name;
			list<Customer*> clist = bank->bankOfCustomers;
			for (auto it = clist.begin(); it != clist.end(); it++) {
				if (strcmp(name, (*it)->getName()) == 0) {
					result = to_string((*it)->getNumOfAccounts());
				}
			}
		}
		else if (strcmp(operation, "totalInterestEarned") == 0) {
			char* name = new char[10];
			cin >> name;
			list<Customer*> clist = bank->bankOfCustomers;
			for (auto it = clist.begin(); it != clist.end(); it++) {
				if (strcmp(name, (*it)->getName()) == 0) {
					double num = (*it)->totalInterestEarned();
					double fnum = floor(num*10.f + 0.5) / 10.f;
					result = to_string(fnum);
					result = result.substr(0, result.length() - 5);
				}
			}
		}
		else if (strcmp(operation, "getStatement") == 0) {
			char* name = new char[10];
			cin >> name;
			list<Customer*> clist = bank->bankOfCustomers;
			for (auto it = clist.begin(); it != clist.end(); it++) {
				if (strcmp(name, (*it)->getName()) == 0) {
					result = (*it)->getStatement();
				}
			}
		}
		else if (strcmp(operation, "banktotalInserstPaid") == 0) {
			double num = bank->banktotalInserstPaid();
			double fnum = floor(num*10.f + 0.5) / 10.f;
			result = to_string(fnum);
			result = result.substr(0, result.length() - 5);
		}
		else if (strcmp(operation, "customsum") == 0) {
			result = bank->customsum();
		}
		else if (strcmp(operation, "end") == 0) {
			cout << result;
			result = "";
			account = new Account;
			customer = new Customer;
			bank = new Bank;
		}
	}
	//system("pause");
}