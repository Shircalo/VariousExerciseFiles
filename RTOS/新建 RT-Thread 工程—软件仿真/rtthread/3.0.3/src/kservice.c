#include <rtthread.h>
#include <rthw.h>

/**
 * 该函数将指定个数的字符串从一个地方拷贝到另一个地方
 *
 * @param dst 字符串拷贝的目的地
 * @param src 字符串从哪里拷贝
 * @param n 要拷贝的最大长度
 *
 * @return the result
 */
char *rt_strncpy(char *dst, const char *src, rt_ubase_t n)
{
	if(n != 0)
	{
		char *d = dst;
		const char *s = src;
		
		do
		{
			if((*d++ = *s++) == 0)
			{
				/* NUL pad the remaining n-1 bytes */
				while (--n != 0)
					*d++ = 0;
				break;
			}
		}while (--n != 0);
	}
	
	return (dst);
}

#ifndef RT_USING_CPU_FFS
/*
 * __lowest_bit_bitmap[] 数组的解析
 * 将一个8位整形数的取值范围0~255作为数组的索引，索引值第一个出现1（从最低位开始）的位号作为该数组索引下的成员值。
 * 举例：十进制数10的二进制为：0000 1010，从最低位开始，第一个出现1的位号为bit1，则有__lowest_bit_bitmap[10]=1
 * 注意：只需要找到第一个出现1的位号即可
 */
const rt_uint8_t __lowest_bit_bitmap[] = 
{
	/* 00 */ 0, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* 10 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* 20 */ 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* 30 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* 40 */ 6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* 50 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* 60 */ 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* 70 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* 80 */ 7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* 90 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* A0 */ 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* B0 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* C0 */ 6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* D0 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* E0 */ 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	/* F0 */ 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0
};

/**
 * 该函数用于从一个32位数中寻找第一个被置1的位（从低位开始），
 * 然后返回该位的索引（即位号）
 * 
 * @return 返回第一个置1位的索引号。如果全为0，则返回0。
 */
int __rt_ffs(int value)
{
	/* 如果值为0，则直接返回0 */
	if (value == 0) return 0;
	
	/* 检查bits [07:00] 
	这里加1的原因是避免当第一个置1的位是位0时
	返回的索引号与值都为0时返回的索引号重复*/
	if (value & 0xff)
		return __lowest_bit_bitmap[value &0xff] + 1;
	
	/* 检查 bits [15:08] */
	if (value & 0xff00)
		return __lowest_bit_bitmap[(value & 0xff00) >> 8] + 9;
	
	/* 检查 bits [23:16] */
	if (value &0xff0000)
		return __lowest_bit_bitmap[(value & 0xff0000) >> 16] + 17;
	
	/* 检查 bits [31:24] */
	return __lowest_bit_bitmap[(value & 0xff000000) >> 24] + 25;
}
#endif





