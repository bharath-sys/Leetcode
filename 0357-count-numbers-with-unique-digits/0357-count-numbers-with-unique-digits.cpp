class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> memo = {1,9,9,8,7,6,5,4,3,2,1};
        int ans = 0;int mul = 1;
        for (int i = 0; i <= n; i++) {
            ans += (mul*memo[i]);
            mul*=memo[i];
        }
        return ans;
    }
};