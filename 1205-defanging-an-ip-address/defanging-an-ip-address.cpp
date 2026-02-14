class Solution {
public:
    string defangIPaddr(string address) {
        int start=0;
        string ans;
        while(start<address.size())
        {
            if(address[start]=='.')
            {
                ans+="[.]";
            }
            else
            {
                ans+=address[start];
            }
            start++;
        }
        return ans;
    }
};