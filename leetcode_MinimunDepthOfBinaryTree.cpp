class Solution {
public:
    int run(TreeNode *root) {
        if (root == nullptr)
            return 0;
        
        int H_left = run(root->left);
        int H_right = run(root->right);
        
        if (H_left == 0 || H_right == 0)
            return 1 + H_left + H_right;
        else
            return H_left < H_right ? 1 + H_left : 1 + H_right;
    }
};
