/*
 * @Author: wztlink1013
 * @Date: 2022-03-31 13:50:25
 * @LastEditTime: 2022-03-31 15:08:14
 * @Description: https://leetcode-cn.com/problems/container-with-most-water/
 */
function maxArea(height: number[]): number {
  let head: number = 0
  let back: number = height.length - 1
  const result_fun = (head: number, back: number): number => {
    return Math.min(height[head], height[back]) * (back - head)
  }
  let result = result_fun(head, back)

  while (head !== back) {
    height[head] < height[back] ? head++ : back--
    if(result <= result_fun(head, back) ) result = result_fun(head, back)
  }

  return result
}

console.log(maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]))
