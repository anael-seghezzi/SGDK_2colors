#include "genesis.h"
#include "poly.h"

const u16 _tiley[128] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    256, 257, 258, 259, 260, 261, 262, 263,
    512, 513, 514, 515, 516, 517, 518, 519,
    768, 769, 770, 771, 772, 773, 774, 775,
    0, 1, 2, 3, 4, 5, 6, 7,
    256, 257, 258, 259, 260, 261, 262, 263,
    512, 513, 514, 515, 516, 517, 518, 519,
    768, 769, 770, 771, 772, 773, 774, 775,
    0, 1, 2, 3, 4, 5, 6, 7,
    256, 257, 258, 259, 260, 261, 262, 263,
    512, 513, 514, 515, 516, 517, 518, 519,
    768, 769, 770, 771, 772, 773, 774, 775,
    0, 1, 2, 3, 4, 5, 6, 7,
    256, 257, 258, 259, 260, 261, 262, 263,
    512, 513, 514, 515, 516, 517, 518, 519,
    768, 769, 770, 771, 772, 773, 774, 775,
};

const u32 _colory[128] = {
    0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0,
    0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0,
    0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0,
    0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0, 0x88888888>>0,
    0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1,
    0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1,
    0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1,
    0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1, 0x88888888>>1,
    0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2,
    0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2,
    0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2,
    0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2, 0x88888888>>2,
    0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3,
    0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3,
    0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3,
    0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3, 0x88888888>>3,
};

const u32 _seta[256] = {
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
    0xFFFFFFFF, 0x0FFFFFFF, 0x00FFFFFF, 0x000FFFFF, 0x0000FFFF, 0x00000FFF, 0x000000FF, 0x0000000F,
};
const u32 _setb[256] = {
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
    0xF0000000, 0xFF000000, 0xFFF00000, 0xFFFF0000, 0xFFFFF000, 0xFFFFFF00, 0xFFFFFFF0, 0xFFFFFFFF,
};

inline static void _line(u32 *tile_line, u16 a, u16 b, u32 color)
{
    __asm__ 
    (
        "move.w     %1,%%d2\n"
        "move.w     %2,%%d3\n"
        "asr.w      #6,%%d2\n"
        "asr.w      #6,%%d3\n"
        "cmp.w      %%d2,%%d3\n"
        "jgt        5f\n"
        "exg        %%d2,%%d3\n"

        "5:\n"
        "move.w     %%d2,%%d0\n"
        "move.w     %%d3,%%d1\n"
        "asr.w      #3,%%d0\n"              // ta = a / 8
        "asr.w      #3,%%d1\n"              // tb = b / 8
        "cmp.w      %%d0,%%d1\n"            // if (ta == tb)
        "jne        1f\n"

        "asl.w      #5,%%d0\n"              // * 32
        "add.w      %%d2,%%d2\n"
        "add.w      %%d2,%%d2\n"
        "add.w      %%d3,%%d3\n"
        "add.w      %%d3,%%d3\n"
        "move.l     (%4,%%d2.w),%%d1\n"
        "and.l      (%5,%%d3.w),%%d1\n"     // mab
        "and.l      %3,%%d1\n"
        "or.l       %%d1,(%0,%%d0.w)\n"
        "jra        2f\n"

        "1:\n"
        "sub.w      %%d0,%%d1\n"
        "asl.w      #5,%%d0\n"              // * 32
        "lea        32(%0,%%d0.w),%%a0\n"
        "subq.w     #2,%%d1\n"              // len = tb - ta1
        "jlt        3f\n"                   // if (tb > ta1)

        "4:\n"
        "or.l       %3,(%%a0)\n"
        "add.w      %6,%%a0\n"
        "dbra       %%d1,4b\n"

        "3:\n"
        "add.w      %%d2,%%d2\n"
        "add.w      %%d2,%%d2\n"
        "move.l     (%4,%%d2.w),%%d1\n"     // ma
        "and.l      %3,%%d1\n"
        "or.l       %%d1,(%0,%%d0.w)\n"

        "add.w      %%d3,%%d3\n"
        "add.w      %%d3,%%d3\n"
        "move.l     (%5,%%d3.w),%%d1\n"     // mb
        "and.l      %3,%%d1\n"
        "or.l       %%d1,(%%a0)\n"

        "2:\n"
        :
        : "a" (tile_line), "rm" (a), "rm" (b), "d" (color),
          "a" ((u32 *)_seta), "a" ((u32 *)_setb), "r" (32)
        : "d0", "d1", "d2", "d3", "a0"
    );
}

void triangle(u32 *dest, Vect2D_s16 v0, Vect2D_s16 v1, Vect2D_s16 v2, u32 color)
{
    // sort points
    if (v1.y < v0.y) {
        Vect2D_s16 t = v0;
        v0 = v1;
        v1 = t;
    }
    if (v2.y < v1.y) {
        Vect2D_s16 t = v1;
        v1 = v2;
        v2 = t;
        if (v1.y < v0.y) {
            t = v0;
            v0 = v1;
            v1 = t;
        }
    }

    s16 dyb = v2.y - v0.y; 
    if (dyb) {

        v0.x<<=FS;
        v1.x<<=FS;
        v2.x<<=FS;

        s16 dya = v1.y - v0.y;
        s16 dyc = v2.y - v1.y;

        s16 db = divs(v2.x - v0.x, dyb);
        s16 xb = v0.x + (db>>1);
        u16 y = v0.y;

        // top part
        if (dya) {
            s16 da = divs(v1.x - v0.x, dya);
            s16 xa = v0.x + (da>>1);
            dya--;
            do {
                u32 *tile_line = dest + _tiley[y];
                _line(tile_line, xa, xb, _colory[y++] & color);
                xa += da;
                xb += db;
            } while (--dya != -1);
        }

        // bottom part
        if (dyc) {
            s16 dc = divs(v2.x - v1.x, dyc);
            s16 xc = v1.x + (dc>>1);
            dyc--;
            do {
                u32 *tile_line = dest + _tiley[y];
                _line(tile_line, xc, xb, _colory[y++] & color);
                xc += dc;
                xb += db;
            } while (--dyc != -1);
        }
    }
}