#include <bits/stdc++.h>
using namespace std;

#define INF 100000

vector<pair<int, int>> adj[1000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int cost[1000];
int parent[1000];

void dijkstra(int source)
{

    for (int i = 0; i < 1000; i++)
    {
        cost[i] = INF;
    }

    cost[source] = 0;
    parent[source] = source;

    pq.push({0, source});

    while (!pq.empty())
    {
        int fr = pq.top().second;
        pq.pop();

        for (int i = 0; i < adj[fr].size(); i++)
        {
            int v = adj[fr][i].first;
            int weight = adj[fr][i].second;

            if (cost[fr] + weight < cost[v])
            {
                cost[v] = cost[fr] + weight;

                parent[v] = fr;
                pq.push({cost[v], v});
            }
        }
    }
}

int main()
{
    memset(adj, 0, sizeof(adj));

    int n, e;

    cout << "The number of nodes and edges ???" << endl;

    cin >> n >> e;

    int u, v, weight;

    cout << "Enter node 1 and node 2 and weight" << endl;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> weight;

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    int start, destination;

    cout << "Enter the source and destination node" << endl;

    cin >> start;
    cin >> destination;

    dijkstra(start);

    cout << "The cost to reach the destination is " << cost[destination] << endl;

    vector<int> vv;

    int now = destination;
    vv.push_back(destination);

    while (now != parent[now])
    {
        now = parent[now];
        vv.push_back(now);
    }

    reverse(vv.begin(), vv.end());

    for (int i = 0; i < vv.size(); i++)
    {
        cout << "->" << vv[i];
    }

    cout << endl;

    return 0;
}