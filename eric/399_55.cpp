/**********************************************************************************
 * https://leetcode.com/problems/evaluate-disivion
 *
 * Auther: Eric Z
 *
 * Tip:
 *
 * Time: O(|V| + |E|)
 * Space: O(|V| + |E|)
 **********************************************************************************/

#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values,
                                vector<pair<string, string>> queries)
    {
        buildGraph(equations, values);

        vector<double> res;
        for (auto &i : queries) {
            auto i1 = m_value.find(i.first);
            auto i2 = m_value.find(i.second);
            if (i1 == m_value.end() ||
                i2 == m_value.end() ||
                i1->second.first != i2->second.first) {
                res.push_back(-1.0);
            }
            else {
                res.push_back(m_value[i.first].second / m_value[i.second].second);
            }
        }
        return res;
    }
private:
    void buildGraph(vector<pair<string, string>> &equations, vector<double>& values)
    {
        for (size_t i = 0; i < equations.size(); ++i) {
            auto eq = equations[i];
            auto val = values[i];
            // What we have: "first/second = val"
            m_input[eq.first].push_back(make_pair(eq.second, val));
            m_input[eq.second].push_back(make_pair(eq.first, 1/val));
            m_value[eq.first] = make_pair(-1, 0.0);
            m_value[eq.second] = make_pair(-1, 0.0);
        }

        int graphIdx = 0;
        for (auto &i : m_input) {
            // starts a new graph
            if (m_value[i.first].first == -1) {
                dfs(i.first, 1.0, graphIdx++);
            }
        }
    }

    void dfs(const string& str, double value, int graphIdx)
    {
        m_value[str] = make_pair(graphIdx, value);
        for (auto &i : m_input[str]) {
            if (m_value[i.first].first == -1) {
                dfs(i.first, value / i.second, graphIdx);
            }
        }
    }

    unordered_map<string, vector<pair<string, double>>> m_input;
    // @int of pair serves: (1) visited? (2) graph index
    unordered_map<string, pair<int, double>> m_value;
};

int main()
{
    vector<pair<string, string>> equations = {{"a","b"}, {"b","a"}, {"a","b"}, {"c","d"}};
    vector<double> values = {1.0,0.5,1.0,3,0};
    vector<pair<string, string>> queries = {{"a","b"}, {"b","a"}, {"c","d"}, {"a","c"}, {"d","c"}};
    vector<double> res;
    Solution so;
    res = so.calcEquation(equations, values, queries);
    for_each(res.cbegin(), res.cend(), [](double d) { cout << d << endl; });

    return 0;
}
