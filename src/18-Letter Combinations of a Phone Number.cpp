// Source : https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : Javier Liu
// Date   : 2015-03-02

/********************************************************************************** 
* 
* Given a digit string, return all possible letter combinations that the number could represent.
* A mapping of digit to letters (just like on the telephone buttons) is given below. 
*
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
* Note: Although the above answer is in lexicographical order, your answer could be in any order you want.
*
* Solution: Recursion
**********************************************************************************/

class Solution {
private:
    char phone[10][4] = { 
                            {' ',  '\0', '\0', '\0' }, //0
                            {'\0', '\0', '\0', '\0' }, //1
                            {'a',  'b',  'c',  '\0' }, //2
                            {'d',  'e',  'f',  '\0' }, //3
                            {'g',  'h',  'i',  '\0' }, //4
                            {'j',  'k',  'l',  '\0' }, //5
                            {'m',  'n',  'o',  '\0' }, //6
                            {'p',  'q',  'r',  's'  }, //7
                            {'t',  'u',  'v',  '\0' }, //8
                            {'w',  'x',  'y',  'z'  }  //9
                        }; 
    void GetCombinations(string& digits, vector<string>& vecResult, string& strOutput,int index)
    {
        if (index == digits.length())
        {
            vecResult.push_back(strOutput);
            return;
        }
        for (int i = 0; i < 4; ++i)
        {
            int number = digits[index] - '0';
            if (phone[number][i] == '\0')
                continue;
            strOutput += phone[number][i];
            GetCombinations(digits, vecResult, strOutput, index+1);
            strOutput.erase(index, 1);
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vecResult;
        if (digits.length() == 0) 
            return vecResult;
        
        string strOutput("");
        GetCombinations(digits, vecResult, strOutput,0);
        return vecResult;
    }
};