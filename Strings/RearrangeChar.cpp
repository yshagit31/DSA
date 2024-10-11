// link - https://www.geeksforgeeks.org/problems/rearrange-characters4649/1
// Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
// Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

// Example 1:

// Input : str = "geeksforgeeks"
// Output: 1
// Explanation: All the repeated characters of the
// given string can be rearranged so that no 
// adjacent characters in the string is equal.
// Any correct rearrangement will show a output
// of 1.
// Example 2:

// Input : str = "bbbbb"
// Output: 0
// Explanation: Repeated characters in the string
// cannot be rearranged such that there should not
// be any adjacent repeated character.
// Your task :
// You don't have to read input or print anything. Your task is to complete the functionrearrangeString() which takes the string as input and returns the modified string. If the string cannot be modified return "-1".
// Note:The generatedoutput is 1 if the string is successfully rearranged and is 0 if rearranging is not possible.
 
// Expected Time Complexity : O(NlogN), N = length of String
// Expected Auxiliary Space : O(number of english alphabets)
 
// Constraints :
// 1 <= length of string <= 104

#include<bits/stdc++.h>
using namespace std;

 string rearrangeString(string str)
    {      
     unordered_map<char, int> hash;
    for (char ch : str) {
        hash[ch]++;
    }

    // Priority queue (max heap) to store characters based on frequency
    priority_queue<pair<int, char>> pq;
    
    for (auto it : hash) {
        pq.push({it.second, it.first});
    }

    string res = "";
    pair<int, char> prev = {-1, '#'};  // Initialize with a dummy value
    
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        
        // Append the current character to the result
        res += current.second;

        // Decrease frequency of the current character
        current.first--;
        
        // If the previous character's frequency is still greater than 0, push it back to the queue
        if (prev.first > 0) {
            pq.push(prev);
        }

        // Set current character as the previous character for the next round
        prev = current;
    }

    // If the rearranged string length is not the same as the original, return "-1"
    if (res.length() != str.length()) {
        return "-1";
    }
    
    return res;
    }