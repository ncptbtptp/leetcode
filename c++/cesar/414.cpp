#include "StdAfx.h"


class Solution414 {

public:
    int thirdMax(vector<int>& nums) {
		vector<int> threes;
		for(int i=0;i<nums.size();i++){
			if( threes.empty()) threes.push_back(nums[i]);
			else if(nums[i] > threes[0]){
				threes.insert(threes.begin(), nums[i]);
			}else if( nums[i] != threes[0] && ((threes.size() > 1 && nums[i] > threes[1]) || threes.size()==1)){
				threes.insert(threes.begin()+1, nums[i]);
			}else if( nums[i] != threes[0] && nums[i] != threes[1] && ((threes.size() > 2 && nums[i] > threes[2]) || (threes.size()==2 ))){
				threes.insert(threes.begin()+2, nums[i]);
			}
			if( threes.size()>3){
				threes.erase(threes.begin()+3);
			}

		}
		if( threes.size() < 3){
			return threes[0];
		}else return threes[2];
    }
};

/*int main(){
	Solution414 s;
	int a[] = {3,3,2,2,5,5};
	vector<int> v(a,a+6);
	cout<<s.thirdMax(v);
	return 0;
}*/