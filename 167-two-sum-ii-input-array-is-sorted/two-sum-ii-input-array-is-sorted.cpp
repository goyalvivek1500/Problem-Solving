class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size=numbers.size();
        vector<int>ans(2,0);
        int start=0,end=size-1;
        while(start<=end)
        {
            if(numbers[start]+numbers[end]==target)
            {
                ans[0]=start+1;
                ans[1]=end+1;
                return ans;
            }
            else if(numbers[start]+numbers[end]<target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return ans;
    }
};