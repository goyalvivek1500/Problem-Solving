class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushAll(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if (temp->right != NULL) {
            pushAll(temp->right);
        }

        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};