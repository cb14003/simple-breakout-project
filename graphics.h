#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "raylib.h"

extern Vector2 screen_size;
extern float screen_scale;
extern float cell_size;
extern Vector2 shift_to_center;
extern size_t game_frame;

void derive_graphics_metrics();

void draw_menu();
void draw_ui();
void draw_level();
void draw_paddle();
void draw_ball();
void draw_pause_menu();
void init_victory_menu();
void draw_victory_menu();
void draw_level_select_menu();
void draw_game_over_menu();
void draw_shop_menu();

#endif // GRAPHICS_H
