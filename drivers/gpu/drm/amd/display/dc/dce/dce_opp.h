/* Copyright 2012-15 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */

#ifndef __DC_OPP_DCE_H__
#define __DC_OPP_DCE_H__

#include "dc_types.h"
#include "opp.h"
#include "core_types.h"

#define FROM_DCE11_OPP(opp)\
	container_of(opp, struct dce110_opp, base)

enum dce110_opp_reg_type {
	DCE110_OPP_REG_DCP = 0,
	DCE110_OPP_REG_DCFE,
	DCE110_OPP_REG_FMT,

	DCE110_OPP_REG_MAX
};

#define OPP_COMMON_REG_LIST_BASE(id) \
	SRI(FMT_DYNAMIC_EXP_CNTL, FMT, id), \
	SRI(FMT_BIT_DEPTH_CONTROL, FMT, id), \
	SRI(FMT_CONTROL, FMT, id), \
	SRI(FMT_DITHER_RAND_R_SEED, FMT, id), \
	SRI(FMT_DITHER_RAND_G_SEED, FMT, id), \
	SRI(FMT_DITHER_RAND_B_SEED, FMT, id), \
	SRI(FMT_CLAMP_CNTL, FMT, id), \
	SRI(FMT_CLAMP_COMPONENT_R, FMT, id), \
	SRI(FMT_CLAMP_COMPONENT_G, FMT, id), \
	SRI(FMT_CLAMP_COMPONENT_B, FMT, id)

#define OPP_DCE_80_REG_LIST(id) \
	OPP_COMMON_REG_LIST_BASE(id), \
	SRI(FMT_TEMPORAL_DITHER_PATTERN_CONTROL, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_S_MATRIX, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_T_MATRIX, FMT, id)

#define OPP_DCE_100_REG_LIST(id) \
	OPP_COMMON_REG_LIST_BASE(id), \
	SRI(FMT_TEMPORAL_DITHER_PATTERN_CONTROL, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_S_MATRIX, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_T_MATRIX, FMT, id)

#define OPP_DCE_110_REG_LIST(id) \
	OPP_COMMON_REG_LIST_BASE(id), \
	SRI(FMT_TEMPORAL_DITHER_PATTERN_CONTROL, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_S_MATRIX, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_T_MATRIX, FMT, id)

#define OPP_DCE_112_REG_LIST(id) \
	OPP_COMMON_REG_LIST_BASE(id), \
	SRI(FMT_TEMPORAL_DITHER_PATTERN_CONTROL, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_S_MATRIX, FMT, id), \
	SRI(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_T_MATRIX, FMT, id), \
	SRI(CONTROL, FMT_MEMORY, id)

#define OPP_DCE_120_REG_LIST(id) \
	OPP_COMMON_REG_LIST_BASE(id), \
	SRI(CONTROL, FMT_MEMORY, id)

#define OPP_SF(reg_name, field_name, post_fix)\
	.field_name = reg_name ## __ ## field_name ## post_fix

