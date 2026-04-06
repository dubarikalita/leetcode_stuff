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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        ans=preorder(root);
        return ans;
    }

    vector<int> preorder(TreeNode* node){
        if(node==NULL) return {};
        vector<int> data;
        vector<int>left =preorder(node->left);
        vector<int>right=preorder(node->right);
        data.push_back(node->val);
        data.insert(data.end(),left.begin(),left.end());
        data.insert(data.end(),right.begin(),right.end());
        return data;
    }
};