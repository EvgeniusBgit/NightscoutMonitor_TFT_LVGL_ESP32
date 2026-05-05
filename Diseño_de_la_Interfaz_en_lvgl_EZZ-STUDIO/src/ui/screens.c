#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff464653), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 4, 7);
            lv_obj_set_size(obj, 310, 71);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // icon_location_11p
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_location_11p = obj;
            lv_obj_set_pos(obj, 12, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_icon_location_11p);
        }
        {
            // label_city
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_city = obj;
            lv_obj_set_pos(obj, 28, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Ciudad");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff0f0f0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // label_time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_time = obj;
            lv_obj_set_pos(obj, 8, 22);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "00:00:00");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff0f0f0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_letter_space(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // image_icon_weather
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.image_icon_weather = obj;
            lv_obj_set_pos(obj, 159, 4);
            lv_obj_set_size(obj, 33, 35);
            lv_img_set_src(obj, &img_icon_01d_22p);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        }
        {
            // label_date
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_date = obj;
            lv_obj_set_pos(obj, 8, 57);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Hoy");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff0f0f0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // NS_Panel
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ns_panel = obj;
            lv_obj_set_pos(obj, 4, 80);
            lv_obj_set_size(obj, 310, 133);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_105, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffefcc12), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0b38c4), LV_PART_MAIN | LV_STATE_PRESSED);
        }
        {
            // label_feels_like
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_feels_like = obj;
            lv_obj_set_pos(obj, 183, 39);
            lv_obj_set_size(obj, 37, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "00.0 °C");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff0f0f0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 243, 9);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_icon_humd_22p);
        }
        {
            // label_humidity
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_humidity = obj;
            lv_obj_set_pos(obj, 259, 12);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "00%");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff0f0f0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 243, 38);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_icon_wind_11p);
        }
        {
            // label_temperature
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_temperature = obj;
            lv_obj_set_pos(obj, 187, 12);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "00.0°C");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff0f0f0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 168, 56);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_icon_pressure_11p);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 243, 55);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_icon_visibility_11p);
        }
        {
            // label_wind
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_wind = obj;
            lv_obj_set_pos(obj, 249, 38);
            lv_obj_set_size(obj, 54, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "00.0 m/s");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff0f0f0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // label_pressure
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_pressure = obj;
            lv_obj_set_pos(obj, 183, 56);
            lv_obj_set_size(obj, 51, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "0000 hPa");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff0f0f0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // label_visibility
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_visibility = obj;
            lv_obj_set_pos(obj, 257, 56);
            lv_obj_set_size(obj, 43, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "00.0 km");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff0f0f0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 4, 216);
            lv_obj_set_size(obj, 20, 20);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // btn_view_config
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.btn_view_config = obj;
                    lv_obj_set_pos(obj, -12, -12);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_setting_18);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 47, 217);
            lv_obj_set_size(obj, 264, 20);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // label_info
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_info = obj;
            lv_obj_set_pos(obj, 56, 220);
            lv_obj_set_size(obj, 246, LV_SIZE_CONTENT);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
            lv_label_set_text(obj, "Ultima actualizacion: 00:00:00 (Correcto)");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff0f0f0), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 168, 38);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_feels_like_11p);
        }
        {
            // NS_current
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.ns_current = obj;
            lv_obj_set_pos(obj, 7, 88);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "00.0");
            lv_obj_set_style_text_font(obj, &ui_font_montserrat_bold_105, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfffaf4f4), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // NS
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.ns = obj;
            lv_obj_set_pos(obj, 239, 144);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ns_st_72p);
        }
        {
            // NS_delta
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.ns_delta = obj;
            lv_obj_set_pos(obj, 257, 92);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, " +00,0");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff3eeee), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 239, 90);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_ns_delta_22p);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 26, 216);
            lv_obj_set_size(obj, 19, 20);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // btn_view_config_1
                    lv_obj_t *obj = lv_img_create(parent_obj);
                    objects.btn_view_config_1 = obj;
                    lv_obj_set_pos(obj, -12, -12);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_img_set_src(obj, &img_vol_down18);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                }
            }
        }
        {
            // NS_data
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.ns_data = obj;
            lv_obj_set_pos(obj, 86, 190);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "00.00.00 00:00");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff3eeee), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // icon_alarm on
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.icon_alarm_on = obj;
            lv_obj_set_pos(obj, 124, 10);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_alarm_on11);
        }
    }
}

