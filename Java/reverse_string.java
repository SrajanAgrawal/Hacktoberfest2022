import java.io.*;
import java.util.Scanner;

class reverseST {
    public static void main (String[] args) {

        String str= "Rishabh", nstr="";
        char ch;

      System.out.print("Original word: ");
      System.out.println("Rishabh"); //Example word

      for (int i=0; i<str.length(); i++)
      {
        ch= str.charAt(i);
        nstr= ch+nstr;
      }
      System.out.println("Reversed word: "+ nstr);
    }
}
