__kernel void redumin(__global float* output, __global float* input, __constant uint* size, __local float *l_data)
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

