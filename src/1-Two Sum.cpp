// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Javier Liu
// Date   : 2015-02-26

/********************************************************************************** 
* 
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
*              
**********************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    /*
     *   The easy solution is O(n^2) run-time complexity. But Time Limit Exceeded!!!!
     *
     *     vector<int> vecResult(2, 0);
     *     for (int i = 0; i < numbers.size() - 1; ++i)
     *     {
     *        int iTemp = target - numbers[i];
     *        for (int j = i + 1; j < numbers.size(); ++j)
     *        {
     *            if (iTemp == numbers[j])
     *            {
     *                vecResult[0] = i+1;
     *                vecResult[1] = j+1;
     *            }
     *        }
     *     }
     *     return vecResult;
     */
        vector<int> vecResult(2, 0);
        map<int, int> mapHash;
        for (int i = 0; i < numbers.size(); ++i)
        {
            int iTemp = target - numbers[i];
            
            if (mapHash.find(numbers[i]) != mapHash.end())
            {
                vecResult[0] = mapHash[numbers[i]] + 1;
                vecResult[1] = i+1;
            }
            else
            {
                mapHash[iTemp] = i;
            }
        }
        return vecResult;
    }
};