// Source : https://oj.leetcode.com/problems/reverse-integer/
// Author : Javier Liu
// Date   : 2015-02-27

/********************************************************************************** 
* 
* Reverse digits of an integer.
* 
* Example1: x = 123, return 321
* Example2: x = -123, return -321
* 
* Solution: Consider the boundary condition
*           1. 0
*           2. 10, 20, 100, 1000...
*           3. overflow, reverse 1000000003 -> 3000000001
**********************************************************************************/

class Solution {
public:
    //const int INT_MAX = 2147483647;
    //const int INT_MIN = -2147483648;
    int reverse(int x) {
        bool isNegative(false);
        if (x == 0)
        {
            return 0;
        }
        int iReverse = 0;
        while ( x != 0)
        {
            if (iReverse > INT_MAX / 10 || iReverse < INT_MIN / 10)
            {
                return 0;
            }
            iReverse *= 10;
            iReverse += (x % 10);
            x = x / 10;
        }
        return iReverse;
    }
};