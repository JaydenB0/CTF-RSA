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
  if (p != 0)
    mpz_fdiv_q(q.get_mpz_t(), n.get_mpz_t(), p.get_mpz_t());
}

// Calculate P; given Q, N
void Calculate::P_Q_N() {
  if (q != 0 )
    mpz_fdiv_q(p.get_mpz_t(), n.get_mpz_t(), q.get_mpz_t());
}
// Calculate C; given M, E, N
void Calculate::C_M_E_N() {
  mpz_powm(c.get_mpz_t(), m.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
}

// Calculate M; given C, D, N;
void Calculate::M_C_D_N() {
  mpz_powm_sec(m.get_mpz_t(), c.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t());
}

// Calculate D; given E, phi
void Calculate::D_E_Phi(){
  mpz_invert(d.get_mpz_t(), e.get_mpz_t(), phi.get_mpz_t());
}
// QUADRATIC SIEVE //
