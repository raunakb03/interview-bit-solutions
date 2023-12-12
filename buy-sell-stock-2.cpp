// LINK - https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &arr)
{
  int n = arr.size();
  vector<vector<int>> dp(n + 1, vector<int>(2, 0));

  for (int day = n - 1; day >= 0; day--)
  {
    for (int buy = 0; buy < 2; buy++)
    {
      int profit = 0;
      if (buy == 0)
        profit = max(dp[day + 1][buy], -arr[day] + dp[day + 1][1 - buy]);
      else
        profit = max(dp[day + 1][buy], arr[day] + dp[day + 1][1 - buy]);
      dp[day][buy] = profit;
    }
  }
  return dp[0][0];
}
