// Problem Statement:

// Every decimal number can be changed into its binary form. Suppose your computer has it's own Coronavirus, that eats binary digits from the right side of a number.
// Suppose a virus has 6 spikes, it will eat up 6 LSB binary digits in your numbers.

// You will have a bunch of numbers, and your machine will have a virus with n spikes, you have to calculate what will be the final situation of the final numbers.

// Input Format:

// First line, a single Integer N

// Second line N space separated integers of the bunch of values as array V Third line a single integer n, the number of spikes in Corona for Computer

// Output Format:

// Single N space separated integers denoting the final situation with the array v.

// Sample Input:

// 5
// 12345
// 2

// Output:
// 00011

// Explanation:

// 5 is 101 in binary, when you cut the last two binary digits, its 1.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr;
    int num;
    cout<<"Enter array elements ";
    while(cin>>num&& num!=-1)
    {
        arr.push_back(num);
    }
    int n;
    cout<<"Enter spikes";
    cin>>n;
    vector <int> vec;
    for(int i : arr)
    {
            int num=i>>n;
            vec.push_back(num);
    }
    for( int i: vec)
    {
        cout<<i<<" ";
    }   
 return 0;
}