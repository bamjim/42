/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:05:54 by mku               #+#    #+#             */
/*   Updated: 2024/11/15 17:02:32 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

typedef	struct s_export
{
	char	*temp;
	char *command1;
	char *command2;
	int	flag;
	int	error_flag;
}t_export;

#endif
