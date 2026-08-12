#include<bits/stdc++.h>
#define BK putchar('\n');
using i64 = long long;
using u64 = unsigned long long;

bool geq(int t1, int t2){
	return t1 >= t2 ? true : false;
}

bool leq(int t1, int t2){
	return t1 <= t2 ? true : false;
}

void merge(int l1, int r1, int l2, int r2, std::vector<int> &a){
	std::vector<int> temp((r1 - l1 + 1) + (r2 - l2 + 1) + 1);
	int L1 = l1, L2 = l2, i = 1, al = std::min(l1, l2), ar = std::max(l1, l2);
	while(L1 <= r1 && L2 <= r2){
		if (geq(a[L1], a[L2])){
			temp[i++] = a[L1]; L1++;
		}
		else{
			temp[i++] = a[L2]; L2++;
		}
		
	}
	while(L1 <= r1){temp[i++] = a[L1]; L1++;}
	while(L2 <= r2){temp[i++] = a[L2]; L2++;}
	for(int j = 1;j < i; ++j) a[al++] = temp[j];
}

void mergesort(std::vector<int> &a, int l, int r){
	if (l >= r){
		return;
	}
	else{
		int mid = (l + r) >> 1;
		mergesort(a, l, mid);
		mergesort(a, mid + 1, r);
		merge(l, mid, mid + 1, r, a);
	}
}

void solve(){
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	
	mergesort(a, 1, n);
	
	for (int i = 1; i <= n; ++i) std::cout << a[i] << ' ';
}

int main(){
	int t = 1;
	//std::cin >> t;
	while(t--) solve();
}
