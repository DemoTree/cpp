/*
寻找最长回文子串
输入一个字符串，输出它最长的回文连续子串，回文即指逆序之后和原字符串相同的字符串，
如“abba”。
例：
输入：aykskksya
输出：skks
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