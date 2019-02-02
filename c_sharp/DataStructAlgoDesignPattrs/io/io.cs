using System;

public class Class1
{
	public static void Main(string[] args)
	{
			string input_str = Console.ReadLine();
			// to read an integer
			string input_int = Console.ReadLine();
			// TryParse returns a boolean value to indicate
			// the status of the parse
			if (int.TryParse(input_int, out int number)){
				Console.WriteLine("Integer parsed: {0}", number);
			} else {
				Console.WriteLine("Error parsing the int");
			}
			for(int i = 0; i < number; i++){
    	    	Console.WriteLine("Cola");
			}

			// Formatted output
			/// Fill with spaces
			int k = 23;
			Console.WriteLine("{0,4}", k);
			Console.WriteLine("{0,3}", k);
			Console.WriteLine("{0,2}", k);
			Console.WriteLine("{0,1}", k);
			Console.WriteLine("{0}", k);
	}
}
