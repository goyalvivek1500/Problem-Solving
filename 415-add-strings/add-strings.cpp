class Solution {
public:
    string sum(string num1,string num2)
    {
        int index1=num1.size()-1;
        int index2=num2.size()-1;
        int carry=0;
        string ans;
        while(index2>=0)
        {
            int temp=(num1[index1]-'0')+(num2[index2]-'0')+carry;
            int a=temp%10;
            carry=temp/10;
            ans+=(a+'0');
            index1--;
            index2--;
        }
        while(index1>=0)
        {
            int temp=(num1[index1]-'0')+carry;
            int a=temp%10;
            carry=temp/10;
            ans+=(a+'0');
            index1--;
        }
        if(carry)
        {
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string addStrings(string num1, string num2) {
        
        int index1=num1.size();
        int index2=num2.size();
        string s;
        if(index1>=index2)
        {
            s=sum(num1,num2);
        }
        else
        {
            s=sum(num2,num1);
        }
        return s;
    }
};