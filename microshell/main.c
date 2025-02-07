//Allowed functions:
//    malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <sys/wait.h>
# include <stdbool.h>

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		j;
	int		pv;
	int		*cmd_pos;
	bool	simple;

	i = 1;
	j = 1;
	pv = 0;
	simple = true;
	while (i < argc)
	{
		if (simple && !strcmp(argv[i], "|"))
			simple = false;
		if (!strcmp(argv[i], ";"))
			pv++;
		i++;
	}
	cmd_pos = malloc ((pv + 1) * sizeof(int));
	cmd_pos[0] = 1;
	i = 1;
	while (i < argc)
	{
		if (!strcmp(argv[i], ';') || !strcmp(argv[i], '|'))
		{
			cmd_pos[j] = i + 1;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	if (simple)
	{
		while(i <= pv)
		{
			if (!strcmp(argv[cmd_pos[i]], "cd"))
				exec_cd(argv[cmd_pos[i] + 1]); //WIP escrever cd aqui
			else
				execve(argv[cmd_pos[i]], argv + cmd_pos[i] + 1, envp); //WIP importante terminar aquele argv + cmd_pos[i] + 1... ate argv + cmd_pos[i + 1] - 2... ou assim. Preciso pensar no ultimo comando
			i++;
		}
		free(cmd_pos);
		return (0);
	}
	free(cmd_pos);
	//WIP PIPES! FORK()! DEUSMELIVRE!!!!!
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
