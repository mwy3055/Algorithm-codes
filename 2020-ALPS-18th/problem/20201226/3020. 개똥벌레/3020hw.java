<<<<<<< HEAD
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static int[] arr1;
    private static int[] arr2;
    private static int[] result;
    public static int lowerBound(int[] arr, int target){
        int low = 0;
        int high = arr.length;
        while(low<high){
            int mid = low+(high-low)/2;
            if(target<=arr[mid]){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
    public static int upperBound(int[] arr, int target){
        int low = 0;
        int high = arr.length;
        while(low<high){
            int mid = low+(high-low)/2;
            if(target>=arr[mid]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
            int n = scan.nextInt();
            int h = scan.nextInt();
            int idx1 = 0; int idx2 = 0;
            //석순, 종유석 따로 저장
            arr1 = new int[n/2];
            arr2 = new int[n/2];
            result = new int[h];
        for(int i=0;i<n/2;i++){
            arr1[idx1++]=scan.nextInt();
            arr2[idx2++]=scan.nextInt();
        }
            //탐색을 위해 정렬
            Arrays.sort(arr1);
            Arrays.sort(arr2);
            //부셔야하는 장애물 구하기 - 높이(h)만큼 반복
        int temp = 0;
        for(int i=0;i<h;i++){
                //석순은 lower bound, 종유석은 upper bound
                temp = n/2- lowerBound(arr1, i+1);
                temp += n/2 - upperBound(arr2, h-(i+1));
                result[i] = temp;
            }
            //장애물 최솟값, 구간의 수 출력
            int cnt = 1;
            int min = Integer.MAX_VALUE;
            for(int i=0;i<h;i++){
                if(result[i]==min){
                    cnt++;
                }else if(result[i]<min){
                    min = result[i];
                    cnt = 1;
                }
            }
            System.out.println(min+" "+cnt);

        }

}
=======
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static int[] arr1;
    private static int[] arr2;
    private static int[] result;
    public static int lowerBound(int[] arr, int target){
        int low = 0;
        int high = arr.length;
        while(low<high){
            int mid = low+(high-low)/2;
            if(target<=arr[mid]){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
    public static int upperBound(int[] arr, int target){
        int low = 0;
        int high = arr.length;
        while(low<high){
            int mid = low+(high-low)/2;
            if(target>=arr[mid]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
            int n = scan.nextInt();
            int h = scan.nextInt();
            int idx1 = 0; int idx2 = 0;
            //석순, 종유석 따로 저장
            arr1 = new int[n/2];
            arr2 = new int[n/2];
            result = new int[h];
        for(int i=0;i<n/2;i++){
            arr1[idx1++]=scan.nextInt();
            arr2[idx2++]=scan.nextInt();
        }
            //탐색을 위해 정렬
            Arrays.sort(arr1);
            Arrays.sort(arr2);
            //부셔야하는 장애물 구하기 - 높이(h)만큼 반복
        int temp = 0;
        for(int i=0;i<h;i++){
                //석순은 lower bound, 종유석은 upper bound
                temp = n/2- lowerBound(arr1, i+1);
                temp += n/2 - upperBound(arr2, h-(i+1));
                result[i] = temp;
            }
            //장애물 최솟값, 구간의 수 출력
            int cnt = 1;
            int min = Integer.MAX_VALUE;
            for(int i=0;i<h;i++){
                if(result[i]==min){
                    cnt++;
                }else if(result[i]<min){
                    min = result[i];
                    cnt = 1;
                }
            }
            System.out.println(min+" "+cnt);

        }

}
>>>>>>> 68196bb61d126f1040cb1bf7ba5b2922d3fba073
