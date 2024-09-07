//link - https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1?page=1&category=Recursion&sortBy=submissions

// Print numbers from 1 to n without the help of loops. You only need to complete the function printNos() that takes N as parameter and prints number from 1 to N recursively.

// Don't print newline, it will be added by the driver code.

// Examples

// Input: n = 10
// Output: 1 2 3 4 5 6 7 8 9 10
// Input: n = 5
// Output: 1 2 3 4 5
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n) (Recursive).

// Constraints:
// 1 <= n <= 1000

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void printNos(int N)
    {
      if(N==1)
      {
          cout<<N<<" ";
          return;
      }
      printNos(N-1);
      cout<<N<<" ";
    }
};

//{ Driver Code Starts.
/* Driver program to test printNos */
int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    
    while(T--)
    {
        int N;
        
        //input N
        cin>>N;
        Solution ob;
        //calling printNos() function
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends