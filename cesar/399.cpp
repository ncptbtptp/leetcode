#include "StdAfx.h"

//DFS 有向图
class Solution399 {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        //预处理
		unordered_map<string,unordered_map<string,double>> eq;
		for(int i=0;i<equations.size();i++){
			string a = equations[i].first;
			string b = equations[i].second;
			double v = values[i];
			eq[a][b] = v;
			eq[b][a] = 1/v;
		}
		unordered_map<string,unordered_map<string,double>>::iterator it = eq.begin();
		while( it != eq.end()){
			string a = it->first;
			eq[a][a] = 1.0;
			it++;
		}
		vector<double> ret;
		unordered_set<string> used;
		for(int i=0;i<queries.size();i++){			
			used.insert(queries[i].first);
			double r = calculate(queries[i].first, queries[i].second, eq, used);
			ret.push_back(r);
			used.clear();
		}
		return ret;
    }

private:
	double calculate(string a, string b, unordered_map<string,unordered_map<string,double>>& eq, unordered_set<string>& used){
		unordered_map<string,unordered_map<string,double>>::iterator it = eq.find(a);
		if( it == eq.end()){
			return -1.0;
		}else{
			unordered_map<string,double>::iterator it2 = it->second.find(b);
			if( it2 != it->second.end()){
				return it2->second;
			} else{
				it2 = it->second.begin();
				while( it2 != it->second.end()){
					string c = it2->first;
					if( used.find(c) != used.end()) {
						it2++;
						continue;
					}
					used.insert(c);
					double d = calculate(c, b, eq, used);
					if( d >= 0){
						return it2->second * d;
						break;
					}
					it2++;
				}
				return -1.0;
			}
		}
	}
};

/*int main(){
	Solution399 s;

	pair<string,string> e[] = {make_pair<string,string>("a","e"), make_pair<string,string>("b","e")};
	double v[] = {4.0,3.0};
	pair<string,string> q[] = {make_pair<string,string>("a","b"), make_pair<string,string>("e","e"),
		make_pair<string,string>("x","x")};//, make_pair<string,string>("a","a"), make_pair<string,string>("x","x")};

	vector<pair<string,string>> v1(e,e+2);
	vector<double> v2(v,v+2);
	vector<pair<string,string>> v3(q,q+3);
	vector<double> r = s.calcEquation(v1,v2,v3);
	return 0;
}*/