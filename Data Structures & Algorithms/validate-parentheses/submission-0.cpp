class Solution {
public:
    bool isValid(string s) {
        std::stack<char> braces;
        std::unordered_map<char, char> close_brace;
        close_brace['('] = ')';
        close_brace['['] = ']';
        close_brace['{'] = '}';

        for (char& brace : s) {
            if (close_brace.contains(brace)) {
                braces.push(brace);
            } else {
                if (braces.empty()) {
                    return false;
                } else {
                    if (brace == close_brace[braces.top()]) {
                        braces.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        if (braces.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
