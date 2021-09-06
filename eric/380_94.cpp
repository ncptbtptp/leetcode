/**********************************************************************************
 * https://leetcode.com/problems/insert-delete-getrandom-o1/
 *
 * Auther: ncptbtptp
 *
 * Tip:
 *
 * Time: O(?)
 * Space: O(?)
 **********************************************************************************/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <ctime>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet()
    {
        srand(time(NULL));
    }

    bool insert(int val)
    {
        if (m_data.find(val) == m_data.end()) {
            m_data[val] = m_ref.size();
            m_ref.push_back(val);
            return true;
        }
        else {
            return false;
        }
    }

    bool remove(int val)
    {
        auto it = m_data.find(val);
        if (it != m_data.end()) {
            std::swap(m_ref[it->second], m_ref.back());
            m_data[m_ref[it->second]] = it->second;
            m_ref.pop_back();
            m_data.erase(it);
            return true;
        }
        else {
            return false;
        }
    }

    int getRandom()
    {
        return m_ref[rand() % m_ref.size()];
    }

private:
    // i -> value
    vector<int> m_ref;
    // value -> index of ref array
    unordered_map<int, int> m_data;
};

//int main()
//{
//    RandomizedSet randomSet;
//
//    randomSet.insert(1);
//    randomSet.insert(10);
//    randomSet.insert(20);
//    randomSet.insert(30);
//
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//    cout << randomSet.getRandom() << endl;
//
//    return 0;
//}
