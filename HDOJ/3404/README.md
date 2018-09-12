# Switch lights

Nim 积, 裸题.

SG(n,m) = mex(SG(i,j) xor SG(i,m) xor SG(n,j)
	for i <= n && j <= m && (i != n || j != m))

复杂度 log^2.
