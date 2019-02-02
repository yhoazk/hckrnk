using System;

public class arrays{
    public static void Main(string[] args){
        Console.WriteLine("Arrays");
        // Create an array
        int[] one_dim;
        // Assign the default init memory
        one_dim = new int[10];
        var length = one_dim.GetLength(0);
        Console.WriteLine($"Array len {length}");
        
    }
}