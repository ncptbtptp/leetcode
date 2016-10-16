#include "StdAfx.h"
#include "ArithmeticSlices413.h"


ArithmeticSlices413::ArithmeticSlices413(void)
{
}


ArithmeticSlices413::~ArithmeticSlices413(void)
{
}

void ArithmeticSlices413::runTest() {
	int aa[] = {1,2,3};//{1,10,11,13,15,17,20,23,26,29};
	vector<int> v(aa,aa+3);
	cout<<numberOfArithmeticSlices(v);
}

// two pointers
int ArithmeticSlices413::numberOfArithmeticSlices(vector<int>& A) {
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
