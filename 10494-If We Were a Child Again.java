import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        BigDecimal op1, op2;
        String operand;
        while(input.hasNext()){
            op1 = new BigDecimal(input.next());
            operand = input.next();
            op2 = new BigDecimal(input.next());
            //System.out.println(op1.toString() + operand + op2);
            
            switch(operand){
                case "+" :
                    System.out.println(op1.add(op2));
                    break;
                case "-" :
                    System.out.println(op1.subtract(op2));
                    break;
                case "*" :
                    System.out.println(op1.multiply(op2));
                    break;
                case "/" :
                    System.out.println(op1.divide(op2, RoundingMode.DOWN));
                    break;
                case "%" :
                    System.out.println(op1.remainder(op2));
                    break;
            }
        

        }
    }
}