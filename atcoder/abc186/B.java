import java.io.*;
import java.util.*;
public class Main {
        public static void main(String[] args)throws Exception {
                FastScanner fs = new FastScanner();
                PrintWriter out = new PrintWriter(System.out);
                int T = 1;
                // T = fs.nextInt();
                for (int tt = 0; tt < T; tt++) {
                        int n = fs.nextInt();
                        int m = fs.nextInt();
                        int sum = 0;
                        int val = Integer.MAX_VALUE;
                        for(int i = 0; i < n; i++){
                                for(int j = 0; j < m; j++){
                                        int x = fs.nextInt();
                                        val = Math.min(val, x);
                                        sum += x;
                                }
                        }
                        out.print(sum - (n * m * val))  ;
                }
                out.close();
        }



        static class FastScanner         {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                StringTokenizer st = new StringTokenizer("");
                String next() {
                        while (!st.hasMoreTokens())
                                try {
                                        st = new StringTokenizer(br.readLine());
                                } catch (IOException e) {
                                        e.printStackTrace();
                                }
                        return st.nextToken();
                }


                int nextInt() {
                        return Integer.parseInt(next());
                }
                int[] readArray(int n) {
                        int[] a = new int[n];
                        for (int i = 0; i < n; i++) a[i] = nextInt();
                        return a;
                }
                long nextLong() {
                        return Long.parseLong(next());
                }
                double nextDouble() {
                        return Double.parseDouble(next());
                }
        }


}
