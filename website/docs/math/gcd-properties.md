---
sidebar_position: 1
---

# GCD Properties

- **Blueprint of Numbers:** The GCD (Greatest Common Divisor) of a set of numbers can be thought of as a blueprint of those numbers. If you keep adding the GCD, you can make all numbers that belong to that set.

- **Common Divisors:** Every common divisor of $a$ and $b$ is a divisor of $\gcd(a,b)$.

- **Linear Combination:** $\gcd(a,b)$, where both $a$ and $b$ are non-zero, can also be defined as the smallest positive integer $d$ which can be expressed as a linear combination of $a$ and $b$ in the form

  $$
  d = a \cdot p + b \cdot q
  $$

  where both $p$ and $q$ are integers.

- **GCD with Zero:** 

  $$
  \gcd(a, 0) = |a|, \text{ for } a \neq 0
  $$

  since any number is a divisor of 0, and the greatest divisor of $a$ is $|a|$.

- **Division Property:** If $a$ divides $b \cdot c$ and $\gcd(a,b) = d$, then 

  $$
  \frac{a}{d} \text{ divides } c
  $$

- **Scaling Property:** If $m$ is a non-negative integer, then 

  $$
  \gcd(m \cdot a, m \cdot b) = m \cdot \gcd(a, b)
  $$

  It also follows from this property that if $\gcd(a,b) = g$, then 

  $$
  \frac{a}{g} \text{ and } \frac{b}{g}
  $$
  should be coprime.

- **Translation Property:** If $m$ is any integer,

  $$
  \gcd(a,b) = \gcd(a + m \cdot b, b)
  $$

- **Euclidean Algorithm:** The GCD can be found using the Euclidean algorithm:

  $$
  \gcd(a, b) = \gcd(b, a \mod b)
  $$

- **Common Divisor Scaling:** If $m$ is a positive common divisor of $a$ and $b$, then 

  $$
  \gcd\left(\frac{a}{m}, \frac{b}{m}\right) = \frac{\gcd(a, b)}{m}
  $$

- **Multiplicative Function:** The GCD is a multiplicative function. That is, if $a_1$ and $a_2$ are coprime,

  $$
  \gcd(a_1 \cdot a_2, b) = \gcd(a_1, b) \cdot \gcd(a_2, b)
  $$

  In particular, recalling that GCD is a positive integer-valued function, we obtain that 

  $$
  \gcd(a, b \cdot c) = 1 \text{ if and only if } \gcd(a, b) = 1 \text{ and } \gcd(a, c) = 1.
  $$

  If the GCD is one, then they need not be coprime to distribute the GCD; moreover, each GCD individually should also be 1.

- **Commutative Property:** The GCD is a commutative function:

  $$
  \gcd(a, b) = \gcd(b, a)
  $$

- **Associative Property:** The GCD is an associative function:

  $$
  \gcd(a, \gcd(b, c)) = \gcd(\gcd(a, b), c)
  $$

  Thus,

  $$
  \gcd(a, b, c, \ldots)
  $$

  can be used to denote the GCD of multiple arguments.

- **Relation with LCM:** $\gcd(a, b)$ is closely related to the least common multiple $\operatorname{lcm}(a, b)$: we have

  $$
  \gcd(a, b) \cdot \operatorname{lcm}(a, b) = |a \cdot b|
  $$
- **the Subtraction Property of GCD or Substitution Lemma:** It forms one of the foundational principles of the Euclidean Algorithm, which leverages the idea of subtracting the smaller number from the larger one to reduce the problem of finding the GCD to smaller numbers.
In general terms, this property expresses that the GCD remains unchanged when multiples of one number are subtracted from the other. Thus, we can state:

  $$
  \gcd(a, b) = \gcd(a - b, b)
  $$

- **Distributivity Versions:** The following versions of distributivity hold true:

  $$
  \gcd(a, \operatorname{lcm}(b, c)) = \operatorname{lcm}(\gcd(a, b), \gcd(a, c))
  $$

  $$
  \operatorname{lcm}(a, \gcd(b, c)) = \gcd(\operatorname{lcm}(a, b), \operatorname{lcm}(a, c))
  $$

- **Prime Factorization:** If we have the unique prime factorizations of $a = p_1^{e_1} p_2^{e_2} \cdots p_m^{e_m}$ and $b = p_1^{f_1} p_2^{f_2} \cdots p_m^{f_m}$, where $e_i \geq 0$ and $f_i \geq 0$, then the GCD of $a$ and $b$ is:

  $$
  \gcd(a,b) = p_1^{\min(e_1,f_1)} p_2^{\min(e_2,f_2)} \cdots p_m^{\min(e_m,f_m)}
  $$

- **Cartesian Coordinate System Interpretation:** In a Cartesian coordinate system, $\gcd(a, b)$ can be interpreted as the number of segments between points with integral coordinates on the straight line segment joining the points $(0, 0)$ and $(a, b)$.

- **Euclidean Algorithm in Base $n$:** For non-negative integers $a$ and $b$, where $a$ and $b$ are not both zero, provable by considering the Euclidean algorithm in base $n$, it simply states that:

  $$
  \gcd(n^a - 1, n^b - 1) = n^{\gcd(a, b)} - 1
  $$

  If you want an informal proof, think of numbers in base 2. We are calculating GCDs of numbers which contain all continuous 1s in their binary representations. For example: 001111 and 000011; their GCD can be the greatest common length, which in this case is 2. Thus, the GCD becomes 000011. Think of numbers in terms of length; maybe you get the idea.

- **Euler's Totient Function Identity:** An identity involving Euler's totient function:

  $$
  \gcd(a,b) = \sum \phi(k)
  $$

  where $k$ are all common divisors of $a$ and $b$.

