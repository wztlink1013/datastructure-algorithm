package com.wztlink1013.problems.leetcode.editor.cn;

//给定一个链表，判断链表中是否有环。
//题目有图
//https://leetcode-cn.com/problems/linked-list-cycle/

public class P141LinkedListCycle{
    public static void main(String[] args) {
        Solution solution = new P141LinkedListCycle().new Solution();
        
    }
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) return false;

        // TODO: 快慢指针
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) return true; //如果能相遇则表示有环
        }
        return false; //不能相遇则没有环
    }
}
//leetcode submit region end(Prohibit modification and deletion)

}