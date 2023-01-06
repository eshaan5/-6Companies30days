// Question link: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

class Solution {
public:

    int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int hcf = numsDivide[0];
        for(int i=1; i<numsDivide.size(); i++) {

            hcf = gcd(hcf, numsDivide[i]);
            if(hcf == 1)
            break;

        }

        sort(nums.begin(), nums.end());

        int res = 0;

        for(int i=0; i<nums.size(); i++) {

            if((hcf%nums[i]) != 0)
                res++;

            if((hcf%nums[i]) == 0)
                break;

        }

        if(res == nums.size())
            return -1;
        
        return res;
    }
};