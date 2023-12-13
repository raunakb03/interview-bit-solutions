// LINK - https://www.interviewbit.com/problems/largest-number/
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
  string s1 = to_string(a);
  string s2 = to_string(b);
  string aa = s1 + s2;
  string bb = s2 + s1;
  if (aa >= bb)
    return true;
  return false;
}
string largestNumber(const vector<int> &v)
{
  vector<int> arr = v;
  sort(arr.begin(), arr.end(), cmp);
  string ans = "";
  for (auto c : arr)
    ans += to_string(c);
  if (ans[0] == '0')
    return "0";
  return ans;
}
