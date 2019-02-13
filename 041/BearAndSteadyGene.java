import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the steadyGene function below.
    static int steadyGene(String gene) {
        int limit_count = gene.length() / 4;
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        map.put('A', 0);
        map.put('C', 0);
        map.put('T', 0);
        map.put('G', 0);

        for( int i = 0; i < gene.length(); ++i )
        {
            char gene_char = gene.charAt(i);
            map.put( gene_char, map.get( gene_char ) + 1 );
        }
        for( int i = 0; i < map.size(); ++i )
        {
            
        }
        int min_index = 0, max_index = 0;


        return 0;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String gene = scanner.nextLine();

        int result = steadyGene(gene);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
