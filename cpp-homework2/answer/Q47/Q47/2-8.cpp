#include<iostream>

using namespace std;
#define MAX 99999

int main() {
	int res;
	char input[MAX];
	cin >> input;

	int len = 0;
	int num = 0;
	while (input[len] != ']') {
		if (input[len] == ',') {
			num++;
		}
		len++;
	}
	num++;

	int *array = new int[num];
	int flag = 0;
	for (int i = 0; i < num; i++) {
		array[i] = 0;
	}
	for(int i=1; i<len-1; i++){
		if (input[i] != ',') {
			array[flag] = array[flag]*10 + int(input[i]-'0');
		}
		else if (input[i] == ',') {
			flag++;
		}

	}
	
	int a = 0, b = 0;
	while (true) {
		a = array[array[a]];
		b = array[b];
		if (a == b) {
			a = 0;
			while (array[b] != array[a]) {
				a = array[a];
				b = array[b];
			}
			res = array[b];
			break;
		}
	}

	cout << res;
	system("pause");

}

