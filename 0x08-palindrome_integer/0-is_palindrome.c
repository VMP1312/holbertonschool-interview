#include "palindrome.h"
/**
 * is_palindrome - Checks if a given unsigned integer is a palindrome.
 * @n: Int.
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
  int svr = 0;
  unsigned long int bwds = 0;
  unsigned long int fwrd = n;
  while (n >= 1)
    {
      svr = n % 10;
      bwds = (bwds *(10)) + svr;
      n = n / 10;
    }
  return (fwrd == bwds);
}
