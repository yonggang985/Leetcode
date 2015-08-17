/*119	Pascal's Triangle II
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Hide Tags Array
Hide Similar Problems (E) Pascal's Triangle

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> vec(rowIndex+1);
        vec[0] = 1;
        vec[rowIndex] = 1;
        for(int m=1;m<rowIndex/2+1; ++m)
        {
            vec[rowIndex-m] = ((long long int)vec[m-1]*vec[rowIndex-m+1])/m;
            vec[m] = vec[rowIndex-m];
        }
        return vec;
    }
};