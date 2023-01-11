// Question Link: https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution
{
public:
    int trailingZeroes(int n)
    {

        // no of zeroes means no of 10s in n! which is no of 2 & 5s in n! which simply boils down to no of 5s coz we can get 2 from any even num
        int res = 0;

        /* while(n >= 5) {

            res += n / 5;

            n /= 5;

        }

        return res; */

        return n / 3125 + n / 625 + n / 125 + n / 25 + n / 5;
        // This approach works coz n <= 10^4, so the max no of times we'll be dividing by 5 is 5, 5^6 > 10^4
    }
};