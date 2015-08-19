/*	28	Implement strStr()
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.

Hide Tags Two Pointers String
Hide Similar Problems (H) Shortest Palindrome

*/


class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int hlen = haystack.length();
        int nlen = needle.length();
        if(nlen==0)
        {
            return 0;
        }
        for(int i=0; i<hlen-nlen+1; i++)
        {
            int j=0;
            for(; j<nlen; j++)
            {
                if(haystack[i+j]!=needle[j])
                {
                    break;
                }
            }
            if(j==nlen)
            {
                return i;
            }
        }
        return -1;
    }
};