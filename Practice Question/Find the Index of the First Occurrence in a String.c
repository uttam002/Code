int strStr(char* haystack, char* needle) {
   char* ptr = strstr(haystack, needle);
    if (ptr != NULL) return ptr - haystack; // Calculate the index of the substring
    else return -1; 
}
