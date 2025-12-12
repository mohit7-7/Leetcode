import java.util.*;

class Solution {
    void applyMsg(List<String> event, int[] mentions, int[] offline) {
        int time = Integer.parseInt(event.get(1));
        String[] tokens = event.get(2).split(" ");
        for (String id : tokens) {
            if (id.equals("ALL")) {
                for (int i = 0; i < mentions.length; i++) {
                    mentions[i]++;
                }
            } 
            else if (id.equals("HERE")) {
                for (int i = 0; i < mentions.length; i++) {
                    // offline[i] == -1 means "never offline"
                    if (offline[i] == -1 || offline[i] + 60 <= time) {
                        mentions[i]++;
                    }
                }
            } 
            else {
                int idx = Integer.parseInt(id.substring(2));
                mentions[idx]++;
            }
        }
    }

    public int[] countMentions(int n, List<List<String>> events) {

        // sort by time, then type lexicographically
        events.sort((v1, v2) -> {
            int t1 = Integer.parseInt(v1.get(1));
            int t2 = Integer.parseInt(v2.get(1));
            if (t1 != t2) return t1 - t2;
            return v2.get(0).compareTo(v1.get(0));
        });

        int[] mentions = new int[n];
        int[] offline = new int[n];

        // initialize offline times to -1 (never offline)
        Arrays.fill(offline, -1);

        for (List<String> event : events) {
            String type = event.get(0);

            if (type.equals("MESSAGE")) {
                applyMsg(event, mentions, offline);
            } 
            else if (type.equals("OFFLINE")) {
                int time = Integer.parseInt(event.get(1));
                int id = Integer.parseInt(event.get(2));
                offline[id] = time;
            }
        }

        return mentions;
    }
}
