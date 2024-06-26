//link - https://www.geeksforgeeks.org/problems/compare-two-fractions4438/1
// You are given a string str containing two fractions a/b and c/d, compare them and return the greater. If they are equal, then return "equal".

// Note: The string str contains "a/b, c/d"(fractions are separated by comma(,) & space( )). 

// Examples

// Input: str = "5/6, 11/45"
// Output: 5/6
// Explanation: 5/6=0.8333 and 11/45=0.2444, So 5/6 is greater fraction.
// Input: str = "8/1, 8/1"
// Output: equal
// Explanation: We can see that both the fractions are same, so we'll return a string "equal".
// Input: str = "10/17, 9/10"
// Output: 9/10
// Explanation: 10/17 = 0.588 & 9/10 = 0.9, so the greater fraction is "9/10".
// Expected Time Complexity: O(len|str|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 0<=a,c<=103
// 1<=b,d<=103

#include<bits/stdc++.h> 
using namespace std; 

string compareFrac(string str)
  {
     int pos=str.find(",");
     string s1=str.substr(0,pos);
     string s2=str.substr(pos+2);
     
    int p1=s1.find("/");
     string num1=s1.substr(0,p1);
     string den1=s1.substr(p1+1);
   
     
      int p2=s2.find("/");
     string num2=s2.substr(0,p2);
     string den2=s2.substr(p2+1);
     
     
     double n1=stof(num1)/stoi(den1);
     double n2=stof(num2)/stoi(den2);
 
     
     if(n1>n2)
        return s1;
     else if(n1<n2)
        return s2;
     else 
        return "equal";
    }



// or

class Solution {
  public:
  
  string compareFrac(string str) {
    int pos = str.find(",");
    string s1 = str.substr(0, pos);
    string s2 = str.substr(pos + 2);
    
    int p1 = s1.find("/");
    string num1 = s1.substr(0, p1);
    string den1 = s1.substr(p1 + 1);
 
    
    int p2 = s2.find("/");
    string num2 = s2.substr(0, p2);
    string den2 = s2.substr(p2 + 1);
 
    // Convert numerator and denominator strings to integers
    int n1 = stoi(num1);
    int d1 = stoi(den1);
    int n2 = stoi(num2);
    int d2 = stoi(den2);
    
    // Calculate float values of the fractions
    double f1 = double(n1) / d1;
    double f2 = double(n2) / d2;
    
    // Compare the fractions and return the appropriate string
    if (f1 > f2)
        return s1;
    else if (f1 < f2)
        return s2;
    else 
        return "equal";
}

};