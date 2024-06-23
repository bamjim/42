/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_number_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mku <mku@student.42gyeongsan.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:56:31 by mku               #+#    #+#             */
/*   Updated: 2024/06/23 20:56:35 by mku              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char **nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (*nptr[i] == '-' || *nptr[i] == '+')
	{
		if (*nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (*nptr[i] >= '0' && *nptr[i] <= '9')
	{
		result = result * 10 + (*nptr[i] - '0');
		i++;
	}
	return (result * sign);
}