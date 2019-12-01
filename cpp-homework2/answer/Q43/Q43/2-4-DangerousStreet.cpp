#include<iostream>

using namespace std;
#define MAX 100000

int distance(int x1, int y1, int x2, int y2, int k){
	if(abs(y2-y1)<=k && x2==x1){
		return 1;
	}else if(abs(x1-x2)<=k && y1==y2){
		return 1;
	}else{
		return 0;
	}
}

int main() {

	int x;
	int y;
	int numOfBombs;
	int range;
	int num;

	cin >> x;
	cin>> y;
	cin >> numOfBombs;
	cin >> range;

	int **bomb = new int *[numOfBombs];
	for(int i=0; i<numOfBombs; i++){
		bomb[i] = new int[2];
	}

	int **area = new int*[MAX];
	for(int i=0;i<MAX;i++){
		area[i] = new int[2];
	}

	int i=0,j=0,k=0,flag=0;
	char *temp=new char[4];
	char ch;
	int ich=0;
	while(i<numOfBombs){
		ch=getchar();
		if(ch>='0'&&ch<='9'){
			ich=ich*10+(ch-'0');
		}
		if(ch==','&&flag==1){
			bomb[i][0]=ich;
			ich=0;
		}else if(ch==')'){
			bomb[i][1]=ich;
			ich=0;
			flag=0;
			i++;
		}
		if(ch=='('){
			flag=1;
		}
	}

	int numOfArea=0;
	for(int i=1; i<x+1; i++){
		for(int j=1; j<y+1; j++){
			int index = 0;
			for (int m = 0; m < numOfBombs; m++) {
				if (distance(i, j, bomb[m][0], bomb[m][1], range-1)) {
					index = 1;
					break;
				}
			}
			if (index) {
				area[numOfArea][0] = i;
				area[numOfArea][1] = j;
				numOfArea++;
			}		
		}
	}

	for(int i=0; i<numOfArea; i++){
		cout<<"("<<area[i][0]<<","<<area[i][1]<<")";
		if(i!=numOfArea-1){
			cout<<",";
		}
	}
}