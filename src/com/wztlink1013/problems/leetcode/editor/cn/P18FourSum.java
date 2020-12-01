package com.wztlink1013.problems.leetcode.editor.cn;

//给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c +
// d 的值与 target 相等？找出所有满足条件且不重复的四元组。 
//
// 注意： 
//
// 答案中不可以包含重复的四元组。 
//
// 示例： 
//
// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
//
//满足要求的四元组集合为：
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]
// 
// Related Topics 数组 哈希表 双指针 
// 👍 554 👎 0

/*
* 思路：
*   四个for循环，简单粗暴
* 缺点：
*   时间复杂度高
* */
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class P18FourSum{
    public static void main(String[] args) {
        Solution solution = new P18FourSum().new Solution();
    }

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new LinkedList<>();
        int a = 0;
        int b = 1;
        int c = 2;
        int d = 3;
        for (int i=nums[a];i<nums.length;++a){
            for (int j=nums[b];j<nums.length;++b){
                for (int k=nums[c];k<nums.length;++c){
                    for (int l=nums[d];l<nums.length;++d){
                        if (i+j+k+l == target){
                            result.add(new LinkedList<>(Arrays.asList(i, j, k, l)));
                        }break;
                    }
                }
            }
        }
        return result;
    }
}
//leetcode submit region end(Prohibit modification and deletion)

}