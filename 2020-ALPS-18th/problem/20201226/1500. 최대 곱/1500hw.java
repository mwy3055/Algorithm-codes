<<<<<<< HEAD
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*1500번 최대곱
  곱하는 수의 차이가 가장 작게*/
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        List<Long> list = new ArrayList<>();
        long result = 1;
        long s = scan.nextInt();
        long k = scan.nextInt();
        long div = s/k;
        long res = s%k;

        //몫을 k개만큼 저장
        for(int i=0;i<k;i++){
            list.add(div);
        }
        //나머지만큼만 1씩 더함
        for(int i=0;i<res;i++){
            list.set(i,(list.get(i)+1));
        }
        for(int i=0;i<list.size();i++){
            result *= list.get(i);
        }

        System.out.println(result);
    }
}
=======
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*1500번 최대곱
  곱하는 수의 차이가 가장 작게*/
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        List<Long> list = new ArrayList<>();
        long result = 1;
        long s = scan.nextInt();
        long k = scan.nextInt();
        long div = s/k;
        long res = s%k;

        //몫을 k개만큼 저장
        for(int i=0;i<k;i++){
            list.add(div);
        }
        //나머지만큼만 1씩 더함
        for(int i=0;i<res;i++){
            list.set(i,(list.get(i)+1));
        }
        for(int i=0;i<list.size();i++){
            result *= list.get(i);
        }

        System.out.println(result);
    }
}
>>>>>>> 68196bb61d126f1040cb1bf7ba5b2922d3fba073
