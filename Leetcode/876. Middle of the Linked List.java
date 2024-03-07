/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
    class Solution {
        public ListNode middleNode(ListNode head) {
			for (int size = checkSize(head) / 2; size > 0; size--)
                head = head.next;
            return head;
        }

        private int checkSize(ListNode head) {
            return head.next == null ? 1 : 1 + checkSize(head.next);
        }
    }
