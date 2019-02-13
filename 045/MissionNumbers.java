import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the missingNumbers function below.
    static List<Integer> missingNumbers(int[] arr, int[] brr) {
        
        Arrays.sort( arr );
        Arrays.sort( brr );
        int count = brr.length - arr.length;
        List<Integer> result = new ArrayList<Integer>();

        int i = 0, j = 0;
        while( true ) {
            if ( count == 0 ) {
                break;
            }
            if ( arr[ i ] < brr[ j ] ){
                --j;
                --count;
                if ( result.size() > 1 && arr[ i ] == result.get(result.size() - 1) ) {
                    continue;
                }
                else {
                    result.add( arr[i] );
                }
            }
            else if ( arr[ i ] > brr[ j ] ) {
                --i;
                --count;
                if ( result.size() > 1 && brr[ j ] == result.get(result.size() - 1) ) {
                    continue;
                }
                else{
                    result.add( brr[j]);
                }
            }
            ++i;
            ++j;
        }
        
        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int m = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] brr = new int[m];

        String[] brrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            int brrItem = Integer.parseInt(brrItems[i]);
            brr[i] = brrItem;
        }

        List<Integer> result = missingNumbers(arr, brr);

        for( int a : result ) {
            bufferedWriter.write(String.valueOf(a) );
            bufferedWriter.write(" ");
            
        }

        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
