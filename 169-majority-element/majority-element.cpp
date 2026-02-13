class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int size=nums.size();
        int count=0,majority=0;
        int start=0;
        while(start<size)
        {
            if(count==0)
            {
                majority=nums[start];
                count++;
            }
            else
            {
                if(majority==nums[start])
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
            start++;
        }
        count=0;
        for(int i=0;i<size;i++)
        {
            if(nums[i]==majority)
            {
                count++;
            }
        }
        if(count>size/2)
        {
            return majority;
        }
        else
        {
            return -1;
        }
    }
};