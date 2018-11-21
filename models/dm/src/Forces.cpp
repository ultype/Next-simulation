#include <cmath>
#include "Force.hh"
#include "aux.hh"
#include "sim_services/include/simtime.h"
#define NRANSI
#include "nrutil.h"
#define MAXITS 20000000
#define ALF 1.0e-4
#define EPS 1.0e-7   // 1.0e-7
#define TOLF 1.0e-8  // 1.0e-4
#define TOLX 1.0e-9
#define STPMX 100.0
#define TOLMIN 1.0e-10  // 1.0e-6
#define FREERETURN                \
  do {                            \
    free_dvector(fvec, 1, n);     \
    free_dvector(xold, 1, n);     \
    free_dvector(w, 1, n);        \
    free_dvector(t, 1, n);        \
    free_dvector(s, 1, n);        \
    free_dmatrix(r, 1, n, 1, n);  \
    free_dmatrix(qt, 1, n, 1, n); \
    free_dvector(p, 1, n);        \
    free_dvector(g, 1, n);        \
    free_dvector(fvcold, 1, n);   \
    free_dvector(d, 1, n);        \
    free_dvector(c, 1, n);        \
    return;                       \
  } while (0);

double *fvec;
int nn;

Forces::Forces(Data_exchang &input)
    : VECTOR_INIT(FAPB, 3),
      VECTOR_INIT(FAP, 3),
      VECTOR_INIT(FMB, 3),
      VECTOR_INIT(FMAB, 3),
      VECTOR_INIT(Q_G, 6),
      VECTOR_INIT(Q_Aero, 6),
      VECTOR_INIT(rhoC_1, 3),
      MATRIX_INIT(I1, 3, 3),
      VECTOR_INIT(ddrP_1, 3),
      VECTOR_INIT(ddang_1, 3),
      VECTOR_INIT(dang_1, 3),
      VECTOR_INIT(ddrhoC_1, 3),
      VECTOR_INIT(p_b1_ga, 3),
      VECTOR_INIT(p_b1_be, 3),
      VECTOR_INIT(f, 6),
      VECTOR_INIT(gamma_b1_q1, 3),
      VECTOR_INIT(gamma_b1_q2, 3),
      VECTOR_INIT(gamma_b1_q3, 3),
      VECTOR_INIT(beta_b1_q4, 3),
      VECTOR_INIT(beta_b1_q5, 3),
      VECTOR_INIT(beta_b1_q6, 3) {
  data_exchang = &input;
}
Forces::Forces(const Forces &other)
    : VECTOR_INIT(FAPB, 3),
      VECTOR_INIT(FAP, 3),
      VECTOR_INIT(FMB, 3),
      VECTOR_INIT(FMAB, 3),
      VECTOR_INIT(Q_G, 6),
      VECTOR_INIT(Q_Aero, 6),
      VECTOR_INIT(rhoC_1, 3),
      MATRIX_INIT(I1, 3, 3),
      VECTOR_INIT(ddrP_1, 3),
      VECTOR_INIT(ddang_1, 3),
      VECTOR_INIT(dang_1, 3),
      VECTOR_INIT(ddrhoC_1, 3),
      VECTOR_INIT(p_b1_ga, 3),
      VECTOR_INIT(p_b1_be, 3),
      VECTOR_INIT(f, 6),
      VECTOR_INIT(gamma_b1_q1, 3),
      VECTOR_INIT(gamma_b1_q2, 3),
      VECTOR_INIT(gamma_b1_q3, 3),
      VECTOR_INIT(beta_b1_q4, 3),
      VECTOR_INIT(beta_b1_q5, 3),
      VECTOR_INIT(beta_b1_q6, 3) {
  this->data_exchang = other.data_exchang;
  this->FAP = other.FAP;
  this->FAPB = other.FAPB;
  this->FMB = other.FMB;
  this->FMAB = other.FMAB;
  this->Q_G = other.Q_G;
  this->Q_Aero = other.Q_Aero;
  this->rhoC_1 = other.rhoC_1;
  this->I1 = other.I1;
  this->ddrP_1 = other.ddrP_1;
  this->ddang_1 = other.ddang_1;
  this->dang_1 = other.dang_1;
  this->ddrhoC_1 = other.ddrhoC_1;
  this->p_b1_ga = other.p_b1_ga;
  this->p_b1_be = other.p_b1_be;
  this->f = other.f;
  this->gamma_b1_q1 = other.gamma_b1_q1;
  this->gamma_b1_q2 = other.gamma_b1_q2;
  this->gamma_b1_q3 = other.gamma_b1_q3;
  this->beta_b1_q4 = other.beta_b1_q4;
  this->beta_b1_q5 = other.beta_b1_q5;
  this->beta_b1_q6 = other.beta_b1_q6;
}

