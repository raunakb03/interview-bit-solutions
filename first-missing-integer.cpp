// LINK - https://www.interviewbit.com/problems/first-missing-integer/
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    if (nums[i] > 0 && nums[i] <= n)
    {
      bool dec = false;
      if (nums[i] - 1 > i)
        dec = true;
      swap(nums[nums[i] - 1], nums[i]);
      if (dec)
        i--;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (nums[i] != i + 1)
      return i + 1;
  }
  return n + 1;
}
