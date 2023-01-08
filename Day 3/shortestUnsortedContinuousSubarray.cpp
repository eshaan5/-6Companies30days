// Question link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {

        int n = nums.size();
        int s = 0, e = -1;

        int val = nums[0];

        for (int i = 1; i < n; i++)
        {

            if (nums[i] < val) // found last break point
                e = i;

            else
                val = nums[i];
        }

        val = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {

            if (nums[i] > val) // found first break point
                s = i;

            else
                val = nums[i];
        }

        return e - s + 1;
    }
};