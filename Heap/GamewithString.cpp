// Given a string str of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of k characters. The value of a string is defined as the sum of squares of the count of each distinct character present in the string. Return the minimum possible required value.

// Examples :

// Input: str = abccc, k = 1
// Output: 6
// Explaination: We remove c to get the value as 12 + 12 + 22
// Input: str = aabcbcbcabcc, k = 3
// Output: 27
// Explaination: We remove two 'c' and one 'b'. Now we get the value as 32 + 32 + 32.
// Expected Time Complexity: O(n+klog(p))  
// Expected Auxiliary Space: O(n)

// Constraints:
// 0 ≤ k ≤ |string length| ≤ 5*104

// Note : Here n is the length of string and p is number of distinct alphabets and k number of alphabets to be removed. 

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minValue(string s, int k) {
        priority_queue<int> heap;
        unordered_map<char,int> letter;
         for(int i=0;i<s.size();i++)
        {
            letter[s[i]]++;
        }
        for(auto it=letter.begin();it!=letter.end();it++)
        {
            heap.push(it->second);
        }
        int j=0;
        int temp=0;
        while(!heap.empty()&& j<k)
        {
            temp=heap.top();
            heap.pop();
            temp--;
            if(temp) heap.push(temp);
            j++;
        }
        int sum=0;
        while(!heap.empty())
        {
            temp=heap.top();
            sum=sum+(temp*temp);
            heap.pop();
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.minValue(s, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends