#include <bits/stdc++.h>
using namespace std;

int n,m;
const int Max = 1000;
vector<int>dist(Max);
vector<int>visited(Max);
vector<int>parent(Max);
int is_negative_cyclic= -1;

void bellman_ford(vector<vector<pair<int,int>>> list,int src){
   for (int i = 0; i <= n; i++)
   {
      for (int nodes = 0; nodes < n; nodes++)
      {
         for (pair<int, int> pr : list[nodes])
         {
            int totalCost = dist[nodes] + pr.second;
            if (dist[pr.first] > totalCost)
            {
               if(i==n){
                  is_negative_cyclic = pr.first;
               }
               parent[pr.first] = nodes;
               dist[pr.first] = totalCost;
            }
         }
      }
      
      
   }
   
}

int main()
{
   cin>>n>>m;
   vector<vector<pair<int,int>>> adj_list(n+1);
   int src =0;
   for (int i = 0; i < m; i++)
   {
      int x,y,v;
      cin>>x>>y>>v;
      adj_list[x].push_back({y,v});
      // adj_list[y].push_back({x,v});
      dist[i] = 1e8;
   }
   dist[src] = 0;
   parent[src]=-1;
   bellman_ford(adj_list,src);
   if (is_negative_cyclic!=-1){
      cout<<"Negative cycle exist"<<is_negative_cyclic;
      int newOne = is_negative_cyclic;
      while(true){
         newOne = parent[newOne];
         cout << newOne << "<-";
         if(newOne==is_negative_cyclic){
            break;
         }
      }
   }else{
      for (int i = 0; i < n; i++)
      {
         cout << i << "= " << dist[i] << " parent= " << parent[i] << "\n";
      }
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