/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> mp;
        string str_s;
        for(int i{0};i<int(strs.size());i++){
            str_s = strs[i];
            sort(str_s.begin(),str_s.end());
            mp[str_s].push_back(strs[i]);
        }

        vector<vector<string>> ans(mp.size());
        int index = 0;

        for(auto x:mp){
            auto tmp = x.second;

            for(auto ele : tmp){
                ans[index].push_back(ele);
            }
            index++;
        }

        return ans;

    }
};

// @lc code=end

