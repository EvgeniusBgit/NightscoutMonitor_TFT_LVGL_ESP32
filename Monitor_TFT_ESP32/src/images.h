#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_icon_location_11p;
extern const lv_img_dsc_t img_icon_temp_22p;
extern const lv_img_dsc_t img_icon_max_11p;
extern const lv_img_dsc_t img_icon_min_11p;
extern const lv_img_dsc_t img_icon_humd_22p;
extern const lv_img_dsc_t img_icon_wind_11p;
extern const lv_img_dsc_t img_icon_pressure_11p;
extern const lv_img_dsc_t img_icon_visibility_11p;
extern const lv_img_dsc_t img_logo_lvgl;
extern const lv_img_dsc_t img_logo_procs;
extern const lv_img_dsc_t img_icon_01d_22p;
extern const lv_img_dsc_t img_icon_01n_22p;
extern const lv_img_dsc_t img_icon_02d_22p;
extern const lv_img_dsc_t img_icon_02n_22p;
extern const lv_img_dsc_t img_icon_03d_03n_22p;
extern const lv_img_dsc_t img_icon_04d_04n_22p;
extern const lv_img_dsc_t img_icon_09d_09n_22p;
extern const lv_img_dsc_t img_icon_10d_22p;
extern const lv_img_dsc_t img_icon_10n_22p;
extern const lv_img_dsc_t img_icon_11d_11n_22p;
extern const lv_img_dsc_t img_icon_13d_13n_22p;
extern const lv_img_dsc_t img_icon_50d_50n_22p;
extern const lv_img_dsc_t img_setting_18;
extern const lv_img_dsc_t img_feels_like_11p;
extern const lv_img_dsc_t img_ns_2down_72p;
extern const lv_img_dsc_t img_ns_2up_72p;
extern const lv_img_dsc_t img_ns_down_72p;
extern const lv_img_dsc_t img_ns_light_down;
extern const lv_img_dsc_t img_ns_light_up;
extern const lv_img_dsc_t img_ns_st_72p;
extern const lv_img_dsc_t img_ns_up_72p;
extern const lv_img_dsc_t img_ns_delta_22p;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[32];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/