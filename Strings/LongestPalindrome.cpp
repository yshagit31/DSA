 //link - https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1?page=1&category=Strings&sortBy=submissions

// Given a string str, find the longest palindromic substring in str. Substring of string str: str[ i . . . . j ] where 0 ≤ i ≤ j < len(str). Return the longest palindromic substring of str.

// Palindrome string: A string that reads the same backward. More formally, str is a palindrome if reverse(str) = str. In case of conflict, return the substring which occurs first ( with the least starting index).

// Examples :

// Input: str = "aaaabbaa"
// Output: aabbaa
// Explanation: The longest Palindromic substring is "aabbaa".
// Input: str = "abc"
// Output: a
// Explanation: "a", "b" and "c" are the longest palindromes with same length. The result is the one with the least starting index.

// Expected Time Complexity: O(|str|2).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ |str| ≤ 103

//6 July String session


 #include<bits/stdc++.h>
 using namespace std;

//chatgpt soln

  string longestPalin (string S) {
        int n = S.size();
        if (n == 0) return "";
        
        int start = 0, maxLen = 1; // Initialize start and maxLen for the longest palindrome
        for (int i = 0; i < n; ++i) {
            // Find the longest palindrome centered at i
            int l = i, r = i;
            // Expand around center for odd length palindromes (like "aba")
            while (l >= 0 && r < n && S[l] == S[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                --l;
                ++r;
            }
            
            // Expand around center for even length palindromes (like "abba")
            l = i, r = i + 1;
            while (l >= 0 && r < n && S[l] == S[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                --l;
                ++r;
            }
        }
        
        return S.substr(start, maxLen);
  }