/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> St;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[') St.push(s[i]);
            else if(s[i]==')'){
                if (St.size() == 0 ) return false;  // judge if St is empty
                if(St.top()!='(') return false;
                else St.pop();
            }
            else if(s[i]=='}'){
                if (St.size() == 0 ) return false;
                if(St.top()!='{') return false;
                St.pop();
            }
            else if(s[i]==']'){
                if (St.size() == 0 ) return false;
                if(St.top()!='[') return false;
                St.pop();
            }
            else return false;
        }
        if(!St.empty()) return false;
        return true;
    }
};



//optimization
class Solution {
public:
    bool isValid(string s) {
        stack<char> St;
        unordered_map<char,char> mp={
            {'}','{'},
            {')','('},
            {']','['}
        };
         for (char & c : s){
            if(c==')'||c=='}'||c==']') {
                if (St.size() == 0 ) return false;  // judge if St is empty
                if(St.top()!=mp[c]) return false;
                else St.pop();
            }
            else St.push(c);
        }
        if(!St.empty()) return false;
        return true;
    }
};
