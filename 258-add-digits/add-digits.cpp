class Solution {
public:
    int addDigits(int nums) {
        int rem;
        while(nums>9)
        {
            int ans=0;
            while(nums)
            {
                rem=nums%10;
                nums/=10;
                ans+=rem;
            }
            nums=ans;
        }
        return nums;
    }
};