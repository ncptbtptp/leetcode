#include "StdAfx.h"

class Solution400 {
public:
    int findNthDigit(int n) {
	   int radix = 1;
	   int v = 1;
       while( n > 0){
		   int count = 9*v*radix;
		   //溢出判断
		   if( count < 0 || n <= count ){
			   break;			   
		   }
		   n -= count;
		   v*=10;
		   radix++;
	   }
	   int ret = findNthDigit(n, radix); 
	   if(radix==1) ret++;
	   return ret;
    }

private:
	int findNthDigit(int n, int radix){
		//判断n在某个数的从左数第几位上
		int m = n%radix;
		if( m==0) m = radix;
		int c = pow((double)10,radix-m);
		c *= radix;
		n = n/c;
		if( m==radix) n--;
		else if( m==1) n++;
		n = n%10;
		return n;
	}

};

int main(){
	Solution400 s;
	cout<<s.findNthDigit(1000000000)<<endl;
	cout<<s.findNthDigit(9)<<endl;
	cout<<s.findNthDigit(10)<<endl;
	cout<<s.findNthDigit(11)<<endl;
	cout<<s.findNthDigit(12)<<endl;
	cout<<s.findNthDigit(13)<<endl;
	cout<<s.findNthDigit(14)<<endl;
	cout<<s.findNthDigit(15)<<endl;
	cout<<s.findNthDigit(16)<<endl;
	cout<<s.findNthDigit(17)<<endl;

	cout<<s.findNthDigit(189)<<endl;
	cout<<s.findNthDigit(190)<<endl;
	cout<<s.findNthDigit(191)<<endl;
	cout<<s.findNthDigit(192)<<endl;
	cout<<s.findNthDigit(193)<<endl;
	cout<<s.findNthDigit(194)<<endl;
	cout<<s.findNthDigit(195)<<endl;
	cout<<s.findNthDigit(196)<<endl;
	cout<<s.findNthDigit(197)<<endl;
	cout<<s.findNthDigit(198)<<endl;
	cout<<s.findNthDigit(199)<<endl;
	cout<<s.findNthDigit(200)<<endl;
	return 0;
}