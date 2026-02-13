class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int start=0,end=0;
        for(int i=0;i<weights.size();i++)
        {
            start=max(start,weights[i]);
            end+=weights[i];
        }
        int ans=0;
        while(start<=end)
        {
            int mid=(start+end)/2;
            int count=1,weight=0;
            for(int i=0;i<weights.size();i++)
            {
                weight+=weights[i];
                if(weight>mid)
                {
                    weight=weights[i];
                    count++;
                }
            }
            if(count<=days)
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