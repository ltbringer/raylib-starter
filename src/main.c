# include "raylib.h"
# include "view/colorschemes.h"

int main(void) {
    const char *message = "Hello World";
    constexpr int fps = 60;
    InitWindow(0, 0, message);

    SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_VSYNC_HINT);

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    SetWindowSize(screenWidth, screenHeight);
    SetTargetFPS(fps);

    const auto backgroundColor = BLACK;
    const auto textColor = APP_LIGHT_GREEN;
    const auto primaryButtonColor = GRAY;
    const auto primaryInteractiveColor = DARKGRAY;
    constexpr int buttonWidth = 150;
    constexpr int buttonHeight = 50;
    const Rectangle exitButton = {
        (screenWidth - buttonWidth) / 2,
        (screenHeight - buttonHeight) / 2,
        buttonWidth,
        buttonHeight
    };
    bool exitButtonHovered = false;

    while (!WindowShouldClose()) {
        const char *exitButtonText = "Exit";
        const Vector2 exitButtonSize = MeasureTextEx(GetFontDefault(), exitButtonText, 20, 2);
        constexpr int fontSize = 60;
        exitButtonHovered = CheckCollisionPointRec(GetMousePosition(), exitButton);
        if (exitButtonHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            break;
        }

        BeginDrawing();
        ClearBackground(backgroundColor);

        const Vector2 textSize = MeasureTextEx(
            GetFontDefault(),
            message,
            fontSize,
            2
        );
        DrawText(
            message,
            (screenWidth - textSize.x) / 2,
            screenHeight * 0.05,
            fontSize,
            textColor
        );
        DrawRectangleRec(
            exitButton,
            exitButtonHovered
                ? primaryInteractiveColor
                : primaryButtonColor
        );
        DrawText(exitButtonText,
                 exitButton.x + (buttonWidth / 2) - (exitButtonSize.x / 2),
                 exitButton.y + (buttonHeight / 2) - (exitButtonSize.y / 2),
                 20,
                 textColor
        );
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
