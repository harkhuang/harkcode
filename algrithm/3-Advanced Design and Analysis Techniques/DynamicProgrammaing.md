Dynamic Programing
===  


##### Question:[Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/) 
 
#### 解释	  
	 买股票,低价买,高价卖 
		inptu:[7,1,5,3,6,4]
		output: 5

####分析

```
1.确定买点->买点的初始化->注意边界条件
2. 确定卖点或者最大收益->(在状态相同的条件下)买点一旦确认,即可确认最优的买点

```

####注意
        Ps:注意初始化值,注意边界条件
#### 代码 

```
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            // 找到最好的买点  初始化最差的买点  边界定义
            int buy = INT_MAX;
            int profit = 0;
            for(int i =  0;i <prices.size();i++){
                buy    = min(buy, prices[i]);
                //只有边界定义清晰 这里思路才正确
                profit = max(profit ,prices[i] - buy );
            }  
            return profit;
        }
};
```
		
		
		