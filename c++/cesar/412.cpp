#include "StdAfx.h"


class Solution412 {
private:
	string plus(string old, int num){
		string p = "";
		int u = 0;
		for(int i=old.length()-1;i>=0;i--){
			int c = old[i] - '0';
			c = c + u;
			if( i==old.length()-1) c += num;	
			if( c >=10){
				c -=10;
				u = 1;
			}else u = 0;
			char c1 = c + '0';
			p.insert(p.begin(),c1); 
		}
		if( u >0) p.insert(p.begin(),'1');
		return p;
	}
public:
	vector<string> fizzBuzz(int n) {
        vector<string> ret;
		int diff = 0;
		for(int i=1;i<=n;i++){
			if( i % 15==0) {
				ret.push_back("FizzBuzz");
				diff++;
			}
			else if( i % 3 ==0) {
				ret.push_back("Fizz");
				diff++;
			}
			else if( i % 5 ==0) {
				ret.push_back("Buzz");
				diff++;
			}else{
				if( i==1) {
					ret.push_back("1");
				}else{
					string r = plus(ret[ret.size()-diff], diff);
					ret.push_back(r);
				}
				diff = 1;
			}
		}

		return ret;
    }
};

int main(){
	Solution412 s;
	vector<string> r = s.fizzBuzz(15);
	return 0;
}