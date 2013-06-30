import java.math.*;
import java.util.*;

public class BigIntegerTest
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);

		System.out.println("How many number you need to draw??");
		System.out.print("> ");
		int draw = in.nextInt();

		System.out.println("What is the highest number you can draw??");
		System.out.print("> ");
		int total = in.nextInt();

		BigInteger lotteryOdds = BigInteger.valueOf(1);
		for(int i=1; i<=draw; i++)
		{
			lotteryOdds = lotteryOdds.multiply(BigInteger.valueOf(total - i + 1)).divide(BigInteger.valueOf(i));
		}

		System.out.println("Your odds are 1 in " + lotteryOdds + ". Good Luck!");
	}
}
