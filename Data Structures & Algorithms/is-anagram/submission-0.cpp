#include <map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> dict;
        for (char c : s) {
            dict[c]++;
        }
        for (char c : t) {
            dict[c]--;
        }

        for (const auto p : dict) {
            if (p.second != 0) {
                return false;
            } 
        }
        return true;
    }
};
