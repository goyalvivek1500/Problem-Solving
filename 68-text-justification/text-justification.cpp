class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0, n = words.size();

        while (i < n) {
            int j = i, lineLen = 0;

            // Step 1: fit words in one line
            while (j < n && lineLen + words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                j++;
            }

            int spaces = maxWidth - lineLen;
            int gaps = j - i - 1;

            string line = "";

            // Step 2: last line or single word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                // Step 3: distribute spaces
                int evenSpace = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) {
                        line += string(evenSpace + (extra-- > 0 ? 1 : 0), ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};