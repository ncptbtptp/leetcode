#include "StdAfx.h"
#include <unordered_set>

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
		if(existValues.find(val) == existValues.end()) {
			existValues.insert(val);
			allValues.push_back(val);
			return true;
		} else{
			return false;
		}
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(existValues.find(val) == existValues.end()) {
			return false;
		} else {
			existValues.erase(val);
			return true;
		}
    }
    
    /** Get a random element from the set. */
    int getRandom() {
		int len = allValues.size();
		int val;
		do{
			int r = rand() % len;
			val = allValues[r];
		} while(existValues.find(val) == existValues.end());
		return val;
    }

private:
	unordered_set<int> existValues;
	vector<int> allValues;
};

int main(){
	RandomizedSet s;
	cout<<s.insert(1)<<endl;
	cout<<s.insert(2)<<endl;
	cout<<s.insert(3)<<endl;
	cout<<s.insert(4)<<endl;
	cout<<s.insert(1)<<endl;

	cout<<s.remove(2)<<endl;
	cout<<s.remove(2)<<endl;
	cout<<s.getRandom()<<endl;
	cout<<s.getRandom()<<endl;
	cout<<s.getRandom()<<endl;
	cout<<s.getRandom()<<endl;
	cout<<s.getRandom()<<endl;
	cout<<s.getRandom()<<endl;
	return 0;
}