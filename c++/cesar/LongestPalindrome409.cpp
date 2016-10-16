#include "StdAfx.h"
#include "LongestPalindrome409.h"
#include <unordered_map>

LongestPalindrome409::LongestPalindrome409(void)
{
}


LongestPalindrome409::~LongestPalindrome409(void)
{
}

void LongestPalindrome409::runTest(){
	cout<<longestPalindrome("aaabbcccdddd");
}

int LongestPalindrome409::longestPalindrome(string s) {
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
