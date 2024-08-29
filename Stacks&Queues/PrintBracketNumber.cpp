//link - https://www.geeksforgeeks.org/problems/print-bracket-number4058/1?page=1&category=Stack&difficulty=Easy&sortBy=submissions
// Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the ith opening or closing bracket to appear in the string. 

//  Examples:

// Input:  str = "(aa(bdc))p(dee)"
// Output: 1 2 2 1 3 3
// Explanation: The highlighted brackets in
// the given string (aa(bdc))p(dee) are
// assigned the numbers as: 1 2 2 1 3 3.
// Input:  str = "(((()("
// Output: 1 2 3 4 4 5
// Explanation: The highlighted brackets in
// the given string (((()( are assigned
// the numbers as: 1 2 3 4 4 5
// Expected Time Complexity: O(|str|)
// Expected Auxiliary Space: O(|str|)

// Constraints:
// 1 <= |str| <= 105
// str contains lowercase English alphabets, and '(', ')' characters
// At any index, the number of opening brackets is greater than or equal to closing brackets


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//my approach
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        stack <pair<char,int>> st;
        vector <int> arr;
        int j=0;
        for(int i=0;i<str.length();i++)
        {
         if(str[i]=='(')
         {
             j++;
             st.push(make_pair(str[i],j));
             arr.push_back(j);
         }
            else if(str[i]==')')
            {
                arr.push_back(st.top().second);
                st.pop();
            }
            
        }
        
        return arr;
    }
};

//Rishabh aaproach only storing count in stack
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        stack <int> st;
        vector <int> arr;
        int j=0;
        for(int i=0;i<str.length();i++)
        {
         if(str[i]=='(')
         {
             j++;
             st.push(j);
             arr.push_back(j);
         }
            else if(str[i]==')')
            {
                arr.push_back(st.top());
                st.pop();
            }
            
        }
        
        return arr;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends