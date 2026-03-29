class Solution {
public:

    string encode(vector<string>& strs) {
        std::string msg;
        for (string& str : strs) {
            msg.append(std::to_string(str.size()));
            msg.push_back('#');
            msg.append(str);
        }
        return msg;
    }

    vector<string> decode(string s) {
        int pos = 0;
        int n = s.size();

        std::vector<std::string> answer;

        while(pos < n) {
            int length = 0;
            while (s[pos] != '#') {
                length = length * 10 + s[pos] - '0';
                pos++;
            }
            pos++;
            answer.push_back(s.substr(pos, length));
            pos += length;    
        }

        return answer;
    }
};
