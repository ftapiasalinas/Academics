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

/* This file is designed for use with ISim build 0xb869381d */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Documents and Settings/user/Desktop/prosahil/sahil.v";
static unsigned int ng1[] = {127U, 0U};
static unsigned int ng2[] = {0U, 0U};



static void Always_50_0(char *t0)
{
    char t6[8];
    char t20[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t21;
    char *t22;
    char *t23;

LAB0:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 1548);
    *((int *)t2) = 1;
    t3 = (t0 + 1380);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(51, ng0);

LAB5:    xsi_set_current_line(52, ng0);
    t4 = (t0 + 600U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t6 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 8);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 8);
    t13 = (t12 & 1);
    *((unsigned int *)t4) = t13;
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t14);
    t16 = (~(t15));
    t17 = *((unsigned int *)t6);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    xsi_vlogtype_concat(t6, 16, 16, 2U, t2, 7, t3, 9);
    t4 = (t0 + 828);
    xsi_vlogvar_assign_value(t4, t6, 0, 0, 16);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(53, ng0);
    t21 = (t0 + 600U);
    t22 = *((char **)t21);
    t21 = ((char*)((ng1)));
    xsi_vlogtype_concat(t20, 16, 16, 2U, t21, 7, t22, 9);
    t23 = (t0 + 828);
    xsi_vlogvar_assign_value(t23, t20, 0, 0, 16);
    goto LAB8;

}


extern void work_m_00000000004292977395_2964505861_init()
{
	static char *pe[] = {(void *)Always_50_0};
	xsi_register_didat("work_m_00000000004292977395_2964505861", "isim/testbench_isim_beh.exe.sim/work/m_00000000004292977395_2964505861.didat");
	xsi_register_executes(pe);
}
