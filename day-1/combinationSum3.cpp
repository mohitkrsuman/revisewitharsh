class Solution {
    void help(int i, int k, int target, vector<int>&soln, vector<vector<int>>&ans){
        
        if(target == 0 && k == 0){
            ans.push_back(soln);
            return;
        }
        
        if(target < 0 || k < 0){
            return;
        }
        
        if(i == 10){
            return;
        }
        
        //skip the ith elem
        help(i+1, k, target, soln, ans);
        
        //pick the ith elem
        soln.push_back(i);
        help(i+1, k-1, target - i, soln, ans);
        // backtrack
        soln.pop_back();
        
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        // instead of making a array we can use i for our counting
        vector<vector<int>> ans;
        vector<int> soln;
        
        // help(0, candidates, k, n, soln, ans);
        help(1, k, n, soln, ans);
        return ans;
    }
};
