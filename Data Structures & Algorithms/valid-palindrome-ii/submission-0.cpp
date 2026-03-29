class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0; 
        int r = s.size() - 1;
        int r_reserve = -1;
        int l_reserve = -1;

        while (l < r) {
            if (s[l] != s[r]) {
                if (r_reserve == -1) {
                    r_reserve = r;
                    l_reserve = l + 1;
                    l--;
                } else if (l_reserve == -2) {
                    return false;
                } else {
                    r = r_reserve;
                    l = l_reserve;
                    l--;
                    r++;
                    l_reserve = -2;
                }
            }
            l++;
            r--;
        }
        return true;
    }
};