/*
 * @Author: wztlink1013
 * @Date: 2022-04-01 21:17:25
 * @LastEditTime: 2022-04-01 21:32:28
 * @Description:
 */
function isValid(s: string): boolean {
  let stack: Array<string> = []
  for (let i of s) {
    if (['(', '[', '{'].includes(i)) {
      stack.push(i)
    } else {
      switch (i) {
        case ')':
          if (stack[stack.length - 1] === '(') {
            stack.pop()
          } else {
            return false
          }
          break
        case ']':
          if (stack[stack.length - 1] === '[') {
            stack.pop()
          } else {
            return false
          }
          break
        case '}':
          if (stack[stack.length - 1] === '{') {
            stack.pop()
          } else {
            return false
          }
          break
      }
    }
  }
  return stack.length ? false : true
}

console.log(isValid('([)]'))