Forces &Forces::operator=(const Forces &other) {
  if (&other == this) return *this;
  this->data_exchang = other.data_exchang;
  this->FAP = other.FAP;
  this->FAPB = other.FAPB;
  this->FMB = other.FMB;
  this->FMAB = other.FMAB;
  this->Q_G = other.Q_G;
  this->Q_Aero = other.Q_Aero;
  this->rhoC_1 = other.rhoC_1;
  this->I1 = other.I1;
  this->ddrP_1 = other.ddrP_1;
  this->ddang_1 = other.ddang_1;
  this->dang_1 = other.dang_1;
  this->ddrhoC_1 = other.ddrhoC_1;
  this->p_b1_ga = other.p_b1_ga;
  this->p_b1_be = other.p_b1_be;
  this->f = other.f;
  this->gamma_b1_q1 = other.gamma_b1_q1;
  this->gamma_b1_q2 = other.gamma_b1_q2;
  this->gamma_b1_q3 = other.gamma_b1_q3;
  this->beta_b1_q4 = other.beta_b1_q4;
  this->beta_b1_q5 = other.beta_b1_q5;
  this->beta_b1_q6 = other.beta_b1_q6;
  return *this;
}

void Forces::default_data() {}

void Forces::init() {
  // gamma_beta();
  // Gravity_Q();
}

void Forces::set_DOF(int ndof) { DOF = ndof; }
void Forces::set_aero_flag(unsigned int in) { Aero_flag = in; }

void Forces::collect_forces_and_propagate() {
  double *ff, *x;
  int check(0);
  ff = new double[7];
  x = new double[7];
  /*****************input from another module*******************/

  data_exchang->hget("XCG", rhoC_1);
  data_exchang->hget("WBIB", dang_1);

  rhoC_1(0) = rhoC_1(0) - xp;

  calculate_I1();
  gamma_beta();
  Gravity_Q();
  if (Aero_flag == 1) {
    AeroDynamics_Q();
  }

  for (int i = 0; i < DOF; i++) {
    x[i + 1] = 0.0;
  }

  broydn(x, DOF, &check);

  funcv(DOF, x, ff);
  for (int i = 0; i < 3; i++) {
    ddrP_1(i) = x[i + 1];
    ddang_1(i) = x[i + 4];
  }

  ddrhoC_1 = cross(ddang_1, rhoC_1) +
             cross(dang_1, cross(dang_1, rhoC_1));  // Eq.(5-12)

  data_exchang->hset("ddrP_1", ddrP_1);
  data_exchang->hset("ddang_1", ddang_1);
  data_exchang->hset("rhoC_1", rhoC_1);
  data_exchang->hset("ddrhoC_1", ddrhoC_1);

  delete[] ff;
  delete[] x;
}

void Forces::gamma_beta() {
  // 1st generalized coordinate q1
  // Velocity coefficient
  gamma_b1_q1(0) = 1.0;
  gamma_b1_q1(1) = 0.0;
  gamma_b1_q1(2) = 0.0;

  // 2nd generalized coordinate q2
  gamma_b1_q2(0) = 0.0;
  gamma_b1_q2(1) = 1.0;
  gamma_b1_q2(2) = 0.0;

  // 3rd generalized coordinate q3
  gamma_b1_q3(0) = 0.0;
  gamma_b1_q3(1) = 0.0;
  gamma_b1_q3(2) = 1.0;

  // Angular velocity coefficients
  beta_b1_q4(0) = 1.0;
  beta_b1_q4(1) = 0.0;
  beta_b1_q4(2) = 0.0;

  // Angular velocity coefficients
  beta_b1_q5(0) = 0.0;
  beta_b1_q5(1) = 1.0;
  beta_b1_q5(2) = 0.0;

  // Angular velocity coefficients
  beta_b1_q6(0) = 0.0;
  beta_b1_q6(1) = 0.0;
  beta_b1_q6(2) = 1.0;
}

