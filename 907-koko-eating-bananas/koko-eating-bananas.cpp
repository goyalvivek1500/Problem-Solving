class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int start=1,end=0,ans=0;
        for(int i=0;i<piles.size();i++)
        {
            end=max(end,piles[i]);
        }
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            long long count=0;
            for(int i=0;i<piles.size();i++)
            {

                count+=piles[i]/mid;
                if(piles[i]%mid)
                {
                    count++;
                }
            }
            if(count<=h)
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;

    }
};