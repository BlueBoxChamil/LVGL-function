/*
 * @Author: BlueBoxChamil 283040422@qq.com
 * @Date: 2022-08-30 10:10:08
 * @LastEditors: BlueBoxChamil 283040422@qq.com
 * @LastEditTime: 2022-08-31 10:25:31
 * @FilePath: \20220826\src\grid_func.cpp
 * @Description:
 *
 * Copyright (c) 2022 by BlueBoxChamil 283040422@qq.com, All Rights Reserved.
 */

#include "grid_func.h"

lv_obj_t *main_grid_cont;
lv_obj_t *btn0, *btn1, *btn2, *btn3, *btn4, *btn5, *btn6, *btn7, *btn8;
lv_obj_t *label_0, *label_1, *label_2, *label_3, *label_4, *label_5, *label_6, *label_7, *label_8;

/**
 * @brief 3*3主界面
 *
 * @param parent
 */
void main_grid_demo(lv_obj_t *parent)
{
    static lv_coord_t col_dsc[] = {51, 51, 51, LV_GRID_TEMPLATE_LAST}; // 3行，分别为：51,51,51 像素的宽度
    static lv_coord_t row_dsc[] = {72, 72, 72, LV_GRID_TEMPLATE_LAST}; // 3列，分别为：72,72,72 像素的高度

    /*Create a main_grid_container with grid*/
    main_grid_cont = lv_obj_create(parent);

    //设置对象网格布局行描述数组
    lv_obj_set_style_grid_column_dsc_array(main_grid_cont, col_dsc, 0);
    //设置对象网格布局列描述数组
    lv_obj_set_style_grid_row_dsc_array(main_grid_cont, row_dsc, 0);
    //设置网格大小
    lv_obj_set_size(main_grid_cont, 200, 270);
    lv_obj_center(main_grid_cont);
    //设置对象使用网格布局
    lv_obj_set_layout(main_grid_cont, LV_LAYOUT_GRID);

    lv_obj_t *label;
    lv_obj_t *obj;

    uint32_t i;
    for (i = 0; i < 9; i++)
    {
        uint8_t col = i % 3;
        uint8_t row = i / 3;

        obj = lv_btn_create(main_grid_cont);
        //将创建好的按钮指针指向对应按钮
        switch_button(col, row, obj);

        lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, col, 1,
                             LV_GRID_ALIGN_STRETCH, row, 1);

        label = lv_label_create(obj);
        //将创建好的label指针指向对应label
        switch_lable(obj, label);

        lv_label_set_text_fmt(label, "c%d, r%d", col, row);
        lv_obj_center(label);
    }
    //主界面按钮文字初始化
    main_grid_button_func_init();
}
/**
 * @brief 主界面按钮文字初始化
 *
 */
void main_grid_button_func_init()
{
    main_grid_button_func_0_init();
    main_grid_button_func_1_init();
    main_grid_button_func_2_init();
    main_grid_button_func_3_init();
}

/**
 * @brief 时间按钮初始化
 *
 */
void main_grid_button_func_0_init()
{
    //判断按钮是否为空
    if (is_object_null(btn0) == true)
        return;
    //判断按钮文字是否为空
    if (is_object_null(label_0) == true)
        return;
    //重新修改按钮文字
    lv_label_set_text_fmt(label_0, "TIME");
    //确保在触摸到按钮上的子级label时，触摸状态可以传递到父级按钮
    lv_obj_add_flag(label_0, LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_CLICKABLE);
    //创建按钮回调函数
    lv_obj_add_event_cb(btn0, main_grid_button_func_0_callback, LV_EVENT_ALL, NULL);
}

/**
 * @brief LED按钮初始化
 *
 */