#define OPP_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh)\
	OPP_SF(FMT_DYNAMIC_EXP_CNTL, FMT_DYNAMIC_EXP_EN, mask_sh),\
	OPP_SF(FMT_DYNAMIC_EXP_CNTL, FMT_DYNAMIC_EXP_MODE, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TRUNCATE_EN, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TRUNCATE_DEPTH, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TRUNCATE_MODE, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_SPATIAL_DITHER_EN, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_SPATIAL_DITHER_DEPTH, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_SPATIAL_DITHER_MODE, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_HIGHPASS_RANDOM_ENABLE, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_FRAME_RANDOM_ENABLE, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_RGB_RANDOM_ENABLE, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_EN, mask_sh),\
	OPP_SF(FMT_DITHER_RAND_R_SEED, FMT_RAND_R_SEED, mask_sh),\
	OPP_SF(FMT_DITHER_RAND_G_SEED, FMT_RAND_G_SEED, mask_sh),\
	OPP_SF(FMT_DITHER_RAND_B_SEED, FMT_RAND_B_SEED, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_EN, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_RESET, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_OFFSET, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_DEPTH, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_LEVEL, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_25FRC_SEL, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_50FRC_SEL, mask_sh),\
	OPP_SF(FMT_BIT_DEPTH_CONTROL, FMT_75FRC_SEL, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SRC_SELECT, mask_sh),\
	OPP_SF(FMT_CLAMP_CNTL, FMT_CLAMP_DATA_EN, mask_sh),\
	OPP_SF(FMT_CLAMP_CNTL, FMT_CLAMP_COLOR_FORMAT, mask_sh),\
	OPP_SF(FMT_CLAMP_COMPONENT_R, FMT_CLAMP_LOWER_R, mask_sh),\
	OPP_SF(FMT_CLAMP_COMPONENT_R, FMT_CLAMP_UPPER_R, mask_sh),\
	OPP_SF(FMT_CLAMP_COMPONENT_G, FMT_CLAMP_LOWER_G, mask_sh),\
	OPP_SF(FMT_CLAMP_COMPONENT_G, FMT_CLAMP_UPPER_G, mask_sh),\
	OPP_SF(FMT_CLAMP_COMPONENT_B, FMT_CLAMP_LOWER_B, mask_sh),\
	OPP_SF(FMT_CLAMP_COMPONENT_B, FMT_CLAMP_UPPER_B, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_PIXEL_ENCODING, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SUBSAMPLING_MODE, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SUBSAMPLING_ORDER, mask_sh)

#define OPP_COMMON_MASK_SH_LIST_DCE_110(mask_sh)\
	OPP_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_STEREOSYNC_OVERRIDE, mask_sh)

#define OPP_COMMON_MASK_SH_LIST_DCE_100(mask_sh)\
	OPP_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_STEREOSYNC_OVERRIDE, mask_sh)

#define OPP_COMMON_MASK_SH_LIST_DCE_112(mask_sh)\
	OPP_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh),\
	OPP_SF(FMT_MEMORY0_CONTROL, FMT420_MEM0_SOURCE_SEL, mask_sh),\
	OPP_SF(FMT_MEMORY0_CONTROL, FMT420_MEM0_PWR_FORCE, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_420_PIXEL_PHASE_LOCKED_CLEAR, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_420_PIXEL_PHASE_LOCKED, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_CBCR_BIT_REDUCTION_BYPASS, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP, mask_sh),\
	OPP_SF(FMT_CONTROL, FMT_STEREOSYNC_OVERRIDE, mask_sh)

#define OPP_COMMON_MASK_SH_LIST_DCE_80(mask_sh)\
	OPP_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh)

