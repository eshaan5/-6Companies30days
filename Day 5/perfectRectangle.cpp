// Has to revise this one again
// Question link: https://leetcode.com/problems/perfect-rectangle/

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {

        map<pair<int, int>, int> m;

        for (auto it : rectangles)
        {
            m[{it[0], it[1]}]++;
            m[{it[2], it[3]}]++;
            m[{it[0], it[3]}]--;
            m[{it[2], it[1]}]--;
        }

        int count = 0;

        for (auto it = m.begin(); it != m.end(); it++)
        {

            if (abs(it->second) == 1)
            {
                count++;
            }

            else if (abs(it->second) != 1 && it->second != 0)
            {
                return false;
            }
        }

        return count == 4;
    }
};