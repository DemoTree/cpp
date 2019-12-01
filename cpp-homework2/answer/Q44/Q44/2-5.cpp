#include<iostream>
#include<cmath>

using namespace std;

int gcd(int x, int y) {
	//return x == 0 ? y : gcd(y%x, x);
	while (y != 0) {
		int temp = y;
		y = x % y;
		x = temp;
	}
	return x;
}

int main() {
	int array[4];

	char ch;
	int flag = 1;
	int ich = 0;
	while ((ch = getchar()) != '\n') {
		if (ch == '-') {
			flag = -1;
		}
		if (ch >= '0'&&ch <= '9') {
			ich = ich * 10 + (ch - '0');
		}
		if (ch == ',') {
			array[0] = flag * ich;
			flag = 1;
			ich = 0;
		}
		else if (ch == ')') {
			array[1] = flag * ich;
			flag = 1;
			ich = 0;
		}
	}
	while ((ch = getchar()) != '\n') {
		if (ch == '-') {
			flag = -1;
		}
		if (ch >= '0'&&ch <= '9') {
			ich = ich * 10 + (ch - '0');
		}
		if (ch == ',') {
			array[2] = flag * ich;
			flag = 1;
			ich = 0;
		}
		else if (ch == ')') {
			array[3] = flag * ich;
			flag = 1;
			ich = 0;

		}
	}

	int x1 = array[0], y1 = array[1], x2 = array[2], y2 = array[3];
	int fz = y1 - y2;
	int fm = x1 - x2;
	int temp = gcd(fz, fm);
	fz /= temp;
	fm /= temp;

	cout << "y=";
	//k
	if (fz != 0 && fm == 1) {
		cout << fz << "x";
	}
	else if (fz != 0 && fm != 0) {
		if (fz*fm < 0) {
			cout << "-(" << abs(fz) << '/' << abs(fm) << ")x";
		}
		else if (fz*fm > 0) {
			cout << "(" << abs(fz) << '/' << abs(fm) << ")" << 'x';
		}
	}
	else if (fz == 0) {
		cout << "0";
	}

	if (fm != 1) {
		int fmm = fm;
		int fzz = fmm * y1 - fz * x1;
		if (fz*fm < 0) {
			temp = gcd(fzz, fmm);
			fzz /= temp;
			fmm /= temp;
			if (fzz != 0) {
				if (fzz*fmm < 0) {
					cout << "-(" << abs(fzz) << "/" << abs(fmm) << ")";
				}
				else {
					cout << "+(" << abs(fzz) << "/" << abs(fmm) << ")";
				}
			}
		}
		else {
			temp = gcd(fzz, fmm);
			fzz /= temp;
			fmm /= temp;
			if (fzz != 0) {
				if (fzz*fmm < 0) {
					cout << "-(" << abs(fzz) << '/' << abs(fmm) << ")";
				}
				else {
					cout << "+(" << abs(fzz) << "/" << abs(fmm) << ")";
				}
			}
		}

	}
	else if (fm == 1) {
		if (y1 - fz * x1 > 0) {
			cout << '+' << y1 - fz * x1;
		}
		else if (y1 - fz * x1 < 0) {
			cout << '-' << y1 - fz * x1;
		}
	}
}