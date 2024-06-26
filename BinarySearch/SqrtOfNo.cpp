//link - https://www.naukri.com/code360/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM
// Problem statement
// You are given a positive integer ‘n’.

// Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

// Example:
// Input: ‘n’ = 7

// Output: 2

// Explanation:
// The square root of the number 7 lies between 2 and 3, so the floor value is 2.


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 6
// Sample Output 1:
// 2
// Explanation of Sample Input 1:
// The square root of the given number 6 lies between 2 and 3, so the floor value is 2.

// Sample Input 2:
// 100
// Sample Output 2:
// 10
// Explanation of Sample Output 2:
// The square root of the given number 100 is 10.

// Expected Time Complexity:
// Try solving this in O(log(n)).
// Constraints:
// 0 <= n <= 10 ^ 9

#include<bits/stdc++.h>
using namespace std;

int floorSqrt(int n)
{
   int low=1,high=n,ans;
   long long mid;

   // we'll square mid no from 1 to n and if that mid sauqre is smaller than req no then, means square of mid is less than no so we need to check in right of mid.
    // Yani update start to mid+1. If mid sqaure is gerater than our no so means root lies before mid, update end; 
    
   while(low<=high)
    {
        mid=low+(high-low)/2;
        long long sqrt=mid*mid;
        if(sqrt==n)
        {
            return mid;
        }
        else if(sqrt<n)
        {
            low=mid+1;
            ans=mid;
        }
        else 
        {
            high=mid-1;
        }
    }
    return ans;
}

///what if we want the the decimal points as well meaning exact values

double morePrecision(int n,int precision, int tempSol)
{
    double factor=1, ans=tempSol;
    for(int i=0;i<precision;i++)
    {
        factor=factor/10;
        cout<<factor<<endl;
        for(double j=ans;j*j<n;j=j+factor)
        {
            cout<<j<<endl;
            ans=j;
        }
    }
    return ans;
}
int main()
{
 int tempsol,n;
 cout<<"Enter number ";
 cin>>n;
 tempsol=floorSqrt(n);
 cout<<"Square root of "<<n<<" is "<<morePrecision(n,3,tempsol);
}