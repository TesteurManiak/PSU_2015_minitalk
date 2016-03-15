/*
** server.c for server in /home/roux_l/rendu/PSU_2015_minitalk/server
**
** Made by Guillaume Roux
** Login   <roux_l@epitech.net>
**
** Started on  Mon Feb  1 15:37:58 2016 Guillaume Roux
** Last update Thu Feb  4 16:00:33 2016 Guillaume Roux
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void	my_putchar(char c)
{
  write (1, &c, 1);
}

void		my_env(int bin)
{
  static char	carac;
  static int	i;

  carac = carac + (bin << i);
  i++;
  if (i > 7)
    {
      if (carac == '\0')
	my_putchar('\n');
      else
	my_putchar(carac);
      carac = 0;
      i = 0;
    }
}

void	binarizer(int sign)
{
  if (sign == SIGUSR1)
    my_env(1);
  if (sign == SIGUSR2)
    my_env(0);
}

void	err_gest()
{
  signal(SIGUSR1, binarizer);
  if (signal(SIGUSR1, binarizer) == SIG_ERR)
    exit (0);
  signal(SIGUSR2, binarizer);
  if (signal(SIGUSR2, binarizer) == SIG_ERR)
    exit (0);
}

int	main()
{
  pid_t	pid;

  err_gest();
  my_put_nbr(getpid());
  my_putchar('\n');
  while (10)
    pause();
  return (0);
}
