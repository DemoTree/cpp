#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Task {
protected:
	int name;
	int type;
	int priority;
	int arrive_time;
	int task_take;
	int coreId = 0;
	int current_time;
public:
	Task(int name, int type, int priority, int arrive_time, int task_take) {
		this->name = name;
		this->type = type;
		this->priority = priority;
		this->arrive_time = arrive_time;
		this->task_take = task_take;
	}
	int get_name() {
		return name;
	}
	int get_priority() {
		return priority;
	}
	int get_arrive_time() {
		return arrive_time;
	}
	int get_task_take() {
		return task_take;
	}
	string get_type() {
		string label = "";
		if (type == 0) {
			label = "LoadDatabase";
		}
		else if (type == 1) {
			label = "ETL";
		}
		else if (type == 2) {
			label = "DataAnalyze";
		}
		return label;
	}
	void set_coreId(int coreId) {
		this->coreId = coreId;
	}
	int get_coreId() {
		return coreId;
	}
	void set_current_time(int time) {
		this->current_time = time;
	}
	int get_current_time() {
		return current_time;
	}

	void printLoad() {
		cout << "task " << name << " load: time " << 0 << " coreId " << coreId << " name task" 
			<< name << " type "<< get_type() << " priority " << priority << endl;
		cout << "task " << name << " execute: time " << 0 << " coreId " << coreId << endl;
	}
	void printFinish() {
		cout << "task " << name << " finish: time " << task_take << " coreId " << coreId << endl;
	}
	virtual void printExecute() = 0;
};

class LoadDatabase :public Task {
public:
	LoadDatabase(int name, int type, int priority, int arrive_time, int task_take) :Task(name, type, priority, arrive_time, task_take) {
		this->name = name;
		this->type = type;
		this->priority = priority;
		this->arrive_time = arrive_time;
		this->task_take = task_take;
	}
	void printExecute() override{
		cout << "task " << name << " --- Load driver" << endl;
		cout << "task " << name << " --- Establish a database connection" << endl;
		cout << "task " << name << " --- Create a Statement object" << endl;
		cout << "task " << name << " --- Execute SQL" << endl;
		cout << "task " << name << " --- Close the database" << endl;
	}
};

class ETL :public Task {
public:
	ETL(int name, int type, int priority, int arrive_time, int task_take) :Task(name, type, priority, arrive_time, task_take) {
		this->name = name;
		this->type = type;
		this->priority = priority;
		this->arrive_time = arrive_time;
		this->task_take = task_take;
	}
	void printExecute() override {
		cout << "task " << name << " --- Read data from a file" << endl;
		cout << "task " << name << " --- Data transform" << endl;
		cout << "task " << name << " --- Load data into the database" << endl;
	}

};

class DataAnalyze :public Task {
public:
	DataAnalyze(int name, int type, int priority, int arrive_time, int task_take) :Task(name, type, priority, arrive_time, task_take) {
		this->name = name;
		this->type = type;
		this->priority = priority;
		this->arrive_time = arrive_time;
		this->task_take = task_take;
	}
	void printExecute() override {
		cout << "task " << name << " --- Finding the center point" << endl;
		cout << "task " << name << " --- Data Classification" << endl;
		cout << "task " << name << " --- Data comparison" << endl;
		cout << "task " << name << " --- Data Display" << endl;
	}
};

class Factory {
public:
	static Task* createTask(int name, int type, int priority, int arrive_time, int task_take) {
		switch (type) {
		case 0:
			return new LoadDatabase(name, type, priority, arrive_time, task_take);
		case 1:
			return new ETL(name, type, priority, arrive_time, task_take);
		case 2:
			return new DataAnalyze(name, type, priority, arrive_time, task_take);
		}
		return 0;
	}
};

class CPU {
protected:
	int num;
	map<int, Task*> tasks;//存储所有任务
	int** cpus = new int*[num];
	int time = 0;
	vector<Task*> loads;//加载顺序
public:
	CPU(int numOfCPU) {
		this->num = numOfCPU;
	}
	void setCPU() {
		for (int i = 0; i < num; i++) {
			cpus[i] = new int[2];
			for (int j = 0; j < 2; j++) {
				cpus[i][j] = 0;
			}
		}
	}

	void addTask(int name, int type, int priority, int arrive_time, int task_take) {
		tasks[name] = Factory::createTask(name, type, priority, arrive_time, task_take);
	}

	//分配core
	void setTask(Task* task) {
		for (int i = 0; i < num; i++) {
			if (cpus[i][0] == 0) {
				task->set_coreId(i);
				cpus[i][0] = 1;
				cpus[i][1] = task->get_name();
			}
		}
	}

	//TODO 结束后释放CPU
	void freeTask() {

	 }

	//TODO 加载顺序队列
	void loading() {
		map<int, Task*>::iterator itr = tasks.begin();
		loads.push_back(itr->second);
		while (itr != tasks.end()) {
			if(itr!=tasks.begin()){
				for (auto itv = loads.begin(); itv != loads.end(); itv++) {
					if (itr->second->get_arrive_time() > (*itv)->get_arrive_time()) {
						//时间大的放在后面
						loads.push_back(itr->second);
					}
					else if (itr->second->get_arrive_time() < (*itv)->get_arrive_time()) {
						//时间小的放在前面
						loads.insert(itv, itr->second);
					}
					else {
						//时间相同的判断优先级
						if (itr->second->get_priority() > (*itv)->get_priority()) {
							//优先级数字小代表优先级大，放在前面
							loads.insert(itv, itr->second);
						}
						else {
							loads.push_back(itr->second);
						}
					}
				}
			}
			itr++;
		}
	}

	//TODO
	void printPSA() {
		//loading();
		//for (auto itr = loads.begin(); itr != loads.end(); itr++) {
			//cout << (*itr)->get_name() << " " << endl;
		//}
		map<int, Task*>::iterator itr = tasks.begin();
		while (itr != tasks.end()) {
			setTask(itr->second);
			itr->second->printLoad();
			itr->second->printExecute();
			itr->second->printFinish();
			itr++;
		}
	}

	//TODO
	void printHRRF() {
		map<int, Task*>::iterator itr = tasks.begin();
		while (itr != tasks.end()) {
			setTask(itr->second);
			itr->second->printLoad();
			itr->second->printExecute();
			itr->second->printFinish();
			itr++;
		}
	}

};

int main() {
	int numofCPU, numofTask;
	char* way = new char[5];
	cin >> numofCPU >> way >> numofTask;
	CPU cpu(numofCPU);
	cpu.setCPU();
	for (int i = 0; i < numofTask; i++) {
		int id, type, priority, arrive_time, task_take;
		char* cname = new char[5];
		cin >> id >> cname >> type >> priority >> arrive_time >> task_take;
		string sname = cname;
		sname.erase(0, 4);
		int name = stoi(sname);
		cpu.addTask(name, type, priority, arrive_time, task_take);
	}
	if (strcmp(way, "PSA") == 0) {
		cpu.printPSA();
	}
	else{
		cpu.printHRRF();
	}
	
	system("pause");
}