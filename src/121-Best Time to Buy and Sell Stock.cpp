// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : Javier Liu
// Date   : 2015-03-08

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
* 
* Solution: Dynamic Programing. Time O(n), Space O(1)
*           P[i]max = P[i-1]max, prices[i]-iMin <= iProfit
*                     prices[i]-iMin, prices[i]-iMin > iProfit
*              
**********************************************************************************/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
    
        int iProfit = 0, iMin = prices[0];
        for (vector<int>::iterator iter=prices.begin(); iter!=prices.end(); ++iter)
        {
            if (*iter-iMin > iProfit)
                iProfit = *iter - iMin;
            if (iMin > *iter)
                iMin = *iter;
        }
        return iProfit;
    }
};