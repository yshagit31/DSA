// link - https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix
// Dijkstra Algorithm
// Difficulty: MediumAccuracy: 50.83%Submissions: 201K+Points: 4Average Time: 25m
// Given a weighted, undirected and connected graph where you have given adjacency list adj. You have to find the shortest distance of all the vertices from the source vertex src, and return a list of integers denoting the shortest distance between each node and source vertex src.

// Note: The Graph doesn't contain any negative weight edge.

// Examples:

// Input: adj = [[[1, 9]], [[0, 9]]], src = 0
// Output: [0, 9]
// Explanation:

// The source vertex is 0. Hence, the shortest distance of node 0 is 0 and the shortest distance from node 0 to 1 is 9.
// Input: adj = [[[1, 1], [2, 6]], [[2, 3], [0, 1]], [[1, 3], [0, 6]]], src = 2
// Output: [4, 3, 0]
// Explanation:

// For nodes 2 to 0, we can follow the path 2-1-0. This has a distance of 1+3 = 4, whereas the path 2-0 has a distance of 6. So, the Shortest path from 2 to 0 is 4.
// The shortest distance from 0 to 1 is 1 .
// Constraints:
// 1 ≤ no. of vertices ≤ 1000
// 0 ≤ adj[i][j] ≤ 1000
// 0 ≤ src < no. of vertices
