#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define SIZE 40

int snumber = 0;
int gnumber = 0;
int shapes[SIZE][6] = { 0 };
int groups[SIZE][4] = { 0 };

class Shape {
private:
	int x;
	int y;
	int z;
public:
	Shape(int input_x, int input_y, int input_z) {
		this->x = input_x;
		this->y = input_y;
		this->z = input_z;
	};
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getZ() = 0;
};

class Normal :public Shape {
private:
	int x;
	int y;
	int z;
public:
	Normal(int x, int y, int z) :
		Shape(x, y, z) {
		this->x = x;
		this->y = y;
		this->z = z;
	};
	int getX() override{
		return x;
	}
	int getY() override {
		return y;
	}
	int getZ() override {
		return z;
	}
};

class Reserve :public Shape {
private:
	int x;
	int y;
	int z;
public:
	Reserve(int x, int y, int z) :
		Shape(x, y, z) {
		this->x = x;
		this->y = y;
		this->z = z;
	};
	int getX() override {
		return 255 - x;
	}
	int getY() override {
		return 255 - y;
	}
	int getZ() override {
		return 255 - z;
	}
};

class Single :public Shape {
private:
	int x;
	int y;
	int z;
public:
	Single(int x, int y, int z) :
		Shape(x, y, z) {
		this->x = x;
		this->y = y;
		this->z = z;
	};
	int getX() override {
		return x;
	}
	int getY() override {
		return 0;
	}
	int getZ() override {
		return 0;
	}
};

class Factory {
public:
	static Shape* getType(int type, int a, int b, int c) {
		switch (type) {
		case 1:
			return new Normal(a, b, c);
		case 2:
			return new Reserve(a, b, c);
		case 3:
			return new Single(a, b, c);
		}
		return 0;
	}
};

void createShape(int type, int id, int i) {
	shapes[i][0] = id;
	shapes[i][1] = type;
	shapes[i][2] = 0;
	shapes[i][3] = 0;
	shapes[i][4] = 0;
	shapes[i][5] = 0;
}

void setColor(int id, int a, int b, int c) {
	for (int i = 0; i < snumber; i++) {
		if (shapes[i][0] == id) {
			Shape* shape = Factory::getType(shapes[i][1], a, b, c);
			shapes[i][2] = shape->getX();
			shapes[i][3] = shape->getY();
			shapes[i][4] = shape->getZ();
		}
	}
}

void createGroup1(int id, int id1, int i) {
	groups[i][0] = id;
	groups[i][1] = 1;
	groups[i][2] = id1;
	groups[i][3] = 0;
}

void createGroup2(int id, int id1, int id2, int i) {
	groups[i][0] = id;
	groups[i][1] = 2;
	groups[i][2] = id1;
	groups[i][3] = id2;
}

void setGroupColor(int id, int a, int b, int c) {
	for (int i = 0; i < gnumber; i++) {
		if (groups[i][0] == id) {
			if (groups[i][1] == 1) {
				setColor(groups[i][2], a, b, c);
			}
			else if (groups[i][1] == 2) {
				setColor(groups[i][2], a, b, c);
				setColor(groups[i][3], a, b, c);
			}
		}
	}
}

void sortedbyGray() {
	double **gray = new double*[snumber];
	double temp[SIZE];
	int zero = 0;
	for (int j = 0; j < snumber; j++) {
		gray[j] = new double[2];
	}
	for (int i = 0; i < snumber; i++) {
		gray[i][0] = shapes[i][0];
		gray[i][1] = shapes[i][2] * 0.299 + shapes[i][3] * 0.587 + shapes[i][4] * 0.114;
		temp[i] = gray[i][1];
		if (temp[i] == 0) {
			zero++;
		}
	}

	double t = 0;
	for (int i = 0; i < snumber; i++) {
		for (int j = 0; j < snumber; j++) {
			if (temp[i] < temp[j]) {
				t = temp[i];
				temp[i] = temp[j];
				temp[j] = t;
			}
		}
	}
	//0
	int tempid[SIZE];
	int n = 0;
	for (int i = 0; i < snumber; i++) {
		if (gray[i][1] == 0) {
			tempid[n] = shapes[i][0];
			n++;
		}
	}

	int tt = 0;
	for (int i = 0; i < zero; i++) {
		for (int j = 0; j < zero; j++) {
			if (tempid[i] < tempid[j]) {
				tt = tempid[i];
				tempid[i] = tempid[j];
				tempid[j] = tt;
			}
		}
	}

	for (int i = 0; i < snumber; i++) {
		for (int j = 0; j < snumber; j++) {
			if (tempid[i] == shapes[j][0]) {
				cout << "P" << shapes[j][0] << " " << shapes[j][2] << " " << shapes[j][3] << " " << shapes[j][4] << endl;
			}
		}
	}
	
	for (int i = 0; i < snumber; i++) {
		for (int j = 0; j < snumber; j++) {
			if (temp[i] == gray[j][1] && temp[i] != 0) {
				cout << "P" << shapes[j][0] << " " << shapes[j][2] << " " << shapes[j][3] << " " << shapes[j][4] << endl;
			}
		}
	}
}

