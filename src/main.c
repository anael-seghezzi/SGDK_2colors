// 2 colors, direct frame buffer using palette masking and fast DMA transfer, resolution 256 x 128
// double buffer is not needed as DMA transfer is v-synced and can run at 60fps

// instead of 64 pixels in 16 colors each tile is packing 256 pixels in 2 colors
// the frame is divided in 4 blocs of 32 lines as each tile is reused 4 times (using palette masking)
// we use the 4 palettes here to demonstrate but we could update just one every 32 lines with an interrupt
// the bits are interleaved so indexing is not trivial and slow (tables can speed it up)

// bit masking example (in 8 bits):
// 0b10001000 // 2 pixels in bloc 1
// 0b01000100 // 2 pixels in bloc 2
// 0b00100010 // 2 pixels in bloc 3
// 0b00010001 // 2 pixels in bloc 4

// palette masking (0 is black, 1 is white):
// pal0: 0000000011111111
// pal1: 0000111100001111
// pal2: 0011001100110011
// pal3: 0101010101010101

#include "genesis.h"
#include "poly.h"

#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")


///////////////////////////////////////////////////////////////////////////////////////////////////////

inline static void draw_pixel(u32 *dest, u16 x, u16 y)
{
    u16 v = (y & 31);
    u16 shift = (y / 32) + ((x & 7) * 4);
    u32 value = 0x80000000 >> shift;
    u16 tile = (((v / 8) * 32) + ((x / 8)) * 8);
    dest[tile + (v & 7)] |= value;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////

const u32 _tab_value[8] = {
    0x80000000,
    0x08000000,
    0x00800000,
    0x00080000,
    0x00008000,
    0x00000800,
    0x00000080,
    0x00000008,
};

#define TAB_V_OFFSET(v) (v / 8) * 256 + (v & 7)
const u16 _tab_tile_v[32] = {
    TAB_V_OFFSET(0),
    TAB_V_OFFSET(1),
    TAB_V_OFFSET(2),
    TAB_V_OFFSET(3),
    TAB_V_OFFSET(4),
    TAB_V_OFFSET(5),
    TAB_V_OFFSET(6),
    TAB_V_OFFSET(7),
    TAB_V_OFFSET(8),
    TAB_V_OFFSET(9),
    TAB_V_OFFSET(10),
    TAB_V_OFFSET(11),
    TAB_V_OFFSET(12),
    TAB_V_OFFSET(13),
    TAB_V_OFFSET(14),
    TAB_V_OFFSET(15),
    TAB_V_OFFSET(16),
    TAB_V_OFFSET(17),
    TAB_V_OFFSET(18),
    TAB_V_OFFSET(19),
    TAB_V_OFFSET(20),
    TAB_V_OFFSET(21),
    TAB_V_OFFSET(22),
    TAB_V_OFFSET(23),
    TAB_V_OFFSET(24),
    TAB_V_OFFSET(25),
    TAB_V_OFFSET(26),
    TAB_V_OFFSET(27),
    TAB_V_OFFSET(28),
    TAB_V_OFFSET(29),
    TAB_V_OFFSET(30),
    TAB_V_OFFSET(31),
};

inline static void draw_pixel_faster(u32 *dest, u16 x, u16 y)
{
    u32 value = _tab_value[x & 7] >> (y / 32);
    u16 index = _tab_tile_v[y & 31] + ((x / 8) * 8);
    dest[index] |= value;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////

int main(bool hardReset)
{
    VDP_setScreenWidth256();
    VDP_setPlaneSize(32, 32, TRUE);
    VDP_clearPlane(BG_A, 0);
    VDP_clearPlane(BG_B, 0);

    SYS_disableInts();

	// tile index
	{
		u16 tile_addr[32*8];
        for (s16 i = 0; i < 32*8; i++)
            tile_addr[i] = TILE_USERINDEX + i + (0 << TILE_ATTR_PALETTE_SFT);
        DMA_doDmaFast(DMA_VRAM, tile_addr, VDP_getPlaneAddress(BG_B, 0,  6), 32*8, 2);
        for (s16 i = 0; i < 32*8; i++)
            tile_addr[i] = TILE_USERINDEX + i + (1 << TILE_ATTR_PALETTE_SFT);
		DMA_doDmaFast(DMA_VRAM, tile_addr, VDP_getPlaneAddress(BG_B, 0, 10), 32*8, 2);
        for (s16 i = 0; i < 32*8; i++)
            tile_addr[i] = TILE_USERINDEX + i + (2 << TILE_ATTR_PALETTE_SFT);
        DMA_doDmaFast(DMA_VRAM, tile_addr, VDP_getPlaneAddress(BG_B, 0, 14), 32*8, 2);
        for (s16 i = 0; i < 32*8; i++)
            tile_addr[i] = TILE_USERINDEX + i + (3 << TILE_ATTR_PALETTE_SFT);
        DMA_doDmaFast(DMA_VRAM, tile_addr, VDP_getPlaneAddress(BG_B, 0, 18), 32*8, 2);
	}

    // palette masking
    for (u16 i = 1; i < 16; i++) {
        if (i & 8)
            PAL_setColor(i, RGB24_TO_VDPCOLOR(0xFFFFFF));
        else
            PAL_setColor(i, RGB24_TO_VDPCOLOR(0x0));
    }
    for (u16 i = 1; i < 16; i++) {
        if (i & 4)
            PAL_setColor(16+i, RGB24_TO_VDPCOLOR(0xC0C0C0));
        else
            PAL_setColor(16+i, RGB24_TO_VDPCOLOR(0x0));
    }
    for (u16 i = 1; i < 16; i++) {
        if (i & 2)
            PAL_setColor(32+i, RGB24_TO_VDPCOLOR(0x808080));
        else
            PAL_setColor(32+i, RGB24_TO_VDPCOLOR(0x0));
    }
    for (u16 i = 1; i < 16; i++) {
        if (i & 1)
            PAL_setColor(48+i, RGB24_TO_VDPCOLOR(0x606060));
        else
            PAL_setColor(48+i, RGB24_TO_VDPCOLOR(0x0));
    }

    s16 point[16][4];

    setRandomSeed(0);
    for (u16 i = 0; i < 16; i++) {
        point[i][0] = random() & 255;
        point[i][1] = random() & 127;
        point[i][2] = 1 + (random() & 1);
        point[i][3] = 1 + (random() & 1);
        if (random() & 1)
            point[i][2] = -point[i][2];
        if (random() & 1)
            point[i][3] = -point[i][3];
    }

    SYS_enableInts();

    while(TRUE)
    {
        u32 frame_buffer[1024] = {0};

        // bounce points
        for (u16 i = 0; i < 16; i++) {

            s16 x = point[i][0] + point[i][2];
            s16 y = point[i][1] + point[i][3];

            if (x < 0) {
                x = 0;
                point[i][2] = -point[i][2];
            }
            else if (x > 255) {
                x = 255;
                point[i][2] = -point[i][2];
            }
            if (y < 0) {
                y = 0;
                point[i][3] = -point[i][3];
            }
            else if (y > 127) {
                y = 127;
                point[i][3] = -point[i][3];
            }

            point[i][0] = x;
            point[i][1] = y;
        }

        // triangle 1
        {
            Vect2D_s16 v0 = {point[0][0], point[0][1]};
            Vect2D_s16 v1 = {point[1][0], point[1][1]};
            Vect2D_s16 v2 = {point[2][0], point[2][1]};
            triangle(frame_buffer, v0, v1, v2, 0xFFFFFFFF);
        }
        // triangle 2
        {
            Vect2D_s16 v0 = {point[3][0]/2, point[3][1]/2};
            Vect2D_s16 v1 = {point[4][0]/2, point[4][1]/2};
            Vect2D_s16 v2 = {point[5][0]/2, point[5][1]/2};
            triangle(frame_buffer, v0, v1, v2, 0xF0F0F0F0);
        }

        for (u16 i = 6; i < 16; i++)
            draw_pixel_faster(frame_buffer, point[i][0], point[i][1]);

        SYS_doVBlankProcess();

        // send frame buffer to vram
        DMA_doDmaFast(DMA_VRAM, frame_buffer, TILE_USERINDEX*32, 2048, 2);

        //VDP_showCPULoad();
        VDP_showFPS(0);
    }

    return 0;
}