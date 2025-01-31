//link - https://www.geeksforgeeks.org/problems/topological-sort/14

// Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a directed edge u -> v. Return topological sort for the given graph.

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
// Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be 1 else 0.

// Examples:

// Input: adj = [[], [0], [0], [0]] 

// Output: 1
// Explanation: The output 1 denotes that the order is valid. Few valid Topological orders for the given graph are:
// [3, 2, 1, 0]
// [1, 2, 3, 0]
// [2, 3, 1, 0]
// Input: adj = [[], [3], [3], [], [0,1], [0,2]]

// Output: 1
// Explanation: The output 1 denotes that the order is valid. Few valid Topological orders for the graph are:
// [4, 5, 0, 1, 2, 3]
// [5, 2, 4, 0, 1, 3]
// Constraints:
// 2  ≤  V  ≤  103
// 1  ≤  E  ≤  (V * (V - 1)) / 2

#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
    void dfs(int i,vector<vector<int>>& adj,int vis[],stack<int>&st)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,st);
            }
        }
        st.push(i);
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
     int V=adj.size();
     stack<int>st;
     int vis[V]={0};
      for(int i=0;i<V;i++)
      {
          if(!vis[i])
          {
              dfs(i,adj,vis,st);
          }
      }
      
      vector<int> topo;
      while(!st.empty())
      {
          topo.push_back(st.top());
          st.pop();
      }
      return topo;
    }
};
