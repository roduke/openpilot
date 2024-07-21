#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_2996987840940209969);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7773820477739863926);
void car_H_mod_fun(double *state, double *out_6408861910983383116);
void car_f_fun(double *state, double dt, double *out_3226443868375093669);
void car_F_fun(double *state, double dt, double *out_7633556307026359504);
void car_h_25(double *state, double *unused, double *out_5538059647569476415);
void car_H_25(double *state, double *unused, double *out_5117248484210377327);
void car_h_24(double *state, double *unused, double *out_9052054595967233791);
void car_H_24(double *state, double *unused, double *out_2944598885204877761);
void car_h_30(double *state, double *unused, double *out_4087428254940593248);
void car_H_30(double *state, double *unused, double *out_589552154082769129);
void car_h_26(double *state, double *unused, double *out_978989263777749475);
void car_H_26(double *state, double *unused, double *out_1375745165336321103);
void car_h_27(double *state, double *unused, double *out_7907011158479229556);
void car_H_27(double *state, double *unused, double *out_2813146225266712346);
void car_h_29(double *state, double *unused, double *out_9089101522601438893);
void car_H_29(double *state, double *unused, double *out_1099783498397161313);
void car_h_28(double *state, double *unused, double *out_4277255159493442747);
void car_H_28(double *state, double *unused, double *out_3063413769962487564);
void car_h_31(double *state, double *unused, double *out_6137849199789724265);
void car_H_31(double *state, double *unused, double *out_749537063102969627);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}