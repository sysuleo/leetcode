/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int lensH=haystack.size();
        int lensN=needle.size();
        if(lensN==0) return 0;
        for(int i=0;i<=lensH-lensN;i++){
            if(haystack.substr(i,lensN)==needle) return i;
        }
        return -1;
    }
};
