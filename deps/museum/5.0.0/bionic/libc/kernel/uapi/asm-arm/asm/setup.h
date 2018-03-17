/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _UAPI__ASMARM_SETUP_H
#define _UAPI__ASMARM_SETUP_H
#include <museum/5.0.0/bionic/libc/linux/types.h>
#define COMMAND_LINE_SIZE 1024
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATAG_NONE 0x00000000
struct tag_header {
 __u32 size;
 __u32 tag;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define ATAG_CORE 0x54410001
struct tag_core {
 __u32 flags;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 pagesize;
 __u32 rootdev;
};
#define ATAG_MEM 0x54410002
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct tag_mem32 {
 __u32 size;
 __u32 start;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATAG_VIDEOTEXT 0x54410003
struct tag_videotext {
 __u8 x;
 __u8 y;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 video_page;
 __u8 video_mode;
 __u8 video_cols;
 __u16 video_ega_bx;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 video_lines;
 __u8 video_isvga;
 __u16 video_points;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATAG_RAMDISK 0x54410004
struct tag_ramdisk {
 __u32 flags;
 __u32 size;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 start;
};
#define ATAG_INITRD 0x54410005
#define ATAG_INITRD2 0x54420005
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct tag_initrd {
 __u32 start;
 __u32 size;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define ATAG_SERIAL 0x54410006
struct tag_serialnr {
 __u32 low;
 __u32 high;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define ATAG_REVISION 0x54410007
struct tag_revision {
 __u32 rev;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define ATAG_VIDEOLFB 0x54410008
struct tag_videolfb {
 __u16 lfb_width;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u16 lfb_height;
 __u16 lfb_depth;
 __u16 lfb_linelength;
 __u32 lfb_base;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 lfb_size;
 __u8 red_size;
 __u8 red_pos;
 __u8 green_size;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 green_pos;
 __u8 blue_size;
 __u8 blue_pos;
 __u8 rsvd_size;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u8 rsvd_pos;
};
#define ATAG_CMDLINE 0x54410009
struct tag_cmdline {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 char cmdline[1];
};
#define ATAG_ACORN 0x41000101
struct tag_acorn {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 memc_control_reg;
 __u32 vram_pages;
 __u8 sounddefault;
 __u8 adfsdrives;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define ATAG_MEMCLK 0x41000402
struct tag_memclk {
 __u32 fmemclk;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct tag {
 struct tag_header hdr;
 union {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct tag_core core;
 struct tag_mem32 mem;
 struct tag_videotext videotext;
 struct tag_ramdisk ramdisk;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct tag_initrd initrd;
 struct tag_serialnr serialnr;
 struct tag_revision revision;
 struct tag_videolfb videolfb;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct tag_cmdline cmdline;
 struct tag_acorn acorn;
 struct tag_memclk memclk;
 } u;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct tagtable {
 __u32 tag;
 int (*parse)(const struct tag *);
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define tag_member_present(tag,member)   ((unsigned long)(&((struct tag *)0L)->member + 1)   <= (tag)->hdr.size * 4)
#define tag_next(t) ((struct tag *)((__u32 *)(t) + (t)->hdr.size))
#define tag_size(type) ((sizeof(struct tag_header) + sizeof(struct type)) >> 2)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define for_each_tag(t,base)   for (t = base; t->hdr.size; t = tag_next(t))
#endif