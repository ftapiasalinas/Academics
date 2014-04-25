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
static unsigned int ng1[] = {1184U, 0U};
static unsigned int ng2[] = {11U, 0U};
static unsigned int ng3[] = {32U, 0U};
static unsigned int ng4[] = {14U, 0U};
static unsigned int ng5[] = {160U, 0U};
static unsigned int ng6[] = {161U, 0U};
static unsigned int ng7[] = {178U, 0U};
static unsigned int ng8[] = {51U, 0U};
static unsigned int ng9[] = {164U, 0U};
static unsigned int ng10[] = {165U, 0U};
static unsigned int ng11[] = {166U, 0U};
static unsigned int ng12[] = {101U, 0U};
static unsigned int ng13[] = {183U, 0U};
static unsigned int ng14[] = {5U, 0U};
static unsigned int ng15[] = {168U, 0U};
static unsigned int ng16[] = {12U, 0U};
static unsigned int ng17[] = {169U, 0U};
static unsigned int ng18[] = {128U, 0U};
static unsigned int ng19[] = {58U, 0U};
static unsigned int ng20[] = {171U, 0U};
static unsigned int ng21[] = {204U, 0U};
static unsigned int ng22[] = {7U, 0U};
static unsigned int ng23[] = {45U, 0U};
static unsigned int ng24[] = {4294967295U, 0U};
static unsigned int ng25[] = {0U, 0U};



static void Always_478_0(char *t0)
{
    char t14[8];
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
    char *t13;
    unsigned int t15;

LAB0:    t1 = (t0 + 14048U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(478, ng0);
    t2 = (t0 + 14616);
    *((int *)t2) = 1;
    t3 = (t0 + 14080);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(479, ng0);

LAB5:    xsi_set_current_line(480, ng0);
    t4 = (t0 + 2008U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(518, ng0);

LAB10:    xsi_set_current_line(519, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    memset(t14, 0, 8);
    t2 = (t14 + 4);
    t4 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 8);
    *((unsigned int *)t14) = t7;
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 8);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t10 & 255U);
    t15 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t15 & 255U);
    t5 = (t0 + 8808);
    xsi_vlogvar_assign_value(t5, t14, 0, 0, 8);
    xsi_set_current_line(520, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    memset(t14, 0, 8);
    t2 = (t14 + 4);
    t4 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    *((unsigned int *)t14) = t7;
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t10 & 255U);
    t15 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t15 & 255U);
    t5 = (t0 + 8968);
    xsi_vlogvar_assign_value(t5, t14, 0, 0, 8);
    xsi_set_current_line(522, ng0);
    t2 = (t0 + 1368U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB11;

LAB12:    xsi_set_current_line(525, ng0);
    t2 = ((char*)((ng25)));
    t3 = (t0 + 13128);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB13:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(481, ng0);

LAB9:    xsi_set_current_line(482, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 8008);
    xsi_vlogvar_assign_value(t12, t11, 0, 0, 8);
    t13 = (t0 + 12968);
    xsi_vlogvar_assign_value(t13, t11, 8, 0, 8);
    xsi_set_current_line(484, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 8168);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(484, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 8328);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(486, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 8488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(486, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 8648);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(488, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 8808);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(488, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 8968);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(490, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 9128);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(490, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 9288);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(492, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 9448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(492, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 11208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(494, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 11368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(494, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 11528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(496, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 11688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(496, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 11848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(498, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 12008);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(498, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 12168);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(500, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 12648);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(500, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 9608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(502, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 12328);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(502, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 12488);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(504, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 9768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(504, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 9928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(506, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 10088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(506, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 10248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(508, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 10408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(508, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 10568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(510, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 10728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(510, ng0);
    t2 = ((char*)((ng21)));
    t3 = (t0 + 10888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(512, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 11048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(512, ng0);
    t2 = ((char*)((ng23)));
    t3 = (t0 + 12808);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(514, ng0);
    t2 = ((char*)((ng24)));
    t3 = (t0 + 13128);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB8;

LAB11:    xsi_set_current_line(523, ng0);
    t4 = (t0 + 7448U);
    t5 = *((char **)t4);
    t4 = (t0 + 13128);
    xsi_vlogvar_assign_value(t4, t5, 0, 0, 32);
    goto LAB13;

}

static void implSig1_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 14296U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng25)));
    t3 = (t0 + 14696);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 65535U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 15);

LAB1:    return;
}


extern void work_m_00000000004286915414_2381739659_init()
{
	static char *pe[] = {(void *)Always_478_0,(void *)implSig1_execute};
	xsi_register_didat("work_m_00000000004286915414_2381739659", "isim/testbench_isim_beh.exe.sim/work/m_00000000004286915414_2381739659.didat");
	xsi_register_executes(pe);
}
