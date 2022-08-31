/*
 * @Author: BlueBoxChamil 283040422@qq.com
 * @Date: 2022-08-30 13:52:45
 * @LastEditors: BlueBoxChamil 283040422@qq.com
 * @LastEditTime: 2022-08-30 14:09:41
 * @FilePath: \20220826\src\grid_led.h
 * @Description:
 *
 * Copyright (c) 2022 by BlueBoxChamil 283040422@qq.com, All Rights Reserved.
 */
#ifndef _GRID_LED_H_
#define _GRID_LED_H_

#include "lvgl.h"
#include <Arduino.h>
#include "grid_func.h"

void grid_led_init(lv_obj_t *parent);
void led_event_handler(lv_event_t *e);

#endif