
#include<iostream>

using namespace std;

int main(){

	int m=0;
	int n=0;
	cin >> n>> m;

	int array[100][100];
	int result[1000];

	int t = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			array[i][j] = t;
			t++; 
		}
	}

	int temp = 0;
	int flag = 0;
	while (n > flag * 2 && m > flag * 2) {
		int endx=n-flag-1;
		int endy=m-flag-1;

		for(int i=flag; i<=endx; i++){
			result[temp] = *(*(array+flag)+i);
			temp++;
		}
	
		if(flag<endy){
			for(int i=flag+1; i<=endy; i++){
				result[temp] = *(*(array+i)+endx);
				temp++;
			}
		}

		if(flag<endx && flag<endy){
			for(int i=endx-1; i>=0; i--){
				result[temp] = *(*(array+endy)+i);
				temp++;
			}
		}
	
		if(flag<endx && flag<endy-1){
			for(int i=endy-1; i>=flag+1; i--){
				result[temp] = *(*(array+i)+flag);
				temp++;
			}
		}
		flag++;
	}

	for (int i = 0; i < m*n; i++) {
		if (i == m*n - 1) {
			cout << result[i];
		}
		else {
			cout << result[i] << " ";
		}
	}

	system("pause");
}
