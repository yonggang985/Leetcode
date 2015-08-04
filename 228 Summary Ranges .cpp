/*
228 Summary Ranges 
Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> ret;
        int len = nums.size();
        if(0==len)
        {
            return ret;
        }
        int p1 = 0;
        int p2 = 1;
        while(p1<len)
        {
            while(p2<len && nums[p2]==nums[p2-1]+1)
            {
                ++p2;
            }
            if(p1<p2-1)
            {
                ret.push_back(to_string(nums[p1]) + "->" + to_string(nums[p2-1]));
            }
            else
            {
                ret.push_back(to_string(nums[p1]));
            }
            p1 = p2;
            ++p2;
        }
        return ret;
    }
};