// LINK - https://www.interviewbit.com/problems/anti-diagonals/
// EASY

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonal(vector<vector<int>> &mat)
{
  int n = mat.size();
  vector<vector<int>> ans;
  for (int j = 0; j < n; j++)
  {
    int row = j;
    for (int i = 0; i < n; i++)
    {
      // start putting from the row+jth column
      if (row + 1 > ans.size())
      {
        vector<int> curr;
        curr.push_back(mat[i][j]);
        ans.push_back(curr);
      }
      else
      {
        ans[row].push_back(mat[i][j]);
      }
      row++;
    }
  }
  for (auto &c : ans)
  {
    reverse(c.begin(), c.end());
  }
  return ans;
}