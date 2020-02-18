#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
//C:\\Users\\zoe\\Documents\\q54.txt
    string input;
	ofstream mycout("C:\\Users\\zoe\\Documents\\q54.txt", ios::app);
	while (getline(cin, input)) {
		mycout << input << endl;

	}
	cin >> input;
	mycout << "done" << endl;
	mycout.close();
}

//按行读入
	std::ifstream myfile("/Users/zoe/Documents/project/cpp/cpp-homework3/answer/q53.txt");
	string temp; 
    if (!myfile.is_open()) 
    { 
        cout << "未成功打开文件" << endl; 
    }
    return 0;

