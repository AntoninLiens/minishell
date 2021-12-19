/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:06:08 by ctirions          #+#    #+#             */
/*   Updated: 2021/11/30 15:06:08 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/includes/libft.h"

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define ORANGE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

typedef struct	s_env	t_env;
typedef struct	s_cmd	t_cmd;

struct	s_env
{
	char	*str;
	t_env	*next;
};

struct	s_cmd
{
	char	*str;
	t_cmd	*next;
	t_cmd	*prev;
};

typedef struct  s_mini
{
    t_env	*env;
	t_cmd	*cmd;
	char	*answer;
	int		pid;
    int		exit;
}               t_mini;

/*		INIT		*/

int init_env(t_mini *shell, char **basic_env);

/*		ENV		*/

char    *get_env_val(t_env *env, char *name);

/*		SHLVL		*/

void    up_shlvl(t_mini *shell);

/*		UTILS		*/

void	free_env(t_env *env);

/*		SIGNALS		*/

void    sigint(int code);

/*		PARSE		*/

int		parser(char *ans, t_mini *shell);

/*		COMMANDS	*/

void    echo(char **cmds);
void	env(t_env *env);
void    pwd(t_env *env);
void    cd(char *path, t_mini *shell);
void    export(t_env *env, char *arg);
void    unset(t_env *env, char *name);

#endif