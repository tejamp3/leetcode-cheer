

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        // pair<neighbor, weight>
        unordered_map<int, vector<pair<int,int>>> adj;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2 * wt});   // reversed edge cost
        }

        // pair<distance, node>
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        pq.push({0, 0});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;  

            pq.pop();

            if (node == n - 1) {
                return d;
            }

            if (d > dist[node]) continue;

            for (auto &pr : adj[node]) {
                int adjNode = pr.first;
                int wt = pr.second;

                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return -1;
    }
};