//best for palindrome number 
import java.math.BigInteger;
import java.util.*;

public class spoj {
    public static String nextPalindrome(String num) {
        int len = num.length();
        String left = num.substring(0, len / 2);
        String middle = num.substring(len / 2, len - len / 2);
        String right = num.substring(len - len / 2);
        System.out.println(left+" "+middle+" "+right);
        if (right.compareTo(reverse(left)) < 0){
            System.out.println(" right"+left + middle + reverse(left));
            return left + middle + reverse(left);}

        String next = new BigInteger(left + middle).add(BigInteger.ONE).toString();
        System.out.println(next);
        return next.substring(0, left.length() + middle.length())
                + reverse(next).substring(middle.length());
    }

    private static String reverse(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc=new Scanner(System.in);

        int t=sc.nextInt();
        while(t>0){
            String input=sc.next();
            int i=0;
            while(i<input.length() && input.charAt(i)=='0'){
                i++;
            }
            input=input.substring(i);
            String ans=nextPalindrome(input);
            System.out.println(ans);

            t--;
        }
    }
}