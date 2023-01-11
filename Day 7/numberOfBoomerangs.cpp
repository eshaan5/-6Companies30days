// Question Link: https://leetcode.com/problems/number-of-boomerangs/

class Solution
{
public:
    int dis(vector<int> x, vector<int> y)
    {

        return (x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]);
    }

    int numberOfBoomerangs(vector<vector<int>> &points)
    {

        int ans = 0;

        for (auto i : points)
        {

            unordered_map<int, int> m; // distance - point
            for (auto j : points)
            {

                m[dis(i, j)]++;
            }

            for (auto k : m)
            {

                if (k.second > 1)
                    ans += (k.second * (k.second - 1)); // we have to choose 2 points from k.second no of points
            }
        }

        return ans;
    }
};