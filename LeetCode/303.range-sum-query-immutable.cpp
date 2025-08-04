/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class NumArray
{
    vector<int> m_arr{};

public:
    vector<int> sums{};
    NumArray(vector<int> &nums)
    {
        m_arr = nums;

        int valStore{0};
        // prefix sums cal step 1
        for (int i{0}; i < nums.size(); i++)
        {
            valStore += m_arr[i];
            sums.push_back(valStore);
        }
    }

    int sumRange(int left, int right)
    {
        if (left == right)
        {
            return m_arr[left];
        }
        else if (left == 0)
        {
            return sums[right];
        }
        else
        {
            return (sums[right] - sums[left - 1]);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

