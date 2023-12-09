// LINK - https://www.interviewbit.com/problems/longest-increasing-subsequence/ 
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

// method 1
int lis(const vector<int> &A) {
    int n= A.size();
    vector<int> temp;
    temp.push_back(A[0]);
    for(int i=1; i<n; i++){
        if(A[i]>temp.back()){
            temp.push_back(A[i]);
        } else {
            int index= lower_bound(temp.begin(), temp.end(), A[i])-temp.begin();
            temp[index]= A[i];
        }
    }
    return temp.size();
}

// method 2
int lis(const vector<int> &A) {
    int n= A.size();
    vector<int> dp(n, 1);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[i]>A[j]){
                dp[i]= max(dp[i], 1+dp[j]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
