#include<readline/readline.h>
#include<readline/history.h>
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>

typedef struct s_commands{
	char	*unparsed;
	char	***parsed;
	int		pipes;
}	t_commands;

char *ft_prompt (char *str)
{
	char *cwd;
	cwd = getcwd (0, 0);
	printf ("%s", cwd);
	str = readline("\n>");
	free (cwd);
	return (str);
}

int	ft_check_after_pipe (char *pipe)
{
	int	i;

	i = 0;
	while (pipe[++i])
	{
		if (pipe[i] == '|')
		{
			printf ("Syntax error\n");
			exit (1);
		}
		else if (pipe[i] == ' ')
			;
		else
			break;
	}
	return (i);
}

void ft_check_quote_and_pipe (t_commands *cmd)
{
	int i;
	int quote;
	int double_quote;

	cmd->pipes = 0;
	quote = 1;
	double_quote = 1;
	i = -1;
	while (cmd->unparsed[++i])
	{
		if (cmd->unparsed[i] == '\'' && double_quote > 0)
			quote *= -1;
		else if (cmd->unparsed[i] == '\"' && quote > 0)
			double_quote *= -1;
		else if (cmd->unparsed[i] == '|' && quote > 0 && double_quote > 0)
		{
			i += ft_check_after_pipe (&cmd->unparsed[i]);
			cmd->pipes++;
		}
	}
	if (quote < 0 || double_quote < 0)
		printf ("\nError in quote\n");
	return;
}

void	ft_parse (t_commands *cmd)
{
	int	i;

	i = -1;
	ft_check_quote_and_pipe (cmd);
	while (cmd->unparsed[++i])
	{
		;
	}

}

int	main (void)
{
	t_commands *cmd;
	cmd = malloc (sizeof (cmd));
	while (1)
	{
		cmd->unparsed = ft_prompt (0);
 		ft_parse (cmd);
		printf ("%s\n",cmd->unparsed);
	}
}
