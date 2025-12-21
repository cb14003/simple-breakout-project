#include "assets.h"
#include "game.h"

#include "raylib.h"

void load_fonts()
{
    menu_font = LoadFontEx("data/fonts/ARCADECLASSIC.TTF", 256, nullptr, 0);
}

void unload_fonts()
{
    UnloadFont(menu_font);
}

void load_textures()
{
    wall_texture = LoadTexture("data/images/wall.png");
    void_texture = LoadTexture("data/images/void.png");
    block_texture = LoadTexture("data/images/block.png");
    paddle_texture = LoadTexture("data/images/paddle.png");

    for (size_t i = 0; i < ballSkinCount; ++i) {
        ball_skins[i] = LoadTexture(ballSkins[i].texturePath.c_str());
    }

    ball_sprite.frame_count = 1;
    ball_sprite.frames_to_skip = 0;
    ball_sprite.frame_index = 0;
    ball_sprite.frames_skipped = 0;
    ball_sprite.loop = false;
    ball_sprite.prev_game_frame = 0;

    ball_sprite.frames = new Texture2D[1];
    ball_sprite.frames[0] = ball_skins[0];
    }

void unload_textures()
{
    UnloadTexture(wall_texture);
    UnloadTexture(void_texture);
    UnloadTexture(block_texture);
    UnloadTexture(paddle_texture);
    unload_sprite(ball_sprite);

    for (size_t i = 0; i < ballSkinCount; ++i) {
        UnloadTexture(ball_skins[i]);
    }

    if (ball_sprite.frames != nullptr) {
        delete[] ball_sprite.frames;
        ball_sprite.frames = nullptr;
    }
}

void load_sounds()
{
    InitAudioDevice();
    win_sound = LoadSound("data/sounds/win.wav");
    lose_sound = LoadSound("data/sounds/lose.wav");
    victory_sound = LoadSound("data/sounds/victory.wav");
    selecting_sound = LoadSound("data/sounds/selecting.wav");
    losing_sound = LoadSound("data/sounds/losing.wav");
    wall_hit_sound = LoadSound("data/sounds/wall_hit.wav");
    block_hit_sound  = LoadSound("data/sounds/block_hit.wav");
    paddle_hit_sound = LoadSound("data/sounds/paddle_hit.wav");
    background_sound = LoadSound("data/sounds/background.wav");
}

void unload_sounds()
{
    UnloadSound(win_sound);
    UnloadSound(lose_sound);
    UnloadSound(victory_sound);
    UnloadSound(selecting_sound);
    UnloadSound(losing_sound);
    UnloadSound(wall_hit_sound);
    UnloadSound(block_hit_sound);
    UnloadSound(paddle_hit_sound);
    UnloadSound(background_sound);
    CloseAudioDevice();
}
