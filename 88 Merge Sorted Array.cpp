/*88	Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

Hide Tags Array Two Pointers
Hide Similar Problems (E) Merge Two Sorted Lists

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int a = m-1;
        int b = n-1;
        int i = m+n-1;
        while(a>=0 && b>=0)
        {
            if(nums1[a] > nums2[b])
            {
                nums1[i--] = nums1[a--];
            }
            else
            {
                nums1[i--] = nums2[b--];
            }
        }
        while(b>=0)
        {
            nums1[i--] = nums2[b--];
        }
    }
};