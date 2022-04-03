/*
 * @Author: wztlink1013
 * @Date: 2022-04-02 14:15:42
 * @LastEditTime: 2022-04-02 14:26:59
 * @Description:
 */
function fib(n: number): number {
  if (n <= 1) return n
  return fib(n - 1) + fib(n - 2)
}

console.log(fib(4))
