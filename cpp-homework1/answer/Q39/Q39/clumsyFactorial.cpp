#include<iostream>

using namespace std;

int main() {
	int n;
	std::cin >> n;

	int a = (n - 1) / 4;
	int b = (n - 1) % 4;
	int ans = 0;

	if (a == 0) {
		if (b == 0) {
			ans = n;
		}
		else if (b == 1) {
			ans = n * (n - 1);
		}
		else if (b == 2) {
			ans = n * (n - 1)/(n - 2);

		}
		else if (b == 3) {
			ans = n * (n - 1) / (n - 2) + (n - 3);
		}
	}
	else {
		ans = n * (n - 1) / (n - 2) + (n - 3);
		a--;
		for (int i = 0; i < a; i++) {
			n = n - 4;
			ans += (-n)*(n - 1) / (n - 2) + (n - 3);
		}
		n = n - 4;
		if (b == 0) {
			ans -= n;
		}
		else if (b == 1) {
			ans += (-n) * (n - 1);
		}
		else if (b == 2) {
			ans += (-n) * (n - 1) / (n - 2);
		}
		else if (b == 3) {
			ans += (-n) * (n - 1) / (n - 2) + (n - 3);
		}
	}
	std::cout << ans << endl;
	system("pause");
}