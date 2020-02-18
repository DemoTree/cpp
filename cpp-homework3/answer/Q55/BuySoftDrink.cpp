#include <iostream>

using namespace std;

//库存数目大于 10 件
class DrinkOverflowException: public exception{
public:
	const char* what() {
		return "DrinkOverflow";
	}
};

//饮料数目不足
class DrinkNotFoundException : public exception {};

//仓库类，管理数量
class DrinkHouse{
private:
	int* drinks;
	DrinkHouse() {
		drinks = new int[4]{ 0, 0, 0, 0 };
	}		
public:
	static DrinkHouse* getInstance(){
		static DrinkHouse instance;
		return &instance;
	}
	void add(int type, int num){
		int sum = drinks[0] + drinks[1] + drinks[2] + drinks[3];
		if (sum + num > 10){
			throw DrinkOverflowException();
		}
		drinks[type - 1] += num;
	}
	int getNum(int type){
		return drinks[type - 1];
	}
};

class Product{
public:
	virtual void buy() = 0;
};

class Coffee: public Product{
public:
	void buy(){
		DrinkHouse::getInstance()->add(1, -1);
		std::cout << "coffee:5" << endl;
	}
};

class Milk: public Product{
public:
	void buy(){
		DrinkHouse::getInstance()->add(2, -1);
		cout << "milk:4" << endl;
	}
};

class Tea: public Product{
public:
	void buy(){
		DrinkHouse::getInstance()->add(3, -1);
		cout << "tea:3" << endl;
	}
};

class Beer: public Product{
public:
	void buy(){
		DrinkHouse::getInstance()->add(4, -1);
		cout << "beer:6" << endl;
	}
};

class Factory {
public:
	static Product* getDrink(int type)
	{
		if (DrinkHouse::getInstance()->getNum(type) <= 0){
			throw DrinkNotFoundException();
		}
		switch (type){
			case 1:
				return new Coffee;
			case 2:
				return new Milk;
			case 3:
				return new Tea;
			case 4:
				return new Beer;
		}
		return 0;
	}
};

int main(){
	int operation = 0;
	int type;
	int num;
	while(operation < 3){
		cin >> operation;
		switch(operation){
			case 1:
				cin >> type >> num;
				try{
					DrinkHouse::getInstance()->add(type, num);
				}catch (DrinkOverflowException e){
					cout << e.what() << endl;
				}
				break;
			case 2:
				cin >> type;
				try{
					Factory::getDrink(type)->buy();
				}catch (DrinkNotFoundException){
					switch (type){
						case 1:
							cout << "coffee";
							break;
						case 2:
							cout << "milk";
							break;
						case 3:
							cout << "tea";
							break;
						case 4:
							cout << "beer";
					}
					cout << " is not found" << endl;
				}
				break;
		}
		//cout << "coffee" << DrinkHouse::getInstance().getNum(1) << endl;
		//cout << "milk" << DrinkHouse::getInstance().getNum(2) << endl;
		//cout << "tea" << DrinkHouse::getInstance().getNum(3) << endl;
		//cout << "beer" << DrinkHouse::getInstance().getNum(4) << endl;
	}
	system("pause");
}