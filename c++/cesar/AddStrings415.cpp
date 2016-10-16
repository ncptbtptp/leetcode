#include "StdAfx.h"
#include "AddStrings415.h"


AddStrings415::AddStrings415(void)
{
}


AddStrings415::~AddStrings415(void)
{
}

void AddStrings415::runTest()
{
	cout<<addStrings("1","99")<<endl;
	cout<<addStrings("309","29878")<<endl;
}

string AddStrings415::addStrings(string num1, string num2) {
	string ret;
	int i = num1.length()-1;
	int j = num2.length()-1;
	int u = 0;
	while(i>=0 && j>=0){
		int a = num1[i] - '0';
		int b = num2[j] - '0';
		int sum = a+b+u;
		if(sum>=10){
			sum-=10;
			u=1;
		}else{
			u = 0;
		}
		char s = '0' + sum;
		ret.insert(ret.begin(),s);
		i--;
		j--;
	}
	//处理剩下的较长的字符串
	if( i<0 && j>=0){
		while(j>=0){
			int a = num2[j]-'0';
			int sum = a+u;
			if(sum>=10){
				sum-=10;
				u=1;
			}else{
				u = 0;
			}
			char s = '0' + sum;
			ret.insert(ret.begin(),s);
			j--;
		}
	}else if(j<0 && i>=0){
		while(i>=0){
			int a = num1[i]-'0';
			int sum = a+u;
			if(sum>=10){
				sum-=10;
				u=1;
			}else{
				u = 0;
			}
			char s = '0' + sum;
			ret.insert(ret.begin(),s);
			i--;
		}
	}
	if(u==1){
		ret.insert(ret.begin(),'1');
	}
	return ret;
}
