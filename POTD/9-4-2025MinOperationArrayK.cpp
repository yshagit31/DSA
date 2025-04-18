// 


#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
      int n = nums.size();
            unordered_set<int> uniqueNum;
    
            for (int i = 0; i < n; i++) {
                if (nums[i] < k) return -1;
                if (nums[i] > k) uniqueNum.insert(nums[i]);
            }
    
            return uniqueNum.size();
        }
    };