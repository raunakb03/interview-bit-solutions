// LINK - https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

// tabulation
int maxProfit(const vector<int> &prices)
{
  int n = prices.size();
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
  for (int ind = n - 1; ind >= 0; ind--)
  {
    for (int canBuy = 0; canBuy <= 1; canBuy++)
    {
      for (int cap = 1; cap <= 2; cap++)
      {
        int profit = INT_MIN;
        if (canBuy)
        {
          int buy = -prices[ind] + dp[ind + 1][0][cap];
          int notBuy = 0 + dp[ind + 1][1][cap];
          profit = max(buy, notBuy);
        }
        else
        {
          int sell = prices[ind] + dp[ind + 1][1][cap - 1];
          int notSell = 0 + dp[ind + 1][0][cap];
          profit = max(sell, notSell);
        }
        dp[ind][canBuy][cap] = profit;
      }
    }
  }
  return dp[0][1][2];
}

// space optimization
int maxProfit(const vector<int> &prices)
{
  int n = prices.size();
  vector<vector<int>> curr(2, vector<int>(3, 0));
  vector<vector<int>> next(2, vector<int>(3, 0));
  for (int ind = n - 1; ind >= 0; ind--)
  {
    for (int canBuy = 0; canBuy <= 1; canBuy++)
    {
      for (int cap = 1; cap <= 2; cap++)
      {
        int profit = INT_MIN;
        if (canBuy)
        {
          int buy = -prices[ind] + next[0][cap];
          int notBuy = 0 + next[1][cap];
          profit = max(buy, notBuy);
        }
        else
        {
          int sell = prices[ind] + next[1][cap - 1];
          int notSell = 0 + next[0][cap];
          profit = max(sell, notSell);
        }
        curr[canBuy][cap] = profit;
      }
    }
    next = curr;
  }
  return next[1][2];
}