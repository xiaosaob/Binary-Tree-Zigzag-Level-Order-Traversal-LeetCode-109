// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(!root) return res;
        queue<TreeNode*> myQue;
        myQue.push(root);
        int lvl1 = 1, lvl2 = 0;
        bool isRev = false;
        while(!myQue.empty()) {
            vector<int> curRow;
            while(lvl1) {
                TreeNode *curNode = myQue.front();
                myQue.pop();
                --lvl1;
                curRow.push_back(curNode->val);
                if(curNode->left) {
                    myQue.push(curNode->left);
                    ++lvl2;
                }
                if(curNode->right) {
                    myQue.push(curNode->right);
                    ++lvl2;
                }
            }
            if(isRev) reverse(curRow.begin(), curRow.end());
            res.push_back(curRow);
            isRev = !isRev;
            lvl1 = lvl2;
            lvl2 = 0;
        }
        return res;
    }
};
