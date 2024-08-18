// Si tenemos un array de longitud N y los valores van desde 1 <= Ai <= M

// A1 < A2 < A3 < A4 < A5 < ... < AN-1 < AN
// Combinaciones SIN Repeticiones M combinado N 

// A1 <= A2 <= A3 <= A4 <= A5 <= ... <= AN-1 <= AN
// Combinaciones CON Repeticiones M combinado N 

// Si A1 == 1 && (A[i] + 1 == A[i + 1] o A[i] == A[i + 1])
// 1 1 1
// 1 1 2
// 1 2 2
// 1 2 3
// Esto es igual a 2^(N - 1)