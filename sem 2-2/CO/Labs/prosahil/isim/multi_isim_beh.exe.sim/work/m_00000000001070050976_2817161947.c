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
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {3U, 0U};
static unsigned int ng5[] = {4U, 0U};
static unsigned int ng6[] = {5U, 0U};
static unsigned int ng7[] = {6U, 0U};
static unsigned int ng8[] = {7U, 0U};
static unsigned int ng9[] = {65535U, 65535U};



static void Always_108_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 2088U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 2284);
    *((int *)t2) = 1;
    t3 = (t0 + 2116);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(109, ng0);

LAB5:    xsi_set_current_line(110, ng0);
    t4 = (t0 + 1336U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t4, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 3, t2, 3);
    if (t6 == 1)
        goto LAB21;

LAB22:
LAB24:
LAB23:    xsi_set_current_line(119, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 1564);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);

LAB25:    goto LAB2;

LAB7:    xsi_set_current_line(111, ng0);
    t7 = (t0 + 600U);
    t8 = *((char **)t7);
    t7 = (t0 + 1564);
    xsi_vlogvar_assign_value(t7, t8, 0, 0, 16);
    goto LAB25;

LAB9:    xsi_set_current_line(112, ng0);
    t3 = (t0 + 692U);
    t4 = *((char **)t3);
    t3 = (t0 + 1564);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    goto LAB25;

LAB11:    xsi_set_current_line(113, ng0);
    t3 = (t0 + 784U);
    t4 = *((char **)t3);
    t3 = (t0 + 1564);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    goto LAB25;

LAB13:    xsi_set_current_line(114, ng0);
    t3 = (t0 + 876U);
    t4 = *((char **)t3);
    t3 = (t0 + 1564);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    goto LAB25;

LAB15:    xsi_set_current_line(115, ng0);
    t3 = (t0 + 968U);
    t4 = *((char **)t3);
    t3 = (t0 + 1564);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    goto LAB25;

LAB17:    xsi_set_current_line(116, ng0);
    t3 = (t0 + 1060U);
    t4 = *((char **)t3);
    t3 = (t0 + 1564);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    goto LAB25;

LAB19:    xsi_set_current_line(117, ng0);
    t3 = (t0 + 1152U);
    t4 = *((char **)t3);
    t3 = (t0 + 1564);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    goto LAB25;

LAB21:    xsi_set_current_line(118, ng0);
    t3 = (t0 + 1244U);
    t4 = *((char **)t3);
    t3 = (t0 + 1564);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    goto LAB25;

}


extern void work_m_00000000001070050976_2817161947_init()
{
	static char *pe[] = {(void *)Always_108_0};
	xsi_register_didat("work_m_00000000001070050976_2817161947", "isim/multi_isim_beh.exe.sim/work/m_00000000001070050976_2817161947.didat");
	xsi_register_executes(pe);
}
