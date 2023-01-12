// Question link: https://leetcode.com/problems/invalid-transactions/

class Solution
{
public:
    vector<string> invalidTransactions(vector<string> &transactions)
    {

        int n = transactions.size();
        vector<string> names;
        vector<int> times;
        vector<int> amounts;
        vector<string> cities;

        for (auto i : transactions)
        {

            stringstream ss(i);
            vector<string> v;

            while (ss.good())
            {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }

            names.push_back(v[0]);
            times.push_back(stoi(v[1]));
            amounts.push_back(stoi(v[2]));
            cities.push_back(v[3]);
        }

        // now the game begins
        vector<bool> isValid(n, true);

        for (int i = 0; i < n; i++)
        {

            if (amounts[i] > 1000)
                isValid[i] = false;
            ;

            for (int j = 0; j < n; j++)
            {

                if ((abs(times[i] - times[j]) <= 60) && (names[i] == names[j]) && (cities[i] != cities[j]))
                {

                    isValid[i] = false;
                    isValid[j] = false;
                }
            }
        }

        vector<string> ans;

        for (int i = 0; i < n; i++)
        {

            if (!isValid[i])
                ans.push_back(transactions[i]);
        }

        return ans;
    }
};