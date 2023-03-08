//5.
//a. Print the exponent of a prime number p from the decomposition in prime factors of a given number n (n is a non-null natural number).
//b.Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime.

#include <stdio.h>
#include <math.h> 
#include <stdbool.h>

int find_exp(int n, int p)
{
    /// <summary>
    /// we initialize the frequency vector with 0 so we can declare it locally
    /// we put in a frequency vector each appearence of i in the decomposition of n;
    /// we divide by i to reduce the number of steps
    /// we return the number of appearences of p 
    /// </summary>
    /// <param name="n"></param> given number
    /// <param name="p"></param> prime number p from the decomposition of n 
    /// <returns></returns> the exponent of the prime number p from the decomposition in prime factors of n

    int i, k = n, v[100];
    for (i = 0; i < 100; i++)
        v[i] = 0;
    for (i = 2; i <= n; i++)
        while (n % i == 0)
        {
            v[i] = v[i] + 1;
            n = n / i;
        }
    for (i = 2; i <= k; i++)
        if (v[i] != 0 && i == p)
            return v[i];
    return 0;
}
int relatively_prime(int a, int b)
{
    /// <summary>
    /// checks if two number are relatively prime 
    /// we verify that they have only one common factors and that is 1
    /// </summary>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns></returns> 1 if a and b are relatively prime,0 otherwise
    int i, nr = 0;
    for (i = 1; i <= a; i++)
        if (a % i == 0 && b % i == 0)
            nr = i;
    if (nr == 1)
        return 1;
    else return 0;

}

int longestsubseq(int a[], int n)
{
    /// <summary>
    /// left = the left indice of the selected sequence 
    /// right = the right indice of the selected sequence
    /// we navigate through the vector of numbers a and we check at every step if two consecutive numbers are relatively prime 
    /// we check if the length of the subarray is greater than the length of the longest subsequence found so far
    /// </summary>
    /// <param name="a"></param>the vector of numbers
    /// <param name="n"></param>the number of elements from the vector 
    /// <returns></returns>the lenght of the longest subsequence
    int i, j, left, right, k, nr;
    left = 1, right = 0;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
        {
            bool ok = true;
            for (k = i; k < j; k++)
                if (relatively_prime(a[k], a[k + 1]) == 0)
                    ok = false;
            if (ok)
                if (j - i + 1 > right - left + 1)
                    left = i, right = j;
        }
    return nr = left * 10 + right;

}

int product(int b[], int k)
{
    int i, prod = 1, nr = 0;
    for (i = 0; i < k; i++)
    {
        prod = prod * b[i];
    }
    while (prod % 10 == 0)
    {
        prod = prod / 10;
        nr++;
    }
    return nr;
}

void read_vector(int a[], int* nr)
{
    printf("Enter the number of elements in the vector: ");
    scanf_s("%d", nr);
    printf("Enter the elements: \n");
    for (int i = 1; i <= *nr; i++)
    {
        scanf_s("%d", &a[i]);//introducing elements from the vector
    }
}
int main()
{
    printf("Please choose your option:");
    printf("\n 1.Reading a vector of numbers from the console");
    printf("\n 2.Functionality 1");
    printf("\n 3.Functionality 2");
    printf("\n 4.Lab activity");
    printf("\n 0.Exit ");
    int run = 1, opt, n, p, exp, a[100], nr = 0, b[100], k, x;
    while (run == 1)
    {
        printf("\n \n User's option is: ");
        scanf_s("%d", &opt);//read the user option from the keyboard
        if (opt == 1)
        {
            read_vector(a, &nr);

            printf("String elements are: ");
            for (int i = 1; i <= nr; i++)
                printf("%d ", a[i]);

        }

        if (opt == 2)
        {
            printf("\n Enter the number n: ");
            scanf_s("%d", &n);//the number to be decomposed
            printf("\n Enter the prime number p: ");
            scanf_s("%d", &p);//the prime number from the decomposition of n 
            exp = find_exp(n, p);
            if (exp == 0)
                printf(" p is not in the decomposition of n");
            else
                printf(" The exponent of p is: %d", exp);

        }
        if (opt == 3)
        {
            if (nr == 0)
                printf_s("\nPlease read a vector of numbers first! \nSelect option 1!!");
            else {
                int lr, l, r;
                //13
                // 6 12 13 34 35 6 4 22 23 24 14 7 9
                //12 13 34 35 6 - 5 lenght


                lr = longestsubseq(a, nr);

                l = lr / 10;
                r = lr % 10;
                for (int i = l; i <= r; i++)
                    printf("%d ", a[i]);
            }


        }
        if (opt == 4)
        {
            k = 0; x = 0;
            printf("Enter a sequence of numbers ended with 0: \n");
            scanf_s("%d", &x);
            b[k] = x; k++;
            while (x != 0)
            {
                scanf_s("%d", &x);
                b[k] = x;
                k++;
            }
            printf("The number of 0 digits of the product of the read numbers is: %d", product(b, k - 1));

        }
        if (opt == 0)
            run = 0;
        if (opt != 0 && opt != 1 && opt != 2 && opt != 3 && opt != 4)
        {
            printf("Invalid option!");
        }
    }

    return 0;
}