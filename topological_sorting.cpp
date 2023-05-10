#include <bits/stdc++.h>
using namespace std;

const int Max = 1000;
int inUsed[Max];
vector<vector<int>> adjacent_list(Max);
stack<int> nodes;

bool DFS(int src)
{
    // cout<<src<<" ";
    inUsed[src] = 1;
    for (int i = 0; i < adjacent_list[src].size(); i++)
    {
        if (inUsed[adjacent_list[src][i]] == 0)
        {
            bool value = DFS(adjacent_list[src][i]);
            if (value == true)
                return true;
        }
        if (inUsed[adjacent_list[src][i]] == 1)
        {
            return true;
        }
    }
    inUsed[src] = 2;
    nodes.push(src);
    return false;
};

int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjacent_list[u].push_back(v);
    }
    bool isCycle = true;
    for (int i = 1; i <= n; i++)
    {
        if (inUsed[i] == 0)
        {
            isCycle = DFS(i);
            if (isCycle == true)
            {
                break;
            }
        }
    }
    cout << "problem solved"
         << "\n";

    if (isCycle)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << nodes.top() << "  ";
            nodes.pop();
        }
    }

    return 0;
}
/**
 * input
5 5
1 2
1 3
2 3
1 4
4 5
**/