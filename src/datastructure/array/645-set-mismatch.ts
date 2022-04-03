function findErrorNums(nums: number[]): number[] {
    let result: any = []
    nums.sort((a: number, b:number) => { return a - b })
    nums.forEach((data: number, index: number) => {
        // 重复的值
        if (data === nums[index - 1]) {
            result.unshift(data)
            nums.splice(index, 1)
            nums.push(0)
            // 丢失的值
            for (let i: number = 0; i < nums.length; i++) {
                if(i + 1 !== nums[i]) {
                    result.push(i + 1)
                    break
                }
            }
        }
    })
    return result
};