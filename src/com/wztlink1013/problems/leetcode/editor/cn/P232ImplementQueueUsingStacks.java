package com.wztlink1013.problems.leetcode.editor.cn;

// P232.用栈实现队列
// P232.implement-queue-using-stacks
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）： 
//
// 实现 MyQueue 类： 
//
// 
// void push(int x) 将元素 x 推到队列的末尾 
// int pop() 从队列的开头移除并返回元素 
// int peek() 返回队列开头的元素 
// boolean empty() 如果队列为空，返回 true ；否则，返回 false 
// 
//
// 
//
// 说明： 
//
// 
// 你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
// 
// 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。 
// 
//
// 
//
// 进阶： 
//
// 
// 你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。 
// 
//
// 
//
// 示例： 
//
// 
//输入：
//["MyQueue", "push", "push", "peek", "pop", "empty"]
//[[], [1], [2], [], [], []]
//输出：
//[null, null, null, 1, 1, false]
//
//解释：
//MyQueue myQueue = new MyQueue();
//myQueue.push(1); // queue is: [1]
//myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//myQueue.peek(); // return 1
//myQueue.pop(); // return 1, queue is [2]
//myQueue.empty(); // return false
// 
//
// 
// 
//
// 
//
// 提示： 
//
// 
// 1 <= x <= 9 
// 最多调用 100 次 push、pop、peek 和 empty 
// 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作） 
// 
// Related Topics 栈 设计 
// 👍 361 👎 0

import java.util.Stack;

public class P232ImplementQueueUsingStacks{
    public void main(String[] args) {
        MyQueue myQueue = new MyQueue();
        //本地调试需要将MyQueue类和主函数加上静态static修饰字
        myQueue.push(1); // queue is: [1]
        myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
        myQueue.pop();
        myQueue.peek();
//        myQueue.peek(); // return 1
//        myQueue.pop(); // return 1, queue is [2]
//        myQueue.empty(); // return false
//        System.out.println(myQueue);
    }

//leetcode submit region begin(Prohibit modification and deletion)
class MyQueue {
    Stack<Integer> stack_input = new Stack<>();
    Stack<Integer> stack_output = new Stack<>();
    /** Initialize your data structure here. */
    public MyQueue() {
//        Stack<Integer> stack_input = new Stack<>();
//        Stack<Integer> stack_output = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        stack_input.push(x);
        int temp = stack_input.size();
        if (stack_output.size() == 0) {
            for (int i=0; i<temp; i++){
                stack_output.push(stack_input.pop());
            }
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        int temp = stack_input.size();
        if (stack_output.size() == 0) {
            for (int i=0; i<temp; i++){
                stack_output.push(stack_input.pop());
            }
        }
        return stack_output.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        int temp = stack_input.size();
        if (stack_output.size() == 0) {
            for (int i=0; i<temp; i++){
                stack_output.push(stack_input.pop());
            }
        }
        return stack_output.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        if (stack_input.size() == 0 && stack_output.size() == 0) {
            return true;
        }
        return false;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
//leetcode submit region end(Prohibit modification and deletion)

}