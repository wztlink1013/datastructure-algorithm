package com.wztlink1013.problems.leetcode.editor.cn;

//反转一个单链表。 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL 
//
// 进阶: 
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？ 
// Related Topics 链表 
// 👍 1204 👎 0

public class P206ReverseLinkedList{
    public static void main(String[] args) {
        Solution solution = new P206ReverseLinkedList().new Solution();
        
    }

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public ListNode reverseList(ListNode head) {
//        TODO: for循环
//        for (ListNode node = head.next;node != null;node = node.next){
//            node.next.next = node;
//            node.next = null;
//        }
//        return head;
        /*
        // TODO: 递归思想
        // 避免陷入死循环
        if (head == null || head.next == null)
            return head;

        ListNode newHead = reverseList(head.next); //此处递归，找到最后一个节点了
        head.next.next = head; //重新指定节点指向（有两个next，注意少写）
        head.next = null; //将最初的节点指向空
        return newHead; //返回新的“倒置”头节点
        */

        // TODO: 非递归（快慢指针）
        if (head == null || head.next == null) return head;

        ListNode newHead = null;
        while (head != null){
            ListNode tmp = head.next;
            head.next = newHead;
            newHead = head;
            head = tmp;
        }
        return newHead;

    }
}
//leetcode submit region end(Prohibit modification and deletion)

}