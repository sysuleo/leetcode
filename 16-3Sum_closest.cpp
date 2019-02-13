/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int lens=nums.size();
        if(lens<3) return {};
        sort(nums.begin(),nums.end());
        int sum;
        int diff;
        int MIN=INT_MAX-1;
        int res;
        for(int i=0;i<=lens-3;i++){
            int left=i+1;
            int right =lens-1;
            while(left<right){
                sum=nums[left]+nums[i]+nums[right];
                diff=sum-target;
                if(diff==0) return target;
                if(abs(diff)<abs(MIN)){
                    MIN=abs(diff);
                    res=sum;
                }
                if(diff>0) right--;
                else left++;
                
            }
        }
       return res;
        
    }
};
