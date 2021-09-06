#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
   vector<string> findItinerary(vector<pair<string, string>> tickets)
   {
      buildGraph(tickets);

      vector<string> res;
      res.push_back("JFK");
      for (auto &i : m_start["JFK"]) {
         clear();
         if (DFS(i, tickets.size(), res))
            break;
      }

      return res;
   }
private:
   void clear()
   {
      for (auto &i : m_start) {
         for (auto &j : i.second) {
            j.first = false;
         }
      }
   }

   bool DFS(pair<bool, string>& start, int nTickets, vector<string>& res)
   {
      start.first = true;

      res.push_back(start.second);

      nTickets -= 1;
      if (nTickets == 0) {
         return true;
      }

      for (auto &i : m_start[start.second]) {
         if (!i.first && DFS(i, nTickets, res)) {
            return true;
         }
      }
      res.pop_back();

      start.first = false;
      return false;
   }

   void buildGraph(const vector<pair<string, string>> &tickets)
   {
      for (const auto & ti : tickets) {
         auto & v = m_start[ti.first];
         auto i = v.begin();
         while (i != v.end() && ti.second > i->second)
            ++i;
         v.insert(i, make_pair(false, ti.second));
      }
   }

   unordered_map<string, list<pair<bool, string>>> m_start;
};


//int main()
//{
//   Solution so;
//   vector<pair<string, string>> tickets;
//   pair<string, string> s1("EZE", "TIA");
//   pair<string, string> s2("EZE", "HBA");
//   pair<string, string> s3("AXA", "TIA");
//   pair<string, string> s4("JFK", "AXA");
//   pair<string, string> s5("ANU", "JFK");
//   pair<string, string> s6("ADL", "ANU");
//   pair<string, string> s7("TIA", "AUA");
//   pair<string, string> s8("ANU", "AUA");
//   pair<string, string> s9("ADL", "EZE");
//   pair<string, string> s10("ADL", "EZE");
//   pair<string, string> s11("EZE", "ADL");
//   pair<string, string> s12("AXA", "EZE");
//   pair<string, string> s13("AUA", "AXA");
//   pair<string, string> s14("JFK", "AXA");
//   pair<string, string> s15("AXA", "AUA");
//   pair<string, string> s16("AUA", "ADL");
//   pair<string, string> s17("ANU", "EZE");
//   pair<string, string> s18("TIA", "ADL");
//   pair<string, string> s19("EZE", "ANU");
//   pair<string, string> s20("AUA", "ANU");
//   tickets.push_back(s1);
//   tickets.push_back(s2);
//   tickets.push_back(s3);
//   tickets.push_back(s4);
//   tickets.push_back(s5);
//   tickets.push_back(s6);
//   tickets.push_back(s7);
//   tickets.push_back(s8);
//   tickets.push_back(s9);
//   tickets.push_back(s10);
//   tickets.push_back(s11);
//   tickets.push_back(s12);
//   tickets.push_back(s13);
//   tickets.push_back(s14);
//   tickets.push_back(s15);
//   tickets.push_back(s16);
//   tickets.push_back(s17);
//   tickets.push_back(s18);
//   tickets.push_back(s19);
//   tickets.push_back(s20);
//   vector<string> res = so.findItinerary(tickets);
//   for (int i = 0; i < res.size(); ++i)
//      cout << res[i] << " ";
//   cout << endl;
//
//   return 0;
//}
