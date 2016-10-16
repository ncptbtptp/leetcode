#include "StdAfx.h"
#include "PartitionEqualSubsetSum416.h"


PartitionEqualSubsetSum416::PartitionEqualSubsetSum416(void)
{
}


PartitionEqualSubsetSum416::~PartitionEqualSubsetSum416(void)
{
}

void PartitionEqualSubsetSum416::runTest()
{
	//[1, 5, 11, 5] [1, 2, 3, 5]
	int aa[] = {1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100,99,100};
	vector<int> v(aa,aa+178);
	cout<<canPartition(v);
}

bool PartitionEqualSubsetSum416::canAddedTo(vector<int>& nums, int start, int target)
{
	for(int i=start;i<nums.size();i++){
		if(nums[i] < target){
			if( i+1 < nums.size()) {
				if( canAddedTo(nums, i+1, target-nums[i]) ) return true;
			}else{
				break;
			}
			
		}else if(nums[i]==target) return true;
		else break;
	}
	return false;
}

bool PartitionEqualSubsetSum416::canPartition(vector<int>& nums) {
    //求和
	int sum = 0;
	for(int i=0;i<nums.size();i++){
		sum+=nums[i];
	}
	if( sum % 2 != 0) return false;
	//排序
	sort(nums.begin(),nums.end(), greater<int>());
	return canAddedTo(nums,0,sum/2);
}
