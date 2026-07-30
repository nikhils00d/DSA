class Solution {
public:
    void allcombination(vector<int> &arr, int idx, int tar, vector<vector<int>> &ans, vector<int> &combin){
        

        if(tar==0){
            ans.push_back({combin});
            return;
        }
        for (int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1])continue;
            if(arr[i]>tar)break;
            combin.push_back(arr[i]);
            allcombination(arr, i+1, tar-arr[i], ans, combin);
            combin.pop_back();
        }        
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> combin;
        allcombination(arr, 0, target, ans, combin);

        return ans;
        
    }
};