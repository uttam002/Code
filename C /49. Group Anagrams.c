
int cmpStr(const void* a, const void* b){
    return *(char*)a - *(char*)b;
}

unsigned int RSHash(char *str) {
    unsigned int b = 378551,a = 63689,hash = 0;

    while (*str) {
        hash = hash * a + (*str++);
        a *= b;
    }
    return (hash & 0x7FFFFFFF);
}

int hash(char* s) {
    int len = strlen(s);
    char* temp = malloc((len+1) * sizeof(char));
    strcpy(temp, s);
    qsort(temp, len, sizeof(char), cmpStr);
    int ans = RSHash(temp);
    free(temp);
    return ans;
}

int cmpfunc(const void* p1, const void* p2) {
    int* arr1 = *(int**)p1;
    int* arr2 = *(int**)p2;
    if (arr1[2] == arr2[2]) return arr1[1] - arr2[1]; 
    return arr1[2] - arr2[2];
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    int i, j,cn = 1,idx = 0;
    int** lenTable = malloc(strsSize * sizeof(int*)); 
    
    for (i = 0; i < strsSize; i++) {
        lenTable[i] = malloc(3 * sizeof(int));
        lenTable[i][0] = i;
        lenTable[i][1] = strlen(strs[i]);
        lenTable[i][2] = hash(strs[i]);
    }
    
    qsort(lenTable, strsSize, sizeof(int*), cmpfunc);
    
    char*** ans = malloc(strsSize * sizeof(char**));
    *returnColumnSizes = malloc(strsSize * sizeof(int));
    for (i = 1; i < strsSize; i++) {
        if (lenTable[i][2] == lenTable[i-1][2]) cn++;
        else {
            ans[idx] = malloc(cn * sizeof(char*));
            (*returnColumnSizes)[idx] = cn;
            for (j = 0; j < cn; j++) ans[idx][j] = strdup(strs[lenTable[i-1-j][0]]);
            idx++;
            cn = 1;
        }
    }
    ans[idx] = malloc(cn * sizeof(char*));
    (*returnColumnSizes)[idx] = cn;
    for (j = 0; j < cn; j++) ans[idx][j] = strdup(strs[lenTable[strsSize-1-j][0]]);
    idx++;
    *returnSize = idx;
    
   
    
    return ans;
}
