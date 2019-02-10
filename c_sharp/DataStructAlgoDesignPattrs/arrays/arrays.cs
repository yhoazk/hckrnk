using System;

public class arrays{
    public static void Main(string[] args)
    {
        Console.WriteLine("Arrays");
        // Create an array
        int[] one_dim;
        // Assign the default init memory
        one_dim = new int[10];
        var length = one_dim.GetLength(0);
        //Console.WriteLine($"Array len {length}");
        Console.WriteLine("Teco");
        Console.ForegroundColor = ConsoleColor.Blue;
        Console.BackgroundColor = ConsoleColor.Red;
        Console.WriteLine("Teco");
        Console.ResetColor();
       // Console.OutputEncoding = UTF8Encoding.UTF8;
       // Console.OutputEncoding.
        PrintColorsInColor();
        one_dim_array();
        two_dim_array();
        jagged_arrays();
    }

    private static void one_dim_array(){
        float[] one_dim = {3.14f, 2.71f, 1.4142f};
        Console.WriteLine("One dimension array");
        Console.WriteLine(one_dim.GetType());
    }

    private static void two_dim_array(){
        float[,,] three_dim = {{{1,2,3},{4,5,6},{7,8,9}},
                                {{10,11,12},{13,14,15},{16,17,18}}};
        Console.WriteLine("N dimension array");
        // Dimensions start with index 0, and are not checked in this method.
        Console.WriteLine(three_dim.GetLength(0));
        Console.WriteLine(three_dim.GetLength(1));
        Console.WriteLine(three_dim.GetLength(2));
        // Getting and setting  values in the array
        Console.Write("Array pos 1,1,2: ");
        Console.WriteLine(three_dim[1,1,2]);
    }

    private static void jagged_arrays(){
        /**
            A jagged array is a one dimension array which contains a reference to
            other array objects.!--
        */
        int[][] jagged = new int[3][]; // Here the size must be declared cannot be omited
        // Now setting the sizes of every array of the array of arrays
        jagged[0] = new int[1];
        jagged[1] = new int[5];
        jagged[2] = new int[3];
        // Now set the values in every array
        jagged[0] = new int[]{1};
        jagged[1] = new int[]{0,1,2,3,4};
        jagged[2] = new int[]{2,3,4};
        // Accessing the values in the jagged array is different from the 
        // multidimensional arrays
        Console.WriteLine("Jagged arrays: 1,1");
        Console.WriteLine(jagged[1][4]);
    }
    private static void PrintColorsInColor(){
        Type color_type = typeof(ConsoleColor);
        foreach (var name in Enum.GetNames(color_type)){
            Console.ForegroundColor = (ConsoleColor)Enum.Parse(color_type, name);
            Console.Write("  " + name);
        }
        Console.ResetColor();
    }   
}