#include<iostream>
#include<string>

using namespace std;

int maxSum(int *array, int n);

int main() {
	string s;
	std::cin>>s;
	int a=s.find(',');
	int n=std::stoi(s.substr(1,a));

	int *array = new int[n];
	string ss = s.substr(a + 1, s.length());

	if (n == 1) {
		std::cout << ss.substr(0,ss.length()-1) << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				array[i] = std::stoi(ss.substr(0, ss.length() - 1));
			}
			else {
				int a = ss.find(',');
				array[i] = std::stoi(ss.substr(0, a));
				ss = ss.substr(a + 1, ss.length());
			}
			//std::cout << array[i] << endl;
		}

		std::cout << maxSum(array,n) << endl;
	}
	system("pause");
}

int maxSum(int *array, int n){
	int max = 0;
	int pos = 0;
	for (int i = 0;i < n;i++) {
		pos = array[i];
		for (int j = i;j < n;j++) {
			if (j == i) {
				if (pos > max) {
					max = pos;
				}
			}
			else {
				pos += array[j];
				if (pos >= max) {
					max = pos;
				}
			}
		}
	}
	return max;
	/*
	int max = array[0];
	int temp = array[0];
	int left = 0;
	int right = 0;
	for(int i=1; i<sizeof(array); i++){
		if(temp < 0){
			temp = array[i];
			left = i;
		}
		else{
			temp += array[i];
		}
		if(max < temp){
			max = temp;
			right = i;
		}
	}
	return max;
	*/
}