import java.util.Scanner;
import java.util.Stack;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int count = input.nextInt();
        String garbage = input.nextLine();
        String str;
        Stack<Character> myStack = new Stack<Character>(); 
        for(int times = 0; times < count; times++){
            boolean isTrue = true;
            str = input.nextLine();
            myStack.clear();
            for(int i = 0; i < str.length(); i++){
                if(str.charAt(i) == '(' || str.charAt(i) == '[')
                    myStack.push(str.charAt(i));
                else if(!myStack.isEmpty()){
                    if(str.charAt(i) == ')' && myStack.peek() == '(')
                        myStack.pop();
                    else if(str.charAt(i) == ']' && myStack.peek() == '[')
                        myStack.pop();            
                    else 
                        isTrue = false;
                }
                else
                    isTrue = false;
            }
            if(!isTrue || !myStack.isEmpty())
                System.out.println("No");
            else
                System.out.println("Yes");
        }
    }
}