/*
 * @Author: BlueBoxChamil 283040422@qq.com
 * @Date: 2022-08-23 16:02:29
 * @LastEditors: BlueBoxChamil 283040422@qq.com
 * @LastEditTime: 2022-08-31 10:13:50
 * @FilePath: \20220826\src\current_clock.h
 * @Description:
 *
 * Copyright (c) 2022 by BlueBoxChamil 283040422@qq.com, All Rights Reserved.
 */
#ifndef _CURRENT_CLOCK_H_
#define _CURRENT_CLOCK_H_

#include <Arduino.h>
#include <NTPClient.h>
#include "esp_wifi.h"
#include <WiFiUdp.h>
#include "WiFi.h"
#include <lvgl.h>

#include "grid_func.h"

//定义一个存储时间的结构体并重命名
typedef struct get_current_time GetCurrentTime;
struct get_current_time
{
    int time_hour;
    int time_mintues;
    int time_seconds;
};

GetCurrentTime now_time();
void lvgl_clock(lv_obj_t *parent);
void wifi_time_get();

static void set_value_sec(void *indic, int32_t v);

static void back_button_func(lv_event_t *event);

#endif