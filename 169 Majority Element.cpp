/*	169	Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags Divide and Conquer Array Bit Manipulation
Hide Similar Problems (M) Majority Element II

*/


class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int len = nums.size();
        int major = nums[0];
        int count = 1;
        for(int i=1; i<len; i++)
        {
           if(count==0)
           {
               count++;
               major = nums[i];
           }
           else if(major==nums[i])
           {
               count++;
           }
           else
           {
               count--;
           }
        }
        return major;
    }
};