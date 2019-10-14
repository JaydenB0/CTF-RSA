#pragma once
#include <gmp.h>
#include <gmpxx.h>
#include <iostream>
using namespace std;

using vs = string;
using mt = mpz_class;
using ll = long long;
class Calculate {
public:
  mt m, p, c, q, n, d, e, phi;
  Calculate(vs iN, vs iM, vs iP, vs iC, vs iQ, vs iD, vs iE, vs iPhi);
  void Eulers_P_Q(mt phi, mt p, mt q);
  void N_P_Q();
  void Q_P_N(mt q, mt p, mt n);
  void C_M_E_N(mt c, mt m, mt e, mt n);
};