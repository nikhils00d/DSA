class Solution {
public:
    

    void allSubsets(vector<int> &nums,int idx, vector<vector<int>>&ans, vector<int>part){
        ans.push_back(part);
        for (int i =idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1])continue;
            part.push_back(nums[i]);
            allSubsets(nums, i+1, ans, part);
            part.pop_back();
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> part;
        vector<vector<int>> ans;
        int idx=0;
        allSubsets(nums,idx, ans, part);
        return ans;        
    }
};