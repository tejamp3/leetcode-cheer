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
int getH(TreeNode* root){
    if(root==NULL) return 0;
    int left=getH(root->left);
    int right=getH(root->right);
    return 1+max(left,right);
}
TreeNode* f(TreeNode* root){
    if(root==NULL) return root;
    int lh=getH(root->left);
    int rh=getH(root->right);
    if(lh==rh) return root;
    else if(lh>rh) return f(root->left);
    else return f(root->right);

}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return f(root);
    }
};