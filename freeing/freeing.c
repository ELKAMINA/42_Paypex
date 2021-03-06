/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:56:58 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/01 18:28:46 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_pipex.h"

void	freeing(char *paths[])
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		paths[i] = NULL;
		i++;
	}
	free(paths);
	paths = NULL;
}

void	freeing_execution(char *paths[], char *cmd, char *cmd_opt[])
{
	freeing(cmd_opt);
	free(cmd);
	freeing(paths);
	error_msgs();
}

void	freeing_cmd(char *paths[], char *cmd, char *cmd_opt[])
{
	freeing(cmd_opt);
	free(cmd);
	freeing(paths);
	cmd_not_found(ERR_CMD);
}
