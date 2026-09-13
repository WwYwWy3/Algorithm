#include <iostream>
#include <vector>
#include <algorithm>

void Floyd(int G[][110], int ans[][110], int N){
	for(int i = 1; i <= N; ++i){
		for(int j = 1;j <= N; ++j) ans[i][j] = G[i][j];
	}
	
	for(int k = 1;k <= N; ++k){
		for(int i = 1;i <= N; ++i){
			for (int j = 1;j <= N; ++j){
				ans[i][j] = std::min(ans[i][k] + ans[k][j], ans[i][j]);
			}
		}
	}
}



int main(){
	int G[110][110], ans[110][110];

	
	int N, M;
	std::cin >> N >> M;
	
	for(int i = 1;i <= N; ++i){
		for(int j = 1;j <= N; ++j){
			G[i][j] = 0x3f3f3f3f;
			if(i == j) G[i][j] = 0;
		}
	}
	
	while(M--){
		int u, v, dis;
		std::cin >> u >> v >> dis;
		if(G[u][v] == 0x3f3f3f3f){
			G[u][v] = dis;
			G[v][u] = dis;
		}
	}	
	
	Floyd(G, ans, N);
	
	for(int i = 1;i <= N; ++i){
		for(int j = 1;j <= N; ++j){
			std::cout << ans[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
