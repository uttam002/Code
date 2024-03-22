int getDigitSquareSum(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = getDigitSquareSum(slow);
        fast = getDigitSquareSum(getDigitSquareSum(fast));
    } while (slow != fast);

    return slow == 1;
}
