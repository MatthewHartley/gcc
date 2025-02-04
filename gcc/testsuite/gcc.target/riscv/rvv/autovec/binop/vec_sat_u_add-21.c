/* { dg-do compile } */
/* { dg-options "-march=rv64gcv -mabi=lp64d -O3 -ftree-vectorize -fdump-rtl-expand-details -fno-schedule-insns -fno-schedule-insns2" } */
/* { dg-skip-if "" { *-*-* } { "-flto" } } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "../vec_sat_arith.h"

/*
** vec_sat_u_add_uint8_t_fmt_6:
** ...
** vsetvli\s+[atx][0-9]+,\s*zero,\s*e8,\s*m1,\s*ta,\s*ma
** ...
** vsaddu\.vv\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+
** ...
*/
DEF_VEC_SAT_U_ADD_FMT_6(uint8_t)

/* { dg-final { scan-rtl-dump-times ".SAT_ADD " 2 "expand" } } */
