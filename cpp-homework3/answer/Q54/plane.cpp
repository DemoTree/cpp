#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

class Plane {
protected:
	int off_take = 0;
	int off_time = 0;
	int task_take = 0;
	int land_take = 0;
	int land_time = 0;
	int land_first_time = 0;
	int off_priority;
	int land_priority;
	int type;
	int id;
public:
	Plane(int id, int type) {
		this->id = id;
		this->type = type;
	}
	
	void reset(int off, int task, int land) {
		this->off_take = off;
		this->task_take = task;
		this->land_take = land;
	}

	int get_off_take() {
		return off_take;
	}

	int get_off_time() {
		return off_time;
	}

	int get_task_take() {
		return task_take;
	}

	int get_land_take() {
		return land_take;
	}

	int get_land_time() {
		return land_time;
	}

	int getId() {
		return id;
	}

	int get_off_priority() {
		return off_priority;
	}

	int get_land_priority() {
		return land_priority;
	}

	int get_land_first_time() {
		return land_first_time;
	}

	void set_land_first_time(int time) {
		this->land_first_time = time;
	}

	void set_off_time(int time) {
		this->off_time = time;
	}

	void set_land_time(int time) {
		this->land_time = time;
	}

	void landing(int time) {
		this->land_time =  time + this->land_take;
	}

	string getType() {
		string label = "";
		if (type == 1) {
			label = "battleplane";
		}
		else if (type == 2) {
			label = "transportplane";
		}
		else if (type == 3) {
			label = "helicopter";
		}
		return label;
	}

	void printNormalPlane() {
		cout << "p" << id << " " << getType() << " " << off_take << " " << task_take << " " << land_take << endl;
	}

	void printSchedulePlane() {
		cout << "p" << id << " " << off_time << " " << land_time << endl;
	}
};

class Battleplane :public Plane {
public:
	Battleplane(int id, int type) : Plane(id, type) {
		this->off_take = 2;
		this->task_take = 0;
		this->land_take = 2;
		this->off_priority = 2;
		this->land_priority = 2;
	}
};

class Transportplane :public Plane {
public:
	Transportplane(int id, int type) : Plane(id, type) {
		this->off_take = 3;
		this->task_take = 0;
		this->land_take = 3;
		this->off_priority = 1;
		this->land_priority = 3;
	}
};

class Helicopter :public Plane {
public:
	Helicopter(int id, int type) : Plane(id, type) {
		this->off_take = 1;
		this->task_take = 0;
		this->land_take = 1;
		this->off_priority = 3;
		this->land_priority = 1;
	}
};

class Factory {
public:
	static Plane* createPlane(int id, int type) {
		switch (type) {
		case 1:
			return new Battleplane(id, type);
		case 2:
			return new Transportplane(id, type);
		case 3:
			return new Helicopter(id, type);
		}
		return 0;
	};
	static int getItype(char* ctype) {
		int type = 0;
		if (strcmp(ctype, "battleplane") == 0) {
			type = 1;
		}
		else if (strcmp(ctype, "transportplane") == 0) {
			type = 2;
		}
		else if (strcmp(ctype, "helicopter") == 0) {
			type = 3;
		}
		return type;
	}
};

class Carrier {
public:
	int time = 0;
	map<int, Plane*> planes;
	vector<Plane*> offs;
	vector<Plane*> lands;
	vector<Plane*> landfirsts;
	vector<Plane*> schedules;//output
public:
	void addPlane(int id, int type) {
		planes[id] = Factory::createPlane(id, type);
	}

	void setPlane(int id, int off_take, int task_take, int land_take) {
		planes[id]->reset(off_take, task_take, land_take);
	}

	void joinPlane(int id, int time) {
		planes[id]->set_off_time(time);
		for (auto itr = offs.begin(); itr != offs.end(); itr++) {
			if (time > (*itr)->get_off_time()) {
				continue;
			}
			else if (time == (*itr)->get_off_time()) {
				if (planes[id]->get_off_priority() > (*itr)->get_off_priority()) {
					offs.insert(itr, planes[id]);
					return;
				}
				else if (planes[id]->get_off_priority() == (*itr)->get_off_priority()) {
					if (planes[id]->getId() < (*itr)->getId()) {
						offs.insert(itr, planes[id]);
						return;
					}
				}
			}
			else {
				offs.insert(itr, planes[id]);
				return;
			}
		}

		offs.push_back(planes[id]);
	}

