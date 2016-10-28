#include "StdAfx.h"

class Solution55 {

public:
	bool canJump(vector<int>& nums) {
		if(nums.size() == 1) return true;
		vector<bool> jump;
		jump.resize(nums.size()-1);
		for(int i=nums.size()-2;i>=0;i--)
		{
			if(nums[i]==0) jump[i] = false;
			else if(i + nums[i] >= nums.size()-1){
				jump[i] = true;
			}else{				
				if(nums[i]-nums[i+1]>=1){
					if(jump[i+1] == true){
						jump[i]=true;
					}else{
						// search
						int j=i+2+nums[i+1];
						for(;j<=i+nums[i];j++){
							if(jump[j]==true){
								jump[i]=true;
								break;
							}
						}
						if(j>i+nums[i])
							jump[i] = false;
					}
				}else{
					// search for all positions that current position can reach
					int j=i+1;
					for(;j<=i+nums[i];j++){
						if(jump[j]==true){
							jump[i]=true;
							break;
						}
					}
					if(j>i+nums[i])
						jump[i] = false;
				}
			}
		}
		return jump[0];
	}

};

int main(){
	Solution55 s;
	int ia[] = {2,3,1,1,4};
	vector<int> v(ia,ia+5);
	cout<<s.canJump(v);

	int ia2[] = {3,2,1,0,4};
	vector<int> v2(ia2,ia2+5);
	cout<<s.canJump(v2);
	return 0;
}