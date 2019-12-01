/*	increasingDigits
8.求每位单调递增的数字
给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的
数字是单调递增。
（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）
*/


#include<iostream>
#include<string>
#include<fstream>


using namespace std;

int main()
{
	int n;
	std::cin >> n;
	fstream f("\\Mac\Home\Documents\project\cpp\readme.txt", ios::app);
	f << n << endl;
	f.close();


	string num = to_string(n);
	int flag = num.size();

	for (int i = num.size() - 1; i >= 1; --i) {
		if (num[i] < num[i - 1]) {
			flag = i;
			num[i - 1] = num[i - 1] - 1;
		}
	}

	for (int i = flag;i < num.size();i++) {
		num[i] = '9';
	}

	int result = atoi(num.c_str());

	std::cout << result << endl;

	system("pause");

}