// LINK - https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &A) {
    if(A.size()==0) return 0;
    int profit=0;
    int currPrice=A[0];
    for(int i=0; i<A.size(); i++){
        currPrice= min(currPrice, A[i]);
        profit= max(profit, A[i]-currPrice);
    }
    return profit;
}
