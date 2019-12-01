#include<iostream>
#include<iomanip>

using namespace std;

template<typename T>

void add(T &matrix1, T &matrix2, T &index){
	double x1 = index[0][0];
	double y1 = index[0][1];
	double x2 = index[1][0];
	double y2 = index[1][1];
	double **matrixd = new double*[x1];
		for (int i = 0; i < x1; i++) {
			matrixd[i] = new double[y2];
		}
		for(int i=0;i<x1;i++){
			for(int j=0;j<y2;j++){
				matrixd[i][j]=0;
				for(int k=0;k<y1;k++){
					matrixd[i][j]+=matrix1[i][k]*matrix2[k][j];
				}
			}
		}

		cout<<1<<endl;

		if (matrixd[0][0] == int(matrixd[0][0])) {
			for (int i = 0; i < x1; i++) {
				for (int j = 0; j < y2; j++) {
					if (j != y2 - 1) {
						cout << fixed << setprecision(0) << matrixd[i][j] << " ";
					}
					else {
						cout << fixed << setprecision(0) << matrixd[i][j];
					}
				}
				cout << endl;
			}
		}
		else {
			for (int i = 0; i < x1; i++) {
				for (int j = 0; j < y2; j++) {
					if (j != y2 - 1) {
						cout << fixed << setprecision(4) << matrixd[i][j] << " ";
					}
					else {
						cout << fixed << setprecision(4) << matrixd[i][j];
					}
				}
				cout << endl;
			}
		}	
}

void try(char*** matrix1, char*** martrix2) {
	for (int i = 0; i < ; i++) {

	}
}

void pinjie(char ***matrix1, char ***matrix2, double **index) {
	double x1 = index[0][0];
	double y1 = index[0][1];
	double x2 = index[1][0];
	double y2 = index[1][1];
	double **matrixd = new double*[x1];
	for (int i = 0; i < x1; i++) {
		matrixd[i] = new double[y2];
	}
	char *result;
	for (int i = 0; i < x1; i++) {
		for (int j = 0; j < y2; j++) {
			matrixd[i][j] = 0;
			for (int k = 0; k < y1; k++) {
				matrixd[i][j] = try(matrix1[i][k], matrix2[k][j]);
			}
		}
	}

	cout << -1 << endl;

		for (int i = 0; i < x1; i++) {
			for (int j = 0; j < y2; j++) {
				if (j != y2 - 1) {
					cout  << matrixd[i][j] << " ";
				}
				else {
					cout  << matrixd[i][j];
				}
			}
			cout << endl;
		}
}


int main() {
	int type1,type2,x1,y1,x2,y2;
	cin >> type1;
	cin >> x1 >> y1;
	double **matrix1 = new double*[x1];
	char ***matrix11 = new char**[x1];

	if(type1){
		for (int i = 0; i < x1; i++) {
			matrix1[i] = new double[y1];
		}
		for(int i=0;i<x1;i++){
			for(int j=0;j<y1;j++){
				cin>>matrix1[i][j];
			}
		}
	}else{
		for (int i = 0; i < x1; i++) {
			matrix11[i] = new char*[y1];
			for (int j = 0; j < y1; j++) {
				matrix11[i][j] = new char[10];
			}
		}

		for (int i = 0; i < x1; i++) {
			for (int j = 0; j < y1; j++) {
				for (int k = 0; k < 10; k++) {
					cin >> matrix11[i][j][k];
				}
			}
		}
	}
	/*
	for (int i = 0; i < x1; i++) {
		for (int j = 0; j < y1; j++) {
			if (j != y1 - 1) {
				cout << setprecision(3) << matrix1[i][j] << " ";
			}
			else {
				cout << setprecision(3) << matrix1[i][j];
			}
		}
		cout << endl;
	}
	*/
	cin;
	cin >> type2;
	cin >> x2 >> y2;
	double **matrix2 = new double*[x2];
	char ***matrix22 = new char**[x2];
	char *s = new char[10];
	if(type2){
		for (int i = 0; i < x2; i++) {
			matrix2[i] = new double[y2];
		}
		for(int i=0;i<x2;i++){
			for(int j=0;j<y2;j++){
				cin>>matrix2[i][j];
			}
		}
	}else{
		for (int i = 0; i < x2; i++) {
			matrix22[i] = new char*[y2];
			for (int j = 0; j < y2; j++) {
				matrix22[i][j] = new char[10];
			}
		}
		
		for (int i = 0; i < x2; i++) {
			for (int j = 0; j < y2; j++) {
				for (int k = 0; k < 10; k++) {
					cin >> matrix22[i][j][k];
				}
			}
		}
	}
	
	
	for (int i = 0; i < x2; i++) {
		for (int j = 0; j < y2; j++) {	
			if (j != y2 - 1) {
				for (int k = 0; k < 10; k++) {
					cout << matrix22[i][j][k] << " ";
				}
			}
			else {
				for (int k = 0; k < 10; k++) {
					cout << matrix22[i][j][k];
				}
			}
		}
		cout << endl;
	}

	//矩阵相乘，数值
	double **index = new double*[2];
	for (int i = 0; i < 2; i++) {
		index[i] = new double[2];
	}
	index[0][0] = x1;
	index[0][1] = y1;
	index[1][0] = x2;
	index[1][1] = y2;
	
	if(type1*type2){
		add(matrix1, matrix2, index);
	}else{
		pinjie(matrix11, matrix22, index);
	}	
	system("pause");
}