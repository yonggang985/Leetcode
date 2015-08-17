/*	168	Excel Sheet Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases.

Hide Tags Math
Hide Similar Problems (E) Excel Sheet Column Number


*/


class Solution {
public:
    string convertToTitle(int n) 
    {
        string res;
        char temp;
        while(n!=0)
        {
            n -= 1;
            temp = 'A' + n%26;
            res = temp + res;
            n /= 26;
        }
        return res;
    }
};