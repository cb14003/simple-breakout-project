#include "assets.h"
#include "ball.h"
#include "game.h"
#include "graphics.h"
#include "level.h"
#include "paddle.h"

#include "raylib.h"

void update()
{
    if (game_state == in_game_state) {
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
            move_paddle(-paddle_speed);
        }
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
            move_paddle(paddle_speed);
        }
    }

        if (game_state == menu_state) {

            if (IsKeyPressed(KEY_ENTER)) {
                game_state = level_select_state;
                return;
            }
        }

        if (game_state == level_select_state) {

            for (int i = 0; i < level_count; ++i) {
                if (IsKeyPressed(KEY_ONE + i)) {
                    current_level_index = i;
                    load_level(0);
                    game_state = in_game_state;
                    return;
                }
            }

            if (IsKeyPressed(KEY_M)) {
                game_state = menu_state;
            }
        }

        if (IsKeyPressed(KEY_ESCAPE)) {

            if (game_state == in_game_state) {
                game_state = paused_state;
                return;
            }

            if (game_state == paused_state) {
                game_state = in_game_state;
                return;
            }
        }

        if (game_state == paused_state) {
            if (IsKeyPressed(KEY_M)) {
                game_state = menu_state;
            }

            if (IsKeyPressed(KEY_S)) {
                game_state = level_select_state;
            }

            return;
        }

        if (game_state == in_game_state) {
            move_ball();
        }

        if (game_state == in_game_state) {
            if (!is_ball_inside_level()) {
                load_level();
                PlaySound(lose_sound);
            }
            else if (current_level_blocks == 0) {
                PlaySound(win_sound);
                game_state = victory_state;
                victory_timer = 0.0f;
                return;
            }
        }
    if (game_state == victory_state) {
        victory_timer += GetFrameTime();
        victory_animation_angle += GetFrameTime() * 360.0f;

        if (IsKeyPressed(KEY_ENTER)) {
            load_level(0);
            game_state = in_game_state;
            return;
        }

        if (IsKeyPressed(KEY_N)) {
            if (current_level_index + 1 < level_count) {
                current_level_index++;
                load_level(0);
                game_state = in_game_state;
            }
            return;
        }

        if (IsKeyPressed(KEY_B)) {

            if (current_level_index > 0) {
                current_level_index--;
                load_level(0);
                game_state = in_game_state;
            }
            return;
        }

        if (IsKeyPressed(KEY_S)) {
            game_state = level_select_state;
            return;
        }

        return;
    }
    if (game_state == victory_state) {

        if (!victory_initialized) {
            init_victory_menu();
            victory_initialized = true;
        }

        if (IsKeyPressed(KEY_ENTER)) {
            load_level(0);
            game_state = in_game_state;
            victory_initialized = false;
            return;
        }

        if (IsKeyPressed(KEY_N)) {
            if (current_level_index + 1 < level_count) {
                current_level_index++;
                load_level(0);
                game_state = in_game_state;
                victory_initialized = false;
            }
            return;
        }

        if (IsKeyPressed(KEY_B)) {
            if (current_level_index > 0) {
                current_level_index--;
                load_level(0);
                game_state = in_game_state;
                victory_initialized = false;
            }
            return;
        }

        if (IsKeyPressed(KEY_S)) {
            game_state = level_select_state;
            victory_initialized = false;
            return;
        }

        return;
    }

    }

void draw() {
    switch (game_state) {
    case menu_state:
        draw_menu();
        break;

    case in_game_state:
        draw_level();
        draw_paddle();
        draw_ball();
        draw_ui();
        break;

    case paused_state:
        draw_pause_menu();
        break;

    case victory_state:
        draw_victory_menu();
        break;
    case level_select_state:
        draw_level_select_menu();
        break;
    }
}

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(1280, 720, "Breakout");
    SetExitKey(KEY_Q);
    SetTargetFPS(60);

    load_fonts();
    load_textures();
    load_level();
    load_sounds();

    while (!WindowShouldClose()) {
        BeginDrawing();

        draw();
        update();

        EndDrawing();
    }
    CloseWindow();

    unload_sounds();
    unload_level();
    unload_textures();
    unload_fonts();

    return 0;
}
