/*
 * @Author: wztlink1013
 * @Date: 2022-03-29 21:48:06
 * @LastEditTime: 2022-03-29 21:50:42
 * @Description: https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 */
function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  let arr: number[] = nums1.concat(nums2).sort((a: any, b: any) => {
    return a - b
  })
  if (arr.length % 2) {
    return arr[(arr.length - 1) / 2]
  } else {
    return (arr[arr.length / 2] + arr[arr.length / 2 - 1]) / 2
  }
}

console.log(findMedianSortedArrays([1, 3], [2]))
