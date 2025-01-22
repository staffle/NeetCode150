// https://neetcode.io/problems/is-palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(auto& ch: s) {
            if(ch >= 'A' && ch <= 'Z')
                ch = tolower(ch);
            if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
                t += ch;
            }
        }
        s = t;
        for(int i = 0, j = s.length() - 1; i < j; i++, j--)
            if(s[i] != s[j])
                return false;
        return true;
    }
};
