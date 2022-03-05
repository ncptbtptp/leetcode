#include <stack>
#include <vector>
using namespace std;

struct group
{
    group(int idx, int temp) : index(idx), temperture(temp)
    {}
    int index;
    int temperture;
};

class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<group> s;
        vector<int> res(arr.size(), 0);

        for (int i = 0; i < arr.size(); ++i) {
            while (!s.empty() && arr[i] > s.top().temperture) {
                group p = s.top();
                s.pop();
                res[p.index] = (i - p.index);
            }
            s.push(group(i, arr[i]));
        }

        // for rest, no higher "future" temperature, so res[i] = 0
        while (!s.empty()) {
            group p = s.top();
            s.pop();
            res[p.index] = 0;
        }

        return res;
    }
};

