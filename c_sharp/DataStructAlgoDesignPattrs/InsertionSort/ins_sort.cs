using System;

/**
  The array is divided in two parts, as in the selection sort: sorted and unsorted
  The first element is taken as a trivially sorted array, as it has only one element
  Then the smallest element in the unsorted part is found and moved to the sorted
  part in its correct location considering the already unique element in the sorted
  array
  Then the initial indexer starts at 1 instead of 0 as in selection sort

     */
class ins_sort{
    public static void Main(){
        Console.WriteLine("Ins Sort:");
    }
}