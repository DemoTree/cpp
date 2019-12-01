#include<iostream>

using namespace std;
#define MAX 1000
int main() {
	int *array = new int[MAX];
	char ch;
	int len=0;
	while(len<MAX){
		ch=getchar();
		if((ch>='0' && ch<='9') || ch=='-'){
			ungetc(ch,stdin);
			cin>>array[len++];
		}
		if(ch=='\n') break;
	}

	int num=0;
	cin>>num;

	int res=0;
	int i=0,j=0;
	int lenq=0;
	for(int i=0;i<len;i++){
		int *queen = new int[len];
		lenq=0;
		queen[lenq]=i;
		lenq++;
		for(int j=i+1;j<len;j++){
			if(lenq==0||array[queen[lenq-1]]<array[j]){
				queen[lenq]=j;
				lenq++;
				if(array[j]-array[queen[0]]>num){
					res+=len-j;
					break;
				}
			}else if(array[queen[lenq-1]]>array[j]){
				if(array[queen[lenq-1]]-array[j]>num){
					res+=len-j;
					break;
				}
			}
		}
	}
	cout<<res;
}