// LINK - https://www.interviewbit.com/problems/next-permutation/
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &nums)
{
  // 2 1 5 4 3 0 0
  //   |

  // find the element where the curr number is greater than the previous number
  int n = nums.size();
  int ind = -1;
  for (int i = n - 1; i > 0; i--)
  {
    if (nums[i] > nums[i - 1])
    {
      ind = i;
      break;
    }
  }
  if (ind != -1)
  {
    sort(nums.begin() + ind, nums.end());
    int newInd = ind;
    while (newInd < n)
    {
      if (nums[newInd] > nums[ind - 1])
      {
        swap(nums[newInd], nums[ind - 1]);
        break;
      }
      newInd++;
    }
    sort(nums.begin() + ind, nums.end());
    return nums;
  }

  sort(nums.begin(), nums.end());
  return nums;
}
