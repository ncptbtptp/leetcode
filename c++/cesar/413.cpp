#include "StdAfx.h"

class Solution413 {

public:
	// two pointers
	int numberOfArithmeticSlices(vector<int>& A) {
		int ret = 0;
		int front = 1;
		int back = 0;
		while(front<A.size()){
			int diff = A[front]-A[back];
			while(front<A.size() && A[front] - A[front-1] == diff){
				ret = ret + (front-back-1);
				front++;			
			}
			if(front>=A.size()) break;
			else{
				back = front-1;
			}
		}
		return ret;
	}
};

/*int main() {
	int aa[] = {1,2,3};//{1,10,11,13,15,17,20,23,26,29};
	vector<int> v(aa,aa+3);
	Solution413 s;
	cout<<s.numberOfArithmeticSlices(v);
	return 0;
}*/


