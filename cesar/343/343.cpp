#include <iostream>
#include <gtest/gtest.h>
using namespace std;


class Solution343 {
public:
    int integerBreak(int n) {
        //binary search
		int p2 = getProductBySegment(n, 2);
		int p3 = getProductBySegment(n, 3);
		if(p2>=p3) return p2;
		else{
			int low = 2;
			int high = n;
			int pmid;
			while(low<=high){
				int mid = (low+high)/2;
				pmid = getProductBySegment(n, mid);
				int pright = getProductBySegment(n, mid+1);
				int pleft = getProductBySegment(n, mid-1);
				if(pmid>=pright && pmid>=pleft) return pmid;
				else {
					if(pmid< pleft){
						high=mid-1;
					}else{
						low=mid+1;
					}
				}
			}
			return pmid;
		}
    }

private:
	int getProductBySegment(int n, int segment){
		int base = n/segment;
		int r = n%segment;
		int p = 1;
		for(int i=0;i<segment-r;i++){
			p*=base;
		}
		for(int i=0;i<r;i++){
			p*=(base+1);
		}
		return p;
	}

};

TEST(Test343, Test_2)
{
  Solution343 s;
  EXPECT_EQ(1,s.integerBreak(2));
}

TEST(Test343, Test_3)
{
  Solution343 s;
  EXPECT_EQ(2,s.integerBreak(3));
}

TEST(Test343, Test_10)
{
  Solution343 s;
  EXPECT_EQ(36,s.integerBreak(10));
}

TEST(Test343, Test_40)
{
  Solution343 s;
  EXPECT_EQ(2125764,s.integerBreak(40));
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}



