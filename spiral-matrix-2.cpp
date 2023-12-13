// LINK - https://www.interviewbit.com/problems/spiral-order-matrix-ii/
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
  int start = 0, end = n - 1, left = 0, right = n - 1;
  vector<vector<int>> ans(n, vector<int>(n, 0));
  int num = 1;
  while (start <= end && left <= right)
  {
    vector<int> curr;
    // traverse left to right
    for (int col = left; col <= right; col++)
    {
      ans[start][col] = num++;
    }
    start++;
    if (start > end)
      break;
    // traverse top to bottom
    for (int row = start; row <= end; row++)
    {
      ans[row][right] = num++;
    }
    right--;
    if (right < left)
      break;
    // traverse right to left
    for (int col = right; col >= left; col--)
    {
      ans[end][col] = num++;
    }
    end--;
    if (end < start)
      break;
    // traverse bottom to top
    for (int row = end; row >= start; row--)
    {
      ans[row][left] = num++;
    }
    left++;
    if (left > right)
      break;
  }
  return ans;
}
