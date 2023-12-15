// LINK - https://www.interviewbit.com/problems/hotel-bookings-possible/
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int c)
{
  int n = arrive.size();
  sort(arrive.begin(), arrive.end());
  sort(depart.begin(), depart.end());
  int rooms = 0;
  int i = 0, j = 0;
  while (i < n && j < n)
  {
    if (arrive[i] <= depart[j])
    {
      rooms++;
      i++;
    }
    else
    {
      rooms--;
      j++;
    }
    if (rooms > c)
      return false;
  }
  return true;
}