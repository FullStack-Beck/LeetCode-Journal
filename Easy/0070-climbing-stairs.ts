function climbStairs(n: number): number {
    const ways = [];
    for(let i = 1; i <= n; i++)
    {
        if(i === 1) {
            ways.push(1)
        }
        else if(i === 2) {
            ways.push(2)
        }
        else if(i > 2) {
            ways.push(ways[i-2] + ways[i-3])
        }
    }
    return ways[n - 1];
};
