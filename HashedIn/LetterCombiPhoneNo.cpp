// link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

//Pehle to number to char mapping cahiye so uske liye ya to string se bana lo ya hashmap se. Phir hum har jo bhi digit di hai uske mapped charcters pr
// recursive call krenge phir uske bina usko hata ke recursive call krenge

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string digits, vector<string>&res, string &output ,int index, unordered_map<char,string> &hash)
    {
        if(index>=digits.length())
        {
            res.push_back(output);
            return;
        }
        string curr=hash[digits[index]];
        for(int i=0;i<curr.size();i++)
        {
            output.push_back(curr[i]);
            solve(digits,res,output,index+1,hash);
            output.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) 
    {
        
        vector<string> res;
        if(digits.empty()) return res;
        unordered_map<char,string> hash;
        //using character as a key in hashmap
        hash['2']="abc";  // remember to give 2 as '2' since 2 is a char here
        hash['3']="def";
        hash['4']="ghi";
        hash['5']="jkl";
        hash['6']="mno";
        hash['7']="pqrs";
        hash['8']="tuv";
        hash['9']="wxyz";

        string output;
        int index=0;
        solve(digits,res,output,index,hash);
        return res;

    }
};


// using int as a key in hashmap

class Solution {
public:
    void Solve(string &digits, vector<string>&res, string &output, int index, unordered_map<int,string>&hash)
    {
        if(digits.size()<=index)
        {
            res.push_back(output);
            return;
        }
        int key=digits[index]-'0';
        string curr=hash[key];
        for(int i=0;i<curr.size();i++)
        {
           output.push_back(curr[i]);
           Solve(digits,res,output,index+1,hash);
           output.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
       vector<string> res;
        if(digits.empty()) return {};
       string output="";
       unordered_map<int, string>hash;
       hash[2]="abc";
       hash[3]="def";
       hash[4]="ghi";
       hash[5]="jkl";
       hash[6]="mno";
       hash[7]="pqrs";
       hash[8]="tuv";
       hash[9]="wxyz";

       Solve(digits,res,output,0,hash);
       return res;

    }
};