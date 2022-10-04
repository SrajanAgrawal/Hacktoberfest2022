import java.util.Scanner;
public class stackgame {
    static int arr[];
    static int brr[];
    static int sum;
    static int top;
    static int t;

    stackgame(int a, int b) {
        arr = new int[a];
        brr = new int[b];
        top = 0;
        t = 0;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the sum");
        sum = sc.nextInt();
        System.out.println("Enter the Length of both the array");
        int m = sc.nextInt();
        int n = sc.nextInt();
        stackgame ob=new stackgame(m,n);
        System.out.println("Enter the element in the First stack");
        for (int i = 0; i < m; i++)
            arr[i] = sc.nextInt();
        System.out.println("Enter the Element in second stack");
        for (int i = 0; i < n; i++)
            brr[i] = sc.nextInt();
        int score=score();
        System.out.println("The result of the game is");
        System.out.println(score);
    }

    static int score()
    {
        int s = 0;
        int c = 0;
        while (s <= sum)
        {
            if (arr[top] <= brr[t])
            {
                s = s + arr[top];
                if (s < sum)
                {
                    pop(1);
                    c = c + 1;
                }
                else
                    break;
            }
            else
            {
                s=s+brr[t];
                if(s<sum)
                {
                    pop(2);
                    c=c+1;
                }
                else
                    break;
            }
        }
        return c;
    }
    static void pop(int a)
    {
        if(a==1)
        {
            top=top+1;
        }
        if(a==2)
        {
            t=t+1;
        }
    }
}
