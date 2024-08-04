#include <stdio.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform(*picture_data, picture, N, M);

    make_picture(picture, N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j != 0) printf(" ");
            printf("%d", picture[i][j]);
        }
        if (i != N - 1) printf("\n");
    }
    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const int tree_trunk[] = {7, 7, 7, 7};
    const int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);

    // SUN
    for (int i = 1; i < length_frame_h - 8; i++) {
        for (int j = 7; j < length_frame_w - 1; j++) {
            picture[i][j] = sun_data[i - 1][j - 7];
        }
    }
    // TREE
    for (int i = 0; i < 4; i++) {
        picture[i + 2][3] = tree_foliage[i];
        picture[i + 2][4] = tree_foliage[i];
        picture[3][i + 2] = tree_foliage[i];
        picture[4][i + 2] = tree_foliage[i];
    }
    for (int i = 0; i < 4; i++) {
        picture[10][i + 2] = tree_trunk[i];
        picture[i + 6][3] = tree_trunk[i];
        picture[i + 6][4] = tree_trunk[i];
    }
    // FRAME
    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[length_frame_h / 2][i] = frame_w[i];
        picture[length_frame_h - 1][i] = frame_w[i];
    }
    for (int i = 0; i < length_frame_h; i++) {
        picture[i][0] = frame_h[i];
        picture[i][length_frame_w / 2] = frame_h[i];
        picture[i][length_frame_w - 1] = frame_h[i];
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}
