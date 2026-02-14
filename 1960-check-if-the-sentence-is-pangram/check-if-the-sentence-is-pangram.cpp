class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        int size=sentence.size();
        vector<int>ans(26,0);
        for(int i=0;i<size;i++)
        {
            ans[sentence[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(ans[i]==0)
            {
                return 0;
            }
        }
        return 1;
    }
};