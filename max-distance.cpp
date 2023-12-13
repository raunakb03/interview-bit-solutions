// LINK - https://www.interviewbit.com/problems/max-distance/
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &A)
{
  // max of j-i such that a[j]>=a[i]
  int n = A.size();
  int maxDis = 0, minPos = INT_MAX;
  vector<pair<int, int>> nums;
  for (int i = 0; i < n; i++)
    nums.push_back({A[i], i});
  sort(nums.begin(), nums.end());
  minPos = nums[0].second;

  for (int i = 1; i < n; i++)
  {
    if (nums[i].second > minPos)
      maxDis = max(maxDis, (nums[i].second - minPos));
    minPos = min(minPos, nums[i].second);
  }

  return maxDis;
}
