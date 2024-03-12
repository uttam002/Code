import java.util.ArrayList;

class Solution {
    
    // Method to remove zero sum sublists from a linked list
    public ListNode removeZeroSumSublists(ListNode head) {
        if (head == null)
            return null;

        // Convert linked list values into an ArrayList for easier manipulation
        ArrayList<Integer> values = new ArrayList<>();
        while (head != null) {
            values.add(head.val);
            head = head.next;
        }

        // Find the answer array by recursively removing zero sum sublists
        ArrayList<Integer> ans = findAns(values);
        
        // Convert the answer ArrayList back into a linked list
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        for (int i : ans) {
            current.next = new ListNode(i);
            current = current.next;
        }
        return dummy.next;
    }

    // Recursive method to find answer array by removing zero sum sublists
    public ArrayList<Integer> findAns(ArrayList<Integer> a) {
        ArrayList<Integer> ans = new ArrayList<>();
        
        for (int i = 0; i < a.size(); i++) {
            int sum = 0;
            for (int j = i; j < a.size(); j++) {
                sum += a.get(j);
                if (sum == 0) {
                    // When a zero sum sublist is found, exclude it and recursively find the answer
                    for (int k = 0; k < i; k++) {
                        ans.add(a.get(k));
                    }
                    for (int k = j + 1; k < a.size(); k++) {
                        ans.add(a.get(k));
                    }
                    return findAns(ans);
                }
            }
        }
        // If no zero sum sublist is found, return the input ArrayList itself
        return a;
    }
}
