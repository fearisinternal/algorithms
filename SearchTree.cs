using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace SearchTree
{
    class Program
    {
        static void rep(int[] A, int vertex, int count)
        {
            if (2 * vertex + 1 > count) return;
            int imax = 0;
            if (2 * vertex + 1 == count)
            {
                imax = 2 * vertex + 1;
            }
            else
            {
                int l = 2 * vertex + 1;
                int r = 2 * vertex + 2;
                imax = A[l] > A[r] ? l : r;
            }
            if (A[imax] > A[vertex])
            {
                int tmp = A[imax];
                A[imax] = A[vertex];
                A[vertex] = tmp;
                rep(A, imax, count);
            }
        }
        static void Main(string[] args)
        {
            int[] A = { 17, 2, 6, 21, 9, 1, 2, 5, 7, 8, 99, 1000, 3, 4, 6 };
            for (int i = A.Length / 2; i >= 0; i--)
            {
                rep(A, i, A.Length - 1);
            }
 
            for (int i=A.Length-1; i>=0; i--)
            {
                int tmp = A[i];
                A[i] = A[0];
                A[0] = tmp;
                rep(A, 0, i - 1);
            }
 
            Console.WriteLine();
        }
    }
}
