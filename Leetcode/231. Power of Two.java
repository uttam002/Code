class Solution {
    public boolean isPowerOfTwo(int n) {
    if(n<1){
        return false;
    }
    int p=(int)(Math.log(n)/Math.log(2));
    return Math.pow(2,p)==n;

    }
}
