using System;

namespace Sharper
{
  internal class Program
  {
    private static void Main(string[] args)
    {
      Console.WriteLine("calculating...");
      int num = 99;
      for (int index = num; index >= 0; --index)
      {
        Console.WriteLine(index);
        Console.WriteLine("val: " + Program.calc(num - index).ToString());
      }
    }

    private static int calc(int num)
    {
      int num1 = 0;
      for (int index1 = 0; index1 < num; ++index1)
      {
        for (int index2 = 0; index2 < num; ++index2)
        {
          for (int index3 = 0; index3 < num; ++index3)
          {
            for (int index4 = 0; index4 < num; ++index4)
            {
              for (int index5 = 0; index5 < num; ++index5)
              {
                string str = index1.ToString() + " to " + index2.ToString() + " to " + index3.ToString() + " to " + index4.ToString() + " to " + index5.ToString();
                num1 += str.Length;
              }
            }
          }
        }
      }
      return num1;
    }
  }
}
