/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:25:51 by cgray             #+#    #+#             */
/*   Updated: 2024/02/07 15:28:36 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
|-----------------------PIPEX-----------------------|
	- Receive arguments
		- infile -
		- cmd1
		- cmd2
		- outfile
		- Behaves like
			< infile cmd1 | cmd2 > outfile
	- set up pipe and create two child processes
		-child process 1 inside fork (pid1)
			-open input file av[1]
			-dup2 file to redirect input to pipe
			-dup2 file for output to pipe
			-close extra FDs fd[0]
			-exec command av[2]
		-parent process
			-open output file av[4]
			-dup2 fd to redirect input to pipe fd[0]->stdin
			-dup2 fd for output to outfile outfile->stdout
			-close extra FDs fd[1]
			-exec command av[3]
	- execute commands
		Function: int execve (const char *filename,
			char *const argv[], char *const env[])
		*envp[]
			A typical value for this environment variable might be a string like:

			:/bin:/etc:/usr/bin:/usr/new/X11:/usr/new:/usr/local/bin
			This means that if the user tries to execute a program named foo,
			the system will look for files named foo, /bin/foo, /etc/foo,
			and so on.
			The first of these files that exists is the one that is executed.

		- split and execute commands seperately
		-command absolute or relative path?
			-look for path line in envp
			-first access path is right, return path
				access(path, option F_OK (tests existance of file))
*/

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <fcntl.h> //open/unlink
# include <unistd.h> //read/write/access/pipe/fork/execve/dup2
# include <sys/wait.h> //wait/waitpid
# include <stdio.h> //perror
# include <string.h> //strerror






#endif
