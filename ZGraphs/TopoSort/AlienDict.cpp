// link - https://www.geeksforgeeks.org/problems/alien-dictionary/1

// Alien Dictionary
// Difficulty: HardAccuracy: 47.81%Submissions: 141K+Points: 8
// Given a sorted dictionary of an alien language having some words dict and k starting alphabets of a standard dictionary. Find the order of characters in the alien language. If no valid ordering of letters is possible, then return an empty string.

// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be "true" if the order of string returned by the function is correct else "false" denotes incorrect string returned.

// Examples:

// Input: dict[] = ["baa","abcd","abca","cab","cad"], k = 4
// Output: true
// Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
// Similarly we can find other orders.
// Input: dict[] = ["caa","aaa","aab"], k = 3
// Output: true
// Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output.
// Similarly we can find other orders.
// Input: dict[] = ["dhhid","dahi","cedg","fg","gdah","i","gbdei","hbgf","e","ddde"], k = 9 
// Output: false
// Constraints:
// 1 ≤ dict.size()≤ 104
// 1 ≤ k ≤ 26
// 1 ≤ Length of words ≤ 50

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    vector<int> topoSort(int V,vector<int>adj[])
    {
     
        int vis[V]={0};
        int indegree[V]={0};
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
        
    }
  public:
    string findOrder(vector<string> dict, int k) {
        vector<int>adj[k];
        for(int i=0;i<dict.size()-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            
            int len=s1.size()<s2.size() ? s1.size():s2.size();
            
            for(int j=0;j<len;j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int> topo=topoSort(k,adj);
        string res="";
        for(auto it:topo)
        {
           res+=it+'a'; 
        }
        return res;
        
    }
};
