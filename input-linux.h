/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input-linux.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:59:11 by msariasl          #+#    #+#             */
/*   Updated: 2023/04/30 14:07:27 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_LINUX
# define INPUT_LINUX

enum	EVENTS
{
	EVENT_ON_KEYDOWN = 2,
	EVENT_ON_KEYUP = 3,
	EVENT_ON_MOUSEDOWN = 4,
	EVENT_ON_MOUSEUP = 5,
	EVENT_ON_MOUSEMOVE = 6,
	EVENT_ON_EXPOSE = 12,
	EVENT_ON_DESTROY = 33,
	EVENT_ON_RESIZE = 25
};

enum	KEYS
{
	KEY_ESC = 65307,
	KEY_W = 'w',
	KEY_A = 'a',
	KEY_S = 's',
	KEY_D = 'd',
	KEY_Q = 'q',
	KEY_E = 'e',
	KEY_T = 't',
	KEY_Y = 'y',
	KEY_R = 'r',
	KEY_C = 'c',
	KEY_G = 'g',
	KEY_B = 'b',
	KEY_K = 'k',
	KEY_L = 'l',
	KEY_M = 'm',
	KEY_N = 'n',
	KEY_P = 'p'
};

#endif