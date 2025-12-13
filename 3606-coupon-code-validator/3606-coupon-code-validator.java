class Solution {
    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {

        Map<String, List<String>> map = new HashMap<>();
        map.put("electronics", new ArrayList<>());
        map.put("grocery", new ArrayList<>());
        map.put("pharmacy", new ArrayList<>());
        map.put("restaurant", new ArrayList<>());

        for (int i = 0; i < code.length; i++) {
            if (
                isActive[i] &&
                code[i].matches("[a-zA-Z0-9_]+") &&
                map.containsKey(businessLine[i])
            ) {
                map.get(businessLine[i]).add(code[i]);
            }
        }

        List<String> ans = new ArrayList<>();

        String[] order = {"electronics", "grocery", "pharmacy", "restaurant"};
        for (String b : order) {
            Collections.sort(map.get(b));
            ans.addAll(map.get(b));
        }

        return ans;
    }
}
