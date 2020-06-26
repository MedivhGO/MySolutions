//https://www.hackerrank.com/challenges/java-comparator/problem
// Write your Checker class here
class Checker implements Comparator<Player> {
    public int compare(Player a1,Player a2) {
       if (a1.score == a2.score)
           return a1.name.compareTo(a2.name);
       else
           return a1.score > a2.score ? -1 : 1;
    }
}