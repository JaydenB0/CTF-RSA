#include "includes/calculations.hpp"

Calculate::Calculate(vs iN, vs iM, vs iP, vs iC, vs iQ, vs iD, vs iE, vs iPhi) {
  auto n = mpz_class(iN);
  auto m = mpz_class(iM);
  auto p = mpz_class(iP);
  auto c = mpz_class(iC);
  auto q = mpz_class(iQ);
  auto d = mpz_class(iD);
  auto e = mpz_class(iE);
  auto phi = mpz_class(iPhi);
}

// Calculate Euler's totient; given P, Q
void Calculate::Eulers_P_Q(mt phi, mt p, mt q) {
  mt copy_p, copy_q;
  mpz_inits(copy_p, copy_q, NULL);
  mpz_sub_ui(copy_p, p, 1);
  mpz_sub_ui(copy_q, q, 1);
  mpz_mul(phi, copy_p, copy_q);
  mpz_clears(copy_p, copy_q, NULL);
}

// Calculate N; given P, Q
void Calculate::N_P_Q() { mpz_mul(this->n, this->p, this->q); }

// Calculate Q; given P, N
void Calculate::Q_P_N(mt q, mt p, mt n) { mpz_div(q, n, p); }

// Calculate C; given M, E, N
void Calculate::C_M_E_N(mt c, mt m, mt e, mt n) { mpz_powm(c, m, e, n); }