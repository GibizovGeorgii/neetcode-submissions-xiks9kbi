#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        std::map<string, vector<string>> hashMap;

        for (string& str : strs) {
            string storage = str;

            std::sort(storage.begin(), storage.end());

            hashMap[storage].push_back(str);
        }

        for (auto& [name, group] : hashMap) {
            result.push_back(group);
        }

        return result;
    }
};
