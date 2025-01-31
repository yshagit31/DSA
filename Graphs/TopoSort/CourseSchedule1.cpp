//  Leetcode - 207

//link - https://leetcode.com/problems/course-schedule/

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 
// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.

#include<bits/stdc++.h>
using namespace std;

// M1 - using DFS
class Solution {
private:
    bool dfs(int i, vector<int>& vis, vector<vector<int>>& adj) {
        if (vis[i] == 1) return false; // Cycle detected
        if (vis[i] == 2) return true;  // Already processed

        vis[i] = 1; // Mark the course as being visited
        for (auto it : adj[i]) {
            if (!dfs(it, vis, adj)) {
                return false; // Cycle detected in the prerequisites
            }
        }
        vis[i] = 2; // Mark the course as fully processed
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // Adjacency list for prerequisites
        vector<int> vis(numCourses, 0); // Visited state for each course

        // Build the adjacency list
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); // Add edge from prerequisite to course
        }

        // Perform DFS for each course
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) { // If course hasn't been visited yet
                if (!dfs(i, vis, adj)) {
                    return false; // Cycle detected, can't finish all courses
                }
            }
        }

        return true; // No cycle detected, can finish all courses
    }
};



// The goal of this code is to determine if it's possible to finish all courses given their prerequisites. This is a classic cycle detection problem in a directed graph, where:

// Each course is represented as a node.
// A prerequisite relationship between two courses is represented as a directed edge between two nodes.
// The algorithm uses Depth-First Search (DFS) to detect cycles in the graph. If a cycle is detected, it means that some courses depend on each other in a circular way, and it's impossible to complete all courses.

// Key Steps:
// DFS Traversal:

// The dfs function is responsible for traversing the graph.
// It uses a vis array to track the state of each course:
// 0: The course has not been visited yet.
// 1: The course is being visited (i.e., in the current DFS path).
// 2: The course has been fully processed (all its prerequisites are checked).
// DFS Logic:

// If vis[i] == 1, it means the course is already in the current DFS path, indicating a cycle. So, return false.
// If vis[i] == 2, it means the course has been fully processed, so return true.
// If the course hasn't been visited yet (vis[i] == 0), mark it as being visited (vis[i] = 1).
// For each prerequisite of the current course (for (auto it : adj[i])), recursively call dfs on the prerequisite.
// After visiting all prerequisites, mark the course as fully processed (vis[i] = 2).
// Main Function:

// Create an adjacency list adj where each course points to the courses that depend on it.
// Traverse each course. If it hasn't been visited yet, call dfs to check if it's possible to complete the course without cycles.
// If any cycle is detected, return false. Otherwise, return true.
// Dry Run:
// Let's dry run the code with an example:

// Input:
// cpp
// Copy code
// numCourses = 4
// prerequisites = {{1, 0}, {2, 1}, {3, 2}, {1, 3}}
// Adjacency List Construction:

// adj[0] = {1}: Course 0 is a prerequisite for course 1.
// adj[1] = {2}: Course 1 is a prerequisite for course 2.
// adj[2] = {3}: Course 2 is a prerequisite for course 3.
// adj[3] = {1}: Course 3 is a prerequisite for course 1 (this forms a cycle).
// DFS Traversal:

// Starting with course 0 (i = 0):

// vis[0] = 0, so mark it as being visited: vis[0] = 1.
// Check its prerequisite: course 1 (adj[0] = {1}).
// Call dfs(1).
// DFS on course 1 (i = 1):

// vis[1] = 0, so mark it as being visited: vis[1] = 1.
// Check its prerequisite: course 2 (adj[1] = {2}).
// Call dfs(2).
// DFS on course 2 (i = 2):

// vis[2] = 0, so mark it as being visited: vis[2] = 1.
// Check its prerequisite: course 3 (adj[2] = {3}).
// Call dfs(3).
// DFS on course 3 (i = 3):

// vis[3] = 0, so mark it as being visited: vis[3] = 1.
// Check its prerequisite: course 1 (adj[3] = {1}).
// Call dfs(1).
// DFS on course 1 again (i = 1):

// vis[1] = 1, which means course 1 is already in the current DFS path, indicating a cycle.
// Return false from dfs(1) to dfs(3), and then propagate false back to the main function.
// Final Output:

// Since a cycle is detected, the function returns false, meaning it is not possible to finish all courses.
// Final Vis Array:
// vis = {2, 2, 2, 1}: Courses 0, 1, and 2 are fully processed, but course 3 is still in the current DFS path, indicating a cycle.
// Time Complexity:
// O(V + E), where V is the number of courses (nodes) and E is the number of prerequisites (edges). This is because each node and edge is visited once during the DFS traversal.
// Space Complexity:
// O(V + E) for the adjacency list and the vis array.

