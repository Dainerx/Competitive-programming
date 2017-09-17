import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

// The part of the program involving reading from STDIN and writing to STDOUT has been provided by us.
public class Solution {

    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static boolean subset(int[] numbers) {
        for (int i = 1; i < numbers.length; i++) {
            numbers[i] = gcd(numbers[i - 1], numbers[i]);
            if (gcd(numbers[i - 1], numbers[i]) == 1) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws NumberFormatException, IOException {

        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int i = 0; i < T; i++) {
            int N = scanner.nextInt();
            int[] array = new int[N];
            for (int j = 0; j < N; j++) {
                int a;
                a = scanner.nextInt();
                array[j] = a;
            }

            if (subset(array)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }

    }
}
