/*
- Author: Seungho Jeon
- Data: 22.10.06
- Description: Basic RGP game
- Patch note:
	1. function
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int player_hp = 100;
int player_att = 10;
int player_def = 8;

int monster_hp = 80;
int monster_att = 10;
int monster_def = 8;

void print_status(int, int, int, int ,int, int);
int print_menu();
int calculate_damage(int, int, int);
void attack();
void defense();

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

void print_status(int player_hp, int player_att, int player_def,
	int monster_hp, int monster_att, int monster_def) {
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
}

int print_menu() {
	printf("Menu=====================\n");
	printf("1. Attack.\n");
	printf("2. Defense.\n");
	printf("3. Run.\n");
	printf("=========================\n");

	int choice;
	scanf("%d", &choice);

	return choice;
}

int calculate_damage(int att, int def, int do_critical) {
	int damage = att - def;
	int is_critical = rand() % 2;

	if (is_critical && do_critical) damage *= 2;

	return damage;
}

void attack() {
	int damage = calculate_damage(player_att, monster_def, TRUE);

	printf("Hit the monster with damage %d.\n", damage);
	monster_hp -= damage;

	int cntatt = rand() % 2;
	if (monster_hp > 0 && cntatt) {
		printf("Watch out! Monster's counterattack!\n");
		damage = calculate_damage(monster_att, player_def, FALSE);
		player_hp -= damage;
		printf("Got damage %d from the mosnter.\n", damage);
	}
}

void defense() {
	int damage = calculate_damage(monster_att, player_def, TRUE);

	printf("Got damage %d from the monster.\n", damage);
	player_hp -= damage;

	int cntatt = rand() % 2;
	if (player_hp > 0 && cntatt) {
		printf("Let's counterattack.\n");
		damage = calculate_damage(player_att, monster_def, FALSE);
		monster_hp -= damage;
		printf("Hit the monster with damage %d.\n", damage);
	}
}