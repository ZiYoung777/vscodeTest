#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int N1=s.size(),N2=t.size();
        if(N1<N2)
        return false;
        vector<vector<bool>> dp(N1,vector<bool>(N2,false));
        dp[0][0]=(s[0]==t[0]);
        for(int i=0;i<N1;++i){
            for(int j=max(1,i);j<N2;++j){
                if(s[i]==s[j])
                dp[i][j]=(i==0)?true:dp[i-1][j-1];
            }
        }
        return dp[N1-1][N2-1];
    }
};

int main()
{
    vector<int> b({1,2,3});

    if(1)
    cout<<*max_element(b.begin(),b.end());
    return 0;
}