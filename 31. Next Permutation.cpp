/*
从后往前找到满足nums[i]<nums[i+1]的i
  如果没有（i<0)则reverse(nums[0:nums.end()]）
  否则，从后往前找到第一个nums[k]>nums[i]
   swap(nums[k],nums[i]);
   reverse(nums[i+1:nums.end()]);
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
//题意理解，重新排列找到下一个比当前排列数字大的数

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lens=nums.size(),k;
        int i=lens-2;  //lens-2开始
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        if(i<0) reverse(nums.begin(), nums.end());
        else{
            for (k = lens - 1; k >i ; k--) {
                if (nums[k] > nums[i]) {
                    break;
                }
            }
            swap(nums[k],nums[i]);
            reverse(nums.begin()+i+1,nums.end());
        }
    }
};
