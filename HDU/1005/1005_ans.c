import java.util.Scanner;
 
public class Main{
 
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (true){
            int a = input.nextInt();
            int b = input.nextInt();
            int n = input.nextInt();
 
            int [] num = new int [50];
 
            if (a == 0 && b == 0 && n == 0)
                break;
 
            num[0] = num[1] = 1;
            int i;
            for(i=2;i<50;i++)
            {
                num[i] = (a*num[i-1]+b*num[i-2])%7;
                if(num[i]==1&&num[i-1]==1)
                    break;
            }
            n %= (i-1);         // ¼´, n %= 49
            if (n == 0)
                System.out.println(num[i-2]);
            else
                System.out.println(num[n-1]);
 
        }
    }
}