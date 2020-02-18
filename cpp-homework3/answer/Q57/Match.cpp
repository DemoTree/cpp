#include<iostream>

using namespace std;

class Role {
public:
	virtual int getHp() = 0;
	virtual int getAtk() = 0;
	virtual const char* getName() = 0;
};

class Warrior :public Role {
public:
	int getHp() {
		return 12;
	}
	int getAtk() {
		return 2;
	}
	const char* getName() {
		return "Warrior";
	}
};

class Magician :public Role {
public:
	int getHp() {
		return 2;
	}
	int getAtk() {
		return 6;
	}
	const char* getName() {
		return "Magician";
	}
};

class Leader :public Role {
public:
	int getHp() {
		return 6;
	}
	int getAtk() {
		return 6;
	}
	const char* getName() {
		return "Leader";
	}
};

class Factory {
public:
	static Role* getRole(int type) {
		switch (type) {
		case 1:
			return new Warrior;
		case 2:
			return new Magician;
		case 3:
			return new Leader;
		}
		return 0;
	}
};

int battle(int id1, int* hp1, int* atk1, int* time1, int id2, int* hp2, int* atk2, int* time2) {
	while (!(hp1 <= 0 || hp2 <= 0)) {
		if (id1 == 1) {
			*hp1 = *hp1 - *atk2;
			if (*hp1 > 0) {
				*hp1 = *hp1 + 1;
			}
		}
		else if (id1 == 2) {
			if (*time1 == 0) {
				*time1 = 1;
			}
			else {
				*hp1 = *hp1 - *atk2;
			}
		}
		else if (id1 == 3) {
			*hp1 = *hp1 - *atk2;
			if (*hp1 > 0) {
				*atk1 = *atk1 + 1;
			}
		}

			if (id2 == 1) {
				*hp2 = *hp2 - *atk1;
				if (*hp2 > 0) {
					*hp2 = *hp2 + 1;
				}
			}
			else if (id2 == 2) {
				if (*time2 == 0) {
					*time2 = 1;
				}
				else {
					*hp2 = *hp2 - *atk1;
				}
			}
			else if (id2 == 3) {
				*hp2 = *hp2 - *atk1;
				if (*hp2 > 0) {
					*atk2 = *atk2 + 1;
				}
			}

		int result = -1;
		if (*hp1 <= 0 && *hp2 <= 0) {
			result = 0;//Tie
		}
		else if (*hp1 <= 0) {
			result = 2;//Player 2 Win
		}
		else if (*hp2 <= 0) {
			result = 1;//Player 1 Win
		}
		return result;
	}
}

void getQuality(int type, int* hp, int* atk) {
	*hp = Factory::getRole(type)->getHp();
	*atk = Factory::getRole(type)->getAtk();
}

void output(int type) {

}

int main() {
	int num;
	int result = -1;
	int x = 0;
	int y = 0;
	cin >> num;
	int* list1 = new int[num];
	int* list2 = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> list1[i];
	}
	for (int i = 0; i < num; i++) {
		cin >> list2[i];
	}

	int hp1 = 0;
	int hp2 = 0;
	int atk1 = 0;
	int atk2 = 0;
	int time1 = 0;
	int time2 = 0;
	getQuality(list1[x], &hp1, &atk1);
	getQuality(list2[y], &hp2, &atk2);

	while (!(x >= num || y >= num)) {
		//Player 1 Win
		if (result == 1) {
			getQuality(list2[y], &hp2, &atk2);
			time2 = 0;
		}//Player 2 Win
		else if (result == 2) {
			getQuality(list1[x], &hp1, &atk1);
			time1 = 0;
		}//Tie
		else if(result == 0){
			getQuality(list1[x], &hp1, &atk1);
			getQuality(list2[y], &hp2, &atk2);
			time1 = 0;
			time2 = 0;
		}

		//cout << "begin: " << hp1 << " " << atk1 << " " << hp2 << " " << atk2 << endl;
		result = battle(list1[x], &hp1, &atk1, &time1, list2[y], &hp2, &atk2, &time2);
		//cout << "result: " << result << " " << x << " " << y << endl;
		//cout << "end: " << hp1 << " " << atk1 << " " << hp2 << " " << atk2 << endl;

		if (result == 1) {
			y++;
		}
		else if (result == 2) {
			x++;
		}
		else if (result == 0) {
			x++;
			y++;
		}
	}

		if ((num == 1 && result == 0) || (x == num && y == num)) {
			cout << "All Dead";
		}
		else {
			int type = 0;
			if (result == 1 || (result==0 && x < y)) {
				if (result == 0) {
					getQuality(list1[x], &hp1, &atk1);
				}
				while (x < num) {	
					type = list1[x];
					switch (type) {
					case 1:
						cout << "Warrior ";
						break;
					case 2:
						cout << "Magician ";
						break;
					case 3:
						cout << "Leader ";
						break;
					}
					cout << atk1 << " " << hp1;

					x++;
					if (x < num) {
						getQuality(list1[x], &hp1, &atk1);
						cout << endl;
					}
				}
			}
			else if (result == 2 || (result == 0 && x > y)) {
				if (result == 0) {
					getQuality(list2[y], &hp2, &atk2);
				}
				while (y < num) {
					type = list2[y];
					switch (type) {
					case 1:
						cout << "Warrior ";
						break;
					case 2:
						cout << "Magician ";
						break;
					case 3:
						cout << "Leader ";
						break;
					}
					cout << atk2 << " " << hp2;

					y++;
					if (y < num) {
						getQuality(list2[y], &hp2, &atk2);
						cout << endl;
					}
				}
			}
		}

	//system("pause");
}