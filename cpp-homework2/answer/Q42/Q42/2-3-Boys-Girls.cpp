#include<iostream>
using namespace std;

int main() {
	char *array = new char[300];
	char t;
	int len=0;
	cin >> array;

	int numOfBoys = 0;
	int numOfbo=0;
	int numOfb = 0;
	int numOfGirls = 0;
	int numOfgi=0;
	int numOfgir=0;
	int numOfg = 0;

	for(int i=0; i<300; i++){
		if(array[i]=='b' || array[i]=='o' || array[i]=='y'){
			numOfb++;
		}
		if(array[i]=='b' && array[i+1]=='o' && array[i+2]=='y'){
			numOfBoys++;
		}
		if(array[i]=='b' && array[i+1]=='o'){
			numOfbo++;
		}
		if(array[i+1]=='o' && array[i+2]=='y'){
			numOfbo++;
		}
		if(array[i]=='g' || array[i]=='i' || array[i]=='r' || array[i]=='l'){
			numOfg++;
		}
		if(array[i]=='g' && array[i+1]=='i' && array[i+2]=='r' && array[i+3]=='l'){
			numOfGirls++;
		}
		if(array[i]=='g' && array[i+1]=='i'){
			numOfgi++;
		}
		if(array[i+1]=='i' && array[i+2]=='r'){
			numOfgi++;
		}
		if(array[i+2]=='r' && array[i+3]=='l'){
			numOfgi++;
		}
		if(array[i]=='g' && array[i+1]=='i' && array[i+2]=='r'){
			numOfgir++;
		}
		if(array[i+1]=='i' && array[i+2]=='r' && array[i+3]=='l'){
			numOfgir++;
		}

	}

	numOfbo = numOfbo - 2 * numOfBoys;
	numOfb = numOfb - 2 * numOfbo - 3 * numOfBoys;
	numOfgir = numOfgir - 2 * numOfGirls;
	numOfgi = numOfgi - 2 * numOfgir - 3 * numOfGirls;
	numOfg = numOfg - 3 * numOfgir - 2 * numOfgi - 4 * numOfGirls;
	int a = numOfBoys + numOfbo + numOfb;
	int b = numOfg + numOfgi + numOfgir + numOfGirls;
	
	cout << a << " " << b;
}