import java.math.BigDecimal;
import java.util.*;
public class Main{
    public static void main(String[] args) {
        BigDecimal n1 = new BigDecimal("0");
        BigDecimal temp = new BigDecimal("1");
        String str, tempStr;

        Scanner input = new Scanner(System.in);
        
        while(true){
            tempStr = input.next();       
            if(tempStr.equals("0")) break;
            temp = new BigDecimal(tempStr);
            n1 = n1.add(temp);
        }
        
        System.out.println(n1);
    }
}