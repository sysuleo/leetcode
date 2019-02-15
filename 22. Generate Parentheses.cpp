/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/



//backtrack

class Solution {
public:
     void Backtrack(int start,int n,vector<string> &PT,string &res,int &LeftAvil,int &RightAvil,int &needRight);
    vector<string> generateParenthesis(int n) {
        vector<string> PT;
        if(n<=0) return PT;
        Backtrack(PT,"",n,n,0);
         return PT;
    }
    
    void Backtrack(vector<string> &PT,string res,int LeftAvil,int RightAvil,int needRight){
        if(LeftAvil<0 || RightAvil<0) return;
        if(LeftAvil==0 && RightAvil==0){
            PT.push_back(res);
        }
        Backtrack(PT,res+'(',LeftAvil-1,RightAvil,needRight+1);
        if(needRight>0) Backtrack(PT,res+')',LeftAvil,RightAvil-1,needRight-1);
    }
};
