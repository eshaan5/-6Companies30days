// Question link: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {

        int n = cards.size();
        int ans = INT_MAX;
        vector<int> lastOccur(1000001, -1);

        for (int i = 0; i < n; i++)
        {

            if (lastOccur[cards[i]] != -1)
            {

                ans = min(i - lastOccur[cards[i]] + 1, ans);
            }

            lastOccur[cards[i]] = i;
        }

        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};