#include <vector>
using namespace std;

// {red}{white}{blue}{TODO} + tail pointers: not efficient
class Solution_V1 {
public:
    void sortColors(vector<int>& nums)
    {
        if (nums.size() == 1)
            return;

        int red_tail = -1, white_tail = -1, blue_tail = -1;
        int next = 0;

        while (next < nums.size())
        {
            // Next item is red
            if (nums[next] == 0)
            {
                // Both {white} and {blue} is empty
                if (white_tail == -1 && blue_tail == -1)
                {
                    ++red_tail;
                }
                else if (blue_tail == -1)
                {
                    std::swap(nums[next], nums[red_tail + 1]);
                    ++red_tail;
                    ++white_tail;
                }
                else if (white_tail == -1)
                {
                    std::swap(nums[next], nums[red_tail + 1]);
                    ++red_tail;
                    ++blue_tail;                    
                }
                else
                {
                    nums[next] = 2;
                    nums[white_tail + 1] = 1;
                    nums[red_tail + 1] = 0;
                    ++blue_tail;
                    ++white_tail;
                    ++red_tail;
                }
            }//red
            else if (nums[next] == 1)
            {
                if (blue_tail == -1)
                {
                    if (white_tail == -1)
                        white_tail = red_tail + 1;
                    else
                        ++white_tail;
                }
                else
                {
                    if (white_tail != -1)
                    {
                        std::swap(nums[next], nums[white_tail + 1]);
                        ++blue_tail;
                        ++white_tail;
                    }
                    else
                    {
                        nums[next] = 2;
                        nums[red_tail + 1] = 1;
                        white_tail = red_tail + 1;
                        ++blue_tail;
                    }
                }
            }//white
            else
            {
                if (blue_tail != -1)
                {
                    ++blue_tail;
                }
                else
                {
                    blue_tail = max(red_tail, white_tail) + 1;
                }
            }

            ++next;
        }//while
    }
};

// {red}{white}{TODO}{blue} + head pointers: efficient
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        // SET                  BEGIN
        // red: [0, h1)         h1 = 0
        // white: [h1, h2)      h2 = 0
        // blue: [h3, size())   h3 = size()
        // TODO: [h2, h3)       [0, size())
        int h1 = 0, h2 = 0, h3 = nums.size();

        if (nums.size() < 2) return;

        while (h2 < h3) {
            if (nums[h2] == 0)
            {
                std::swap(nums[h2], nums[h1]);
                ++h1;
                ++h2;
            }
            else if (nums[h2] == 1)
            {
                ++h2;
            }
            else
            {
                std::swap(nums[h2], nums[h3 - 1]);
                --h3;
            }
        }
    }
};
