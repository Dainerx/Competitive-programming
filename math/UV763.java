package cp;

import java.math.BigInteger;
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

public class Cp {

    private static Map<Integer, BigInteger> memo = new HashMap<>();
    private static Vector<BigInteger> numbers = new Vector<>();

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        for (int i = 2; i < 100; i++) {
            numbers.add(fib(i));
        }

        while (scanner.hasNextLine()) {
            String line0 = scanner.nextLine();
            String line1 = scanner.nextLine();
            String line2 = scanner.nextLine();
            BigInteger x = convert(line0);
            BigInteger y = convert(line1);
            x = x.add(y);
            System.out.println(find(x));
            System.out.println();
        }

    }

    public static BigInteger convert(String s) {
        BigInteger result = BigInteger.ZERO;
        for (int i = 0; i < s.length(); i++) {
            Integer x = Character.getNumericValue(s.charAt(i));
            BigInteger bi = BigInteger.valueOf(x);
            result = result.add(numbers.elementAt(s.length() - i - 1).multiply(bi));
        }
        return result;
    }

    public static StringBuilder find(BigInteger x) {
        int index = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (x.compareTo(numbers.elementAt(i)) < 0) {
                index = i;
                break;
            }
        }

        StringBuilder result = new StringBuilder("");
        boolean firstTime = false;
        int j = index - 1;
        int indexEndString = 0;
        while (x.compareTo(BigInteger.ZERO) > 0) {
            BigInteger y = x.subtract(numbers.elementAt(j));
            if (y.compareTo(BigInteger.ZERO) >= 0) {
                if (firstTime == false) {
                    indexEndString = j + 1;
                    for (int i = 0; i <= indexEndString - 1; i++) {
                        result.append("0");
                    }
                }

                firstTime = true;
                x = y;
                result.setCharAt(result.length() - j - 1, '1');
            }
            j--;
        }

        return result;
    }

    public static BigInteger fib(int n) {
        if (n == 0) {
            return BigInteger.ZERO;
        }

        if (n == 1) {
            return BigInteger.ONE;
        }

        if (memo.containsKey(n)) {
            return memo.get(n);
        }

        memo.put(n, fib(n - 2).add(fib(n - 1)));
        return fib(n - 2).add(fib(n - 1));
    }
}
