int climbStairs(int n) {
    int a=1, b=2, c, i;

    if(n == 1 || n == 2) {
        return n;
    }

    for(i=3; i<=n; i++) {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}