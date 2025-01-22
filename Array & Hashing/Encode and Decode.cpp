class Solution {
public:

    string encode(vector<string>& strs) {
        string monster = "";
        string DELIMETER = "#";
        for(auto& str: strs) {
            monster += to_string(str.length()) + DELIMETER + str;
        }
        return monster;
    }

    vector<string> decode(string s) {
        int len = 0, i = 0;
        string DELIMETER = "#";
        bool in_len = true;
        string cur_str = "";
        vector<string> ans;
        while(i < s.length()){
            if(in_len) {
                if(s[i] == DELIMETER[0]) {
                    in_len = 0;
                    if(len == 0) {
                        ans.push_back("");
                        in_len = 1;
                    }
                }
                else{
                    len *= 10;
                    len += s[i] - '0';
                }
            }
            else {
                cur_str += s[i];
                len -= 1;
                if(len == 0) {
                    in_len = 1;
                    ans.push_back(cur_str);
                    cur_str = "";
                }
            }
            i++;
        }
        return ans;
    }
};
