#include<iostream>
#include<list>

using namespace std;

const double MIN_CAR = 13.3;
const double MIN_PRO = 13.5;
const double MIN_DF = 3.3;
const double MAX_FAT = 10.3;

class Food {
private:
	double carbohydrate;
	double protein;
	double DF;
	double fat;
public:
	Food(double carbohydrate, double protein, double DF, double fat) {
		this->carbohydrate = carbohydrate;
		this->protein = protein;
		this->DF = DF;
		this->fat = fat;
	}
	double getCarbohydrate() {
		return carbohydrate;
	}
	double getProtein() {
		return protein;
	}
	double getDF() {
		return DF;
	}
	double getFat() {
		return fat;
	}
};

class Rice : public Food{
private:
	double carbohydrate;
	double protein;
	double DF;
	double fat;
public:
	Rice(double carbohydrate, double protein, double DF, double fat) :
		Food(carbohydrate, protein, DF, fat) {
		this->carbohydrate = carbohydrate;
	}
	double getCarbohydrate() {
		return carbohydrate;
	}
	double getProtein() {
		return protein;
	}
	double getDF() {
		return DF;
	}
	double getFat() {
		return fat;
	}
};

class Beef : public Food {
private:
	double carbohydrate;
	double protein;
	double DF;
	double fat;
public:
	Beef(double carbohydrate, double protein, double DF, double fat) :
		Food(carbohydrate, protein, DF, fat) {
		this->carbohydrate = carbohydrate;
	}
	double getCarbohydrate() {
		return carbohydrate;
	}
	double getProtein() {
		return protein;
	}
	double getDF() {
		return DF;
	}
	double getFat() {
		return fat;
	}
};

class Bro : public Food {
private:
	double carbohydrate;
	double protein;
	double DF;
	double fat;
public:
	Bro(double carbohydrate, double protein, double DF, double fat) :
		Food(carbohydrate, protein, DF, fat) {
		this->carbohydrate = carbohydrate;
	}
	double getCarbohydrate() {
		return carbohydrate;
	}
	double getProtein() {
		return protein;
	}
	double getDF() {
		return DF;
	}
	double getFat() {
		return fat;
	}
};

class Oat : public Food {
private:
	double carbohydrate;
	double protein;
	double DF;
	double fat;
public:
	Oat(double carbohydrate, double protein, double DF, double fat) :
		Food(carbohydrate, protein, DF, fat) {
		this->carbohydrate = carbohydrate;
	}
	double getCarbohydrate() {
		return carbohydrate;
	}
	double getProtein() {
		return protein;
	}
	double getDF() {
		return DF;
	}
	double getFat() {
		return fat;
	}
};

class Duck : public Food {
private:
	double carbohydrate;
	double protein;
	double DF;
	double fat;
public:
	Duck(double carbohydrate, double protein, double DF, double fat) :
		Food(carbohydrate, protein, DF, fat) {
		this->carbohydrate = carbohydrate;
	}
	double getCarbohydrate() {
		return carbohydrate;
	}
	double getProtein() {
		return protein;
	}
	double getDF() {
		return DF;
	}
	double getFat() {
		return fat;
	}
};

class Cab : public Food {
private:
	double carbohydrate;
	double protein;
	double DF;
	double fat;
public:
	Cab(double carbohydrate, double protein, double DF, double fat) :
		Food(carbohydrate, protein, DF, fat) {
		this->carbohydrate = carbohydrate;
	}
	double getCarbohydrate() {
		return carbohydrate;
	}
	double getProtein() {
		return protein;
	}
	double getDF() {
		return DF;
	}
	double getFat() {
		return fat;
	}
};



class Factory {
public:
	static Food* getFood(int type) {
		switch (type) {
			case 1:
				return new Rice(16.2, 3.7, 0, 0);
			case 2:
				return new Beef(1.8, 17.5, 0, 7.2);
			case 3:
				return new Bro(0.2, 0.4, 3.6, 0);
			case 4:
				return new Oat(12.3, 5.7, 7.3, 3);
			case 5:
				return new Duck(6.9, 9, 0, 9.3);
			case 6:
				return new Cab(2.1, 0.8, 4.3, 0);
		}
		return 0;
	};
};

class Diet {
public:
	list<Food*> foodlist;

	Diet& operator+=(Food* food) {
		foodlist.push_back(food);
		return *this;
	}

	static bool if_healthy(int x1, int x2, int x3);
};

bool Diet::if_healthy(int x1, int x2, int x3) {
	Diet diet;
	diet += Factory::getFood(x1);
	diet += Factory::getFood(x2);
	diet += Factory::getFood(x3);

	double sum_car = 0;
	double sum_pro = 0;
	double sum_DF = 0;
	double sum_fat = 0;
	list<Food*> foodlist = diet.foodlist;
	for (list<Food*>::iterator itr = foodlist.begin(); itr != foodlist.end(); itr++) {
		sum_car = sum_car + (*itr)->getCarbohydrate();
		sum_pro = sum_pro + (*itr)->getProtein(); 
		sum_DF = sum_DF + (*itr)->getDF();
		sum_fat = sum_fat + (*itr)->getFat();
	}

	if (sum_car >= MIN_CAR && sum_pro >= MIN_PRO && sum_DF >= MIN_DF && sum_fat <= MAX_FAT) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int x1, x2, x3;
	cin >> x1 >> x2 >> x3;
	
	if (x1 >= 0 && x1 <= 6 && x2 >= 0 && x2 <= 6 && x3 >= 0 && x3 <= 6) {
		if (Diet::if_healthy(x1, x2, x3)) {
			cout << "healthy";
		}
		else {
			cout << "unhealthy";
		}
	}
	else {
		cout << -1;
	}

	//system("pause");
}