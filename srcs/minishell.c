/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:39:14 by ctirions          #+#    #+#             */
/*   Updated: 2021/11/30 14:39:14 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*pathfinder(char *ans, char **env)
{
	char	**paths;
	char	*part_path;
	char	*path;
	int		i;

	i = -1;
	while (!ft_strnstr(env[++i], "PATH", 4))
		;
	paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, ans);
		free(part_path);
		if (!access(path, F_OK))
			return (path);
	}
	return (0);
}

void	make_my_actions(char *ans, char **env)
{
	pid_t	pid;
	char	**cmd;
	char	*path;

	pid = fork();
	cmd = ft_split(ans, ' ');
	path = pathfinder(ans, env);
	if (!path)
		return ;
	if (!pid)
		execve(path, cmd, env);
	else
		waitpid(pid, 0, 0);
}

int	parse_answer(char *answer, char **env)
{
	(void)env;
	char	**cmd;
	int		i;

	i = -1;
	cmd = ft_split(answer, ' ');
	while (cmd[++i])
	{
		if (cmd[i] == "echo" || cmd[i] == "cd" || cmd[i] == "ls" || \
		cmd[i] == "pwd" || cmd[i] == "export" || cmd[i] == "unset" || \
		cmd[i] == "env")
			cass_exec(cmd[i], env);
		else if (cmd[i] == "exit")
			return (0);
		else
			return (1);
	}
}

int main(int argc, char **argv, char **env)
{
	char	*answer;
	int		first;

	first = 0;
	if (argc > 1 && argv)
		return (1);
	while (!first++ || answer)
	{
		answer = readline("😁 \033[34mMINISHELL \033[31m$ \033[0m");
		add_history(answer);
		make_my_actions(answer, env);
		if (parse_answer(answer, env))
			return (1);
	}
	printf("\n");
	return (0);
}
