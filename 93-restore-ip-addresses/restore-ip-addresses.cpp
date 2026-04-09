
class Solution {
public:
    vector<string> result;

    bool isValid(string s) {
        if (s.size() > 1 && s[0] == '0') return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    void backtrack(string s, int index, int parts, string current) {
        if (parts == 4 && index == s.size()) {
            result.push_back(current.substr(0, current.size() - 1));
            return;
        }

        if (parts >= 4) return;

        for (int len = 1; len <= 3; len++) {
            if (index + len > s.size()) break;

            string part = s.substr(index, len);

            if (isValid(part)) {
                backtrack(s, index + len, parts + 1, current + part + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return result;
    }
};