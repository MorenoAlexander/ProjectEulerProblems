/******************************************************************************
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.


Simple use of Java's useful BigInteger class

Reason being that the integers in the text file are far too large
for regular data types to hold.  
*******************************************************************************/
import java.util.Scanner;
import java.io.File;
import java.math.BigInteger;
import java.io.FileNotFoundException;
public class PE13
{
	public static void main(String[] args) {

		//Initialize the file we need.
		File dataFile = new File("sumfile.txt");
		try{
		    
		
		Scanner dataScanner = new Scanner(dataFile);
	    dataScanner.useDelimiter("\n");//Specify the delimiter we will use, assuming integers are stored in a 1 per line basis
		
		//Initialize SumVar
		BigInteger SumVar = new BigInteger("0");
		//Iterate through each line
		while(dataScanner.hasNextLine()){
		    //Retrieve the next line, then create a "BigInteger" with that value then add and assign to SumVar.
		    SumVar = SumVar.add(new BigInteger(dataScanner.nextLine()));
		}
		 String res = SumVar.toString();
		System.out.println(res + " is the result\n");
		
		return;
		
		
	}
	    catch(FileNotFoundException e){
	    System.out.println("Error, no file\n");
	    }
	}
	
}
