/*	increasingDigits
8.��ÿλ��������������
����һ���Ǹ����� N���ҳ�С�ڻ���� N ������������ͬʱ���������Ҫ���������λ���ϵ�
�����ǵ���������
�����ҽ���ÿ������λ���ϵ����� x �� y ���� x <= y ʱ�����ǳ���������ǵ��������ġ���
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