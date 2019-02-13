import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static int count ;
    // Complete the journeyToMoon function below.
    static int journeyToMoon(int n, int[][] astronaut) {
        
        ArrayList<Integer>[] a = (ArrayList<Integer>[]) new ArrayList[n ]; 
        for (int i = 0; i < n; i++) 
        { 
            a[i] = new ArrayList<>(); 
        } 

        for (int i = 0; i < astronaut.length; i++) 
        { 
            int v1 = astronaut[i][0]; 
            int v2 = astronaut[i][1]; 
            a[v1].add(v2); 
            a[v2].add(v1); 
        }
        for( int i = 0; i < a.length; ++i )
        {
            a[i].removeIf(Objects::isNull);   
        }
       
      // ArrayList<Integer>[] countrySizes =  new ArrayList[ n ];
      int[] countrySizes = new int[n]; 
        boolean[] c = new boolean[n ];
        for( int i = 0;i < a.length; ++i )
        {
            count =0;
            dfs( a, c, i);
            countrySizes[i] = count;
          //  System.out.print( "\n" + count  );
        }


    int sum = 0;
    int  result = 0;
    for(int size : countrySizes)
    {
        result += sum*size;
        sum += size;    
    }   
    return result;

    }
    
    public static void dfs(ArrayList<Integer>[] a, boolean[] c, int v ) {

        if (c[v]) {
            return;
        }
        c[v] = true;
      //  System.out.print(v + " ");
        ++Solution.count;
        for (int vv : a[v]) {

            if (!c[vv]) {
                dfs(a, c, vv);
            }

        }

    }
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] np = scanner.nextLine().split(" ");

        int n = Integer.parseInt(np[0]);

        int p = Integer.parseInt(np[1]);

        int[][] astronaut = new int[p][2];

        for (int i = 0; i < p; i++) {
            String[] astronautRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 2; j++) {
                int astronautItem = Integer.parseInt(astronautRowItems[j]);
                astronaut[i][j] = astronautItem;
            }
        }

        int result = journeyToMoon(n, astronaut);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
