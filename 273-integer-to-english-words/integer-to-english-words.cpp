class Solution {
public:
    string ones(int num) {
        vector<string> v = {"", "One", "Two", "Three", "Four", "Five", "Six",
                            "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
                            "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                            "Seventeen", "Eighteen", "Nineteen"};
        return v[num];
    }

    string tens(int num) {
        vector<string> v = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                            "Sixty", "Seventy", "Eighty", "Ninety"};
        return v[num];
    }

    string helper(int num) {
        string res = "";

        if (num >= 100) {
            res += ones(num / 100) + " Hundred";
            num %= 100;
            if (num) res += " ";
        }

        if (num >= 20) {
            res += tens(num / 10);
            num %= 10;
            if (num) res += " ";
        }

        if (num > 0 && num < 20) {
            res += ones(num);
        }

        return res;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string ans = "";

        int billion = num / 1000000000;
        num %= 1000000000;

        int million = num / 1000000;
        num %= 1000000;

        int thousand = num / 1000;
        num %= 1000;

        int rest = num;

        if (billion) ans += helper(billion) + " Billion";
        if (million) {
            if (!ans.empty()) ans += " ";
            ans += helper(million) + " Million";
        }
        if (thousand) {
            if (!ans.empty()) ans += " ";
            ans += helper(thousand) + " Thousand";
        }
        if (rest) {
            if (!ans.empty()) ans += " ";
            ans += helper(rest);
        }

        return ans;
    }
};
