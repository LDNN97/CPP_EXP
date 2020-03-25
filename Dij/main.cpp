#include <iostream>
#include <queue>
#include <vector>

typedef std::pair<int, double> item;

struct cmp {
    bool operator()(const item &p1, const item &p2) const{
        return p1.second > p2.second;
    }
};

void dij(std::vector<item> map[], double dis[], bool bol[]){
    dis[0] = 0; bol[0] = true;
    std::priority_queue<item, std::vector<item>, cmp> que;
    que.push(item(dis[0], 0));
    while (!que.empty()) {
        item now = que.top(); que.pop(); bol[now.first] = true;
        for (auto e : map[now.first]){
            if (!bol[e.first]) {
                if (dis[e.first] > dis[now.first] + e.second) {
                    dis[e.first] = dis[now.first] + e.second;
                    que.push(item(e.first, dis[e.first]));
                }
            }
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<item> map[n];
    int u, v; double d;
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v >> d;
        map[u].emplace_back(item(v, d));
        map[v].emplace_back(item(u, d));
    }

    double dis[n]; bool bol[n];
    for (int i = 0; i < n; i++)
        dis[i] = 1000;
    memset(bol, 0, sizeof(bol));

    dij(map, dis, bol);

    for (int i = 0; i < n; i++)
        std::cout << i << " " << dis[i] << std::endl;

    return 0;
}
