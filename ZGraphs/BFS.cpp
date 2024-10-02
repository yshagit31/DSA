
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
       int vis[V]={0}; 
       vector<int> res;
       q.push(0);
       vis[0]=1;
       while(!q.empty())
       {
        int temp=q.front();
        q.pop();
        res.push_back(temp);
        for(auto it: adj[temp])
        {
           if(!vis[it])
           {
            vis[it]=1;
            q.push(it);
           }
        }
       }
      
      return res;
    }
};

