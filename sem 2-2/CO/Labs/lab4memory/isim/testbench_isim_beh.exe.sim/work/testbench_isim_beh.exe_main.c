/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000003630634319_1887574944_init();
    work_m_00000000002911040919_3311943062_init();
    work_m_00000000000678088923_3980182883_init();
    work_m_00000000000969045947_3361184447_init();
    work_m_00000000004134284947_2321183677_init();
    work_m_00000000002524690100_1949178628_init();
    work_m_00000000002013452923_2073120511_init();


    xsi_register_tops("work_m_00000000002524690100_1949178628");
    xsi_register_tops("work_m_00000000002013452923_2073120511");


    return xsi_run_simulation(argc, argv);

}
