// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Author : Javier Liu
// Date   : 2015-03-08

/********************************************************************************** 
* 
* Say you have an array for which the ith element is the price of a given stock on day i.
* Design an algorithm to find the maximum profit. You may complete at most two transactions.
* 
* Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
* 
* Solution: 1. Vmax[n]=Vmax[0..i]+Vmax[i...n], use i to divide the period into two parts. 
*           2. It is easy to calc Vmax[0..i], do as No.121.
*           3. For Vmax[i...n], it equals -Vmin[n...i]. From now to before, loss more means earn more from before to now.
*              
**********************************************************************************/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0 || prices.size() == 1)
            return 0;
        int n = prices.size();

        // Just Like No.121, calculate the max profit for each day.
        vector<int> vecProfit_0toi(n, 0);//vecProfit[0]=0;
        int iMin = prices[0];
        for (int i = 1; i < n; ++i)
        {
            if (prices[i]-iMin > vecProfit_0toi[i-1])
                vecProfit_0toi[i] = prices[i] - iMin;
            else
                vecProfit_0toi[i] = vecProfit_0toi[i-1];

            if (iMin > prices[i])
                iMin = prices[i];
        }

        //Reverse
        //from now to before, generate the array for loss, loss more means earn more from before to now.
        vector<int> vecLoss_ntoi(n, 0);
        int iMax = prices[n-1];
        for (int i = n-2; i >= 0 ; --i)
        {
            if (prices[i]-iMax < vecLoss_ntoi[i+1])
                vecLoss_ntoi[i] = prices[i]-iMax;
            else
                vecLoss_ntoi[i] = vecLoss_ntoi[i-1];

            if (iMax < prices[i])
                iMax = prices[i];
        }

        int iMaxProfit = 0;
        for (int i = 0; i < n-1; ++i)
        {
            iMaxProfit = (vecProfit_0toi[i]-vecLoss_ntoi[i]>iMaxProfit ? vecProfit_0toi[i]-vecLoss_ntoi[i] : iMaxProfit);
        }
        return iMaxProfit;
    }
};