#include<iostream>
#include<string>
#include<fstream>
#include<map>

using namespace std;

int cmp(pair<int, int>&x, pair<int, int>&y) {
	return x.second > y.second;
}

int main() {
	//按行读入
	std::ifstream myfile("/Users/apple/Documents/project/cpp/t/Q30/input.txt");
	string temp; 
    if (!myfile.is_open()) 
    { 
        cout << "未成功打开文件" << endl; 
    } 

    map<string, int> num;
    if(index>='A'&&index<='Z'){
            s[i]+=32;
        }
    num[index]++;

	for (map<string, int>::iterator it = stringNum.begin(); it != stringNum.end(); it++)
	{
		cout << it->first << " : " << it->second << endl;
	}
	
	vector<pair<int, int>> vec;
	string flag = "";
	for (map<int, int>::iterator temp = c.begin(); temp != c1.end(); temp++){
		vec.push_back(make_pair(temp->first, temp->second));
		};

		sort(vec.begin(), vec.end(), cmp);

		for (int i = 0;i < vec.size();i++) {
				cout << vec[i].second << ":" << vec[i].second << endl;

	}
		





	myfile.close(); 
	system("pause");


}

