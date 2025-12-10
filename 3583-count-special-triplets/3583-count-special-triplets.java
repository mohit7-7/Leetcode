class Solution {
    int mod = (int)1e9+7;
    public int specialTriplets(int[] nums) {
        long count=0;
        HashMap<Integer, Integer>right = new HashMap<>();
        HashMap<Integer, Integer>left = new HashMap<>();
        for (int num : nums) {
            right.put(num, right.getOrDefault(num, 0) + 1);
        }

        for(int num: nums){
            right.put(num, right.get(num) - 1);
            if(right.get(num)==0) right.remove(num);
            int target = num*2;
            if(left.containsKey(target) && right.containsKey(target)){
                long ways = (long)left.get(target) * right.get(target);
                count = (count + ways)%mod;
            }
            left.put(num, left.getOrDefault(num, 0) + 1);
        }
        return (int)count;
    }
}