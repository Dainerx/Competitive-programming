import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

// The part of the program involving reading from STDIN and writing to STDOUT has been provided by us.
public class Solution {

    public static int unfair(List<Integer> numbers, int k) {
        Collections.sort(numbers);

        int unfairness = Integer.MAX_VALUE;

        for (int i=0; i<numbers.size()-k+1; i++)
            unfairness = Math.min(unfairness, numbers.get(i+k-1) - numbers.get(i));

        return unfairness;
    }

    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        int K = Integer.parseInt(in.readLine());
        List<Integer> numbers = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            int b = Integer.parseInt(in.readLine());
            numbers.add(b);
        }

        int unfairness = unfair(numbers, K);
        System.out.println(unfairness);
    }
}
