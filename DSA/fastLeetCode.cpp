#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int mostFrequentElement(vector<int> &nums)
    {
        map<int,int> mpp;
        for(int i{0};i<nums.size();i++){
            mpp[nums[i]]++;
        }

        int mostFrequentElement = nums[0];
        int maxfreq=0;
        for(const auto &it : mpp){
            if(it.second>maxfreq) {
                mostFrequentElement =it.first;
                maxfreq = it.second;
            }
        }
        return mostFrequentElement;
    }
};
int main()
{
    vector v1 {2,2,4,4,5};
    Solution s1;
    cout<<s1.mostFrequentElement(v1)<<endl;
}