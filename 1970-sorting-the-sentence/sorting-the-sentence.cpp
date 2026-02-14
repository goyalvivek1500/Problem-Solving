class Solution {
public:
    string sortSentence(string s) {
        
        vector<string>ans(10);
        int start=0,count=0;
        string temp="";
        while(start<s.size())
        {
            if(s[start]==' ')
            {
                int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos]=temp;
                temp.clear();
                count++;
            }
            else
            {
                temp+=s[start];
            }
            start++;
        }
        int pos=temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos]=temp;
                temp.clear();
                count++;
        string g;
        for(int i=1;i<=count;i++)
        {
           g+=ans[i];
           g+=" ";
        }
        g.pop_back();
        return g;
    }
};