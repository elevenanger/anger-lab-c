/*
 * @author Anger
 * @date 2022/9/5
 * @brief 随机漫步
 * 初始化一个 10 * 10 的字符数组矩阵
 * 初始化的元素都为 '.'
 * 程序必须随机从一个元素移动到另一个元素
 * 每次都向 上 下 左 右 随机移动一个位置
 * 已访问过的元素按照 A B C D ... 的顺序进行标记
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define ROW_NUM 10
#define COL_NUM 10
#define DIRECTIONS 4
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

/* 当前元素的横坐标和纵坐标 */
int row_val, col_val;
char matrix[ROW_NUM][COL_NUM];
/* 漫步者 */
char foo;

/**
 * 检查是否坐标是否超出矩阵范围
 * @param x 横坐标
 * @param y 纵坐标
 * @return 检查结果
 */
bool check_bounds(int x, int y) {
    if (x < 0 || y < 0 ||
        x > (COL_NUM - 1) || y > (ROW_NUM - 1))
        return false;
    return true;
}


/**
 * 检查能否向上移动
 */
bool check_move_up() {
    if (check_bounds(col_val, row_val - 1))
        if (matrix[col_val][row_val - 1] == '.')
            return true;
    return false;
}

/**
 * 检查能否向下移动
 */
bool check_move_down() {
    if (check_bounds(col_val, row_val + 1))
        if (matrix[col_val][row_val + 1] == '.')
            return true;
    return false;
}

/**
 * 检查能否向左移动
 */
bool check_move_left() {
     if (check_bounds(col_val - 1, row_val))
        if (matrix[col_val - 1][row_val] == '.')
            return true;
    return false;
}

/**
 * 检查能否向右移动
 */
bool check_move_right() {
      if (check_bounds(col_val + 1, row_val))
        if (matrix[col_val + 1][row_val] == '.')
            return true;
    return false;
}

/**
 * 检查能否移动
 */
bool check_move() {
    if (check_move_up() || check_move_down() ||
        check_move_left() || check_move_right()) return true;
    return false;
}

/**
 * 上移
 */
bool move_up() {
    if (!check_move_up())
        return false;
    row_val -= 1;
    return true;
}

/**
 * 下移
 */
bool move_down() {
    if (!check_move_down())
        return false;
    row_val += 1;
    return true;
}

/**
 * 左移
 */
bool move_left() {
    if (!check_move_left())
        return false;
    col_val -= 1;
    return true;
}

/**
 * 右移
 */
bool move_right() {
    if (!check_move_right())
        return false;
    col_val += 1;
    return true;
}

void print_matrix() {
    for (int i = 0; i < ROW_NUM; ++i) {
        for (int j = 0; j < COL_NUM; ++j) {
            printf("%c ", matrix[i][j]);
        }
        puts("");
    }

}

int main(void) {

    /* 初始化所有的元素为 '.' */
    for (int i = 0; i < ROW_NUM; ++i)
        for (int j = 0; j < COL_NUM; ++j)
            matrix[i][j] = '.';

    srand((unsigned) time(NULL));

    /* 初始化横坐标和纵坐标 */
    col_val = rand() % ROW_NUM;
    row_val = rand() % COL_NUM;
    foo = 'A';
    matrix[col_val][row_val] = foo;

    /* 每次移动 + 1 直到到达 Z */
    while (++foo <= 'Z') {
        /* 当前位置无法继续移动则游戏结束 */
        if (!check_move()) {
            printf("game over!\n");
            break;
        }

        /* 设置一个是否移动的变量，循环移动动作，直到移动成功 */
        bool moved = false;
        while (!moved) {
            switch (rand() % DIRECTIONS) {
                case UP: moved = move_up(); break;
                case DOWN: moved = move_down(); break;
                case LEFT: moved = move_left(); break;
                case RIGHT: moved = move_right(); break;
            }
        }
        /* 坐标移动后将当前位置的字母设置为当前的字母 */
        matrix[col_val][row_val] = foo;
    }

    print_matrix();

    return 0;
}