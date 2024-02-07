/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:48:44 by cgray             #+#    #+#             */
/*   Updated: 2024/02/07 17:02:01 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


/* Split command
find path to command line
 */
void	run_cmd(char **av, char **envp)
{

}

/* Child process runs inside of fork.
Takes the fileinput av[1], puts output to pipe p_fd[1]
close
execute av[2]
*/
void	child_process(char **av, char **envp, int *p_fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY, 0777); //creating a file, so need file mode
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

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777); //creating file, write-only, create file, erase if already exists
	dup2(p_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(p_fd[1]);
	run_cmd(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		p_fd[2];
	pid_t	pid1;

	if (ac == 5)
	{
		if (pipe(p_fd) == -1) //create pipe p_fd[0] & p_fd[1]
			perror("pipe failed");
		pid1 = fork();
		if (pid1 == -1) //fork error
			perror("fork failed");
		if (pid1 == 0) //child process
			child_process(av, envp, p_fd);
		waitpid(pid1, NULL, 0); //wait for child process to finish
		parent_process(av, envp, p_fd);
	}
	else
	{
		perror("bad arguments");
	}
	return (0);
}
