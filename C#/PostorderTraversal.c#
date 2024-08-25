/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public IList<int> PostorderTraversal(TreeNode root) {
        List<int> result = new List<int>();
        PostOrder(root,result);
        return result;
    }
    internal void PostOrder(TreeNode root,List<int> result){
        if(root == null){
            return;
        }

        PostOrder(root.left,result);
        PostOrder(root.right,result);
        result.Add(root.val);
    }
    
}
