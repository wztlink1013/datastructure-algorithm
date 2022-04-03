/*
 * @Author: wztlink1013
 * @Date: 2022-04-02 13:38:19
 * @LastEditTime: 2022-04-02 13:50:18
 * @Description:
 */
function repeatedSubstringPattern(s: string): boolean {
  let reg: RegExp = /^(\w+)\1+$/
  return reg.test(s)
}

console.log(repeatedSubstringPattern('abcabcabcabc'))
