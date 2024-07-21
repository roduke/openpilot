#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_8093280458722028871);
void live_err_fun(double *nom_x, double *delta_x, double *out_2329582857333837057);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_4575116125226568338);
void live_H_mod_fun(double *state, double *out_3554337354835071978);
void live_f_fun(double *state, double dt, double *out_8072129119001875925);
void live_F_fun(double *state, double dt, double *out_8922137796898738244);
void live_h_4(double *state, double *unused, double *out_5764221680073741306);
void live_H_4(double *state, double *unused, double *out_8699886012221389646);
void live_h_9(double *state, double *unused, double *out_4037350409543272207);
void live_H_9(double *state, double *unused, double *out_8458696365591799001);
void live_h_10(double *state, double *unused, double *out_1866788582643306631);
void live_H_10(double *state, double *unused, double *out_6599771279639068883);
void live_h_12(double *state, double *unused, double *out_7215564058970746752);
void live_H_12(double *state, double *unused, double *out_8078786987173795979);
void live_h_35(double *state, double *unused, double *out_8023320980266321701);
void live_H_35(double *state, double *unused, double *out_5333223954848782270);
void live_h_32(double *state, double *unused, double *out_1620715106595382419);
void live_H_32(double *state, double *unused, double *out_2628199441947032333);
void live_h_13(double *state, double *unused, double *out_5208451031767510303);
void live_H_13(double *state, double *unused, double *out_4622461517911340855);
void live_h_14(double *state, double *unused, double *out_4037350409543272207);
void live_H_14(double *state, double *unused, double *out_8458696365591799001);
void live_h_33(double *state, double *unused, double *out_3196664996622667359);
void live_H_33(double *state, double *unused, double *out_2182666950209924666);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}