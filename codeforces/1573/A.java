import java.io.*;
import java.util.*;
public class Main {
        public static void main(String[] args)throws Exception {
                FastScanner fs = new FastScanner();
                PrintWriter out = new PrintWriter(System.out);
                int T = 1;
                T = fs.nextInt();

                for (int tt = 0; tt < T; tt++) {
                        int n = fs.nextInt();
                        String s = fs.next();

                        int ans = s.charAt(n - 1) - '0';
                        for(int i = 0; i < n - 1; i++){
                                if(s.charAt(i) != '0')
                                        ans += s.charAt(i) - '0' + 1;
                        }
                        out.println(ans);

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
