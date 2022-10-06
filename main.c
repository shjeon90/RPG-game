/*
- Author: Seungho Jeon
- Data: 22.09.29
- Description: Basic RGP game
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int player_hp = 100;
	int player_att = 10;
	int player_def = 8;

	int monster_hp = 80;
	int monster_att = 10;
	int monster_def = 8;

	srand(time(NULL));

	while (1) {
		printf("Player status============\n");
		printf("- HP: %d\n", player_hp);
		printf("- ATT: %d\n", player_att);
		printf("- DEF: %d\n", player_def);
		printf("=========================\n");
		printf("Monster status============\n");
		printf("- HP: %d\n", monster_hp);
		printf("- ATT: %d\n", monster_att);
		printf("- DEF: %d\n", monster_def);
		printf("=========================\n");

		printf("Menu=====================\n");
		printf("1. Attack.\n");
		printf("2. Defense.\n");
		printf("3. Run.\n");
		printf("=========================\n");

		int choice;
		scanf("%d", &choice);

		if (choice == 1) {
			int damage = player_att - monster_def;
			int is_critical = rand() % 2;

			if (is_critical) damage *= 2;

			printf("Hit the monster with damage %d.\n", damage);
			monster_hp -= damage;

			int cntatt = rand() % 2;
			if (monster_hp > 0 && cntatt) {
				printf("Watch out! Monster's counterattack!\n");
				damage = monster_att - player_def;
				player_hp -= damage;
				printf("Got damage %d from the mosnter.\n", damage);
			}
		}
		else if (choice == 2) {
			int damage = monster_att - player_def;
			int is_critical = rand() % 2;

			if (is_critical) damage *= 2;

			printf("Got damage %d from the monster.\n", damage);
			player_hp -= damage;

			int cntatt = rand() % 2;
			if (player_hp > 0 && cntatt) {
				printf("Let's counterattack.\n");
				damage = player_att - monster_def;
				monster_hp -= damage;
				printf("Hit the monster with damage %d.\n", damage);
			}
		}
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