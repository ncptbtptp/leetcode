#pragma once
class PartitionEqualSubsetSum416
{
public:
	PartitionEqualSubsetSum416(void);
	~PartitionEqualSubsetSum416(void);
	bool canPartition(vector<int>& nums);
	void runTest();
private:
	bool canAddedTo(vector<int>& nums, int start, int target);
};

