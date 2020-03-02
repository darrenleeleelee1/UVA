import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int count = input.nextInt();
        int size;
        int[] train = new int[51];
        for(int times = 0; times < count ; times++){
            size = input.nextInt();
            int counter = 0;
            for (int i = 1; i <= size; i++) {
                train[i] = input.nextInt();
            }
            for (int i = 1; i <= size-1; i++) {
                for (int j = i+1; j <= size; j++) {
                    if(train[i] > train[j]){
                        int temp = train[i];
                        train[i] = train[j];
                        train[j] = temp;
                        counter++; 
                    }
                }
            }
            System.out.println("Optimal train swapping takes " + counter + " swaps.");
        }
    }
}