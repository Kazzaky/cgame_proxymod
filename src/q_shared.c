#include "q_shared.h"

#include <stddef.h>

int32_t LongSwap(int32_t l)
{
  byte b1, b2, b3, b4;

  b1 = l & 255;
  b2 = (l >> 8) & 255;
  b3 = (l >> 16) & 255;
  b4 = (l >> 24) & 255;

  return ((int32_t)b1 << 24) + ((int32_t)b2 << 16) + ((int32_t)b3 << 8) + b4;
}

int Q_stricmpn(const char* s1, const char* s2, int n)
{
  int c1, c2;

  if (s1 == NULL)
  {
    if (s2 == NULL)
      return 0;
    else
      return -1;
  }
  else if (s2 == NULL)
    return 1;

  do
  {
    c1 = *s1++;
    c2 = *s2++;

    if (!n--)
    {
      return 0; // strings are equal until end point
    }

    if (c1 != c2)
    {
      if (c1 >= 'a' && c1 <= 'z')
      {
        c1 -= ('a' - 'A');
      }
      if (c2 >= 'a' && c2 <= 'z')
      {
        c2 -= ('a' - 'A');
      }
      if (c1 != c2)
      {
        return c1 < c2 ? -1 : 1;
      }
    }
  } while (c1);

  return 0; // strings are equal
}

int Q_strncmp(const char* s1, const char* s2, int n)
{
  int c1, c2;

  do
  {
    c1 = *s1++;
    c2 = *s2++;

    if (!n--)
    {
      return 0; // strings are equal until end point
    }

    if (c1 != c2)
    {
      return c1 < c2 ? -1 : 1;
    }
  } while (c1);

  return 0; // strings are equal
}

int Q_stricmp(const char* s1, const char* s2)
{
  return (s1 && s2) ? Q_stricmpn(s1, s2, 99999) : -1;
}
