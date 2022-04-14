/*
 * @Author: wztlink1013
 * @Date: 2022-04-14 13:57:34
 * @LastEditTime: 2022-04-14 13:57:37
 * @Description:
 */
var maximumWealth = function(accounts) {
  let result = 0
  accounts.forEach(data => {
      result = result > data.reduce((a, b) => { return a + b }) ? result : data.reduce((a, b) => { return a + b })
  })
  return result
};