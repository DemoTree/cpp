#include<iostream>

using namespace std;



int main() {


	std::cout<<maxSum(array)<<endl;
	system("pause");
}

int maxProduct(int[] array){
	int maxProduct = array[0];
	int right = a[0];
	int left = a[0];
	for(int i=1; i<num; i++){
		if(right*array[i]>=left*array[i]){
			right = right*array[i];
		}else{
			right = left*array[i];
		}
		if(right<array[i]){
				right = array[i];
		}

		if(right*array[i]<=left*array[i]){
			left = right*array[i];
		}else{
			left = right*array[i];
		}
		if(left>array[i]){
			left = array[i];
		}

		if(maxProduct<right){
			maxProduct = right;
		}
	}
	return maxProduct;
}