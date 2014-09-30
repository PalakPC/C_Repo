//Java program to sort the given command-line float arguments in ascending order using quicksort algorithm.

public class sort { 
   static float[] numbers;
   static int num = 0;

   public static class qsort {
      public void sort() {
         if(numbers == null || num == 0)
            return;
         quicksort(0, num - 1);
      }

      private void quicksort(int low, int high) {
         int i = low, j = high;
         float pivot = numbers[low + (high - low) / 2];
         while(i <= j) {
            while(numbers[i] < pivot)
               ++i;		
            while(numbers[j] > pivot)
               --j;
            if(i <= j) {
               exchange(i, j);
               ++i; 
               --j;
            }
         }
         if(low < j)
            quicksort(low, j);
         if(i < high)
            quicksort(i, high);
      }

      private void exchange(int i, int j) {
         float temp = numbers[i];
         numbers[i] = numbers[j];
         numbers[j] = temp;
      }
   }

   public static void main(String[] args) {
      numbers = new float[50];	
      while(num < args.length) {
         try {
            numbers[num] =  Float.parseFloat(args[num]);    //Parsing command-line arguments to float.
         }			
         catch(NumberFormatException e) {
            System.out.println("Your argument is a non-float");
            System.exit(1);
         }	
         ++num;
      }		
      qsort q = new qsort();
      q.sort();
      num = 0;
      while(num < args.length) {
         System.out.println(numbers[num]);
         ++num;
      }
   }	
}	
