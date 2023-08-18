<<<<<<< HEAD
import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int A = scan.nextInt();
        int B = scan.nextInt();
        int[][] map = new int[B][A];

        String[] rightRota = {"N","E","S","W"};
        String[] leftRota = {"N","W","S","E"};
        int N = scan.nextInt();
        int M = scan.nextInt();
        String[] dir = new String[N];
        int[][] rbt = new int[N][2];

        int x,y;
        for(int i=0;i<N;i++){
            x = scan.nextInt()-1;
            y = scan.nextInt()-1;
            rbt[i][0]=x; rbt[i][1]=y;
            map[y][x] = i+1;
            dir[i] = scan.next();
        }
        //명령
        for(int i=0;i<M;i++){
            int robot = scan.nextInt();
            String order = scan.next();
            int cnt = scan.nextInt();
            y = rbt[robot-1][0];
            x = rbt[robot-1][1];
            switch (order){
                case "F":{//앞으로전진
                    try{
                        switch (dir[robot-1]){
                            case "W":{ //왼쪽방향
                                for(int j=0;j<cnt;j++){
                                    if(map[y][x-j-1]!=0 && map[y][x-j-1]!=robot){
                                        System.out.println("Robot "+robot+" crashes into robot "+map[y][x-j-1]);
                                        return;
                                    }
                                    map[y][x-j-1] = robot;
                                    rbt[robot-1][1] = x-j-1;
                                }
                                break;
                            }
                            case "E":{//오른쪽
                                for(int j=0;j<cnt;j++){
                                    if(map[y][x+j+1]!=0&& map[y][x+j+1]!=robot){
                                        System.out.println("Robot "+robot+" crashes into robot "+map[y][x+j+1]);
                                        return;
                                    }
                                    map[y][x+j+1] = robot;
                                    rbt[robot-1][1] = x+j+1;
                                }
                                break;
                            }
                            case "N":{//위
                                for(int j=0;j<cnt;j++){
                                    if(map[y-j-1][x]!=0&& map[y-j-1][x]!=robot){
                                        System.out.println("Robot "+robot+" crashes into robot "+map[y-j-1][x]);
                                        return;
                                    }
                                    map[y-j-1][x] = robot;
                                    rbt[robot-1][0] = y-j-1;
                                }
                                break;
                            }
                            case "S":{//아래
                                for(int j=0;j<cnt;j++){
                                    if(map[y+j+1][x]!=0 && map[y+j+1][x]!=robot){
                                        System.out.println("Robot "+robot+" crashes into robot "+map[y+j+1][x]);
                                        return;
                                    }
                                    map[y+j+1][x] = robot;
                                    rbt[robot-1][0] =y+j+1;
                                }
                                break;
                            }
                        }
                    } catch(ArrayIndexOutOfBoundsException e){
                        System.out.println("Robot "+robot+" crashes into the wall");
                        return;
                    }
                    break;
                }
                case "L":{
                    switch (dir[robot-1]){
                        case "N": dir[robot-1] = leftRota[cnt%4]; break;
                        case "S": dir[robot-1] = leftRota[(2+cnt)%4]; break;
                        case "E": dir[robot-1] = rightRota[(1+cnt)%4]; break;
                        case "W": dir[robot-1] = rightRota[(3+cnt)%4]; break;
                    }
                    break;
                }
                case "R":{
                    switch (dir[robot-1]){
                        case "N": dir[robot-1] = rightRota[cnt%4]; break;
                        case "S": dir[robot-1] = rightRota[(2+cnt)%4]; break;
                        case "E": dir[robot-1] = leftRota[(3+cnt)%4]; break;
                        case "W": dir[robot-1] = leftRota[(1+cnt)%4]; break;
                    }
                    break;
                }
            }
        }
        System.out.println("OK");
    }
=======
import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int A = scan.nextInt();
        int B = scan.nextInt();
        int[][] map = new int[B][A];

        String[] rightRota = {"N","E","S","W"};
        String[] leftRota = {"N","W","S","E"};
        int N = scan.nextInt();
        int M = scan.nextInt();
        String[] dir = new String[N];
        int[][] rbt = new int[N][2];

        int x,y;
        for(int i=0;i<N;i++){
            x = scan.nextInt()-1;
            y = scan.nextInt()-1;
            rbt[i][0]=x; rbt[i][1]=y;
            map[y][x] = i+1;
            dir[i] = scan.next();
        }
        //명령
        for(int i=0;i<M;i++){
            int robot = scan.nextInt();
            String order = scan.next();
            int cnt = scan.nextInt();
            y = rbt[robot-1][0];
            x = rbt[robot-1][1];
            switch (order){
                case "F":{//앞으로전진
                    try{
                        switch (dir[robot-1]){
                            case "W":{ //왼쪽방향
                                for(int j=0;j<cnt;j++){
                                    if(map[y][x-j-1]!=0 && map[y][x-j-1]!=robot){
                                        System.out.println("Robot "+robot+" crashes into robot "+map[y][x-j-1]);
                                        return;
                                    }
                                    map[y][x-j-1] = robot;
                                    rbt[robot-1][1] = x-j-1;
                                }
                                break;
                            }
                            case "E":{//오른쪽
                                for(int j=0;j<cnt;j++){
                                    if(map[y][x+j+1]!=0&& map[y][x+j+1]!=robot){
                                        System.out.println("Robot "+robot+" crashes into robot "+map[y][x+j+1]);
                                        return;
                                    }
                                    map[y][x+j+1] = robot;
                                    rbt[robot-1][1] = x+j+1;
                                }
                                break;
                            }
                            case "N":{//위
                                for(int j=0;j<cnt;j++){
                                    if(map[y-j-1][x]!=0&& map[y-j-1][x]!=robot){
                                        System.out.println("Robot "+robot+" crashes into robot "+map[y-j-1][x]);
                                        return;
                                    }
                                    map[y-j-1][x] = robot;
                                    rbt[robot-1][0] = y-j-1;
                                }
                                break;
                            }
                            case "S":{//아래
                                for(int j=0;j<cnt;j++){
                                    if(map[y+j+1][x]!=0 && map[y+j+1][x]!=robot){
                                        System.out.println("Robot "+robot+" crashes into robot "+map[y+j+1][x]);
                                        return;
                                    }
                                    map[y+j+1][x] = robot;
                                    rbt[robot-1][0] =y+j+1;
                                }
                                break;
                            }
                        }
                    } catch(ArrayIndexOutOfBoundsException e){
                        System.out.println("Robot "+robot+" crashes into the wall");
                        return;
                    }
                    break;
                }
                case "L":{
                    switch (dir[robot-1]){
                        case "N": dir[robot-1] = leftRota[cnt%4]; break;
                        case "S": dir[robot-1] = leftRota[(2+cnt)%4]; break;
                        case "E": dir[robot-1] = rightRota[(1+cnt)%4]; break;
                        case "W": dir[robot-1] = rightRota[(3+cnt)%4]; break;
                    }
                    break;
                }
                case "R":{
                    switch (dir[robot-1]){
                        case "N": dir[robot-1] = rightRota[cnt%4]; break;
                        case "S": dir[robot-1] = rightRota[(2+cnt)%4]; break;
                        case "E": dir[robot-1] = leftRota[(3+cnt)%4]; break;
                        case "W": dir[robot-1] = leftRota[(1+cnt)%4]; break;
                    }
                    break;
                }
            }
        }
        System.out.println("OK");
    }
>>>>>>> 68196bb61d126f1040cb1bf7ba5b2922d3fba073
}