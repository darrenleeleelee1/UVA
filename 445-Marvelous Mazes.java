import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str;
        int count = 0;
        while(input.hasNextLine()){
            str = input.nextLine();
            for (int i = 0; i < str.length(); i++) {
                if(str.charAt(i) == '!') System.out.println("");
                else if(Character.isAlphabetic(str.charAt(i))) {
                    if(str.charAt(i) == 'b'){
                        for(int j = 0; j < count; j++){
                            System.out.print(" ");
                        }
                    }
                    else{
                        for(int j = 0; j < count; j++){
                            System.out.print(str.charAt(i));
                        }
                    }
                    count  = 0;
                }
                else if(str.charAt(i) == '*'){
                    for(int j = 0; j < count; j++){
                        System.out.print(str.charAt(i));
                    }
                    count = 0;
                }
                else{
                    count += ((int)str.charAt(i) - 48);
                }
            }
            System.out.println("");
        }
    }
}