/*
- Author: Seungho Jeon
- Data: 22.10.06
- Description: Basic RGP game
- Patch note:
	1. function
*/
#include "game.h"

int main() {
	srand(time(NULL));

	while (1) {
		print_status(player_hp, player_att, player_def,
			monster_hp, monster_att, monster_def);

		int choice = print_menu();

		if (choice == 1) attack();
		else if (choice == 2) defense();
		else if (choice == 3) {
			printf("Bye bye!\n");
			break;
		}
		else {
			printf("Wrong input\n");
			continue;
		}

		if (player_hp <= 0) {
			printf("You loose.\n");
			break;
		}
		else if (monster_hp <= 0) {
			printf("You won.\n");
			break;
		}
	}

	return 0;
}

