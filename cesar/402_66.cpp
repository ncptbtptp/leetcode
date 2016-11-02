#include "StdAfx.h"

class Solution402 {
public:
    string removeKdigits(string num, int k) {
		string ret = "";
        stack<int> numbers;
		int i=0;
		for(;i<num.length();i++){
			int value = num[i] - '0';
			if(numbers.empty()){
				numbers.push(value);
			}else{
				//compare with the top of the stack
				if( value >= numbers.top()){
					numbers.push(value);
				}else{
					int topValue = numbers.top();
					while( !numbers.empty() && value < topValue){
						topValue = numbers.top();
						if( value >= topValue) break;						
						numbers.pop();
						k--;	
						if( k==0) break;
					}
					if( k==0) break;
					numbers.push(value);					
				}
			}
		}
		if( k >0){
			while(k>0){
				numbers.pop();
				k--;
			}
		}
		while(!numbers.empty()){
			char c = '0' + numbers.top();
			ret.insert(ret.begin(), c);
			numbers.pop();
		}
		ret += num.substr(i, num.length()-i);
		// remove leading zeros
		i = 0;
		for(;i<ret.length();i++){
			if(ret[i] != '0') break;
		}
		ret = ret.substr(i, ret.length()-i);
		if( ret.empty()) return "0";
		return ret;
    }
};

int main(){
	Solution402 s;
	cout<<s.removeKdigits("10200",1)<<endl;
	cout<<s.removeKdigits("1432219",2)<<endl;
	cout<<s.removeKdigits("1432219",3)<<endl;
	cout<<s.removeKdigits("1432219",4)<<endl;
	cout<<s.removeKdigits("1432219",5)<<endl;
	cout<<s.removeKdigits("1432219",6)<<endl;
	cout<<s.removeKdigits("1432219",7)<<endl;
	return 0;
}