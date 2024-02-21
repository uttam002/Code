int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
        
        while (left < right) {
            left >>= 1; // Right shift left
            right >>= 1; // Right shift right
            shift++; // Increment shift to count common prefix bits
        }
        
        // Shift left by the number of common prefix bits
        return left << shift;
}