void main_grid_button_func_1_init()
{
    if (is_object_null(btn1) == true)
    {
        return;
    }

    if (is_object_null(label_1) == true)
    {
        return;
    }

    lv_label_set_text_fmt(label_1, "LED");
    lv_obj_add_flag(label_1, LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(btn1, main_grid_button_func_1_callback, LV_EVENT_ALL, NULL);
}

/**
 * @brief 重力圈按钮初始化
 *
 */
void main_grid_button_func_2_init()
{
    if (is_object_null(btn2) == true)
    {
        return;
    }

    if (is_object_null(label_2) == true)
    {
        return;
    }

    lv_label_set_text_fmt(label_2, "ARC");
    lv_obj_add_flag(label_2, LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(btn2, main_grid_button_func_2_callback, LV_EVENT_ALL, NULL);
}

/**
 * @brief 图片库初始化
 *
 */
void main_grid_button_func_3_init()
{
    if (is_object_null(btn3) == true)
    {
        return;
    }

    if (is_object_null(label_3) == true)
    {
        return;
    }

    lv_label_set_text_fmt(label_3, "IMG");
    lv_obj_add_flag(label_3, LV_OBJ_FLAG_EVENT_BUBBLE | LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(btn3, main_grid_button_func_3_callback, LV_EVENT_ALL, NULL);
}
void main_grid_button_func_4_init()
{
}
void main_grid_button_func_5_init()
{
}
void main_grid_button_func_6_init()
{
}
void main_grid_button_func_7_init()
{
}
void main_grid_button_func_8_init()
{
}

/**
 * @brief 时间按钮回调函数
 *
 * @param event
 */
void main_grid_button_func_0_callback(lv_event_t *event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if (code == LV_EVENT_CLICKED)
    {
        //删除主界面
        lv_obj_del(main_grid_cont);
        //创建按钮新界面
        lvgl_clock(lv_scr_act());
    }
}

/**
 * @brief led按钮回调函数
 *
 * @param event
 */
void main_grid_button_func_1_callback(lv_event_t *event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if (code == LV_EVENT_CLICKED)
    {
        lv_obj_del(main_grid_cont);
        grid_led_init(lv_scr_act());
    }
}

/**
 * @brief 重力圈按钮回调函数
 *
 * @param event
 */
void main_grid_button_func_2_callback(lv_event_t *event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if (code == LV_EVENT_CLICKED)
    {
        lv_obj_del(main_grid_cont);
        mpu6050_start(lv_scr_act());
    }
}

/**
 * @brief 图片库按钮初始化
 *
 * @param event
 */
void main_grid_button_func_3_callback(lv_event_t *event)
{
    lv_event_code_t code = lv_event_get_code(event);
    if (code == LV_EVENT_CLICKED)
    {
        lv_obj_del(main_grid_cont);
        grid_img_init(lv_scr_act());
    }
}

/**
 * @brief 判断对象是否为空
 *
 * @param temp
 * @return true
 * @return false
 */
bool is_object_null(lv_obj_t *temp)
{
    if (temp == NULL)
        return true;
    else
        return false;
}

/**
 * @brief 将行列按钮对应到按钮对象上
 *
 * @param col
 * @param row
 * @param temp
 * @return lv_obj_t*
 */
lv_obj_t *switch_button(uint8_t col, uint8_t row, lv_obj_t *temp)
{
    uint8_t btn_num = row * 3 + col;

    switch (btn_num)
    {
    case 0:
        btn0 = temp;
        break;
    case 1:
        btn1 = temp;
        break;
    case 2:
        btn2 = temp;
        break;
    case 3:
        btn3 = temp;
        break;
    case 4:
        btn4 = temp;
        break;
    case 5:
        btn5 = temp;
        break;
    case 6:
        btn6 = temp;
        break;
    case 7:
        btn7 = temp;
        break;
    case 8:
        btn8 = temp;
        break;

    default:
        break;
    }
    return temp;
}

/**
 * @brief 将label对应到按钮对象上
 *
 * @param btn_temp
 * @param label_temp
 * @return lv_obj_t*
 */
lv_obj_t *switch_lable(lv_obj_t *btn_temp, lv_obj_t *label_temp)
{
    if (btn_temp == btn0)
    {
        label_0 = label_temp;
    }
    else if (btn_temp == btn1)
    {
        label_1 = label_temp;
    }
    else if (btn_temp == btn2)
    {
        label_2 = label_temp;
    }
    else if (btn_temp == btn3)
    {
        label_3 = label_temp;
    }
    else if (btn_temp == btn4)
    {
        label_4 = label_temp;
    }
    else if (btn_temp == btn5)
    {
        label_5 = label_temp;
    }
    else if (btn_temp == btn6)
    {
        label_6 = label_temp;
    }
    else if (btn_temp == btn7)
    {
        label_7 = label_temp;
    }
    else if (btn_temp == btn8)
    {
        label_8 = label_temp;
    }

    return label_temp;
}