#define OPP_COMMON_MASK_SH_LIST_DCE_120(mask_sh)\
	OPP_SF(FMT0_FMT_DYNAMIC_EXP_CNTL, FMT_DYNAMIC_EXP_EN, mask_sh),\
	OPP_SF(FMT0_FMT_DYNAMIC_EXP_CNTL, FMT_DYNAMIC_EXP_MODE, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_TRUNCATE_EN, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_TRUNCATE_DEPTH, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_TRUNCATE_MODE, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_SPATIAL_DITHER_EN, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_SPATIAL_DITHER_DEPTH, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_SPATIAL_DITHER_MODE, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_EN, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_RESET, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_OFFSET, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_DEPTH, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_LEVEL, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_25FRC_SEL, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_50FRC_SEL, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_75FRC_SEL, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_HIGHPASS_RANDOM_ENABLE, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_FRAME_RANDOM_ENABLE, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_RGB_RANDOM_ENABLE, mask_sh),\
	OPP_SF(FMT0_FMT_BIT_DEPTH_CONTROL, FMT_TEMPORAL_DITHER_EN, mask_sh),\
	OPP_SF(FMT0_FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX, mask_sh),\
	OPP_SF(FMT0_FMT_CONTROL, FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP, mask_sh),\
	OPP_SF(FMT0_FMT_CONTROL, FMT_STEREOSYNC_OVERRIDE, mask_sh),\
	OPP_SF(FMT0_FMT_DITHER_RAND_R_SEED, FMT_RAND_R_SEED, mask_sh),\
	OPP_SF(FMT0_FMT_DITHER_RAND_G_SEED, FMT_RAND_G_SEED, mask_sh),\
	OPP_SF(FMT0_FMT_DITHER_RAND_B_SEED, FMT_RAND_B_SEED, mask_sh),\
	OPP_SF(FMT_MEMORY0_CONTROL, FMT420_MEM0_SOURCE_SEL, mask_sh),\
	OPP_SF(FMT_MEMORY0_CONTROL, FMT420_MEM0_PWR_FORCE, mask_sh),\
	OPP_SF(FMT0_FMT_CONTROL, FMT_SRC_SELECT, mask_sh),\
	OPP_SF(FMT0_FMT_CONTROL, FMT_420_PIXEL_PHASE_LOCKED_CLEAR, mask_sh),\
	OPP_SF(FMT0_FMT_CONTROL, FMT_420_PIXEL_PHASE_LOCKED, mask_sh),\
	OPP_SF(FMT0_FMT_CLAMP_CNTL, FMT_CLAMP_DATA_EN, mask_sh),\
	OPP_SF(FMT0_FMT_CLAMP_CNTL, FMT_CLAMP_COLOR_FORMAT, mask_sh),\
	OPP_SF(FMT0_FMT_CLAMP_COMPONENT_R, FMT_CLAMP_LOWER_R, mask_sh),\
	OPP_SF(FMT0_FMT_CLAMP_COMPONENT_R, FMT_CLAMP_UPPER_R, mask_sh),\
	OPP_SF(FMT0_FMT_CLAMP_COMPONENT_G, FMT_CLAMP_LOWER_G, mask_sh),\
	OPP_SF(FMT0_FMT_CLAMP_COMPONENT_G, FMT_CLAMP_UPPER_G, mask_sh),\
	OPP_SF(FMT0_FMT_CLAMP_COMPONENT_B, FMT_CLAMP_LOWER_B, mask_sh),\
	OPP_SF(FMT0_FMT_CLAMP_COMPONENT_B, FMT_CLAMP_UPPER_B, mask_sh),\
	OPP_SF(FMT0_FMT_CONTROL, FMT_PIXEL_ENCODING, mask_sh),\
	OPP_SF(FMT0_FMT_CONTROL, FMT_SUBSAMPLING_MODE, mask_sh),\
	OPP_SF(FMT0_FMT_CONTROL, FMT_SUBSAMPLING_ORDER, mask_sh),\
	OPP_SF(FMT0_FMT_CONTROL, FMT_CBCR_BIT_REDUCTION_BYPASS, mask_sh)

