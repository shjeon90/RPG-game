/*
- Author: Seungho Jeon
- Data: 22.10.20
- Description: Basic RGP game
- Patch note:
	1. introducing pointer variables.
*/
#include "game.h"

int main() {
	int player_hp;
	int player_att;
	int player_def;

	int monster_hp;
	int monster_att;
	int monster_def;

	init_game(&player_hp, &player_att, &player_def, 
		&monster_hp, &monster_att, &monster_def);
	run_game(&player_hp, &player_att, &player_def,
		&monster_hp, &monster_att, &monster_def);

	return 0;
}