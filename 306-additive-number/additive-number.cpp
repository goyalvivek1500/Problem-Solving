class Solution {
public:
    string addStrings(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string ans = "";

        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';

            ans.push_back(char(sum % 10 + '0'));
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool check(string num, int i, string a, string b) {
        if(i == num.size()) return true;

        string c = addStrings(a, b);

        // num ke i position se c match hona chahiye
        if(num.substr(i, c.size()) != c) return false;

        return check(num, i + c.size(), b, c);
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();

        for(int len1 = 1; len1 <= n - 2; len1++) {
            for(int len2 = 1; len2 <= n - len1 - 1; len2++) {

                string a = num.substr(0, len1);
                string b = num.substr(len1, len2);

                // leading zero not allowed (except "0")
                if(a.size() > 1 && a[0] == '0') continue;
                if(b.size() > 1 && b[0] == '0') continue;

                if(check(num, len1 + len2, a, b)) return true;
            }
        }
        return false;
    }
};
