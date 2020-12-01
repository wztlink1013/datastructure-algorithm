package com.wztlink1013.problems.leetcode.editor.cn;

//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。 
//
// 示例 1: 
//
// 输入: 1->1->2
//输出: 1->2
// 
//
// 示例 2: 
//
// 输入: 1->1->2->3->3
//输出: 1->2->3 
// Related Topics 链表 
// 👍 388 👎 0

public class P83RemoveDuplicatesFromSortedList{
    public static void main(String[] args) {
        Solution solution = new P83RemoveDuplicatesFromSortedList().new Solution();

    }

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        // TODO: 快慢指针
        if (head == null) return head;
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null){
            if (slow.val != fast.val) {
                slow.next = fast;
                slow = fast;
            }
            fast = fast.next;
        }
        slow.next = null;
        return head;
    }
}
// TODO: 单指针下一步
//class Solution {
//    public ListNode deleteDuplicates(ListNode head) {
//        ListNode cur = head;
//        while(cur != null && cur.next != null) {
//            if(cur.val == cur.next.val) {
//                cur.next = cur.next.next;
//            } else {
//                cur = cur.next;
//            }
//        }
//        return head;
//    }
//}


//leetcode submit region end(Prohibit modification and deletion)

}