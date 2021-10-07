/**********************************************************************************
 * https://leetcode.com/problems/target-sum/
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
#include <iostream>
#include <queue>
#include <unordered_set>
#include <set>
#include <map>
#include <cmath>
using namespace std;

/*
class Solution {
public:
    // bitIdx starts from 0, least significant bit
    bool is_set(int num, int bitIdx) {
        return (num & 1 << bitIdx);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0, n = nums.size();
        
        // try bitmasks in [0, 2^n)

        for (int bitmask = 0; bitmask < std::pow(2, n); ++bitmask) {
            int sum(0);
            for (int bitIdx = 0; bitIdx < n; ++bitIdx) {
                // for each bit: 0 means +, 1 means -
                if (is_set(bitmask, bitIdx)) sum -= nums[bitIdx];
                else sum += nums[bitIdx];
            }
            if (sum == target) {
                ++count;
            }
        }
        
        return count;
    }
};
*/

/*
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int count(0);        
        vector<int> cache({0});
        for (int i = 0; i < nums.size() - 1; ++i) {
            vector<int> tmp;
            for (auto num : cache) {
                tmp.push_back(num + nums[i]);
                tmp.push_back(num - nums[i]);
            }
            cache.swap(tmp);
        }

        for (auto num : cache) {
            if (num + nums.back() == target) ++count;
            if (num - nums.back() == target) ++count;
        }

        return count;
    }
};
*/

//class Solution {
//public:
//    int findTargetSumWays(vector<int>& nums, int target) {
//        
//        int count(0);
//        map<int, int> cache = {{0, 1}};
//
//        for (int i = 0; i < nums.size() - 1; ++i) {
//            map<int, int> tmp;
//            for (auto num : cache) {
//                int num_1 = num.first + nums[i], num_2 = num.first - nums[i];
//                if (tmp.find(num_1) == tmp.end()) tmp[num_1] = num.second;
//                else tmp[num_1] += num.second;
//
//                if (tmp.find(num_2) == tmp.end()) tmp[num_2] = num.second;
//                else tmp[num_2] += num.second;
//            }
//            cache.swap(tmp);
//        }
//
//        int num_1(target + nums.back()), num_2(target - nums.back());
//        if (cache.find(num_1) != cache.end()) count += cache[num_1];
//        if (cache.find(num_2) != cache.end()) count += cache[num_2];
//
//        return count;
//    }
//};


//1d memo w/ swap
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int TOTAL(0);
        for_each(nums.begin(), nums.end(), [&TOTAL](int i) { TOTAL += i; });
        
        // sum -> freq, of last level/index i
        vector<int> sums(2 * TOTAL + 1, 0);
        // sentinel
        sums[0 + TOTAL] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            vector<int> tmp(2 * TOTAL + 1, 0);
            for (int j = 0; j < sums.size(); ++j) {
                if (sums[j] != 0) {
                    tmp[j + nums[i]] = sums[j];
                    tmp[j - nums[i]] += sums[j];
                }
            }
            std::swap(tmp, sums);
        }
        
        return (std::abs(target) > TOTAL) ? 0 : sums[target + TOTAL];
    }
};

