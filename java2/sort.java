public class sort
{ 
	static int i=0;
	static float[] arr;

	private class qsort
	{
		private int number;
		private float[] numbers;

		public void sort(float[] values)
		{
			if(values==null||values.length==0)
			{
				return;
			}
			this.numbers=values;
			number=values.length;
			quicksort(0, number-1);
		}

		private void quicksort(int low, int high)
		{
			int i=low, j=high;
			float pivot=numbers[low+(high-low)/2];

			while(i<=j)
			{
				while(numbers[i]<pivot)
				{
					++i;
				}
				
				while(numbers[j]>pivot)
				{
					--j;
				}

				if(i<=j)
				{
					exchange(i, j);
					++i; 
					--j;
				}
			}

			if(low<j)
			{
				quicksort(low, j);
			}

			if(i<high)
			{
				quicksort(i, high);
			}
		}

		private void exchange(int i, int j)
		{
			float temp=numbers[i];
			numbers[i]=numbers[j];
			numbers[j]=temp;
		}
	}

	public static void main (String[] args)
	{
		arr = new float[50];
	
		while(i<args.length)
		{
			try
			{
				float a=Float.parseFloat(args[i]);
				arr[i]=a;
			}
			catch(NumberFormatException e)
			{
				System.out.println("Your argument is a non-float");
			}
			i=i+1;
		}
		
		qsort q;
		q.sort(arr);
	}	
}	
