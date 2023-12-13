// LINK - https://www.interviewbit.com/problems/add-one-to-number/
// EASY

#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &nums)
{
  reverse(nums.begin(), nums.end());
  int sum = 0, carry = 1;
  for (auto &c : nums)
  {
    sum = (c + carry) % 10;
    carry = (c + carry) / 10;
    c = sum;
  }
  if (carry != 0)
    nums.push_back(carry);
  while (nums.back() == 0)
    nums.pop_back();
  reverse(nums.begin(), nums.end());
  return nums;
}