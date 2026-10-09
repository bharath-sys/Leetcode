class Solution {
public:
    bool checkValidString(string s) {
        int l,h;
        l = h = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                h++;l++;
            }
            else if(s[i]==')'){
                h--;l--;
            }
            else {
                h++;
                l--; 
            }
            if(h<0)return false;
            if(l<0)l=0;
        }
        return l==0;
    }
};