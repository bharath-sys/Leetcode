class Solution {
public:
    string removeDuplicates(string s) {
        int start = 0;
        for(int j=0;j<s.length();++start,++j){
            s[start] = s[j];
            if(start>0 && s[start]==s[start-1]){
                start-=2;
            }
        }
        return s.substr(0,start);
    }
};