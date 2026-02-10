class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> need(26, 0);

        // count required letters from licensePlate
        for(char ch : licensePlate) {
            if(isalpha(ch)) {
                ch = tolower(ch);
                need[ch - 'a']++;
            }
        }

        string ans = "";

        for(string w : words) {
            vector<int> cnt(26, 0);

            for(char ch : w) {
                cnt[ch - 'a']++;
            }

            bool ok = true;
            for(int i = 0; i < 26; i++) {
                if(cnt[i] < need[i]) {
                    ok = false;
                    break;
                }
            }

            if(ok) {
                if(ans == "" || w.size() < ans.size()) {
                    ans = w;
                }
            }
        }

        return ans;
    }
};