void Forces::AeroDynamics_Q() {
  double pdynmc;
  double refa;
  double refd;
  double cy;
  double cll;
  double clm;
  double cln;
  double cx;
  double cz;
  arma::vec3 XCP;
  arma::mat33 TBI;

  data_exchang->hget("pdynmc", &pdynmc);
  data_exchang->hget("refa", &refa);
  data_exchang->hget("refd", &refd);
  data_exchang->hget("cy", &cy);
  data_exchang->hget("cll", &cll);
  data_exchang->hget("clm", &clm);
  data_exchang->hget("cln", &cln);
  data_exchang->hget("cx", &cx);
  data_exchang->hget("cz", &cz);
  data_exchang->hget("XCP", XCP);
  data_exchang->hget("TBI", TBI);

  arma::vec3 rhoCP;
  rhoCP(0) = -(XCP(0) * refd) - (xp);
  rhoCP(1) = 0.0;
  rhoCP(2) = 0.0;

  // total non-gravitational forces
  FAPB = pdynmc * refa * arma::vec({cx, cy, cz});

  // aerodynamic moment
  FMAB = pdynmc * refa * refd * arma::vec({cll, clm, cln});

  Q_Aero(0) = dot(trans(TBI) * FAPB, gamma_b1_q1);
  Q_Aero(1) = dot(trans(TBI) * FAPB, gamma_b1_q2);
  Q_Aero(2) = dot(trans(TBI) * FAPB, gamma_b1_q3);
  Q_Aero(3) =
      dot(FMAB, beta_b1_q4) +
      dot(trans(TBI) * FAPB, -trans(TBI) * cross_matrix(rhoCP) * beta_b1_q4);
  Q_Aero(4) =
      dot(FMAB, beta_b1_q5) +
      dot(trans(TBI) * FAPB, -trans(TBI) * cross_matrix(rhoCP) * beta_b1_q5);
  Q_Aero(5) =
      dot(FMAB, beta_b1_q6) +
      dot(trans(TBI) * FAPB, -trans(TBI) * cross_matrix(rhoCP) * beta_b1_q6);

  data_exchang->hset("FAPB", FAPB);
  data_exchang->hset("FMAB", FMAB);
}

void Forces::Gravity_Q() {
  arma::vec3 GRAVG;
  arma::mat33 TBI;
  double vmass;
  int liftoff;

  data_exchang->hget("GRAVG", GRAVG);
  data_exchang->hget("TBI", TBI);
  data_exchang->hget("vmass", &vmass);
  data_exchang->hget("liftoff", &liftoff);

  arma::vec3 Fg;
  Fg = vmass * GRAVG;

  if (liftoff == 1) {
    Q_G(0) = dot(Fg, gamma_b1_q1);
    Q_G(1) = dot(Fg, gamma_b1_q2);
    Q_G(2) = dot(Fg, gamma_b1_q3);
    Q_G(3) = dot(Fg, -trans(TBI) * cross_matrix(rhoC_1) * beta_b1_q4);
    Q_G(4) = dot(Fg, -trans(TBI) * cross_matrix(rhoC_1) * beta_b1_q5);
    Q_G(5) = dot(Fg, -trans(TBI) * cross_matrix(rhoC_1) * beta_b1_q6);
  } else {
    Q_G(0) = dot(Fg, gamma_b1_q1);
    Q_G(1) = dot(Fg, gamma_b1_q2);
    Q_G(2) = dot(Fg, gamma_b1_q3);
    Q_G(3) = dot(Fg, -trans(TBI) * cross_matrix(rhoC_1) * beta_b1_q4);
    Q_G(4) = dot(Fg, -trans(TBI) * cross_matrix(rhoC_1) * beta_b1_q5);
    Q_G(5) = dot(Fg, -trans(TBI) * cross_matrix(rhoC_1) * beta_b1_q6);
  }
}

