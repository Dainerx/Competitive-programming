package cp;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

// The part of the program involving reading from STDIN and writing to STDOUT has been provided by us.
public class Solution {

    public static int radios(int[] houses, int n, int k) {
        int i = 0, count = 0;
        Arrays.sort(houses);
        while (i < n) {
            count++;

            //we take the house that can cover all the left;
            int loc = houses[i] + k;

            //we move to the index -1 of the chosen house
            while (i < n && houses[i] <= loc) {
                i++;
            }

            //we move the location to the right edge covered by the chosen house
            loc = houses[--i] + k;

            //move the index to that location
            while (i < n && houses[i] <= loc) {
                i++;
            }
        }
        return count;
    }

    public static void main(String[] args) throws NumberFormatException, IOException {

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] array = new int[n];
        int k = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int a;
            a = scanner.nextInt();
            array[i] = a;
        }
        System.out.println(radios(array, n, k));

    }
}
