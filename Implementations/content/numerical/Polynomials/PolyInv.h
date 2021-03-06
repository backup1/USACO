/**
 * Description: computes $v^{-1}$ such that 
 	* $vv^{-1}\equiv 1\pmod{x^p}$
 * Time: O(N\log N)
 * Source: CF, http://people.csail.mit.edu/madhu/ST12/scribe/lect06.pdf
 * Verification: https://codeforces.com/contest/438/problem/E
 */

#include "FFT.h"

template<class T> vector<T> inv(vector<T> v, int p) { 
	v.rsz(p); vector<T> a = {T(1)/v[0]};
	for (int i = 1; i < p; i *= 2) {
		if (2*i > p) v.rsz(2*i);
		auto l = vector<T>(begin(v),begin(v)+i);
		auto r = vector<T>(begin(v)+i,begin(v)+2*i);
		auto c = mult(a,l); c = vector<T>(begin(c)+i,end(c));
		auto b = mult(a*T(-1),mult(a,r)+c); b.rsz(i);
		a.insert(end(a),all(b));
	}
	a.rsz(p); return a;
}