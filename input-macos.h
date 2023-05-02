/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input-macos.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:59:11 by msariasl          #+#    #+#             */
/*   Updated: 2023/05/02 19:05:14 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_MAC
# define INPUT_MAC

enum	EVENTS
{
	EVENT_ON_KEYDOWN = 2,
	EVENT_ON_KEYUP = 3,
	EVENT_ON_MOUSEDOWN = 4,
	EVENT_ON_MOUSEUP = 5,
	EVENT_ON_MOUSEMOVE = 6,
	EVENT_ON_EXPOSE = 12,
	EVENT_ON_DESTROY = 17,
	EVENT_ON_RESIZE = 25
};

enum	KEYS
{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_Q = 12,
	KEY_E = 14,
	KEY_T = 17,
	KEY_Y = 16,
	KEY_R = 15,
	KEY_C = 8,
	KEY_G = 5,
	KEY_B = 11,
	KEY_K = 40,
	KEY_L = 37,
	KEY_M = 46,
	KEY_N = 45,
	KEY_P = 35
};

enum MASKS
{
	KEY_DOWN_MASK = 0
};


#endif