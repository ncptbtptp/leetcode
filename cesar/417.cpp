#include "stdafx.h" 
#include <queue>

using namespace std; 

//BFS
class Solution417 {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int,int>> ret;
		if(matrix.empty()) return ret;
		vector<int> flags(matrix[0].size(),0);
		vector<vector<int>> mflags(matrix.size(), flags);
		int dx[4] = {1,0,-1,0};
		int dy[4] = {0,1,0,-1};
		//pacific
		queue<pair<int,int>> pacific;
		for(int i=0;i<matrix.size();i++){
			pacific.push(pair<int,int>(i,0));
			mflags[i][0] |= 1;
		}
		for(int i=1;i<matrix[0].size();i++){
			pacific.push(pair<int,int>(0,i));
			mflags[0][i] |= 1;
		}
		while(!pacific.empty()){
			pair<int,int> p = pacific.front();
			for(int i=0;i<4;i++){
				int x = p.first+dx[i];
				int y = p.second+dy[i];
				if( x >=0 && x < matrix.size() && y>=0 && y<matrix[0].size()){
					if((mflags[x][y] & 1)==0 && matrix[x][y] >= matrix[p.first][p.second]){
						pacific.push(pair<int,int>(x,y));
						mflags[x][y] |= 1;
					}
				}				
			}
			pacific.pop();
		}
		//atlantic
		queue<pair<int,int>> atlantic;
		for(int i=0;i<matrix.size();i++){
			atlantic.push(pair<int,int>(i,matrix[0].size()-1));
			mflags[i][matrix[0].size()-1] |= 2;
		}
		for(int i=0;i<matrix[0].size()-1;i++){
			atlantic.push(pair<int,int>(matrix.size()-1,i));
			mflags[matrix.size()-1][i] |= 2;
		}
		while(!atlantic.empty()){
			pair<int,int> p = atlantic.front();
			for(int i=0;i<4;i++){
				int x = p.first+dx[i];
				int y = p.second+dy[i];
				if( x >=0 && x < matrix.size() && y>=0 && y<matrix[0].size()){
					if((mflags[x][y] & 2)==0 && matrix[x][y] >= matrix[p.first][p.second]){
						atlantic.push(pair<int,int>(x,y));
						mflags[x][y] |= 2;
					}
				}				
			}
			atlantic.pop();
		}
		for(int i=0;i<mflags.size();i++){
			for(int j=0;j<mflags[0].size();j++){
				if(mflags[i][j] == 3){
					ret.push_back(pair<int,int>(i,j));
				}
			}
		}
		return ret;
	}
};

int main(){
	int a1[] = {3,3,3};
	int a2[] = {3,1,3};
	int a3[] = {0,2,4};
	int a4[] = {6,7,1,4,5};
	int a5[] = {5,1,1,2,4};
	Solution417 s;
	vector<int> v1(a1,a1+3);
	vector<int> v2(a2,a2+3);
	vector<int> v3(a3,a3+3);
	vector<int> v4(a4,a4+5);
	vector<int> v5(a5,a5+5);
	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	//v.push_back(v4);
	//v.push_back(v5);
	s.pacificAtlantic(v);
	return 0;
}