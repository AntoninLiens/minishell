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
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>  
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

typedef struct s_env	t_env;
typedef struct s_cmd	t_cmd;

struct	s_env
{
	char	*str;
	t_env	*next;
};

struct	s_cmd
{
	char	**str;
	char	*fdin;
	char	*fdout;
	char	**limit_string;
	int		heredoc;
	int		append;
	int		s_quotes;
	int		d_quotes;
	int		end_parse_error;
	t_cmd	*next;
	t_cmd	*prev;
};

typedef struct s_mini
{
	t_cmd	*cmd;
	t_env	*env;
	char	**basic_env;
	char	*answer;
	int		fdin;
	int		fdout;
	int		exit;
	int		exit_status;
	int		nb_cmds;
}				t_mini;

/*		MAIN		*/

void	minishell(t_mini *shell);

/*		INIT		*/

int		init(t_mini *shell, char **env);
int		init_env(t_mini *shell, char **basic_env);
void	up_shlvl(t_mini *shell);

/*		ENV		*/

void	replace_spec_char(t_mini *shell);
void	get_spec_char(t_cmd *cmd, int i, t_mini *shell);
char	*get_env_val(t_env *env, char *name);

/*		UTILS		*/

char	*pathfinder(char *ans, t_env *env);
char	*ft_strjoin_mini(char *s1, char *s2);
char	*get_file_name(char *str);

void	free_env(t_env *env);
void	free_double_char(char **str);
void	free_cmd(t_cmd *cmd);

void	lst_first(t_cmd **list);
void	lst_last(t_cmd **list);

char	**sort_env(char **export);

/*		SIGNALS		*/

int		set_sig_cmd_out(t_cmd *cmd);
int		set_sig_cmd_in(t_cmd *cmd);
void	ctrl_c_cmd_heredoc_out(int code);
void	ctrl_c_cmd_heredoc_in(int code);
void	ctrl_c_cmd_out(int code);
void	ctrl_c_cmd_in(int code);
int		sig_cmd_heredoc_out(void);
int		sig_cmd_heredoc_in(void);
int		sig_cmd_out(void);
int		sig_cmd_in(void);
void	ctrl_c_default(void);
void	sigint(int code);
void	sigquit(int code);

/*		PARSE		*/

void	parser(char *ans, t_mini *shell);
void	stop_parse_error(t_mini *shell);

int		check_operator(char *ans, t_mini *shell);
int		init_cmd(t_mini *shell, char **cmd);
int		add_command(t_mini *shell, char *command);
int		init_other_cmd(t_mini *shell, char *command);
int		init_heredoc(t_cmd *cmd, char *command, int *i);

int		close_quotes(char *cmd);
char	*quotes(char *command);

char	*init_inoutfd(char *command, t_cmd *cmd);
char	*init_infile(char *command, t_cmd *cmd, int *i, char *ret);
char	*init_infile(char *command, t_cmd *cmd, int *i, char *ret);

/*		EXEC		*/

int		big_exec(t_mini *shell);

int		builts_in(t_mini *shell, char **cmd);
int		exec_bin(char **cmd, t_mini *shell);

int		pipes(t_mini *shell, int *pfd);
void	pipe_child(t_cmd *tmp, int *pfd, int fdin, t_mini *shell);
void	close_my_pipes(int *pfd, t_mini *shell, pid_t pid);

/*		REDIRECTIONS		*/

int		mini_inout(t_mini *shell, t_cmd *cmd);

int		mini_heredoc(t_cmd *cmd);
int		child_heredoc(t_cmd *cmd, char *line, int pipefd[2]);
int		heredoc_no_cmd(t_cmd *cmd, char *line);

/*		COMMANDS	*/

int		echo(char **cmd);
int		aff_env(t_env *env, char **cmd);
int		mini_exit(t_mini *shell, char **cmd);
int		pwd(t_env *env, char **cmd);
int		cd(t_mini *shell, char **cmd);
int		export(t_env *env, char **cmd);
int		unset(t_env *og_env, char **arg);
void	unset_name(char *name, t_env *og_env);

#endif