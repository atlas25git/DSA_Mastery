int sumOfDigits(int n)
{
    // Return n if it is less than 10
    if(n<10)
        return n;
    // Recursively compute sum of digits if n is more than 9
    else
        return n%10//current right most digit
        + sumOfDigits(n/10); //removing that digit
}
