#include<iostream>

bool cmp(int a, int b){
	return a < b;
}

void SELECTSORT(int arr[], int I, int J, bool (*cmp)(int a, int b)){
	for(int i = I;i <= J; ++i){
		int cnt = i;
		for(int j = i + 1;j <= J; ++j){
			if(cmp(arr[j], arr[cnt])){
				cnt = j;
			}
		}
		if(cnt != i){
			int temp = arr[cnt];
			arr[cnt] = arr[i];
			arr[i] = temp;
		}
	}	
}


int main(){
	int arr[10];
	
	for (int i = 0;i < 10; ++i) std::cin >> arr[i];
	
	SELECTSORT(arr, 0, 9, &cmp);
	
	for (int i = 0;i < 10; ++i) std::cout << arr[i] << ' ';
}
