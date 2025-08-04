/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> myMap;   // we are storing needed as key and index as value
        for(int i{0};i<nums.size();i++){
            int needed = target - nums[i];
            if(myMap.contains(needed)){
                return {myMap[needed],i};
            }
            myMap[nums[i]]=i;
        }
        return {-1,-1};
    }
};
// @lc code=end

