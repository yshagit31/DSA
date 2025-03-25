// 3169. Count Days Without Meetings

// You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

// Return the count of days when the employee is available for work but no meetings are scheduled.

// Note: The meetings may overlap.

// Example 1:

// Input: days = 10, meetings = [[5,7],[1,3],[9,10]]

// Output: 2

// Explanation:

// There is no meeting scheduled on the 4th and 8th days.

// Example 2:

// Input: days = 5, meetings = [[2,4],[1,3]]

// Output: 1

// Explanation:

// There is no meeting scheduled on the 5th day.

// Example 3:

// Input: days = 6, meetings = [[1,6]]

// Output: 0

// Explanation:

// Meetings are scheduled for all working days.

 

// Constraints:

// 1 <= days <= 109
// 1 <= meetings.length <= 105
// meetings[i].length == 2
// 1 <= meetings[i][0] <= meetings[i][1] <= days


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
  vector<pair<int,int>>time;
  vector<pair<int,int>>merged;
    for(int i=0;i<meetings.size();i++)
        {
         time.push_back(make_pair(meetings[i][0],meetings[i][1]));
        }
        sort(time.begin(),time.end());

        int j=0;
        // for(int i=0;i<time.size()-1;i++)
        // {
        //     int s=time[i].first;
        //     int e=time[i].second;
        //     if(time[i].first>=s&&time[i].first<=e)
        //     {
        //         e=max(e,time[i].second);
        //         merged.push_back(make_pair(s,e));
        //         j++;
        //     }
        // }
               merged.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i].first <= merged.back().second) {
                // Overlapping intervals, merge them
                merged.back().second = max(merged.back().second, intervals[i].second);
            } else {
                // Non-overlapping interval, add to merged list
                merged.push_back(intervals[i]);
            }
        }

       int cnt=0,l,r;

        for(int i=0;i<merged.size();i++)
        {
            if(i==0) 
            {
                cnt+=merged[i].first-1;
                l=merged[i].second;
            }else if(i==merged.size()-1)
            {
                   r=merged[i].first;
                   cnt+=r-l-1;
                cnt+=days-merged[i].second;
            }
            else{
                r=merged[i].first;
                cnt+=r-l-1;
                l=merged[i].second;
            }
        }
    return cnt;
    }
}