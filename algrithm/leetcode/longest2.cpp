#include <iostream>
#include <vector>
 
 using namespace std;

class Solution {
public:
    // There's a typical DP solution with O(N^2) Time and O(N) space 
    // DP[i] means the result ends at i
    // So for dp[i], dp[i] is max(dp[j]+1), for all j < i and nums[j] < nums[i]

};
    int lengthOfLIS(vector<int>& nums) {
        const int size = nums.size();
        if (size == 0) { return 0; } 
        vector<int> dp(size, 1);
        int res = 1;
        for (int i = 1; i < size; ++i) {
            printf(" [2, 5, 3, 7, 11, 8, 10, 13, 6] \n");
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {                    
                    //当前数满足条件  后面的数字可以和前面连接 当前数字加1 表示DP当前当项最优
                    dp[i] = max(dp[i], dp[j]+1);
                    printf("%d<%d\n",nums[j], nums[i]);
                  
                }else{
                     printf("%d>%d\n",nums[j], nums[i]);
                }
                   
                printf("dp[%d]=%d\n",i,dp[i]);
            }
            printf("\nlast = dp[%d]=%d\n",i,dp[i]);
            printf("----------------------\n");
            res = max (res, dp[i]);
        }
        printf("====================\n");
        return res;
    }
int main() {
    Solution sol;
    std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };

    std::cout << "Length of Longest Increasing Subsequence is " << lengthOfLIS(v) << 'n';
   return 0;
}
