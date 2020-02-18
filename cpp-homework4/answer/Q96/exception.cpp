#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class NothingLeftException :public exception {
public:
	void printMsg() {
		cout << "Nothing Left" << endl;
	}
};

class NoSuchCommodityException :public exception {
public:
	void printMsg() {
		cout << "No Such Commodity" << endl;
	}
};

class OverflowException :public exception {
public:
	void printMsg() {
		cout << "Overflow" << endl;
	}
};

class CanNotAffordException :public exception {
public:	
	void printMsg() {
		cout << "Can not Afford" << endl;
	}
};

class Commodity {
protected:
	int id;
	double price;
	int number = 0;
public:
	Commodity(int id) {
		this->id = id;
	}

	double getPrice() {
		return price;
	}

	int getId() {
		return id;
	}

	void buyItem() {
		number++;
	}

	void sellItem() {
		number--;
	}

	int getNum() {
		return number;
	}
};

class Commodity1 : public Commodity {
public:
	Commodity1(int id) :Commodity(id) {
		this->id = id;
		this->price = 10;
	}
};

class Commodity2 : public Commodity {
public:
	Commodity2(int id) :Commodity(id) {
		this->id = id;
		this->price = 15;
	}
};

class Commodity3 : public Commodity {
public:
	Commodity3(int id) :Commodity(id) {
		this->id = id;
		this->price = 20;
	}
};

class Factory {
public:
	static Commodity* getCommodity(int id) {
		switch (id) {
		case 1:
			return new Commodity1(id);
			break;
		case 2:
			return new Commodity2(id);
			break;
		case 3:
			return new Commodity3(id);
			break;
		}
		return 0;
	}
};

class Bourse {
private:
	int max;
	double money;
	vector<Commodity*> factory;
public:
	Bourse(int max, double money) {
		this->max = max;
		this->money = money;
	}

	void buy(Commodity* item) {
		if (getSum() + 1 > max) {
			throw OverflowException();
		}
		if (money < item->getPrice()) {
			throw CanNotAffordException();
		}

		int amount = getAmount(item);
		if (amount == 0) {
			factory.push_back(item);
			for (auto itr = factory.begin(); itr != factory.end(); itr++) {
				if ((*itr)->getId() == item->getId()) {
					(*itr)->buyItem();
				}
			}
		}
		else {
			for (auto itr = factory.begin(); itr != factory.end(); itr++) {
				if ((*itr)->getId() == item->getId()) {
					(*itr)->buyItem();
				}
			}
		}

		money -= item->getPrice();
		cout << money << endl;
	}

	void sell(Commodity* item) {
		if (getSum() == 0) {
			throw NothingLeftException();
		}

		int amount = getAmount(item);
		if (amount < 1) {
			throw NoSuchCommodityException();
		}

		money += item->getPrice()*1.2;

		for (auto itr = factory.begin(); itr != factory.end(); itr++) {
			if ((*itr)->getId() == item->getId()) {
				(*itr)->sellItem();
			}
		}

		cout << money << endl;
	}

	int  getAmount(Commodity* item) {
		int amount = 0;
		for (auto itr = factory.begin(); itr != factory.end(); itr++) {
			if ((*itr)->getId() == item->getId()) {
				amount++;
			}
		}
		return amount;
	}

	int getSum() {
		int sum = 0;
		for (auto itr = factory.begin(); itr != factory.end(); itr++) {
			sum = sum + (*itr)->getNum();
		}
		return sum;
	}
};

int main() {
	int max;
	double money;
	cin >> max >> money;
	Bourse bourse(max, money);

	int type, id;
	while (1) {
		cin >> type;

		try {
			if (type == -1) {
				break;
			}
			else {
				cin >> id;
				Commodity* item = Factory::getCommodity(id);
				if (type == 1) {//进货
					bourse.buy(item);
				}
				else if (type == 0) {//销售
					bourse.sell(item);
				}
			}
		}
		catch (NothingLeftException e1) {
			e1.printMsg();
		}
		catch (NoSuchCommodityException e2) {
			e2.printMsg();
		}
		catch (OverflowException e3) {
			e3.printMsg();
		}
		catch (CanNotAffordException e4) {
			e4.printMsg();
		}
	}

	system("pause");
}