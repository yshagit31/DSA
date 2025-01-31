// link - https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

// Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

// NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

// Examples:

// Input: V = 5, E = 5
// adj = [[1], [0, 2, 4], [1, 3], [2, 4], [1, 3]] 
// Output: 1
// Explanation: 

// 1->2->3->4->1 is a cycle.
 
// Input: V = 4, E = 2
// adj = [[], [2], [1, 3], [2]]
// Output: 0
// Explanation: 

// No cycle in the graph.
 
// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V) 

// Constraints:
// 1 ≤ V, E ≤ 105

