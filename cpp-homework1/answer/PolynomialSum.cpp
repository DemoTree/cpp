/*
多项式相加
一个多项式可以表达为x的各次幂与系数乘积的和，比如：
现在，你的程序要读入两个多项式，然后输出这两个多项式的和，即多项式的合并同类项。
输入格式：
总共要在两行输入两个多项式，每个多项式的输入格式如下：
2x^6 + 3x^5 + 12x^3
每两项之间的+号两边都有一个空格，x代表未知数，‘^’后面的数字代表的指数
注：给定的输入不一定是按照降幂排序
输出格式：
从最高幂开始降幂排序输出，如：
4x^6 + 6x^5 + 12x^3 + 12x^2 + 12x^1 + 40x^0
注：其中的x是小写字母x，并且+号两边有空格，如果某项的指数为0则不需要有那项。
*/


#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main() {
	string s,x;
	int c1[1000] = { 0 };
	int a, b;

	getline(cin, s);
	x = s;
	while (x.length() >= 4) {
		int temp1 = x.find('x');
		int temp2 = x.find('+');
		a = std::stoi(x.substr(0, temp1));
		b = std::stoi(x.substr(temp1 + 2, x.length()));
		x = x.substr(temp2+2, x.length());
		c1[b] = c1[b] + a;
	}

	

	/*
	stringstream ss;
		getline(cin, s);
		ss.clear();
		ss.str(s);
		while (1) {
			ss >> x;
			std::cout << x << endl;

			temp = x.find('x');
			std::cout << temp << endl;


			a = std::stoi(x.substr(0, temp));
			b = std::stoi(x.substr(temp + 2, x.length()));
			x = x.substr(temp, x.length());
			c1[b] = c1[b] + a;

			std::cout << a << endl;
			std::cout << b << endl;
			if (ss.fail())	break;
		}
		*/
	string result;
	system("pause");
}


//int cmp(pair<int, int>&x, pair<int, int>&y) {
//	return x.second > y.second;
//}


	/*
	vector<pair<int, int>> vec;
	string flag = "";
	for (map<int, int>::iterator temp = c1.begin(); temp != c1.end(); temp++){
		vec.push_back(make_pair(temp->first, temp->second));
		};

		sort(vec.begin(), vec.end(), cmp);

		for (int i = 0;i < vec.size();i++) {
				cout << vec[i].second << ":" << vec[i].second << endl;

		}
		*/