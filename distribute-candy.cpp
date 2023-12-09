// LINK - https://www.interviewbit.com/problems/distribute-candy/  
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &A)
{
  int n = A.size();
  vector<int> lr(n, 1);
  vector<int> rl(n, 1);

  for (int i = 1; i < n; i++)
    if (A[i] > A[i - 1])
      lr[i] = lr[i - 1] + 1;

  for (int i = n - 2; i >= 0; i--)
    if (A[i] > A[i + 1])
      rl[i] = rl[i + 1] + 1;
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += max(lr[i], rl[i]);

  return ans;
}
