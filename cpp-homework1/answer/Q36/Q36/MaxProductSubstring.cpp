#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
	int n;
	std::cin >> n;
	int *array = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> array[i];
	}
	fstream f("\\Mac\Home\Documents\project\cpp\readme.txt", ios::app);
	f << n << array << endl;

	int max = 0;
	int pos = 1;
	int start = 0;
	int end = 0;
	for(int i=0; i<n; i++){
		int pos = array[i];
		for(int j=i; j<n; j++){
			if (j == i) {
				if (pos > max) {
					max = pos;
					start = i;
					end = j;
				}
			}
			else {
				pos *= array[j];
				if (pos > max) {
					max = pos;
					start = i;
					end = j;
				}
			}
		}
	}

	string result = "[";
	for(int k=start; k<=end; k++){
		if(k==end){
			result = result + std::to_string(array[k]) + "]";
		}else{
			result = result + std::to_string(array[k]) + ",";
		}
	}

	std:: cout << result << endl;
	system("pause");
}