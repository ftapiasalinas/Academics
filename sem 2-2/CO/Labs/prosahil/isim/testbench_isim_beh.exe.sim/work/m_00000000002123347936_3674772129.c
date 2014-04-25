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
static unsigned int ng2[] = {8U, 0U};
static unsigned int ng3[] = {20U, 0U};
static unsigned int ng4[] = {32U, 0U};
static unsigned int ng5[] = {1U, 0U};
static unsigned int ng6[] = {5U, 0U};



static void Gate_179_0(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 5032U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2164U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 1152U);
    t13 = *((char **)t12);
    t12 = (t0 + 6488);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    xsi_vlog_AndGate(t17, 2, t4, t13);
    t18 = (t0 + 6488);
    xsi_driver_vfirst_trans(t18, 0, 0);
    t19 = (t0 + 6380);
    *((int *)t19) = 1;

LAB1:    return;
}

static void Gate_180_1(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 5176U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2164U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 1);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 1);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 1152U);
    t13 = *((char **)t12);
    t12 = (t0 + 6524);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    xsi_vlog_AndGate(t17, 2, t4, t13);
    t18 = (t0 + 6524);
    xsi_driver_vfirst_trans(t18, 0, 0);
    t19 = (t0 + 6388);
    *((int *)t19) = 1;

LAB1:    return;
}

static void Gate_181_2(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 5320U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2164U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 2);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 2);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 1152U);
    t13 = *((char **)t12);
    t12 = (t0 + 6560);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    xsi_vlog_AndGate(t17, 2, t4, t13);
    t18 = (t0 + 6560);
    xsi_driver_vfirst_trans(t18, 0, 0);
    t19 = (t0 + 6396);
    *((int *)t19) = 1;

LAB1:    return;
}

static void Gate_182_3(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 5464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2164U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 3);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 3);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 1152U);
    t13 = *((char **)t12);
    t12 = (t0 + 6596);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    xsi_vlog_AndGate(t17, 2, t4, t13);
    t18 = (t0 + 6596);
    xsi_driver_vfirst_trans(t18, 0, 0);
    t19 = (t0 + 6404);
    *((int *)t19) = 1;

LAB1:    return;
}

static void Gate_183_4(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 5608U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2164U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 4);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 4);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 1152U);
    t13 = *((char **)t12);
    t12 = (t0 + 6632);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    xsi_vlog_AndGate(t17, 2, t4, t13);
    t18 = (t0 + 6632);
    xsi_driver_vfirst_trans(t18, 0, 0);
    t19 = (t0 + 6412);
    *((int *)t19) = 1;

LAB1:    return;
}

static void Gate_184_5(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 5752U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2164U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 5);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 5);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 1152U);
    t13 = *((char **)t12);
    t12 = (t0 + 6668);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    xsi_vlog_AndGate(t17, 2, t4, t13);
    t18 = (t0 + 6668);
    xsi_driver_vfirst_trans(t18, 0, 0);
    t19 = (t0 + 6420);
    *((int *)t19) = 1;

LAB1:    return;
}

static void Gate_185_6(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 5896U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2164U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 6);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 6);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 1152U);
    t13 = *((char **)t12);
    t12 = (t0 + 6704);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    xsi_vlog_AndGate(t17, 2, t4, t13);
    t18 = (t0 + 6704);
    xsi_driver_vfirst_trans(t18, 0, 0);
    t19 = (t0 + 6428);
    *((int *)t19) = 1;

LAB1:    return;
}

static void Gate_186_7(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 6040U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2164U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 7);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 7);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 1152U);
    t13 = *((char **)t12);
    t12 = (t0 + 6740);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    xsi_vlog_AndGate(t17, 2, t4, t13);
    t18 = (t0 + 6740);
    xsi_driver_vfirst_trans(t18, 0, 0);
    t19 = (t0 + 6436);
    *((int *)t19) = 1;

LAB1:    return;
}

static void Always_202_8(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;

LAB0:    t1 = (t0 + 6184U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(202, ng0);
    t2 = (t0 + 6444);
    *((int *)t2) = 1;
    t3 = (t0 + 6212);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(203, ng0);

LAB5:    xsi_set_current_line(204, ng0);
    t4 = (t0 + 1336U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(226, ng0);

LAB10:    xsi_set_current_line(227, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t0 + 3956);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 16);
    xsi_set_current_line(228, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t0 + 4048);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 16);
    xsi_set_current_line(229, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t0 + 4140);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 16);
    xsi_set_current_line(230, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t0 + 4232);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 16);
    xsi_set_current_line(231, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t0 + 4324);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 16);
    xsi_set_current_line(232, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t0 + 4416);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 16);
    xsi_set_current_line(233, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t0 + 3864);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 16);
    xsi_set_current_line(235, ng0);
    t2 = (t0 + 2256U);
    t3 = *((char **)t2);
    t2 = (t0 + 3128);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    xsi_set_current_line(236, ng0);
    t2 = (t0 + 2348U);
    t3 = *((char **)t2);
    t2 = (t0 + 3220);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    xsi_set_current_line(237, ng0);
    t2 = (t0 + 2440U);
    t3 = *((char **)t2);
    t2 = (t0 + 3312);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    xsi_set_current_line(238, ng0);
    t2 = (t0 + 2532U);
    t3 = *((char **)t2);
    t2 = (t0 + 3404);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    xsi_set_current_line(239, ng0);
    t2 = (t0 + 2624U);
    t3 = *((char **)t2);
    t2 = (t0 + 3496);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    xsi_set_current_line(240, ng0);
    t2 = (t0 + 2716U);
    t3 = *((char **)t2);
    t2 = (t0 + 3588);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    xsi_set_current_line(241, ng0);
    t2 = (t0 + 2808U);
    t3 = *((char **)t2);
    t2 = (t0 + 3680);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    xsi_set_current_line(242, ng0);
    t2 = (t0 + 2900U);
    t3 = *((char **)t2);
    t2 = (t0 + 3772);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(205, ng0);

LAB9:    xsi_set_current_line(206, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 4508);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 16);
    xsi_set_current_line(207, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3864);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(208, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 3956);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(209, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 4048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(210, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 4140);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(211, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 4232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(212, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 4324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(213, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4416);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(215, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3128);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(216, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3220);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(217, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3312);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(218, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3404);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(219, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3496);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(220, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3588);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(221, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3680);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(222, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 3772);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB8;

}


extern void work_m_00000000002123347936_3674772129_init()
{
	static char *pe[] = {(void *)Gate_179_0,(void *)Gate_180_1,(void *)Gate_181_2,(void *)Gate_182_3,(void *)Gate_183_4,(void *)Gate_184_5,(void *)Gate_185_6,(void *)Gate_186_7,(void *)Always_202_8};
	xsi_register_didat("work_m_00000000002123347936_3674772129", "isim/testbench_isim_beh.exe.sim/work/m_00000000002123347936_3674772129.didat");
	xsi_register_executes(pe);
}
