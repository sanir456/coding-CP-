/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
          int maxProfit=0;
        
        if(prices.size()<2)
            return 0;
        if(k>prices.size()/2){
            for(int i=1; i<prices.size(); i++)
                maxProfit += max(prices[i]-prices[i-1], 0);
            return maxProfit;
        }
        
        int hold[k+1];
        int rele[k+1];
        for (int i=0;i<=k;++i){
            hold[i] = INT_MAX;
            rele[i] = 0;
        }
        
        for(int i=0; i<prices.size(); i++){
            for(int j=k; j>=1; j--){
                rele[j] = max(rele[j], prices[i]-hold[j]);
                hold[j] = min(hold[j], prices[i]-rele[j-1]);
               
            }
        }
        return rele[k];
    }
};
// @lc code=end

