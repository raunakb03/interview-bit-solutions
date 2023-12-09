// LINK - https://www.interviewbit.com/problems/majority-element/
// MEDIUM (without using extra space)
 
#include <bits/stdc++.h>
using namespace std;

int majorityElement(const vector<int> &A) {
    int ele=-1, cnt=0;
    for(auto c : A){
        if(cnt==0){ 
            ele= c;
            cnt++;
        }
        else if(c==ele) cnt++;
        else cnt--;
    }
    return ele;
}