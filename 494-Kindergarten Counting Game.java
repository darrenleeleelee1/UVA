import java.util.Scanner;
public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str;
        while(input.hasNextLine()){
            str = input.nextLine();
            boolean startWord = false;
            int counter = 0;
            for (int i = 0; i < str.length(); i++) {
                if(!startWord && Character.isLetter(str.charAt(i))){
                    counter++;
                    startWord = true;
                }
                else if(startWord && !Character.isLetter(str.charAt(i))) startWord = false;
            }
            System.out.println(counter);
        }
    }
}