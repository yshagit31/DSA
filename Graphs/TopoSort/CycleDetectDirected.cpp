// link - https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Cycle in a Directed Graph
// Difficulty: MediumAccuracy: 27.88%Submissions: 433K+Points: 4
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. Specifically, adj[i][j] represents an edge from vertex i to vertex j.

// Example 1:

// Input:



// Output: 1
// Explanation: 3 -> 3 is a cycle
// Example 2:
// Input:


// Output: 0
// Explanation: no cycle in the graph
// Constraints:
// 1 ≤ V, E ≤ 105