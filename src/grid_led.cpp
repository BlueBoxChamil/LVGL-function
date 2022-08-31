/*
 * @Author: BlueBoxChamil 283040422@qq.com
 * @Date: 2022-08-30 13:52:14
 * @LastEditors: BlueBoxChamil 283040422@qq.com
 * @LastEditTime: 2022-08-31 10:29:10
 * @FilePath: \20220826\src\grid_led.cpp
 * @Description:
 *
 * Copyright (c) 2022 by BlueBoxChamil 283040422@qq.com, All Rights Reserved.
 */
#include "grid_led.h"

static lv_obj_t *grid_led_btn;
static lv_obj_t *back_btn;

bool is_led_open = false;

/**
 * @brief led灯初始化
 *
 * @param parent
 */
void grid_led_init(lv_obj_t *parent)
{
    grid_led_btn = lv_btn_create(parent);
    lv_obj_set_size(grid_led_btn, 100, 50);
    //   lv_obj_set_pos(grid_led, 10, 80);
    lv_obj_center(grid_led_btn);
    lv_obj_add_event_cb(grid_led_btn, led_event_handler, LV_EVENT_ALL, NULL);

    lv_obj_t *label = lv_label_create(grid_led_btn);
    lv_label_set_text(label, "LED");
    lv_obj_center(label);
    lv_obj_add_flag(label, LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_CLICKABLE);

    pinMode(LED_BUILTIN, OUTPUT);
    // digitalWrite(LED_BUILTIN, LOW);

    back_btn = lv_btn_create(parent);
    lv_obj_set_size(back_btn, 100, 50);
    // lv_obj_set_pos(back_btn, 100, 80);
    lv_obj_align(back_btn, LV_ALIGN_CENTER, 0, 80);
    lv_obj_add_event_cb(back_btn, back_button_func, LV_EVENT_ALL, NULL);

    lv_obj_t *label1 = lv_label_create(back_btn);
    lv_label_set_text(label1, "back");
    lv_obj_center(label1);
    lv_obj_add_flag(label1, LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_CLICKABLE);
}

/**
 * @brief led灯按钮回调函数
 *
 * @param e
 */
void led_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED)
    {
        // Serial.printf("Clicked\r\n");
        if (is_led_open == false)
        {
            is_led_open = true;
            digitalWrite(LED_BUILTIN, HIGH);
        }
        else
        {
            is_led_open = false;
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
}

/**
 * @brief 返回按钮回调函数
 *
 * @param event
 */
static void back_button_func(lv_event_t *event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if (code == LV_EVENT_CLICKED)
    {
        lv_obj_del(grid_led_btn);
        lv_obj_del(back_btn);
        main_grid_demo(lv_scr_act());
    }
}