void Forces::calculate_I1() {
  double vmass;
  arma::mat33 IBBB;

  data_exchang->hget("vmass", &vmass);
  data_exchang->hget("IBBB", IBBB);

  I1(0, 0) =
      IBBB(0, 0) + (vmass) * (rhoC_1(1) * rhoC_1(1) + rhoC_1(2) * rhoC_1(2));
  I1(0, 1) = IBBB(0, 1) - (vmass)*rhoC_1(0) * rhoC_1(1);
  I1(0, 2) = IBBB(0, 2) - (vmass)*rhoC_1(0) * rhoC_1(2);
  I1(1, 0) = IBBB(1, 0) - (vmass)*rhoC_1(1) * rhoC_1(0);
  I1(1, 1) =
      IBBB(1, 1) + (vmass) * (rhoC_1(2) * rhoC_1(2) + rhoC_1(0) * rhoC_1(0));
  I1(1, 2) = IBBB(1, 2) - (vmass)*rhoC_1(1) * rhoC_1(2);
  I1(2, 0) = IBBB(2, 0) - (vmass)*rhoC_1(2) * rhoC_1(0);
  I1(2, 1) = IBBB(2, 1) - (vmass)*rhoC_1(2) * rhoC_1(1);
  I1(2, 2) =
      IBBB(2, 2) + (vmass) * (rhoC_1(0) * rhoC_1(0) + rhoC_1(1) * rhoC_1(1));
}

void Forces::funcv(int n, double *x, double *ff) {
  arma::mat33 TB1_I;
  double m1;
  arma::vec6 Q_TVC;
  data_exchang->hget("vmass", &m1);
  data_exchang->hget("Q_TVC", Q_TVC);
  data_exchang->hget("TBI", TB1_I);

  for (int i = 0; i < 3; i++) {
    ddrP_1(i) = x[i + 1];
    ddang_1(i) = x[i + 4];
  }

  ddrhoC_1 = cross(ddang_1, rhoC_1) +
             cross(dang_1, cross(dang_1, rhoC_1));  // Eq.(5-12)
  //  Eq.(5-19)
  p_b1_ga = m1 * (ddrP_1 + trans(TB1_I) * ddrhoC_1);
  p_b1_be = I1 * ddang_1 + cross_matrix(dang_1) * I1 * dang_1 +
            m1 * cross_matrix(rhoC_1) * TB1_I * ddrP_1;
  f(0) = dot(p_b1_ga, gamma_b1_q1) - (Q_G(0) + Q_TVC(0) + Q_Aero(0));
  f(1) = dot(p_b1_ga, gamma_b1_q2) - (Q_G(1) + Q_TVC(1) + Q_Aero(1));
  f(2) = dot(p_b1_ga, gamma_b1_q3) - (Q_G(2) + Q_TVC(2) + Q_Aero(2));
  f(3) = dot(p_b1_be, beta_b1_q4) - (Q_G(3) + Q_TVC(3) + Q_Aero(3));
  f(4) = dot(p_b1_be, beta_b1_q5) - (Q_G(4) + Q_TVC(4) + Q_Aero(4));
  f(5) = dot(p_b1_be, beta_b1_q6) - (Q_G(5) + Q_TVC(5) + Q_Aero(5));

  for (int i = 0; i < n; i++) {
    ff[i + 1] = f(i);
  }
}

