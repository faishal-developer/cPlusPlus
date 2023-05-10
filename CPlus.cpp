#include <bits/stdc++.h>
using namespace std;

int n,m;
const int Max = 1000;
vector<int>dist(Max);
vector<int>parent(Max);
int is_negative_cyclic= -1;

vector<vector<int>> floyed_warshal(vector<vector<int>> matrix){
   for (int v = 0; v < n; v++)
   {
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            if(i==v || j==v)continue;
            if (matrix[i][j] > matrix[i][v]+matrix[v][j]){
               matrix[i][j] = matrix[i][v] + matrix[v][j];
            }
            if (i == j)
            {
               matrix[i][j] = 0;
            }
         }
      }
   }
   return matrix;
   
}

int main()
{
   cin>>n>>m;
   int value = 1e8;
   vector<vector<int>> adj_matrix(n,vector<int>(n,value));

   for (int i = 0; i < m; i++)
   {
      int x,y,v;
      cin>>x>>y>>v;
      adj_matrix[x][y] = v;

   }
   cout<<"now see the adjacency_matrix\n";
   adj_matrix = floyed_warshal(adj_matrix);
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout<<adj_matrix[i][j]<<" ";
      }
      cout<<"\n";
      
   }
   
   
   return 0;
}

/**
 *
 input
4 4
0 1 5
0 2 2
1 2 1
1 3 4

5 5
0 1 5
1 2 2
2 3 5
2 4 -5
4 2 -3

3 4
0 1 1
0 2 -3
1 2 1
2 1 2

5 5
3 2 3
2 4 2
4 1 4
1 2 1
0 4 1


4 5
0 1 1
1 3 1
3 2 -2
2 0 1
3 0 -3
**/