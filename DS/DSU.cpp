#include<iostream>

struct DSU{
	int* a, *size;
	
	DSU(int n){
		a = (int* )calloc(n + 1, sizeof(int));
		size = (int* )calloc(n + 1, sizeof(int));
		for(int i = 1;i <= n; ++i){
			a[i] = i;
			size[i] = 1;
		}
	}
	
	
	int find(int x){
		if(a[x] == x) {return x;}
		else{
			int fa = find(a[x]);
			a[x] = fa;
			return fa;
		}
	}
	
	void merge(int x, int y){
		int fax = find(x), fay = find(y);
		if(fax == fay){return;}
		else{
			if(size[fax] > size[fay]){
				a[fay] = fax;
				size[fax] += size[fay]; size[fay] = 0;
			}
			else{
				a[fax] = fay;
				size[fay] += size[fax]; size[fax] = 0;
			}
		}
	}
	
	bool same(int x, int y){
		int fax = find(x), fay = find(y);
		return fax == fay;
	}
};
