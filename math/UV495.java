import java.math.BigInteger;
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
public class Main {
    private static Map<Integer, BigInteger> memo = new HashMap<>();
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int n;
        while(scanner.hasNext()) {
            n = scanner.nextInt();
            System.out.printf("The Fibonacci number for %d is %s\n", n, fib(n).toString());
        }
    }
    public static BigInteger fib(int n) {
        if (n == 0)
            return BigInteger.ZERO;
        
        if (n==1)
            return BigInteger.ONE;
            
        if (memo.containsKey(n)) {
            return memo.get(n);
        }
        memo.put(n, fib(n - 2).add(fib(n - 1)));
    return fib(n - 2).add(fib(n - 1));
}
}
