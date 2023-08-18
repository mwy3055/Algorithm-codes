import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        long[][] dp = new long[32][32];
        List<Integer> N = new ArrayList<>();
        //dp배열을 1로 초기화
        for(int i=0;i<dp.length;i++){ Arrays.fill(dp[i],1); }
        for(int w=1;w<31;w++){
            for(int h=0;h<31;h++){
                //반쪽알약이 없다면 큰알약만 먹을수있음
                if(h==0){ dp[w][h] = dp[w-1][1]; }
                //큰알약을 먹는경우, 반쪽알약하나가 추가 + 반쪽알약을 먹으면 반쪽알약-1,큰알약은 그대로
                else { dp[w][h] = dp[w-1][h+1] + dp[w][h-1]; }
            }
        }
        while(true){
            int n = scan.nextInt();
            if(n==0) break;
            N.add(n);
        }
        for(int idx: N){
            System.out.println(dp[idx][0]);
        }
    }
}