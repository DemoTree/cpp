#include<iostream>

using namespace std;
#define MAX 2000
int main() {
	char ch;
	int ich=0;
	int array[MAX];
	for (int i = 0; i < MAX; i++) {
		array[i] = 0;
	}
	int num = 0;
	int last = 0;
	
	while ((ch = getchar()) != '\n') {
		if (ch >= '0'&&ch <= '9') {
			ich = ich * 10 + (ch - '0');
		}
		last = ich;
		if (ch == ' ') {
			array[num] = ich;
			num++;
			ich = 0;
		}
	}
	array[num] = last;
	num++;

	int count = 0;
	int res = 0;
	cin >> count;
	for (int i = 0; i < num; i++) {
		int min = array[i], max = array[i];
		for (int j = i+1; j < num; j++) {
			if (array[j] > array[i]) {
				if (max < array[j]) {
					max = array[j];
				}
				if (min > array[i]) {
					min = array[i];
				}
			}
			else {
				if (max < array[i]) {
					max = array[i];
				}
				if (min > array[j]) {
					min = array[j];
				}
			}
			if (max - min > count) {
				res +=( num - j);
				break;
			}
		}
	}


	/*
	int res=0;
	int i=0,j=0;
	int lenq=0;
	for(int i=0;i<num;i++){
		int *queen = new int[num];
		lenq=0;
		queen[lenq]=i;
		lenq++;
		for(int j=i+1;j<num;j++){
			if(array[queen[lenq-1]]<array[j]){
				queen[lenq]=j;
				lenq++;
				if(array[j]-array[queen[0]]>max){
					res+=num-j;
					break;
				}
			}else if(array[queen[lenq-1]]>array[j]){
				if(array[queen[lenq-1]]-array[j]>max){
					res+=num-j;
					break;
				}
			}
		}
	}
	*/
	
	cout<<res<<endl;

	system("pause");
}