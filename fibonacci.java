import java.util.Scanner;

class Main {
  public static void main(String args[]) {
  
  /*
  * this program receives an N number and returns the 
  * first N numbers in the fibonacci sequence.
  */

    Scanner input = new Scanner(System.in);
    
    String answer = "";
    int number1 = 0;
    int number2 = 1;
    boolean switchLoop = true;

    for (int range = input.nextInt();range>0;range--) {
      if (switchLoop) {
        answer += Integer.toString(number1)+" ";
        number1 += number2;
        switchLoop = false;
      }
      else if (!switchLoop) {
        answer += Integer.toString(number2)+" ";
        number2 += number1;
        switchLoop = true;
      }
    }
    System.out.println(answer.trim());
  }
}
