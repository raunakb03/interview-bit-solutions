// LINK - https://www.interviewbit.com/problems/gas-station/   
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost)
{
  int balance = 0;
  int curr = 0;
  int start = 0;
  int deficit = 0;
  for (int i = 0; i < gas.size(); i++)
  {
    int curr = gas[i] - cost[i];
    balance += curr;
    if (balance < 0)
    {
      start = i + 1;
      deficit += balance;
      balance = 0;
    }
  }
  if (deficit + balance < 0)
    return -1;
  return start;
}
