// Question link: https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long> st;

        for (auto i : tokens)
        {

            if (i == "+" && !st.empty())
            {

                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();

                st.push(op2 + op1);
            }

            else if (i == "-" && !st.empty())
            {

                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();

                st.push(op2 - op1);
            }

            else if (i == "*" && !st.empty())
            {

                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();

                st.push(op2 * op1);
            }

            else if (i == "/" && !st.empty())
            {

                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();

                st.push(op2 / op1);
            }

            else
                st.push(stoi(i));
        }

        return st.top();
    }
};