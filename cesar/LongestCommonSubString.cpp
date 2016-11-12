#include "StdAfx.h"


class LongestCommonSubString {
public:
	int LCS(string s1, string s2){
		if(s1.empty() || s2.empty()) return 0;
		//first: LCS
		//second: LCS at tail
		vector<vector<pair<int,int>>> dp;
		for(int i=0;i<s1.length();i++){
			vector<pair<int,int>> v(s2.length(),pair<int,int>(0,0));
			dp.push_back(v);
		}
		for(int i=0;i<s1.length();i++){
			for(int j=0;j<s2.length();j++){
				if(i==0 && j==0){
					if(s1[i] == s2[j]){
						dp[i][j] = pair<int,int>(1,1);
					}else{
						dp[i][j] = pair<int,int>(0,0);
					}
				}else if(j==0){
					pair<int,int> last = dp[i-1][j];
					if(s1[i] == s2[j]){
						dp[i][j] = pair<int,int>(1,1);
					}else{
						dp[i][j] = pair<int,int>(last.first,0);
					}
				}else if(i==0){
					pair<int,int> last = dp[i][j-1];
					if(s1[i] == s2[j]){
						dp[i][j] = pair<int,int>(1,1);
					}else{
						dp[i][j] = pair<int,int>(last.first,0);
					}
				}else{
					int mx = max(dp[i-1][j].first, dp[i][j-1].first);
					if(s1[i]==s2[j]){
						pair<int,int> last2 = dp[i-1][j-1];
						pair<int,int> cur;
						cur.second = last2.second + 1;
						mx = max(mx, cur.second);
						cur.first = mx;
						dp[i][j] = cur;
					}else{
						dp[i][j] = pair<int,int>(mx,0);
					}
				}
			}
		}
		return dp[s1.length()-1][s2.length()-1].first;
	}

};

int main(){
	LongestCommonSubString l;
	cout<<l.LCS("a","b")<<endl;
	cout<<l.LCS("a","a")<<endl;
	cout<<l.LCS("xyz98765abcd00000","abcd1234xyzfffff")<<endl;
	cout<<l.LCS("abchijk","hijkabc")<<endl;
	cout<<l.LCS("hijkabc","abchijk")<<endl;
	return 0;

}