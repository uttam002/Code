int get_location_length(char *pos) {
    int cnt = 0;
    while(pos[cnt] != '/' && pos[cnt] != '\0') {
        cnt++;
    }
    return cnt;
}

typedef struct _subpath_struct_t {
    char *subpath;
    int len;
} subpath_struct_t;

subpath_struct_t *sub_path(char *path, int l) {
    char *sub_p = malloc(sizeof(char)*l);
    memcpy(sub_p, path, sizeof(char)*l);
    subpath_struct_t *subpath_struct = malloc(sizeof(subpath_struct_t));
    subpath_struct->subpath = sub_p;
    subpath_struct->len = l;
    return subpath_struct;
}

char *simplifyPath(char *path) {
    int length = strlen(path);
    subpath_struct_t **pth = malloc(sizeof(subpath_struct_t **)*length);

    if(length <= 1) return path;
    
    int count = 0;
    int i_sub = 0;
    while(count < length) {
        int temp = get_location_length(&path[count]);
        if(temp != 0) {
            if(temp == 2 && path[count] == '.' && path[count+1] == '.') {
                if(i_sub == 0) {
                    path[0] = '/';
                }
                else {
                    i_sub--;
                    free(pth[i_sub]);
                }
            }
            else if(path[count] == '.' && temp == 1) {
                
            }
            else {
                pth[i_sub++] = sub_path(&path[count], temp);
                // printf("sub path: %s\n", pth[i_sub-1]->subpath);
            }
        }

        count += temp + 1;
    }

    int k = 1;
    
    for(int i=0;i<i_sub;i++) {
        // printf("%s\n", pth[i]->subpath);
        memcpy(&path[k], pth[i]->subpath, pth[i]->len*sizeof(char));
        free(pth[i]->subpath);

        k += pth[i]->len;
        path[k++] = '/';
    }
    if(i_sub == 0) {
        memset(path, 0, length);
        path[0] = '/';
    }
    else {
        path[k-1] = '\0';
    }
    
    free(pth);
    
    return path;
}
