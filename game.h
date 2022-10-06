#pragma once
#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

extern int player_hp;
extern int player_att;
extern int player_def;

extern int monster_hp;
extern int monster_att;
extern int monster_def;

void print_status(int, int, int, int, int, int);
int print_menu();
int calculate_damage(int, int, int);
void attack();
void defense();

#endif