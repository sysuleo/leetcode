/*
ou are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string,int> counts;  #计算words里面每个word的次数
        int lenS=s.length(),num=words.size();
        if(!lenS || !num) return res;
        for(string word:words){
            counts[word]++;
        }
        int lenWord=words[0].length();
        if(lenS<lenWord*num) return res;
        for(int i=0;i<lenS-lenWord*num+1;i++){
            unordered_map<string,int> seen;  #计算从下标i开始，s里面出现word的个数 放在for循环里面，每次都要初始化
            int j=0;   #j放在for循环外，因为要判断j==num满足条件的情况
            for(;j<num;j++){
                string word=s.substr(i+j*lenWord,lenWord);
                if (counts.find(word) != counts.end()) {  #能在counts里面找到word
                    seen[word]++;
                    if(seen[word]>counts[word]) break; #出现次数过多
                 }
                else break;   
            }
            if(j==num) res.push_back(i);
        }
        return res;
    }
};
