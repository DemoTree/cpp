/*
�����������ж�[����]switch��case
�����������ж�
�ӿ���̨��ȡ6���������룬�ֱ�Ϊ������3����������ꡣ
����x1,y1,x2,y2,x3,y3��
ͨ�����������ж����������͡�
���������δ������£�
1����ֱͨ�������Ρ���ORT
2������ֱ�������Ρ���LRT
3����ͨ���������Ρ���OIT
4���ȱ������Ρ���ET
5����ͨ�����Ρ���OT
6�������γ������Ρ���NT
*/

#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<fstream>

using namespace std;

int main() {
	string s1;
	std::cin >> s1;
	fstream f("/Users/apple/Documents/project/cpp",ios::app);
	f<<s1<<;
	f.close();
	string result = "";

    int t1 = s1.find(",");
    int a1 = std::stoi(s1.substr(1,t1));
    string s2 = s1.substr(t1+1, s1.length());
    int t2 = s2.find(",");
    int a2 = std::stoi(s2.substr(0,t2));
    string s3 = s2.substr(t2+1, s2.length());
    int t3 = s3.find(",");
    int b1 = std::stoi(s3.substr(0,t3));
    string s4 = s3.substr(t3+1, s3.length());
    int t4 = s4.find(",");
    int b2 = std::stoi(s4.substr(0,t4));
    string s5 = s4.substr(t4+1, s4.length());
    int t5 = s5.find(",");
    int c1 = std::stoi(s5.substr(0,t5));
    string s6 = s5.substr(t5+1, s5.length());
    int c2 = std::stoi(s6.substr(0,s6.length()));

	double l1 = double(sqrt(double((a2-b2)*(a2-b2) + (a1-b1)*(a1-b1))));
	double l2 = double(sqrt(double((c2 - b2)*(c2 - b2) + (c1 - b1)*(c1 - b1))));
	double l3 = double(sqrt(double((a2 - c2)*(a2 - c2) + (a1 - c1)*(a1 - c1))));
	double L1 = (a2 - b2)*(a2 - b2) + (a1 - b1)*(a1 - b1);
	double L2 = (c2 - b2)*(c2 - b2) + (c1 - b1)*(c1 - b1);
	double L3 = (a2 - c2)*(a2 - c2) + (a1 - c1)*(a1 - c1);

	bool isOIT = false;

	if (l1 + l2 > l3 || l1 + l3 > l2 || l2 + l3 > l1) {
		if (L1 == L2 && L2 == L3) {
			result = "ET";
		}
		else if (L1 == L2 && L1 != L3) {
			isOIT = true;
			if (L1+L2==L3) {
				result = "LRT";
			}
			else {
				result = "OIT";
			}
		}
		else if (L1 == L3 && L2 != L1) {
			isOIT = true;
			if (L1 + L3 == L2) {
				result = "LRT";
			}
			else {
				result = "OIT";
			}
		}
		else if (L2 == L3 && L1 != L2) {
			isOIT = true;
			if (L3+L2==L1) {
				result = "LRT";
			}
			else {
				result = "OIT";
			}
		}
		else if (isOIT == false && (L1+L2==L3 || L1+L3==L2 || L3+L2==L1) ){
			result = "ORT";
		}
		else {
			result = "OT";
		}
	}
	else {
		result = "NT";
	}

	std::cout << result << endl;
	//std::cout << l1 << endl;
	//std::cout << l2 << endl;
	//std::cout << sqrt(18) << endl;
   
    system("pause");
}