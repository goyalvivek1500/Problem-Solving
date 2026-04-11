class Solution {
public:
    int minimumDistance(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, std::vector<int>> g;
        
        // Group indices of the same number
        for (int i = 0; i < n; ++i) {
            g[nums[i]].push_back(i);
        }
        
        const int inf = 1e9 + 7;
        int ans = inf;
        
        // Iterate through groups of equal elements
        for (auto& [val, ls] : g) {
            if (ls.size() < 3) continue;
            
            // Check consecutive indices within the group to minimize distance
            for (int h = 0; h < (int)ls.size() - 2; ++h) {
                int i = ls[h];
                int k = ls[h + 2]; // 3rd index (i, j, k)
                
                // Formula: (j-i) + (k-j) + (k-i) = 2*(k-i)
                int dist = 2 * (k - i);
                ans = std::min(ans, dist);
            }
        }
        
        return ans == inf ? -1 : ans;
    }
};