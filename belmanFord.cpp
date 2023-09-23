#include<limits.h>

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
   //step 1: check n-1 times
   vector<int> dist(n+1, 1e8);
   dist[src] = 0;
   for(int i = 1; i < n; i++) {
       //traverse on edge list
       for(auto i : edges){
           int u = i[0];
           int v = i[1];
           int w = i[2];

           if(dist[u] + w < dist[v]) {
               dist[v] = dist[u] + w;
           }
       }
   }

   bool flag = 0;

   for(auto i : edges){
    if(dist[i[0]] + i[2] < dist[i[1]]){
        dist[i[1]] = dist[ i[0] ] + i[2];
        flag = 1;
    }
   }

   if(flag == 0){
    return dist;
   }
   return -1;
}