void Forces::broydn(double x[], int n, int *check) {
  int i, j, k, restrt, sing, skip;
  double den, fff, fold, stpmax, sum, temp, test, *c, *d, *fvcold;
  double *g, *p, **qt, **r, *s, *t, *w, *xold;
  c = dvector(1, n);
  d = dvector(1, n);
  fvcold = dvector(1, n);
  g = dvector(1, n);
  p = dvector(1, n);
  qt = dmatrix(1, n, 1, n);
  r = dmatrix(1, n, 1, n);
  s = dvector(1, n);
  t = dvector(1, n);
  w = dvector(1, n);
  xold = dvector(1, n);
  fvec = dvector(1, n);
  nn = n;
  fff = f_min(x);
  test = 0.0;
  for (i = 1; i <= n; i++)
    if (fabs(fvec[i]) > test) test = fabs(fvec[i]);
  if (test < 0.01 * TOLF) {
    *check = 0;
    FREERETURN
  }
  for (sum = 0.0, i = 1; i <= n; i++) sum += DSQR(x[i]);
  stpmax = STPMX * DMAX(sqrt(sum), (double)n);
  restrt = 1;
  for (its = 1; its <= MAXITS; its++) {
    if (restrt) {
      fdjac(n, x, fvec, r);
      qrdcmp(r, n, c, d, &sing);
      if (sing) nrerror("singular Jacobian in broydn : qrdcmp");
      for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) qt[i][j] = 0.0;
        qt[i][i] = 1.0;
      }
      for (k = 1; k < n; k++) {
        if (c[k]) {
          for (j = 1; j <= n; j++) {
            sum = 0.0;
            for (i = k; i <= n; i++) sum += r[i][k] * qt[i][j];
            sum /= c[k];
            for (i = k; i <= n; i++) qt[i][j] -= sum * r[i][k];
          }
        }
      }
      for (i = 1; i <= n; i++) {
        r[i][i] = d[i];
        for (j = 1; j < i; j++) r[i][j] = 0.0;
      }
    } else {
      for (i = 1; i <= n; i++) s[i] = x[i] - xold[i];
      for (i = 1; i <= n; i++) {
        for (sum = 0.0, j = i; j <= n; j++) sum += r[i][j] * s[j];
        t[i] = sum;
      }
      skip = 1;
      for (i = 1; i <= n; i++) {
        for (sum = 0.0, j = 1; j <= n; j++) sum += qt[j][i] * t[j];
        w[i] = fvec[i] - fvcold[i] - sum;
        if (fabs(w[i]) >= EPS * (fabs(fvec[i]) + fabs(fvcold[i]))) {
          skip = 0;
        } else {
          w[i] = 0.0;
        }
      }
      if (!skip) {
        for (i = 1; i <= n; i++) {
          for (sum = 0.0, j = 1; j <= n; j++) sum += qt[i][j] * w[j];
          t[i] = sum;
        }
        for (den = 0.0, i = 1; i <= n; i++) den += DSQR(s[i]);
        for (i = 1; i <= n; i++) s[i] /= den;
        qrupdt(r, qt, n, t, s);
        for (i = 1; i <= n; i++) {
          if (r[i][i] == 0.0) nrerror("r singular in broydn : qrupdt");
          d[i] = r[i][i];
        }
      }
    }
    for (i = 1; i <= n; i++) {
      for (sum = 0.0, j = 1; j <= n; j++) sum += qt[i][j] * fvec[j];
      p[i] = -sum;
    }
    for (i = n; i >= 1; i--) {
      for (sum = 0.0, j = 1; j <= i; j++) sum -= r[j][i] * p[j];
      g[i] = sum;
    }
    for (i = 1; i <= n; i++) {
      xold[i] = x[i];
      fvcold[i] = fvec[i];
    }
    fold = fff;
    rsolv(r, n, d, p);
    lnsrch(n, xold, fold, g, p, x, &fff, stpmax, check);
    test = 0.0;
    for (i = 1; i <= n; i++)
      if (fabs(fvec[i]) > test) test = fabs(fvec[i]);
    if (test < TOLF) {
      *check = 0;
      FREERETURN
    }
    if (*check) {
      if (restrt) {
        FREERETURN
      } else {
        test = 0.0;
        den = DMAX(fff, 0.5 * n);
        for (i = 1; i <= n; i++) {
          temp = fabs(g[i]) * DMAX(fabs(x[i]), 1.0) / den;
          if (temp > test) {
            test = temp;
          }
        }
        if (test < TOLMIN) {
          FREERETURN
        } else {
          restrt = 1;
        }
      }
    } else {
      restrt = 0;
      test = 0.0;
      for (i = 1; i <= n; i++) {
        temp = (fabs(x[i] - xold[i])) / DMAX(fabs(x[i]), 1.0);
        if (temp > test) test = temp;
      }
      if (test < EPS) FREERETURN
    }
  }
  nrerror("MAXITS exceeded in broydn");
  FREERETURN
}

