using System;

public class UserMainCode
{
    public int minLightRange(int input1, int input2, int[] input3, int[] input4)
    {
        bool canCoverAllBenches(int power)
        {
            int j = 0; 
            for (int i = 0; i < input3.Length; i++)
            {
                while (j < input4.Length && Math.Abs(input4[j] - input3[i]) > power)
                {
                    j++; 
                }
                
                if (j == input4.Length)
                {
                    return false;
                }
            }
            return true;
        }

        int low = 0, high = int.MaxValue, result = high;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            
            if (canCoverAllBenches(mid))
            {
                result = mid; 
                high = mid - 1; 
            }
            else
            {
                low = mid + 1; 
            }
        }
        
        return result; 
    }

    public static void Main(string[] args)
    {
        Console.WriteLine("Test Case 1:");
        int input1 = 6;
        int input2 = 4;
        int[] input3 = { 2, 7, 12, 17, 22, 27 };
        int[] input4 = { 5, 10, 15, 20 };
        UserMainCode userMainCode = new UserMainCode();
        int result1 = userMainCode.minLightRange(input1, input2, input3, input4);
        Console.WriteLine("Expected Output: 7, Actual Output: " + result1);
        
        Console.WriteLine("\nTest Case 2:");
        input1 = 5;
        input2 = 3;
        input3 = new int[] { 6, 7, 8, 9, 10 };
        input4 = new int[] { 6, 8, 10 };
        int result2 = userMainCode.minLightRange(input1, input2, input3, input4);
        Console.WriteLine("Expected Output: 1, Actual Output: " + result2);
    }
}
