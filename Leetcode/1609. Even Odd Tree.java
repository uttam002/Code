/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private static class Count {
        int count = 0;
        public Count(int count){
            this.count = count;
        }
    }
    public boolean isEvenOddTree(TreeNode root) {
        return diveInto(root, new Count(0), new HashMap<>());
    }

    private boolean diveInto(TreeNode root, Count count, HashMap<Integer, Integer> map){
        if(root == null){
            return true;
        }
        if((count.count % 2 == 0 && root.val % 2 == 0) || (count.count % 2 == 1 && root.val % 2 == 1))
            return false;
        if((count.count % 2 == 0 && root.val % 2 == 1)){ // нечетный odd
            if(!map.containsKey(count.count)){
                map.put(count.count, root.val);
            }else {
                int previous = map.get(count.count);
                if(previous >= root.val)
                    return false;
                map.put(count.count, root.val);
            }
        }else if((count.count % 2 == 1 && root.val % 2 == 0)){ // четный - even
            if(!map.containsKey(count.count)){
                map.put(count.count, root.val);
            }else {
                int previous = map.get(count.count);
                if(previous <= root.val)
                    return false;
                map.put(count.count, root.val);
            }
        }
        return diveInto(root.left, new Count(++count.count), map) && diveInto(root.right, new Count(count.count), map);
    }
}