	void landFirst(int id, int time) {
		planes[id]->set_land_first_time(time);
		landfirsts.push_back(planes[id]);
	}

	void scheduling() {
		int off_ptr = 0;
		int land_ptr = 0;
		do{
			//landfirst end>begin
			for (int i = landfirsts.size() - 1; i >= 0; i--) {
				if (landfirsts[i]->get_land_first_time() <= time) {
					landfirsts[i]->landing(time);
					schedules.push_back(landfirsts[i]);
					time += landfirsts[i]->get_off_take();
					for (int j = 0; j < lands.size(); j++) {
						if (landfirsts[i]->getId() == lands[j]->getId()) {
							lands.erase(lands.begin() + j);
						}
					}
					landfirsts.erase(landfirsts.begin() + i);
					break;
				}
			}

			//off
			if (off_ptr < offs.size()) {
				if (offs[off_ptr]->get_off_time() <= time) {
					offs[off_ptr]->set_off_time(time);
					setLand(offs[off_ptr], time);
					time += offs[off_ptr]->get_off_take();
					off_ptr++;
					continue;
				}
			}
			//land
			else if (land_ptr < lands.size()) {
				if (lands[land_ptr]->get_land_time() <= time) {
					lands[land_ptr]->landing(time);
					schedules.push_back(lands[land_ptr]);
					time += lands[land_ptr]->get_land_take();
					land_ptr++;
					continue;
				}
			}
			time++;
		} while (off_ptr < offs.size() || land_ptr < lands.size());
	}

	void setLand(Plane* plane, int off_time) {
		int land_time = off_time + plane->get_off_take() + plane->get_task_take();
		plane->set_land_time(land_time);
		for (auto itr = lands.begin(); itr != lands.end(); itr++) {
			if (land_time < (*itr)->get_land_time()) {
				lands.insert(itr, plane);
				return;
			}
			else if (land_time == (*itr)->get_land_time()) {
				if (plane->get_land_priority() > (*itr)->get_land_priority()) {
					lands.insert(itr, plane);
					return;
				}
				else if (plane->get_land_priority() == (*itr)->get_land_priority()) {
					if (plane->getId() < (*itr)->getId()) {
						lands.insert(itr, plane);
						return;
					}
				}
			}
		}
		lands.push_back(plane);
	}

	void printNormal() {
		map<int, Plane*>::iterator itr = planes.begin();
		while (itr != planes.end()) {
			itr->second->printNormalPlane();
			itr++;
		}
	}

	void printSchedule() {
		vector<Plane*>::iterator itr = schedules.begin();
		while (itr != schedules.end()) {
			(*itr)->printSchedulePlane();
			itr++;
		}
	}
};



int main() {
	Carrier carrier;
	int numOfOrder;
	cin >> numOfOrder;
	for (int i = 0; i < numOfOrder; i++) {
		char* operation = new char[10];
		cin >> operation;
		if (strcmp(operation, "add") == 0) {
			char* stype = new char[15];
			char* cid = new char[5];
			cin >> stype >> cid;
			string sid = cid;
			sid.erase(0, 1);
			int id = stoi(sid);
			int type = Factory::getItype(stype);
			carrier.addPlane(id, type);
		}
		else if (strcmp(operation, "set") == 0) {
			char* cid = new char[5];
			int a, b, c;
			cin >> cid >> a >> b >> c;
			string sid = cid;
			sid.erase(0, 1);
			int id = stoi(sid);
			carrier.setPlane(id, a, b, c);
		}
		else if (strcmp(operation, "join") == 0) {
			char* cid = new char[5];
			int join_time;
			cin >> cid >> join_time;
			string sid = cid;
			sid.erase(0, 1);
			int id = stoi(sid);
			carrier.joinPlane(id, join_time);
		}
		else if (strcmp(operation, "landfirst") == 0) {
			char* cid = new char[5];
			int land_time;
			cin >> land_time >> cid;
			string sid = cid;
			sid.erase(0, 1);
			int id = stoi(sid);
			carrier.landFirst(id, land_time);
		}
		else if (strcmp(operation, "normal") == 0) {
			carrier.printNormal();
		}
		else if (strcmp(operation, "schedule") == 0) {
			carrier.scheduling();
			carrier.printSchedule();
		}
	}
	system("pause");
}