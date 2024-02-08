
char* convertToBase7(int num) {
    if (num == 0) return "0";

    char* result = (char*)malloc(12 * sizeof(char)); // Max length of the result string
    int index = 11;
    result[index--] = '\0';
    
    int isNegative = num < 0;
    if (isNegative) num = -num;// Make num positive for processing


    while (num) {
        result[index--] = num % 7 + '0';// Store the remainder in the result string
        num /= 7;
    }
    
    if (isNegative) result[index--] = '-';

    return &result[index + 1];
}
