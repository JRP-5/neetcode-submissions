class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> edges(n);
        for(vector<int> a : times){
            edges[a[0]-1].push_back({a[1]-1, a[2]});
        }
        // Min-heap storing {distance, vertex}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // Initialize distances to infinity
        vector<int> dist(n, INT_MAX);
        // Distance from source to itself is 0
        dist[k-1] = 0;
        pq.push({0, k-1});
        while (!pq.empty()) {
            int d = pq.top()[0];
            int u = pq.top()[1];
            pq.pop();
            // Skip outdated entries
            if (d > dist[u])
                continue;
            // Traverse adjacent vertices
            for (const auto &x : edges[u]){
                int v = x.first;
                int weight = x.second;
                // Update distance if a shorter path is found
                if (dist[v] > d + weight){
                    dist[v] = d + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxi = 0;
        for(int a : dist){
            if(a == INT_MAX){
                return -1;
            }
            maxi = max(maxi, a);
        }
        return maxi;
    }
};
