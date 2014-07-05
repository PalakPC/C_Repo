//Java program to sort the given command-line float arguments in ascending order using quicksort algorithm.

public class sort { 
	static int n = 0;
	static float[] arr;
	static float[] numbers;
	static int num;

	public static class qsort {
		public void sort (float[] values, int x) {
			if (values == null || values.length == 0)
				return;

			numbers = values;
			num = x;
			quicksort (0, num - 1);
		}

		private void quicksort (int low, int high) {
			int i = low, j = high;
			float pivot = numbers[low + (high - low) / 2];

			while (i <= j) {
				while (numbers[i] < pivot)
					++i;
				
				while (numbers[j] > pivot)
					--j;

				if (i <= j) {
					exchange (i, j);
					++i; 
					--j;
				}
			}

			if (low < j)
				quicksort (low, j);

			if (i < high)
				quicksort (i, high);
		}

		private void exchange (int i, int j) {
			float temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
		}
	}

	public static void main (String[] args) {
		arr = new float[50];
	
		while (n < args.length) {
			try {
				float a = Float.parseFloat (args[n]);	//Parsing command-line arguments to float.
				arr[n] = a;
			}
			
			catch (NumberFormatException e) {
				System.out.println ("Your argument is a non-float");
				System.exit (1);
			}
			
			++n;
		}
		
		qsort q = new qsort ();
		q.sort (arr, n);

		n = 0;
		while (n < args.length) {
			System.out.println (numbers[n]);
			++n;
		}
	}	
}	
