class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0)
        {
            return false;
        }
        int y=x,ans=0,rem=0;
        while(x>0)
        {
            rem=x%10;
            x/=10;
            if(ans>INT_MAX/10)
            {
                return false;
            }
            ans=ans*10+rem;
        }
        if(ans==y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};