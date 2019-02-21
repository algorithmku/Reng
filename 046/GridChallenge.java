import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the gridChallenge function below.
    static String gridChallenge(String[] grid) {

        int ascending = -1;
        for( int i = 0; i < grid.length; ++i ) {
            char[] tmp = grid[i].toCharArray();
            Arrays.sort( tmp );
            grid[ i ] = new String( tmp );
        }

        char base_char;
        for(  int x = 0; x < grid[0].length(); ++x ) {
            base_char = grid[ 0 ].charAt(x);
            for( int y = 1; y < grid.length ; ++y ) {
                if ( ascending == -1 ) {
                    if ( base_char > grid[ y ].charAt(x) ) ascending = 0;
                    if ( base_char < grid[ y ].charAt( x ) ) ascending = 1;
                }
                
                if ( ascending == 0 && ( base_char < grid[ y ].charAt( x ) ) ) return "NO";
                if ( ascending == 1 && ( base_char > grid[ y ].charAt( x ) ) ) return "NO";  
                base_char = grid[ y ].charAt(x);
            }
        }

        return "YES";

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            String[] grid = new String[n];

            for (int i = 0; i < n; i++) {
                String gridItem = scanner.nextLine();
                grid[i] = gridItem;
            }

            String result = gridChallenge(grid);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
