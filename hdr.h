/*

Copyright (c) 2015 Harm Hanemaaijer <fgenfb@yahoo.com>

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

*/

bool detexCalculateDynamicRange(uint8_t *pixel_buffer, int nu_pixels, uint32_t pixel_format,
	float *range_min_out, float *range_max_out);

void detexConvertHDRHalfFloatToUInt16Gamma1(uint16_t *buffer, int n, float range_min,
	float range_max);

void detexConvertHDRHalfFloatToUInt16SpecialGamma(uint16_t *buffer, int n, float gamma,
	float range_min, float range_max);

void detexConvertHDRFloatToFloatGamma1(float *buffer, int n, float range_min,
	float range_max);

void detexConvertHDRFloatToFloatSpecialGamma(float *buffer, int n, float gamma,
	float range_min, float range_max);

