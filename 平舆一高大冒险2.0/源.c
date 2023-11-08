#include <stdio.h>
#include <stdlib.h>
void exit_game() {
	printf("回去重修！");
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
	printf("这里是国旗台广场，你可以打羽毛球，甚至是躺在国旗台上睡觉！\n");
}
void map_1() {
	printf("这里是一班，都是人才中的人才~\n");
}
void map_2() {
	printf("这里是二班，班主任是抽象的~\n");
}
void map_3() {
	printf("这里是三班，嘘！不要惊动了光谱！\n");
}
void map_4() {
	printf("这里是四班，哇，班主任最抽象的一集~\n");

}
void map_5() {
	printf("这里是五班，咦？班主任好像不在。\n");
}
void map_6() {
	printf("这里是六班，唯一的精英文科班~\n");
}
void map_7() {
	printf("这里是22届的楼，后生可畏~\n");
}
void map_8() {
	printf("这里是普班和21的混合体，曾经有人在这里抛头颅、洒热血。");
}
void map_9() {
	printf("这里是一高的大门，梦开始的地方！\n");
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
		printf("还在开发中，憋着急！\n");
		break;
	}
}


void choice(struct Player* player) {
	int cell = map[player->y][player->x];
	if (cell == 4) {
		printf("是否开始学习？1：无需多言，开卷！,2：学习？学个屁！\n");



		int choice2;
		scanf_s("%d\n", &choice2);
		if (choice2 == 1) {
			printf("学什么？1:math,2:chines,3:english,4:biology,5:physics,6:chemistry\n");
			int choice3;
			scanf_s("%d\n", &choice3);
			printf("恭喜你又学了一天！\n");
		}
		else {
			printf("请你退出这个教室!\n");
		}

	}

	return;
}
int cols = 6;
int rows = 3;
void move_player(struct Player* player, int x, int y) {
	if (x < 0 || x >= cols || y < 0 || y >= rows) {
		printf("哥们，前面的区域还没写呢，憋着急~\n");
		return;
	}
	player->x = x;
	player->y = y;
	printf("你看\n", map[y][x]);
	on_map(player);

}

void listen_move(struct Player* player) {
	printf("去往何方？（4向左，6向右,8向上，2向下）：\n");
	int dir;
	scanf_s("%d", &dir);
	int x = player->x;
	int y = player->y;
	switch (dir) {
	case 4:
		printf("公主王子左边请~\n");
		move_player(player, x - 1, y);
		break;
	case 6:
		printf("公主王子右边请~\n");
		move_player(player, x + 1, y);
		break;
	case 8:
		printf("公主王子前面请！\n");
		move_player(player, x, y - 1);
		break;
	case 2:
		printf("公主王子后边请\n");
		move_player(player, x, y + 1);
		break;
	default:
		printf("在做了，在做了~\n");
		break;

	}
}



void listen_input(struct Player* player) {
	printf("你想要干什么？1:查看当前位置，4:学习，2：移动，9:出校门\n");
	int type;
	scanf_s("%d", &type);
	switch (type) {
	case 1:on_map(player); break;
	case 2:listen_move(player); break;
	case 4:choice(player); break;
	case 9:exit_game(); break;
	default:
		printf("无效输入！\n");
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
		//死循环
		listen_input(&player);

	}
}
