import java.math.BigDecimal;
import java.util.Scanner;


public class Main{
    public static void main(String[] args) {
        BigDecimal mul1, mul2;
        Scanner input = new Scanner(System.in);
        while(input.hasNextLine()){
            mul1 = new BigDecimal(input.nextLine());
            mul2 = new BigDecimal(input.nextLine());
            System.out.println(mul1.multiply(mul2));
        }
    }
}