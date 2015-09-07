#include <cstdio>  
#include <cstring>  

using namespace std;  

const int N = 64;  
const int M = 1024;  

#define CELL(row, col) (((row) << 3) + (col))  
#define ROW(cell) ((cell) >> 3)  
#define COL(cell) ((cell) & 7)  
#define PIECE(r,c) piece[CELL(r,c)]  
#define COLOR(r, c) color[CELL(r, c)]  
#define ATTACKED(r, c) attacked[CELL(r, c)]  
#define VALID(r, c) (((r) >= 0) && ((r) < 8) && ((c) >= 0) && ((c) < 8))  
#define FREE(r, c) (VALID(r, c) && PIECE(r,c) == 0)  
#define MARK(r, c) {if (VALID(r, c)) ATTACKED(r, c) = 1;}  

int piece[N], color[N], attacked[N];  
char buf[M];

void parse(char *s) {
    memset(piece, 0, sizeof(piece));
    memset(color, 0, sizeof(color));
    memset(attacked, 0, sizeof(attacked));
    for (int i = 0; *s; ++ s) {
        if (*s >= '1' && *s <= '8') {
            i += *s - '0';
            continue;
        }
        if (strchr("PNBRQK", *s) != NULL) {
            piece[i] = *s;
            color[i] = 'W';
            ++ i;
        } else if (strchr("pnbrqk", *s) != NULL) {
            piece[i] = *s - 'a' + 'A';
            color[i] = 'B';
            ++ i;
        }
    }
}

void pawn() {
    for (int r = 0; r < 7; ++ r) {
        for (int c = 0; c < 8; ++ c) {
            if (PIECE(r, c) != 'P') continue;
            if (COLOR(r, c) == 'B') {
                MARK(r + 1, c - 1);
                MARK(r + 1, c + 1);
            } else {
                MARK(r - 1, c - 1);
                MARK(r - 1, c + 1);
            }
        }
    }
}

void knight() {  
    for (int r = 0; r < 8; ++ r) {
        for (int c = 0; c < 8; ++ c) {
            if (PIECE(r, c) != 'N') continue;
            MARK(r - 2, c - 1);
            MARK(r - 2, c + 1);
            MARK(r - 1, c - 2);
            MARK(r - 1, c + 2);
            MARK(r + 1, c - 2);
            MARK(r + 1, c + 2);
            MARK(r + 2, c - 1);
            MARK(r + 2, c + 1);
        }
    }
}

void king() {  
    for (int r = 0; r < 8; ++ r) {
        for (int c = 0; c < 8; ++ c) {
            if (PIECE(r,c) != 'K') continue;
            MARK(r - 1, c - 1);
            MARK(r - 1, c);
            MARK(r - 1, c + 1);
            MARK(r, c - 1);
            MARK(r, c + 1);
            MARK(r + 1, c - 1);
            MARK(r + 1, c);
            MARK(r + 1, c + 1);
        }
    }
}

void rook() {  
    for (int i = 0; i < 64; ++ i) {  
        if (piece[i] != 'R' && piece[i] != 'Q') continue;
        for (int r = ROW(i) - 1, c = COL(i); FREE(r, c); -- r) MARK(r, c);
        for (int r = ROW(i) + 1, c = COL(i); FREE(r, c); ++ r) MARK(r, c);  
        for (int c = COL(i) - 1, r = ROW(i); FREE(r, c); -- c) MARK(r, c);
        for (int c = COL(i) + 1, r = ROW(i); FREE(r, c); ++ c) MARK(r, c);
    }
}

void bishop() {  
    for (int i = 0; i < 64; ++ i) {
        if (piece[i] != 'B' && piece[i] != 'Q') continue;
        for (int r = ROW(i) - 1, c = COL(i) - 1; FREE(r, c); -- r, -- c) MARK(r, c);
        for (int r = ROW(i) + 1, c = COL(i) + 1; FREE(r, c); ++ r, ++ c) MARK(r, c);
        for (int r = ROW(i) + 1, c = COL(i) - 1; FREE(r, c); ++ r, -- c) MARK(r, c);
        for (int r = ROW(i) - 1, c = COL(i) + 1; FREE(r, c); -- r, ++ c) MARK(r, c);
    }
}

int total() {  
    int ret = 0;
    for (int i = 0; i < 64; ++ i) {
        if (piece[i] == 0 && !attacked[i]) ++ ret;
    }
    return ret;
}

int main() {  
    while (gets(buf)) {  
        parse(buf);
        pawn();
        knight();
        rook();
        bishop();
        king();
        printf("%d\n", total());
    }
    return 0;
}
