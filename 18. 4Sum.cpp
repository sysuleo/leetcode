/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int lens=nums.size();
        int count;
        vector <vector<int>>res;
        if(lens<4) return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<lens-3;i++){
            for(int j=i+1;j<lens-2;j++){
                int left=j+1;
                int right=nums.size()-1;
                while(left<right){
                    count=nums[i]+nums[j]+nums[left]+nums[right];
                    if(count==target){
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                    if(count<target) left++;
                    if(count>target) right--;
                }
            }
        }
        sort(res.begin(),res.end());    //sort 
        res.erase(unique(res.begin(),res.end()),res.end());    //erase the duplicates
        return res;
    }
};
