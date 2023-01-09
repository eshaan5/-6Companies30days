// Question Link: https://leetcode.com/problems/course-schedule/

class Solution
{
public:
    bool solve(int node, unordered_map<int, set<int>> &adj, vector<bool> &visited, vector<bool> &dfsCall)
    {

        visited[node] = true;
        dfsCall[node] = true;

        for (auto i : adj[node])
        {

            if (!visited[i])
            {

                int ans = solve(i, adj, visited, dfsCall);
                if (ans)
                    return true;
            }

            else if (dfsCall[i])
                return true;
        }

        dfsCall[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        // adj list
        unordered_map<int, set<int>> adj;

        for (int i = 0; i < prerequisites.size(); i++)
        {

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].insert(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> dfsCall(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {

            if (!visited[i])
            {

                bool ans = solve(i, adj, visited, dfsCall);
                if (ans)
                    return false;
            }
        }

        return true;
    }
};