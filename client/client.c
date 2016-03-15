/*
** client.c for client in /home/roux_l/rendu/PSU_2015_minitalk/client
**
** Made by Guillaume Roux
** Login   <roux_l@epitech.net>
**
** Started on  Mon Feb  1 15:43:45 2016 Guillaume Roux
** Last update Mon Feb  8 14:51:56 2016 Guillaume Roux
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void	convert_msg(int pid, char carac)
{
  int	i;

  i = 0;
  while (i < 8)
    {
      usleep(1000);
      if (((carac >> i) & 1) == 1)
	{
	  if (kill(pid, SIGUSR1) == -1)
	    exit(0);
	}
      else
	if (kill(pid, SIGUSR2) == -1)
	  exit(0);
      i++;
    }
}

void	my_client(int pid, char *msg)
{
  int	i;

  i = 0;
  while (msg[i] != '\0')
    {
      convert_msg(pid, msg[i]);
      i++;
    }
  convert_msg(pid, msg[i]);
}

void	useless()
{
  int	i;

  i = 0;
}

int	main(int ac, char **av)
{
  int	i;
  int	pid;
  char	*str;

  i = 2;
  if (ac > 2)
    {
      pid = my_getnbr(av[1]);
      while (i < ac)
	{
	  str = av[i];
	  if (signal(SIGUSR1, useless) == SIG_ERR)
	    return (0);
	  if (signal(SIGUSR2, useless) == SIG_ERR)
	    return (0);
	  my_client(pid, str);
	  i++;
	}
    }
  return (0);
}
