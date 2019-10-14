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
void Calculate::Eulers_P_Q(mt phi, mt p, mt q) {
}

// Calculate N; given P, Q
void Calculate::N_P_Q() {
  n = p * q;
}

// Calculate Q; given P, N
void Calculate::Q_P_N(mt q, mt p, mt n) {}

// Calculate C; given M, E, N
void Calculate::C_M_E_N(mt c, mt m, mt e, mt n) {}