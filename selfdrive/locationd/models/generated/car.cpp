#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2996987840940209969) {
   out_2996987840940209969[0] = delta_x[0] + nom_x[0];
   out_2996987840940209969[1] = delta_x[1] + nom_x[1];
   out_2996987840940209969[2] = delta_x[2] + nom_x[2];
   out_2996987840940209969[3] = delta_x[3] + nom_x[3];
   out_2996987840940209969[4] = delta_x[4] + nom_x[4];
   out_2996987840940209969[5] = delta_x[5] + nom_x[5];
   out_2996987840940209969[6] = delta_x[6] + nom_x[6];
   out_2996987840940209969[7] = delta_x[7] + nom_x[7];
   out_2996987840940209969[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7773820477739863926) {
   out_7773820477739863926[0] = -nom_x[0] + true_x[0];
   out_7773820477739863926[1] = -nom_x[1] + true_x[1];
   out_7773820477739863926[2] = -nom_x[2] + true_x[2];
   out_7773820477739863926[3] = -nom_x[3] + true_x[3];
   out_7773820477739863926[4] = -nom_x[4] + true_x[4];
   out_7773820477739863926[5] = -nom_x[5] + true_x[5];
   out_7773820477739863926[6] = -nom_x[6] + true_x[6];
   out_7773820477739863926[7] = -nom_x[7] + true_x[7];
   out_7773820477739863926[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6408861910983383116) {
   out_6408861910983383116[0] = 1.0;
   out_6408861910983383116[1] = 0;
   out_6408861910983383116[2] = 0;
   out_6408861910983383116[3] = 0;
   out_6408861910983383116[4] = 0;
   out_6408861910983383116[5] = 0;
   out_6408861910983383116[6] = 0;
   out_6408861910983383116[7] = 0;
   out_6408861910983383116[8] = 0;
   out_6408861910983383116[9] = 0;
   out_6408861910983383116[10] = 1.0;
   out_6408861910983383116[11] = 0;
   out_6408861910983383116[12] = 0;
   out_6408861910983383116[13] = 0;
   out_6408861910983383116[14] = 0;
   out_6408861910983383116[15] = 0;
   out_6408861910983383116[16] = 0;
   out_6408861910983383116[17] = 0;
   out_6408861910983383116[18] = 0;
   out_6408861910983383116[19] = 0;
   out_6408861910983383116[20] = 1.0;
   out_6408861910983383116[21] = 0;
   out_6408861910983383116[22] = 0;
   out_6408861910983383116[23] = 0;
   out_6408861910983383116[24] = 0;
   out_6408861910983383116[25] = 0;
   out_6408861910983383116[26] = 0;
   out_6408861910983383116[27] = 0;
   out_6408861910983383116[28] = 0;
   out_6408861910983383116[29] = 0;
   out_6408861910983383116[30] = 1.0;
   out_6408861910983383116[31] = 0;
   out_6408861910983383116[32] = 0;
   out_6408861910983383116[33] = 0;
   out_6408861910983383116[34] = 0;
   out_6408861910983383116[35] = 0;
   out_6408861910983383116[36] = 0;
   out_6408861910983383116[37] = 0;
   out_6408861910983383116[38] = 0;
   out_6408861910983383116[39] = 0;
   out_6408861910983383116[40] = 1.0;
   out_6408861910983383116[41] = 0;
   out_6408861910983383116[42] = 0;
   out_6408861910983383116[43] = 0;
   out_6408861910983383116[44] = 0;
   out_6408861910983383116[45] = 0;
   out_6408861910983383116[46] = 0;
   out_6408861910983383116[47] = 0;
   out_6408861910983383116[48] = 0;
   out_6408861910983383116[49] = 0;
   out_6408861910983383116[50] = 1.0;
   out_6408861910983383116[51] = 0;
   out_6408861910983383116[52] = 0;
   out_6408861910983383116[53] = 0;
   out_6408861910983383116[54] = 0;
   out_6408861910983383116[55] = 0;
   out_6408861910983383116[56] = 0;
   out_6408861910983383116[57] = 0;
   out_6408861910983383116[58] = 0;
   out_6408861910983383116[59] = 0;
   out_6408861910983383116[60] = 1.0;
   out_6408861910983383116[61] = 0;
   out_6408861910983383116[62] = 0;
   out_6408861910983383116[63] = 0;
   out_6408861910983383116[64] = 0;
   out_6408861910983383116[65] = 0;
   out_6408861910983383116[66] = 0;
   out_6408861910983383116[67] = 0;
   out_6408861910983383116[68] = 0;
   out_6408861910983383116[69] = 0;
   out_6408861910983383116[70] = 1.0;
   out_6408861910983383116[71] = 0;
   out_6408861910983383116[72] = 0;
   out_6408861910983383116[73] = 0;
   out_6408861910983383116[74] = 0;
   out_6408861910983383116[75] = 0;
   out_6408861910983383116[76] = 0;
   out_6408861910983383116[77] = 0;
   out_6408861910983383116[78] = 0;
   out_6408861910983383116[79] = 0;
   out_6408861910983383116[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3226443868375093669) {
   out_3226443868375093669[0] = state[0];
   out_3226443868375093669[1] = state[1];
   out_3226443868375093669[2] = state[2];
   out_3226443868375093669[3] = state[3];
   out_3226443868375093669[4] = state[4];
   out_3226443868375093669[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3226443868375093669[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3226443868375093669[7] = state[7];
   out_3226443868375093669[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7633556307026359504) {
   out_7633556307026359504[0] = 1;
   out_7633556307026359504[1] = 0;
   out_7633556307026359504[2] = 0;
   out_7633556307026359504[3] = 0;
   out_7633556307026359504[4] = 0;
   out_7633556307026359504[5] = 0;
   out_7633556307026359504[6] = 0;
   out_7633556307026359504[7] = 0;
   out_7633556307026359504[8] = 0;
   out_7633556307026359504[9] = 0;
   out_7633556307026359504[10] = 1;
   out_7633556307026359504[11] = 0;
   out_7633556307026359504[12] = 0;
   out_7633556307026359504[13] = 0;
   out_7633556307026359504[14] = 0;
   out_7633556307026359504[15] = 0;
   out_7633556307026359504[16] = 0;
   out_7633556307026359504[17] = 0;
   out_7633556307026359504[18] = 0;
   out_7633556307026359504[19] = 0;
   out_7633556307026359504[20] = 1;
   out_7633556307026359504[21] = 0;
   out_7633556307026359504[22] = 0;
   out_7633556307026359504[23] = 0;
   out_7633556307026359504[24] = 0;
   out_7633556307026359504[25] = 0;
   out_7633556307026359504[26] = 0;
   out_7633556307026359504[27] = 0;
   out_7633556307026359504[28] = 0;
   out_7633556307026359504[29] = 0;
   out_7633556307026359504[30] = 1;
   out_7633556307026359504[31] = 0;
   out_7633556307026359504[32] = 0;
   out_7633556307026359504[33] = 0;
   out_7633556307026359504[34] = 0;
   out_7633556307026359504[35] = 0;
   out_7633556307026359504[36] = 0;
   out_7633556307026359504[37] = 0;
   out_7633556307026359504[38] = 0;
   out_7633556307026359504[39] = 0;
   out_7633556307026359504[40] = 1;
   out_7633556307026359504[41] = 0;
   out_7633556307026359504[42] = 0;
   out_7633556307026359504[43] = 0;
   out_7633556307026359504[44] = 0;
   out_7633556307026359504[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7633556307026359504[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7633556307026359504[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7633556307026359504[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7633556307026359504[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7633556307026359504[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7633556307026359504[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7633556307026359504[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7633556307026359504[53] = -9.8000000000000007*dt;
   out_7633556307026359504[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7633556307026359504[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7633556307026359504[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7633556307026359504[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7633556307026359504[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7633556307026359504[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7633556307026359504[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7633556307026359504[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7633556307026359504[62] = 0;
   out_7633556307026359504[63] = 0;
   out_7633556307026359504[64] = 0;
   out_7633556307026359504[65] = 0;
   out_7633556307026359504[66] = 0;
   out_7633556307026359504[67] = 0;
   out_7633556307026359504[68] = 0;
   out_7633556307026359504[69] = 0;
   out_7633556307026359504[70] = 1;
   out_7633556307026359504[71] = 0;
   out_7633556307026359504[72] = 0;
   out_7633556307026359504[73] = 0;
   out_7633556307026359504[74] = 0;
   out_7633556307026359504[75] = 0;
   out_7633556307026359504[76] = 0;
   out_7633556307026359504[77] = 0;
   out_7633556307026359504[78] = 0;
   out_7633556307026359504[79] = 0;
   out_7633556307026359504[80] = 1;
}
void h_25(double *state, double *unused, double *out_5538059647569476415) {
   out_5538059647569476415[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5117248484210377327) {
   out_5117248484210377327[0] = 0;
   out_5117248484210377327[1] = 0;
   out_5117248484210377327[2] = 0;
   out_5117248484210377327[3] = 0;
   out_5117248484210377327[4] = 0;
   out_5117248484210377327[5] = 0;
   out_5117248484210377327[6] = 1;
   out_5117248484210377327[7] = 0;
   out_5117248484210377327[8] = 0;
}
void h_24(double *state, double *unused, double *out_9052054595967233791) {
   out_9052054595967233791[0] = state[4];
   out_9052054595967233791[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2944598885204877761) {
   out_2944598885204877761[0] = 0;
   out_2944598885204877761[1] = 0;
   out_2944598885204877761[2] = 0;
   out_2944598885204877761[3] = 0;
   out_2944598885204877761[4] = 1;
   out_2944598885204877761[5] = 0;
   out_2944598885204877761[6] = 0;
   out_2944598885204877761[7] = 0;
   out_2944598885204877761[8] = 0;
   out_2944598885204877761[9] = 0;
   out_2944598885204877761[10] = 0;
   out_2944598885204877761[11] = 0;
   out_2944598885204877761[12] = 0;
   out_2944598885204877761[13] = 0;
   out_2944598885204877761[14] = 1;
   out_2944598885204877761[15] = 0;
   out_2944598885204877761[16] = 0;
   out_2944598885204877761[17] = 0;
}
void h_30(double *state, double *unused, double *out_4087428254940593248) {
   out_4087428254940593248[0] = state[4];
}
void H_30(double *state, double *unused, double *out_589552154082769129) {
   out_589552154082769129[0] = 0;
   out_589552154082769129[1] = 0;
   out_589552154082769129[2] = 0;
   out_589552154082769129[3] = 0;
   out_589552154082769129[4] = 1;
   out_589552154082769129[5] = 0;
   out_589552154082769129[6] = 0;
   out_589552154082769129[7] = 0;
   out_589552154082769129[8] = 0;
}
void h_26(double *state, double *unused, double *out_978989263777749475) {
   out_978989263777749475[0] = state[7];
}
void H_26(double *state, double *unused, double *out_1375745165336321103) {
   out_1375745165336321103[0] = 0;
   out_1375745165336321103[1] = 0;
   out_1375745165336321103[2] = 0;
   out_1375745165336321103[3] = 0;
   out_1375745165336321103[4] = 0;
   out_1375745165336321103[5] = 0;
   out_1375745165336321103[6] = 0;
   out_1375745165336321103[7] = 1;
   out_1375745165336321103[8] = 0;
}
void h_27(double *state, double *unused, double *out_7907011158479229556) {
   out_7907011158479229556[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2813146225266712346) {
   out_2813146225266712346[0] = 0;
   out_2813146225266712346[1] = 0;
   out_2813146225266712346[2] = 0;
   out_2813146225266712346[3] = 1;
   out_2813146225266712346[4] = 0;
   out_2813146225266712346[5] = 0;
   out_2813146225266712346[6] = 0;
   out_2813146225266712346[7] = 0;
   out_2813146225266712346[8] = 0;
}
void h_29(double *state, double *unused, double *out_9089101522601438893) {
   out_9089101522601438893[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1099783498397161313) {
   out_1099783498397161313[0] = 0;
   out_1099783498397161313[1] = 1;
   out_1099783498397161313[2] = 0;
   out_1099783498397161313[3] = 0;
   out_1099783498397161313[4] = 0;
   out_1099783498397161313[5] = 0;
   out_1099783498397161313[6] = 0;
   out_1099783498397161313[7] = 0;
   out_1099783498397161313[8] = 0;
}
void h_28(double *state, double *unused, double *out_4277255159493442747) {
   out_4277255159493442747[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3063413769962487564) {
   out_3063413769962487564[0] = 1;
   out_3063413769962487564[1] = 0;
   out_3063413769962487564[2] = 0;
   out_3063413769962487564[3] = 0;
   out_3063413769962487564[4] = 0;
   out_3063413769962487564[5] = 0;
   out_3063413769962487564[6] = 0;
   out_3063413769962487564[7] = 0;
   out_3063413769962487564[8] = 0;
}
void h_31(double *state, double *unused, double *out_6137849199789724265) {
   out_6137849199789724265[0] = state[8];
}
void H_31(double *state, double *unused, double *out_749537063102969627) {
   out_749537063102969627[0] = 0;
   out_749537063102969627[1] = 0;
   out_749537063102969627[2] = 0;
   out_749537063102969627[3] = 0;
   out_749537063102969627[4] = 0;
   out_749537063102969627[5] = 0;
   out_749537063102969627[6] = 0;
   out_749537063102969627[7] = 0;
   out_749537063102969627[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_2996987840940209969) {
  err_fun(nom_x, delta_x, out_2996987840940209969);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7773820477739863926) {
  inv_err_fun(nom_x, true_x, out_7773820477739863926);
}
void car_H_mod_fun(double *state, double *out_6408861910983383116) {
  H_mod_fun(state, out_6408861910983383116);
}
void car_f_fun(double *state, double dt, double *out_3226443868375093669) {
  f_fun(state,  dt, out_3226443868375093669);
}
void car_F_fun(double *state, double dt, double *out_7633556307026359504) {
  F_fun(state,  dt, out_7633556307026359504);
}
void car_h_25(double *state, double *unused, double *out_5538059647569476415) {
  h_25(state, unused, out_5538059647569476415);
}
void car_H_25(double *state, double *unused, double *out_5117248484210377327) {
  H_25(state, unused, out_5117248484210377327);
}
void car_h_24(double *state, double *unused, double *out_9052054595967233791) {
  h_24(state, unused, out_9052054595967233791);
}
void car_H_24(double *state, double *unused, double *out_2944598885204877761) {
  H_24(state, unused, out_2944598885204877761);
}
void car_h_30(double *state, double *unused, double *out_4087428254940593248) {
  h_30(state, unused, out_4087428254940593248);
}
void car_H_30(double *state, double *unused, double *out_589552154082769129) {
  H_30(state, unused, out_589552154082769129);
}
void car_h_26(double *state, double *unused, double *out_978989263777749475) {
  h_26(state, unused, out_978989263777749475);
}
void car_H_26(double *state, double *unused, double *out_1375745165336321103) {
  H_26(state, unused, out_1375745165336321103);
}
void car_h_27(double *state, double *unused, double *out_7907011158479229556) {
  h_27(state, unused, out_7907011158479229556);
}
void car_H_27(double *state, double *unused, double *out_2813146225266712346) {
  H_27(state, unused, out_2813146225266712346);
}
void car_h_29(double *state, double *unused, double *out_9089101522601438893) {
  h_29(state, unused, out_9089101522601438893);
}
void car_H_29(double *state, double *unused, double *out_1099783498397161313) {
  H_29(state, unused, out_1099783498397161313);
}
void car_h_28(double *state, double *unused, double *out_4277255159493442747) {
  h_28(state, unused, out_4277255159493442747);
}
void car_H_28(double *state, double *unused, double *out_3063413769962487564) {
  H_28(state, unused, out_3063413769962487564);
}
void car_h_31(double *state, double *unused, double *out_6137849199789724265) {
  h_31(state, unused, out_6137849199789724265);
}
void car_H_31(double *state, double *unused, double *out_749537063102969627) {
  H_31(state, unused, out_749537063102969627);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
