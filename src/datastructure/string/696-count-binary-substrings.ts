/*
 * @Author: wztlink1013
 * @Date: 2022-03-22 14:30:00
 * @LastEditTime: 2022-03-22 19:31:57
 * @Description: 696. 计数二进制子串
 * https://leetcode-cn.com/problems/count-binary-substrings/
 */
function countBinarySubstrings(s: string): number {
  let flag: string = s[0]
  let arr: number[] = []
  let result: number = 0
  for (let i: number = 0; i < s.length; i++) {
    if (s[i] !== flag) {
      arr.push(i)
      flag = s[i]
    }
  }
  console.log(s.match(/([1]+)|([0]+)/g))
  arr.forEach((data: number, index: number) => {
    if (index === 0) {
      arr.length === 1
        ? (result += Math.min(data, s.length - data))
        : (result += Math.min(data, arr[index + 1] - data))
    } else if (index === arr.length - 1) {
      result += Math.min(data - arr[index - 1], s.length - data)
    } else {
      result += Math.min(arr[index + 1] - data, data - arr[index - 1])
    }
  })
  return result
}

console.log(countBinarySubstrings('00110011'))
