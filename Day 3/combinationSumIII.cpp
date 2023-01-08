// Question link: https://leetcode.com/problems/combination-sum-iii/

class Solution
{
public:
    void solve(int start, int n, int k, vector<int> &temp, vector<vector<int>> &sol)
    {

        if (temp.size() == k)
        {

            if (n == 0)
                sol.push_back(temp);
            return;
        }

        if (n < 0)
            return;

        for (int i = start; i < 10; i++)
        {

            temp.push_back(i);
            solve(i + 1, n - i, k, temp, sol);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> sol;

        if (n == 1 || n == 2)
            return sol;

        vector<int> temp;

        solve(1, n, k, temp, sol);

        return sol;
    }
};