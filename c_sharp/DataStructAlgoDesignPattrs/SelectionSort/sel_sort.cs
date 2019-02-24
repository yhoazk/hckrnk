using System;
//// <summary>
////  Div the array in 2 parts,: sorted and unsorted
////  At the beginning the sorted part is len = 0
////  Then the the smallest element of the unsorted part is
////  swapped to the sorted part in a fifo basis
////  This operation is repeadted until the unsorted part 
////  has len = 0
//// </summary>
 // compile with: -doc:DocFineName.xml

class sel_sort{
    public static void Main(){
        Console.WriteLine("Selection Sort");
                         // n............0 The indices are from N to less 
        int[] test_int = {3,3,4,-12,6,7,8,-12,9};
        string[] test_str = {"aa", "Ee", "wer", "ywe", "Z", "qwe"};
//        sort(test_int);
        swap(ref test_int[test_int.Length-1],ref test_int[0]);
        Console.WriteLine(""); // print a new line char
//        sort(test_int);
        Console.Write("Indx of -12: ");
        Console.WriteLine(getIndexOf(coll: test_int, item: -12));
        getIndexOf(coll: test_str, item: "Z");
//        sort(test_str);
    }

    public static void sort<T>(T[] elem) where T: IComparable
    {
        for (int i = 0; i < elem.GetLength(0); i++){
           Console.Write(elem[i]);
        }
        // Parameters can be also called by name
        // and the type has to be specified as a C++ template specialization
//        getIndexOf<T>(coll: elem, item: -12);
    }

    /// <summary>
    /// Given two objects, swaps its contents using a temp var
    /// </summary>
    /// <remarks>
    /// For this method to work in the array context we need to add the 
    /// modifier <c>ref</c> to the paramter declaration otherwise the numbers
    /// are passed by copy and the array is not modified
    /// <remarks>
    /// <returns>void, swap is done in place</return>
    /// <paramref name="a">First element</param>
    /// <paramref name="b">Secon element</param>
    private static void swap<T>(ref T a, ref T b){
        T temp = a;
        a = b;
        b = temp;
    }
    /// Is possible to only swap the references inside of the array or 
    /// the data is actually there as in the std c arrays and not a ref
    /// to the contained object
    private static void swap<T>(T[] array, int first, int second)
    {
        T temp = array[first];
        array[first] = array[second];
        array[second] = temp;
    }
    /// <summary>
    /// Returns the index of the element <c>item</c> in the collection
    /// </summary>
    /// <remarks>
    /// <remarks>
    /// <returns>int as the index of the array</return>
    /// <param name="coll">Iterable collection of elements</param>
    /// <param name="item">Item to find</param>
    /// <param name="start">The iterable will start from this position, default 0</param>
    /// <param name="end">The search for the item in collection will stop at this index</param>
    private static int getIndexOf<T>(T[] coll, T item, int start=0, int end=-1) where T: IComparable
    {
        int indx = 0;
        foreach (var i in coll)
        {
            Console.Write(i);
            Console.Write("::");
            Console.WriteLine(item);
            if(item.CompareTo(i) == 0){
              //  Console.WriteLine("FOUND");
                break;                
            }
            indx++;
        }

        return indx;
    }
}
/* error CS0411: Die Typargumente der 'sel_sort.getIndexOf<T>(T[], T, int, int)'-Methode können nicht per Rückschluss
        aus der Syntax abgeleitet werden. Geben Sie die Typargumente explizit an. */