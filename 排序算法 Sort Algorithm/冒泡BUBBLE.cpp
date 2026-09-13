#include<iostream>

bool cmp(int a, int b){
	return a < b;
}

void BUBBLESORT(int arr[], int I, int J, bool (*cmp)(int a, int b)){
	bool flag = true;
	while(flag){
		flag = false;
		for(int i = I;i <= J; ++i){
			if(cmp(arr[i + 1], arr[i])){
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = true; 
			}
		}
		if(!flag){
			break;
		}
	}
}

int main(){
	int arr[10];
	
	for (int i = 0;i < 10; ++i) std::cin >> arr[i];
	
	BUBBLESORT(arr, 1, 8, &cmp);
	
	for (int i = 0;i < 10; ++i) std::cout << arr[i] << ' ';
}
