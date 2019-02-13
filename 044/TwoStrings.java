import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the twoStrings function below.
    static String twoStrings(String s1, String s2) {
        boolean result = false;
        String s1_no_repeated = "";
        String s2_no_repeated = "";
        for( int i = 0; i < s1.length(); ++i )
        {
            if ( !s1_no_repeated.contains( String.valueOf( s1.charAt(i) ) ) )
            {
                s1_no_repeated += String.valueOf( s1.charAt(i) );
            }
        }
        for( int i = 0; i < s2.length(); ++i )
        {
            if ( !s2_no_repeated.contains( String.valueOf( s2.charAt(i) ) ) )
            {
                s2_no_repeated += String.valueOf( s2.charAt(i) );
            }
        }
        /*
        for( int i = 0; i < s1.length(); ++i )
        {
            if ( s2.contains( String.valueOf( s1.charAt(i) ) ) )
            {
                result = true;
                break;
            }
        }*/
        for ( Character c : s1.toCharArray() ){
           if ( -1 != s2.indexOf( c ) ) {
               result = true;
               break;
           } 
        }
        
        return result ? "YES" : "NO";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s1 = scanner.nextLine();

            String s2 = scanner.nextLine();

            String result = twoStrings(s1, s2);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
