/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// LINK - https://www.interviewbit.com/problems/unique-binary-search-trees/
// MEDIUM

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val)
  {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

vector<TreeNode *> f(int start, int end)
{
  vector<TreeNode *> curr;
  if (start > end)
  {
    curr.push_back(NULL);
    return curr;
  }
  for (int i = start; i <= end; i++)
  {
    TreeNode *root = new TreeNode(i);
    vector<TreeNode *> left = f(start, i - 1);
    vector<TreeNode *> right = f(i + 1, end);

    for (int j = 0; j < left.size(); j++)
    {
      for (int k = 0; k < right.size(); k++)
      {
        TreeNode *root = new TreeNode(i);
        root->left = left[j];
        root->right = right[k];
        curr.push_back(root);
      }
    }
  }
  return curr;
}
vector<TreeNode *> generateTrees(int n)
{
  if (n == 0)
    return vector<TreeNode *>(0);
  return f(1, n);
}
