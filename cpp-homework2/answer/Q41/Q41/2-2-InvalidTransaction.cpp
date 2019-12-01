#include<iostream>

using namespace std;
#define MAX 9999

struct Info{
	char name[11];
	char time[6];
	char amount[5];	
	char city[11];
	bool valid;
};

int my_strcmp(char *a, char*b){
	while (*a == *b) {
        if (*a == '\0')
            return 0;
        
        ++a;
        ++b;
    }
    int re;
    if(*a - *b==0){
    	re=0;
    }else{
    	re=1;
    }
    return re;
}


int main() {
	Info inf[300];
	char *input = new char[MAX];
	cin >> input;
	if (input[0] == '['&&input[1] == ']') {
		cout << "[]";
	}
	else {
		//交易数量
		int num = 0;
		//input长度
		int len = 0;
		while (input[len] != '\0') {
			if (input[len] == ',' && input[len + 1] == '\"') {
				num++;
			}
			len++;
		}
		len++;
		num++;

		if (num == 0) {
			cout << "[]";
		}
		else {
			int j = 0, in = 0, it = 0, ia = 0, ic = 0, time = 1;
			for (int i = 2; i < len - 2; i++) {
				inf[j].valid = true;
				if (input[i] != '\"') {
					if (input[i] == ',') time++;
					else if (time == 1) {
						inf[j].name[in] = input[i];
						in++;
					}
					else if (time == 2) {
						inf[j].time[it] = input[i];
						it++;
					}
					else if (time == 3) {
						inf[j].amount[ia] = input[i];
						ia++;
					}
					else if (time == 4) {
						inf[j].city[ic] = input[i];
						ic++;
					}
				}
				else if (input[i] == '\"'&&input[i - 1] == ',') {
					j++;
					in = 0, it = 0, ia = 0, ic = 0, time = 1;
				}
			}
			for (int i = 0; i < num; i++) {
				int a, b, c;
				a = atoi(inf[i].amount);
				b = atoi(inf[i].time);
				if (a > 1000) inf[i].valid = false;
				for (int j = i; j < num; j++) {
					c = atoi(inf[j].time);
					int temp = 0;
					if (b > c) {
						temp = c;
						c = b;
						b = temp;
					}
					int cmpn = my_strcmp(inf[i].name, inf[j].name);
					int cmpc = my_strcmp(inf[i].city, inf[j].city);
					if (i != j && cmpn == 0 && cmpc == 1 && (c - b <= 60)) {
						inf[i].valid = false;
						inf[j].valid = false;
					}

				}

			}

			cout << "[";
			int flag = 0;
			for (int i = 0; i < num; i++) {
				if (inf[i].valid == false) {
					if (flag == 0) {
						cout << "\"" << inf[i].name << "," << inf[i].time << "," << inf[i].amount << "," << inf[i].city << "\"";
						flag++;
					}
					else {
						cout << ",\"" << inf[i].name << "," << inf[i].time << "," << inf[i].amount << "," << inf[i].city << "\"";
						flag++;
					}
				}
			}
			cout << "]";
		}

	}
}