SET(SOURCES ui_Screen1.c
    ui_theme_manager.c
    ui_themes.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_img_home_png.c
    fonts/ui_font_Sans.c
    fonts/ui_font_Sans30.c)

add_library(ui ${SOURCES})
