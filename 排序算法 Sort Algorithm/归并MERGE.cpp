#include<iostream>

bool cmp(int a, int b){
	return a < b;
}

void merge(int arr[], int I1, int J1, int I2, int J2, bool (*cmp)(int a, int b)){
	const int len = J2 - I1 + 10;
	int assist[len], cnt = 0, i1 = I1, i2 = I2;
	
	while(i1 <= J1 && i2 <= J2){
		if(cmp(arr[i1], arr[i2])){
			assist[cnt++] = arr[i1]; i1++;
		}
		else{
			assist[cnt++] = arr[i2]; i2++;
		}
	}
	
	while(i1 <= J1){assist[cnt++] = arr[i1]; i1++;}
	while(i2 <= J2){assist[cnt++] = arr[i2]; i2++;}
	
	for(int i = 0, j = I1; i < cnt; ++i, ++j){arr[j] = assist[i];}
}

void MERGESORT(int arr[], int I, int J, bool (*cmp)(int a, int b)){
	if (I >= J) return;
	
	int mid = (I + J) >> 1;
	MERGESORT(arr, I, mid, cmp); MERGESORT(arr, mid + 1, J, cmp);
	
	merge(arr, I, mid, mid + 1, J, cmp);
}

int main(){
	int arr[10];
	
	for (int i = 0;i < 10; ++i) std::cin >> arr[i];
	
	MERGESORT(arr, 0, 9, &cmp);
	
	for (int i = 0;i < 10; ++i) std::cout << arr[i] << ' ';
}
