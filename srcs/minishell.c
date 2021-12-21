/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:39:14 by ctirions          #+#    #+#             */
/*   Updated: 2021/12/21 16:17:43 by ctirions         ###   ########.fr       */
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
	if (ans)
		printf("minishell: command not found: %s\n", ans);
	return (NULL);
}

int	make_my_actions(t_mini *shell, char **env)
{
	char	**cmd;
	char	*path;

	if (!shell->cmd)
		return (1);
	cmd = ft_split(shell->cmd->str, ' ');
	path = pathfinder(cmd[0], env);
	if (!path)
		return (1);
	if (execve(path, cmd, env))
	{
		printf("minishell: command not found: %s\n", cmd[0]);
		return (1);
	}
	//shell->cmd = shell->cmd->next;
	return (0);
}

int main(int argc, char **argv, char **env)
{
	t_mini	shell;

	shell.basic_env = env;
	if (argc > 1 && argv)
		return (1);
	shell.exit = 0;
	if (init_env(&shell, env))
		return (1);
	up_shlvl(&shell);
	while (!shell.exit)
	{
		signal(SIGINT, &sigint);
		shell.answer = readline("MINISHELL $ ");
		if (!shell.answer)
		{
			printf("\n");
			return (1);
		}
		add_history(shell.answer);
		if (parser(shell.answer, &shell))
			shell.exit = 1;
	}
	free_env(shell.env);
	return (0);
}
