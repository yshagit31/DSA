//link - https://www.naukri.com/code360/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1&
// Problem statement
// You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].

// Now, in the given array/list, 'M' numbers are present twice and one number is present only once.

// You need to find and return that number which is unique in the array/list.

//  Note:
// Unique element is always present in the array/list according to the given condition.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^3
// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 2 3 1 6 3 6 2
// Sample Output 1:
// 1
// Explanation: The array is [2, 3, 1, 6, 3, 6, 2]. Here, the numbers 2, 3, and 6 are present twice, and the number 1 is present only once. So, the unique number in this array is 1.
// Sample Input 2:
// 2
// 5
// 2 4 7 2 7
// 9
// 1 3 1 3 6 6 7 10 7
// Sample Output 2:
// 4
// Explanation: In the first test case, the array is [2, 4, 7, 2, 7]. Here, the numbers 2 and 7 are present twice, and the number 4 is present only once. So, the unique number in this array is 4.

// 10
// Explanation: In the second test case, the array is [1, 3, 1, 3, 6, 6, 7, 10, 7]. Here, the numbers 1, 3, 6, and 7 are present twice, and the number 10 is present only once. So, the unique number in this array is 10.

int findUnique(int *arr, int size)
{
    //Write your code here
    int ans=0;
    for(int i=0;i<size;i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}


//Unique nos in given range

//link - https://www.geeksforgeeks.org/problems/unique-numbers3019/1

// In the given range [L, R], print all numbers having unique digits. e.g. In range 10 to 20 should print all numbers except 11.

// Example 1:

// Input:
// L = 10
// R = 20

// Output:
// 10 12 13 14 15 16 17 18 19 20

// Explanation:
// The number 11 has two 1 therefore
// 11 is not a unique number.
// Example 2:

// Input:
// L = 1
// R = 9

// Output:
// 1 2 3 4 5 6 7 8 9

// Explanation:
// All the Numbers are unique.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function uniqueNumbers() which takes two integers L and R as an input parameter and returns the list/vector of all the unique numbers present between L to R.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= L <= R <= 104

 //{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    bool uniqueDigit(int num)
    {
        bool digitSeen[10]={false};
        int dgt;
        while(num>0)
        {
            dgt=num%10;
            if(digitSeen[dgt])
            {
                return false;
            }
            digitSeen[dgt]=true;
            num=num/10;
        }
        return true;
    }
    vector<int> uniqueNumbers(int L,int R)
    {
        vector <int> ans;
        for(int i=L;i<=R;i++)
        {
         if(uniqueDigit(i))
         {
            ans.push_back(i);
         }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l,r ;
        cin >> l >> r;
		Solution ob;
		vector<int> numbers = ob.uniqueNumbers(l,r);
		
		for(int num : numbers){
		   cout<<num<<" ";
		}
		cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends