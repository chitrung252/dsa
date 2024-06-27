/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class CloneLinkedList {

private
    ListNode clone(ListNode head) {
        ListNode cloneHead = null;
        ListNode prev = null;
        ListNode current = head;
        while (current != null) {
            ListNode listnode = new ListNode(current.val);
            if (cloneHead == null) {
                cloneHead = listnode;
            }
            if (prev != null) {
                prev.next = listnode;
            }
            prev = listnode;
            current = current.next;
        }
        return cloneHead;
    }
}
