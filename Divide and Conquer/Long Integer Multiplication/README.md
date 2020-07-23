### [Fast Long Integer Multiplication](https://github.com/ardasdasdas/algorithms-and-complexity/tree/master/Divide%20and%20Conquer/Long%20Integer%20Multiplication)
#### Long Integer Multiplication: 
The following little algorithm shows a bit more about the surprising applications of divide-and-conquer. The problem that we want to consider is how to perform arithmetic on
long integers, and multiplication in particular. The reason for doing arithmetic on long numbers stems
from cryptography. Most techniques for encryption are based on number-theoretic techniques. For
example, the character string to be encrypted is converted into a sequence of numbers, and encryption
keys are stored as long integers. Efficient encryption and decryption depends on being able to perform
arithmetic on long numbers, typically containing hundreds of digits.
Addition and subtraction on large numbers is relatively easy. If n is the number of digits, then these
algorithms run in Θ(n) time. But
the standard algorithm for multiplication runs in Θ(n2) time, which can be quite costly when lots of
long multiplications are needed.
This raises the question of whether there is a more efficient way to multiply two very large numbers. It
would seem surprising if there were, since for centuries people have used the same algorithm that we
all learn in grade school. In fact, we will see that it is possible.
#### Divide-and-Conquer Algorithm:
We know the basic grade-school algorithm for multiplication. We normally think of this algorithm as applying on a digit-by-digit basis, but if we partition an n digit number
into two “super digits” with roughly n/2 each into longer sequences, the same multiplication rule still
applies.
To avoid complicating things with floors and ceilings, let’s just assume that the number of digits n is
a power of 2. Let A and B be the two numbers to multiply. Let A[0] denote the least significant digit
and let A[n − 1] denote the most significant digit of A. Because of the way we write numbers, it is
more natural to think of the elements of A as being indexed in decreasing order from left to right as
A[n − 1..0] rather than the usual A[0..n − 1].
Let m = n/2. Let
w = A[n − 1..m] x = A[m − 1..0] and
y = B[n − 1..m] z = B[m − 1..0].

![DQ](https://user-images.githubusercontent.com/53192718/78257828-0fe15a00-7503-11ea-9551-c68c1e752c88.png)

If we think of w, x, y and z as n/2 digit numbers, we can express A and B as
A = w · 10^m + x
B = y · 10^m + z,
and their product is
mult(A, B) = mult(w, y)10^2m + (mult(w, z) + mult(x, y))10^m + mult(x, z).
The operation of multiplying by 10^m should be thought of as simply shifting the number over by
m positions to the right, and so is not really a multiplication. Observe that all the additions involve
numbers involving roughly n/2 digits, and so they take Θ(n) time each. Thus, we can express the
multiplication of two long integers as the result of 4 products on integers of roughly half the length of
the original, and a constant number of additions and shifts, each taking Θ(n) time. This suggests that
if we were to implement this algorithm, its running time would be given by the following recurrence

![bigo2](https://user-images.githubusercontent.com/53192718/78260194-5dab9180-7506-11ea-990d-157cae974cf0.png)

If we apply the Master Theorem, we see that a = 4, b = 2, k = 1, and a>bk, implying that Case
1 holds and the running time is Θ(nlg 4) = Θ(n2). Unfortunately, this is no better than the standard
algorithm.
#### Faster Divide-and-Conquer Algorithm:
Even though the above exercise appears to have gotten us nowhere,
it actually has given us an important insight. It shows that the critical element is the number of multiplications on numbers of size n/2. The number of additions (as long as it is a constant) does not affect
the running time. So, if we could find a way to arrive at the same result algebraically, but by trading
off multiplications in favor of additions, then we would have a more efficient algorithm. (Of course,
we cannot simulate multiplication through repeated additions, since the number of additions must be a
constant, independent of n.)
The key turns out to be a algebraic “trick”. The quantities that we need to compute are C = wy,
D = xz, and E = (wz + xy). Above, it took us four multiplications to compute these. However,
observe that if instead we compute the following quantities, we can get everything we want, using only
three multiplications (but with more additions and subtractions).
C = mult(w, y)
D = mult(x, z)
E = mult((w + x),(y + z)) − C − D = (wy + wz + xy + xz) − wy − xz = (wz + xy).
Finally we have
mult(A, B) = C · 10^2m + E · 10^m + D.
Altogether we perform 3 multiplications, 4 additions, and 2 subtractions all of numbers with n/2
digitis. We still need to shift the terms into their proper final positions. The additions, subtractions, and
shifts take Θ(n) time in total. So the total running time is given by the recurrence:

![bigo](https://user-images.githubusercontent.com/53192718/78260111-42408680-7506-11ea-9af3-d4e5cee3351b.png)

Now when we apply the Master Theorem, we have a = 3, b = 2 and k = 1, yielding T(n) ∈
Θ(nlg 3) ≈ Θ(n1.585).
Is this really an improvement? This algorithm carries a larger constant factor because of the overhead
of recursion and the additional arithmetic operations. But asymptotics says that if n is large enough,
then this algorithm will be superior. For example, if we assume that the clever algorithm has overheads
that are 5 times greater than the simple algorithm (e.g. 5n1.585 versus n2) then this algorithm beats the
simple algorithm for n ≥ 50. If the overhead was 10 times larger, then the crossover would occur for
n ≥ 260.
## References:
https://www.cs.umd.edu/users/meesh/cmsc351/mount/lectures/lect10-long-int-multiply.pdf
