// Question link: https://leetcode.com/problems/largest-divisible-subset/

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1); // dp[i] = maximum said set upto i
        int maxDp = 1, prev = -1;

        for (int i = 1; i < n; i++)
        {

            for (int j = 0; j < i; j++)
            {

                if (!(nums[i] % nums[j]) && (dp[i] < 1 + dp[j]))
                {

                    dp[i] = 1 + dp[j];
                    maxDp = max(maxDp, dp[i]);
                }
            }
        }

        vector<int> ans;
        for (int i = n - 1; i >= 0; i--)
        {

            if (maxDp == dp[i] && (prev == -1 || prev % nums[i] == 0))
            {

                ans.push_back(nums[i]);
                maxDp--;
                prev = nums[i];
            }
        }

        return ans;
    }
};