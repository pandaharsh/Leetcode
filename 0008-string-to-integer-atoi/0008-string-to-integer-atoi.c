long long int myAtoi(char* s) {
    long long int i = 0, sum = 0, f=0;
    char si = '+';
    while(s[i] != '\0')
    {
        if(s[i] == '-' && f==0)
        {
            si = '-';
            f = 1;
        }
        else if(s[i] == '+' && f==0)
        {
            si = '+';
            f = 1;
        }
        else if(s[i] == ' ' && f==0)
        {
           
        }
        else if(s[i]>='0' && s[i]<='9')
        {
            if(sum>INT_MAX) 
            {
                goto z;
            }
            sum = sum*10+(s[i]-'0');
            if(!isdigit(s[i+1]))
            {
                break;
            }
        }
        else {
            break;
        }
        i++;
    }
    z:
    if(si == '-')
    {
        sum *= -1;
        if(sum<INT_MIN){
            return INT_MIN;
        }
        return sum;
    }     
    else {
        if(sum>INT_MAX) {
            return INT_MAX;
        }
        return sum;
    }
}