#include <bits/stdc++.h>
using namespace std;

int n, m;
string path_str;
int Max = 1000;
// vector<int>isVisited(1000);
vector<vector<int>> visited(Max, vector<int>(Max, 0));

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

pair<int, string> solve_Maze(vector<vector<int>> matrix, pair<int, int> src, int length, string str)
{
    if (matrix[src.first][src.second] == -1)
    {
        return {-1, ""};
    }
    else if (src.first == 0 || src.first == n - 1 || src.second == 0 || src.second == m - 1)
    {
        return {length, str};
    }
    pair<int, string> value;
    for (int i = 0; i < 4; i++)
    {
        pair<int, int> newSrc = {src.first + di[i], src.second + dj[i]};
        int x = newSrc.first;
        int y = newSrc.second;
        if (visited[x][y] == 0)
        {
            visited[x][y] = 1;
            value = solve_Maze(matrix, newSrc, length + 1, str);
            if (value.first != -1)
            {
                string temp = "";
                if (i == 0)
                    temp = 'R';
                else if (i == 1)
                    temp = 'L';
                else if (i == 2)
                    temp = 'D';
                else
                    temp = 'U';

                return {value.first, value.second + temp};
            }
        }
    }
    return {value.first, ""};
}
int main()
{
    cin >> n >> m;
    vector<vector<int>> adjacency_matrix(n);
    pair<int, int> src;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        vector<int> intermediate(m);
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '#' || str[j] == 'M')
            {
                intermediate[j] = -1;
            }
            else if (str[j] == 'A')
            {
                src = {i, j};
            }
        }
        adjacency_matrix[i] = intermediate;
    }
    visited[src.first][src.second] = 1;
    pair<int, string> value = solve_Maze(adjacency_matrix, src, 0, "");
    if (value.first == -1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES"
             << "\n"
             << value.first;
        reverse(value.second.begin(), value.second.end());
        cout << "\n"
             << value.second;
    }

    return 0;
}
/**
 * input
5 8
..######
#M..A..#
#.#.M#.#
#M#..#..
..#.####
**/