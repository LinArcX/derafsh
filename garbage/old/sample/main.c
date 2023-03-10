#include <stdio.h>
#include <math.h>

#include <nuboBase.h>
#include <nuboForm.h>
#include <nuboLabel.h>
#include <nuboEditBox.h>
#include <nuboDropDown.h>

void
process_key_escape(void)
{
    glfwSetWindowShouldClose(fBase.window, 1);
}

void
process_key_q(void)
{
    glfwSetWindowShouldClose(fBase.window, 1);
}

void
custom_background()
{
    const GLfloat color[] = { (float)sin(fBase.current_time) * 0.5f + 0.5f,
                              (float)cos(fBase.current_time) * 0.5f + 0.5f,
                              0.0f,
                              1.0f };
    glClearBufferfv(GL_COLOR, 0, color);
}

void
key_manager()
{
    process_key(GLFW_KEY_ESCAPE, GLFW_PRESS, process_key_escape);
    process_key(GLFW_KEY_Q, GLFW_PRESS, process_key_q);
}

void
windows_changed(void)
{
    printf("window's size changed.\n");
    glViewport(0, 0, fBase.width, fBase.height);
}

void
startup(void)
{
    printf("App started.\n");
}

void
render()
{
    // printf("current time: %f\n", fBase.current_time);
    key_manager();
    set_background_color(DARK_GRAY);

    // Form
    nubo_form("Form", 0, 0, fBase.width, fBase.height);
    nubo_label("Login", 40, 40, 280, 20);
    nubo_edit_box("Email", 40, 80, 300, 30);
    nubo_edit_box("Name", 40, 120, 300, 30);
    nubo_drop_down("Effects", 40, 160, 280, 28);

    // drawCheckBox(vg, "Remember me", x,y, 140,28);
    // drawButton(vg, ICON_LOGIN, "Sign in", x+138, y, 140, 28,
    // nvgRGBA(0,96,128,255));
}

void
shutdown(void)
{
    printf("App finished.\n");
}

int
main(int argc, char *argv[])
{
    nubo_init("Sample", 800, 600, startup, render, shutdown, windows_changed);
    return 0;
}
