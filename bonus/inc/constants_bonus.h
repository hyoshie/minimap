/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:05:28 by user42            #+#    #+#             */
/*   Updated: 2022/03/16 11:27:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_BONUS_H
# define CONSTANTS_BONUS_H

/*	Window and Map Info	*/
# define TILE_SIZE 32
# define MAP_NUM_COLS 20
# define MAP_NUM_ROWS 13
# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 416
# define WINDOW_ASPECT_RATIO 0.65
# define WINDOW_NAME "####Cub3D####"
# define MINIMAP_SCALE 0.375
# define MINIMAP_WIDTH_MAX 240
# define MINIMAP_HEIGHT_MAX 156

/*	Cubfile Info	*/
# define NUM_DESIGN_ELEMS 6
# define MAX_MAP_COLS 256
# define MAX_MAP_ROWS 256

/*	Render Info	*/
# define NUM_RAYS WINDOW_WIDTH
# define PLAYER_RADIUS 10
# define MOVE_STEP 2
# define START_SHADING_DISTANCE 200

/*	Color	*/
# define RED 0x00FF0000
# define YELLOW 0x00FFFF00
# define ORANGE 0x00FF6500
# define GRAY 0x002F3128
# define LIGHTGRAY 0x00D3D3D3
# define OFFWHITE 0x00FFF9EE
# define BLACK 0x00000000
# define SKYBLUE 0x0090D7EC
# define KOGETYA 0x006A4332

/*	Keycode	*/
# define KEY_ESC 0xff1b
# define KEY_A 0x61
# define KEY_D 0x64
# define KEY_S 0x73
# define KEY_W 0x77
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53

/*	Xwindow	*/
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOUSE_MOVE 6
# define WIN_DESTROY 17
# define KEY_PRESS_MASK 1
# define KEY_RELEASE_MASK 2
# define MOUSE_MOVE_MASK 64
# define STRUCTURE_NOTIFY_MASK 131072

/*	Message	*/
# define MSG_WALL_COLLISION "Ouch! What a hard wall!"

/*	Exit Message	*/
# define EM_ESC "(｡-ω-)ﾉsee you again… "
# define EM_ARG "Error\nUsage ./cub3d xxx.cub"
# define EM_READ_XPM "Error\nCan't read xpm file"
# define EM_OPEN "Error\nopen: Can't read file"
# define EM_GNL "Error\ngnl: Can't read line"
# define EM_RGB "Error\nrgb numbers need to be integer between 0 and 255"
# define EM_MANY_RGB "Error\nToo many RGB numbers"
# define EM_FEW_RGB "Error\nRGB needs to have 3 numbers"
# define EM_MISS_DES "Error\nDesign info is missing"
# define EM_WRONG_DES "Error\nDesign info is wrong"
# define EM_MAP_BIG "Error\nMap is too big (Upto 256 * 256)"
# define EM_MAP_NOT_CLOSED "Error\nMap is not closed by wall"
# define EM_MANY_PLAYERS "Error\nToo many players"
# define EM_NO_PLAYER "Error\nOne player is needed"
# define EM_MLX "Error\nSomething is wrong in mlx function"
# define EM_DESIGN "Error\nTexture or color settings is invalid"
# define EM_NO_MAP "Error\nCannot find valid map"
# define EM_MAP_CHAR "Error\nMap has wrong charactor"
# define EM_MAP_DUP "Error\nOnly one map is accepted"

#endif /* CONSTANTS_H */
