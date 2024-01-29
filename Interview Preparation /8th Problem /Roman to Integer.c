int romanToInt(const char* s) {
    int num = 0, temp,pre;
    char c;
    for (long i = 0; s[i] != '\0'; i++) {
        c = s[i];
        switch (c) {
            case 'I':
                temp = 1;
                break;
            case 'V':
                temp = 5;
                break;
            case 'X':
                temp = 10;
                break;
            case 'L':
                temp = 50;
                break;
            case 'C':
                temp = 100;
                break;
            case 'D':
                temp = 500;
                break;
            case 'M':
                temp = 1000;
                break;
        }
        if (i==0) pre=temp;
        else if (pre<temp)temp-=(2*pre);
        num += temp;
        pre=temp;
    }
    return num;
}
