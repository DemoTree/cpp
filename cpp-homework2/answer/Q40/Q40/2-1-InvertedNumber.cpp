#include<iostream>

using namespace std;

int inverted(int *num, int len);

int main() {
	int res = 0;
	int len = 0;
	cin >> len;
	int * num = new int[len];
	int j = 0;
	while (j < len) {
		cin >> num[j];
		j++;
	}

	res = inverted(num, len);
	
	cout << res << endl;
	delete[] num;

	system("pause");
}

int inverted(int* array, int len) {
	int res = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			if (array[i] > array[j]) {
				res++;
			}
		}
	}
	return res;
}