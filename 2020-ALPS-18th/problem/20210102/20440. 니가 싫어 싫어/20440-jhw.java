import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int[] sum = new int[2100000001];
        Arrays.fill(sum,0);
        int start, end;
        int max = 0;
        for(int i=0;i<N;i++){
            start = scan.nextInt();
            end = scan.nextInt();
            while(start<end){
                sum[start]++;
                if(sum[start]>max){
                    max = sum[start];
                }
                start++;
            }
        }
        start = -1; end = 0;
        int idx = 0;
        while(true){
            if(sum[idx]==max && start==-1) { start = idx; }
            if(sum[idx]!=max && start!=-1) { end = idx; break; }
            idx++;
        }

        System.out.println(max);
        System.out.println(start+" "+end);
    }
}