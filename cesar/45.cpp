#include "StdAfx.h"

class Solution45 {

public:
	int jump(vector<int>& nums) {
		// end case
		if(nums.size() <= 1) return 0;
		vector<int> jump;
		// 动态规划 令jump[i]为从数组位置i处跳跃到末尾需要的最小次数，则
		// jump[i] = 1+ min(jump[j]) j是从i处一步可以到达的所有位置
		jump.resize(nums.size()-1);
		for(int i=nums.size()-2;i>=0;i--){
			int maxLen = nums[i];
			if(i+maxLen>=nums.size()-1){
				// 位置i已经可以直接跳到数组末尾
				jump[i] = 1;
			}else{
				// 关键！可优化的地方，减少比较次数
				// 如果i的最大可跳范围大于i+1的最大可跳范围，求可跳范围的最小值时可以略过i+1的可跳范围，因为这段范围的最小值已经在之前求jump[i+1]时求过了
				if(nums[i]>nums[i+1]){
					jump[i] = jump[i+1];
					// 从超过i+1的最大可跳范围后面开始继续求最小值!
					for(int j=i+1+nums[i+1]+1; j<=i+maxLen;j++){
						if(jump[j] + 1 < jump[i]) {
							jump[i] = jump[j] + 1;
						}
					}
				}else{
					// i的最大可跳范围小于i+1的最大可跳范围
					jump[i] = jump[i+1] + 1;
					for(int j=i+2;j<=i+maxLen;j++){
						// get the min(jump[j])
						if(jump[j] + 1 < jump[i]) {
							jump[i] = jump[j] + 1;
						}
					}
				}			
			}
		}

		return jump[0];
	}


};

/*int main(){
	Solution45 s;
	int ia[] = {2,3,1,1,4};
	vector<int> v(ia,ia+5);
	cout<<s.jump(v);
	return 0;
}*/