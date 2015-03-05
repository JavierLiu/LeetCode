// Source : https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Javier Liu
// Date   : 2015-03-02

/********************************************************************************** 
*
* Given a string, find the length of the longest substring without repeating characters. 
* For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
* For "bbbbb" the longest substring is "b", with the length of 1.
* 
* Solution: Use hasp-map to store the last appearance of character.
*           When met the duplicate char, means the previous substring is over, and need to re-cal after the previous duplicate one.
*
**********************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, startIndex = 0;
        map<char, int> mapHashIndex;
        for (int i = 0; i < s.length(); ++i) 
        {
            if (mapHashIndex.find(s[i]) != mapHashIndex.end())
            {
                int currentLen = i - startIndex;
                if (startIndex < mapHashIndex[s[i]]+1)
                    startIndex = mapHashIndex[s[i]]+1;
                mapHashIndex[s[i]] = i;
                if (currentLen > maxLen)
                    maxLen = currentLen;
            }
            else
            {//not find
                mapHashIndex[s[i]] = i;
            }
        }
        if (s.length()-startIndex > maxLen)
            maxLen=s.length()-startIndex;
        return maxLen;
    }
};