#include "includes/calculations.hpp"
using ll = mpz_t;

// Calculate Euler's totient; given P, Q
void Eulers_P_Q(ll phi, ll p, ll q) {
  ll copy_p, copy_q;
  mpz_inits(copy_p, copy_q, NULL);
  mpz_sub_ui(copy_p, p, 1);
  mpz_sub_ui(copy_q, q, 1);
  mpz_mul(phi, copy_p, copy_q);
  mpz_clears(copy_p, copy_q, NULL);
}

// Calculate N; given P, Q
void N_P_Q(ll n, ll p, ll q) { mpz_mul(n, p, q); }

// Calculate Q; given P, N
void Q_P_N(ll q, ll p, ll n) { mpz_div(q, n, p); }

// Calculate C; given M, E, N
void C_M_E_N(ll c, ll m, ll e, ll n) { mpz_powm(c, m, e, n); }