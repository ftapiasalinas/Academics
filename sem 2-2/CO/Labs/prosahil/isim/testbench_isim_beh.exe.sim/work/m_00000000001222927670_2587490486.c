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
static int ng3[] = {0, 0};
static int ng4[] = {1, 0};
static unsigned int ng5[] = {2U, 0U};
static unsigned int ng6[] = {3U, 0U};
static unsigned int ng7[] = {4U, 0U};
static unsigned int ng8[] = {5U, 0U};
static unsigned int ng9[] = {6U, 0U};



static void Always_584_0(char *t0)
{
    char t8[8];
    char t37[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    int t32;
    int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;

LAB0:    t1 = (t0 + 1812U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(584, ng0);
    t2 = (t0 + 2008);
    *((int *)t2) = 1;
    t3 = (t0 + 1840);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(585, ng0);

LAB5:    xsi_set_current_line(587, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 1196);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(588, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1104);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(589, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);

LAB6:    t2 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng9)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB19;

LAB20:
LAB21:    goto LAB2;

LAB7:    xsi_set_current_line(592, ng0);

LAB22:    xsi_set_current_line(594, ng0);
    t4 = (t0 + 692U);
    t5 = *((char **)t4);
    t4 = (t0 + 784U);
    t7 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 16, t5, 16, t7, 16);
    t4 = (t0 + 1012);
    xsi_vlogvar_assign_value(t4, t8, 0, 0, 16);
    goto LAB21;

LAB9:    xsi_set_current_line(601, ng0);

LAB23:    xsi_set_current_line(602, ng0);
    t4 = (t0 + 692U);
    t5 = *((char **)t4);
    t4 = (t0 + 784U);
    t7 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_unsigned_minus(t8, 16, t5, 16, t7, 16);
    t4 = (t0 + 1012);
    xsi_vlogvar_assign_value(t4, t8, 0, 0, 16);
    xsi_set_current_line(603, ng0);
    t2 = (t0 + 1012);
    t4 = (t2 + 36U);
    t5 = *((char **)t4);
    t7 = ((char*)((ng3)));
    memset(t8, 0, 8);
    t9 = (t5 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB25;

LAB24:    if (t20 != 0)
        goto LAB26;

LAB27:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB28;

LAB29:    xsi_set_current_line(609, ng0);

LAB32:    xsi_set_current_line(611, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);

LAB30:    goto LAB21;

LAB11:    xsi_set_current_line(616, ng0);

LAB33:    xsi_set_current_line(617, ng0);
    t4 = (t0 + 692U);
    t5 = *((char **)t4);
    t4 = (t0 + 784U);
    t7 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_unsigned_divide(t8, 16, t5, 16, t7, 16);
    t4 = (t0 + 1012);
    xsi_vlogvar_assign_value(t4, t8, 0, 0, 16);
    xsi_set_current_line(618, ng0);
    t2 = (t0 + 692U);
    t4 = *((char **)t2);
    t2 = (t0 + 784U);
    t5 = *((char **)t2);
    memset(t8, 0, 8);
    xsi_vlog_unsigned_mod(t8, 16, t4, 16, t5, 16);
    t2 = (t0 + 1104);
    xsi_vlogvar_assign_value(t2, t8, 0, 0, 16);
    goto LAB21;

LAB13:    xsi_set_current_line(621, ng0);
    t4 = (t0 + 692U);
    t5 = *((char **)t4);
    t4 = (t0 + 784U);
    t7 = *((char **)t4);
    t11 = *((unsigned int *)t5);
    t12 = *((unsigned int *)t7);
    t13 = (t11 | t12);
    *((unsigned int *)t8) = t13;
    t4 = (t5 + 4);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t14 = *((unsigned int *)t4);
    t15 = *((unsigned int *)t9);
    t16 = (t14 | t15);
    *((unsigned int *)t10) = t16;
    t17 = *((unsigned int *)t10);
    t18 = (t17 != 0);
    if (t18 == 1)
        goto LAB34;

LAB35:
LAB36:    t30 = (t0 + 1012);
    xsi_vlogvar_assign_value(t30, t8, 0, 0, 16);
    goto LAB21;

LAB15:    xsi_set_current_line(625, ng0);
    t4 = (t0 + 784U);
    t5 = *((char **)t4);
    t4 = (t0 + 692U);
    t7 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_unsigned_lshift(t8, 16, t5, 16, t7, 16);
    t4 = (t0 + 1012);
    xsi_vlogvar_assign_value(t4, t8, 0, 0, 16);
    goto LAB21;

LAB17:    xsi_set_current_line(628, ng0);
    t4 = (t0 + 784U);
    t5 = *((char **)t4);
    t4 = (t0 + 692U);
    t7 = *((char **)t4);
    memset(t37, 0, 8);
    xsi_vlog_signed_arith_rshift(t37, 16, t5, 16, t7, 16);
    t4 = (t0 + 1012);
    xsi_vlogvar_assign_value(t4, t37, 0, 0, 16);
    goto LAB21;

LAB19:    xsi_set_current_line(630, ng0);
    t4 = (t0 + 784U);
    t5 = *((char **)t4);
    t4 = (t0 + 692U);
    t7 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_unsigned_rshift(t8, 16, t5, 16, t7, 16);
    t4 = (t0 + 1012);
    xsi_vlogvar_assign_value(t4, t8, 0, 0, 16);
    goto LAB21;

LAB25:    *((unsigned int *)t8) = 1;
    goto LAB27;

LAB26:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB27;

LAB28:    xsi_set_current_line(604, ng0);

LAB31:    xsi_set_current_line(606, ng0);
    t30 = ((char*)((ng4)));
    t31 = (t0 + 1196);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 1);
    goto LAB30;

LAB34:    t19 = *((unsigned int *)t8);
    t20 = *((unsigned int *)t10);
    *((unsigned int *)t8) = (t19 | t20);
    t23 = (t5 + 4);
    t24 = (t7 + 4);
    t21 = *((unsigned int *)t23);
    t22 = (~(t21));
    t25 = *((unsigned int *)t5);
    t32 = (t25 & t22);
    t26 = *((unsigned int *)t24);
    t27 = (~(t26));
    t28 = *((unsigned int *)t7);
    t33 = (t28 & t27);
    t29 = (~(t32));
    t34 = (~(t33));
    t35 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t35 & t29);
    t36 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t36 & t34);
    goto LAB36;

}


extern void work_m_00000000001222927670_2587490486_init()
{
	static char *pe[] = {(void *)Always_584_0};
	xsi_register_didat("work_m_00000000001222927670_2587490486", "isim/testbench_isim_beh.exe.sim/work/m_00000000001222927670_2587490486.didat");
	xsi_register_executes(pe);
}
