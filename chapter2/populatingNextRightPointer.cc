/**
 * Given a binary tree

    struct TreeLinkNode {
          TreeLinkNode *left;
          TreeLinkNode *right;
          TreeLinkNode *next;
        }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
    Given the following perfect binary tree,
             1
	            /  \
			          2    3
				       / \  / \
					           4  5  6  7
						   After calling your function, the tree should look like:
						            1 -> NULL
							           /  \
									         2 -> 3 -> NULL
										      / \  / \
											          4->5->6->7 -> NULL

*/

/**
 *  * Definition for binary tree with next pointer.
 *   * struct TreeLinkNode {
 *    *  int val;
 *     *  TreeLinkNode *left, *right, *next;
 *      *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 *       * };
 *        */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        level traverse
        list<TreeLinkNode*> q;
        if (NULL == root)
            return;
        q.push_back(root);
        while(! q.empty()) {
            int level_num = q.size();
            // traverse the level
            int i = 0;
            for(auto iter = q.begin(); iter != q.end() && i < level_num; ++iter, ++ i) {
                if ((*iter) -> left)
                    q.push_back((*iter)->left);
                if ((*iter) -> right)
                    q.push_back((*iter)->right);
            }
            // pop last level and fix next pointer
            for (int i = 0; i < level_num; ++ i) {
                TreeLinkNode* post = q.front();
                q.pop_front();
                TreeLinkNode* cur = q.front();
                if (level_num - 1 == i)
                    cur = NULL;
                post -> next = cur;
            }
        }
    }
};
