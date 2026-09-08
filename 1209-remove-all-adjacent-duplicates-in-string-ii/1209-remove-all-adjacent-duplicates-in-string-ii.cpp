class Solution {
public:
    string removeDuplicates(string s, int k) {
       int i,j;
       i=j=0;
       vector<int> freq(s.length(),1);
       while(j<s.length()){
        s[i] = s[j];
        freq[i] = 1;
        if(i>0 && s[i]==s[i-1]){
            freq[i]=freq[i-1]+1;
            if(freq[i]==k){
                i-=k;
            }
        }
        i+=1;j+=1;
       }
       return s.substr(0,i);
    }
};