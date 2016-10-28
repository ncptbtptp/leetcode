#include "StdAfx.h"
#include <unordered_map>

class Solution409 {
public:
	int longestPalindrome(string s) {
		int len = 0;
		unordered_map<char,int> charToCount;
		for(int i=0;i<s.length();i++){
			charToCount[s[i]]++;
		}
		unordered_map<char,int>::iterator it = charToCount.begin();
		bool hasOddCount = false;
		while(it!=charToCount.end()){
			if(it->second % 2==0){
				len+=it->second;
			}else{
				len+=(it->second-1);
				hasOddCount = true;
			}
			it++;
		}
		if(hasOddCount) len++;
		return len;
	}
};

/*int main(){
	Solution409 s;
	cout<<s.longestPalindrome("aaabbcccdddd");
	return 0;
}*/


