class Solution {
public:
    string sortVowels(string s) {
        
        int size=s.size();
        vector<int>upper(26,0);
        vector<int>lower(26,0);

        //select the vowel
        string ans="";
        for(int i=0;i<size;i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u')
            {
                lower[s[i]-'a']++;
                s[i]='&';
            }
            else if(s[i]=='A'||s[i]=='E'||s[i]=='O'||s[i]=='U'||s[i]=='I')
            {
                upper[s[i]-'A']++;
                s[i]='&';
            }
        }

        //sort the vowel;
        for(int i=0;i<26;i++)
        {
            char ch='A'+i;
            while(upper[i])
            {
                ans.push_back(ch);
                upper[i]--;
            }
        }

        for(int i=0;i<26;i++)
        {
            char ch='a'+i;
            while(lower[i])
            {
                ans.push_back(ch);
                lower[i]--;
            }
        }

        //insert the vowel
        int start=0;
        for(int i=0;i<size;i++)
        {
            if(s[i]=='&')
            {
                s[i]=ans[start];
                start++;
            }
        }
        return s;
    }
};