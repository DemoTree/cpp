#include<iostream>

using namespace std;

class GPU {
private:
	int price;
	int hashRate;
public:
	virtual double Caculate() = 0;
	int get_hashRate() {
		return hashRate;
	}
	int get_price() {
		return price;
	}
	friend istream &operator>>(istream &input, GPU &gpu) {
		input >> gpu.price >> gpu.hashRate;
		return input;
	}
};

class Type1 : public GPU {
public:
	double Caculate() override {
		return get_hashRate() * 0.02 - 16.2;
	}

};

class Type2 : public GPU {
public:
	double Caculate() override {
		return get_hashRate() * 0.02 - 28.8;
	}

};

class Type3 : public GPU {
public:
	double Caculate() override {
		return get_hashRate() * 0.02 - 19.44;	
	}

};

int main() {
	Type1 type1;
	Type2 type2;
	Type3 type3;
	cin >> type1;
	cin >> type2;
	cin >> type3;

	int price = type1.get_price() + type2.get_price() + type3.get_price();
	int income = -price;
	int day = 0;
	int sum = type1.Caculate() + type2.Caculate() + type3.Caculate();
	if (sum <= 0) {
		day = -1;
	}
	else {
		while (income < 0) {
			income = day * (type1.Caculate() + type2.Caculate() + type3.Caculate()) - price;
			day++;
		}
		day--;
	}
	
	cout << day;
}