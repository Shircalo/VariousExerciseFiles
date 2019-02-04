


/* 
***************************************************************************************
*																			包含的头文件
***************************************************************************************
*/

#include <rtthread.h>
#include "ARMCM4.h"


/* 
***************************************************************************************
*																			全局变量
***************************************************************************************
*/
rt_uint8_t flag1;
rt_uint8_t flag2;

extern rt_list_t rt_thread_priority_table[RT_THREAD_PRIORITY_MAX];

/*
***************************************************************************************
*                             线程控制块 & STACK & 线程声明
***************************************************************************************
*/


/* 定义线程控制块 */
struct rt_thread rt_flag1_thread;
struct rt_thread rt_flag2_thread;

ALIGN(RT_ALIGN_SIZE)
/* 定义线程栈 */
rt_uint8_t rt_flag1_thread_stack[512];
rt_uint8_t rt_flag2_thread_stack[512];

/* 线程声明 */
void flag1_thread_entry(void *p_arg);
void flag2_thread_entry(void *p_arg);

/**************************************************************************************
	*	@brief	main函数
	*	@brief	无
	*	@param	无
	*	@retval 无
	*
	*	@attention
	*************************************************************************************
	*/
	
int main(void)
{
	/* 硬件初始化 */
	/* 将硬件相关的初始化放在这里，如果是软件仿真则没有相关的初始化代码 */
	
	/* 调度器初始化 */
	rt_system_scheduler_init();
	
	
	/* 初始化线程 */
	rt_thread_init( &rt_flag1_thread,                /* 线程控制块 */
	                flag1_thread_entry,              /* 线程入口地址 */
	                RT_NULL,                         /* 线程形参 */
	                &rt_flag1_thread_stack[0],      /* 线程栈起始地址 */
	                sizeof(rt_flag1_thread_stack) ); /* 线程栈的大小，单位为字节 */
	/* 将线程插入到就绪列表 */
	rt_list_insert_before( &(rt_thread_priority_table[0]), &(rt_flag1_thread.tlist) );
	
	/* 初始化线程 */
	rt_thread_init( &rt_flag2_thread,                /* 线程控制块 */
	                flag2_thread_entry,              /* 线程入口地址 */
	                RT_NULL,                         /* 线程形参 */
	                &rt_flag2_thread_stack[0],        /* 线程栈起始地址 */
	                sizeof(rt_flag2_thread_stack) ); /* 线程栈的大小，单位为字节 */
	/* 将线程插入到就绪列表 */
	rt_list_insert_before( &(rt_thread_priority_table[1]), &(rt_flag2_thread.tlist) );

}

/*
*****************************************************************************************
*                                      函数实现
*****************************************************************************************
*/
/* 软件延时 */
void delay (uint32_t count)
{
	for(; count!=0; count--);
}

/* 线程1 */
void flag1_thread_entry( void *p_arg )
{
	for( ;; )
	{
		flag1 = 1;
		delay( 100 );
		flag1 = 0;
		delay( 100 );		
	}
}
/* 线程1 */
void flag2_thread_entry( void *p_arg )
{
	for( ;; )
	{
		flag2 = 1;
		delay( 100 );
		flag2 = 0;
		delay( 100 );		
	} 
}