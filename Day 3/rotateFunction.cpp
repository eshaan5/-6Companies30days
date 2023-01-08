// Question link: https://leetcode.com/problems/rotate-function/

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {

        int n = nums.size(), maxi = INT_MIN;

        int prevSum = 0; // f(0)
        for (int i = 0; i < n; i++)
        {
            prevSum += (i * nums[i]);
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        maxi = prevSum;

        for (int i = 0; i < n; i++)
        {

            int currSum = (sum - (n * nums[n - 1 - i]) + prevSum);
            maxi = max(maxi, currSum);

            prevSum = currSum;
        }

        return maxi;
    }
};