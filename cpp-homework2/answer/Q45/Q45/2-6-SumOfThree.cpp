#include<iostream>

using namespace std;
void sort(int array[], int num){
	for (int index = num / 2; index > 0; index /= 2)
    {
        for (int i = index; i < num; i++)
        {
            int j, temp = array[i];
            for (j=i; j - index >= 0; j -= index)
            {
                if (array[j - index] > temp)
                    array[j] = array[j - index];
                else
                    break;
            }
            array[j] = temp;
        }
    }
}

int main() {
	int num=0;
	cin>>num;
	int *array = new int[num];
	int **res = new int*[100];
	for(int i=0; i<100; i++){
		res[i] = new int[3];
	}
	int i=0;
	char ch;
	while(i<num){
		ch=getchar();
		if((ch>='0' && ch<='9') || ch=='-'){
			ungetc(ch,stdin);
			cin>>array[i++];
		}
	}

	sort(array,num);

	int flag=0;
	int a=0,b=0,c=0;
	for(int i=0;i<num;i++){
		for(int j=i+1;j<num;j++){
			for(int k=j+1;k<num;k++){
				if(array[i]+array[j]+array[k]==0 && (a!=array[i] || b!=array[j] || c!=array[k])){
					a=res[flag][0]=array[i];
					b=res[flag][1]=array[j];
					c=res[flag][2]=array[k];
					flag++;
				}
			}
		}
	}

	for(int i=0;i<flag;i++){
		cout<<'['<<res[i][0]<<','<<res[i][1]<<','<<res[i][2]<<']';
		if(i<flag-1) cout<<',';
	}
	if (flag == 0)
		cout << "-1" << endl;

	system("pause");
}