// Question Link: https://leetcode.com/problems/count-nice-pairs-in-an-array/

#define MOD 1000000007

class Solution
{
public:
    int revNum(int num)
    {

        int res = 0;

        while (num)
        {

            res = res * 10 + num % 10;
            num /= 10;
        }

        return res;
    }

    int countNicePairs(vector<int> &nums)
    {

        unordered_map<int, long long int> m;

        int n = nums.size();

        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            nums[i] = nums[i] - revNum(nums[i]);
            m[nums[i]]++;
            ans = (ans + m[nums[i]] - 1) % MOD; // got it
        }

        return ans % MOD;
    }
};