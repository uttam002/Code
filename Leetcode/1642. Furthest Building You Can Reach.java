class Solution {    
    public int furthestBuilding(int[] arr, int b, int l) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int n = arr.length;
        for(int i=0; i<n-1; i++){
            int diff = arr[i+1]-arr[i];

            if(diff>0){
                pq.add(diff);
            }
            if(pq.size()>l){
                b = b-pq.remove();
            }
            if(b<0) return i;
        }
        return n-1;
    }
}
