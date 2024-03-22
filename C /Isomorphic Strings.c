bool isIsomorphic(char* s, char* t) {
    char sMap[256] = {0},tMap[256] = {0}; 
    for (; *s != '\0'; s++, t++) {
        if ((sMap[*s] && sMap[*s] != *t) || (tMap[*t] && tMap[*t] != *s)) {
            return false;
        }
        sMap[*s] = *t;
        tMap[*t] = *s;
    }

    return true;
}
