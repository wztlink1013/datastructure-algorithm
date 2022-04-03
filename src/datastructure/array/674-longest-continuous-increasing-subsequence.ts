/*
 * @Author: wztlink1013
 * @Date: 2022-04-02 11:57:03
 * @LastEditTime: 2022-04-02 12:29:11
 * @Description:
 */
function findLengthOfLCIS(nums: number[]): number {
  if (nums.length === 1) return 1
  let head: number = 0
  let next: number = 1
  let result: number = 1
  while (next !== nums.length) {
    nums[next - 1] < nums[next]
      ? (result = result <= next - head + 1 ? next - head + 1 : result)
      : (head = next)
    next++
  }
  return result
}

console.log(findLengthOfLCIS([1, 3, 5, 4, 7]))
