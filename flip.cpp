// LINK - https://www.interviewbit.com/problems/flip/
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

vector<int> flip(string A)
{
  int n = A.size();
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    if (A[i] == '1')
      arr[i] = -1;
    else
      arr[i] = 1;
  }
  int l = 0;
  int curr_sum = 0;
  int best_sum = 0;
  pair<int, int> ans = {INT_MAX, INT_MAX};
  for (int i = 0; i < n; i++)
  {
    if (curr_sum + arr[i] < 0)
    {
      l = i + 1;
      curr_sum = 0;
    }
    else
    {
      curr_sum += arr[i];
    }
    if (best_sum < curr_sum)
    {
      best_sum = curr_sum;
      ans.first = l;
      ans.second = i;
    }
  }
  if (ans.first == INT_MAX)
    return vector<int>();
  return {ans.first + 1, ans.second + 1};
}