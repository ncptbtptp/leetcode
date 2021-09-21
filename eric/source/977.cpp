/**********************************************************************************
 * https://leetcode.com/problems/rotate-array/
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
#include <stack>
using namespace std; 

//// Method 1: right shift one by one (over time limit)
//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        if (nums.size() <= 1)
//            return;
//
//        for (int i = 0; i < k; ++i)
//            rotateByOne(nums);
//    }
//
//    void rotateByOne(vector<int>& nums) {
//        if (nums.size() <= 1)
//            return;
//
//        int last = nums.back();
//        auto it = nums.rbegin();
//        while (it != nums.rend() - 1){
//            *it = *(it + 1);
//            ++it;
//        }
//        *it = last;
//    }
//};

//// Method 2: shift "through"  
//class Solution {
//public:
//    void rotate(vector<int>& nums, int k) {
//        if (nums.size() <= 1)
//            return;
//
//        k = k % nums.size();
//        if (k == 0)
//            return;
//
//        // K < nums.size()
//        rotateSmallLeft(nums, 0, nums.size() - 1 - k, nums.size() - 1);
//    }
//
//    void swap(int& a, int& b) {
//        a = a^b;
//        b = a^b;
//        a = a^b;
//    }
//
//    // Swap block [l1, l2] with [l2+1, l3] of the same size
//    void swapBlock(vector<int>& nums, int l1, int l2, int l3) {
//        size_t len = (size_t)l2 - l1 + 1;
//        for (int i = l1; i <= l2; ++i)
//            swap(nums[i], nums[i + len]);
//    }
//
//    // Move [l1, l2, l3] to [, 13, l1, l2]
//    void plainRotate(vector<int>& nums, int l1, int l2, int l3) {
//        for (int i = l2; i >= l1; --i, --l3) {
//            // i <-> [i+1, l3]
//            for (int j = i + 1; j <= l3; ++j) {
//                swap(nums[j - 1], nums[j]);
//            }
//        }
//    }
//
//    void rotateSmallRight(vector<int>& nums, int l1, int l2, int l3) {
//        if (l3 - l1 <= 10)
//            return plainRotate(nums, l1, l2, l3);
//
//        int len = l2 - l1 + 1;
//        while (l3 - l2 >= len) {
//            swapBlock(nums, l1, l2, l2 + len);
//            l1 += len;
//            l2 += len;
//        }
//
//        if (l3 - l2 > 0)
//            rotateSmallLeft(nums, l1, l2, l3);
//    }
//
//    void rotateSmallLeft(vector<int>& nums, int l1, int l2, int l3) {
//        if (l3 - l1 <= 10)
//            return plainRotate(nums, l1, l2, l3);
//
//        int len = l3 - l2;
//        while (l2 - l1 + 1 >= len) {
//            swapBlock(nums, l2 - len + 1, l2, l3);
//            l2 -= len;
//            l3 -= len;
//        }
//
//        if (l2 - l1 + 1 > 0)
//            rotateSmallRight(nums, l1, l2, l3);
//    }
//};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1)
            return;
    }
};

//int main()
//{
//    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};
//    int k = 56;
//    Solution so;
//    so.rotate(nums, k);
//}
