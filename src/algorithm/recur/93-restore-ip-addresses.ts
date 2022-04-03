/*
 * @Author: wztlink1013
 * @Date: 2022-04-02 14:57:12
 * @LastEditTime: 2022-04-03 18:46:11
 * @Description:
 */
function restoreIpAddresses(s: string): string[] {
  // 保存所有符合条件的IP地址
  let r: any[] = []
  // 分四步递归处理ip分段
  let search = (cur: any, sub: any) => {
    if (sub.length > 12) return
    
    // 边界条件
    if (cur.length === 4 && cur.join('') === s) {
      r.push(cur.join('.'))
    } else {
      // 正常的处理过程
      for (let i = 0, len = Math.min(3, sub.length), tmp; i < len; i++) {
        tmp = sub.substr(0, i + 1)
        if (tmp - 256 < 0) {
          // 转换下数据类型，如 01为1（LeetCode测试用例）
          search(cur.concat([tmp * 1]), sub.substr(i + 1))
        }
      }
    }
  }
  search([], s)
  return r
}

console.log(restoreIpAddresses('101023'))
