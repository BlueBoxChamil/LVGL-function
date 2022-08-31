/*
 * @Author: BlueBoxChamil 283040422@qq.com
 * @Date: 2022-08-30 10:10:26
 * @LastEditors: BlueBoxChamil 283040422@qq.com
 * @LastEditTime: 2022-08-30 17:22:48
 * @FilePath: \20220826\src\grid_func.h
 * @Description:
 *
 * Copyright (c) 2022 by BlueBoxChamil 283040422@qq.com, All Rights Reserved.
 */
#ifndef _GRID_MAIN_H_
#define _GRID_MAIN_H_

#include "lvgl.h"
#include <Arduino.h>

#include "current_clock.h"
#include "grid_led.h"
#include "gravity_line.h"
#include "grid_img.h"

void main_grid_demo(lv_obj_t *parent);
void main_grid_button_func_init();
void main_grid_button_func_0_init();
void main_grid_button_func_1_init();
void main_grid_button_func_2_init();
void main_grid_button_func_3_init();
void main_grid_button_func_4_init();
void main_grid_button_func_5_init();
void main_grid_button_func_6_init();
void main_grid_button_func_7_init();
void main_grid_button_func_8_init();

void main_grid_button_func_0_callback(lv_event_t *event);
void main_grid_button_func_1_callback(lv_event_t *event);
void main_grid_button_func_2_callback(lv_event_t *event);
void main_grid_button_func_3_callback(lv_event_t *event);

bool is_object_null(lv_obj_t *temp);

lv_obj_t *switch_button(uint8_t col, uint8_t row, lv_obj_t *temp);
lv_obj_t *switch_lable(lv_obj_t *btn_temp, lv_obj_t *label_temp);

#endif
