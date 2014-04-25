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

/* This file is designed for use with ISim build 0x7dea747 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/Documents/Academics/prosahil/sahil.v";
static unsigned int ng1[] = {0U, 0U};



static void Always_60_0(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t1 = (t0 + 2368U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(60, ng0);
    t2 = (t0 + 2688);
    *((int *)t2) = 1;
    t3 = (t0 + 2400);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(61, ng0);

LAB5:    xsi_set_current_line(62, ng0);
    t5 = (t0 + 1048U);
    t6 = *((char **)t5);
    t5 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 16, 16, 2U, t5, 10, t6, 6);
    t7 = (t0 + 1448);
    xsi_vlogvar_assign_value(t7, t4, 0, 0, 16);
    goto LAB2;

}


extern void work_m_00000000004292977395_3439140385_init()
{
	static char *pe[] = {(void *)Always_60_0};
	xsi_register_didat("work_m_00000000004292977395_3439140385", "isim/testbench_isim_beh.exe.sim/work/m_00000000004292977395_3439140385.didat");
	xsi_register_executes(pe);
}
