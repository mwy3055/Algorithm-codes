import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int[][] input = new int[11][100001];
        int[][] dp = new int[11][100001];
        int N = scan.nextInt();
        int M = scan.nextInt();
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                input[i][j] = scan.nextInt();
            }
        }
        for(int i=0;i<M;i++){
            dp[i][0] = input[i][0];
        }

        int max, temp;
        for(int j=1;j<N;j++){
            for(int i=0;i<M;i++){
                max = 0;
                for(int k=0;k<M;k++){
                    if(i==k){ temp = dp[k][j-1]+input[i][j]/2; }
                    else { temp = dp[k][j-1]+input[i][j]; }
                    if(max<temp){
                        max = temp;
                        dp[i][j] = max;
                    }
                }
            }
        }
        max = 0;
        for(int i=0;i<M;i++){
            if(max<dp[i][N-1]){
                max = dp[i][N-1];
            }
        }
        System.out.println(max);
    }
}