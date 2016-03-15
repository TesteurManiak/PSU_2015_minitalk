/*
** my_getnbr.c for my_getnbr in /home/roux_l/rendu/Piscine_C_AP
** 
** Made by Guillaume Roux
** Login   <roux_l@epitech.net>
** 
** Started on  Thu Oct 15 15:32:12 2015 Guillaume Roux
** Last update Sat Oct 24 08:57:17 2015 Guillaume Roux
*/

char     my_getnbr(char *str)
{
  int   i;
  int   j;
  int   nb;

  i = 0;
  j = 1;
  nb = 0;
  while ((str[i] == '-') || (str[i] == '+'))
    {
      if (str[i] == '-')
        {
          j = j * - 1;
        }
      i = i + 1;
    }
  while ((str[i] >= 48) && (str[i] <= 57))
    {
      nb = nb * 10;
      nb = nb + (str[i] - 48);
      i = i + 1;
    }
  nb = nb * j;
  return (nb);
}
