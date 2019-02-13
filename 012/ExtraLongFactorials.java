import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.math.BigInteger;
public class Solution {
    // Complete the extraLongFactorials function below.
    static BigInteger extraLongFactorials( BigInteger n) {
        if ( n.compareTo( BigInteger.valueOf( 1 ) ) == 0 )
        {
            return BigInteger.valueOf( 1 );
        }
        return n.multiply( extraLongFactorials( n.subtract( BigInteger.valueOf( 1 ) ) ) );
    }
    private static final Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
        BigInteger result = extraLongFactorials( BigInteger.valueOf( n ) );
        System.out.print( result );
        scanner.close();
    }
}