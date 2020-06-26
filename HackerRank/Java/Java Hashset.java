//https://www.hackerrank.com/challenges/java-hashset/problem
HashSet<String> hs = new HashSet<>();
for(int i=0; i < t; i++) {
    String ad = "("+pair_left[i]+","+pair_right[i]+")";
    hs.add(ad);
    System.out.println(hs.size());
}


