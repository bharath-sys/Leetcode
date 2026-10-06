class Solution {
public:
    int minAddToMakeValid(string s) {
        int openLeft = 0;
        int closedLeft = 0;
        for(char ch:s){
            if(ch=='(')openLeft++;
            else{
                if(openLeft)openLeft--;
                else closedLeft++;
            }
        }
        return openLeft+closedLeft;
    }
};