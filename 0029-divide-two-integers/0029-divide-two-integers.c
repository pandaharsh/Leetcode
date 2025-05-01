int divide(int dividend, int divisor) {
    bool sign = (dividend < 0 ^ divisor < 0) ? 1 : 0;
    int div2, res = 0;

    if(divisor == 1) 
        return dividend;
    if(divisor == -1) {
        if (dividend == INT_MIN)
            return INT_MAX;
        return -dividend;
    }

    if(divisor == INT_MIN)
        return (dividend == INT_MIN) ? 1 : 0;
    
    if(divisor > -1073741824 && divisor < 1073741823) {
        div2 = divisor+divisor;
        if(dividend > 0) {
            while((sign && dividend >= -div2) || (!sign && dividend >= div2)) {
                dividend = (sign) ? dividend+div2 : dividend-div2;
                res +=2;
            }
        }
        else {
            while ((sign && dividend <= -div2) || (!sign && dividend <= div2)) {
                dividend = (sign) ? dividend+div2 : dividend-div2;
                res += 2;
            }
        }
    }

    if(dividend > 0) {
        if((sign && dividend >= -divisor) || (!sign && dividend >= divisor))
            res++;
    }
    else {
        if((sign && dividend <= -divisor) || (!sign && dividend <= divisor))
            res++;
    }

    return sign ? -res : res;
}