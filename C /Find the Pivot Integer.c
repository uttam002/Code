int pivotInteger(int n) {
    for (int i=1; i<=n; i++){
        int lsum=(i*(i+1)/2);
        int rsum=(n*(n+1)/2) - lsum + i;
        if (lsum==rsum) return i;
    } return -1;
}
