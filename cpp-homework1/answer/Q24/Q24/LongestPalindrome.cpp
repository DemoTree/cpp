/*
Ѱ��������Ӵ�
����һ���ַ������������Ļ��������Ӵ������ļ�ָ����֮���ԭ�ַ�����ͬ���ַ�����
�硰abba����
����
���룺aykskksya
�����skks
*/

#include<iostream>
#include<string>
#include <algorithm>

using namespace std;


int main() {
	
	string s;
	getline(cin, s);
	string ans="";

	if ( s.length() == 1 || s.length()==0) {
		ans = s;
	}
	else {
		string r = "";
		for (int i = 0; i<s.length(); i++) {
			for (int j = i; j < s.length(); j++) {
				r = r + s[j];
				string temp = r;
				std::reverse(temp.begin(), temp.end());
				if (r == temp) {
					if (ans.length() <= r.length()) {
						ans = r;
					}
				}

			}
			r = "";
		}
	}
	std::cout << ans << endl;



	system("pause");
}