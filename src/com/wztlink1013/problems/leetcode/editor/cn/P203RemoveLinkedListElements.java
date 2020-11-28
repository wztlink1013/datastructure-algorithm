package com.wztlink1013.problems.leetcode.editor.cn;

//删除链表中等于给定值 val 的所有节点。 
//
// 示例: 
//
// 输入: 1->2->6->3->4->5->6, val = 6
//输出: 1->2->3->4->5
// 
// Related Topics 链表 
// 👍 438 👎 0

public class P203RemoveLinkedListElements{
    public static void main(String[] args) {
        Solution solution = new P203RemoveLinkedListElements().new Solution();
        
    }

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        // 将整个链表想象成head+子链表
        if (head == null)
            return null;
        // 先处理子链表
        head.next = removeElements(head.next, val);
        // 再处理头结点
        return head.val == val ? head.next : head;
    }
}

//leetcode submit region end(Prohibit modification and deletion)

}