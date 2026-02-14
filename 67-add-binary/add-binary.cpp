class Solution {
public:
   string add(string a,string b)
   {
    int index1=a.size()-1;
    int index2=b.size()-1;
    int carry=0;
    string ans;
    while(index2>=0)
    {
        int sum=(a[index1]-'0')+(b[index2]-'0')+carry;
        int nums=sum%2;
        carry=sum/2;
        ans+=(nums+'0');
        index1--;
        index2--;
    }
    while(index1>=0)
    {
        int sum=(a[index1]-'0')+carry;
        int nums=sum%2;
        carry=sum/2;
        ans+=(nums+'0');
        index1--;
    }
    if(carry)
    {
        ans+='1';
    }
    reverse(ans.begin(),ans.end());
    return ans;
   }
    string addBinary(string a, string b) {
        
        int m=a.size();
        int n=b.size();
        string s;
        if(m>=n)
        {
            s=add(a,b);
        }
        else
        {
            s=add(b,a);
        }
        return s;
    }
};