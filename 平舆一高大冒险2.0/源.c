#include <stdio.h>
#include <stdlib.h>
void exit_game() {
	printf("��ȥ���ޣ�");
	exit(0);
}

struct Player {
	int x;
	int y;
	int math;
	int chinese;
	int english;
	int biology;
	int physics;
	int chemistry;
};


int map[3][6] = {
	{6,5,4,3,2,1},
	{7,0,0,0,0,8},
	{7,0,9,9,0,8},

};

void map_0() {
	printf("�����ǹ���̨�㳡������Դ���ë�����������ڹ���̨��˯����\n");
}
void map_1() {
	printf("������һ�࣬�����˲��е��˲�~\n");
}
void map_2() {
	printf("�����Ƕ��࣬�������ǳ����~\n");
}
void map_3() {
	printf("���������࣬�꣡��Ҫ�����˹��ף�\n");
}
void map_4() {
	printf("�������İ࣬�ۣ�������������һ��~\n");

}
void map_5() {
	printf("��������࣬�ף������κ����ڡ�\n");
}
void map_6() {
	printf("���������࣬Ψһ�ľ�Ӣ�Ŀư�~\n");
}
void map_7() {
	printf("������22���¥��������η~\n");
}
void map_8() {
	printf("�������հ��21�Ļ���壬����������������ͷ­������Ѫ��");
}
void map_9() {
	printf("������һ�ߵĴ��ţ��ο�ʼ�ĵط���\n");
}

void on_map(struct Player* player) {
	int cell = map[player->y][player->x];

	switch (cell) {
	case 0:map_0(); break;
	case 1:map_1(); break;
	case 2:map_2(); break;
	case 3:map_3(); break;
	case 4:map_4(); break;
	case 5:map_5(); break;
	case 6:map_6(); break;
	case 7:map_7(); break;
	case 8:map_8(); break;
	case 9:map_9(); break;
	default:
		printf("���ڿ����У����ż���\n");
		break;
	}
}


void choice(struct Player* player) {
	int cell = map[player->y][player->x];
	if (cell == 4) {
		printf("�Ƿ�ʼѧϰ��1��������ԣ�����,2��ѧϰ��ѧ��ƨ��\n");



		int choice2;
		scanf_s("%d\n", &choice2);
		if (choice2 == 1) {
			printf("ѧʲô��1:math,2:chines,3:english,4:biology,5:physics,6:chemistry\n");
			int choice3;
			scanf_s("%d\n", &choice3);
			printf("��ϲ����ѧ��һ�죡\n");
		}
		else {
			printf("�����˳��������!\n");
		}

	}

	return;
}
int cols = 6;
int rows = 3;
void move_player(struct Player* player, int x, int y) {
	if (x < 0 || x >= cols || y < 0 || y >= rows) {
		printf("���ǣ�ǰ�������ûд�أ����ż�~\n");
		return;
	}
	player->x = x;
	player->y = y;
	printf("�㿴\n", map[y][x]);
	on_map(player);

}

void listen_move(struct Player* player) {
	printf("ȥ���η�����4����6����,8���ϣ�2���£���\n");
	int dir;
	scanf_s("%d", &dir);
	int x = player->x;
	int y = player->y;
	switch (dir) {
	case 4:
		printf("�������������~\n");
		move_player(player, x - 1, y);
		break;
	case 6:
		printf("���������ұ���~\n");
		move_player(player, x + 1, y);
		break;
	case 8:
		printf("��������ǰ���룡\n");
		move_player(player, x, y - 1);
		break;
	case 2:
		printf("�������Ӻ����\n");
		move_player(player, x, y + 1);
		break;
	default:
		printf("�����ˣ�������~\n");
		break;

	}
}



void listen_input(struct Player* player) {
	printf("����Ҫ��ʲô��1:�鿴��ǰλ�ã�4:ѧϰ��2���ƶ���9:��У��\n");
	int type;
	scanf_s("%d", &type);
	switch (type) {
	case 1:on_map(player); break;
	case 2:listen_move(player); break;
	case 4:choice(player); break;
	case 9:exit_game(); break;
	default:
		printf("��Ч���룡\n");
		break;
	}
}


struct Player init_player() {
	struct Player player;
	player.x = 2;
	player.y = 0;
	player.math = 10;
	player.chinese = 10;
	player.english = 10;
	player.biology = 10;
	player.physics = 10;
	player.chemistry = 10;

	return player;
}

int main() {
	struct Player player = init_player();
	while (1) {
		//��ѭ��
		listen_input(&player);

	}
}
