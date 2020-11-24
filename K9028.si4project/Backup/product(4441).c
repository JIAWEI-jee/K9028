#include "product.h"
#include "key.h"
#include "timer.h"
#include "wdt.h"
#include "uart.h"

static void product_GPIO_Init_Config ( void )
{
	P2M0 = 0x61;                        //P35设置为非施密特数字带上拉输入
	P2M2 = 0XC1;                        //设置为推挽输出
	PRODUCT_OK = 0;
}

static enum producte_test_list product_check_test ( void )
{
	u8 ret = 0;
	product_GPIO_Init_Config();
	if ( PRODUCT_CHECK_IN == 0 )
	{
		ret = CHECK_SUCCESS;
	}
	else
	{
		ret = CHECK_FAIL;
	}
	return ret;
}
u8 state = PRODUCTE_INIT;
u16 test_time_timeout = 0;


void product_test_handle ( void )
{

	switch (state )
	{
		case PRODUCTE_INIT:

			if ( ( KEY_1==0 ) && ( KEY_1==0 ) && ( KEY_1==0 ) )
			{
				state = PRODUCTE_PASS;
				test_time_timeout = 0;
				break;
			}
			if ( test_time_timeout >= 30000 )
			{
				KEY_printf ( " PRODUCTE_ERROR\r\n" );
				state = PRODUCTE_ERROR;

				break;
			}

			break;
		case PRODUCTE_PASS:
			PRODUCT_OK = 1;
		ac_out = 1;
		POWER_IO = 1;
			KEY_printf ( " ENTER_PRODUCTE_ok\r\n" );
			state = PRODUCTE_PASS;
			break;
		case PRODUCTE_ERROR:
			KEY_printf ( " ENTER_PRODUCTE_ERROR\r\n" );
			PRODUCT_OK = 0;
		ac_out = 1;
		POWER_IO = 1;
			break;
		case PRODUCTE_END:
			PRODUCT_OK = 1;
     ac_out = 1;
		POWER_IO = 1;
			break;
	}
}



void product_check_process ( void )
{
	if ( product_check_test() == CHECK_SUCCESS )
	{

		KEY_printf ( " ENTER_TEST_MODE\r\n" );
		ac_out = 1;
		POWER_IO = 1;
		while ( 1 )
		{
			product_test_handle();
			clear_wdt();
		}
	}
}

