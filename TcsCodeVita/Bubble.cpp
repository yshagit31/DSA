#include<bits/stdc++.h>
using namespace std;

int SwapAscending(int arr[],int n)
{
    int scnt=0,temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                scnt++;
            }
        }
    }
    return scnt;
}
int SwapDescending(int arr[],int n)
{
    int scnt=0,temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                scnt++;
            }
        }
    }
    return scnt;
}
int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    int ac[n],dc[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    copy(arr,arr+n,ac);
    copy(arr,arr+n,dc);
    int aswap=SwapAscending(ac,n);
    int dswap=SwapDescending(dc,n);
    cout<<(aswap<dswap ? aswap : dswap);
}