#include<iostream>
#include<string>
#include<fstream>
#include<map>

using namespace std;

int main() {
	//按行读入
	std::ifstream myfile("/Users/apple/Documents/project/cpp/t/Q30/input.txt");
	string temp; 
    if (!myfile.is_open()) 
    { 
        cout << "未成功打开文件" << endl; 
    } 

    map<string, int> num;
    while(getline(myfile,temp)) 
    {      
   } 
   while (in >> c) { 
		stringNum[c]++; 
	}
	for (map<string, int>::iterator it = stringNum.begin(); it != stringNum.end(); it++)
	{
		cout << it->first << " : " << it->second << endl;
	}
	myfile.close(); 
	system("pause");
}