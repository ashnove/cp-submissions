import java.io.*;
import java.util.*;
public class Main {
        public static void main(String[] args)throws Exception {
                FastScanner fs = new FastScanner();
                int T = 1;
                // T = fs.nextInt();
                for (int tt = 0; tt < T; tt++) {

                        String s = fs.next();
                        int n = s.length();
                        int cnt[] = new int[26];
                        for(int i = 0; i < n; i++){
                                ++cnt[s.charAt(i) - 'a'];
                        }
                        int odd=0;
                        for(int i = 0; i < 26; i++){
                                if((cnt[i] & 1) == 1)
                                        odd++;
                        }
                        if(odd <= 1)
                                System.out.println("First");
                        else if(odd % 2 == 0)
                                System.out.println("Second");
                        else
                                System.out.println("First");

                }
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
