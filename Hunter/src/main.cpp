/*
** EPITECH PROJECT, 2018
** delivery
** File description:
** main.c
*/

#include "../include/all.hpp"

void init_tex_sp(lib_t *strG, anim_t *strA)
{
    init_1strg(strG);
    init_2strg(strG);
    init_1stra(strA);
    init_duck(strA);
}

void init_params(param_t *params)
{
    sf::VideoMode mode = {1920, 1080, 32};
    params->score = 0;
    params->loop = 0;
    params->loop2 = 0;
    params->level = 0;
    params->mouse.x = 600;
    params->mouse.y = 600;
    params->intro = 1;
    params->duel.on_off = 0;
    params->font.loadFromFile("resources/arial.ttf");
    params->window =
        std::make_unique<sf::RenderWindow>(mode, "HUNTER", sf::Style::Default);
}

void init_sound(sound_t *sound)
{
    sound->mario.openFromFile("resources/mario.ogg");
    sound->shoot.openFromFile("resources/shoot.ogg");
    sound->reload.openFromFile("resources/sound/reload.ogg");
    sound->death.openFromFile("resources/sound/death.ogg");
    sound->level1.openFromFile("resources/sound/level1.ogg");
    sound->explode.openFromFile("resources/explode.ogg");
    sound->level.openFromFile("resources/level_sound.ogg");
    sound->start.openFromFile("resources/sound/start.ogg");
    sound->level1.setVolume(30);
}

int main(int argc, char const *argv[])
{
    param_t params;
    lib_t strG;
    sound_t sound;
    anim_t strA;

    init_tex_sp(&strG, &strA);
    init_sound(&sound);
    init_params(&params);
    life_init(&params);
    body(&params, &strG, &sound, &strA);
}
