class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int>lower(26,0);
        vector<int>upper(26,0);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a')
            {
                lower[s[i]-'a']++;
            }
            else
            {
                upper[s[i]-'A']++;
            }
        }
        int len1=0;
        bool b=0;
        for(int i=0;i<26;i++)
        {
            if(upper[i]%2==0)
            {
                len1+=upper[i];
            }
            else
            {
                b=1;
                len1+=upper[i]-1;
            }
            if(lower[i]%2==0)
            {
                len1+=lower[i];
            }
            else
            {
                b=1;
                len1+=lower[i]-1;
            }
        }
        return len1+b;
    }
};