#include "StdAfx.h"


class Solution419 {

public:
	int countBattleships(vector<vector<char>>& board) {
		if(board.empty()) return 0;
		int count = 0;
		//int singlePointCount = 0;
        //vertically
		vector<int> ships(board[0].size(),0);
		for(int i=0;i<board.size();i++){
			for(int j=0;j<board[i].size();j++){
				if(board[i][j] == 'X') ships[j]++;
				else if(board[i][j] == '.') ships[j]=0;
				if(ships[j] == 2) count++;
			}
		}
		//horizontally
		vector<int> ships2(board.size(),0);
		for(int i=0;i<board[0].size();i++){
			for(int j=0;j<board.size();j++){
				if(board[j][i] == 'X') ships2[j]++;
				else if(board[j][i] == '.') ships2[j]=0;
				if(ships2[j] == 2) count++;
			}
		}
		//single point
		int dx[4] = {-1,0,1,0};
		int dy[4] = {0,-1,0,1};
		for(int i=0;i<board.size();i++){
			for(int j=0;j<board[i].size();j++){
				if(board[i][j] == 'X'){
					bool isSinglePoint = true;
					for(int k=0;k<4;k++){
						if( i+dx[k] >= 0 && i+dx[k]<board.size() && j+dy[k] >=0 && j+dy[k] <board[0].size()){
							if( board[i+dx[k]][j+dy[k]] == 'X') {
								isSinglePoint = false;
								break;
							}
						}
					}
					if(isSinglePoint) count++;
				}
			}
		}
		return count;
    }
};

int main(){
	Solution419 s;
	char a1[] = {'X','.','.','X'};
	char a2[] = {'.','.','.','X'};
	char a3[] = {'X','X','.','X'};
	vector<char> v1(a1,a1+4);
	vector<char> v2(a2,a2+4);
	vector<char> v3(a3,a3+4);
	vector<vector<char>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	cout<<s.countBattleships(v);
	return 0;
}