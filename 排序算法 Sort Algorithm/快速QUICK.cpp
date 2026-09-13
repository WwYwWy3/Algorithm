#include<iostream>
#include<random>

// std::mt19937 gen(std::random_device{}());

bool cmp(int a, int b){
	return a <= b;
}

int PARTATION(int arr[], int I, int J, bool (*cmp)(int a, int b)){
	// std::uniform_int_distribution<int> dist(I, J);
    // int p = dist(gen);          
    // std::swap(arr[p], arr[I]);  
    
    int pivot = arr[I], l = I, r = J;
	
	while(l < r){
		while(cmp(pivot, arr[r]) && l < r){r--;}
		arr[l] = arr[r];
		while(cmp(arr[l], pivot) && l < r){l++;}
		arr[r] = arr[l];
	}
	arr[l] = pivot;
	
	return l;
}

void QUICKSORT(int arr[], int I, int J, bool (*cmp)(int a, int b)){
	if(I >= J) return;
	int pivot = PARTATION(arr, I, J, cmp);
	QUICKSORT(arr, I, pivot - 1, cmp);
	QUICKSORT(arr, pivot + 1, J, cmp);
}

int main(){
    int N;
    std::cin >> N;
	int arr[100010];
	
	for (int i = 0;i < N; ++i) std::cin >> arr[i];
	
	QUICKSORT(arr, 0, N - 1, &cmp);
	
	for (int i = 0;i < N; ++i) std::cout << arr[i] << ' ';
}
