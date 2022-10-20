#pragma once
#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define INVENTORY_SIZE 10
#define DROP_RATE 0.5

void print_status(int, int, int, short[], int, int, int);
void respawn_monster(int*);
int find_empty_slot(short[]);
void put_item(short[], short);
short get_item();
void print_inventory(short[]);
int print_menu();
int calculate_damage(int, int, int);
void attack(int*, int, int, int*, int, int);
void defense(int*, int, int, int*, int, int);
void init_game(int*, int*, int*, short[], long*, int*, int*, int*);
void run_game(int*, int*, int*, short[], long*, int*, int*, int*);

#endif