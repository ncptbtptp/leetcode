/**********************************************************************************
 * https://leetcode.com/problems/maximum-subarray/
 *
 * Auther: ncptbtptp
 *
 * Tip:
 *
 * Time:
 * Space:
 * Beat:
  **********************************************************************************/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& a) {

		int max_sum = a[0];
		int max_sum_ending_here = a[0];

		for (int i = 1; i < a.size(); ++i)
		{
			if (max_sum_ending_here > 0)
				max_sum_ending_here += a[i];
			else
				max_sum_ending_here = a[i];

			if (max_sum_ending_here > max_sum)
				max_sum = max_sum_ending_here;
		}

		return max_sum;

	}
};

