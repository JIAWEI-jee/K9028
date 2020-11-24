#include "product.h"
#include "key.h"
#include "timer.h"

static void product_GPIO_Init_Config ( void )
{
	P2M0 = 0x61;                        //P35设置为非施密特数字带上拉输入
	P2M2 = 0XC1;                        //设置为推挽输出
}

static enum producte_test_list product_check_test ( void )
{
	u8 ret;
	product_GPIO_Init_Config();
	if ( PRODUCT_CHECK_IN )
	{
		ret = CHECK_SUCCESS;
	}
	else
	{
		ret = CHECK_FAIL;
	}
	return ret;
}

void product_test_handle ( void )
{
	static enum producte_process_state_list state = PRODUCTE_INIT;
	if ( systick_10ms )
	{
		systick_10ms = 0;
		switch ( ( u8 ) state )
		{
			case PRODUCTE_INIT:
				while ( 1 )
				{

				}
				break;
		}
	}
}


void product_check_process ( void )
{
	if ( product_check_test() == CHECK_SUCCESS )
	{
		while ( 1 )
		{
			product_test_handle();
		}
	}
}

