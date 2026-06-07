/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 04:47:39 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/21 04:58:10 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	big;

	big = (long long)n;
	if (big < 0)
	{
		ft_putchar_fd('-', fd);
		big *= -1;
	}
	if (big >= 10)
		ft_putnbr_fd((int)(big / 10), fd);
	ft_putchar_fd((char)('0' + (big % 10)), fd);
}
