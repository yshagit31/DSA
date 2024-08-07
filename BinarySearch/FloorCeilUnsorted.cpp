//link - https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

//named as implement upper bound in striver
// Given an unsorted array Arr[] of N integers and an integer X, find floor and ceiling of X in Arr[0..N-1].

// Floor of X is the largest element which is smaller than or equal to X. Floor of X doesn’t exist if X is smaller than smallest element of Arr[].

// Ceil of X is the smallest element which is greater than or equal to X. Ceil of X doesn’t exist if X is greater than greatest element of Arr[].

// Example 1:

// Input:
// N = 8, X = 7
// Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
// Output: 6 8
// Explanation:
// Floor of 7 is 6 and ceil of 7 
// is 8.
// Example 2:

// Input:
// N = 8, X = 10
// Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
// Output: 9 -1
// Explanation:
// Floor of 10 is 9 but ceil of 10 is not 
// possible.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function getFloorAndCeil() which takes the array of integers arr, n and x as parameters and returns a pair of integers denoting the answer. Return -1 if floor or ceil is not present.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints :
// 1 ≤ N ≤ 105
// 1 ≤ Arr[i], X ≤ 106

 #include<bits/stdc++.h>
 using namespace std;
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int mini=INT_MAX,maxi=INT_MIN;
  
        for(int j=0;j<n;j++)
        {
        if(arr[j]<=x)
        {
            maxi=max(maxi,arr[j]);
        }
           
        if(arr[j]>=x) mini=min(arr[j],mini);
    
        }
 
    if(mini==INT_MAX) return {maxi,-1};
    if(maxi==INT_MIN) return {-1,mini};
    if(maxi==INT_MIN&&mini==INT_MAX) return {-1,-1};
    return {maxi,mini};
}

//or 

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr,arr+n);
    int flo = -1, ce = -1;
    int i = 0, j = n - 1;
    while(i<=j){
        int mid = (i + j)/2;
        if(arr[mid] == x) return {x,x};
        if(arr[mid] < x){
            flo = arr[mid];
            i = mid + 1;
        }else{
            ce = arr[mid];
            j = mid - 1;
        }
    }
    return {flo,ce};
}

// in a sorted array 

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int mini=INT_MAX,maxi=INT_MIN,low=0,high=n-1,mid;
       while(low<=high)
       {
           mid=(low+high)/2;
        if(a[mid]<=x)
        {
            maxi=max(maxi,a[mid]);
            low=mid+1;
        }
        if (a[mid] >= x) {
            mini = min(a[mid], mini);
            high=mid-1;
        }
        }
 
    if(mini==INT_MAX) return {maxi,-1};
    if(maxi==INT_MIN) return {-1,mini};
    if(maxi==INT_MIN&&mini==INT_MAX) return {-1,-1};
    return {maxi,mini};
}