/*
����ʽ���
һ������ʽ���Ա��Ϊx�ĸ�������ϵ���˻��ĺͣ����磺
���ڣ���ĳ���Ҫ������������ʽ��Ȼ���������������ʽ�ĺͣ�������ʽ�ĺϲ�ͬ���
�����ʽ��
�ܹ�Ҫ������������������ʽ��ÿ������ʽ�������ʽ���£�
2x^6 + 3x^5 + 12x^3
ÿ����֮���+�����߶���һ���ո�x����δ֪������^����������ִ����ָ��
ע�����������벻һ���ǰ��ս�������
�����ʽ��
������ݿ�ʼ��������������磺
4x^6 + 6x^5 + 12x^3 + 12x^2 + 12x^1 + 40x^0
ע�����е�x��Сд��ĸx������+�������пո����ĳ���ָ��Ϊ0����Ҫ�����
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