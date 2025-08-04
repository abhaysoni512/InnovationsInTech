/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // learning 1 : count
        int zeroCount = count(nums.begin(), nums.end(), 0);
        // learning 2 : for each loop
        for(auto it = nums.begin(); it !=nums.end();){
            if(*it == 0)
                // learning 3: erasing
                it = nums.erase(it);
            else
                ++it;
        }
        // learning 4 : insert
        nums.insert(nums.end(), zeroCount,0);
    }
};
// @lc code=end
// Above program tooks o(n)
/*

below program takes o(n^2)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for(auto &it: nums) {
            if(it != 0)
                nums[pos++] = it;
        }

        while(pos < nums.size()) {
            nums[pos++] = 0;
        }
    }
};
*/