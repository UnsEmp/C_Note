#include <bits/stdc++.h>
using namespace std;


//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // add(root1, root2);      
        if(root1 && root2) {
            root1->val += root2->val;
        }
        else if(!root1 && root2) {
            TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
            r->val = 0;
            r->left = r->right = nullptr;
            r->val += root2->val;
            root1 = r;
        }
        else
            return root1;
        root1->left = add(root1->left, root2->left);
        root1->right = add(root1->right, root2->right);
        return root1;
    }
    TreeNode* add(TreeNode* root1, TreeNode* root2) {
        if(root1 || root2) {
            if(root1 && root2) {
                root1->val += root2->val;
            }
            else if(!root1 && root2) {
                // TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
                // r->val = 0;
                // r->left = r->right = nullptr;
                // r->val += root2->val;
                // root1 = r;
                return root2;
            }
            else if(root1 && !root2)
                return root1;
            else
                return nullptr;

            root1->left = add(root1->left, root2->left);
            root1->right = add(root1->right, root2->right);
        }
        return root1;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root1 = stringToTreeNode(line);
        getline(cin, line);
        TreeNode* root2 = stringToTreeNode(line);
        
        TreeNode* ret = Solution().mergeTrees(root1, root2);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}