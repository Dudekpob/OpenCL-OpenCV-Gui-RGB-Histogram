__kernel void myKernel(__global int* output, __global int* input,__constant uint *rows, __constant uint *cols, __local uint* l_data)
{
    uint xg_id = get_global_id(0);
    uint yg_id = get_global_id(1);
    uint xl_id = get_local_id(0);
    uint yl_id = get_local_id(1);

    uint l_id = yl_id * get_local_size(0) + xl_id;
    uint g_id = yg_id * (*cols) + xg_id;

    if (g_id < (*rows) * (*cols)){
        l_data[l_id] = input[g_id];
    }
    else{
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