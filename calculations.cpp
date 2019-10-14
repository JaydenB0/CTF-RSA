#include "includes/calculations.hpp"

Calculate::Calculate(vs iN, vs iM, vs iP, vs iC, vs iQ, vs iD, vs iE, vs iPhi) {
  n = mpz_class(iN);
  m = mpz_class(iM);
  p = mpz_class(iP);
  c = mpz_class(iC);
  q = mpz_class(iQ);
  d = mpz_class(iD);
  e = mpz_class(iE);
  phi = mpz_class(iPhi);
}

// Calculate Euler's totient; given P, Q
void Calculate::Eulers_P_Q() {
  phi = (p-1) * (q-1);
}

// Calculate N; given P, Q
void Calculate::N_P_Q() {
  n = p * q;
}

// Calculate Q; given P, N
void Calculate::Q_P_N() {
  mpz_fdiv_q(q.get_mpz_t(), n.get_mpz_t(), p.get_mpz_t());
}

void Calculate::P_Q_N() {
  mpz_fdiv_q(p.get_mpz_t(), n.get_mpz_t(), q.get_mpz_t());
}
// Calculate C; given M, E, N
void Calculate::C_M_E_N(mt c, mt m, mt e, mt n) {}