//signle source shortest path with BFS problem solved by BFS traversal
#include <bits/stdc++.h>
using namespace std;

int n, m;
const int Max = 1000;
vector<int> isVisited(Max);
vector<int> dist(Max);

void BFS_traversal(vector<vector<pair<int, int>>> nodes, int src)
{
    queue<int> q;
    q.push(src);
    isVisited[src] = 1;
    dist[src] = 0;
    while (q.size())
    {
        int head = q.front();
        vector<pair<int, int>> intermediate = nodes[head];
        q.pop();
        for (int i = 0; i < intermediate.size(); i++)
        {
            if (isVisited[intermediate[i].first] == 0)
            {
                isVisited[intermediate[i].first] = 1;
                q.push(intermediate[i].first);
                dist[intermediate[i].first] = dist[head] + intermediate[i].second;
            }
            else
            {
                int d = dist[intermediate[i].first];
                if (d > dist[head] + intermediate[i].second)
                {
                    dist[intermediate[i].first] = dist[head] + intermediate[i].second;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<vector<pair<int, int>>> SSSPNodes(n + 1);

    for (int i = 1; i <= m; i++)
    {
        int first, second, third;
        cin >> first >> second >> third;
        SSSPNodes[first].push_back({second, third});
        SSSPNodes[second].push_back({first, third});
    }
    BFS_traversal(SSSPNodes, 1);

    for (int i = 1; i <= n; i++)
    {
        cout << i << "=" << dist[i] << "\n";
    }

    return 0;
}
/**
 * input
9 14
1 2 4
1 8 8
2 8 11
2 3 8
8 9 7
8 7 1
3 9 2
3 4 7
3 6 4
9 7 6
7 6 2
4 5 9
4 6 14
6 5 10


4 4
1 2 5
1 3 2
2 3 1
2 4 4
**/