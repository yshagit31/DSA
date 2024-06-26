//code to categorize character on lower case , upper case or digits

#include<iostream>
// #include<stdio.h>
using namespace std;
int main()
{
    char ch;
    cout<<"Enter a character ";
    cin>>ch;
    if(ch>='a'&&ch<='z')
    {
        cout<<"Lower case letters";
    }
     else if(ch>='A'&&ch<='Z')
    {
        cout<<"Uppper case letters";
    }
    else if(ch>='0' && ch<='9')
    {
        cout<<"Digits";
    }
    else
    {
        cout<<"Special characters or non alphanumeric characters";
    }
    return 0;
}