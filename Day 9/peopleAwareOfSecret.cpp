// Question link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/

#define MOD 1000000007

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        // dp[i] = no of new people getting to know about the secret

        long long int noOfPeopleSharing = 0;
        vector<long long int> dp(n + 1, 0);
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {

            long long int noOfNewPeople = dp[max(i - delay, 0)];
            long long int noOfPeopleForgetting = dp[max(i - forget, 0)];

            noOfPeopleSharing += (noOfNewPeople - noOfPeopleForgetting + MOD) % MOD; // +MOD is to avoid underflow

            dp[i] = noOfPeopleSharing;
        }

        int ans = 0;
        for (int i = n - forget + 1; i <= n; i++)
            ans = (ans + dp[i]) % MOD;

        return ans % MOD;
    }
};