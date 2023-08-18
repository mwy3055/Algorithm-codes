import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] arr = new int[N][];
        boolean[] check = new boolean[M];//램프on/off check
        int cnt = 0;
        Arrays.fill(check, false);

        for(int i=0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            arr[i] = new int[Integer.parseInt(st.nextToken())];
            for(int j=0;j<arr[i].length;j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for(int i=M;1<=i;i--){
            for(int idx=0;idx<N;idx++){
                if(arr[idx].length==i){
                    for(int j=0;j<arr[idx].length;j++){
                        check[arr[idx][j]-1] = true;
                    }
                    cnt++;
                }else{
                    continue;
                }
            }
        }
        if(cnt<=N-1) System.out.println(1);
        else System.out.println(0);
    }
}