void Forces::rsolv(double **a, int n, double d[], double b[]) {
  int i, j;
  double sum;

  b[n] /= d[n];
  for (i = n - 1; i >= 1; i--) {
    for (sum = 0.0, j = i + 1; j <= n; j++) sum += a[i][j] * b[j];
    b[i] = (b[i] - sum) / d[i];
  }
}

void Forces::fdjac(int n, double x[], double fvec[], double **df) {
  int i, j;
  double h, temp, *ff;

  ff = dvector(1, n);
  for (j = 1; j <= n; j++) {
    temp = x[j];
    h = EPS * fabs(temp);
    if (h == 0.0) h = EPS;
    x[j] = temp + h;
    h = x[j] - temp;
    funcv(n, x, ff);
    x[j] = temp;
    for (i = 1; i <= n; i++) {
      df[i][j] = (ff[i] - fvec[i]) / h;
    }
  }
  free_dvector(ff, 1, n);
}

double Forces::f_min(double x[]) {
  int i;
  double sum;

  funcv(nn, x, fvec);
  for (sum = 0.0, i = 1; i <= nn; i++) sum += DSQR(fvec[i]);
  return 0.5 * sum;
}

void Forces::lnsrch(int n, double xold[], double fold, double g[], double p[],
                    double x[], double *f, double stpmax, int *check) {
  int i;
  double a, alam, alam2, alamin, b, disc, f2, rhs1, rhs2, slope, sum, temp,
      test, tmplam;

  *check = 0;
  for (sum = 0.0, i = 1; i <= n; i++) sum += p[i] * p[i];
  sum = sqrt(sum);
  if (sum > stpmax) {
    for (i = 1; i <= n; i++) p[i] *= stpmax / sum;
  }
  for (slope = 0.0, i = 1; i <= n; i++) slope += g[i] * p[i];
  if (slope >= 0.0) {
    nrerror("Roundoff problem in lnsrch.");
  }
  test = 0.0;
  for (i = 1; i <= n; i++) {
    temp = fabs(p[i]) / DMAX(fabs(xold[i]), 1.0);
    if (temp > test) {
      test = temp;
    }
  }
  alamin = TOLX / test;
  alam = 1.0;
  for (;;) {
    for (i = 1; i <= n; i++) x[i] = xold[i] + alam * p[i];
    *f = f_min(x);
    if (alam < alamin) {
      for (i = 1; i <= n; i++) x[i] = xold[i];
      *check = 1;
      return;
    } else if (*f <= fold + ALF * alam * slope) {
      return;
    } else {
      if (alam == 1.0) {
        tmplam = -slope / (2.0 * (*f - fold - slope));
      } else {
        rhs1 = *f - fold - alam * slope;
        rhs2 = f2 - fold - alam2 * slope;
        a = (rhs1 / (alam * alam) - rhs2 / (alam2 * alam2)) / (alam - alam2);
        b = (-alam2 * rhs1 / (alam * alam) + alam * rhs2 / (alam2 * alam2)) /
            (alam - alam2);
        if (a == 0.0) {
          tmplam = -slope / (2.0 * b);
        } else {
          disc = b * b - 3.0 * a * slope;
          if (disc < 0.0) {
            tmplam = 0.5 * alam;
          } else if (b <= 0.0) {
            tmplam = (-b + sqrt(disc)) / (3.0 * a);
          } else {
            tmplam = -slope / (b + sqrt(disc));
          }
        }
        if (tmplam > 0.5 * alam) {
          tmplam = 0.5 * alam;
        }
      }
    }
    alam2 = alam;
    f2 = *f;
    alam = DMAX(tmplam, 0.1 * alam);
  }
}

void Forces::qrdcmp(double **a, int n, double *c, double *d, int *sing) {
  int i, j, k;
  double scale, sigma, sum, tau;

  *sing = 0;
  for (k = 1; k < n; k++) {
    scale = 0.0;
    for (i = k; i <= n; i++) scale = DMAX(scale, fabs(a[i][k]));
    if (scale == 0.0) {
      *sing = 1;
      c[k] = d[k] = 0.0;
    } else {
      for (i = k; i <= n; i++) a[i][k] /= scale;
      for (sum = 0.0, i = k; i <= n; i++) sum += DSQR(a[i][k]);
      sigma = SIGN(sqrt(sum), a[k][k]);
      a[k][k] += sigma;
      c[k] = sigma * a[k][k];
      d[k] = -scale * sigma;
      for (j = k + 1; j <= n; j++) {
        for (sum = 0.0, i = k; i <= n; i++) sum += a[i][k] * a[i][j];
        tau = sum / c[k];
        for (i = k; i <= n; i++) a[i][j] -= tau * a[i][k];
      }
    }
  }
  d[n] = a[n][n];
  if (d[n] == 0.0) *sing = 1;
}

