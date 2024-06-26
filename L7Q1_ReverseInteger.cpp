
//LINK-https://leetcode.com/problems/reverse-integer/description/
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go
//  outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
 

// Constraints:

// -231 <= x <= 231 - 1
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int rev=0,dgt;
        while(x!=0)
        {
            dgt=x%10;
            if(rev>(INT_MAX/10)||rev<(INT_MIN/10)){return 0; } 
            rev=(rev*10)+dgt;
            x=x/10;
        }
        return rev;
        
    }
};