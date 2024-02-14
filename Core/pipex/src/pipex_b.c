/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:48:44 by cgray             #+#    #+#             */
/*   Updated: 2024/02/14 18:57:42 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Split command
find path to command line
exec command and error check
**cmd = commandd array (av[2] and av[3]) {ls, -l} {wc -l}
*path = path to command program*/
int	run_cmd(char *av, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	cmd = ft_split(av, ' ');
	path = extract_path(cmd[0], envp);
	i = 0;
	if (!path)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		error("Path to command not found.\n");
	}
	i = 0;
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/* Child process that runs inside of fork.
Creates input file,
Takes the infile av[1], puts output to pipe p_fd[1]
close pipe input
execute av[2]
*/
void	child_process_b(char *av, char **envp)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		error("pipe failed.\n");
	pid = fork();
	if (pid == -1)
		error("fork failed.\n");
	if (pid == 0)
	{
		close(p_fd[0]);
		dup2(p_fd[1], STDOUT_FILENO);
		if (run_cmd(av, envp) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter)
{
	pid_t	pid;
	int		p_fd[2];
	char	*line;

	if (pipe(p_fd) == -1)
		error("pipe failed.\n");
	pid = fork();
	if (pid == -1)
		error("fork failed.\n");
	if (pid == 0)
	{
		close(p_fd[0]);
		while (get_next_line_terminal(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(p_fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

/* Determines flags to open/create file based on which
argument and flag (av placement) is passed to it
0 == here_doc
1 == outfile
2 == infile*/
int	open_flag(char *av, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(av, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (i == 1)
		fd = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (i == 2)
		fd = open(av, O_RDONLY, 0666);
	if (fd == -1)
		error("open file failed. Check permissions.\n");
	return (fd);
}

/* Main Function
-checks arguments
-creates pipe and fork
-calls child and parent process after child process finishes */
int	main(int ac, char **av, char **envp)
{
	int		i;
	int		infile;
	int		outfile;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			if (ac < 6)
				error("Bad arguments for here_doc.\n");
			i = 3;
			outfile = open_flag(av[2], 0);
			here_doc(av[2]);
		}
		else
		{
			i = 2;
			outfile = open_flag(av[ac - 1], 1);
			infile = open_flag(av[1], 2);
			dup2(infile, STDIN_FILENO);
		}
		while (i < ac - 2)
			child_process_b(av[i++], envp);
		dup2(outfile, STDOUT_FILENO);
		run_cmd(av[ac - 2], envp);
	}
	else
	{
		error("Error: bad arguments\n");
		ft_printf("Expected format:\n./pipex infile cmd1 cmd2 outfile\n");
	}
	return (0);
}

// ft_printf("\t./pipex 'here_doc' infile cmd1 cmd2 outfile\n");
