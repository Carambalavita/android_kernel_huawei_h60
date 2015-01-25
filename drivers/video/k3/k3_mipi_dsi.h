/* Copyright (c) 2013-2014, Hisilicon Tech. Co., Ltd. All rights reserved.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 and
* only version 2 as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
* GNU General Public License for more details.
*
*/
#ifndef K3_MIPI_DSI_H
#define K3_MIPI_DSI_H

#include "k3_fb.h"


/* mipi dsi panel */
enum {
    DSI_VIDEO_MODE,
    DSI_CMD_MODE,
};

enum {
    DSI_1_LANES = 0,
    DSI_2_LANES,
    DSI_3_LANES,
    DSI_4_LANES,
};

enum {
    DSI_16BITS_1 = 0,
    DSI_16BITS_2,
    DSI_16BITS_3,
    DSI_18BITS_1,
    DSI_18BITS_2,
    DSI_24BITS_1,
    DSI_24BITS_2,
    DSI_24BITS_3,
};

enum {
    DSI_NON_BURST_SYNC_PULSES = 0,
    DSI_NON_BURST_SYNC_EVENTS,
    DSI_BURST_SYNC_PULSES_1,
    DSI_BURST_SYNC_PULSES_2,
};

#define DSI_VIDEO_DST_FORMAT_RGB565			0
#define DSI_VIDEO_DST_FORMAT_RGB666			1
#define DSI_VIDEO_DST_FORMAT_RGB666_LOOSE	2
#define DSI_VIDEO_DST_FORMAT_RGB888			3

#define DSI_CMD_DST_FORMAT_RGB565	0
#define DSI_CMD_DST_FORMAT_RGB666	1
#define DSI_CMD_DST_FORMAT_RGB888	2

/* dcs read/write */
#define DTYPE_DCS_WRITE		0x05	/* short write, 0 parameter */
#define DTYPE_DCS_WRITE1	0x15	/* short write, 1 parameter */
#define DTYPE_DCS_READ		0x06	/* read */
#define DTYPE_DCS_LWRITE	0x39	/* long write */

/* generic read/write */
#define DTYPE_GEN_WRITE		0x03	/* short write, 0 parameter */
#define DTYPE_GEN_WRITE1	0x13    /* short write, 1 parameter */
#define DTYPE_GEN_WRITE2	0x23	/* short write, 2 parameter */
#define DTYPE_GEN_LWRITE	0x29	/* long write */
#define DTYPE_GEN_READ		0x04	/* long read, 0 parameter */
#define DTYPE_GEN_READ1		0x14	/* long read, 1 parameter */
#define DTYPE_GEN_READ2		0x24	/* long read, 2 parameter */

#define DTYPE_TEAR_ON		0x35	/* set tear on */
#define DTYPE_MAX_PKTSIZE	0x37	/* set max packet size */
#define DTYPE_NULL_PKT		0x09	/* null packet, no data */
#define DTYPE_BLANK_PKT		0x19	/* blankiing packet, no data */

#define DTYPE_CM_ON				0x02	/* color mode off */
#define DTYPE_CM_OFF			0x12	/* color mode on */
#define DTYPE_PERIPHERAL_OFF	0x22
#define DTYPE_PERIPHERAL_ON		0x32

#define DSI_HDR_DTYPE(dtype)	((dtype) & 0x03f)
#define DSI_HDR_VC(vc)			(((vc) & 0x03) << 6)
#define DSI_HDR_DATA1(data)		(((data) & 0x0ff) << 8)
#define DSI_HDR_DATA2(data)		(((data) & 0x0ff) << 16)
#define DSI_HDR_WC(wc)			(((wc) & 0x0ffff) << 8)

#define DSI_PLD_DATA1(data)		((data) & 0x0ff)
#define DSI_PLD_DATA2(data)		(((data) & 0x0ff) << 8)
#define DSI_PLD_DATA3(data)		(((data) & 0x0ff) << 16)
#define DSI_PLD_DATA4(data)		(((data) & 0x0ff) << 24)

#define MIPI_DSI_FREQ1_STR "00001"
#define MIPI_DSI_FREQ2_STR "00010"
#define MIPI_DSI_FREQ3_STR "00100"
#define MIPI_DSI_FREQ4_STR "01000"
#define MIPI_DSI_FREQ5_STR "10000"

struct dsi_cmd_desc {
	int dtype;
	int vc;
	int wait;
	int waittype;
	int dlen;
	char *payload;
};


/******************************************************************************
** FUNCTIONS PROTOTYPES
*/
void mipi_dsi_max_return_packet_size(struct dsi_cmd_desc *cm,
	char __iomem *dsi_base);
void mipi_dsi_sread(u32 *out, char __iomem *dsi_base);
void mipi_dsi_lread(u32 *out, char __iomem *dsi_base);
u32 mipi_dsi_read(u32 *out, char __iomem *dsi_base);
int mipi_dsi_swrite(struct dsi_cmd_desc *cm, char __iomem *dsi_base);
int mipi_dsi_lwrite(struct dsi_cmd_desc *cm, char __iomem *dsi_base);

int mipi_dsi_cmds_tx(struct dsi_cmd_desc *cmds, int cnt,
	char __iomem *dsi_base);

struct k3_fb_data_type;
int mipi_dsi_clk_enable(struct k3_fb_data_type *k3fd);
int mipi_dsi_clk_disable(struct k3_fb_data_type *k3fd);

#endif  /* K3_MIPI_DSI_H */
