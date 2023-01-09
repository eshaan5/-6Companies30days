// Question link: https://leetcode.com/problems/bulls-and-cows/

class Solution
{
public:
    string getHint(string secret, string guess)
    {

        int bulls = 0, cows = 0;

        for (int i = 0; i < secret.length(); i++)
        {

            if (secret[i] == guess[i])
            {
                secret[i] = 'a';
                guess[i] = 'b';
                bulls++;
            }
        }

        for (int i = 0; i < secret.length(); i++)
        {

            for (int j = 0; j < guess.length(); j++)
            {

                if (secret[i] == guess[j] && i != j)
                {

                    cows++;
                    secret[i] = 'a';
                    guess[j] = 'b';
                    break;
                }
            }
        }

        return (to_string(bulls) + "A" + to_string(cows) + "B");
    }
};