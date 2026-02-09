/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    TreeNode* solve(int l, int r, vector<int> &ans){
        if(l>r) return NULL;
        int mid= l+(r-l)/2;
        TreeNode* root= new TreeNode(ans[mid]);
        root->left = solve(l, mid-1, ans);
        root->right = solve(mid+1, r, ans);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        int n= ans.size();
        int l=0, r=n-1;
        return solve(l, r, ans);
    }
};