/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero.
Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Example 2:
Input: dividend = 7, divisor = -3
Output: -2

Note:
Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        else if(divisor==1) return dividend;
        else if(!divisor) return INT_MAX;
        long long res=0;
        long long a=labs(dividend);  /一定要是labs，不能是abs
        long long b=labs(divisor);
        while(a>=b){
            long long temp=b,m=1;
            while (a>= (temp << 1)) {
                temp <<= 1;
                m <<= 1;
            }
            res+=m;
            a-=temp;
        }
        return (dividend<0==divisor<0)?res:-1*res;
    }
};
