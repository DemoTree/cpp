#include<iostream>
#include<vector>

using namespace std;

template <class T>
class myTemplate {
private:
	vector<T> list;
	int len;
public:
	void add(T x) {
		list.push_back(x);
	}

	void setLen(int len) {
		this->len = len;
	}

	int binarySearch(T target) {
		int i = 0;
		int left = 0;
		int right = len - 1;
		while (left <= right) {
			i++;
			int middle = (left + right) / 2;
			if (list[middle] == target) {
				break;
			}
			if (list[middle] < target) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		return i;
	}

	void mySort() {
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (list[i] > list[j]) {
					mySwap(list[i], list[j]);
				}
			}
		}
	}

	void mySwap(T & a, T & b) {
		T c = a;
		a = b;
		b = c;
	}

};

int main() {
	int ilen, dlen, clen;
	int result[3];
	int itarget;
	double dtarget;
	char ctarget;

	myTemplate<int> ilist;
	myTemplate<double> dlist;
	myTemplate<char> clist;

	cin >> ilen;
	ilist.setLen(ilen);

	for (int i = 0; i < ilen; i++) {
		cin >> itarget;
		ilist.add(itarget);
	}
	cin >> itarget;
	ilist.mySort();
	result[0] = ilist.binarySearch(itarget);

	cin >> dlen;
	dlist.setLen(dlen);

	for (int i = 0; i < dlen; i++) {
		cin >> dtarget;
		dlist.add(dtarget);
	}
	cin >> dtarget;
	dlist.mySort();
	result[1] = dlist.binarySearch(dtarget);

	cin >> clen;
	clist.setLen(clen);

	for (int i = 0; i < clen; i++) {
		cin >> ctarget;
		clist.add(ctarget);
	}
	cin >> ctarget;
	clist.mySort();
	result[2] = clist.binarySearch(ctarget);

	cout << result[0] << endl;
	cout << result[1] << endl;
	cout << result[2];

	//system("pause");
}