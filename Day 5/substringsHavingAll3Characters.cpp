// Question link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution
{
public:
    int numberOfSubstrings(string s)
    {

        int res = 0, a = -1, b = -1, c = -1;

        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == 'a')
                a = i;

            else if (s[i] == 'b')
                b = i;

            else
                c = i;

            if (i > 1)
                res += min(a, min(b, c)) + 1;
        }

        return res;
    }
};