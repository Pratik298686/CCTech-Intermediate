#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include<cassert>
using namespace std;

int findClosestNumber(vector<int> &nums)
{
   sort(nums.begin(),nums.end());
   int close = INT_MAX;
   int ans;

   for(int i = 0; i<= nums.size(); i++)
   {
    if(abs(nums[i]) <= close)
    {
        close = abs(nums[i]);
        ans = nums[i];
    }
   }
   return ans;
}

int main()
{
    vector<int> nums{-4,-2,1,4,8};
    cout<< "Close to zero :"<<findClosestNumber(nums);

}