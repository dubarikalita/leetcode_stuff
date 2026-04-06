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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        ans=postorder(root);
        return ans;
    }

    vector<int> postorder(TreeNode* node){
        if(node==NULL) return {};
        vector<int>data;
        vector<int>left=postorder(node->left);
        vector<int>right=postorder(node->right);

        data.insert(data.end(),left.begin(),left.end());
        data.insert(data.end(),right.begin(),right.end());
        data.push_back(node->val);
        return data;
    }
};