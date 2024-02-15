int lengthOfLastWord(char* s) {
     int count = 0;
   for (int i =  strlen(s) - 1; i >= 0; i--) {
            if (isalpha(s[i])) {
                count++;
            } else if (count != 0) {
                return count;
            }
        }
    
    return count;
}
