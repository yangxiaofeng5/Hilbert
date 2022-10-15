// Hilbert.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "fftw3.h" 
#include <windows.h>


int main()
{
    fftw_complex* in, * out;
    fftw_plan p;
    int N = 8;
    int i;
    int j;
    in = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * N);
    for (i = 0; i < N; i++)
    {
        in[i][0] = 1.0;
        in[i][1] = 0.0;
        printf("%6.2f ", in[i][0]);
    }
    printf("\n");
    p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p); /* repeat as needed*/
    for (j = 0; j < N; j++)
    {
        printf("%6.2f ", out[j][0]);
    }
    printf("\n");
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);
    system("pause");//暂停
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
