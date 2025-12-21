#include "ball.h"
#include "assets.h"
#include "level.h"
#include "paddle.h"
#include "game.h"

#include "raylib.h"

#include <cmath>
#include <numbers>

extern int player_score;

void spawn_ball()
{
    for (int column = 0; column < current_level.columns; column++) {
        for (int row = 0; row < current_level.rows; row++) {
            if (get_level_cell(row, column) == BALL) {
                set_level_cell(row, column, VOID);
                ball_pos = { static_cast<float>(column), static_cast<float>(row) };
                constexpr float ball_launch_angle_radians = ball_launch_angle_degrees * (std::numbers::pi_v<float> / 180.0f);
                ball_vel.y = -ball_launch_vel_mag * std::sin(ball_launch_angle_radians);
                ball_vel.x = (rand() % 2 == 0) ? ball_launch_vel_mag * std::cos(ball_launch_angle_radians) : -ball_launch_vel_mag * std::cos(ball_launch_angle_radians);
                goto outer_loop_end;
            }
        }
    }
outer_loop_end:;
}

void move_ball()
{
    Vector2 next_ball_pos = {
        ball_pos.x + ball_vel.x,
        ball_pos.y + ball_vel.y
    };

    bool played_wall_sound = false;
    bool played_block_sound = false;

    if (is_colliding_with_level_cell(next_ball_pos, ball_size, WALL)) {
        if (is_colliding_with_level_cell({ next_ball_pos.x, ball_pos.y }, ball_size, WALL)) {
            ball_vel.x = -ball_vel.x;
            next_ball_pos.x = std::round(next_ball_pos.x);
            if (!played_wall_sound) {
                PlaySound(wall_hit_sound);
                played_wall_sound = true;
            }
        }
        if (is_colliding_with_level_cell({ ball_pos.x, next_ball_pos.y }, ball_size, WALL)) {
            ball_vel.y = -ball_vel.y;
            next_ball_pos.y = std::round(next_ball_pos.y);
            if (!played_wall_sound) {
                PlaySound(wall_hit_sound);
                played_wall_sound = true;
            }
        }
    } else if (is_colliding_with_level_cell(next_ball_pos, ball_size, BLOCKS)) {
        char& temp = get_colliding_level_cell(next_ball_pos, ball_size, BLOCKS);

        if (is_colliding_with_level_cell({ next_ball_pos.x, ball_pos.y }, ball_size, BLOCKS)) {
            ball_vel.x = -ball_vel.x;
            next_ball_pos.x = std::round(next_ball_pos.x);
        }
        if (is_colliding_with_level_cell({ ball_pos.x, next_ball_pos.y }, ball_size, BLOCKS)) {
            ball_vel.y = -ball_vel.y;
            next_ball_pos.y = std::round(next_ball_pos.y);
        }

        temp = VOID;
        --current_level_blocks;
        player_score += 100;

        if (!played_block_sound) {
            PlaySound(block_hit_sound);
            played_block_sound = true;
        }
    } else if (is_colliding_with_paddle(next_ball_pos, ball_size)) {
        ball_vel.y = -std::abs(ball_vel.y);
        PlaySound(paddle_hit_sound);

    } else if (is_colliding_with_paddle(next_ball_pos, ball_size)) {
        ball_vel.y = -std::abs(ball_vel.y);
    }

    ball_pos = next_ball_pos;
}

bool is_ball_inside_level()
{
    return is_inside_level(static_cast<int>(ball_pos.y), static_cast<int>(ball_pos.x));
}
