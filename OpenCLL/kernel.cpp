#include "kernel.hpp" // note: unbalanced round brackets () are not allowed and string literals can't be arbitrarily long, so periodically interrupt with )+R(
string opencl_c_container() {
	return R( // ########################## begin of OpenCL C code ####################################################################



		kernel void add_kernel(global float* A, global float* B, global float* C) { // equivalent to "for(uint n=0u; n<N; n++) {", but executed in parallel
		const uint n = get_global_id(0);
		C[n] = A[n] + B[n];
	}


	__kernel void redumin(__global float* output, __global float* input, __constant uint * size, __local float* l_data)
	{
		uint g_id = get_global_id(0);
		uint l_id = get_local_id(0);

		if (g_id < *size) {
			l_data[l_id] = input[g_id];
		}
		else {
			l_data[l_id] = 0;
		}
		barrier(CLK_LOCAL_MEM_FENCE);

		for (uint stride = get_local_size(0) / 2; stride > 0; stride >>= 1)
		{
			if (l_id < stride) {
				l_data[l_id] = l_data[l_id] + l_data[l_id + stride];
			}
			barrier(CLK_LOCAL_MEM_FENCE);
		}
		if (0 == l_id) {
			output[get_group_id(0)] = l_data[0];
		}
	}


	__kernel void redumax(__global int* output, __global int* input, __constant uint * rows, __constant uint * cols, __local uint * l_data)
	{
		uint xg_id = get_global_id(0);
		uint yg_id = get_global_id(1);
		uint xl_id = get_local_id(0);
		uint yl_id = get_local_id(1);

		uint l_id = yl_id * get_local_size(0) + xl_id;
		uint g_id = yg_id * (*cols) + xg_id;

		if (g_id < (*rows)* (*cols)) {
			l_data[l_id] = input[g_id];
		}
		else {
			l_data[l_id] = 0;
		}
		barrier(CLK_LOCAL_MEM_FENCE);

		for (uint stride = (get_local_size(0) * get_local_size(1)) / 2; stride > 0; stride >>= 1)
		{
			if (l_id < stride) {
				l_data[l_id] = max(l_data[l_id], l_data[l_id + stride]);
			}
			barrier(CLK_LOCAL_MEM_FENCE);
		}
		if (0 == l_id) {
			if (output[get_group_id(0)] < l_data[0]) {
				output[get_group_id(0)] = l_data[0];
			}
		}
	}





	int ConvolutionX(image2d_t in_image, sampler_t sampler, int2 coord, __global int* filter, uint sizeX, uint sizeY, int filterSize) {
		int xMinus = coord.x - ((filterSize - 1) / 2);
		int xPlus = coord.x + ((filterSize - 1) / 2);
		int yMinus = coord.y - ((filterSize - 1) / 2);
		int yPlus = coord.y + ((filterSize - 1) / 2);

		if (xPlus < sizeX && xMinus >= 0 && yPlus < sizeY && yMinus >= 0)
		{
			int bottom = -((filterSize - 1) / 2);
			int top = ((filterSize - 1) / 2);
			int sum = 0, weightSum = 0;
			int index = 0;
			for (int indexX = bottom; indexX <= top; indexX++) {
				for (int indexY = bottom; indexY <= top; indexY++) {
					uint4 pixel = read_imageui(in_image, sampler, (int2)(coord.x + indexX, coord.y + indexY));
					weightSum += filter[index];
					sum += pixel.x * filter[index];
					index++;
				}
			}
			return (int)(sum / weightSum);
		}
	}
	int ConvolutionY(image2d_t in_image, sampler_t sampler, int2 coord, __global int* filter, uint sizeX, uint sizeY, int filterSize) {
		int xMinus = coord.x - ((filterSize - 1) / 2);
		int xPlus = coord.x + ((filterSize - 1) / 2);
		int yMinus = coord.y - ((filterSize - 1) / 2);
		int yPlus = coord.y + ((filterSize - 1) / 2);

		if (xPlus < sizeX && xMinus >= 0 && yPlus < sizeY && yMinus >= 0)
		{
			int bottom = -((filterSize - 1) / 2);
			int top = ((filterSize - 1) / 2);
			int sum = 0, weightSum = 0;
			int index = 0;
			for (int indexX = bottom; indexX <= top; indexX++) {
				for (int indexY = bottom; indexY <= top; indexY++) {
					uint4 pixel = read_imageui(in_image, sampler, (int2)(coord.x + indexX, coord.y + indexY));
					weightSum += filter[index];
					sum += pixel.y * filter[index];
					index++;
				}
			}
			return (int)(sum / weightSum);
		}
	}
	int ConvolutionZ(image2d_t in_image, sampler_t sampler, int2 coord, __global int* filter, uint sizeX, uint sizeY, int filterSize) {
		int xMinus = coord.x - ((filterSize - 1) / 2);
		int xPlus = coord.x + ((filterSize - 1) / 2);
		int yMinus = coord.y - ((filterSize - 1) / 2);
		int yPlus = coord.y + ((filterSize - 1) / 2);

		if (xPlus < sizeX && xMinus >= 0 && yPlus < sizeY && yMinus >= 0)
		{
			int bottom = -((filterSize - 1) / 2);
			int top = ((filterSize - 1) / 2);
			int sum = 0, weightSum = 0;
			int index = 0;
			for (int indexX = bottom; indexX <= top; indexX++) {
				for (int indexY = bottom; indexY <= top; indexY++) {
					uint4 pixel = read_imageui(in_image, sampler, (int2)(coord.x + indexX, coord.y + indexY));
					weightSum += filter[index];
					sum += pixel.z * filter[index];
					index++;
				}
			}
			return (int)(sum / weightSum);
		}
	}

	__kernel void myKernel(__read_only image2d_t in_image, __write_only image2d_t out_image, __global int* bitmask, __global int* filter, const int filterSize)
	{
		uint x = get_global_id(0);
		uint y = get_global_id(1);

		if ((x < get_image_width(in_image)) && (y < get_image_height(in_image)))
		{
			const sampler_t sampler = CLK_NORMALIZED_COORDS_FALSE | CLK_ADDRESS_NONE | CLK_FILTER_NEAREST;
			int2 coord = (int2)(x, y);
			uint4 pixel = read_imageui(in_image, sampler, coord);
			if (bitmask[0] == 1) {
				pixel.x = ConvolutionX(in_image, sampler, coord, filter, get_image_width(in_image), get_image_height(in_image), filterSize);
			}
			if (bitmask[1] == 1) {
				pixel.y = ConvolutionY(in_image, sampler, coord, filter, get_image_width(in_image), get_image_height(in_image), filterSize);
			}
			if (bitmask[2] == 1) {
				pixel.z = ConvolutionZ(in_image, sampler, coord, filter, get_image_width(in_image), get_image_height(in_image), filterSize);
			}
			write_imageui(out_image, coord, pixel);
		}
	}


	);
} // ############################################################### end of OpenCL C code #####################################################################