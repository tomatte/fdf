/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrandao <dbrandao@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:16:53 by dbrandao          #+#    #+#             */
/*   Updated: 2022/12/07 17:00:25 by dbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	move_lines(char **text, int lines)
{
	int	i;

	i = 0;
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
	i = 0;
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

int	get_hexa_from_text(char *text)
{
	move_spaces(&text);
	if (*text == '-')
		text++;
	while (ft_isdigit(*text))
		text++;
	if (*text == ',')
		text++;
	return (ft_hextoi(text));
}

int	get_color(int line, int column, char *text)
{
	int	color;

	if (!text || line < 0 || column < 0)
		return (DEFAULT_COLOR);
	move_lines(&text, line);
	move_columns(&text, column);
	if (!text)
		return (DEFAULT_COLOR);
	color = get_hexa_from_text(text);
	if (color < 0)
		return (DEFAULT_COLOR);
	return (color);
}
