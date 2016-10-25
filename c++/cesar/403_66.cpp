#include "StdAfx.h"


class Solution403 {

public:
    bool canCross(vector<int>& stones) {
		if(stones.size() <2) return true;
		if(stones[1] != 1) return false;
		unordered_map<int,unordered_map<int,bool>> cache;
		return canCross(stones, 1, 1, cache);
    }

private:
	bool canCross(vector<int>& stones, int start, int lastStep, unordered_map<int,unordered_map<int,bool>>& cache){
		if(start==stones.size()-1) {
			cache[start][lastStep] = true;
			return true;
		}
		//binary search
		vector<int> steps(3, lastStep);
		steps[0]--;
		steps[2]++;
		int low = start;
		for(int i=0;i<3;i++){
			if(steps[i]==0) continue;
			int target = stones[start] + steps[i];			
			int high = stones.size()-1;
			while(low<=high){
				int mid = (low+high)/2;
				if(stones[mid] == target){
					break;
				}else if( stones[mid] < target){
					low = mid+1;
				}else{
					high = mid-1;
				}
			}
			if(low<=high){
				bool r;
				unordered_map<int,unordered_map<int,bool>>::iterator it1 = cache.find((low+high)/2);
				if(it1 != cache.end()){
					unordered_map<int,bool>::iterator it2 = it1->second.find(steps[i]);
					if(it2 != it1->second.end()){
						r = it2->second;
					}else{
						r = canCross(stones, (low+high)/2, steps[i], cache);
					}
				}else{
					r = canCross(stones, (low+high)/2, steps[i], cache);
				}
				if(r) {
					if(i==0){
						cache[start][lastStep-1] = true;
						cache[start][lastStep-2] = true;
					}else if(i==1){
						cache[start][lastStep-1] = true;
						cache[start][lastStep+1] = true;
					}else{
						cache[start][lastStep+1] = true;
						cache[start][lastStep+2] = true;
					}

					cache[start][lastStep] = true;
					return true;
				}
			}
		}
		cache[start][lastStep] = false;
		return false;
	}

};

int main(){
	Solution403 s;
	// [0,1,3,5,6,8,12,17]
	int a[] = {0,1,2,3,4,8,9,11};//{ 0,1,3,5,6,8,12,17};
	vector<int> v(a,a+8);
	cout<<s.canCross(v);
	return 0;
}