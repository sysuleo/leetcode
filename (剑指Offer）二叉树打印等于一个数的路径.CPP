/*
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。

路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
*/



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<vector<int> >res;
    vector<int> trace;
    
    void dfs(TreeNode* root,int left){
        trace.push_back(root->val);
        if(root->val==left && !root->left && !root->right){
            res.push_back(trace);
        }
        else{
            if(root->left  && root->val < left){
                dfs(root->left,left-root->val);
            }
            if(root->right  && root->val < left){
                dfs(root->right,left-root->val);
            }
        }
        trace.pop_back();
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root) dfs(root,expectNumber); //这里一定要判断root是否为空，否者会溢出
        return res;
    }
};
