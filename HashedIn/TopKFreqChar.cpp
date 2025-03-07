// link - https://leetcode.com/problems/top-k-frequent-elements/description/
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 
// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.
 
// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

//to basically krna kya hai ki humko top frequent numbers dene hai. To agar hum numbers ki freq priority queue me dale to ho jayega. But freq nikalne ke liye
// hame cahiye kuch to humne map le liya. Phir ab freq compare to kr rahe pr us freq se related key push krna hai isliye pq me freq ke sath key bhi store kr rahe
// Aur pq me jo pehle hota hai uske acc sorting hoti hai

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
       priority_queue<pair<int,int>> pq;
       unordered_map<int,int> hash;
       vector<int> res;
       for(int n:nums)
       {
        hash[n]++;
       } 

       // Traversing hashmap
        for(const auto& pair :hash)
        {
            // Putting freq in first then key
            pq.push({pair.second,pair.first});
        }

        for(int i=0;i<k;i++)
        {
         res.push_back(pq.top().second);
         pq.pop();
        }
        return res;
    }
};