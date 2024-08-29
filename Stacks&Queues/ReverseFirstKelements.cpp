//link - https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1?page=1&category=Stack&difficulty=Easy&sortBy=submissions
// Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

// Only following standard operations are allowed on queue.

// enqueue(x) : Add an item x to rear of queue
// dequeue() : Remove an item from front of queue
// size() : Returns number of elements in queue.
// front() : Finds front item.
// Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

// Example 1:

// Input:
// 5 3
// 1 2 3 4 5
// Output: 
// 3 2 1 4 5
// Explanation: 
// After reversing the given
// input from the 3rd position the resultant
// output will be 3 2 1 4 5.
// Example 2:

// Input:
// 4 4
// 4 3 2 1
// Output: 
// 1 2 3 4
// Explanation: 
// After reversing the given
// input from the 4th position the resultant
// output will be 1 2 3 4.
// Your Task:
// Complete the provided function modifyQueue() that takes queue and K as parameters and returns a modified queue. The printing is done automatically by the driver code.

// Expected Time Complexity : O(N)
// Expected Auxiliary Space : O(K)

// Constraints:
// 1 <= K <= N <= 105



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k)
    {
       stack <int> st; 
       vector<int> arr;
       for(int i=0;i<k;i++)
       {
         st.push(q.front());
         q.pop();
       }
       while(!q.empty())
       {
          arr.push_back(q.front());
          q.pop();
       }
       while(!st.empty())
       {
           q.push(st.top());
           
           st.pop();
       }
         for(int i=0;i<arr.size();i++)
       {
           q.push(arr[i]);
           
       }
       return q;
      
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends