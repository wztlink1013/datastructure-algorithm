/*
 * @Author: wztlink1013
 * @Date: 2022-03-21 19:04:14
 * @LastEditTime: 2022-03-21 20:39:41
 * @Description: https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
 */

function reverseWords(s: string): string {
  // 字符串按空格进行分隔，保存数组，数组的元素的先后顺序就是单词的顺序
  let arr = s.split(' ')
  // 对数组进行遍历，然后每个元素进行反转
  let result = arr.map((item: any) => {
    return item.split('').reverse().join('')
  })
  return result.join(' ')
}

console.log(reverseWords("Let's take LeetCode contest"))
