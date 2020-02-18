#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Car {
protected:
	int id;
	int type;
	int space;
	int park_time;
	int wait_time;
	double money;
public:
	Car(int id, int type) {
		this->id = id;
		this->type = type;
	};

	string getLabel() {
		string label = "";
		if (type == 1) {
			label += "S";
		}
		else if (type == 2) {
			label += "M";
		}
		else if (type == 3) {
			label += "L";
		}
		string sid = to_string(id);
		label += sid;
		return label;

	}

	int getSpace() {
		return this->space;
	}
	int getParktime() {
		return this->park_time;
	}
	int getWaittime() {
		return this->wait_time;
	}
	double getCost() {
		return this->money;
	}
	void wait() {
		this->wait_time--;
	}
	void park() {
		this->park_time--;
	}
	void leave() {
		Car car(id, type);
	}
	bool normalLeave() {
		if (park_time == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	bool advanceLeave() {
		if (wait_time == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

class S :public Car {
public:
	S(int id, int type): Car(id, type){
		this->space = 2;
		this->park_time = 3;
		this->wait_time = 1;
		this->money = 1.5;
	}
};

class M :public Car {
public:
	M(int id, int type) : Car(id, type) {
		this->space = 3;
		this->park_time = 2;
		this->wait_time = 2;
		this->money = 3;
	}
};

class L :public Car {
public:
	L(int id, int type) : Car(id, type) {
		this->space = 4;
		this->park_time = 1;
		this->wait_time = 3;
		this->money = 4.5;
	}
};

class Factory {
public:
	static Car* getCar(int id, int type) {
		switch (type) {
		case 1:
			return new S(id, type);
		case 2:
			return new M(id, type);
		case 3:
			return new L(id, type);
		}
		return 0;
	};
	static int getItype(char ctype) {
		int type = 0;
		if (ctype == 'S') {
			type = 1;
		}
		else if (ctype == 'M') {
			type = 2;
		}
		else if (ctype == 'L') {
			type = 3;
		}
		return type;
	}
};

class Park {
private:
	int weather;
	int space;
	double cost = 0;

public:
	vector<Car*> waiting;
	vector<Car*> parks;
	Park(int space, int weather) {
		this->space = space;
		this->parks = vector<Car*>(2 * space);
		this->weather = weather;
	};

	void addCar(int type, int id) {
		waiting.push_back(Factory::getCar(id, type));
	}

	//parking process
	void parkCar() {
		int state = -1;
		while (waiting.size() != 0) {
			state = getState(waiting[0]->getSpace());
			if (state == -1) {
				return;
			}
			else {
				parks[state] = waiting[0];
				waiting.erase(waiting.begin());
			}
		}
	}

	//find where to park
	int getState(int size) {
		int count = 0;
		int state = -1;
		for (auto i = 0; i < 2 * space; i++) {
			if (parks[i] == 0) {
				count++;
				if (count >= size) {
					state = i - size + 1;
					return state;
				}
			}
			else {
				i += parks[i]->getSpace() - 1;
				count = 0;
			}
		}
		return state;
	}

	void setOutput() {
		int zero = 0;
		for (auto i = 0; i < 2 * space; i++) {
			if (parks[i] != 0) {
				if (zero == 0) {
					cout << parks[i]->getLabel();
				}
				else {
					cout << " " << parks[i]->getLabel();
				}
				zero = 1;
				i += parks[i]->getSpace() - 1;
			}
		}
		if (zero == 0) {
			cout << "null";
		}
		cout << endl;
	}

	void current() {
		//parks
		for (int i = 0; i < 2 * space; i++) {
			if (parks[i] != 0) {
				parks[i]->park();
				if (parks[i]->normalLeave() == true) {
					cost += parks[i]->getCost();
					int temp = parks[i]->getSpace();
					parks[i]->leave();
					parks[i] = 0;
					i += temp - 1;
				}
			}
		}

		if (this->weather == 1) {
			int index = 0;
			int i = 0;
			while (i < 2 * space) {
				if (parks[i] != 0) {
					if (index != i) {
						parks[index] = parks[i];
						parks[i] = 0;
					}
					i += parks[index]->getSpace() - 1;
					index += parks[index]->getSpace();
				}	
				i++;
			}
		}

		//waiting
		for (auto i = 0; i < waiting.size(); i++) {
			waiting[i]->wait();
			if (waiting[i]->advanceLeave() == true) {
				waiting[i]->leave();
				waiting.erase(waiting.begin() + i);
				i--;
			}
		}
	}

	bool isEmpty() {
		auto itr = parks.begin();
		while (itr != parks.end()) {
			if (*itr != 0) {
				return false;
			}
			itr++;
		}
		return waiting.empty();
	}

	double getSumCost() {
		return cost;
	}

};

int main() {
	int size;
	char* sweather = new char[10];
	cin >> size >> sweather;
	int weather = 0;
	if (strcmp(sweather, "sunny") == 0) {
		weather = 1;
	}else if (strcmp(sweather, "rainy") == 0) {
		weather = 2;
	}
	Park park(size, weather);
	char* operation = new char[10];
	string s = "start";
	strcpy(operation, s.c_str());
	while (strcmp(operation, "end") != 0) {
		cin >> operation;
		if (strcmp(operation, "in") == 0) {
			char ctype;
			char* input_id = new char[5];
			cin >> ctype >> input_id;
			string sid = input_id;
			sid.erase(0, 1);
			int type = Factory::getItype(ctype);
			int id = stoi(sid);

			park.addCar(type, id);
			park.parkCar();
			park.setOutput();
			park.current();
			/*
			int index = 0;
			vector<Car*> vec = park.parks;
			for (auto itr = vec.begin(); itr != vec.end(); itr++) {
				if ((*itr) != 0) {
					cout << index <<":"<<(*itr)->getLabel() << endl;
				}
				index++;
			}
			*/
		}
		else if (strcmp(operation, "end") == 0) {
			while (park.isEmpty() == false) {
				park.parkCar();
				park.setOutput();
				park.current();
				/*
				vector<Car*> vec = park.parks;
				int index = 0;
				for (auto itr = vec.begin(); itr != vec.end(); itr++) {
					if ((*itr) != 0) {
						cout << index << ":" << (*itr)->getLabel() << endl;
					}
					index++;
				}
				*/
			}
			cout << "null" << endl;
			double final_cost = park.getSumCost();
			cout << final_cost;
		}		
	}
	system("pause");
}