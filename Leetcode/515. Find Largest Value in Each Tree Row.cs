using System;
using System.Collections.Generic;

public class Solution {
    public IList<int> LargestValues(TreeNode root) {
        var result = new List<int>();
        if (root == null) return result; // Handle the empty tree case

        var queue = new Queue<TreeNode>();
        queue.Enqueue(root);

        while (queue.Count > 0) {
            int levelSize = queue.Count; // Number of nodes at the current level
            int largestValue = int.MinValue;

            for (int i = 0; i < levelSize; i++) {
                var current = queue.Dequeue();

                // Update the largest value for the current level
                largestValue = Math.Max(largestValue, current.val);

                // Enqueue children for the next level
                if (current.left != null) queue.Enqueue(current.left);
                if (current.right != null) queue.Enqueue(current.right);
            }

            // Add the largest value of the current level to the result
            result.Add(largestValue);
        }

        return result;
    }
}
