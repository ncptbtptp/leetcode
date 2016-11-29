int lengthOfLIS(vector<int>& nums) {
	// A vector saves the LIS that has already been calculated.
	// LIS(length -> the one which has the biggest left number 
	// of all the LIS with the same length) 
	vector<int> lenToNum;
	for(int i=nums.size()-1;i>=0;i--){
		if(lenToNum.empty()){
			lenToNum.push_back(nums[i]);
		}else{
			//binary search
			int low = 0;
			int high = lenToNum.size()-1;
			while(low<=high){
				int mid = (low+high)/2;
				if(lenToNum[mid] < nums[i]){
					high = mid-1;
				}else if(lenToNum[mid] > nums[i]){
					low = mid+1;
				}else{
					break;
				}
			}
			if(low>high){
				if( low < lenToNum.size())
					lenToNum[low] = nums[i];
				else
					lenToNum.push_back(nums[i]);
			}
		}
	}
	if(lenToNum.empty()) return 0;
	else {
		return lenToNum.size();
	}
}