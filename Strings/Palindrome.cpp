//link - https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_5&leftPanelTabValue=PROBLEM

// Problem statement
// You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

// Note :
// String 'S' is NOT case sensitive.

// Example :
// Let S = “c1 O$d@eeD o1c”.
// If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “c1odeedo1c”, which is a palindrome. Hence, the given string is also a palindrome.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= T <= 100 
// 1 <= Length(S) <= 10^4
// Where 'T' denotes the number of test cases and 'S' denotes the given string.
// Time Limit : 1 sec

// Sample Input 1 :
// 2
// N2 i&nJA?a& jnI2n
// A1b22Ba
// Sample Output 1 :
// Yes
// No
// Explanation 1 :
// For the first test case, S = “N2 i&nJA?a& jnI2n”. If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “n2injaajni2n”, which is a palindrome. Hence, the given string is also a palindrome.
// For the second test case, S = “A1b22Ba”. If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “a1b22ba”, which is not a palindrome. Hence, the given string is not a palindrome.

// Sample Input 2 :
// 3
// codingninjassajNiNgNidoc
// 5?36@6?35
// aaBBa@
// Sample Output 2 :
// Yes
// Yes
// No

#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(string s)
{
    int i=0,e=s.length()-1;
    while(i<e)
    {
        if(s[i]>=48&&s[i]<=57||s[i]>=65&&s[i]<=90||s[i]>=97&&s[i]<=122)
        {
            if(s[e]>=48&&s[e]<=57||s[e]>=65&&s[e]<=90||s[e]>=97&&s[e]<=122)
            {
                if(tolower(s[i])==tolower(s[e]))
                {
                     i++,e--;
                    continue;
                }
                else
                {
                    return false;
                }
               
            }
            else
            {
                e--;
            }
        }
        else
        {
            i++;
        }
    }
    return true;
}


//with func

bool checkPalindrome(string s)
{
    int i=0,e=s.length()-1;
    while(i<e)
    {
        if(isalnum(s[i]))
        {
            if(isalnum(s[e]))
            {
                if(tolower(s[i])==tolower(s[e]))
                {
                     i++,e--;
                    continue;
                }
                else  return false;  
            }
            else e--;
        }
        else
        {
            i++;
        }
    }
    return true;
}


//shortest code


bool checkPalindrome(string s)
{
    int i=0,e=s.length()-1;
    while(i<e)
    {
        while(i<e&&!isalnum(s[i]))  i++;
        while(i<e&&!isalnum(s[e])) e--;
        if(tolower(s[i])!=tolower(s[e]))
         {
          return false;
         }
         
          i++,e--;
         
    }
    return true;
}