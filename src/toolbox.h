// toolbox.h:
//
// === NOTES ===
// * This is a _small_ set of typedefs, #defines and inlines that can
//   be found in tonclib, and might not represent the
//   final forms.


#ifndef TOOLBOX_H
#define TOOLBOX_H


// === (from tonc_types.h) ============================================

typedef unsigned char   u8;
typedef unsigned short  u16;

typedef u16 COLOR;

#define INLINE static inline

// === (from tonc_memmap.h) ===========================================

#define MEM_IO      0x04000000
#define MEM_VRAM    0x06000000

#define REG_DISPCNT     *((volatile u32*)(MEM_IO+0x0000))

// === (from tonc_memdef.h) ===========================================

// --- REG_DISPCNT defines ---
#define DCNT_MODE0     0x0000
#define DCNT_MODE1      0x0001
#define DCNT_MODE2      0x0002
#define DCNT_MODE3      0x0003
#define DCNT_MODE4      0x0004
#define DCNT_MODE5      0x0005
// layers
#define DCNT_BG0        0x0100
#define DCNT_BG1        0x0200
#define DCNT_BG2        0x0400
#define DCNT_BG3        0x0800
#define DCNT_OBJ        0x1000


// === (from tonc_video.h) ============================================

#define SCREEN_WIDTH   240
#define SCREEN_HEIGHT  160

#define vid_mem     ((u16*)MEM_VRAM)

#define M3_SIZE			0x12C00		//!< Mode 3 buffer size

typedef u16 COLOR;

#define VRAM_PAGE_SIZE	0x0A000
#define MEM_VRAM_BACK	(MEM_VRAM+ VRAM_PAGE_SIZE)
#define DCNT_PAGE			0x0010	//!< Page indicator
#define pal_bg_mem		((COLOR*)MEM_PAL)
#define MEM_PAL		0x05000000	//!< Palette. Note: no 8bit write !!


INLINE void m3_plot(int x, int y, COLOR clr)
{   mem_back[y*SCREEN_WIDTH+x]= clr;    }

INLINE void m3_fill(COLOR clr)
{
    int ii;
    u32 *dst= (u32*)mem_back;
    u32 wd= (clr<<16) | clr;

    for(ii=0; ii<M3_SIZE/4; ii++)
        *dst++= wd;
}

IWRAM_CODE void m3_fill_black()
{
    int ii;
    u32 *dst= (u32*)mem_back;

    for(ii=0; ii<M3_SIZE/4; ii++)
        *dst++= 0;
}


#define CLR_BLACK   0x0000
#define CLR_RED     0x001F
#define CLR_LIME    0x03E0
#define CLR_YELLOW  0x03FF
#define CLR_BLUE    0x7C00
#define CLR_MAG     0x7C1F
#define CLR_CYAN    0x7FE0
#define CLR_WHITE   0x7FFF


INLINE COLOR RGB15(u32 red, u32 green, u32 blue)
{   return red | (green<<5) | (blue<<10);   }


#if	defined	( __thumb__ )
#define	SystemCall(Number)	 __asm ("SWI	  "#Number"\n" :::  "r0", "r1", "r2", "r3")
#elif !defined(__linux__)
#define	SystemCall(Number)	 __asm ("SWI	  "#Number"	<< 16\n" :::"r0", "r1", "r2", "r3")
#endif


static inline
void VBlankIntrWait()	{ SystemCall(5); }



#endif
