#include <iostream>
#include <queue>
#include <vector>

using Edge = std::pair<int, int>;   

struct QItem {
    int v;
    int dist;
};

struct cmp {
    bool operator()(const QItem &a, const QItem &b) const {
        return a.dist > b.dist;   
    }
};

int Prim(std::vector<std::vector<Edge>> &G, int n){
    int Nnums = 0, ans = 0;
    std::vector<int> vis(n + 1, 0);

    std::priority_queue<QItem, std::vector<QItem>, cmp> pq;
    pq.push({1, 0});

    while(!pq.empty()){
        auto it = pq.top(); pq.pop();
        int u = it.v, w = it.dist;

        if(vis[u]) continue;
        vis[u] = 1;
        Nnums++;
        ans += w;                        

        for(auto &e : G[u]){
            int v = e.first, dis = e.second;
            if(!vis[v]) pq.push({v, dis});
        }
    }

    return Nnums == n ? ans : -1;
}

int main(){
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<Edge>> G(N + 1);  

    while(M--){
        int u, v, dis;
        std::cin >> u >> v >> dis;
        G[u].push_back({v, dis});
        G[v].push_back({u, dis});
    }

    int ans = Prim(G, N);

    if(ans == -1) std::cout << "orz";
    else std::cout << ans;
}
