#include<bits/stdc++.h>
#define BK putchar('\n');
using i64 = long long;
using u64 = unsigned long long;
const int size1 = 1e4 + 10;
const int size2 = 1e5 + 10;
const int size3 = 1e6 + 10;

/*
 T(N) = a * T(N/b) + O(n^c) a, b, c \in R
 a: 子过程调用次数
 b: 问题被划分的规模
 c: 除了递归过程意外剩余部分的时间复杂度
*/

i64 a[size1];

i64 findmax(int l, int r){
	if (l == r) {return a[l];}
	else{
		int mid = (l + r) >> 1;
		i64 lmax = findmax(l, mid);
		i64 rmax = findmax(mid + 1, r);
		return lmax > rmax ? lmax : rmax;
	}
}


void solve(){
	int n;
	std::cin >> n;
	for (int i = 1;i <= n; ++i) std::cin >> a[i];
	
	std::cout << findmax(1, n); BK;
}

int main(){
	int t = 1;
	//std::cin >> t;
	while(t--) solve();
}
