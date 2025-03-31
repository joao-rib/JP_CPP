/*Subject 

Allowed functions:

    malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp

Write a program that will behave like executing a shell command

    The command line to execute will be the arguments of this program

    Executable's path will be absolute or relative but your program must not build a path (from the PATH variable for example)

    You must implement "|" and ";" like in bash

        we will never try a "|" immediately followed or preceded by nothing or "|" or ";"

    Your program must implement the built-in command cd only with a path as argument (no '-' or without parameters)

        if cd has the wrong number of argument your program should print in STDERR "error: cd: bad arguments" followed by a '\n'

        if cd failed your program should print in STDERR "error: cd: cannot change directory to path_to_change" followed by a '\n' with path_to_change replaced by the argument to cd

        a cd command will never be immediately followed or preceded by a "|"

    You don't need to manage any type of wildcards (*, ~ etc...)

    You don't need to manage environment variables ($BLA ...)

    If a system call, except execve and chdir, returns an error your program should immediatly print "error: fatal" in STDERR followed by a '\n' and the program should exit

    If execve failed you should print "error: cannot execute executable_that_failed" in STDERR followed by a '\n' with executable_that_failed replaced with the path of the failed executable (It should be the first argument of execve)

    Your program should be able to manage more than hundreds of "|" even if we limit the number of "open files" to less than 30.

Example that should work : 

$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

>./microshell 

--------------------------*/


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:15:17 by shackbei          #+#    #+#             */
/*   Updated: 2023/12/06 23:29:19 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

/*not needed in exam, but necessary if you want to use this tester:
https://github.com/Glagan/42-exam-rank-04/blob/master/microshell/test.sh*/
// #ifdef TEST_SH
// # define TEST		1
// #else
// # define TEST		0
// #endif

void	ft_putstr_fd2(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
		while(*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
}

void ft_execute(char *argv[], int i, int tmp_fd, char *env[])
{
	//overwrite ; or | or NULL with NULL to use the array as input for execve.
	//we are here in the child so it has no impact in the parent process.
	argv[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(argv[0], argv, env);
	ft_putstr_fd2("error: cannot execute ", argv[0]);
	exit(1);
}

int	main(int argc, char *argv[], char *env[])
{
	int	i;
	int fd[2];
	int tmp_fd;
	(void)argc;	// is needed in exam, because the exam tester compiles with -Wall -Wextra -Werror

	i = 0;
	tmp_fd = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1]) //check if the end is reached
	{
		argv = &argv[i + 1];	//the new argv start after the ; or |
		i = 0;
		//count until we have all informations to execute the next child;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0) //cd
		{
			if (i != 2)
				ft_putstr_fd2("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) != 0)
				ft_putstr_fd2("error: cd: cannot change directory to ", argv[1]	);
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0)) //exec in stdout
		{
			if ( fork() == 0)
				ft_execute(argv, i, tmp_fd, env);
			else
			{
				close(tmp_fd);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if(i != 0 && strcmp(argv[i], "|") == 0) //pipe
		{
			pipe(fd);
			if ( fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				ft_execute(argv, i, tmp_fd, env);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
	}
	close(tmp_fd);
	// if (TEST)		// not needed in exam, but necessary if you want to use this tester:
	// 	while (1);	// https://github.com/Glagan/42-exam-rank-04/blob/master/microshell/test.sh
	return (0);
}