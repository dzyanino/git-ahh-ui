#define CLAY_IMPLEMENTATION // ok so first the clay implementation macro

#include "lib/clay.h" // then import clay just after
#include "lib/renderers/raylib.c" // import the renderer

#include "include/theme/colors.h"

#include "include/welcome/welcome.h"

void HandleClayErrors(Clay_ErrorData error_data) {
  printf("%s", error_data.errorText.chars);
  switch (error_data.errorType) {
    case CLAY_ERROR_TYPE_INTERNAL_ERROR:
      printf("Internal error le baba");
    default:
      printf("\n====\nJEREO FA MISY RAHA TSY MAZAVA\n====\n");
  }
} // make an error handler to give it to clay initializer so that i can debug (or catch probably) errors better

/*
 *
 * MAIN FUNCTION
 */
int main(void) {
  Clay_Raylib_Initialize(800, 600, "Clay with Raylib", FLAG_WINDOW_RESIZABLE); // initialize raylib window

  SetTargetFPS(60);

  uint64_t clay_required_memory = Clay_MinMemorySize(); // get the required memory to launch clay

  Clay_Arena clay_memory = (Clay_Arena) {
    .memory = malloc(clay_required_memory),
    .capacity = clay_required_memory
  }; // make an arena with the memory size

  Clay_Initialize(
    clay_memory,
    (Clay_Dimensions) {
      .width = GetScreenWidth(),
      .height = GetScreenHeight() },
    (Clay_ErrorHandler) { HandleClayErrors }
  ); // initialize clay with the arena (memory), and its default dimensions and the error handler (catcher)

  Font fonts[8];
  fonts[0] = LoadFont("assets/fonts/BricolageGrotesque-Regular.ttf");
  fonts[1] = LoadFont("assets/fonts/BricolageGrotesque-SemiBold.ttf");
  fonts[2] = LoadFont("assets/fonts/BricolageGrotesque-Bold.ttf");
  fonts[3] = LoadFont("assets/fonts/Fraunces-Bold.ttf");
  fonts[4] = LoadFont("assets/fonts/Fraunces-Italic.ttf");
  fonts[5] = LoadFont("assets/fonts/SpaceMono-Regular.ttf");
  fonts[6] = LoadFont("assets/fonts/SpaceMono-Bold.ttf");
  fonts[7] = LoadFont("assets/fonts/SpaceMono-Italic.ttf");

  Clay_SetMeasureTextFunction(Raylib_MeasureText, fonts);
  // call this function to tell clay how to properly size the fonts
  // so that it knows how to layout CLAY_TEXT for example
  // here i'll just use the provided callback function from raylib's renderer

  while (!WindowShouldClose()) { // main loop

    float delta_time = GetFrameTime();

    Clay_SetLayoutDimensions((Clay_Dimensions) {
      .width = GetScreenWidth(),
      .height = GetScreenHeight() }); // update the layout every frame to match the current window's dimensions

    Clay_BeginLayout();
    // the layouts (ui hierarchy) should be put between here and `Clay_EndLayout`

    CLAY(
      CLAY_ID("main-container"),
      { .layout = {
          .sizing = {
            .width = CLAY_SIZING_GROW(0),
            .height = CLAY_SIZING_GROW(0) },
          .padding = CLAY_PADDING_ALL(16),
          .childGap = 16 },
        .backgroundColor = theme_colors[M_COLOR_DARK_BACKGROUND] }
    ) {
      LayoutWelcome();
    }

    Clay_RenderCommandArray render_commands = Clay_EndLayout(delta_time);
    // those layouts will then be computed as raw render commands that any renderer should be able to understand
    // as long as there is a translation layer for them

    BeginDrawing();
    ClearBackground(GREEN); // another background behind clay to see the space between clay's ui and raylib's
    Clay_Raylib_Render(render_commands, fonts); // then render the commands with raylib, with the corresponding font
    EndDrawing();
  }
}
