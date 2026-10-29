class Solution {
public:
    string largestEven(string s) {
        int n=s.size();
        while(s.size()>0 && s[s.size()-1]=='1'){
            s.pop_back();
        }
        return s;
    }
};