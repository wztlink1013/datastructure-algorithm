/*
 * @Author: wztlink1013
 * @Date: 2022-04-06 12:44:59
 * @LastEditTime: 2022-04-06 12:49:30
 * @Description:
 */
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  let result = []
  if (nums.length === 3 && nums[0] + nums[1] + nums[2] === 0) result.push(nums)
  // 判断一个数组是否为一个嵌套数组的子数组
  const isSonArray = (FArray, SArray) => {
    let flag = true
    for (let i of FArray) {
      if (i[0] === SArray[0] && i[1] === SArray[1] && i[2] === SArray[2]) {
        flag = false
        break
      }
    }
    return flag
  }
  if (nums.length > 3) {
    for (let index = 0; index < nums.length - 2; index++) {
      let head = index
      let center = index + 1
      let last = index + 2

      while (center <= nums.length - 2 && last <= nums.length - 1) {
        console.log('+++++++++++', head, center, last)
        if (nums[head] + nums[center] + nums[last] === 0) {
          let test = [nums[head], nums[center], nums[last]]
          test.sort((a, b) => {
            return a - b
          })
          if (isSonArray(result, test)) result.push(test)
        }
        if (last < nums.length - 1) {
          last++
        } else {
          center++
          last = center + 1
        }
      }
    }
  }
  return result
}

console.log(threeSum([-1, 0, 1, 2, -1, -4]))
