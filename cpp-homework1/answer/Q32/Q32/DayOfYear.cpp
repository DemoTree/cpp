#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main() {
	string s;
	std::cin >> s;
	int result=0;
	char ss[11];

	//分割年月日
	int t1 = s.find("-");
	int year = std::stoi(s.substr(0, t1));
	string s1 = s.substr(t1+1, s.length());
	int t2 = s1.find("-");
	int month = std::stoi(s1.substr(0, t2));
	string s2 = s1.substr(t2+1, s1.length());
	int day = std::stoi(s2.substr(0, s2.length()));

	//月份天数
	int c1[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int c2[13] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	//判断闰年
	bool isLeap = false;
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				isLeap = true;
			else
				isLeap = false;
		}
		else
			isLeap = true;
	}
	else
		isLeap = false;

	//天数相加
	for (int i = 0; i < month-1; i++) {
		if (isLeap) {
			result = result + c2[i];
		}
		else {
			result = result + c1[i];
		}
	}
	result = result + day;

	std::cout << result <<endl;

	system("pause");
}