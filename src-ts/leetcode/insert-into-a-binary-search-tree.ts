/* eslint-disable no-param-reassign */
/* eslint-disable no-use-before-define */
class TreeNode {
  val: number;

  left: TreeNode | null;

  right: TreeNode | null;

  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

function insertIntoBST(root: TreeNode | null, val: number): TreeNode | null {
  if (root == null) {
    return new TreeNode(val);
  }

  if (root.left == null && val < root.val) {
    root.left = new TreeNode(val);
    return root;
  }

  if (root.right == null && val > root.val) {
    root.right = new TreeNode(val);
    return root;
  }

  if (root.val > val) {
    root.left = insertIntoBST(root.left, val);
  } else {
    root.right = insertIntoBST(root.right, val);
  }

  return root;
}
