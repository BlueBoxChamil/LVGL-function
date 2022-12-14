/*
 * @Author: BlueBoxChamil 283040422@qq.com
 * @Date: 2022-08-26 14:08:37
 * @LastEditors: BlueBoxChamil 283040422@qq.com
 * @LastEditTime: 2022-08-31 10:36:16
 * @FilePath: \20220826\src\main.cpp
 * @Description:
 *
 * Copyright (c) 2022 by BlueBoxChamil 283040422@qq.com, All Rights Reserved.
 */
#include <Arduino.h>
#include <Arduino_GFX_Library.h>
#include <CST816S.h>

#include "grid_func.h"

void lvgl_creat_init();
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);

Arduino_DataBus *bus = new Arduino_ESP32SPI(12 /* DC */, 15 /* CS */, 14 /* SCK */, 13 /* MOSI */, -1 /* MISO */, HSPI /* spi_num */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, 33 /* RST */, 0, true, 240, 320);

#define I2C_SDA 21
#define I2C_SCL 22
#define RST_N_PIN 5
#define INT_N_PIN 4

CST816S touch(I2C_SDA, I2C_SCL, RST_N_PIN, INT_N_PIN);

void test_for_demo()
{
  //主题界面
  lv_theme_default_init(NULL, lv_palette_main(LV_PALETTE_GREEN), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK,
                        LV_FONT_DEFAULT);

  //主界面
  main_grid_demo(lv_scr_act());
}

void setup()
{
  //串口初始化
  Serial.begin(115200);
  //触摸屏引脚初始化
  touch.begin();

  // lcd屏幕初始化
  gfx->begin();
  gfx->fillScreen(RED);

  //获取网络时间
  wifi_time_get();

  // mpu6050初始化
  mpu6050_init();

  // lvgl初始化配置
  lvgl_creat_init();

  //控件配置
  test_for_demo();
}

void loop()
{
  lv_timer_handler(); /* let the GUI do its work */
  delay(5);
}

/**
 * @brief 显示屏刷新初始化
 *
 * @param disp
 * @param area
 * @param color_p
 */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
  gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#else
  gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#endif

  lv_disp_flush_ready(disp);
}

/**
 * @brief 初始化lvgl
 *
 */
void lvgl_creat_init()
{
  static lv_color_t *disp_draw_buf;
  static lv_disp_draw_buf_t draw_buf;
  static lv_disp_drv_t disp_drv;

  lv_init();
  uint32_t screenWidth = gfx->width();
  uint32_t screenHeight = gfx->height();

#ifdef ESP32
  disp_draw_buf = (lv_color_t *)heap_caps_malloc(sizeof(lv_color_t) * screenWidth * 10, MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
#else
  disp_draw_buf = (lv_color_t *)malloc(sizeof(lv_color_t) * screenWidth * 10);
#endif

  if (!disp_draw_buf)
  {
    Serial.println("LVGL disp_draw_buf allocate failed!");
  }
  else
  {
    //初始化显示缓冲区
    lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, screenWidth * 10);

    /* Initialize the display */
    lv_disp_drv_init(&disp_drv);
    /* Change the following line to your display resolution */
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /* Initialize the (dummy) input device driver */
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    //   /* Create simple label */
    //       *label = lv_label_create(lv_scr_act());
    //   lv_label_set_text(label, "Hello Arduino! (V8.0.X)");
    //   lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 20);
  }
}

/*Read the touchpad*/
/**
 * @brief 触摸屏初始化
 *
 * @param indev_driver
 * @param data
 */
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  uint16_t touchX, touchY;

  bool touched = touch.available();

  if (!touched)
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    // if(touch.gesture() == "SINGLE CLICK")
    {
      data->state = LV_INDEV_STATE_PR;

      /*Set the coordinates*/
      data->point.x = touch.data.x;
      data->point.y = touch.data.y;
      // Serial.print("Data x ");
      // Serial.println(touch.data.x);

      // Serial.print("Data y ");
      // Serial.println(touch.data.y);
    }
  }
}