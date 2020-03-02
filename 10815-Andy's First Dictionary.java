import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        String[] arr = new String[5000];
        Scanner input = new Scanner(System.in);
        int index = 0;
        while(input.hasNext()){
            arr[index++] = input.next();
        }
        for(int i = 0; i < index; i++){
            System.out.println(arr[i]);
        }
    }
}