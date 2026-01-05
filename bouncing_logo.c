#include "terminal_draw.h"
#include <stdbool.h>
#define DVD_WIDTH  30   
#define DVD_HEIGHT 7


typedef struct {
    int x;
    int y;
    int width;
    int height;
    Color color;
} DVDLogo;

const char *DVD_LOGO[] = {
"⠀⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⡀",
"⠀⢠⣿⣿⡿⠀⠀⠈⢹⣿⣿⡿⣿⣿⣇⠀⣠⣿⣿⠟⣽⣿⣿⠇⠀⠀⢹⣿⣿⣿",
"⠀⢸⣿⣿⡇⠀⢀⣠⣾⣿⡿⠃⢹⣿⣿⣶⣿⡿⠋⢰⣿⣿⡿⠀⠀⣠⣼⣿⣿⠏",
"⠀⣿⣿⣿⣿⣿⣿⠿⠟⠋⠁⠀⠀⢿⣿⣿⠏⠀⠀⢸⣿⣿⣿⣿⣿⡿⠟⠋⠁⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣸⣟⣁⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⣠⣴⣶⣾⣿⣿⣻⡟⣻⣿⢻⣿⡟⣛⢻⣿⡟⣛⣿⡿⣛⣛⢻⣿⣿⣶⣦⣄⡀⠀",
"⠉⠛⠻⠿⠿⠿⠷⣼⣿⣿⣼⣿⣧⣭⣼⣿⣧⣭⣿⣿⣬⡭⠾⠿⠿⠿⠛⠉⠀"
};

Color getNextColor(Color color){
    return color = (color - BLACK + 1) % NUM_COLORS + BLACK;
};

void set_color(Color color);
void drawDVD(const DVDLogo *dvd) {
    printf("\033[%dm", dvd->color);  

    for (int i = 0; i < dvd->height; i++) {
        print_at(dvd->x, dvd->y + i, "%s", DVD_LOGO[i]);
    }

    printf("\033[0m"); // reset color
}


bool collideX(const DVDLogo *dvd, int screenW) {
    return (dvd->x <= 1) ||
           (dvd->x + dvd->width >= screenW);
}

bool collideY(const DVDLogo *dvd, int screenH) {
    return (dvd->y <= 2) ||
           (dvd->y + dvd->height >= screenH);
}

int main(void)
{
    int screenWidth, screenHeight;
    get_screen_size(&screenWidth, &screenHeight);

    DVDLogo dvd = {
        .x = screenWidth / 2,
        .y = screenHeight / 2,
        .width = DVD_WIDTH,
        .height = DVD_HEIGHT,
        .color = RED
    };

    int dx = 1, dy = 1;

    while (1)
    {
        clear_screen();
        drawDVD(&dvd);

        dvd.x += dx;
        dvd.y += dy;

        if (collideX(&dvd, screenWidth)) {
            dx = -dx;
            dvd.color = getNextColor(dvd.color);
        }

        if (collideY(&dvd, screenHeight)) {
            dy = -dy;
            dvd.color = getNextColor(dvd.color);
        }

        sleep_ms(40); // Control animation speed (1000ms = 1 second)
    }

    return 0;
}
