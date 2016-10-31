#include "StdAfx.h"
#include "Utilities.h"

class Solution332 {

public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
		vector<string> ret;
        //预处理
		unordered_map<string,list<string>> tcktMap;
		for(int i=0;i<tickets.size();i++){
			tcktMap[tickets[i].first].push_back(tickets[i].second);
		}
		// sort
		unordered_map<string,list<string>>::iterator it = tcktMap.begin();
		while(it!=tcktMap.end()){
			it->second.sort();
			it++;
		}
		return findItinerary(tcktMap,"JFK");
    }

private:
	vector<string> findItinerary(unordered_map<string,list<string>>& tcktMap, string from) {	
		vector<string> ret;
		if(tcktMap.empty()){
			// if ticket map is empty, it means that we are at the end of the recursive loop. The destination is arrived.
			ret.push_back(from);
			return ret;
		}
		unordered_map<string,list<string>>::iterator it = tcktMap.find(from);
		if( it == tcktMap.end()){
			// if ticket map is not empty but it does not have any ticket that starts from the 'from', it means we
			// goes in wrong way. Trace back!
			return ret;
		}
		
		list<string> dest = it->second;
		if(dest.empty()) {
			return ret;
		}
		vector<string> remains;
		bool found = false;
		list<string>::iterator it2 = dest.begin();
		string sDest;
		while( it2 != dest.end()){
			// pick out the destination in lexical order
			sDest = *it2;
			// remove this selection from the ticket map
			it2 = dest.erase(it2);
			if(!dest.empty()) tcktMap[from] = dest;
			else tcktMap.erase(it);
			// recursively call itself to get the subsequent selections
			remains = findItinerary(tcktMap, sDest);
			if(!remains.empty()){
				// we've find the best solution, quit now!
				found = true;
				break;
			}
			// add the used deleted ticket back
			dest.insert(it2, sDest);
			tcktMap[from] = dest;
		}

		if( found) {
			ret.push_back(from);
			ret.insert(ret.end(), remains.begin(), remains.end());
		}
			
		return ret;
	}

};

/*int main(){
	pair<string,string> a[] = {make_pair("JFK","SFO"),make_pair("JFK","ATL"),
		make_pair("SFO","ATL"),make_pair("ATL","JFK"),make_pair("ATL","SFO")};

	pair<string,string> b[] = {make_pair("MUC", "LHR"), make_pair("JFK", "MUC"), make_pair("SFO", "SJC"), make_pair("LHR", "SFO")};
	pair<string,string> c[] = {make_pair("EZE","AXA"),
		make_pair("TIA","ANU"),make_pair("ANU","JFK"),
		make_pair("JFK","ANU"),make_pair("ANU","EZE"),
		make_pair("TIA","ANU"),make_pair("AXA","TIA"),
		make_pair("TIA","JFK"),make_pair("ANU","TIA"),make_pair("JFK","TIA")};
	//[["EZE","AXA"],["TIA","ANU"],["ANU","JFK"],["JFK","ANU"],["ANU","EZE"],["TIA","ANU"],["AXA","TIA"],["TIA","JFK"],["ANU","TIA"],["JFK","TIA"]]
	
	pair<string,string> d[] = {make_pair("JFK","KUL"),
		make_pair("JFK","NRT"),make_pair("NRT","JFK")};
	Solution332 s;
	vector<pair<string,string>> v(a,a+5);
	vector<string> tt = s.findItinerary(v);

	return 0;
}*/