void sortedbyNormal() {
	int temp[SIZE];
	int t = 0;
	for (int i = 0; i < snumber; i++) {
		temp[i] = shapes[i][0];
	}
	for (int i = 0; i < snumber; i++) {
		for (int j = 0; j < snumber; j++) {
			if (temp[i] < temp[j]) {
				t = temp[i];
				temp[i] = temp[j];
				temp[j] = t;
			}
		}
	}
	for (int i = 0; i < snumber; i++) {
		for (int j = 0; j < snumber; j++) {
			if (temp[i] == shapes[j][0]) {
				cout << "P" << shapes[j][0] << " " << shapes[j][2] << " " << shapes[j][3] << " " << shapes[j][4] << endl;
			}
		}
	}
}

int main() {
	int num;
	std::cin >> num;
	char* operation = new char[10];
	for (int k = 0; k < num; k++) {
		std::cin >> operation;
		if (strcmp(operation, "Add") == 0) {
			char* name = new char[10];
			char* ploygonid = new char[10];
			int type = 0;
			std::cin >> name >> ploygonid;
			if (strcmp(name, "normal") == 0) {
				type = 1;
			}
			else if (strcmp(name, "reverse") == 0) {
				type = 2;
			}
			else if (strcmp(name, "single") == 0) {
				type = 3;
			}
			string sid = ploygonid;
			sid.erase(0, 1);
			int id = stoi(sid);
			createShape(type, id, snumber);
			snumber++;
		}
		else if (strcmp(operation, "Set") == 0) {
			char* ploygonid = new char[10];
			int a, b, c;
			std::cin >> ploygonid >> a >> b >> c;
			string sid = ploygonid;
			string label = sid.substr(0, 1);
			sid.erase(0, 1);
			int id = stoi(sid);
			if (label == "P") {
				setColor(id, a, b, c);
			}
			else if (label == "G") {
				setGroupColor(id, a, b, c);
			}
		}
		else if (strcmp(operation, "Group") == 0) {
			int num, id1, id2;
			std::cin >> num; 
			if (num == 1) {
				char* ploygonid = new char[10];
				std::cin >> ploygonid;
				string pid = ploygonid;
				pid.erase(0, 1);
				id1 = stoi(pid);

				char* groupid = new char[10];
				std::cin >> groupid;
				string gid = groupid;
				gid.erase(0, 1);
				int id = stoi(gid);
				createGroup1(id, id1, gnumber);
			}
			else if (num == 2) {
				char* ploygonid1 = new char[10];
				std::cin >> ploygonid1;
				string pid1 = ploygonid1;
				pid1.erase(0, 1);
				id1 = stoi(pid1);

				char* ploygonid2 = new char[10];
				std::cin >> ploygonid2;
				string pid2 = ploygonid2;
				pid2.erase(0, 1);
				id2 = stoi(pid2);

				char* groupid = new char[10];
				std::cin >> groupid;
				string gid = groupid;
				gid.erase(0, 1);
				int id = stoi(gid);
				createGroup2(id, id1, id2, gnumber);
			}
			gnumber++;
		}
	}
	cin >> operation;
	if (strcmp(operation, "Gray") == 0) {
		sortedbyGray();
	}
	else if (strcmp(operation, "Normal") == 0) {
		sortedbyNormal();
	}

	//system("pause");
}