---
generator: pandoc
title: CS 341 Term Notes
...

Preface {#sub:preface .unnumbered}
-------

This course was taken in Winter 2013 at the University of Waterloo under
[Timothy Chan](https://cs.uwaterloo.ca/~tmchan/).

These notes come with no guarantee of correctness, veracity, nor
semblance of course materials. Go to class, your profs are right
experts.

Compiled with love by:

-   Shale Craig - [http://shalecraig.com](http://shalecraig.com)

Please submit corrections, omissions, and requests for change to
[http://github.com/shalecraig/Notes](http://github.com/shalecraig/Notes)

Introduction
============

Bentley’s Problem
-----------------

Find the consecutive sub-array
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") of a given
array ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") with the
maximal value.

i.e: ![A = [1, 2, -3, 4, -4,
0]](http://chart.apis.google.com/chart?cht=tx&chl=A%20%3D%20%5B1%2C%202%2C%20-3%2C%204%2C%20-4%2C%200%5D "A = [1, 2, -3, 4, -4, 0]"),
![B = [1, 2, -3,
4]](http://chart.apis.google.com/chart?cht=tx&chl=B%20%3D%20%5B1%2C%202%2C%20-3%2C%204%5D "B = [1, 2, -3, 4]")

![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")-time
solution exists:

                max_subarray(A):
                    max_ending_here = max_so_far = 0
                    for x in A:
                        max_ending_here = max(0, max_ending_here + x)
                        max_so_far = max(max_so_far, max_ending_here)
                    return max_so_far
            

Basically, we keep track of the maximal subarray ending “here”
(including the empty array), and then compare that to the max so far.

The 3SUM problem
----------------

Given a set of integers
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") and an integer
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k"), find
![3](http://chart.apis.google.com/chart?cht=tx&chl=3 "3") different
numbers in ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A")
that sum to ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k").

i.e. ![A = [1, 2, -3, 4, -4,
0]](http://chart.apis.google.com/chart?cht=tx&chl=A%20%3D%20%5B1%2C%202%2C%20-3%2C%204%2C%20-4%2C%200%5D "A = [1, 2, -3, 4, -4, 0]"),
![k =
3](http://chart.apis.google.com/chart?cht=tx&chl=k%20%3D%203 "k = 3").
![2 + 4 - 3 =
k](http://chart.apis.google.com/chart?cht=tx&chl=2%20%2B%204%20-%203%20%3D%20k "2 + 4 - 3 = k")

![O(n\^2)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E2%29 "O(n^2)")-time
solution exists:

                sort(A);
                for i=0 to n-3 do
                    a = A[i];
                    j = i+1;
                    l = n-1;
                    while (j<l) do
                        b = A[j];
                        c = A[l];
                        if (a+b+c == k) then
                            output a, b, c;
                            exit;
                        else if (a+b+c > k) then
                            l = l - 1;
                        else
                            j = j + 1;
                        end
                    end
                end
            

Basically, we sort values in
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A"), pick one
value of ![a](http://chart.apis.google.com/chart?cht=tx&chl=a "a"), then
try to find values of
![A[j]](http://chart.apis.google.com/chart?cht=tx&chl=A%5Bj%5D "A[j]")
and
![A[l]](http://chart.apis.google.com/chart?cht=tx&chl=A%5Bl%5D "A[l]")
that equal ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k"). We
change the values of
![l](http://chart.apis.google.com/chart?cht=tx&chl=l "l") and
![j](http://chart.apis.google.com/chart?cht=tx&chl=j "j") according to
the value of the sum compared to
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k").

Math review
-----------

### Asymptotic notation

We use ![O](http://chart.apis.google.com/chart?cht=tx&chl=O "O"),
![o](http://chart.apis.google.com/chart?cht=tx&chl=o "o"),
![\\Omega](http://chart.apis.google.com/chart?cht=tx&chl=%5COmega "\Omega"),
![\\omega](http://chart.apis.google.com/chart?cht=tx&chl=%5Comega "\omega"),
and
![\\Theta](http://chart.apis.google.com/chart?cht=tx&chl=%5CTheta "\Theta")
to denote the runtimes of different algorithms as the input sizes tend
to
![\\infty](http://chart.apis.google.com/chart?cht=tx&chl=%5Cinfty "\infty").
This isn’t perfect for talking about small
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"), but
performing well for small
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is less an
algorithms task and more an algebra task.

Here’s a table:

[h]

| l || l | Symbol & Condition\
![f(n) \\in
O(g(n))](http://chart.apis.google.com/chart?cht=tx&chl=f%28n%29%20%5Cin%20O%28g%28n%29%29 "f(n) \in O(g(n))")
& ![|f(n)| \\le k
g(n)](http://chart.apis.google.com/chart?cht=tx&chl=%7Cf%28n%29%7C%20%5Cle%20k%20g%28n%29 "|f(n)| \le k g(n)")
for some positive
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")\
![f(n) \\in
\\Omega(g(n))](http://chart.apis.google.com/chart?cht=tx&chl=f%28n%29%20%5Cin%20%5COmega%28g%28n%29%29 "f(n) \in \Omega(g(n))")
& ![|f(n)| \\ge k
g(n)](http://chart.apis.google.com/chart?cht=tx&chl=%7Cf%28n%29%7C%20%5Cge%20k%20g%28n%29 "|f(n)| \ge k g(n)")
for some positive
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")\
![f(n) \\in
\\Theta(g(n))](http://chart.apis.google.com/chart?cht=tx&chl=f%28n%29%20%5Cin%20%5CTheta%28g%28n%29%29 "f(n) \in \Theta(g(n))")
& ![k\_1 g(n) \\ge |f(n)| \\ge k\_2
g(n)](http://chart.apis.google.com/chart?cht=tx&chl=k_1%20g%28n%29%20%5Cge%20%7Cf%28n%29%7C%20%5Cge%20k_2%20g%28n%29 "k_1 g(n) \ge |f(n)| \ge k_2 g(n)")
for some positive ![k\_1,
k\_2](http://chart.apis.google.com/chart?cht=tx&chl=k_1%2C%20k_2 "k_1, k_2")\
![f(n) \\in
o(g(n))](http://chart.apis.google.com/chart?cht=tx&chl=f%28n%29%20%5Cin%20o%28g%28n%29%29 "f(n) \in o(g(n))")
& ![|f(n)| \\le \\epsilon g(n)
](http://chart.apis.google.com/chart?cht=tx&chl=%7Cf%28n%29%7C%20%5Cle%20%5Cepsilon%20g%28n%29%20 "|f(n)| \le \epsilon g(n) ")
for all positive
![\\epsilon](http://chart.apis.google.com/chart?cht=tx&chl=%5Cepsilon "\epsilon")\
![f(n) \\in \\omega
(g(n))](http://chart.apis.google.com/chart?cht=tx&chl=f%28n%29%20%5Cin%20%5Comega%20%28g%28n%29%29 "f(n) \in \omega (g(n))")
& ![|f(n)| \\ge \\epsilon g(n)
](http://chart.apis.google.com/chart?cht=tx&chl=%7Cf%28n%29%7C%20%5Cge%20%5Cepsilon%20g%28n%29%20 "|f(n)| \ge \epsilon g(n) ")
for all positive
![\\epsilon](http://chart.apis.google.com/chart?cht=tx&chl=%5Cepsilon "\epsilon")\

Summations
----------

Summations are useful, and we only use a few in this course.

Here they are:

\
![\\begin{aligned} \\sum\_{i=0}\^n i &= \\frac{n\^2 + n}{2} \\\\
\\sum\_{i=0}\^n i\^2 &= \\frac{2n\^3 + 3n\^2 + n}{2} \\\\
\\sum\_{i=0}\^n a\^i &= \\frac{1 - a\^{n-1}}{1-a} \\\\ \\sum\_{i=0}\^n
\\frac{1}{n} &= O(\\log n + \\gamma)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Csum_%7Bi%3D0%7D%5En%20i%20%26%3D%20%5Cfrac%7Bn%5E2%20%2B%20n%7D%7B2%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Csum_%7Bi%3D0%7D%5En%20i%5E2%20%26%3D%20%5Cfrac%7B2n%5E3%20%2B%203n%5E2%20%2B%20n%7D%7B2%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Csum_%7Bi%3D0%7D%5En%20a%5Ei%20%26%3D%20%5Cfrac%7B1%20-%20a%5E%7Bn-1%7D%7D%7B1-a%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Csum_%7Bi%3D0%7D%5En%20%5Cfrac%7B1%7D%7Bn%7D%20%26%3D%20O%28%5Clog%20n%20%2B%20%5Cgamma%29%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            \sum_{i=0}^n i &= \frac{n^2 + n}{2} \\
            \sum_{i=0}^n i^2 &= \frac{2n^3 + 3n^2 + n}{2} \\
            \sum_{i=0}^n a^i &= \frac{1 - a^{n-1}}{1-a} \\
            \sum_{i=0}^n \frac{1}{n} &= O(\log n + \gamma)
        \end{aligned}")\

Note: I’m not sure this is complete.

Recurrences [Sec 4.4,4.5,4.3]
-----------------------------

Recurrence relationships are often found in recursive code. We probably
want to solve these to see the asymptotic behaviour of our algorithm.

### The Recursion Tree Method

The basic idea of this approach is we break down values as they go down
to child nodes, and determine a function for the number of child nodes
at each level, and another the cost of each node. By summing these
together, we get the overall cost of the function with respect to
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n").

i.e.

\
![\\begin{aligned} f(n) &= \\left\\{ \\begin{array}{lr} 12
f\\left(\\frac{n}{12}\\right) + 14n & n \\ge 100 \\\\ n &
\\text{otherwise} \\end{array} \\right.
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28n%29%20%26%3D%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%2012%20f%5Cleft%28%5Cfrac%7Bn%7D%7B12%7D%5Cright%29%20%2B%2014n%20%26%20n%20%5Cge%20100%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20n%20%26%20%5Ctext%7Botherwise%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                f(n) &= \left\{
                    \begin{array}{lr}
                        12 f\left(\frac{n}{12}\right) + 14n & n \ge 100 \\
                        n & \text{otherwise}
                    \end{array}
                \right.
            \end{aligned}")\

(Drawing not provided - if you supply one, I’ll add it.)

By drawing this out, we see:

1.  In level ![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i"),
    there are
    ![12\^i](http://chart.apis.google.com/chart?cht=tx&chl=12%5Ei "12^i")
    nodes.

2.  In level ![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i"),
    our cost is ![14
    \\frac{n}{12\^i}](http://chart.apis.google.com/chart?cht=tx&chl=14%20%5Cfrac%7Bn%7D%7B12%5Ei%7D "14 \frac{n}{12^i}")
    per node.

3.  The tree height is (approximately)
    ![\\log\_{12}n](http://chart.apis.google.com/chart?cht=tx&chl=%5Clog_%7B12%7Dn "\log_{12}n").

Based on this, we get the summation:

\
![\\begin{aligned} f(n) &= \\sum\_{i=0}\^{\\log\_{12}n} (12\^i)(14
\\frac{n}{12\^i}) \\\\ &= \\sum\_{i=0}\^{\\log\_{12}n} 14 n \\\\ &= 14 n
\\log\_{12}n
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28n%29%20%26%3D%20%5Csum_%7Bi%3D0%7D%5E%7B%5Clog_%7B12%7Dn%7D%20%2812%5Ei%29%2814%20%5Cfrac%7Bn%7D%7B12%5Ei%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_%7Bi%3D0%7D%5E%7B%5Clog_%7B12%7Dn%7D%2014%20n%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%2014%20n%20%5Clog_%7B12%7Dn%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                f(n) &= \sum_{i=0}^{\log_{12}n} (12^i)(14 \frac{n}{12^i}) \\
                &= \sum_{i=0}^{\log_{12}n} 14 n \\
                &= 14 n \log_{12}n
            \end{aligned}")\

i.e we have ![f(n) = 14 n
\\log\_{12}n](http://chart.apis.google.com/chart?cht=tx&chl=f%28n%29%20%3D%2014%20n%20%5Clog_%7B12%7Dn "f(n) = 14 n \log_{12}n")

In this example I don’t count the leaf nodes, but probably should.

TODO: evaluate the leaf nodes.

### Master Method

The master method is often referred to as a “cookbook” or a “lookup”
based method. We basically know that
![f(n)](http://chart.apis.google.com/chart?cht=tx&chl=f%28n%29 "f(n)")
is of a certain form, we can substitute it into the answer.

Algorithms expressed in the form of ![T(n) = a T\\left( \\frac{n}{b}
\\right) +
f(n)](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%3D%20a%20T%5Cleft%28%20%5Cfrac%7Bn%7D%7Bb%7D%20%5Cright%29%20%2B%20f%28n%29 "T(n) = a T\left( \frac{n}{b} \right) + f(n)")
can be solved using the master theorem. We didn’t talk about other forms
in class.

We define ![c =
\\log\_b{a}](http://chart.apis.google.com/chart?cht=tx&chl=c%20%3D%20%5Clog_b%7Ba%7D "c = \log_b{a}"),
and require that ![\\epsilon \>
0](http://chart.apis.google.com/chart?cht=tx&chl=%5Cepsilon%20%3E%200 "\epsilon > 0").

There are three cases that we can apply it in:

1.  If ![f(n) \\in
    O(n\^{c-\\epsilon})](http://chart.apis.google.com/chart?cht=tx&chl=f%28n%29%20%5Cin%20O%28n%5E%7Bc-%5Cepsilon%7D%29 "f(n) \in O(n^{c-\epsilon})"),
    it follows that ![T(n) \\in
    \\Theta(n\^c)](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%5Cin%20%5CTheta%28n%5Ec%29 "T(n) \in \Theta(n^c)").

2.  If ![f(n) \\in \\Theta(n\^c \\log\^k
    n)](http://chart.apis.google.com/chart?cht=tx&chl=f%28n%29%20%5Cin%20%5CTheta%28n%5Ec%20%5Clog%5Ek%20n%29 "f(n) \in \Theta(n^c \log^k n)")
    for ![k \\ge
    0](http://chart.apis.google.com/chart?cht=tx&chl=k%20%5Cge%200 "k \ge 0"),
    it follows that ![T(n) \\in \\Theta(n\^c
    \\log\^{k+1}n)](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%5Cin%20%5CTheta%28n%5Ec%20%5Clog%5E%7Bk%2B1%7Dn%29 "T(n) \in \Theta(n^c \log^{k+1}n)").

3.  If ![f(n) \\in
    \\Omega(n\^{c+\\epsilon})](http://chart.apis.google.com/chart?cht=tx&chl=f%28n%29%20%5Cin%20%5COmega%28n%5E%7Bc%2B%5Cepsilon%7D%29 "f(n) \in \Omega(n^{c+\epsilon})"),
    it follows that ![T(n) \\in
    \\Theta(n\^c)](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%5Cin%20%5CTheta%28n%5Ec%29 "T(n) \in \Theta(n^c)").

### Guess-And-Check Method

In this method, we guess a recursion and substitute into the recurrence
to check for veracity. If our guess is incorrect we start again, using
what we learned to re-build our guess.

i.e. Guess ![T(n) = c\_1 n +
c\_2](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%3D%20c_1%20n%20%2B%20c_2 "T(n) = c_1 n + c_2"):

\
![\\begin{aligned} T(n) &= T(n/2) + T(n/4) + T(n/8) + n \\\\ T(n) &=
c\_1 n + c\_2 \\\\ T(n/2) + T(n/4) + T(n/8) + n &= c\_1
n\\frac{4+2+1}{8} + 3 c\_2 + n\\\\ &= \\frac{7 n c\_1}{8} + 3 c\_2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%28n%29%20%26%3D%20T%28n%2F2%29%20%2B%20T%28n%2F4%29%20%2B%20T%28n%2F8%29%20%2B%20n%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%28n%29%20%26%3D%20c_1%20n%20%2B%20c_2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%28n%2F2%29%20%2B%20T%28n%2F4%29%20%2B%20T%28n%2F8%29%20%2B%20n%20%26%3D%20c_1%20n%5Cfrac%7B4%2B2%2B1%7D%7B8%7D%20%2B%203%20c_2%20%2B%20n%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B7%20n%20c_1%7D%7B8%7D%20%2B%203%20c_2%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                T(n) &= T(n/2) + T(n/4) + T(n/8) + n \\
                T(n) &= c_1 n + c_2 \\
                T(n/2) + T(n/4) + T(n/8) + n &= c_1 n\frac{4+2+1}{8} + 3 c_2 + n\\
                &= \frac{7 n c_1}{8} + 3 c_2
            \end{aligned}")\

From this, we get that ![\\frac{7c\_1}{8} + 1 =
c\_1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B7c_1%7D%7B8%7D%20%2B%201%20%3D%20c_1 "\frac{7c_1}{8} + 1 = c_1"),
so ![c\_1 =
-8](http://chart.apis.google.com/chart?cht=tx&chl=c_1%20%3D%20-8 "c_1 = -8").
Similarily, ![c\_2 =
0](http://chart.apis.google.com/chart?cht=tx&chl=c_2%20%3D%200 "c_2 = 0").

Divide and Conquer
==================

Divide and conquer algorithms break up problems into smaller sections
that they solve recursively. They can take advantage of the fact they’re
solving smaller problems to provide a better runtime than naive
solutions.

They generally consist of three steps:

1.  Break up input to smaller parts.

2.  Solve each part.

3.  Merge the solutions together.

The Maxima Problem
------------------

TODO: It was this problem.

Given a set of points
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P"), find the set
of points ![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M") that
are a maxima of
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P"). A maximal
point ![p \\in
M](http://chart.apis.google.com/chart?cht=tx&chl=p%20%5Cin%20M "p \in M")
is one where there is no other point
![r](http://chart.apis.google.com/chart?cht=tx&chl=r "r") in
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") where ![r.x \>
p.x](http://chart.apis.google.com/chart?cht=tx&chl=r.x%20%3E%20p.x "r.x > p.x")
and ![r.y \>
p.y](http://chart.apis.google.com/chart?cht=tx&chl=r.y%20%3E%20p.y "r.y > p.y").

Conceptually, we can break the set of points
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") into
![P\_1](http://chart.apis.google.com/chart?cht=tx&chl=P_1 "P_1") and
![P\_2](http://chart.apis.google.com/chart?cht=tx&chl=P_2 "P_2"), each
roughly half the size of the other. Then we can solve to get
![M\_1](http://chart.apis.google.com/chart?cht=tx&chl=M_1 "M_1") and
![M\_2](http://chart.apis.google.com/chart?cht=tx&chl=M_2 "M_2"). We can
merge ![M\_1](http://chart.apis.google.com/chart?cht=tx&chl=M_1 "M_1")
and ![M\_2](http://chart.apis.google.com/chart?cht=tx&chl=M_2 "M_2")
together, and return that.

We need to remember to consider the base case in writing the solution.

                def maxima(P):
                    if len(P) <= 2:
                        return P
                    sortByX(P)
                    ->P1 is the 'top-left half'
                    P1 = P[0 : len(P)/2]
                    P2 = P[len(P)/2+1 : -1]
                    M1 = maxima(P1)
                    M2 = maxima(P2)
                    i1 = 0
                    firstM2 = M2[0]
                    M = []
                    while (M1[i1].y > firstM2.y):
                        M.addOne(M1[i1])
                    M.addAll(M2)
                    return M
            

This algorithm takes ![T(n) = 2T(n/2) + n\\log
n](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%3D%202T%28n%2F2%29%20%2B%20n%5Clog%20n "T(n) = 2T(n/2) + n\log n")
worst-case time. We can use the master method to solve this.

By pre-sorting all the points instead of doing it in every reduction, we
only need to do it once, so we can say that ![T(n) = 2T(n/2) +
n](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%3D%202T%28n%2F2%29%20%2B%20n "T(n) = 2T(n/2) + n").

![a =
2](http://chart.apis.google.com/chart?cht=tx&chl=a%20%3D%202 "a = 2"),
![b =
2](http://chart.apis.google.com/chart?cht=tx&chl=b%20%3D%202 "b = 2"),
![f(n) =
n](http://chart.apis.google.com/chart?cht=tx&chl=f%28n%29%20%3D%20n "f(n) = n"),
![c = \\log\_b{a} =
1](http://chart.apis.google.com/chart?cht=tx&chl=c%20%3D%20%5Clog_b%7Ba%7D%20%3D%201 "c = \log_b{a} = 1").

We know ![f(n) \\in \\Theta(n\^1 \\log\^0
n)](http://chart.apis.google.com/chart?cht=tx&chl=f%28n%29%20%5Cin%20%5CTheta%28n%5E1%20%5Clog%5E0%20n%29 "f(n) \in \Theta(n^1 \log^0 n)"),
so rule 2 must apply for ![k =
0](http://chart.apis.google.com/chart?cht=tx&chl=k%20%3D%200 "k = 0").
Thus, ![T(n) \\in \\Theta(n\^1 \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%5Cin%20%5CTheta%28n%5E1%20%5Clog%20n%29 "T(n) \in \Theta(n^1 \log n)").

The Closest Pair Problem (Shamos’ Algorithm)
--------------------------------------------

Given a set ![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") of
points, find the distance betwwen the closest pair of points
![{\\ensuremath{\\left \\langle p, q \\right \\rangle
}}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20p%2C%20q%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle p, q \right \rangle }}")
in ![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P").

Conceptually, we can solve this problem using a similar (but different!)
approach than before. We will split the points into left and right
halves and solve them independently. We will then merge them, and only
return the best answer between the two. All that remains is to evaluate
pairs of points that cross the separating boundary between the two
halves, which can be done by creating a “moving elevator” that goes up
to iterate through all points that are possibly valid inside this
elevator.

                def getClosestPair(Px, Py):
                    if len(P) == 2
                        return dist(P[0], P[1])
                    Pxl = Px[0 : len(Px)/2]
                    Pxr = Px[len(Px)/2+1 : -1]
                    Pyl = Py[p is in Pxl]
                    Pyl = Py[p is in Pyl]
                    bestLeft = getClosestPair(Pxl, Pyl)
                    bestRight = getClosestPair(Pxr, Pyr)
                    best = min(bestLeft, bestRight)
                    windowRight = Pl[-1].x + best
                    windowLeft = Pr[0].x - best
                    window = Pyl[p.x > windowLeft] + Pyr[p.x < windowRight]
                    for (i=0...len(window)-1):
                        k = i+1
                        while k < len(window)-1 and window[k].y-window[i].y < best:
                            if dist(window[k], window[i]) < best:
                                best = dist(window[k], window[i])
                            k = k+1
                    return best
            

We take ![P\_x](http://chart.apis.google.com/chart?cht=tx&chl=P_x "P_x")
and ![P\_y](http://chart.apis.google.com/chart?cht=tx&chl=P_y "P_y") as
input (points sorted according to x and y). We can express the runtime
of this algorithm as ![T(n) = 2T(n/2) + 6n \\log(n) +
3](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%3D%202T%28n%2F2%29%20%2B%206n%20%5Clog%28n%29%20%2B%203 "T(n) = 2T(n/2) + 6n \log(n) + 3").
Using the master method, we can solve the recurrence as ![T(n) =
\\Theta(n \\log\^2
n)](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%3D%20%5CTheta%28n%20%5Clog%5E2%20n%29 "T(n) = \Theta(n \log^2 n)").

Multiplication of Large Numbers (Karatsuba and Ofman’s Algorithm)
-----------------------------------------------------------------

This can be found at [KT, Sec 5.5 or BB, Sec 7.1]

We want to multiply integers
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") and
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") (expressed as
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") bits) more
efficiently than the grade-school “multiply-everything” approach.

Conceptually, Karatsuba used a shortcut where instead of multiplying
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") with
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") directly, he
performed three multiplications of smaller size, which is a bit faster.
If you use the algorithm recursively, it’s asymptotically faster.

Given integers ![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x")
and ![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y") we want to
compute ![xy](http://chart.apis.google.com/chart?cht=tx&chl=xy "xy").
Choose a base ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B"),
and ![m =
\\log(x)/2](http://chart.apis.google.com/chart?cht=tx&chl=m%20%3D%20%5Clog%28x%29%2F2 "m = \log(x)/2")

\
![\\begin{aligned} x &= x\_1 B\^m + x\_2 \\\\ y &= y\_1 B\^m + y\_2 \\\\
xy &= z\_2 B\^{2m} + z\_0 + z\_1 B\^{m} \\\\ z\_2 &= x\_1 y\_1 \\\\ z\_0
&= x\_0 y\_0 \\\\ z\_1 &= x\_1 y\_0 + x\_0 y\_1 \\\\ &= (x\_1 +
x\_0)(y\_1 + y\_0) - z\_2 - z\_0
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20x%20%26%3D%20x_1%20B%5Em%20%2B%20x_2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20y%20%26%3D%20y_1%20B%5Em%20%2B%20y_2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20xy%20%26%3D%20z_2%20B%5E%7B2m%7D%20%2B%20z_0%20%2B%20z_1%20B%5E%7Bm%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20z_2%20%26%3D%20x_1%20y_1%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20z_0%20%26%3D%20x_0%20y_0%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20z_1%20%26%3D%20x_1%20y_0%20%2B%20x_0%20y_1%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%28x_1%20%2B%20x_0%29%28y_1%20%2B%20y_0%29%20-%20z_2%20-%20z_0%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            x &= x_1 B^m + x_2 \\
            y &= y_1 B^m + y_2 \\
            xy &= z_2 B^{2m} + z_0 + z_1 B^{m} \\
            z_2 &= x_1 y_1 \\
            z_0 &= x_0 y_0 \\
            z_1 &= x_1 y_0 + x_0 y_1 \\
            &= (x_1 + x_0)(y_1 + y_0) - z_2 - z_0
        \end{aligned}")\

It takes ![T(n) = 3 T(n/2) + cn +
d](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%3D%203%20T%28n%2F2%29%20%2B%20cn%20%2B%20d "T(n) = 3 T(n/2) + cn + d")
(![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c") and
![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d") are constants)
to calculate the value of
![AB](http://chart.apis.google.com/chart?cht=tx&chl=AB "AB"). Solved by
the master theorem, this becomes ![T(n) \\in \\Theta(n\^{\\log\_2{3}})
\\approx
\\Theta(n\^1.58)](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%5Cin%20%5CTheta%28n%5E%7B%5Clog_2%7B3%7D%7D%29%20%5Capprox%20%5CTheta%28n%5E1.58%29 "T(n) \in \Theta(n^{\log_2{3}}) \approx \Theta(n^1.58)").

Matrix Multiplication (Strassen’s Algorithm)
--------------------------------------------

This can be found at [CLRS, Sec 4.2]

Given matrices ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A")
and ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B"), find the
product ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") of
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") and
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B").

Conceptually, Strassen realized that (like Karatsuba) you can do these
multiplications in fewer operations that what is explicitly obvious.

\
![\\begin{aligned} A &= \\begin{bmatrix} A\_{1,1} & A\_{1,2} \\\\
A\_{2,1} & A\_{2,2} \\end{bmatrix} \\\\ B &= \\begin{bmatrix} B\_{1,1} &
B\_{1,2} \\\\ B\_{2,1} & B\_{2,2} \\end{bmatrix} \\\\ C &=
\\begin{bmatrix} C\_{1,1} & C\_{1,2} \\\\ C\_{2,1} & C\_{2,2}
\\end{bmatrix} \\\\ C\_{1,1} &= A\_{1,1}B\_{1,1} + A\_{1,2}B\_{2,1} \\\\
C\_{1,2} &= A\_{1,1}B\_{1,2} + A\_{1,2}B\_{2,2} \\\\ C\_{2,1} &=
A\_{2,1}B\_{1,1} + A\_{2,2}B\_{2,1} \\\\ C\_{2,2} &= A\_{2,1}B\_{1,2} +
A\_{2,2}B\_{2,2}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20A%20%26%3D%20%5Cbegin%7Bbmatrix%7D%20A_%7B1%2C1%7D%20%26%20A_%7B1%2C2%7D%20%5C%5C%20A_%7B2%2C1%7D%20%26%20A_%7B2%2C2%7D%20%5Cend%7Bbmatrix%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20B%20%26%3D%20%5Cbegin%7Bbmatrix%7D%20B_%7B1%2C1%7D%20%26%20B_%7B1%2C2%7D%20%5C%5C%20B_%7B2%2C1%7D%20%26%20B_%7B2%2C2%7D%20%5Cend%7Bbmatrix%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20C%20%26%3D%20%5Cbegin%7Bbmatrix%7D%20C_%7B1%2C1%7D%20%26%20C_%7B1%2C2%7D%20%5C%5C%20C_%7B2%2C1%7D%20%26%20C_%7B2%2C2%7D%20%5Cend%7Bbmatrix%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20C_%7B1%2C1%7D%20%26%3D%20A_%7B1%2C1%7DB_%7B1%2C1%7D%20%2B%20A_%7B1%2C2%7DB_%7B2%2C1%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20C_%7B1%2C2%7D%20%26%3D%20A_%7B1%2C1%7DB_%7B1%2C2%7D%20%2B%20A_%7B1%2C2%7DB_%7B2%2C2%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20C_%7B2%2C1%7D%20%26%3D%20A_%7B2%2C1%7DB_%7B1%2C1%7D%20%2B%20A_%7B2%2C2%7DB_%7B2%2C1%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20C_%7B2%2C2%7D%20%26%3D%20A_%7B2%2C1%7DB_%7B1%2C2%7D%20%2B%20A_%7B2%2C2%7DB_%7B2%2C2%7D%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            A &= \begin{bmatrix} A_{1,1} & A_{1,2} \\ A_{2,1} & A_{2,2} \end{bmatrix} \\
            B &= \begin{bmatrix} B_{1,1} & B_{1,2} \\ B_{2,1} & B_{2,2} \end{bmatrix} \\
            C &= \begin{bmatrix} C_{1,1} & C_{1,2} \\ C_{2,1} & C_{2,2} \end{bmatrix} \\
            C_{1,1} &= A_{1,1}B_{1,1} + A_{1,2}B_{2,1} \\
            C_{1,2} &= A_{1,1}B_{1,2} + A_{1,2}B_{2,2} \\
            C_{2,1} &= A_{2,1}B_{1,1} + A_{2,2}B_{2,1} \\
            C_{2,2} &= A_{2,1}B_{1,2} + A_{2,2}B_{2,2}
        \end{aligned}")\

If we define an intermediate matrix
![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M"), we can
calculate ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") in 7
multiplications instead of the 8 above.

\
![\\begin{aligned} M\_1 &= (A\_{1,1} + A\_{2,2})(B\_{1,1} + B\_{2,2})
\\\\ M\_2 &= (A\_{2,1} + A\_{2,2})B\_{1,1} \\\\ M\_3 &=
A\_{1,1}(B\_{1,2} - B\_{2,2}) \\\\ M\_4 &= A\_{2,2}(B\_{2,1} - B\_{1,1})
\\\\ M\_5 &= (A\_{1,1} + A\_{1,2})B\_{2,2} \\\\ M\_6 &= (A\_{2,1} +
A\_{1,1})(B\_{1,1} + B\_{1,2}) \\\\ M\_7 &= (A\_{1,2} +
A\_{2,2})(B\_{2,1} + B\_{2,2})
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20M_1%20%26%3D%20%28A_%7B1%2C1%7D%20%2B%20A_%7B2%2C2%7D%29%28B_%7B1%2C1%7D%20%2B%20B_%7B2%2C2%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20M_2%20%26%3D%20%28A_%7B2%2C1%7D%20%2B%20A_%7B2%2C2%7D%29B_%7B1%2C1%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20M_3%20%26%3D%20A_%7B1%2C1%7D%28B_%7B1%2C2%7D%20-%20B_%7B2%2C2%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20M_4%20%26%3D%20A_%7B2%2C2%7D%28B_%7B2%2C1%7D%20-%20B_%7B1%2C1%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20M_5%20%26%3D%20%28A_%7B1%2C1%7D%20%2B%20A_%7B1%2C2%7D%29B_%7B2%2C2%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20M_6%20%26%3D%20%28A_%7B2%2C1%7D%20%2B%20A_%7B1%2C1%7D%29%28B_%7B1%2C1%7D%20%2B%20B_%7B1%2C2%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20M_7%20%26%3D%20%28A_%7B1%2C2%7D%20%2B%20A_%7B2%2C2%7D%29%28B_%7B2%2C1%7D%20%2B%20B_%7B2%2C2%7D%29%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            M_1 &= (A_{1,1} + A_{2,2})(B_{1,1} + B_{2,2}) \\
            M_2 &= (A_{2,1} + A_{2,2})B_{1,1} \\
            M_3 &= A_{1,1}(B_{1,2} - B_{2,2}) \\
            M_4 &= A_{2,2}(B_{2,1} - B_{1,1}) \\
            M_5 &= (A_{1,1} + A_{1,2})B_{2,2} \\
            M_6 &= (A_{2,1} + A_{1,1})(B_{1,1} + B_{1,2}) \\
            M_7 &= (A_{1,2} + A_{2,2})(B_{2,1} + B_{2,2})
        \end{aligned}")\

We can now calculate
![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") in terms of
![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M"):

\
![\\begin{aligned} C\_{1,1} &= M\_1 + M\_4 - M\_5 + M\_7 \\\\ C\_{1,2}
&= M\_3 + M\_5 \\\\ C\_{2,1} &= M\_2 + M\_4 \\\\ C\_{2,2} &= M\_1 + M\_2
+ M\_3 + M\_6
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20C_%7B1%2C1%7D%20%26%3D%20M_1%20%2B%20M_4%20-%20M_5%20%2B%20M_7%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20C_%7B1%2C2%7D%20%26%3D%20M_3%20%2B%20M_5%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20C_%7B2%2C1%7D%20%26%3D%20M_2%20%2B%20M_4%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20C_%7B2%2C2%7D%20%26%3D%20M_1%20%2B%20M_2%20%2B%20M_3%20%2B%20M_6%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            C_{1,1} &= M_1 + M_4 - M_5 + M_7 \\
            C_{1,2} &= M_3 + M_5 \\
            C_{2,1} &= M_2 + M_4 \\
            C_{2,2} &= M_1 + M_2 + M_3 + M_6
        \end{aligned}")\

Since we calculate this with
![7](http://chart.apis.google.com/chart?cht=tx&chl=7 "7")
multiplications of sub-problems of size
![n/2](http://chart.apis.google.com/chart?cht=tx&chl=n%2F2 "n/2"), this
will take us ![T(n) = 7 T(n/2) +
in](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%3D%207%20T%28n%2F2%29%20%2B%20in "T(n) = 7 T(n/2) + in")
(![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") is for the
number of additions). By master method, we arrive at ![T(n) =
\\Theta(n\^{\\log\_2(7)})](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%3D%20%5CTheta%28n%5E%7B%5Clog_2%287%29%7D%29 "T(n) = \Theta(n^{\log_2(7)})")
as the running time of the algorithm.

Subsection [Sec 9.2-9.3]
------------------------

Basic problem statement: Find the
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i")th element of
an array ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A").

### Randomized Quickselect

Basic idea is to pick a random element, seperate the elements into
subsets that are larger and smaller than the element, then recurse into
the subset.

Best runtime is
![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)"),
but worst runtime is
![O(n\^2)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E2%29 "O(n^2)")
since it is random. Average runtime is
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)"),
but we can do better.

### Blum, Floyd, Pratt, Rivest, and Tarjan’s Algorithm

Also called “Median of Five”.

The way this works is pretty cool. We pick the median by finding the
median of groups of five elements (recursive call 1). Then we use the
knowledge of the value of the median to do a quickselect-style recursion
(call 2) into the half that contains our element.

Through this algorithm, finding the median takes
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")
time (awesome), and the overall algorithm takes
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")
time.

Pseudocode:

                    select(A, k):
                        if (|A| == 1):
                            return A[0]
                        split A into groups G, each of 5 elements
                        create B = median of each g in G
                        x = select(B, |B|/2)
                        L = {a < x}
                        R = {a > x}
                        if (l <= k):
                            return select(L, k)
                        else
                            return select(R, k-|L|)
                

Greedy Algorithms
=================

Put simply, greedy algorithms solve decision problems in short amounts
of time. They don’t backtrack, and rely on a heuristic to make their
decisions. They don’t work in all circumstances, but are speedy in some.
Greedy is (sometimes) good.

We (almost always) need to prove greedy algorithms to be correct.
Proving them wrong is not very hard.

Coin Changing
-------------

Problem definition: You are asked to make
![\\\$1.34](http://chart.apis.google.com/chart?cht=tx&chl=%5C%241.34 "\$1.34")
into the fewest coins possible. Given a dollar value and a set of coin
values, what are the minimum coins that make up that value?

Simple algorithm that everybody uses: pick the highest value coin that
is less than the difference between the sum of coins you have chosen and
the dollar value remaining.

Disjoint intervals
------------------

Problem definition: You are given a set
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") of intervals
where some of them overlap. Choose the largest subset
![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") of
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") such that
elements in ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") do
not overlap.

Here are a bunch of heuristics:

-   Pick the shortest range. This fails.

-   Pick the range that conflicts with the fewest ranges. This fails.

-   Pick the range that finishes first. This succeeds.

Fractional knapsack
-------------------

Problem definition: You are given a set of items
![I](http://chart.apis.google.com/chart?cht=tx&chl=I "I") and a backpack
size ![b](http://chart.apis.google.com/chart?cht=tx&chl=b "b"). Each
item has a weight
![i.w](http://chart.apis.google.com/chart?cht=tx&chl=i.w "i.w") and a
size ![i.s](http://chart.apis.google.com/chart?cht=tx&chl=i.s "i.s").
You are allowed to choose fractional items. Choose backpack items such
that the value of your bag is maximized while not being oversized.

Correct Heuristic: While there is room in your knapsack, pick the
remaining item that has the highest weight/size ratio, and put it in
your knapsack. If it doesn’t fit, put a fraction of it in your knapsack.

Stable marriage
---------------

Problem definition: You are given a set of men and women, and lists of
their preferences for each other. Provide a “matching” of them such that
no two people prefer each other over their “match”.

Correct Heuristic: While there are unmatched men, send an unmatched man
to the next woman on his list that he hasn’t proposed to yet. If that
woman is already paired, she chooses between the two men, and the less
preferred suitor becomes unmatched.

Proof of correctness:

-   Claim 1: A woman exists that he hasn’t proposed to yet.

    Some women are unmatched. All women previously proposed to by him
    are matched. Therefore, some matched woman hasn’t been proposed to
    by him.

-   Claim 2: The resultant matching is stable.

    (By way of contradiction) Suppose we have matched pairs
    ![{\\ensuremath{\\left \\langle c, e \\right \\rangle
    }}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20c%2C%20e%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle c, e \right \rangle }}")
    and ![{\\ensuremath{\\left \\langle c', e' \\right \\rangle
    }}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20c%27%2C%20e%27%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle c', e' \right \rangle }}")
    where ![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c")
    prefers
    ![e'](http://chart.apis.google.com/chart?cht=tx&chl=e%27 "e'") over
    ![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e") and
    ![e'](http://chart.apis.google.com/chart?cht=tx&chl=e%27 "e'")
    prefers ![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c")
    over ![c'](http://chart.apis.google.com/chart?cht=tx&chl=c%27 "c'").
    Then we must have had that
    ![e'](http://chart.apis.google.com/chart?cht=tx&chl=e%27 "e'") made
    an offer to
    ![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c") before
    ![c'](http://chart.apis.google.com/chart?cht=tx&chl=c%27 "c'").
    Later on,
    ![e'](http://chart.apis.google.com/chart?cht=tx&chl=e%27 "e'") made
    an offer to
    ![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c"), and
    ![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c") preferred
    ![e'](http://chart.apis.google.com/chart?cht=tx&chl=e%27 "e'") over
    ![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e"). Since
    that is impossible, the solution must be stable.

Dynamic Programming
===================

Basically, Dynamic Programming is solving smaller problems first before
solving larger problems, then using the smaller problems as building
blocks for the larger problems.

Problems where recursive functions are called repetitively with the same
arguments can be transformed to a dynamic programming problem. We take
the recursive formula, and build up to it (instead of down).

We use an array to “cache” results of recursive functions, and
effectively loop our code from “early parameters” to higher parameters.
We work towards our solution.

In solutions, we need to specify:

1.  Recursive formula

2.  Initial values

3.  Iteration order

4.  A sub-problem the solution is composed of

5.  The answer in terms of an array

Binomial coefficients
---------------------

We want to calculate ![{n \\choose
k}](http://chart.apis.google.com/chart?cht=tx&chl=%7Bn%20%5Cchoose%20k%7D "{n \choose k}")
in the fewest number of calculations possible.

Define our recursive formula:

\
![\\begin{aligned} C(n, k) &= \\left\\{ \\begin{array}{lr} 1 & n = k
\\text{ or } k = 0 \\\\ C(n-1, k-1) + C(n-1, k) & \\text{otherwise}
\\end{array} \\right.
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20C%28n%2C%20k%29%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%201%20%26%20n%20%3D%20k%20%5Ctext%7B%20or%20%7D%20k%20%3D%200%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20C%28n-1%2C%20k-1%29%20%2B%20C%28n-1%2C%20k%29%20%26%20%5Ctext%7Botherwise%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            C(n, k) &=
            \left\{
                \begin{array}{lr}
                    1 & n = k \text{ or } k = 0 \\
                    C(n-1, k-1) + C(n-1, k) & \text{otherwise}
                \end{array}
            \right.
        \end{aligned}")\

Implemented in code, this would look like:

                def C(i, j):
                    if (i == j || j == 0):
                        return 1
                    return C(i-1, j-1) + C(i-1, j)
            

This is a valid algorithm but in this implementation, the same values of
![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") will be
calculated many times over and over.

If we make ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") an
array instead of a function and determine an iteration order, we only
need to calculate values of
![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") once.

For the iteration order, we can iterate from ![i =
0...n](http://chart.apis.google.com/chart?cht=tx&chl=i%20%3D%200...n "i = 0...n"),
and for each of those we can iterate ![j =
0...k](http://chart.apis.google.com/chart?cht=tx&chl=j%20%3D%200...k "j = 0...k").

We also need to determine initial values of
![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C"). In this case
we have ![C[i, 0] =
1](http://chart.apis.google.com/chart?cht=tx&chl=C%5Bi%2C%200%5D%20%3D%201 "C[i, 0] = 1"),
![C[0, i] =
1](http://chart.apis.google.com/chart?cht=tx&chl=C%5B0%2C%20i%5D%20%3D%201 "C[0, i] = 1").

The code would look like this:

                def C(n, k):
                    C = new array[n,k]
                    for i = 0...n:
                        C[i, 0] = 1
                    for i = 0...min(n, k):
                        C[0, i] = 1
                    for i = 0...n:
                        for j=0...k:
                            C[i, j] = C[i-1, j-1] + C[i-1, j]
                    return C[n, k]
            

The array ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") is
![nk](http://chart.apis.google.com/chart?cht=tx&chl=nk "nk") in size.
Every element is calculated once, and takes
![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)")
time to calculate. Thus, this algorithm takes
![O(nk)](http://chart.apis.google.com/chart?cht=tx&chl=O%28nk%29 "O(nk)")
time overall.

Coin Changing
-------------

Given a set of coins
![N](http://chart.apis.google.com/chart?cht=tx&chl=N "N") and a target
value ![w](http://chart.apis.google.com/chart?cht=tx&chl=w "w"), what is
the minimum number of coins in
![N](http://chart.apis.google.com/chart?cht=tx&chl=N "N") summing to
![w](http://chart.apis.google.com/chart?cht=tx&chl=w "w").

Sub-problem: We define ![C[i,
j]](http://chart.apis.google.com/chart?cht=tx&chl=C%5Bi%2C%20j%5D "C[i, j]")
as the minimum number of coins in
![\\{N\_0...N\_i\\}](http://chart.apis.google.com/chart?cht=tx&chl=%5C%7BN_0...N_i%5C%7D "\{N_0...N_i\}")
that sum to ![j](http://chart.apis.google.com/chart?cht=tx&chl=j "j").

Solution: Return ![C[|N|,
w]](http://chart.apis.google.com/chart?cht=tx&chl=C%5B%7CN%7C%2C%20w%5D "C[|N|, w]"),
the minimum number of coins in
![N](http://chart.apis.google.com/chart?cht=tx&chl=N "N") that sum to
![w](http://chart.apis.google.com/chart?cht=tx&chl=w "w").

Base cases:

\
![\\begin{aligned} C[i, 0] &= 0 \\\\ C[0, j] &= \\infty
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20C%5Bi%2C%200%5D%20%26%3D%200%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20C%5B0%2C%20j%5D%20%26%3D%20%5Cinfty%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            C[i, 0] &= 0 \\
            C[0, j] &= \infty
        \end{aligned}")\

Recursive formula:

\
![\\begin{aligned} C[i, j] &= \\left\\{ \\begin{array}{lr} \\min(C[i-1,
j], C[i-1, j-1] + 1) & j \\ge D\_i \\\\ C[i-1, j] & \\text{ otherwise }
\\end{array} \\right.
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20C%5Bi%2C%20j%5D%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmin%28C%5Bi-1%2C%20j%5D%2C%20C%5Bi-1%2C%20j-1%5D%20%2B%201%29%20%26%20j%20%5Cge%20D_i%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20C%5Bi-1%2C%20j%5D%20%26%20%5Ctext%7B%20otherwise%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            C[i, j] &=
            \left\{
                \begin{array}{lr}
                    \min(C[i-1, j], C[i-1, j-1] + 1) & j \ge D_i \\
                    C[i-1, j] & \text{ otherwise }
                \end{array}
            \right.
        \end{aligned}")\

Iteration order: Iterate through all numbers ![i =
1...n](http://chart.apis.google.com/chart?cht=tx&chl=i%20%3D%201...n "i = 1...n"),
for each of those iterate through ![j =
1...w](http://chart.apis.google.com/chart?cht=tx&chl=j%20%3D%201...w "j = 1...w").

Code:

                def minGrouping(D, w):
                    for i = 0...n:
                        C[i, 0] = 0
                    for j = 1...w:
                        C[0, j] = infinity
                    for i = 1...n:
                        for j=1...w:
                            if j < D[i]:
                                C[i, j] = min(C[i-1, j], C[i-1, j-1] + 1)
                            else:
                                C[i, j] = C[i-1, j]
                    return C[|D|, w]
            

The array ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C")
takes
![O(w|N|)](http://chart.apis.google.com/chart?cht=tx&chl=O%28w%7CN%7C%29 "O(w|N|)")
space. Each element in
![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") is calculated
exactly once and takes
![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)")
time to calculate, so the entire algorithm takes
![O(w|N|)](http://chart.apis.google.com/chart?cht=tx&chl=O%28w%7CN%7C%29 "O(w|N|)")
time total.

0-1 Knapsack
------------

Problem definition: Given a set of
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") items with
values ![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V") and
weights ![W](http://chart.apis.google.com/chart?cht=tx&chl=W "W"),
maximize the total value without the weight going over
![w](http://chart.apis.google.com/chart?cht=tx&chl=w "w").

Subproblem definition: ![C[i,
j]](http://chart.apis.google.com/chart?cht=tx&chl=C%5Bi%2C%20j%5D "C[i, j]")
is the highest value possible with the first
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") elements, at a
weight limit of
![j](http://chart.apis.google.com/chart?cht=tx&chl=j "j").

Answer: ![C[n,
w]](http://chart.apis.google.com/chart?cht=tx&chl=C%5Bn%2C%20w%5D "C[n, w]")

Base cases: ![C[0, j] = C[i, 0] =
0](http://chart.apis.google.com/chart?cht=tx&chl=C%5B0%2C%20j%5D%20%3D%20C%5Bi%2C%200%5D%20%3D%200 "C[0, j] = C[i, 0] = 0")

Recursive formula:

\
![\\begin{aligned} C[i, j] &= \\left\\{ \\begin{array}{lr} \\max(C[i-1,
j], C[i-1, j-W\_i] + V\_i) & j \\ge w\_i \\\\ C[i-1, j] & \\text{
otherwise } \\end{array} \\right.
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20C%5Bi%2C%20j%5D%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmax%28C%5Bi-1%2C%20j%5D%2C%20C%5Bi-1%2C%20j-W_i%5D%20%2B%20V_i%29%20%26%20j%20%5Cge%20w_i%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20C%5Bi-1%2C%20j%5D%20%26%20%5Ctext%7B%20otherwise%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            C[i, j] &=
            \left\{
                \begin{array}{lr}
                    \max(C[i-1, j], C[i-1, j-W_i] + V_i) & j \ge w_i \\
                    C[i-1, j] & \text{ otherwise }
                \end{array}
            \right.
        \end{aligned}")\

Code:

                def C(V, W, w):
                    n = |V|
                    for i=0...n:
                        C[i, 0] = 0
                    for j=0...w:
                        C[0, j] = 0
                    for i=1...n:
                        for j=1...w:
                            if (j >= W[i]):
                                C[i, j] = max(C[i-1, j], C[i-1, j-W[i]] + V[i])
                            else:
                                C[i, j] = C[i-1, j]
                    return C[n, w]
            

Longest common subsequence
--------------------------

Reference for this can be found at [Sec 15.4]

Problem statement: Given strings
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") and
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B"), return the
longest subsequence of characters that appear in both strings.

i.e. ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") =
“ALGORITHM”, ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") =
“LOGARITHM”.

The longest common substring is “LORITHM”.

Subproblem: ![C[i,
j]](http://chart.apis.google.com/chart?cht=tx&chl=C%5Bi%2C%20j%5D "C[i, j]")
is the length of the longest substring of the first
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") characters of
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") and the first
![j](http://chart.apis.google.com/chart?cht=tx&chl=j "j") characters of
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B").

Answer: ![C[m,
n]](http://chart.apis.google.com/chart?cht=tx&chl=C%5Bm%2C%20n%5D "C[m, n]"),
where ![m =
|A|](http://chart.apis.google.com/chart?cht=tx&chl=m%20%3D%20%7CA%7C "m = |A|"),
![n =
|B|](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3D%20%7CB%7C "n = |B|").

Base case: ![C[i, 0] = C[0, j] =
0](http://chart.apis.google.com/chart?cht=tx&chl=C%5Bi%2C%200%5D%20%3D%20C%5B0%2C%20j%5D%20%3D%200 "C[i, 0] = C[0, j] = 0")
(![i =
0...m](http://chart.apis.google.com/chart?cht=tx&chl=i%20%3D%200...m "i = 0...m"),
![j =
0...n](http://chart.apis.google.com/chart?cht=tx&chl=j%20%3D%200...n "j = 0...n")).

Recursive formula:

\
![\\begin{aligned} C[i, j] &= \\left\\{ \\begin{array}{lr} \\max(C[i-1,
j], C[i, j-1]) & A\_i \\ne B\_j \\\\ \\max(C[i-1, j], C[i, j-1], C[i-1,
j-1]+1) & A\_i = B\_j \\\\ \\end{array} \\right.
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20C%5Bi%2C%20j%5D%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmax%28C%5Bi-1%2C%20j%5D%2C%20C%5Bi%2C%20j-1%5D%29%20%26%20A_i%20%5Cne%20B_j%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmax%28C%5Bi-1%2C%20j%5D%2C%20C%5Bi%2C%20j-1%5D%2C%20C%5Bi-1%2C%20j-1%5D%2B1%29%20%26%20A_i%20%3D%20B_j%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            C[i, j] &=
            \left\{
                \begin{array}{lr}
                    \max(C[i-1, j], C[i, j-1]) & A_i \ne B_j \\
                    \max(C[i-1, j], C[i, j-1], C[i-1, j-1]+1) & A_i = B_j \\
                \end{array}
            \right.
        \end{aligned}")\

i.e. If the characters at
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") and
![j](http://chart.apis.google.com/chart?cht=tx&chl=j "j") don’t match,
use the max of ![{\\ensuremath{\\left \\langle i-1, j \\right \\rangle
}}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20i-1%2C%20j%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle i-1, j \right \rangle }}")
and ![{\\ensuremath{\\left \\langle i, j-1 \\right \\rangle
}}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20i%2C%20j-1%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle i, j-1 \right \rangle }}").
If they do match, use the max of ![{\\ensuremath{\\left \\langle i-1, j
\\right \\rangle
}}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20i-1%2C%20j%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle i-1, j \right \rangle }}"),
![{\\ensuremath{\\left \\langle i, j-1 \\right \\rangle
}}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20i%2C%20j-1%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle i, j-1 \right \rangle }}"),
and ![{\\ensuremath{\\left \\langle i-1, j-1 \\right \\rangle
}}+1](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20i-1%2C%20j-1%20%5Cright%20%5Crangle%20%7D%7D%2B1 "{\ensuremath{\left \langle i-1, j-1 \right \rangle }}+1").

Code:

                def LCS(A, B):
                    n = |A|
                    m = |B|
                    C = []
                    for i = 0...m:
                        C[i, 0] = 0
                    for j = 0...n:
                        C[0, j] = 0
                    for i = 0...m:
                        for j = 0...n:
                            if (A[i] == B[j]):
                                C[i, j] = max(C[i-1, j], C[i, j-1], C[i-1, j-1]+1)
                            else:
                                C[i, j] = max(C[i-1, j], C[i, j-1])
                    return C[n, m]
            

Minimum-length triangulation
----------------------------

Reference for this can be found at [CLR (1st ed.), Sec 16.4]

Given a convex polygon
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") with
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") vertices, find
the triangulation with minimum length of chords.

Brute force takes
![\\Omega\\left(\\frac{4\^n}{n\^{3/2}}\\right)](http://chart.apis.google.com/chart?cht=tx&chl=%5COmega%5Cleft%28%5Cfrac%7B4%5En%7D%7Bn%5E%7B3%2F2%7D%7D%5Cright%29 "\Omega\left(\frac{4^n}{n^{3/2}}\right)")
possible triangulations. DP does better than this.

Sub-problems: (![1 \\le i \\le j \\le
n](http://chart.apis.google.com/chart?cht=tx&chl=1%20%5Cle%20i%20%5Cle%20j%20%5Cle%20n "1 \le i \le j \le n"))

\
![\\begin{aligned} C[i, j] = \\text{ length of the minimum-length
triangulation of the sub-polygon with the vertices running from \$i\$ to
\$j\$ (then looping back) }
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20C%5Bi%2C%20j%5D%20%3D%20%5Ctext%7B%20length%20of%20the%20minimum-length%20triangulation%20of%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20the%20sub-polygon%20with%20the%20vertices%20running%20from%20%24i%24%20to%20%24j%24%20%28then%20looping%20back%29%20%7D%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            C[i, j] = \text{ length of the minimum-length triangulation of
                the sub-polygon with the vertices running from $i$ to $j$ (then looping back) }
        \end{aligned}")\

Answer: ![C[1,
n]](http://chart.apis.google.com/chart?cht=tx&chl=C%5B1%2C%20n%5D "C[1, n]")

Base-cases: ![C[i, i+1] = C[i, i+2] =
0](http://chart.apis.google.com/chart?cht=tx&chl=C%5Bi%2C%20i%2B1%5D%20%3D%20C%5Bi%2C%20i%2B2%5D%20%3D%200 "C[i, i+1] = C[i, i+2] = 0")

Recursive formula:

\
![\\begin{aligned} C[i, j] &= \\min\_{k \\in \\{ i+1 \\ldots j-1 \\}}
\\left\\{ C[i, k] + C[k, j] + d(V\_i, V\_k) + d(V\_j, V\_k) \\right.
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20C%5Bi%2C%20j%5D%20%26%3D%20%5Cmin_%7Bk%20%5Cin%20%5C%7B%20i%2B1%20%5Cldots%20j-1%20%5C%7D%7D%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20C%5Bi%2C%20k%5D%20%2B%20C%5Bk%2C%20j%5D%20%2B%20d%28V_i%2C%20V_k%29%20%2B%20d%28V_j%2C%20V_k%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            C[i, j] &= \min_{k \in \{ i+1 \ldots j-1 \}} \left\{
                C[i, k] + C[k, j] + d(V_i, V_k) + d(V_j, V_k)
            \right.
        \end{aligned}")\

i.e. ![C[i,
j]](http://chart.apis.google.com/chart?cht=tx&chl=C%5Bi%2C%20j%5D "C[i, j]")
is the minimum length for any way you split the polygon, which is the
cost of the left half plus the right half plus the distance of the
halves.

Iteration order was not written down, but I’m sure it was complicated.

Graph Algorithms
================

BFS/DFS
-------

Skipped writing this one, it’s in my notes, and seems to be pretty
trivial. The only thing to watch out for is to mark vertices as
discovered because “this is a graph” and not a tree.

Connectedness
-------------

Skipped this class?

Cycle Detection
---------------

Skipped this class?

2-Coloring
----------

Skipped this class?

Topological Sorting
-------------------

Problem description: For a directed graph ![G=(V,
E)](http://chart.apis.google.com/chart?cht=tx&chl=G%3D%28V%2C%20E%29 "G=(V, E)"),
return a vertex order such that for all edges, the “from vertex” appears
before the “to vertex”.

Conceptually, we visit all vertices using BFS. If we reach any vertex we
have already touched, then we know there is a cycle. Otherwise, we are
able to put elements into L in the order they are explored.

                def topologicalSort(V, E):
                    L = []
                    while there are unmarked vertices:
                        n = an unmarked vertex
                        visit(n)
                    return L
                def visit(n):
                    if n has a temporary mark, we have found a cycle
                    if n is not marked:
                        mark n temporarily
                        for each node m with an edge from n to m:
                            visit(m)
                        mark n permanently
                        add n to L
            

Strongly Connected Components (Kosaraju and Sharir’s Algorithm)
---------------------------------------------------------------

Given a directed graph ![G = (V,
E)](http://chart.apis.google.com/chart?cht=tx&chl=G%20%3D%20%28V%2C%20E%29 "G = (V, E)"),
partion ![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V") into
components such that for all ![u,
v](http://chart.apis.google.com/chart?cht=tx&chl=u%2C%20v "u, v") in
some component, there exists a path from
![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") to
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") and there
exists a path from
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") to
![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u").

i.e. we want to simplify/condense a directed graph into a DAG.

1.  Run DFS(G), number vertices in the order that they finish.

2.  Form
    ![G\^T](http://chart.apis.google.com/chart?cht=tx&chl=G%5ET "G^T")
    (the transpose of
    ![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G") - arrows
    are reversed).

3.  Run
    DFS(![G\^T](http://chart.apis.google.com/chart?cht=tx&chl=G%5ET "G^T")),
    preferring higher-numbered vertices.

4.  Return the vertices from each DFS tree as components.

Proof: Take a DFS tree
![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") of
![G\^T](http://chart.apis.google.com/chart?cht=tx&chl=G%5ET "G^T"). Let
![r](http://chart.apis.google.com/chart?cht=tx&chl=r "r") be a root,
![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") be any Vertex
of ![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T").

1.  ![r](http://chart.apis.google.com/chart?cht=tx&chl=r "r") has a
    higher number than
    ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") (if not,
    pick ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u")
    first).

2.  There exists a path ![u \\to
    r](http://chart.apis.google.com/chart?cht=tx&chl=u%20%5Cto%20r "u \to r")
    in ![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G"), since
    there exists a path ![r \\to
    u](http://chart.apis.google.com/chart?cht=tx&chl=r%20%5Cto%20u "r \to u")
    in
    ![G\^T](http://chart.apis.google.com/chart?cht=tx&chl=G%5ET "G^T").

3.  There exists a path ![r \\to
    u](http://chart.apis.google.com/chart?cht=tx&chl=r%20%5Cto%20u "r \to u")
    in ![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G").

    By way of contradiction, assume that there is no such path:

    If ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") was
    discovered first, then
    ![r](http://chart.apis.google.com/chart?cht=tx&chl=r "r") finished
    before ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u"),
    which means they would’ve been ordered differently.

    If ![r](http://chart.apis.google.com/chart?cht=tx&chl=r "r") was
    discovered first, ![r \\not \\to
    u](http://chart.apis.google.com/chart?cht=tx&chl=r%20%5Cnot%20%5Cto%20u "r \not \to u")
    by assumption,
    ![r](http://chart.apis.google.com/chart?cht=tx&chl=r "r") finished
    before ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u").

4.  For all ![u,
    v](http://chart.apis.google.com/chart?cht=tx&chl=u%2C%20v "u, v") in
    ![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T"), there
    exists a path ![u \\leftrightarrow
    v](http://chart.apis.google.com/chart?cht=tx&chl=u%20%5Cleftrightarrow%20v "u \leftrightarrow v"),
    since there exist paths ![u \\leftrightarrow
    r](http://chart.apis.google.com/chart?cht=tx&chl=u%20%5Cleftrightarrow%20r "u \leftrightarrow r")
    and ![r \\leftrightarrow
    v](http://chart.apis.google.com/chart?cht=tx&chl=r%20%5Cleftrightarrow%20v "r \leftrightarrow v").

5.  There exists a path ![u \\leftrightarrow
    v](http://chart.apis.google.com/chart?cht=tx&chl=u%20%5Cleftrightarrow%20v "u \leftrightarrow v")
    in ![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G") implies
    ![{\\ensuremath{\\left \\langle u, v \\right \\rangle
    }}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20u%2C%20v%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle u, v \right \rangle }}")
    are in the same tree.

Minimum Spanning Trees
----------------------

A spanning tree is a subgraph of a graph that is a tree and connects to
all vertices.

A minimum spanning tree is a subgraph of a graph that has the least (or
equal to the lowest) sum of weighted edges in the spanning tree compared
to all other spanning trees of the graph.

### Kruskal’s Algorithm

Kruskal’s Algorithm is a greedy algorithm to find the minimum spanning
tree of a graph.

Basic idea of algorithm is as follows:

-   Create a set of trees
    ![F](http://chart.apis.google.com/chart?cht=tx&chl=F "F") from all
    vertices in
    ![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V").

-   Create a set of edges
    ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") from all
    edges in ![E](http://chart.apis.google.com/chart?cht=tx&chl=E "E").

-   While ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") is
    nonempty and
    ![F](http://chart.apis.google.com/chart?cht=tx&chl=F "F") is not
    spanning:

    -   Remove an edge
        ![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e") with
        minimum weight from
        ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S").

    -   If ![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e")
        connects two trees in
        ![F](http://chart.apis.google.com/chart?cht=tx&chl=F "F"),
        remove the two trees from
        ![F](http://chart.apis.google.com/chart?cht=tx&chl=F "F"), join
        them by
        ![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e") and
        add that to
        ![F](http://chart.apis.google.com/chart?cht=tx&chl=F "F").

-   Return ![F](http://chart.apis.google.com/chart?cht=tx&chl=F "F").

### Prim’s Algorithm

Prim’s Algorithm is a greedy algorithm to find the minimum spanning tree
of a graph.

Input: A connected weighted graph ![G = (V,
E)](http://chart.apis.google.com/chart?cht=tx&chl=G%20%3D%20%28V%2C%20E%29 "G = (V, E)").

-   Initialize ![V\_{seen} =
    \\{x\\}](http://chart.apis.google.com/chart?cht=tx&chl=V_%7Bseen%7D%20%3D%20%5C%7Bx%5C%7D "V_{seen} = \{x\}")
    (![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x")) is an
    arbitrary node.

-   Initialize ![E\_{mst} =
    \\{\\}](http://chart.apis.google.com/chart?cht=tx&chl=E_%7Bmst%7D%20%3D%20%5C%7B%5C%7D "E_{mst} = \{\}").

-   While ![V\_{seen} !=
    V](http://chart.apis.google.com/chart?cht=tx&chl=V_%7Bseen%7D%20%21%3D%20V "V_{seen} != V"):

    -   Choose an edge ![{\\ensuremath{\\left \\langle u,v \\right
        \\rangle
        }}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20u%2Cv%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle u,v \right \rangle }}")
        with minimal weight so
        ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") is in
        ![V\_{seen}](http://chart.apis.google.com/chart?cht=tx&chl=V_%7Bseen%7D "V_{seen}")
        and ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") is
        not.

    -   Add ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") to
        ![V\_{seen}](http://chart.apis.google.com/chart?cht=tx&chl=V_%7Bseen%7D "V_{seen}")
        and ![{\\ensuremath{\\left \\langle u, v \\right \\rangle
        }}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20u%2C%20v%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle u, v \right \rangle }}")
        to
        ![E\_{mst}](http://chart.apis.google.com/chart?cht=tx&chl=E_%7Bmst%7D "E_{mst}").

-   Return
    ![E\_{mst}](http://chart.apis.google.com/chart?cht=tx&chl=E_%7Bmst%7D "E_{mst}").

If we set ![n =
|V|](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3D%20%7CV%7C "n = |V|")
and ![m =
|E|](http://chart.apis.google.com/chart?cht=tx&chl=m%20%3D%20%7CE%7C "m = |E|"),
we can get it to be ![O(n\^2 +
m)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E2%20%2B%20m%29 "O(n^2 + m)")
using no fast data structures, ![O(m \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%20%5Clog%20n%29 "O(m \log n)")
using a heap, and ![O(n \\log n +
m)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Clog%20n%20%2B%20m%29 "O(n \log n + m)")
using a Fibonacci Heap.

Shortest Paths
--------------

Given a weighted directed graph ![G = (V,
E)](http://chart.apis.google.com/chart?cht=tx&chl=G%20%3D%20%28V%2C%20E%29 "G = (V, E)"),
find a path ![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P")
from ![s](http://chart.apis.google.com/chart?cht=tx&chl=s "s") to
![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t") such that we
minimize the “weight” of the path.

### DP for DAG case

We can solve this problem using DP.

Sub-Problem: ![\\delta[v] =
w(](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta%5Bv%5D%20%3D%20w%28 "\delta[v] = w(")
shortest path ![s \\to
v)](http://chart.apis.google.com/chart?cht=tx&chl=s%20%5Cto%20v%29 "s \to v)").

Answer:
![\\delta[t]](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta%5Bt%5D "\delta[t]")

Base case: ![\\delta[s] =
0](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta%5Bs%5D%20%3D%200 "\delta[s] = 0")

Recursive formula:

\
![\\begin{aligned} \\delta[i] &= \\min\_{u \\in V : {\\ensuremath{\\left
\\langle u,v \\right \\rangle }} \\in E} \\{ \\delta[u] + w(u,v)\\}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cdelta%5Bi%5D%20%26%3D%20%5Cmin_%7Bu%20%5Cin%20V%20%3A%20%7B%5Censuremath%7B%5Cleft%20%5Clangle%20u%2Cv%20%5Cright%20%5Crangle%20%7D%7D%20%5Cin%20E%7D%20%5C%7B%20%5Cdelta%5Bu%5D%20%2B%20w%28u%2Cv%29%5C%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                \delta[i] &= \min_{u \in V : {\ensuremath{\left \langle u,v \right \rangle }} \in E} \{ \delta[u] + w(u,v)\}
            \end{aligned}")\

Iteration order: Topological sort order.

Analysis: ![O(n + \\sum\_{v \\in V} \\text{inDeg}(v)) = O(m +
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%2B%20%5Csum_%7Bv%20%5Cin%20V%7D%20%5Ctext%7BinDeg%7D%28v%29%29%20%3D%20O%28m%20%2B%20n%29 "O(n + \sum_{v \in V} \text{inDeg}(v)) = O(m + n)")
time.

### Dijkstra’s Algorithm

Dijkstra’s Algorithm assumes a positive weight for all edges in the
graph.

We compute d[v] = shortest path weight from s to v

                    // Assumes positive weight
                    S = {s}
                    delta[s] = 0
                    while S != V:
                        pick edge(u,v) with u in S, v in V-S that minimizes delta[u] + w(u, v)
                        insert v to S
                        delta[v] = delta[u] + w(u, v)
                

In fact, Dijkstra’s algorithm is similar to Prim’s algorithm, but the
selection criteria changes from pick the shortest “edge” from a
![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") to a
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") to pick the
shortest “edge + delta[v]”.

It runs in ![O(n \\log n +
m)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Clog%20n%20%2B%20m%29 "O(n \log n + m)")
time, where ![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m") is
the number of edges.

Claim: If ![{\\ensuremath{\\left \\langle u, v \\right \\rangle
}}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20u%2C%20v%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle u, v \right \rangle }}")
is the edge with the shortest
![delta[u]+w(u,v)](http://chart.apis.google.com/chart?cht=tx&chl=delta%5Bu%5D%2Bw%28u%2Cv%29 "delta[u]+w(u,v)"),
then the shortest weight from
![s](http://chart.apis.google.com/chart?cht=tx&chl=s "s") to
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") is equal to
![delta[u]+w(u,v)](http://chart.apis.google.com/chart?cht=tx&chl=delta%5Bu%5D%2Bw%28u%2Cv%29 "delta[u]+w(u,v)").

Proof: There is a path from
![s](http://chart.apis.google.com/chart?cht=tx&chl=s "s") to
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") of weight
![delta[u] +
w(u,v)](http://chart.apis.google.com/chart?cht=tx&chl=delta%5Bu%5D%20%2B%20w%28u%2Cv%29 "delta[u] + w(u,v)")
Consider another path
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") from
![s](http://chart.apis.google.com/chart?cht=tx&chl=s "s") to
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v"). P contains
edge ![{\\ensuremath{\\left \\langle u',v' \\right \\rangle
}}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20u%27%2Cv%27%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle u',v' \right \rangle }}")
from ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") to
![S-V](http://chart.apis.google.com/chart?cht=tx&chl=S-V "S-V"). Then
![w(p) \\ge delta[u'] + w(u', v') + 0 \\ge delta[u] +
w(u,v)](http://chart.apis.google.com/chart?cht=tx&chl=w%28p%29%20%5Cge%20delta%5Bu%27%5D%20%2B%20w%28u%27%2C%20v%27%29%20%2B%200%20%5Cge%20delta%5Bu%5D%20%2B%20w%28u%2Cv%29 "w(p) \ge delta[u'] + w(u', v') + 0 \ge delta[u] + w(u,v)").

### All-Pairs Shortest Paths

Problem statement: For every pair of vertices ![{\\ensuremath{\\left
\\langle u,v \\right \\rangle
}}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20u%2Cv%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle u,v \right \rangle }}"),
find the shortest path
![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") to
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v").

#### Dijkstra Repeatedly

Runs in ![O(n(n \\log n +
m))](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%28n%20%5Clog%20n%20%2B%20m%29%29 "O(n(n \log n + m))"),
but assumes all edges are positive.

#### DP \#1

Subproblems
![D[i,j,k]](http://chart.apis.google.com/chart?cht=tx&chl=D%5Bi%2Cj%2Ck%5D "D[i,j,k]")
is the minimum weight over all paths from
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") to
![j](http://chart.apis.google.com/chart?cht=tx&chl=j "j") of length
![\\le
k](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20k "\le k").

Answers: ![D[i, j,
n-1]](http://chart.apis.google.com/chart?cht=tx&chl=D%5Bi%2C%20j%2C%20n-1%5D "D[i, j, n-1]")
for all ![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i"),
![j](http://chart.apis.google.com/chart?cht=tx&chl=j "j")

Base Case:

\
![\\begin{aligned} D[i, j, 0] &= \\left\\{ \\begin{array}{lr} 0 & l = j
\\\\ \\infty & \\text{ otherwise } \\end{array} \\right.
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20D%5Bi%2C%20j%2C%200%5D%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%200%20%26%20l%20%3D%20j%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cinfty%20%26%20%5Ctext%7B%20otherwise%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    D[i, j, 0] &=
                    \left\{
                        \begin{array}{lr}
                            0 & l = j \\
                            \infty & \text{ otherwise }
                        \end{array}
                    \right.
                \end{aligned}")\

Recursive Formula:

\
![\\begin{aligned} D[i, j, k] &= \\min\_{\\ell \\in \\{ 1 \\ldots n \\}}
D[i, \\ell, k-1] + w(i, j)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20D%5Bi%2C%20j%2C%20k%5D%20%26%3D%20%5Cmin_%7B%5Cell%20%5Cin%20%5C%7B%201%20%5Cldots%20n%20%5C%7D%7D%20D%5Bi%2C%20%5Cell%2C%20k-1%5D%20%2B%20w%28i%2C%20j%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    D[i, j, k] &= \min_{\ell \in \{ 1 \ldots n \}} D[i, \ell, k-1] + w(i, j)
                \end{aligned}")\

Evaluate in increasing
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k").

                        for i = 1...n
                            for j = 1...n
                                for k = 0...n-1
                                    ...
                    

There are
![\\Theta(n\^3)](http://chart.apis.google.com/chart?cht=tx&chl=%5CTheta%28n%5E3%29 "\Theta(n^3)")
entries, each one takes
![\\Theta(n)](http://chart.apis.google.com/chart?cht=tx&chl=%5CTheta%28n%29 "\Theta(n)")
time. Overall, it is
![\\Theta(n\^4)](http://chart.apis.google.com/chart?cht=tx&chl=%5CTheta%28n%5E4%29 "\Theta(n^4)")
time.

#### DP \# 2

Same setup as DP \# 1, but only ![k = \\{1, 2, 4, 8, ... (n-1) \\text{'s
next power of 2}
\\}](http://chart.apis.google.com/chart?cht=tx&chl=k%20%3D%20%5C%7B1%2C%202%2C%204%2C%208%2C%20...%20%28n-1%29%20%5Ctext%7B%27s%20next%20power%20of%202%7D%20%5C%7D "k = \{1, 2, 4, 8, ... (n-1) \text{'s next power of 2} \}")

We choose the middle vertex
![\\ell](http://chart.apis.google.com/chart?cht=tx&chl=%5Cell "\ell"),
then join things together:

Recursive formula:

\
![\\begin{aligned} D[i, j, k] &= \\min\_{\\ell \\in \\{ 1 \\ldots n \\}}
\\{ D[i, \\ell, k/2] + D[\\ell, j, k/2] \\}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20D%5Bi%2C%20j%2C%20k%5D%20%26%3D%20%5Cmin_%7B%5Cell%20%5Cin%20%5C%7B%201%20%5Cldots%20n%20%5C%7D%7D%20%5C%7B%20D%5Bi%2C%20%5Cell%2C%20k%2F2%5D%20%2B%20D%5B%5Cell%2C%20j%2C%20k%2F2%5D%20%5C%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    D[i, j, k] &= \min_{\ell \in \{ 1 \ldots n \}} \{ D[i, \ell, k/2] + D[\ell, j, k/2] \}
                \end{aligned}")\

There are ![\\Theta(n\^2 \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=%5CTheta%28n%5E2%20%5Clog%20n%29 "\Theta(n^2 \log n)")
entries, each one takes
![\\Theta(n)](http://chart.apis.google.com/chart?cht=tx&chl=%5CTheta%28n%29 "\Theta(n)")
time to compute. Overall, ![\\Theta(n\^3 \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=%5CTheta%28n%5E3%20%5Clog%20n%29 "\Theta(n^3 \log n)")
time.

#### Floyd-Warshall Algorithm

This is another DP variant.

Subproblems: ![D[i, j,
k]](http://chart.apis.google.com/chart?cht=tx&chl=D%5Bi%2C%20j%2C%20k%5D "D[i, j, k]")
minimum weight over all paths
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") to
![j](http://chart.apis.google.com/chart?cht=tx&chl=j "j") with only
intermediate vertices in ![\\{ 1 \\ldots k
\\}](http://chart.apis.google.com/chart?cht=tx&chl=%5C%7B%201%20%5Cldots%20k%20%5C%7D "\{ 1 \ldots k \}").

Answers: ![D[i, j,
n]](http://chart.apis.google.com/chart?cht=tx&chl=D%5Bi%2C%20j%2C%20n%5D "D[i, j, n]")
for any vertices ![{\\ensuremath{\\left \\langle i, j \\right \\rangle
}}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20i%2C%20j%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle i, j \right \rangle }}").

Base Case:

\
![\\begin{aligned} D[i, j, 0] &= \\left\\{ \\begin{array}{lr} w(i, j) &
i \\ne j \\\\ 0 & i = j \\end{array} \\right.
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20D%5Bi%2C%20j%2C%200%5D%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20w%28i%2C%20j%29%20%26%20i%20%5Cne%20j%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%200%20%26%20i%20%3D%20j%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    D[i, j, 0] &=
                        \left\{
                            \begin{array}{lr}
                                w(i, j) & i \ne j \\
                                0 & i = j
                            \end{array}
                        \right.
                \end{aligned}")\

Recursive formula:

\
![\\begin{aligned} D[i, j, k] &= \\min \\{ D[i, j, k-1], D[i, k, k-1] +
D[k, j, k-1] \\}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20D%5Bi%2C%20j%2C%20k%5D%20%26%3D%20%5Cmin%20%5C%7B%20D%5Bi%2C%20j%2C%20k-1%5D%2C%20D%5Bi%2C%20k%2C%20k-1%5D%20%2B%20D%5Bk%2C%20j%2C%20k-1%5D%20%5C%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    D[i, j, k] &= \min \{ D[i, j, k-1], D[i, k, k-1] + D[k, j, k-1] \}
                \end{aligned}")\

i.e. the minimum of the path that doesn’t use
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") and the path
from ![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") to
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") plus the
minimal path ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")
to ![j](http://chart.apis.google.com/chart?cht=tx&chl=j "j").

The iteration order will be weird (increasing
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")). I don’t have
it written down, but would need to think about it.

Every edge takes
![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)")
time to compute, there are
![O(n\^3)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E3%29 "O(n^3)")
edges. I suppose this takes
![O(n\^3)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E3%29 "O(n^3)")
time overall.

NP/P/etc
========

Theory of NP-Completeness
-------------------------

All I have written down is that proving problems is hard.

I’ll describe NP-Completness later in the NP-Completness section.

Problem Specifications
----------------------

### Decision Problem

Decision Problems are problems that output “yes/no” answers.

### Search Problems

Search Problems are problems that determine the existence of at least
one solution to a given problem.

Definition of P
---------------

Class ![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") is the
class of “easy”/“tractable” problems.

![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") is the set of
problems that are solveable in worst-case polynomial time i.e.
![O(n\^d)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5Ed%29 "O(n^d)")
for some constant
![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d"). We require
that ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is a
reasonable representation of the input size, measured in bits.

Definition of NP
----------------

Class ![NP](http://chart.apis.google.com/chart?cht=tx&chl=NP "NP") is
the class of “hard”/“intractable” problems.

![NP](http://chart.apis.google.com/chart?cht=tx&chl=NP "NP") is the set
of problems that have solutions that are verifiable in
![O(n\^d)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5Ed%29 "O(n^d)")
time for some constant
![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d"). We require
that ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is a
reasonable representation of the input size, measured in bits.

All decision problems that can be expressed in the form:

-   ![{\\ensuremath{\\left \\langle x \\right \\rangle
    }}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20x%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle x \right \rangle }}")

-   “yes” iff there exists an object
    ![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y") such that
    property ![R(x,
    y)](http://chart.apis.google.com/chart?cht=tx&chl=R%28x%2C%20y%29 "R(x, y)")
    holds.

    Where:

    1.  ![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y") has
        polynomial size

    2.  ![R(x,
        y)](http://chart.apis.google.com/chart?cht=tx&chl=R%28x%2C%20y%29 "R(x, y)")
        can be verified in polynomial time.

    We call ![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y")
    the certificate, and evaluating
    ![R](http://chart.apis.google.com/chart?cht=tx&chl=R "R")
    verification.

    NP
    ![\\leftrightarrow](http://chart.apis.google.com/chart?cht=tx&chl=%5Cleftrightarrow "\leftrightarrow")
    “Non-Deterministic Polynomial”

P vs NP vs EXPTIME
------------------

\
![\\begin{aligned} P \\subseteq NP \\subseteq EXPTIME
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20P%20%5Csubseteq%20NP%20%5Csubseteq%20EXPTIME%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            P \subseteq NP \subseteq EXPTIME
        \end{aligned}")\

EXPTIME is the set of problems solveable in
![O(2\^{n\^d})](http://chart.apis.google.com/chart?cht=tx&chl=O%282%5E%7Bn%5Ed%7D%29 "O(2^{n^d})")
time.

Proving (or disproving) that ![P =
NP](http://chart.apis.google.com/chart?cht=tx&chl=P%20%3D%20NP "P = NP")
is a million dollar proof.

Polynomial-time reductions
--------------------------

To prove that problems are equivalently hard, we want to provide
polynomial-time “reductions” from one type of problem to another.

We can say that
![L\_1](http://chart.apis.google.com/chart?cht=tx&chl=L_1 "L_1")
polynomial-time reduces to
![L\_2](http://chart.apis.google.com/chart?cht=tx&chl=L_2 "L_2") if
arbitrary instances of problem
![L\_1](http://chart.apis.google.com/chart?cht=tx&chl=L_1 "L_1") can be
solved using polynomial time computational steps, plus polynomial calls
to an oracle that solves
![L\_2](http://chart.apis.google.com/chart?cht=tx&chl=L_2 "L_2").

We say that ![L\_1 \\le\_p
L\_2](http://chart.apis.google.com/chart?cht=tx&chl=L_1%20%5Cle_p%20L_2 "L_1 \le_p L_2")
if there is a polynomial time function
![f](http://chart.apis.google.com/chart?cht=tx&chl=f "f") so that
![L\_1](http://chart.apis.google.com/chart?cht=tx&chl=L_1 "L_1") on
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x") is a “yes” iff
output of
![L\_2](http://chart.apis.google.com/chart?cht=tx&chl=L_2 "L_2") on
![f(x)](http://chart.apis.google.com/chart?cht=tx&chl=f%28x%29 "f(x)")
is “yes”.

NP-Completeness
---------------

NP-Complete problems are a set of NP problems that all polynomial-reduce
to each other. The implications of proving that one of these problems is
in P would mean that ![P =
NP](http://chart.apis.google.com/chart?cht=tx&chl=P%20%3D%20NP "P = NP").

The requirement for NP-Completeness seems pretty trivial, which makes it
easier for us to prove.

\
![\\begin{aligned} L &\\in NP \\\\ L\_0 \\le\_p L
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20L%20%26%5Cin%20NP%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20L_0%20%5Cle_p%20L%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            L &\in NP \\
            L_0 \le_p L
        \end{aligned}")\

If ![L\_0](http://chart.apis.google.com/chart?cht=tx&chl=L_0 "L_0") is
known to be NP-Complete, then
![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") is NP-Complete
too.

### Proving NP-Completeness

SAT (Cook-Levin theorem)
------------------------

SAT to 3SAT
-----------

3SAT to independent set/vertex cover/clique
-------------------------------------------

Vertex cover to Hamiltonian cycle/traveling salesman
----------------------------------------------------

Vertex cover to subset sum/knapsack
-----------------------------------

Beyond NP
---------

### Halting Problem

### Turing’s theorem