void Forces::qrupdt(double **r, double **qt, int n, double u[], double v[]) {
  int i, j, k;

  for (k = n; k >= 1; k--) {
    if (u[k]) break;
  }
  if (k < 1) k = 1;
  for (i = k - 1; i >= 1; i--) {
    rotate(r, qt, n, i, u[i], -u[i + 1]);
    if (u[i] == 0.0) {
      u[i] = fabs(u[i + 1]);
    } else if (fabs(u[i]) > fabs(u[i + 1])) {
      u[i] = fabs(u[i]) * sqrt(1.0 + DSQR(u[i + 1] / u[i]));
    } else {
      u[i] = fabs(u[i + 1]) * sqrt(1.0 + DSQR(u[i] / u[i + 1]));
    }
  }
  for (j = 1; j <= n; j++) r[1][j] += u[1] * v[j];
  for (i = 1; i < k; i++) rotate(r, qt, n, i, r[i][i], -r[i + 1][i]);
}

void Forces::rotate(double **r, double **qt, int n, int i, double a, double b) {
  int j;
  double c, fact, s, w, y;

  if (a == 0.0) {
    c = 0.0;
    s = (b >= 0.0 ? 1.0 : -1.0);
  } else if (fabs(a) > fabs(b)) {
    fact = b / a;
    c = SIGN(1.0 / sqrt(1.0 + (fact * fact)), a);
    s = fact * c;
  } else {
    fact = a / b;
    s = SIGN(1.0 / sqrt(1.0 + (fact * fact)), b);
    c = fact * s;
  }
  for (j = i; j <= n; j++) {
    y = r[i][j];
    w = r[i + 1][j];
    r[i][j] = c * y - s * w;
    r[i + 1][j] = s * y + c * w;
  }
  for (j = 1; j <= n; j++) {
    y = qt[i][j];
    w = qt[i + 1][j];
    qt[i][j] = c * y - s * w;
    qt[i + 1][j] = s * y + c * w;
  }
}

void Forces::set_reference_point(double refp) { xp = refp; }

arma::mat33 Forces::TMX(double ang) {
  arma::mat33 TM;

  TM(0, 0) = 1.0;
  TM(0, 1) = 0.0;
  TM(0, 2) = 0.0;
  TM(1, 0) = 0.0;
  TM(1, 1) = cos(ang);
  TM(1, 2) = sin(ang);
  TM(2, 0) = 0.0;
  TM(2, 1) = -sin(ang);
  TM(2, 2) = cos(ang);

  return TM;
}

arma::mat33 Forces::TMY(double ang) {
  arma::mat33 TM;

  TM(0, 0) = cos(ang);
  TM(0, 1) = 0.0;
  TM(0, 2) = -sin(ang);
  TM(1, 0) = 0.0;
  TM(1, 1) = 1.0;
  TM(1, 2) = 0.0;
  TM(2, 0) = sin(ang);
  TM(2, 1) = 0.0;
  TM(2, 2) = cos(ang);

  return TM;
}

arma::mat33 Forces::TMZ(double ang) {
  arma::mat33 TM;

  TM(0, 0) = cos(ang);
  TM(0, 1) = sin(ang);
  TM(0, 2) = 0.0;
  TM(1, 0) = -sin(ang);
  TM(1, 1) = cos(ang);
  TM(1, 2) = 0.0;
  TM(2, 0) = 0.0;
  TM(2, 1) = 0.0;
  TM(2, 2) = 1.0;

  return TM;
}

#undef MAXITS
#undef EPS
#undef TOLF
#undef TOLMIN
#undef TOLX
#undef STPMX
#undef FREERETURN
#undef NRANSI
