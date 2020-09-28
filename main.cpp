#include <iostream>
#include<vector>
using namespace std;

int jump(vector<int>& nums) {
        int n = nums.size();
       
      int dp[n];
       memset(dp, 0, sizeof(dp));
       int maxRange = nums[0];
       int maxIdx = 0;
       dp[0] = 0;
       
       int subMax = 0, subMaxIdx = 0;
       
       int i = 0;
       while(i<n)
       {
           while(i<n && i<=maxRange)
           {
               if(i+nums[i]>subMax)
               {
                   subMax = i+nums[i];
                   subMaxIdx = i;
               }
               if(i!=maxIdx)
                   dp[i] = dp[maxIdx]+1;
               i++;
           }
           maxRange = subMax;
           maxIdx = subMaxIdx;
       }
       
       return dp[n-1];
    }

int main(int argc, const char * argv[]) {
    vector<int> v= {2,3,1,1,4};
    cout<<jump(v)<<endl;
    return 0;
}
