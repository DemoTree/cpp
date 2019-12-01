#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

struct MyStruct
{
	char s[256];
};


void i_add(void* a, void* b) {
	double * x =(double*) a;
	double * y =(double*) b;
	*x = *x + *y;
}

void i_mul(void* a,void* b,void* res) {
	double * x = (double*)a;
	double * y = (double*)b;
	double *c = (double*)res;
	*c = (*x)*(*y);
}
void c_mul(void * a, void * b, void* res) {
	MyStruct* x = (MyStruct*)a;
	MyStruct* y = (MyStruct*)b;
	MyStruct* c = (MyStruct*)res;
	sprintf(c->s, "%s%s", x->s, y->s);
}
void c_add(void* a, void * b) {
	MyStruct* x = (MyStruct*)a;
	MyStruct* y = (MyStruct*)b;
	char tmp[80];
	sprintf(tmp, "%s%s", x->s, y->s);
	int n = 0;
	for (unsigned int i = 0; i < strlen(tmp); i++) {
		int new_char = 1;
		for (int j = 0; j < n; j++)
			if (tmp[i] == x->s[j])
				new_char = 0;
		if (new_char) {
			x->s[n] = tmp[i];
			n++;
		}
	}
	x->s[n] = 0;
}

void* matrix_mul(void * matrix_ap, void * matrix_bp, int type_len,
				  int row_a,int col_a,int row_b,int col_b,
				  void (*mul)(void*, void*,void*),
				  void (*add)(void*, void*)) {

	char * res = new char[row_a*col_b*type_len]{ 0 };
	char * matrix_a = (char*)matrix_ap;
	char * matrix_b = (char*)matrix_bp;
	char * temp = new char[type_len]();
	for (int i = 0; i < row_a; i++)
		for (int j = 0; j < col_b; j++)
			for (int k = 0; k < col_a; k++) {
				mul(matrix_a + i*col_a*type_len + k * type_len,
					matrix_b+k*col_b*type_len + j * type_len, temp);
				add(res+i*col_b*type_len + j * type_len, temp);
			}
	return res;
}



void * input_matrix(int row, int col,int type_len) {
	char * res = new char[row*col*type_len]{ 0 };
	for (int rb = 0; rb < row; rb++)
		for (int cb = 0; cb < col; cb++)
			cin >> res+rb*col*type_len+cb*type_len;
	return res;
}

void* stru_to_double(MyStruct* s,int row,int col) {
	double * res = new double[row*col]{0};
	for (int rb = 0; rb < row; rb++)
		for (int cb = 0; cb < col; cb++)
			res[rb*col+cb]= atof(s[rb*col+cb].s);
	return res;
}





int main() {
	int type1, row1, col1, type2, row2, col2;
	//input first matrix
	cin >> type1 >> row1 >> col1;
	MyStruct *matrix_a = (MyStruct*)input_matrix(row1, col1, sizeof(MyStruct));
	//input second matrix
	cin >> type2 >> row2 >> col2;
	MyStruct* matrix_b = (MyStruct*)input_matrix(row2, col2, sizeof(MyStruct));
	if (type1 == 1 && type2 == 1) {
		//数值乘法,需要将struct转化为double
		double * a = (double*)stru_to_double(matrix_a, row1, col1);
		double * b = (double*)stru_to_double(matrix_b, row2, col2);
		double * c = (double*)matrix_mul(a, b, sizeof(double), row1, col1, row2, col2, i_mul, i_add);
		cout << 1 << endl;
		for (int rb = 0; rb < row1; rb++) {
			for (int cb = 0; cb < col2; cb++)
				cout << (cb ? " " : "") << c[rb * col2 + cb];
			cout << endl;
		}
	}

	else {
		//字符乘法
		MyStruct *c1 = (MyStruct*)matrix_mul(matrix_a, matrix_b, sizeof(MyStruct),
			row1, col1, row2, col2, c_mul, c_add);
		cout << -1 << endl;
		for (int rb = 0; rb < row1; rb++) {
			for (int cb = 0; cb < col2; cb++)
				cout << (cb ? " " : "") << c1[rb * col2 + cb].s;
			cout << endl;
		}
	}
	system("pause");

}