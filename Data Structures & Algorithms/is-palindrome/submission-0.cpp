class Solution {
public:
    char trueChar(char a) {
        if ('a' <= a and a <= 'z') {
            return a;
        }
        if ('A' <= a and a <= 'Z') {
            return a - 'A' + 'a';
        }
        if ('0' <= a and a <= '9') {
            return a;
        }
        return -1;
    }

    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            while (trueChar(s[l]) == -1 and l < r) {
                l++;
            }
            while (trueChar(s[r]) == -1 and l < r) {
                r--;
            }
            if (l >= r) {
                return true;
            }
            if (trueChar(s[r]) != trueChar(s[l])) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};
