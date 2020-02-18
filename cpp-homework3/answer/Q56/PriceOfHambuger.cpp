#include<iostream>

using namespace std;

class Hambuger{
public:
	virtual int getPrice() = 0;
};

class Beef: public Hambuger{
public:
	int getPrice(){
		return 10;
	}
};

class Pork: public Hambuger{
public:
	int getPrice(){
		return 8;
	}
};

class Chicken: public Hambuger{
public:
	int getPrice(){
		return 7;
	}
};

class DecoratorHambuger: public Hambuger{
public:
	void Decorator(Hambuger* ham, int n1) {
		this->ham = ham;
		this->n1 = n1;
	}
	virtual int getPrice() {
		return ham->getPrice()*n1;
	}
	virtual void getNum(int num) = 0;
protected:
	Hambuger* ham;
	int n1;
};

class Lettuce: public DecoratorHambuger{
public:
	void getNum(int num) {
		this->num = num;
	}
	int getLettuce() {
		return 4;
	}
	int getPrice() {
		return getLettuce()*num + DecoratorHambuger::getPrice();
	}
protected:
	int num;
};

class Tomato: public DecoratorHambuger{
public:
	void getNum(int num) {
		this->num = num;
	}
	int getTomato() {
		return 3;
	}
	int getPrice() {
		return getTomato()*num + DecoratorHambuger::getPrice();
	}
protected:
	int num;
};

int main(){
	int meat, veg, n1, n2;
	cin >> meat >> n1;
	cin >> veg >> n2;
	Hambuger* hambuger = NULL;
	DecoratorHambuger* decorator = NULL;
	switch(meat){
		case 1:
			hambuger = new Beef;
			break;
		case 2:
			hambuger = new Pork;
			break;
		case 3:
			hambuger = new Chicken;
			break;
	}
	switch(veg){
		case 1:
			decorator = new Lettuce;
			break;
		case 2:
			decorator = new Tomato;
			break;
	}
	decorator->Decorator(hambuger, n1);
	decorator->getNum(n2);
	cout << decorator->getPrice();
}