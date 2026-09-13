#include<iostream>

bool cmp(int a, int b){
	return a < b;
}

void INSERTSORT(int arr[], int I, int J, bool (*cmp)(int a, int b)){
	for(int i = I + 1; i <= J; ++i){
		int key = arr[i];
		int j = i - 1;
		while(j >= I && cmp(key, arr[j])){
			arr[j + 1] = arr[j]; 
			j--;
		}
		arr[j + 1] = key;
	}
}

int main(){
	int arr[10];
	
	for (int i = 0;i < 10; ++i) std::cin >> arr[i];
	
	INSERTSORT(arr, 1, 8, &cmp);
	
	for (int i = 0;i < 10; ++i) std::cout << arr[i] << ' ';
}
