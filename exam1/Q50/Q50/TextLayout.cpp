#include<iostream>

using namespace std;

#define MAX 1000

//计算单词长度
int lenOfword(char* arr) {
	int len = 0;
	for (int i = 0; i < 100; i++) {
		if (arr[i] != '\0')
			len++;
		else
			break;
	}
	return len;
}

//判断是否是回文
bool isHuiwen(char* arr) {
	int len = lenOfword(arr);
	int res = 0;
	for (int i = 0; i < len / 2; i++) {
		if (arr[i] != arr[len - i - 1]) {
			res = 1;
		}
	}

	if (res) {
		return false;
	}
	else {
		return true;
	}
}

int main() {
	char array[MAX];
	for (int i = 0; i < MAX; i++) {
		array[i] = '\0';
	}
	cin >> array;
	
	int width;
	cin >> width;

	int num;
	cin >> num;

	//查找单词
	char **word = new char*[num];
	for (int i = 0; i < num; i++) {
		word[i] = new char[100];
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 100; j++) {
			word[i][j] = '\0';
		}
	}

	for (int i = 0; i < num; i++) {
		cin >> word[i];
	}

	//输入
	char **res = new char*[1000];
	for (int i = 0; i < 1000; i++) {
		res[i] = new char[100];
	}
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 100; j++) {
			res[i][j] = '\0';
		}
	}

	//输出,每行width+2长
	char **ans = new char*[1000];
	for (int i = 0; i < 1000; i++) {
		ans[i] = new char[width + 2];
	}
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < width + 2; j++) {
			ans[i][j] = '\0';
		}
	}
	int hang = 0;

	//处理输入数据，存入array
	int flag = 0;
	int j = 0;
	for (int i = 1; i < MAX; i++) {
		if (array[i] == ',') {
			flag++;
			j = 0;
		}
		else if (array[i] != '"' & array[i] != ',' && array[i] != ']') {
			res[flag][j] = array[i];
			j++;
		}
		else if (array[i] == ']') {
			break;
		}
	}
	flag++;

	//文本排版
	int index = 0;
	int last = 0;
	int nowlen = 0;
	int count = 0;
	while (index < flag) {
		if(isHuiwen(res[index])){
			index++;
		}
		else {
			if ((nowlen + count) < width) {
				nowlen += lenOfword(res[index]);
				count++;
			}

			if (nowlen + count > width) {
				count--;

				int zilen = 0;
				for (int i = last; i < last + count; i++) {
					zilen += lenOfword(res[i]);
				}

				int kong = (width - zilen) / (count - 1);

				cout << "\"";
				for (int i = last; i < last + count; i++) {
					cout << res[i];
					if (i != last + count - 1) {
						for (int i = 0; i < kong; i++) {
							cout << " ";
						}
					}
				}
				cout << "\"" << endl;

				last = index;
				cout << last << endl;
				nowlen = 0;
				count = 0;
			}
			else {
				index++;
			}
		
		}
		
	}

	//输出
	/*
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < width + 2; j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}
	*/

	

	system("pause");
}