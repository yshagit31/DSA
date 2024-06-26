// link-https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?page=1&category=Arrays,Binary%20Search&sortBy=submissions

// Given an unsorted array arr of size n of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.
// Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer (The first index contains B and second index contains A)

// Examples

// Input: n = 2 arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and smallest positive missing number is 1.
// Input: n = 3 arr[] = {1, 3, 3} 
// Output: 3 2
// Explanation: Repeating number is 3 and smallest positive missing number is 2.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 ≤ n ≤ 105
// 1 ≤ arr[i] ≤ n

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int A=0;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            A=A^arr[i];
        }
        for(int i=1;i<=n;i++)
        {
            A=A^i;
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]==arr[i+1]&&(ans.empty()||ans.back()!=arr[i]))
            {
                ans.push_back(arr[i]);
            }
        }
        A=A^ans.back();
        ans.push_back(A);
        return ans;
    }
};

    vector<int> findTwoElement(vector<int> arr, int n) {
        int A=0,B;
        vector<int> count(n+1,0);
        vector<int> ans(2);
        for(int i=0;i<n;i++)
        {
            count[arr[i]]++;
        }
       
        for(int i=1;i<=n;i++)
        {
            if(count[i]==2)   B=i;
            else if(count[i]==0) A=i;
        }
        ans[0]=B;
        ans[1]=A;
        return ans;
    }

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends