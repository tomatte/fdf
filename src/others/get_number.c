#include "../fdf.h"

/*  - create A get_word(int line, int word, char *text) function
	* lines are separated by line-breaks and words by spaces
	* just use this logic to create the function  */

static void	move_lines(char **text, int lines)
{
	int	i;

	i = 1;
	while (i++ < lines)
	{
		*text = ft_strchr(*text, '\n');
		if (!*text || !**text)
			return ;
		(*text)++;
	}
}

static void	move_spaces(char **s)
{
	while (**s == ' ' || **s == '\t')
	{
		(*s)++;
	}
}

static void	move_columns(char **text, int columns)
{
	int	i;

	if (!*text)
		return ;
	move_spaces(text);
	i = 1;
	while (i++ < columns)
	{
		while (**text != ' ' && **text != '\t' && **text)
		{
			(*text)++;
		}
		move_spaces(text);
		if (!**text)
			return ;
	}
}

int	get_number(int line, int column, char *text)
{
	int	number;

	if (!text || line < 0 || column < 0)
		return (0);
	move_lines(&text, line);
	move_columns(&text, column);
	if (!text)
		return (0);
	return (ft_atoi(text));
}

