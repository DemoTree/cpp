/* ����ʽ���
2x^6 + 3x^5 + 12x^3
������ݿ�ʼ��������������磺
4x^6 + 6x^5 + 12x^3 + 12x^2 + 12x^1 + 40x^0
ע�����е�x��Сд��ĸx������+�������пո����ĳ���ָ��Ϊ0����Ҫ�����
*/


#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

//int cmp(pair<int, int>&x, pair<int, int>&y) {
//	return x.second > y.second;
//}

int main() {
	string s, x, xx, ss;

	int a, b;
	int max=0;
	map<int, int> c1;
	getline(cin, s);
	x = s;
	int temp1,temp2;
	do{
		temp1 = x.find('x');
		temp2 = x.find('+');
		a = std::stoi(x.substr(0, temp1));
		if (temp2 == -1) {
			b = std::stoi(x.substr(temp1 + 2, x.length()));
		}else{
			b = std::stoi(x.substr(temp1 + 2, temp2 - 1));
		}
		x = x.substr(temp2 + 2, x.length());
		c1[b] += a;
		if (b > max) {
			max = b;
		}
	} while (temp2 != -1);


	getline(cin, ss);
	xx = ss;
	int ttemp1, ttemp2;
	do {
		ttemp1 = xx.find('x');
		ttemp2 = xx.find('+');
		a = std::stoi(xx.substr(0, ttemp1));
		if (ttemp2 == -1) {
			b = std::stoi(xx.substr(ttemp1 + 2, xx.length()));
		}
		else {
			b = std::stoi(xx.substr(ttemp1 + 2,ttemp2 - 1));
		}		
		xx = xx.substr(ttemp2 + 2, xx.length());
		c1[b] += a;
		if (b > max) {
			max = b;
		}
	} while (ttemp2 != -1);

	string res = "";
	for (int i = max ; i >= 0; i--) {

		if (c1[i] != 0) {
			res += to_string(c1[i]) + "x^" + to_string(i);
			if (i != 0) {
				res += " + ";
			}
		}
		
	}

	cout << res <<endl;

	system("pause");
}