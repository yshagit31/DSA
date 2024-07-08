//link - https://leetcode.com/problems/is-subsequence/description/
// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false
 

// Constraints:

// 0 <= s.length <= 100
// 0 <= t.length <= 104
// s and t consist only of lowercase English letters.
 

// Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?

//6 july String Session

#include<bits/stdc++.h>
using namespace std;

//done by me
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        if(s.empty()&&!t.empty()) return true;
        if(s.empty()&&t.empty()) return true;
        while(j<s.size())
        {
        while(i<t.size())
        {
            if(j==s.size()-1&&t[i]==s[j]) return true;
         if(t[i]==s[j]) {i++; break;}
            i++;
        }
        j++;
        }
        return false;
    }
};


//optimised soln
//comments me mila

    bool isSubsequence(string s, string t) {
        int sIndex = 0, tIndex = 0;
        while (sIndex < s.length() && tIndex < t.length()) {
            if (s[sIndex] == t[tIndex]) {
                sIndex++;
            }
            tIndex++;
        }
        return sIndex == s.length();
    };