/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:48:44 by cgray             #+#    #+#             */
/*   Updated: 2024/02/09 18:52:58 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Search envp for PATH value
return path to given command, freeing memory as it is used */
char	*extract_path(char *cmd, char **envp)
{
	int	i;
	char	**paths_tab;
	char	*add_slash;
	char	*cmd_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0) //envp[i] = PATH=/nfs/homes/cgray/bin:/nfs/homes/cgray/bin...
		i++;
	envp[i] += 5; //skip 'PATH='
	paths_tab = ft_split(envp[i], ':');
	i = 0;
	while (paths_tab[i])
	{
		add_slash = ft_strjoin(paths_tab[i], "/");
		cmd_path = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (access(cmd_path, F_OK) == 0) //checks that file exists, stops on first cmd_path that works
			break ;
		free(cmd_path);
		i++;
	}
	i = 0;
	while (paths_tab[i])
		free(paths_tab[i++]);
	free(paths_tab);
	if (!cmd_path)
		return (0);
	return (cmd_path);
}

/* Split command
find path to command line
 */
void	run_cmd(char *av, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	cmd = ft_split(av, ' '); //cmd array (av[2] and av[3]) {ls, -l} {wc -l}
	path = extract_path(cmd[0], envp); //path from cmd
	i = 0;
	if (!path)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		perror("Path to command not found.\n");
	}
	if (execve(path, cmd, envp) == -1) //exec command and error check
		perror("Exec error.\n");
	free(cmd);
}

/* Child process runs inside of fork.
Takes the fileinput av[1], puts output to pipe p_fd[1]
close
execute av[2]
*/
void	child_process(char **av, char **envp, int *p_fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY, 0666); //creating a file, so need file mode
	if (infile == -1)
		perror("open av[1] failed\n");
	dup2(p_fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(p_fd[0]);
	run_cmd(av[2], envp);
}

/* parent process of fork
open av[4], redirect input to pipe fd[0] ->stdin
output outfile to stdout
close
execute av[3]*/
void	parent_process(char **av, char **envp, int *p_fd)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666); //creating file, write-only, create file, erase if already exists
	if (outfile == -1)
		perror("open av[4] failed\n");
	dup2(p_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(p_fd[1]);
	run_cmd(av[3], envp);
}

/* Main Function
-checks arguments
-creates pipe and fork
-calls child and parent process */
int	main(int ac, char **av, char **envp)
{
	int		p_fd[2];
	pid_t	pid1;
	char	*path;

	if (ac == 5)
	{
		if (pipe(p_fd) == -1) //create pipe p_fd[0] & p_fd[1]
			perror("pipe failed\n");
		pid1 = fork();
		if (pid1 == -1) //fork error
			perror("fork failed\n");
		if (pid1 == 0) //child process
			child_process(av, envp, p_fd);
		waitpid(pid1, NULL, 0); //wait for child process to finish
		parent_process(av, envp, p_fd);
	}
	else
	{
		perror("Error: bad arguments\n");
		ft_printf("Expected format:\n./pipex infile cmd1 cmd2 outfile\n");
	}
	return (0);
}

// ft_printf("\t./pipex 'here_doc' infile cmd1 cmd2 outfile\n");
