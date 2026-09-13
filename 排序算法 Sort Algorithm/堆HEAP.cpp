#include<iostream>
#include <vector>
#include <algorithm>

struct HEAP{
    std::vector<int> heap;   
    int max_size, cur_size;

    static bool cmp(int a, int b){ return a < b; }   

    HEAP(int arr[], int I, int J){
        max_size = J - I + 10;
        heap.assign(max_size + 1, 0);   
        cur_size = 0;
        BUILDHEAP(arr, I, J);
    }

    void UP(int cnt){
        while(cnt > 1 && cmp(heap[cnt], heap[cnt/2])){
            std::swap(heap[cnt], heap[cnt/2]);
            cnt /= 2;
        }
    }

    void DOWN(int cnt){
        while(cnt * 2 <= cur_size){          
            int t = cnt * 2;
            if(t + 1 <= cur_size && cmp(heap[t + 1], heap[t])){t++;}  
            if(!cmp(heap[t], heap[cnt])) break;                        
            std::swap(heap[cnt], heap[t]);
            cnt = t;
        }
    }

    void BUILDHEAP(int arr[], int I, int J){
        cur_size = 0;
        for(int i = 1, j = I; j <= J; ++j, ++i){   
            heap[i] = arr[j];
            cur_size++;
        }
        for(int i = cur_size / 2; i >= 1; --i){    
            DOWN(i);
        }
    }

    int GETSIZE(){ return cur_size; }

    void PUSH(int item){
        heap[++cur_size] = item;
        UP(cur_size);
    }

    void POP(){
        if(cur_size == 0) return;
        heap[1] = heap[cur_size];
        cur_size--;
        if(cur_size > 0) DOWN(1);
    }

    int TOP(){ return heap[1]; }
};

void HEAPSORT(int arr[], int I, int J){
	HEAP heap(arr, I, J);
	for(int i = I;i <= J; ++i){arr[i] = heap.TOP(); heap.POP();}
}

int main(){
	int arr[10];
	
	for (int i = 0;i < 10; ++i) std::cin >> arr[i];
	
	HEAPSORT(arr, 0, 9);
	
	for (int i = 0;i < 10; ++i) std::cout << arr[i] << ' ';
}
