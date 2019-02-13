/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/



class Solution {
public:
    vector<string> res;
    vector<string> str={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void backtrack(int now,string &digits,string &cur,unordered_map<char,string> &mp){
        if(now==digits.size()){
            res.push_back(cur);
            return;
        }
        string temp=mp[digits[now]];
        for(int i=0;i<temp.size();i++){
            cur+=temp[i];
            backtrack(now+1,digits,cur,mp);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()<=0) return {};
        string cur="";
        unordered_map<char,string> mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        backtrack(0,digits,cur,mp);
        return res;
    }
};
