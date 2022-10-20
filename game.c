#include "game.h"

void init_game(
	int* player_hp, int* player_att, int* player_def, 
	short inventory[], long* cache,
	int* monster_hp, int* monster_att, int* monster_def) {

	printf("Initialize the game.\n");
	*player_hp = 100;
	*player_att = 10;
	*player_def = 8;
	*cache = 0;

	for (int i = 0; i < INVENTORY_SIZE; ++i)
		inventory[i] = 0;

	*monster_hp = 80;
	*monster_att = 10;
	*monster_def = 8;

	srand(time(NULL));
}

void run_game(
	int* player_hp, int* player_att, int* player_def,
	short inventory[], long* cache,
	int* monster_hp, int* monster_att, int* monster_def) {

	while (1) {
		print_status(
			*player_hp, *player_att, *player_def, inventory,
			*monster_hp, *monster_att, *monster_def);

		int choice = print_menu();

		if (choice == 1)
			attack(player_hp, *player_att, *player_def,
				monster_hp, *monster_att, *monster_def);
		else if (choice == 2)
			defense(player_hp, *player_att, *player_def,
				monster_hp, *monster_att, *monster_def);
		else if (choice == 3) {
			// 1. 팔 아이템의 인덱스를 입력 받는다.
			// 2. 입력 받은 인덱스에 해당하는 배열의 값을
			//    가지고 와서, cache에 더한다 (sell).
			// 3. 배열에서 팔린 아이템의 자리를 0으로 초기화한다.
		}
		else if (choice == 4) {
			printf("Bye bye!\n");
			break;
		}
		else {
			printf("Wrong input\n");
			continue;
		}

		if (*player_hp <= 0) {
			printf("You loose.\n");
			break;
		}
		else if (*monster_hp <= 0) {
			short item = get_item();
			put_item(inventory, item);
			respawn_monster(monster_hp);
			//*monster_hp = 80;
			/*printf("You won.\n");
			break;*/
		}
	}
}

void respawn_monster(int* monster_hp) {
	*monster_hp = 80;
}

int find_empty_slot(short inventory[]) {
	int idx_empty = -1;

	for (int i = 0;i < INVENTORY_SIZE;++i) {
		if (inventory[i] == 0) {
			idx_empty = i;
			break;
		}
	}

	return idx_empty;
}

void put_item(short inventory[], short item) {
	int idx_empty = find_empty_slot(inventory);

	if (idx_empty > -1 && idx_empty < INVENTORY_SIZE)
		inventory[idx_empty] = item;
	else
		printf("Inventorg is full!\n");
}

short get_item() {
	short item = 0;
	double rate = (double)(rand() % 11) / 10.0;

	if (rate < DROP_RATE)
		item = rand() % 51 + 50;

	return item;
}

void print_inventory(short inventory[]) {
	printf("INVENTORY==================\n");
	for (int i = 0;i < INVENTORY_SIZE;++i) {
		printf("%d. %d\t", i, inventory[i]);
	}
	printf("\n===========================\n");
}

void print_status(
	int player_hp, int player_att, int player_def,
	short inventory[],
	int monster_hp, int monster_att, int monster_def) {
	printf("Player status============\n");
	printf("- HP: %d\n", player_hp);
	printf("- ATT: %d\n", player_att);
	printf("- DEF: %d\n", player_def);
	printf("=========================\n");
	print_inventory(inventory);
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
	printf("3. Sell item.\n");
	printf("4. Run.\n");
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

void attack(int* player_hp, int player_att, int player_def,
	int* monster_hp, int monster_att, int monster_def) {
	int damage = calculate_damage(player_att, monster_def, TRUE);

	printf("Hit the monster with damage %d.\n", damage);
	*monster_hp -= damage;

	int cntatt = rand() % 2;
	if (monster_hp > 0 && cntatt) {
		printf("Watch out! Monster's counterattack!\n");
		damage = calculate_damage(monster_att, player_def, FALSE);
		*player_hp -= damage;
		printf("Got damage %d from the mosnter.\n", damage);
	}
}

void defense(int* player_hp, int player_att, int player_def,
	int* monster_hp, int monster_att, int monster_def) {
	int damage = calculate_damage(monster_att, player_def, TRUE);

	printf("Got damage %d from the monster.\n", damage);
	*player_hp -= damage;

	int cntatt = rand() % 2;
	if (player_hp > 0 && cntatt) {
		printf("Let's counterattack.\n");
		damage = calculate_damage(player_att, monster_def, FALSE);
		*monster_hp -= damage;
		printf("Hit the monster with damage %d.\n", damage);
	}
}