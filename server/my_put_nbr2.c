/*
** my_put_nbr.c for my_put_nbr in /home/roux_l/rendu/Piscine_C_AP
**
** Made by Guillaume Roux
** Login   <roux_l@epitech.net>
**
** Started on  Thu Oct 15 14:14:56 2015 Guillaume Roux
** Last update Thu Jan  7 16:37:49 2016 Guillaume Roux
*/

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = - 1 * nb;
      my_putchar('-');
    }
  if (nb < 10)
    {
      my_putchar(nb + 48);
    }
  else
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
}
