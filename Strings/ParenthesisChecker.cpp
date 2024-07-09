//link - https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1?page=1&category=Strings&sortBy=submissions

// Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
// For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).
// Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

// Example 1:
// Input:
// {([])}
// Output: 
// true
// Explanation: 
// { ( [ ] ) }. Same colored brackets can form 
// balanced pairs, with 0 number of 
// unbalanced bracket.

// Example 2:
// Input: 
// ()
// Output: 
// true
// Explanation: 
// (). Same bracket can form balanced pairs, 
// and here only 1 type of bracket is 
// present and in balanced way.

// Example 3:
// Input: 
// ([]
// Output: 
// false
// Explanation: 
// ([]. Here square bracket is balanced but 
// the small bracket is not balanced and 
// Hence , the output will be unbalanced.
// Your Task:
// This is a function problem. You only need to complete the function ispar() that takes a string as a parameter and returns a boolean value true if brackets are balanced else returns false. The printing is done automatically by the driver code.

// Expected Time Complexity: O(|x|)
// Expected Auixilliary Space: O(|x|)

// Constraints:
// 1 ≤ |x| ≤ 32000

//6 july String Session

//done by me 
// approach - for every opening bracket, we add closing bracket to another string. If we encounter closing bracket then we check end of string because it will have 
// the closing bracket of the last bracket we encountered. If its true we remove the last index of string


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        string tobeClosed;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='(') tobeClosed.append(")");
            else if(x[i]=='{') tobeClosed.append("}");
            else if(x[i]=='[') tobeClosed.append("]");
            else if(x[i]==')'&&x[i]!=tobeClosed[tobeClosed.length()-1]) return false;
            else if(x[i]=='}'&&x[i]!=tobeClosed[tobeClosed.length()-1]) return false;
            else if(x[i]==']'&&x[i]!=tobeClosed[tobeClosed.length()-1]) return false;
            else 
            {
                tobeClosed.erase(tobeClosed.length()-1,1);
                continue;
            }
            
         }
        if(!tobeClosed.empty()) return false;
        else return true;
    }
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends