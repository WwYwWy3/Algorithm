#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using Edge = std::pair<int, int>; 

struct QItem{
	int v;
	int dist;
};

struct cmp {
    bool operator()(const QItem &a, const QItem &b) const {
        return a.dist > b.dist;   
    }
};

void dijkstraV1(std::vector<std::vector<Edge>> &G, int n, int s, std::vector<int> &ans){
    const int INF = 0x3f3f3f3f;
    std::vector<int> dist(n + 1, INF), vis(n + 1, 0);
    dist[s] = 0;

    for(int i = 1; i <= n; ++i){
        int u = -1, mn = INF;
        
        for(int j = 1; j <= n; ++j){
            if(!vis[j] && dist[j] < mn){ u = j; mn = dist[j]; }
        }
        
        if(u == -1) break; vis[u] = 1;

        for(auto &e : G[u]){
            int v = e.first, w = e.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    ans = dist;   
}

void dijkstraV2(std::vector<std::vector<Edge>> &G, int n, int s, std::vector<int> &ans){
	const int INF = 0x3f3f3f3f;
    std::vector<int> dist(n + 1, INF), vis(n + 1, 0);
    dist[s] = 0;
    
    std::priority_queue<QItem, std::vector<QItem>, cmp> pq;
    
    pq.push({s, 0});
    
    while(!pq.empty()){
    	auto it = pq.top(); pq.pop();
    	int u = it.v;
    	if(vis[u]) continue;
    	vis[u] = 1;
    	for(auto &e : G[u]){
    		int v = e.first, w = e.second;
    		if(dist[u] + w < dist[v]){
    			dist[v] = dist[u] + w;
    			pq.push({v, dist[u] + w});
    		}
    	}
    }
    ans = dist;
}

int main(){
    int n, m, s;
    std::cin >> n >> m >> s;

    std::vector<std::vector<Edge>> G(n + 1);   

    while(m--){
        int u, v, w;
        std::cin >> u >> v >> w;
        G[u].push_back({v, w});
        
    }

    std::vector<int> ans(n + 1, 0);
    dijkstraV2(G, n, s, ans);

    for(int i = 1; i <= n; ++i) std::cout << ans[i] << ' ';
}