void tick_screen_main() {
}

void create_screen_grafico() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.grafico = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff464653), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // grap_texto
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.grap_texto = obj;
            lv_obj_set_pos(obj, 43, 14);
            lv_obj_set_size(obj, 206, 16);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
            lv_label_set_text(obj, "--");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // ns_grap_alert_min
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_precise_t line_points[] = {
                { 1, 0 },
                { 272, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.ns_grap_alert_min = obj;
            lv_obj_set_pos(obj, 30, 175);
            lv_obj_set_size(obj, 272, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_dash_gap(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_dash_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // label_y
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_y = obj;
            lv_obj_set_pos(obj, 7, 18);
            lv_obj_set_size(obj, 53, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "mmol/L");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // grap_cont
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.grap_cont = obj;
            lv_obj_set_pos(obj, 0, 30);
            lv_obj_set_size(obj, 320, 210);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // grap_line
                    lv_obj_t *obj = lv_chart_create(parent_obj);
                    objects.grap_line = obj;
                    lv_obj_set_pos(obj, 23, 4);
                    lv_obj_set_size(obj, 289, 176);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff272727), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff3a3741), LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // grap_alert
                            lv_obj_t *obj = lv_line_create(parent_obj);
                            static lv_point_precise_t line_points[] = {
                                { 1, 0 },
                                { 272, 0 }
                            };
                            lv_line_set_points(obj, line_points, 2);
                            objects.grap_alert = obj;
                            lv_obj_set_pos(obj, 1, 175);
                            lv_obj_set_size(obj, 272, LV_SIZE_CONTENT);
                            lv_obj_set_style_line_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_dash_gap(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_dash_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // grap_scale_x
                    lv_obj_t *obj = lv_scale_create(parent_obj);
                    objects.grap_scale_x = obj;
                    lv_obj_set_pos(obj, 24, 179);
                    lv_obj_set_size(obj, 287, 23);
                    lv_scale_set_mode(obj, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
                    lv_scale_set_range(obj, 0, 12);
                    lv_scale_set_total_tick_count(obj, 13);
                    lv_scale_set_major_tick_every(obj, 1);
                    lv_scale_set_label_show(obj, true);
                    lv_obj_set_style_length(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xffffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_base_dir(obj, LV_BASE_DIR_RTL, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_ADDITIVE, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // grap_scale_y
                    lv_obj_t *obj = lv_scale_create(parent_obj);
                    objects.grap_scale_y = obj;
                    lv_obj_set_pos(obj, -6, 5);
                    lv_obj_set_size(obj, 30, 175);
                    lv_scale_set_mode(obj, LV_SCALE_MODE_VERTICAL_LEFT);
                    lv_scale_set_range(obj, 0, 15);
                    lv_scale_set_total_tick_count(obj, 16);
                    lv_scale_set_major_tick_every(obj, 1);
                    lv_scale_set_label_show(obj, true);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_base_dir(obj, LV_BASE_DIR_LTR, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xffffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_width(obj, 1, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_length(obj, 10, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_width(obj, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xffffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // label_x
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_x = obj;
            lv_obj_set_pos(obj, 287, 229);
            lv_obj_set_size(obj, 33, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "hour");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff00), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // label_texto
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_texto = obj;
            lv_obj_set_pos(obj, 258, 11);
            lv_obj_set_size(obj, 53, 20);
            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL_CIRCULAR);
            lv_label_set_text(obj, "");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff00ff0f), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_base_dir(obj, LV_BASE_DIR_LTR, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_outline_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // ns_grap_alert_max
            lv_obj_t *obj = lv_line_create(parent_obj);
            static lv_point_precise_t line_points[] = {
                { 1, 0 },
                { 272, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            objects.ns_grap_alert_max = obj;
            lv_obj_set_pos(obj, 30, 169);
            lv_obj_set_size(obj, 272, LV_SIZE_CONTENT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xffd9bc14), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_dash_gap(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_dash_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_grafico() {
}

void create_screen_alarm_page() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.alarm_page = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff464653), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj4 = obj;
                    lv_obj_set_pos(obj, 5, 7);
                    lv_obj_set_size(obj, 310, 22);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj5 = obj;
                    lv_obj_set_pos(obj, 134, 10);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Alarm");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj6 = obj;
                    lv_obj_set_pos(obj, 3, 35);
                    lv_obj_set_size(obj, 310, 199);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // alarmSwich
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    objects.alarm_swich = obj;
                    lv_obj_set_pos(obj, 19, 55);
                    lv_obj_set_size(obj, 96, LV_SIZE_CONTENT);
                    lv_dropdown_set_options(obj, "On\nOff");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // label_estado
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_estado = obj;
                    lv_obj_set_pos(obj, 5, 216);
                    lv_obj_set_size(obj, 172, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // btn_alarm_ok
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_alarm_ok = obj;
                    lv_obj_set_pos(obj, 210, 202);
                    lv_obj_set_size(obj, 84, 28);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "OK");
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // txt alarm_hh
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_alarm_hh = obj;
                    lv_obj_set_pos(obj, 39, 90);
                    lv_obj_set_size(obj, 99, 48);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_text(obj, "08");
                    lv_textarea_set_placeholder_text(obj, "0");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // txt alarm_mm
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_alarm_mm = obj;
                    lv_obj_set_pos(obj, 179, 90);
                    lv_obj_set_size(obj, 99, 48);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_text(obj, "00");
                    lv_textarea_set_placeholder_text(obj, "0");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // txt_alarm repit
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_alarm_repit = obj;
                    lv_obj_set_pos(obj, 202, 56);
                    lv_obj_set_size(obj, 99, 26);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_text(obj, "Repit");
                    lv_textarea_set_placeholder_text(obj, "0");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_ON_FOCUS);
                    lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 152, 88);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, ":");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // alarm is mon
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.alarm_is_mon = obj;
            lv_obj_set_pos(obj, 37, 171);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 32, 148);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Mon  Tue  Wed  Thu   Fri   Sat   Sun");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // alarm is Tues
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.alarm_is_tues = obj;
            lv_obj_set_pos(obj, 76, 171);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // alarm is_Wed
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.alarm_is_wed = obj;
            lv_obj_set_pos(obj, 111, 171);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // alarm is_Thu
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.alarm_is_thu = obj;
            lv_obj_set_pos(obj, 152, 171);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // alarm is_Fri
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.alarm_is_fri = obj;
            lv_obj_set_pos(obj, 191, 171);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // alarm is Sat
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.alarm_is_sat = obj;
            lv_obj_set_pos(obj, 223, 172);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // alarm is Sun
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.alarm_is_sun = obj;
            lv_obj_set_pos(obj, 259, 171);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_alarm_page() {
}

void create_screen_config() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.config = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
            lv_obj_set_scroll_snap_x(obj, LV_DIR_VER);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff464653), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj10 = obj;
                    lv_obj_set_pos(obj, -8, -5);
                    lv_obj_set_size(obj, 310, 22);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj11 = obj;
                    lv_obj_set_pos(obj, 48, -2);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Configurar credenciales");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj12 = obj;
                    lv_obj_set_pos(obj, -8, 21);
                    lv_obj_set_size(obj, 310, 57);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj13 = obj;
                    lv_obj_set_pos(obj, -1, 24);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "WiFi");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // txt_ssid
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_ssid = obj;
                    lv_obj_set_pos(obj, -1, 42);
                    lv_obj_set_size(obj, 141, 18);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "SSID");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // txt_pass
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_pass = obj;
                    lv_obj_set_pos(obj, 158, 42);
                    lv_obj_set_size(obj, 138, 28);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "Password");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj14 = obj;
                    lv_obj_set_pos(obj, -10, 212);
                    lv_obj_set_size(obj, 310, 157);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj15 = obj;
                    lv_obj_set_pos(obj, -1, 213);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "NightScout");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // txt_ns_api
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_ns_api = obj;
                    lv_obj_set_pos(obj, -2, 232);
                    lv_obj_set_size(obj, 297, 28);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "NightScout Adress");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // txt_ns_secret
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_ns_secret = obj;
                    lv_obj_set_pos(obj, -2, 265);
                    lv_obj_set_size(obj, 297, 28);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "NightScout Secret");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj16 = obj;
                    lv_obj_set_pos(obj, -8, 82);
                    lv_obj_set_size(obj, 310, 124);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_PRESSED);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj17 = obj;
                    lv_obj_set_pos(obj, -1, 84);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "OpenWeatherMap");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // txt_api_weather
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_api_weather = obj;
                    lv_obj_set_pos(obj, -1, 103);
                    lv_obj_set_size(obj, 296, 28);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "API");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // txt_ciudad
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_ciudad = obj;
                    lv_obj_set_pos(obj, -1, 137);
                    lv_obj_set_size(obj, 148, 28);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "Ciudad");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // txt_pais
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_pais = obj;
                    lv_obj_set_pos(obj, 158, 137);
                    lv_obj_set_size(obj, 137, 28);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "Pais");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // txt_hora
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.txt_hora = obj;
                    lv_obj_set_pos(obj, -1, 171);
                    lv_obj_set_size(obj, 58, 28);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "UTC");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // NS_Alert_max
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.ns_alert_max = obj;
                    lv_obj_set_pos(obj, 0, 300);
                    lv_obj_set_size(obj, 142, 28);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "Alert max");
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // label_est_conf
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.label_est_conf = obj;
                    lv_obj_set_pos(obj, 79, 408);
                    lv_obj_set_size(obj, 159, 16);
                    lv_label_set_text(obj, "");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff00ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj18 = obj;
                    lv_obj_set_pos(obj, -8, 383);
                    lv_obj_set_size(obj, 310, 55);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff262635), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj19 = obj;
                    lv_obj_set_pos(obj, 0, 386);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Backlight");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // my_label_slider
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.my_label_slider = obj;
                    lv_obj_set_pos(obj, 141, 385);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "--");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // brillo
                    lv_obj_t *obj = lv_slider_create(parent_obj);
                    objects.brillo = obj;
                    lv_obj_set_pos(obj, 8, 410);
                    lv_obj_set_size(obj, 276, 14);
                    lv_slider_set_range(obj, 2, 250);
                    lv_slider_set_value(obj, 250, LV_ANIM_OFF);
                }
                {
                    // btn_gurdar_Cren
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_gurdar_cren = obj;
                    lv_obj_set_pos(obj, 40, 462);
                    lv_obj_set_size(obj, 92, 37);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff40cc04), LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Apply");
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // btn_salir_cren
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.btn_salir_cren = obj;
                    lv_obj_set_pos(obj, 163, 462);
                    lv_obj_set_size(obj, 92, 37);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_label_set_text(obj, "Back");
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // NS_Alert_min
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.ns_alert_min = obj;
                    lv_obj_set_pos(obj, 153, 299);
                    lv_obj_set_size(obj, 142, 28);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "Alert min");
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // NS_Alert_after min
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.ns_alert_after_min = obj;
                    lv_obj_set_pos(obj, 0, 334);
                    lv_obj_set_size(obj, 142, 28);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "Alert after min");
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // NS_Repeat through
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.ns_repeat_through = obj;
                    lv_obj_set_pos(obj, 152, 333);
                    lv_obj_set_size(obj, 142, 28);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "Repeat through");
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // teclado
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.teclado = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 122);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS|LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLL_ELASTIC);
            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_config() {
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_grafico();
    create_screen_alarm_page();
    create_screen_config();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_grafico,
    tick_screen_alarm_page,
    tick_screen_config,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