#define OPP_REG_FIELD_LIST(type) \
	type FMT_DYNAMIC_EXP_EN; \
	type FMT_DYNAMIC_EXP_MODE; \
	type FMT_TRUNCATE_EN; \
	type FMT_TRUNCATE_DEPTH; \
	type FMT_TRUNCATE_MODE; \
	type FMT_SPATIAL_DITHER_EN; \
	type FMT_SPATIAL_DITHER_DEPTH; \
	type FMT_SPATIAL_DITHER_MODE; \
	type FMT_TEMPORAL_DITHER_EN; \
	type FMT_TEMPORAL_DITHER_RESET; \
	type FMT_TEMPORAL_DITHER_OFFSET; \
	type FMT_TEMPORAL_DITHER_DEPTH; \
	type FMT_TEMPORAL_LEVEL; \
	type FMT_25FRC_SEL; \
	type FMT_50FRC_SEL; \
	type FMT_75FRC_SEL; \
	type FMT_HIGHPASS_RANDOM_ENABLE; \
	type FMT_FRAME_RANDOM_ENABLE; \
	type FMT_RGB_RANDOM_ENABLE; \
	type FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX; \
	type FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP; \
	type FMT_STEREOSYNC_OVERRIDE; \
	type FMT_RAND_R_SEED; \
	type FMT_RAND_G_SEED; \
	type FMT_RAND_B_SEED; \
	type FMT420_MEM0_SOURCE_SEL; \
	type FMT420_MEM0_PWR_FORCE; \
	type FMT_SRC_SELECT; \
	type FMT_420_PIXEL_PHASE_LOCKED_CLEAR; \
	type FMT_420_PIXEL_PHASE_LOCKED; \
	type FMT_CLAMP_DATA_EN; \
	type FMT_CLAMP_COLOR_FORMAT; \
	type FMT_CLAMP_LOWER_R; \
	type FMT_CLAMP_UPPER_R; \
	type FMT_CLAMP_LOWER_G; \
	type FMT_CLAMP_UPPER_G; \
	type FMT_CLAMP_LOWER_B; \
	type FMT_CLAMP_UPPER_B; \
	type FMT_PIXEL_ENCODING; \
	type FMT_SUBSAMPLING_ORDER; \
	type FMT_SUBSAMPLING_MODE; \
	type FMT_CBCR_BIT_REDUCTION_BYPASS;\

struct dce_opp_shift {
	OPP_REG_FIELD_LIST(uint8_t)
};

struct dce_opp_mask {
	OPP_REG_FIELD_LIST(uint32_t)
};

struct dce_opp_registers {
	uint32_t FMT_DYNAMIC_EXP_CNTL;
	uint32_t FMT_BIT_DEPTH_CONTROL;
	uint32_t FMT_CONTROL;
	uint32_t FMT_DITHER_RAND_R_SEED;
	uint32_t FMT_DITHER_RAND_G_SEED;
	uint32_t FMT_DITHER_RAND_B_SEED;
	uint32_t FMT_TEMPORAL_DITHER_PATTERN_CONTROL;
	uint32_t FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_S_MATRIX;
	uint32_t FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_T_MATRIX;
	uint32_t CONTROL;
	uint32_t FMT_CLAMP_CNTL;
	uint32_t FMT_CLAMP_COMPONENT_R;
	uint32_t FMT_CLAMP_COMPONENT_G;
	uint32_t FMT_CLAMP_COMPONENT_B;
};

/* OPP RELATED */
#define TO_DCE110_OPP(opp)\
	container_of(opp, struct dce110_opp, base)

struct dce110_opp {
	struct output_pixel_processor base;
	const struct dce_opp_registers *regs;
	const struct dce_opp_shift *opp_shift;
	const struct dce_opp_mask *opp_mask;
};

void dce110_opp_construct(struct dce110_opp *opp110,
	struct dc_context *ctx,
	uint32_t inst,
	const struct dce_opp_registers *regs,
	const struct dce_opp_shift *opp_shift,
	const struct dce_opp_mask *opp_mask);

void dce110_opp_destroy(struct output_pixel_processor **opp);



/* FORMATTER RELATED */
void dce110_opp_program_bit_depth_reduction(
	struct output_pixel_processor *opp,
	const struct bit_depth_reduction_params *params);

void dce110_opp_program_clamping_and_pixel_encoding(
	struct output_pixel_processor *opp,
	const struct clamping_and_pixel_encoding_params *params);

void dce110_opp_set_dyn_expansion(
	struct output_pixel_processor *opp,
	enum dc_color_space color_sp,
	enum dc_color_depth color_dpth,
	enum signal_type signal);

void dce110_opp_program_fmt(
	struct output_pixel_processor *opp,
	struct bit_depth_reduction_params *fmt_bit_depth,
	struct clamping_and_pixel_encoding_params *clamping);

void dce110_opp_set_clamping(
	struct dce110_opp *opp110,
	const struct clamping_and_pixel_encoding_params *params);

#endif
