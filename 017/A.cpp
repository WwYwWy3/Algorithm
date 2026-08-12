#include<bits/stdc++.h>
#define BK putchar('\n');
using i64 = long long;
using u64 = unsigned long long;

struct Node{
	int value;
	int l;
	int r;
};

std::vector<Node> tree;

void pre(int idx){
	if (idx == 0) return;
	
	std::cout << tree[idx].value << ' ';
	pre(tree[idx].l);
	pre(tree[idx].r);
}

void mid(int idx){
	if (idx == 0) return;
	
	mid(tree[idx].l);
	std::cout << tree[idx].value << ' ';
	mid(tree[idx].r);
}

void post(int idx){
	if (idx == 0) return;
	
	post(tree[idx].l);
	post(tree[idx].r);
	std::cout << tree[idx].value << ' ';
}

void solve(){
	int n;
	std::cin >> n;
	tree.resize(n + 1);
	
	for (int i = 1;i <= n; ++i){
		int l, r;
		std::cin >> l >> r;
		tree[i].value = i;
		tree[i].l = l; tree[i].r = r;
	}
	pre(1); BK;
	mid(1); BK;
	post(1); BK;
}

int main(){
	int t = 1;
	//std::cin >> t;
	while(t--) solve();
}
