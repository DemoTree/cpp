/*
回溯
 */

#include<iostream>
#include<string>

using namespace std;
bool isValid(string s);


int main() {
	string ip;
  	std::cin >> ip;
  	int len = ip.length();
  	int result = 0;

	
		for (int i = 0; i < 3; i++)
		{
			for (int m = 0, j = i + 1; m < 3 && j < len; j++, m++)
			{
				for (int n = 0, k = j + 1; n < 3 && k < len; n++, k++)
				{
					string tmp1 = ip.substr(0, i + 1);
					string tmp2 = ip.substr(i + 1, m + 1);
					string tmp3 = ip.substr(j + 1, n + 1);
					string tmp4 = ip.substr(k + 1, len);

					if (isValid(tmp1) && isValid(tmp2) && isValid(tmp3) && isValid(tmp4) 
						&& tmp2[0]!=0 && tmp3[0]!=0 && tmp4[0]!=0)
					{
						result++;
					}

				}
			}
		}
	

    std::cout<<result<<endl;
	system("pause");
}

bool isValid(string s){
	if(s.length==1)
	if (s.length()<=0 || s.length()>3) 
		return false;
	
	int num = stoi(s);
	if(num>=0&&num<=255)
		return true;
	else
		return false;
}