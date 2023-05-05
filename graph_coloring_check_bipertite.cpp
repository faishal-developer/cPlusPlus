#include <bits/stdc++.h>
using namespace std;

const int Max = 1000;
int inUsed[Max];
int color[Max];
vector<vector<int>> adjacent_list(Max);

bool DFS(int src)
{
    // cout<<src<<" ";
    inUsed[src] = 1;
    for (int i = 0; i < adjacent_list[src].size(); i++)
    {
        if (color[adjacent_list[src][i]] == color[src])
        {
            return false;
        }
        if (inUsed[adjacent_list[src][i]] == 0)
        {
            color[adjacent_list[src][i]] = color[src] == 1 ? 2 : 1;
            bool value = DFS(adjacent_list[src][i]);
            if (value == false)
                return false;
        }
    }
    return true;
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
        adjacent_list[v].push_back(u);
    }
    bool isPossible = true;
    for (int i = 1; i <= n; i++)
    {
        if (inUsed[i] == 0)
        {
            color[i] = 1;
            isPossible = DFS(i);
            if (isPossible == false)
            {
                break;
            }
        }
    }

    if (isPossible)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "color==" << color[i] << " \n";
        }
    }
    else
    {
        cout << "impossible";
    }

    return 0;
}
/**
 * input
5 4
1 2
1 3
2 3
4 5
**/