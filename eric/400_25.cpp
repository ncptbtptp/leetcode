#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
   int findNthDigit(int n) {
      double group = 9, sum = group;
      int width = 1, bit = 0, number = 0;
      while (n > sum) {
         ++width;
         group *= 10;
         sum += group * width;
      }

      n = n - (sum - group * width);
      number = (n - 1) / width + 1;   // 1-based
      bit = (n - 1) % width + 1;  // 1-based
      number = (group / 9) + number - 1;
      return findDigit(number, width, bit);
   }

   // find kth decimal bit (1-based) in number
   int findDigit(int number, int width, int k)
   {
      int x = pow(10, (width - 1));
      while (k > 1) {
         number = number % x;
         x = x / 10;
         --k;
      }
      return number / x;
   }
};

int main()
{
   Solution so;
   cout << so.findNthDigit(1000000000) << endl;

   return 0;
}
