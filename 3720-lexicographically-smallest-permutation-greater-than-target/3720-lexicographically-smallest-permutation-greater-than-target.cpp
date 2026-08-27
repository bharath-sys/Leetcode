class Solution {
public:
    vector<int> alphaMap;
    string ans;
    bool backTrack(int idx, string& temp, string s, string target,
                   bool greater) {
        // base condition
        if (idx >= s.length()) {
            if (greater) {
                ans = temp;
                return true;
            }
            return false;
        }
        for (int i = 0; i < 26; i++) {
            if (alphaMap[i] > 0 && ('a' + i >= target[idx] || greater)) {
                temp.push_back(i + 'a');
                alphaMap[i] -= 1;
                if (backTrack(idx + 1, temp, s, target,
                              'a' + i > target[idx] || greater)) {
                    return true;
                };
                temp.pop_back();
                alphaMap[i] += 1;
            }
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        alphaMap.resize(26, 0);
        for (char c : s) {
            alphaMap[c - 'a'] += 1;
        }
        string temp = "";
        backTrack(0, temp, s, target, false);
        return ans;
    }
};