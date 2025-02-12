//Allowed functions:
//    malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <sys/wait.h>
# include <stdbool.h>
# include <stdio.h>

void	write_error(char *msg, char *addend)
{
	int	i;

	i = 0;
	while(msg[i])
	{
		write(2, &msg[i], 1);
		i++;
	}
	i = 0;
	if (addend)
	{
		while(addend[i])
		{
			write(2, &addend[i], 1);
			i++;
		}
	}
	write(2, "\n", 1);
}

void	exec_child(char **args, int size, int curr_fd, char **envp)
{
	args[size] = NULL;
	printf("EXEC_CHILD: cmd: %s, size, %d, argfinal: %s\n", args[0], size, args[size]);
	dup2(curr_fd, STDIN_FILENO);
	close(curr_fd);
	execve(args[0], args, envp);
	write_error("error: cannot execute ", args[0]);
	exit(1);
}

void	exec_cd(char **args, int size)
{
	if (size != 2)
		write_error("error: cd: bad arguments", NULL);
	else if (!chdir(args[1]))
		write_error("error: cd: cannot change directory to ", args[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		curr_fd;
	int		i;
	int		j;
	int		pv;
	int		*cmd_pos;

	i = 1;
	j = 1;
	pv = 0;
	curr_fd = dup(STDIN_FILENO);
	while (i < argc)
	{
		if (!strcmp(argv[i], ";") || !strcmp(argv[i], "|"))
			pv++;
		i++;
	}
	cmd_pos = malloc ((pv + 2) * sizeof(int));
	cmd_pos[0] = 1;
	cmd_pos[pv + 1] = argc + 1;
	i = 1;
	while (i < argc)
	{
		if (!strcmp(argv[i], ";") || !strcmp(argv[i], "|"))
		{
			cmd_pos[j] = i + 1;
			j++;
		}
		i++;
	}
	i = 0;
	printf("cmd_pos: %d, %d, %d\n pv: %d\n", cmd_pos[0], cmd_pos[1], cmd_pos[2], pv);
	while(i < pv || i == 0)
	{
		if (!strcmp(argv[cmd_pos[i]], "cd"))
			exec_cd(argv + cmd_pos[i], cmd_pos[i + 1] - cmd_pos[i] - 1);
		else if (!strcmp(argv[cmd_pos[i + 1] - 1], ";") || argv[cmd_pos[i + 1]] == NULL)
		{
			if (fork() == 0)
				exec_child(argv + cmd_pos[i], cmd_pos[i + 1] - cmd_pos[i] - 1, curr_fd, envp);
			else
			{
				close(curr_fd);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
					;
				curr_fd = dup(STDIN_FILENO);
			}
		}
		else if (!strcmp(argv[cmd_pos[i + 1] - 1], "|"))
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				exec_child(argv + cmd_pos[i], cmd_pos[i + 1] - cmd_pos[i] - 1, curr_fd, envp);
			}
			else
			{
				close(fd[1]);
				close(curr_fd);
				curr_fd = fd[0];
			}
		}
		i++;
	}
	free(cmd_pos);
	close(curr_fd);
	return (0);
}

	//Parse - tokens (argv)
	//Parse - Build tree
	//Execute commands
		//Write cd
		//execve()

    //Assumir caso simples
    	//execve()
    //Else if ";"
    	//??? (estudar o que faz no Bash)
    //Else if "|"
    	//fork()
