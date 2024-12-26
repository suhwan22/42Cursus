/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:37:19 by suhkim            #+#    #+#             */
/*   Updated: 2022/10/05 22:23:47 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_base_printf(unsigned long nbr, char *base, int len, int *bytes)
{
	if (nbr / len)
		ft_putnbr_base_printf(nbr / len, base, len, bytes);
	*bytes += write (1, (base + nbr % len), 1);
	return (*bytes);
}
