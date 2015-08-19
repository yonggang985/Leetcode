/*	172	Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Hide Tags Math
Hide Similar Problems (M) Number of Digit One

*/

class Solution {
public:
    int trailingZeroes(int n) 
    {
        return n==0 ? 0 : n/5 + trailingZeroes(n/5);
    }
};