/*
 * @Author: wztlink1013
 * @Date: 2022-04-02 12:36:01
 * @LastEditTime: 2022-04-02 13:17:55
 * @Description: TODO:
 */
function PredictTheWinner(nums: number[]): boolean {
  let play_one: number = 0
  let play_two: number = 0
  let flag: boolean = true
  while (nums.length !== 0) {
    if (flag) {
      // 1号玩家
      if (nums[0] >= nums[nums.length - 1]) {
        play_one = nums[0] + play_one
        nums.shift()
      } else {
        play_one = nums[nums.length - 1] + play_one
        nums.pop()
      }
      flag = false
    } else {
      // 2号玩家
      if (nums[0] >= nums[nums.length - 1]) {
        play_two = nums[0] + play_two
        nums.shift()
      } else {
        play_two = nums[nums.length - 1] + play_two
        nums.pop()
      }
      flag = true
    }
  }
  return play_one >= play_two ? true : false
}

console.log(PredictTheWinner([1, 5, 233, 7]))
