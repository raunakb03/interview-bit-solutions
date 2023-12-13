// LINK - https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &arr)
{
  int max_ans = *max_element(arr.begin(), arr.end());
  int max_till_now = 0;
  for (auto c : arr)
  {
    max_till_now += c;
    max_ans = max(max_ans, max_till_now);
    if (max_till_now < 0)
      max_till_now = 0;
  }
  return max_ans;
}