class Solution {
public:
    int trap(vector<int>& height) {
        
        int size=height.size();
        vector<int>prefix(size,0);
        vector<int>suffix(size,0);

        prefix[0]=0;
        for(int i=1;i<size;i++)
        {
            prefix[i]=max(prefix[i-1],height[i-1]);
        }

        suffix[size-1]=0;
        for(int i=size-2;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1],height[i+1]);
        }
        int ans=0;
        for(int i=0;i<size;i++)
        {
           int val= min(prefix[i],suffix[i]);
           if(val-height[i]>=0)
           {
            ans+=val-height[i];
           }
        }
        return ans;
    }
};