class Solution {
public:
    string getHint(string secret, string guess) {
        string ans = "";
        unordered_map<char, int> mp;
        for (auto x : guess)
            mp[x] += 1;
        int bulls = 0;
        for (int i = 0; i < guess.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls += 1;
                mp[guess[i]] -= 1;
            }
        }
        ans+=(to_string(bulls));
        ans.push_back('A');
        int cows = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] != guess[i] && mp[secret[i]] >= 1) {
                mp[secret[i]] -= 1;
                cows += 1;
            }
        }
        ans+=(to_string(cows));
        ans.push_back('B');
        return ans;
    }
};