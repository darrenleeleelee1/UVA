import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String strInput;
        StringBuilder strReverse, strMirrored;
        boolean Palindrome, Mirrored;
        while(input.hasNextLine()){
            Palindrome = Mirrored = false;
            strInput = input.nextLine();
            strReverse = new StringBuilder(strInput).reverse();
            strMirrored = new StringBuilder("");
            if(strInput.equals(strReverse.toString())) Palindrome = true;
            for(int i = 0; i < strInput.length(); i++){
                if(strInput.charAt(i) == 'E') strMirrored.append('3');
                else if(strInput.charAt(i) == '3') strMirrored.append('E');
                else if(strInput.charAt(i) == 'J') strMirrored.append('L');
                else if(strInput.charAt(i) == 'L') strMirrored.append('J');
                else if(strInput.charAt(i) == 'S') strMirrored.append('2');
                else if(strInput.charAt(i) == '2') strMirrored.append('S');
                else if(strInput.charAt(i) == 'Z') strMirrored.append('5');
                else if(strInput.charAt(i) == '5') strMirrored.append('Z');
                else if(strInput.charAt(i) == 'A') strMirrored.append('A');
                else if(strInput.charAt(i) == 'H') strMirrored.append('H');
                else if(strInput.charAt(i) == 'I') strMirrored.append('I');
                else if(strInput.charAt(i) == 'M') strMirrored.append('M');
                else if(strInput.charAt(i) == 'O') strMirrored.append('O');
                else if(strInput.charAt(i) == 'T') strMirrored.append('T');
                else if(strInput.charAt(i) == 'U') strMirrored.append('U');
                else if(strInput.charAt(i) == 'V') strMirrored.append('V');
                else if(strInput.charAt(i) == 'W') strMirrored.append('W');
                else if(strInput.charAt(i) == 'X') strMirrored.append('X');
                else if(strInput.charAt(i) == 'Y') strMirrored.append('Y');
                else if(strInput.charAt(i) == '1') strMirrored.append('1');
                else if(strInput.charAt(i) == '8') strMirrored.append('8');
                else {
                    Mirrored = false;
                    break;
                }
            }
            if(strReverse.toString().equals(strMirrored.toString())) Mirrored = true;
            
            if(Palindrome && Mirrored) System.out.println(strInput  + " -- is a mirrored palindrome.");
            else if(Palindrome && !Mirrored) System.out.println(strInput  + " -- is a regular palindrome.");
            else if(!Palindrome && Mirrored) System.out.println(strInput  + " -- is a mirrored string.");
            else System.out.println(strInput  + " -- is not a palindrome.");
            System.out.println("");
            

        }
        
    }
}