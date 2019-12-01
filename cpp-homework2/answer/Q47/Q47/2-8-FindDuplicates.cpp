#include<iostream>

using namespace std;
#define MAX 16001

int main() {
	char * array = new char[MAX];
	char t;
	int index=0;
	char res;
	while ((t=cin.get())!='\n') {
		if(t!=',' && t!='[' && t!=']'){
			//cout<<t<<endl;
			array[index]=t;
			index++;
		}
	}

	for (int i = 0; i < index-1; i++) {
		for (int j = i+1; j < index; j++) {
			//cout<<array[i]<<" "<<array[j]<<endl;
			if (array[i] == array[j]) {
				res=array[i];
			}
		}
	}	
	cout << res;
}