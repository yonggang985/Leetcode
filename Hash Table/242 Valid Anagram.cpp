/*242	Valid Anagram
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Hide Tags Hash Table Sort
Hide Similar Problems (M) Anagrams

*/

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int lens = s.length();
        int lent = t.length();
        if(lens!=lent)
        {
            return false;
        }
        int counts[26] = {0};
        for(int i=0; i<lens; i++)
        {
            counts[s[i]-'a']++;
            counts[t[i]-'a']--;
        }
        for(int i=0; i<26; i++)
        {
            if(counts[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};