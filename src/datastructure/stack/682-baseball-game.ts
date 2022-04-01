/*
 * @Author: wztlink1013
 * @Date: 2022-04-01 20:36:57
 * @LastEditTime: 2022-04-01 20:59:26
 * @Description:
 */
function calPoints(ops: string[]): number {
  let sta: Array<number> = []
  ops.forEach((data: string) => {
    switch (data) {
      case '+':
        sta.push(sta[sta.length - 1] + sta[sta.length - 2])
        break
      case 'D':
        sta.push(sta[sta.length - 1] * 2)
        break
      case 'C':
        sta.pop()
        break
      default:
        sta.push(Number(data))
    }
  })

  return sta.reduce((result: number, index: number) => {
    return result + index
  })
}

console.log(calPoints(['5', '-2', '4', 'C', 'D', '9', '+', '+']))
