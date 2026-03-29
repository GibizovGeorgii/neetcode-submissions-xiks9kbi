class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sh_size = strs[0].size();
        int sh_ind = 0;
        int strs_size = strs.size();

        for (int i = 1; i < strs_size; ++i) {
            if (strs[i].size() < sh_size) {
                sh_size = strs[i].size();
                sh_ind = i;
            }
        }

        std::string result = strs[sh_ind];
        if (sh_size == 0) {
            return "";
        }


        for (int i = 0; i < strs_size; ++i) {
            int cur_ind = 0;
            int cur_size = strs[i].size();
            while (strs[i][cur_ind] == result[cur_ind] and cur_ind < sh_size and cur_ind < cur_size) {
                cur_ind++;
            }
            if (cur_ind == 0) {
                return "";
            }
            if (cur_ind < sh_size) {
                sh_size = cur_ind;
            }
        }

        result.resize(sh_size);
        return result;
    }
};