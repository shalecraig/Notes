---
generator: pandoc
title: CS 466 F13
...

Introduction {#cha:introduction}
============

In this course, we want to solve algorithmic problems, and compounding
general knowledge with developments of the last 30 years. Though these
notes are grouped by lecture, this course can be split into three
sections:

1.  Algorithmic Design

    -   Assumed knowledge of greedy, divide & conquer, and dynamic
        programming techniques

    -   Introduction to randomization, approximation, and online
        algorithmic techniques

2.  Algorithmic Analysis

    -   Assumed knowledge of big
        ![O](http://chart.apis.google.com/chart?cht=tx&chl=O "O"), worst
        case asymptotic analysis techniques

    -   Introduction to amortized analysis, probabilistic analysis, and
        approximation factors methods

3.  Lower Bounds

    -   Understanding of NP-complete-ness is assumed

    -   Hardness of approximation is introduced

The class website is
[https://www.student.cs.uwaterloo.ca/\~cs466/](https://www.student.cs.uwaterloo.ca/~cs466/).

TSP {#sec:tsp}
---

### Problem Statement {#sub:problem_statement}

Given a graph ![G = (V,
E)](http://chart.apis.google.com/chart?cht=tx&chl=G%20%3D%20%28V%2C%20E%29 "G = (V, E)")
with weights on edges ![w : E \\to
R](http://chart.apis.google.com/chart?cht=tx&chl=w%20%3A%20E%20%5Cto%20R "w : E \to R"),
find a [^1^](#fn1), which is a Hamiltonian Tour[^2^](#fn2)
![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") that visits
each vertex exactly once and has minimum weight: \
![\\sum\_{e \\in C}
w(e)](http://chart.apis.google.com/chart?cht=tx&chl=%5Csum_%7Be%20%5Cin%20C%7D%20w%28e%29 "\sum_{e \in C} w(e)")\

Since we can add infinite-weight edges to any non-complete graph, we
assume that we have a complete graph[^3^](#fn3).

TSP is a known NP-completeproblem.

### NP-complete {#sub:npcomplete}

To show a problem
![R](http://chart.apis.google.com/chart?cht=tx&chl=R "R") is
NP-complete, we need to show that both:

1.  Prove ![R](http://chart.apis.google.com/chart?cht=tx&chl=R "R") is
    in NP.

2.  Give a reduction (denoted
    “![\\le\_p](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle_p "\le_p")”)
    from a known NP-completeproblem to an instance of the
    ![R](http://chart.apis.google.com/chart?cht=tx&chl=R "R") problem.

Thus to prove that TSP is NP-complete, we need to show both:

-   TSP is in NP

-   Hamiltonian Cycle
    ![\\le\_p](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle_p "\le_p")
    TSP.

Assuming that Hamiltonian Cycle in our reduction is a known
NP-completeproblem, we now know that TSP is NP-completetoo.

Unless ![{\\textsc{P}\\xspace}=
{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}= {\textsc{NP}\xspace}"),
we need to choose two of these three options:

-   A *speedy* algorithm

-   Solve the *problem precisely*

-   Solve a *hard problem*

NP-completeproblems are hard, so we must choose between *precision* and
*speed* when solving them.

Metric TSP {#sec:metric_tsp}
----------

We define Metric TSP as a weaker variant of TSP where the distance
between two vertexes is the same in either order, and distances always
follows the triangle inequality.

\
![\\begin{aligned} d(u, v) &= d(v, u) \\\\ d(u, v) &\\le d(u, \\beta) +
d(\\beta, v)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20d%28u%2C%20v%29%20%26%3D%20%20%20d%28v%2C%20u%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20d%28u%2C%20v%29%20%26%5Cle%20d%28u%2C%20%5Cbeta%29%20%2B%20d%28%5Cbeta%2C%20v%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    d(u, v) &=   d(v, u) \\
                    d(u, v) &\le d(u, \beta) + d(\beta, v)
                \end{aligned}")\

There exists a fast approximation algorithm that exists for this
problem:

-   Find minimum-spanning tree (see
    Chapter [cha:minimum~s~panning~t~rees] for more information) of the
    graph using [Kruskal’s
    Algorithm](https://en.wikipedia.org/wiki/Kruskal's_algorithm) (![O(m
    \\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%20%5Clog%20n%29 "O(m \log n)")).

-   Take a tour walking around the tree, taking shortcuts to avoid
    re-visiting vertexes

-   The distance added by the shortcuts is less than or equal to twice
    the distance of remaining in the tree.

Here’s a quick proof to this lemma: In a given graph, call
![\\ell](http://chart.apis.google.com/chart?cht=tx&chl=%5Cell "\ell")
the length of the tour of our algorithm, and call
![\\ell\_{TSP}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cell_%7BTSP%7D "\ell_{TSP}")
the distance traveled in the minimal TSP tour.

We want to prove that ![\\ell \\le 2
\\ell\_{TSP}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cell%20%5Cle%202%20%5Cell_%7BTSP%7D "\ell \le 2 \ell_{TSP}"),
so that this is a
![2](http://chart.apis.google.com/chart?cht=tx&chl=2 "2")-approximation
(For more information, see Chapter [cha:approximation~a~lgorithms]).

We know that ![\\ell \\le 2 \\ell\_{MST} \\le 2
\\ell\_{TSP}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cell%20%5Cle%202%20%5Cell_%7BMST%7D%20%5Cle%202%20%5Cell_%7BTSP%7D "\ell \le 2 \ell_{MST} \le 2 \ell_{TSP}")
since deleting one edge of a minimum TSP tour gives us a spanning tree.

**Sidenote:** There exists a
![1.5](http://chart.apis.google.com/chart?cht=tx&chl=1.5 "1.5")
approximation, but there were no specifics given in class. The
apparently, the idea is to use a matching algorithm.

### Implementation {#sub:implementation}

-   We must find a minimum spanning tree, which takes ![O(m\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%5Clog%20n%29 "O(m\log n)")
    time using Prim and Kruskal’s Algorithm.

    ![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m")
    :   is the number of edges.

    ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")
    :   is the number of vertexes.

-   We will see improved heaps in this class that allow us to take the
    time down to ![O(m + n \\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%20%2B%20n%20%5Clog%20n%29 "O(m + n \log n)")

This method doesn’t work for General TSP, since if there exists a
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")-approximation,
then
![{\\textsc{P}\\xspace}={\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%3D%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}={\textsc{NP}\xspace}")[^4^](#fn4).

Types of TSP {#sec:types_of_tsp}
------------

In general, the ordering is from hardest to easiest:

General TSP
![\\ge](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge "\ge")
Metric TSP
![\\ge](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge "\ge")
Euclidean TSP

General
:   is the basic “general” TSP problem.

Metric
:   is described above [^5^](#fn5).

Euclidean
:   is where vertexes are placed on a plane, and the weight of edges is
    the euclidean distance between vertexes [^6^](#fn6).

Every algorithm must store, access, or search data. We look at amortized
analysis and more complicated data structures these data structures.

It’s assumed knowledge of the following:

-   Heap-based priority queue

-   Dictionaries built using hashing, and balanced binary search.

Binomial Heaps {#cha:binomial_heaps}
==============

Heaps {#sec:heaps}
-----

Heaps store are binary trees of elements, each with an numeric key. For
a minimum heap, the minimum key is the root. Usually, we shape our heap
as a near-perfect triangle, so we can store an array in level order and
use indexing instead of pointers. The height of a heap is
![\\theta(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28%5Clog%20n%29 "\theta(\log n)").

We have five main operations in priority queues:

Insert
:   inserts at the bottom, and bubbles up - ![\\theta(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28%5Clog%20n%29 "\theta(\log n)")

Delete Minimum
:   remove the root element, put the last item there, and bubble down. -
    ![\\theta(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28%5Clog%20n%29 "\theta(\log n)")

Decrement Key
:   bubble the item up (or down) -
    ![\\theta(n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28n%29 "\theta(n)")

Build
:   can be done faster than repeated insertion -
    ![\\theta(n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28n%29 "\theta(n)")

Merge
:   merge two heaps into one heap -
    ![\\theta(n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28n%29 "\theta(n)")

Prim’s Algorithm {#sec:prim_s_algorithm}
----------------

Prim’s Algorithm finds the **Minimum Spanning Tree** of a graph.

Start with one node ![s \\in
V](http://chart.apis.google.com/chart?cht=tx&chl=s%20%5Cin%20V "s \in V").

    remaining = V
    while |remaining| > 0:
        e_connecting, v_connected = heap.popMin()
        answer.put(e_connecting)
        remaining.remove(v_connected)
        heap.updateWeights(v_connected)
    return answer
                    

We define ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") as
the number of edges, and
![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m") is the number
of edges. ![m =
O(n\^2)](http://chart.apis.google.com/chart?cht=tx&chl=m%20%3D%20O%28n%5E2%29 "m = O(n^2)").

We can implement this two ways.

-   If we store a heap of edges ordered by weight, this takes
    ![n\\text{DeleteMin} + m(\\text{Insert} + \\text{Delete}) = O((n+m)
    \\log
    m)](http://chart.apis.google.com/chart?cht=tx&chl=n%5Ctext%7BDeleteMin%7D%20%2B%20m%28%5Ctext%7BInsert%7D%20%2B%20%5Ctext%7BDelete%7D%29%20%3D%20O%28%28n%2Bm%29%20%5Clog%20m%29 "n\text{DeleteMin} + m(\text{Insert} + \text{Delete}) = O((n+m) \log m)")
    time.

-   If we store a heap of vertexes, this takes ![n \\text{DeleteMin} + m
    \\text{DecreaseKey} = O((n+m) \\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=n%20%5Ctext%7BDeleteMin%7D%20%2B%20m%20%5Ctext%7BDecreaseKey%7D%20%3D%20O%28%28n%2Bm%29%20%5Clog%20n%29 "n \text{DeleteMin} + m \text{DecreaseKey} = O((n+m) \log n)")
    time.

For now, these are the same[^7^](#fn7). Once we implement different
heaps, this difference becomes relevant.

Binomial Heap {#sec:binomial_heap}
-------------

We can improve the merge speed of our “standard” heaps by using pointers
(where each node has any number of children) instead of an array to
implement the heaps.

We keep the heap order, but we go beyond the fact that the heaps are
made of trees.

Binomial Tree {#sec:binomial_tree}
-------------

We define binomial trees as follows:

The root of
![B\_0](http://chart.apis.google.com/chart?cht=tx&chl=B_0 "B_0") is a
single vertex with no children.

The root of
![B\_1](http://chart.apis.google.com/chart?cht=tx&chl=B_1 "B_1") is the
root of a
![B\_0](http://chart.apis.google.com/chart?cht=tx&chl=B_0 "B_0") with an
additional
![B\_0](http://chart.apis.google.com/chart?cht=tx&chl=B_0 "B_0") root
vertex attached.

The root of
![B\_2](http://chart.apis.google.com/chart?cht=tx&chl=B_2 "B_2") is the
root of a
![B\_1](http://chart.apis.google.com/chart?cht=tx&chl=B_1 "B_1") with an
additional
![B\_1](http://chart.apis.google.com/chart?cht=tx&chl=B_1 "B_1") root
vertex attached.

The root of
![B\_k](http://chart.apis.google.com/chart?cht=tx&chl=B_k "B_k") is the
root of a
![B\_{k-1}](http://chart.apis.google.com/chart?cht=tx&chl=B_%7Bk-1%7D "B_{k-1}")
tree with an additional
![B\_{k-1}](http://chart.apis.google.com/chart?cht=tx&chl=B_%7Bk-1%7D "B_{k-1}")
root vertex as a child of the root vertex.

![Sample Binomial Heaps](images/binomial_tree.png "fig:")
[fig:binomial~h~eap]

There are a few properties of Binomial Heaps we know about[^8^](#fn8):

Size
:   of a
    ![B\_k](http://chart.apis.google.com/chart?cht=tx&chl=B_k "B_k") is
    ![2\^k](http://chart.apis.google.com/chart?cht=tx&chl=2%5Ek "2^k").

Height
:   of a
    ![B\_k](http://chart.apis.google.com/chart?cht=tx&chl=B_k "B_k") is
    ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k"), defined
    in the number of edges from the root to a leaf vertex.

Width of level
:   ![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") of a
    ![B\_k](http://chart.apis.google.com/chart?cht=tx&chl=B_k "B_k") is
    ![ {k \\choose
    i})](http://chart.apis.google.com/chart?cht=tx&chl=%20%7Bk%20%5Cchoose%20i%7D%29 " {k \choose i})").

    This is since ![{k \\choose i} = {{k-1} \\choose i} + {{k-1}
    \\choose
    {i-1}}](http://chart.apis.google.com/chart?cht=tx&chl=%7Bk%20%5Cchoose%20i%7D%20%3D%20%7B%7Bk-1%7D%20%5Cchoose%20i%7D%20%2B%20%7B%7Bk-1%7D%20%5Cchoose%20%7Bi-1%7D%7D "{k \choose i} = {{k-1} \choose i} + {{k-1} \choose {i-1}}")

Binomial Heaps {#sec:binomial_heaps}
--------------

To create binomial trees of arbitrary heights, we need to start using
forests of binomial trees.

We can represent ![n = 13 = 0b1101 = 2\^0 + 2\^2 +
2\^3](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3D%2013%20%3D%200b1101%20%3D%202%5E0%20%2B%202%5E2%20%2B%202%5E3 "n = 13 = 0b1101 = 2^0 + 2^2 + 2^3")
elements as a
![B\_0](http://chart.apis.google.com/chart?cht=tx&chl=B_0 "B_0"),
![B\_2](http://chart.apis.google.com/chart?cht=tx&chl=B_2 "B_2"), and a
![B\_3](http://chart.apis.google.com/chart?cht=tx&chl=B_3 "B_3").

In general, for
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") elements, use
![\\log
n](http://chart.apis.google.com/chart?cht=tx&chl=%5Clog%20n "\log n")
trees.

Most of our operations on this will be through a series of merges.

Merge
:   works like binary addition
    (![\\theta(1)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%281%29 "\theta(1)"))
    across the trees, so the cost is the same as the bit cost of
    addition - ![\\theta(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28%5Clog%20n%29 "\theta(\log n)")

Insert
:   is a merge of the pre-existing forest and a
    ![B\_0](http://chart.apis.google.com/chart?cht=tx&chl=B_0 "B_0")
    tree - ![\\theta(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28%5Clog%20n%29 "\theta(\log n)")
    worst-case[^9^](#fn9)

Delete Minimum
:   is done by finding the smallest tree, breaking removing the root
    vertex, and merging those to the remaining untouched trees -
    ![\\theta(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28%5Clog%20n%29 "\theta(\log n)")

Decrease Key
:   is done inside a binomial tree as a standard “bubble up”, so the
    effect is limited to the height of the individual - ![\\theta(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28%5Clog%20n%29 "\theta(\log n)")

Build Binomial Heap
:   can be done by repeated insertion in
    ![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")
    time.

Amortized Analysis {#cha:amortized_analysis}
==================

Example For Binomial Heaps {#sec:example_for_binomial_heaps}
--------------------------

Binomial heaps take ![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")
time to merge. Let’s prove that.

We want to determine the bit cost for incrementing a binary counter from
![0](http://chart.apis.google.com/chart?cht=tx&chl=0 "0") to
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n").

### Worst-Case Analysis {#sub:worst_case_analysis}

The worst-case cost of one increment on a
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")-bit counter is
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k"), so
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") increments
cost ![O(n \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Clog%20n%29 "O(n \log n)")
(![\\log
n](http://chart.apis.google.com/chart?cht=tx&chl=%5Clog%20n "\log n")
bits flipped ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")
times).

### Amortized Analysis {#sub:amortized_analysis}

We can get a better bound.

-   The
    ![2\^0](http://chart.apis.google.com/chart?cht=tx&chl=2%5E0 "2^0")
    bit flips every time -
    ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")

-   The
    ![2\^1](http://chart.apis.google.com/chart?cht=tx&chl=2%5E1 "2^1")
    bit flips every other time -
    ![\\frac{n}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7Bn%7D%7B2%7D "\frac{n}{2}")

-   The
    ![2\^2](http://chart.apis.google.com/chart?cht=tx&chl=2%5E2 "2^2")
    bit flips every 4th time -
    ![\\frac{n}{4}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7Bn%7D%7B4%7D "\frac{n}{4}")

-   etc.

The total cost is:

\
![\\begin{aligned} \\sum\_{i=0}\^k \\frac{n}{2\^i} \\le 2n
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Csum_%7Bi%3D0%7D%5Ek%20%5Cfrac%7Bn%7D%7B2%5Ei%7D%20%5Cle%202n%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \sum_{i=0}^k \frac{n}{2^i} \le 2n
                    \end{aligned}")\

Thus, the average cost of incrementing a counter is ![\\frac{2n}{n} =
2](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B2n%7D%7Bn%7D%20%3D%202 "\frac{2n}{n} = 2").

Since binomial heap appending is representable with a bit cost of a
binary counter, the total cost for making a binomial heap is
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)").

An Amortized Definition {#sec:an_amortized_definition}
-----------------------

Given a sequence of
![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m") operations
with total cost
![T(m)](http://chart.apis.google.com/chart?cht=tx&chl=T%28m%29 "T(m)"),
then the **amortized cost** per operation is
![\\frac{T(m)}{m}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7BT%28m%29%7D%7Bm%7D "\frac{T(m)}{m}").

Potential Method for Amortized Analysis {#sec:potential_method_for_amortized_analysis}
---------------------------------------

The idea for this method is that we are keeping an account of (time)
cost.

Keeping track of a “potential-time” bank account, we keep track of the
amortized difference between true of operations and a expected for all
operations.

We call the bank balance after the
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i")th operation
![\\Phi\_i](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_i "\Phi_i").

-   Cost is true.

-   Charge is artificial.

\
![\\begin{aligned} \\Phi\_i &= \\Phi\_{i-1} + \\text{charge}(i) -
\\text{cost}(i)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5CPhi_i%20%26%3D%20%5CPhi_%7Bi-1%7D%20%2B%20%5Ctext%7Bcharge%7D%28i%29%20-%20%5Ctext%7Bcost%7D%28i%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \Phi_i &= \Phi_{i-1} + \text{charge}(i) - \text{cost}(i)
                \end{aligned}")\

Since the potential
(![\\Phi\_i](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_i "\Phi_i"))
and charge are artificial, we define them to make analysis easy.

It’s much simpler to define potential to get the charge:

\
![\\begin{aligned} \\text{charge}(i) &= \\text{cost}(i) + \\Phi\_i -
\\Phi\_{i-1}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7Bcharge%7D%28i%29%20%26%3D%20%5Ctext%7Bcost%7D%28i%29%20%2B%20%5CPhi_i%20-%20%5CPhi_%7Bi-1%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \text{charge}(i) &= \text{cost}(i) + \Phi_i - \Phi_{i-1}
                \end{aligned}")\

If the final potential is
![\\ge](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge "\ge") than
the initial potential, then the amortized cost is
![\\le](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle "\le") max
charge.

\
![\\begin{aligned} \\sum\_{i=1}\^m \\text{charge}(i) &= \\sum\_{i=1}\^m
\\text{cost}(i) + \\sum\_{i=1}\^m \\Phi\_i - \\sum\_{i=0}\^{m-1}
\\Phi\_i \\\\ &= \\sum\_{i=1}\^m \\text{cost}(i) + \\Phi\_m - \\Phi\_0
\\\\ \\Phi\_m - \\Phi\_0 \\ge0 &\\implies \\sum \\text{charge}(i) \\ge
\\sum \\text{cost}(i) \\\\ \\text{amortized cost} &= \\sum
\\frac{\\text{cost}(i)}{m} \\\\ &\\le \\sum \\frac{\\text{charge}(i)}{m}
\\\\ &\\le \\text{max charge}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Csum_%7Bi%3D1%7D%5Em%20%5Ctext%7Bcharge%7D%28i%29%20%26%3D%20%5Csum_%7Bi%3D1%7D%5Em%20%5Ctext%7Bcost%7D%28i%29%20%2B%20%5Csum_%7Bi%3D1%7D%5Em%20%5CPhi_i%20-%20%5Csum_%7Bi%3D0%7D%5E%7Bm-1%7D%20%5CPhi_i%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_%7Bi%3D1%7D%5Em%20%5Ctext%7Bcost%7D%28i%29%20%2B%20%5CPhi_m%20-%20%5CPhi_0%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5CPhi_m%20-%20%5CPhi_0%20%5Cge0%20%26%5Cimplies%20%5Csum%20%5Ctext%7Bcharge%7D%28i%29%20%5Cge%20%5Csum%20%5Ctext%7Bcost%7D%28i%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7Bamortized%20cost%7D%20%26%3D%20%5Csum%20%5Cfrac%7B%5Ctext%7Bcost%7D%28i%29%7D%7Bm%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20%5Csum%20%5Cfrac%7B%5Ctext%7Bcharge%7D%28i%29%7D%7Bm%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20%5Ctext%7Bmax%20charge%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \sum_{i=1}^m \text{charge}(i) &= \sum_{i=1}^m \text{cost}(i) + \sum_{i=1}^m \Phi_i - \sum_{i=0}^{m-1} \Phi_i \\
                    &= \sum_{i=1}^m \text{cost}(i) + \Phi_m - \Phi_0 \\
                    \Phi_m - \Phi_0 \ge0 &\implies \sum \text{charge}(i) \ge \sum \text{cost}(i) \\
                    \text{amortized cost} &= \sum \frac{\text{cost}(i)}{m} \\
                    &\le \sum \frac{\text{charge}(i)}{m} \\
                    &\le \text{max charge}
                \end{aligned}")\

### Potential Analysis in a Nutshell {#sub:potential_analysis_in_a_nutshell}

We need to invent a
![\\text{potential}(i)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctext%7Bpotential%7D%28i%29 "\text{potential}(i)")
and a
![\\text{charge}(i)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctext%7Bcharge%7D%28i%29 "\text{charge}(i)")
and prove that ![\\Phi\_m \\ge
\\Phi\_0](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_m%20%5Cge%20%5CPhi_0 "\Phi_m \ge \Phi_0").

A goal when inventing potential and charge is to prove that max charge
is small, since the amortized cost is less than or equal to the maximum
charged.

\
![\\begin{aligned} \\text{charge}(i) &= \\text{cost}(i) + \\Phi\_i -
\\Phi\_{i-1}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7Bcharge%7D%28i%29%20%26%3D%20%5Ctext%7Bcost%7D%28i%29%20%2B%20%5CPhi_i%20-%20%5CPhi_%7Bi-1%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \text{charge}(i) &= \text{cost}(i) + \Phi_i - \Phi_{i-1}
                    \end{aligned}")\

### Binary Counters Using the Potential Method {#sub:binary_counters_using_the_potential_method}

We know that only one bit will undergo ![0 \\to
1](http://chart.apis.google.com/chart?cht=tx&chl=0%20%5Cto%201 "0 \to 1")
in a given increment.

The cost is high when ![1 \\to
0](http://chart.apis.google.com/chart?cht=tx&chl=1%20%5Cto%200 "1 \to 0")
occurs many times. Let’s pay for ![0 \\to
1](http://chart.apis.google.com/chart?cht=tx&chl=0%20%5Cto%201 "0 \to 1")
and an extra \$1 for when this bit eventually flips ![1 \\to
0](http://chart.apis.google.com/chart?cht=tx&chl=1%20%5Cto%200 "1 \to 0").

Thus, ![\\text{charge}(i) =
2](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctext%7Bcharge%7D%28i%29%20%3D%202 "\text{charge}(i) = 2").

By theorem, the amortized cost
![\\le](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle "\le") max
charge ![=2](http://chart.apis.google.com/chart?cht=tx&chl=%3D2 "=2"),
so long as ![\\Phi\_m \\ge
\\Phi\_0](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_m%20%5Cge%20%5CPhi_0 "\Phi_m \ge \Phi_0").

Formally, we’d like to specify the relation between
![\\text{charge}(i)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctext%7Bcharge%7D%28i%29 "\text{charge}(i)")
and
![\\Phi\_i](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_i "\Phi_i").

We make a jump here that
![\\Phi\_i](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_i "\Phi_i")
is the number of
![1](http://chart.apis.google.com/chart?cht=tx&chl=1 "1")s in the
counter after the
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i")th operation.

Supposing the
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i")th operation
changes ![t\_i](http://chart.apis.google.com/chart?cht=tx&chl=t_i "t_i")
bits
![1\\to0](http://chart.apis.google.com/chart?cht=tx&chl=1%5Cto0 "1\to0"),
and ![1](http://chart.apis.google.com/chart?cht=tx&chl=1 "1") bit
![0\\to1](http://chart.apis.google.com/chart?cht=tx&chl=0%5Cto1 "0\to1").

Then we have:

\
![\\begin{aligned} \\text{cost}(i) &= t\_i + 1 \\\\ \\Phi\_i &=
\\Phi\_{i-1} - t\_i + 1 \\\\ \\text{charge}(i) &= \\text{cost}(i) +
\\Phi\_i - \\Phi\_{i-1} \\\\ &= t\_i + 1 - t\_i - 1 \\\\ &= 2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7Bcost%7D%28i%29%20%26%3D%20t_i%20%2B%201%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5CPhi_i%20%26%3D%20%5CPhi_%7Bi-1%7D%20-%20t_i%20%2B%201%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7Bcharge%7D%28i%29%20%26%3D%20%5Ctext%7Bcost%7D%28i%29%20%2B%20%5CPhi_i%20-%20%5CPhi_%7Bi-1%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20t_i%20%2B%201%20-%20t_i%20-%201%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%202%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \text{cost}(i) &= t_i + 1 \\
                        \Phi_i &= \Phi_{i-1} - t_i + 1 \\
                        \text{charge}(i) &= \text{cost}(i) + \Phi_i - \Phi_{i-1} \\
                        &= t_i + 1 - t_i - 1 \\
                        &= 2
                    \end{aligned}")\

Thus, ![\\Phi\_0 =
0](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_0%20%3D%200 "\Phi_0 = 0"),
and ![\\Phi\_m \\ge
0](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_m%20%5Cge%200 "\Phi_m \ge 0"),
so the theorem applies.

Mergeable Heaps {#sec:mergeable_heaps}
---------------

There’s a family of heaps who’s main operation is a `merge`.

[h]

l | c | c | c & Binomial Heap & Lazy Binomial Heap & Fibonacci Heap\

insert & ![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")
& ![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)")
&
![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)")\
delete min & ![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")
& A ![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")
& A ![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")\
merge & ![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")
& ![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)")
&
![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)")\
decrease key & ![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")
& ![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")
& A
![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)")\
build &
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)") &
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)") &
![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)")\

### Lazy Binomial Heaps {#sub:lazy_binomial_heaps}

We can improve merge an insert by lazily combining trees during `insert`
and `merge` operations. We catch up on work when performing a
`delete min` operation to have exactly one tree of each rank.

#### Implementing Delete-Min {#ssub:implementing_delete_min}

-   Look at all roots to find the min

-   Delete that root, its children become separate

-   Consolidate ranks from smallest to largest

The wost case cost of `delete min` is
![\\theta(n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28n%29 "\theta(n)"),
with ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") singleton
trees.

#### Amortized Analysis of Delete Min {#ssub:amortized_analysis_of_delete_min}

We theorize that Lazy Binomial Heaps have A ![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")
cost for `delete min`.

By *magic*, we pick
![\\Phi](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi "\Phi") to
represent the number of trees. Thus, ![\\Phi\_0 =
0](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_0%20%3D%200 "\Phi_0 = 0"),
and ![\\Phi\_m \\ge
0](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_m%20%5Cge%200 "\Phi_m \ge 0"),
so ![\\Phi\_m \\ge
\\Phi\_0](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_m%20%5Cge%20%5CPhi_0 "\Phi_m \ge \Phi_0").

We know that ![\\text{charge}(i) = \\text{cost}(i) + \\Phi\_i -
\\Phi\_{i-1}](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctext%7Bcharge%7D%28i%29%20%3D%20%5Ctext%7Bcost%7D%28i%29%20%2B%20%5CPhi_i%20-%20%5CPhi_%7Bi-1%7D "\text{charge}(i) = \text{cost}(i) + \Phi_i - \Phi_{i-1}").
Let’s examine other operations costs first:

-   Merge cost is
    ![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)"),
    since the number of trees is the same.

-   Decrease key cost is ![O(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)"),
    and the number of trees is the same.

-   Insert cost is
    ![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)"),
    since the number of trees increase by one.

In the case of `delete min`, we have the degree ![r \\in O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=r%20%5Cin%20O%28%5Clog%20n%29 "r \in O(\log n)")
of the node being deleted, and ![t =
\\Phi\_{i-1}](http://chart.apis.google.com/chart?cht=tx&chl=t%20%3D%20%5CPhi_%7Bi-1%7D "t = \Phi_{i-1}")
as the number of trees being deleted.

Consolidate is called on
![t-1+r](http://chart.apis.google.com/chart?cht=tx&chl=t-1%2Br "t-1+r")
trees.

Thus the total cost is ![t - 1 + r + O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=t%20-%201%20%2B%20r%20%2B%20O%28%5Clog%20n%29 "t - 1 + r + O(\log n)").

After consolidation, we have ![\\Phi\_i \\in O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_i%20%5Cin%20O%28%5Clog%20n%29 "\Phi_i \in O(\log n)").

\
![\\begin{aligned} \\text{amortized cost} &\\le \\text{max charge} \\\\
&\\le \\text{cost}(i) + \\Phi\_i - \\Phi\_{i-1} \\\\ &= t - 1 + r +
O(\\log n) - t \\\\ &\\le r + O(\\log n) \\\\ r \\in O(\\log n)
&\\implies \\text{amortized cost} \\in O(\\log n)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7Bamortized%20cost%7D%20%26%5Cle%20%5Ctext%7Bmax%20charge%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20%5Ctext%7Bcost%7D%28i%29%20%2B%20%5CPhi_i%20-%20%5CPhi_%7Bi-1%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20t%20-%201%20%2B%20r%20%2B%20O%28%5Clog%20n%29%20-%20t%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20r%20%2B%20O%28%5Clog%20n%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20r%20%5Cin%20O%28%5Clog%20n%29%20%26%5Cimplies%20%5Ctext%7Bamortized%20cost%7D%20%5Cin%20O%28%5Clog%20n%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                            \text{amortized cost} &\le \text{max charge} \\
                            &\le \text{cost}(i) + \Phi_i - \Phi_{i-1} \\
                            &= t - 1 + r + O(\log n) - t \\
                            &\le r + O(\log n) \\
                            r \in O(\log n) &\implies \text{amortized cost} \in O(\log n)
                        \end{aligned}")\

Thus `delete min` for lazy binomial heaps runs in
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")
worst case, but ![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")
amortized.

### Fibonacci Heaps {#sub:fibonacci_heaps}

In these heaps, we want to improve the amortized cost of `decrease key`.

What if instead of bubbling up, we simply “cut off” the node being
decreased (and its sub-tree) from its parents?

This is dangerous, since the number of trees increases, and the number
of child nodes change (not just
![2\^i](http://chart.apis.google.com/chart?cht=tx&chl=2%5Ei "2^i")) for
details.

TODO: the notes in lecture 3 reference assignment 2 for a practical
alternative to Fibonacci Heaps. Dig this up.

Splay Trees {#cha:splay_trees}
===========

In a nutshell, splay trees are self-adjusting data structures that alter
data structure after each query. They’re the tree equivalent to lists
that use
[https://en.wikipedia.org/wiki/Move-to-front\_transform](move-to-front)
to improve lookup times.

Requisite Knowledge {#sec:requisite_knowledge}
-------------------

### Dictionaries {#sub:dictionaries}

These use keys from a totally ordered universe. Operations include:

-   Insert

-   Delete

-   Search

#### Unbalanced Binary Search Trees {#ssub:unbalanced_binary_search_trees}

All operations take
![O(h)](http://chart.apis.google.com/chart?cht=tx&chl=O%28h%29 "O(h)"),
where ![h](http://chart.apis.google.com/chart?cht=tx&chl=h "h") is the
height of the tree.

#### Balanced Binary Search Tree {#ssub:balanced_binary_search_tree}

We limit ![h \\in O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=h%20%5Cin%20O%28%5Clog%20n%29 "h \in O(\log n)").
There are two (main) implementations: AVL and red-black trees. Both
implementations must keep the balance information, and are re-balanced
using rotations.

Regarding Splay Trees {#sec:regarding_splay_trees}
---------------------

Splay trees were invented (discovered?) by Sleator and Tarjan in \`85.
They offer A ![\\theta(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28%5Clog%20n%29 "\theta(\log n)")
cost per operation, with a
![\\theta(n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28n%29 "\theta(n)")
worst case running time. By not keeping balance information, they become
easier to implement than other conventional balanced trees.

The course notes allude to an example where single rotations do not give
good average behavior, so we will do double rotations instead.

### Splay Operation {#sub:splay_operation}

The `splay(x)` operation moves
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x") repeatedly to
the root. This occurs through three cases. Refer to Figures
[fig:splay~t~rees~c~ase~1~], [fig:splay~t~rees~c~ase~2~], and
[fig:splay~t~rees~c~ase~3~].

![Splay Trees Case 1](images/splay_trees_case_1.png "fig:")
[fig:splay~t~rees~c~ase~1~]

![Splay Trees Case 2](images/splay_trees_case_2.png "fig:")
[fig:splay~t~rees~c~ase~2~]

![Splay Trees Case 3](images/splay_trees_case_3.png "fig:")
[fig:splay~t~rees~c~ase~3~]

### Splay Tree Methods {#sub:splay_tree_methods}

Search
:   - after finding
    ![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x"), calling
    `splay(x)`, even for unsuccessful searches.

Insert
:   - usual binary search tree insert, then we `splay` the new node.

Delete
:   - usual binary search tree delete, then splay the parent of the node
    being removed.

Amortized Analysis of Splay Trees {#sec:amortized_analysis_of_splay_trees}
---------------------------------

If the height ![h](http://chart.apis.google.com/chart?cht=tx&chl=h "h")
of a tree is large, then search is expensive, and we pay out of
potential.

We define
![D(x)](http://chart.apis.google.com/chart?cht=tx&chl=D%28x%29 "D(x)")
as the number of descendants of
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x"), including
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x"), and ![r(x) =
\\log(D(x))](http://chart.apis.google.com/chart?cht=tx&chl=r%28x%29%20%3D%20%5Clog%28D%28x%29%29 "r(x) = \log(D(x))")
. Finally, we define ![\\Phi(T) = \\sum\_x
r(x)](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi%28T%29%20%3D%20%5Csum_x%20r%28x%29 "\Phi(T) = \sum_x r(x)").
By *magic*, we have the max as ![\\Phi\_{\\text{max}} = O(\\log(n!)) =
O(n\\log(n))](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_%7B%5Ctext%7Bmax%7D%7D%20%3D%20O%28%5Clog%28n%21%29%29%20%3D%20O%28n%5Clog%28n%29%29 "\Phi_{\text{max}} = O(\log(n!)) = O(n\log(n))"),
and the min as ![\\Phi\_\\text{min} =
O(n)](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_%5Ctext%7Bmin%7D%20%3D%20O%28n%29 "\Phi_\text{min} = O(n)").

For a single node, we call
![r(x)](http://chart.apis.google.com/chart?cht=tx&chl=r%28x%29 "r(x)")
the current rank, and
![r'(x)](http://chart.apis.google.com/chart?cht=tx&chl=r%27%28x%29 "r'(x)")
the rank after calling `splay(x)`.

We claim that the amortized cost of one step of `splay(x)` is:

\
![\\begin{aligned} O(\\text{splay}(x)) &\\le \\left\\{
\\begin{array}{lr} 3 (r'(x) - r(x)) :& \\text{ for cases 1 and 2}\\\\ 3
(r'(x) - r(x)) + 1 :& \\text{ for case 3} \\end{array} \\right.
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%28%5Ctext%7Bsplay%7D%28x%29%29%20%26%5Cle%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%203%20%28r%27%28x%29%20-%20r%28x%29%29%20%3A%26%20%5Ctext%7B%20for%20cases%201%20and%202%7D%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%203%20%28r%27%28x%29%20-%20r%28x%29%29%20%2B%201%20%3A%26%20%5Ctext%7B%20for%20case%203%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    O(\text{splay}(x)) &\le
                    \left\{
                        \begin{array}{lr}
                            3 (r'(x) - r(x)) :& \text{ for cases 1 and 2}\\
                            3 (r'(x) - r(x)) + 1 :& \text{ for case 3}
                        \end{array}
                    \right.
                \end{aligned}")\

Note that ![(r''(x) - r'(x)) + (r'(x) - r(x)) = r''(x) -
r(x)](http://chart.apis.google.com/chart?cht=tx&chl=%28r%27%27%28x%29%20-%20r%27%28x%29%29%20%2B%20%28r%27%28x%29%20-%20r%28x%29%29%20%3D%20r%27%27%28x%29%20-%20r%28x%29 "(r''(x) - r'(x)) + (r'(x) - r(x)) = r''(x) - r(x)").

Since ![\\Phi\_i \\ge
\\Phi\_0](http://chart.apis.google.com/chart?cht=tx&chl=%5CPhi_i%20%5Cge%20%5CPhi_0 "\Phi_i \ge \Phi_0"),
we now want to find the amortized cost.

-   For case 3, refer to Figure [fig:splay~t~rees~a~mortized~c~ase~3~].

    ![Amortized Splay Tree Analysis - Case
    3](images/splay_trees_amortized_case_3.png "fig:")
    [fig:splay~t~rees~a~mortized~c~ase~3~]

    \
    ![\\begin{aligned} \\text{amortized cost} &\\le \\text{charge} \\\\
    &= \\text{true cost} + \\text{change in potential} \\\\ &= 1 + r'(x)
    + r'(y) - r(x) - r(y) \\\\ r'(x) = r(y) &\\implies \\text{amortized
    cost} = 1 + r'(y) - r(x) \\\\ &\\le 1 + r'(x) - r(x) \\\\ &\\le 1 +
    3(r'(x) - r(x))
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7Bamortized%20cost%7D%20%26%5Cle%20%5Ctext%7Bcharge%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Ctext%7Btrue%20cost%7D%20%2B%20%5Ctext%7Bchange%20in%20potential%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201%20%2B%20r%27%28x%29%20%2B%20r%27%28y%29%20-%20r%28x%29%20-%20r%28y%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20r%27%28x%29%20%3D%20r%28y%29%20%26%5Cimplies%20%5Ctext%7Bamortized%20cost%7D%20%3D%201%20%2B%20r%27%28y%29%20-%20r%28x%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%201%20%2B%20r%27%28x%29%20-%20r%28x%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%201%20%2B%203%28r%27%28x%29%20-%20r%28x%29%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                                \text{amortized cost} &\le \text{charge} \\
                                &= \text{true cost} + \text{change in potential} \\
                                &= 1 + r'(x) + r'(y) - r(x) - r(y) \\
                                r'(x) = r(y) &\implies \text{amortized cost} = 1 + r'(y) - r(x) \\
                                &\le 1 + r'(x) - r(x) \\
                                &\le 1 + 3(r'(x) - r(x))
                            \end{aligned}")\

-   For case 1, refer to Figure [fig:splay~t~rees~a~mortized~c~ase~1~].

    ![Amortized Splay Tree Analysis - Case
    1](images/splay_trees_amortized_case_1.png "fig:")
    [fig:splay~t~rees~a~mortized~c~ase~1~]

    \
    ![\\begin{aligned} \\text{amortized cost} &\\le \\text{true cost} +
    \\text{change in potential} \\\\ &= 2 + (r'(x) + r'(y) + r'(z) -
    r(x) - r(y) - r(z)) \\\\ r'(x) = r(z) &\\implies \\text{amortized
    cost} \\le 2 + r'(y) + r'(z) - r(x) - r(y) \\\\ r'(y) \\le r'(x)
    \\land -r(y) \\le -r(x) &\\implies \\text{amortized cost} \\le 2 +
    r'(x) + r'(z) - 2r(x)
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7Bamortized%20cost%7D%20%26%5Cle%20%5Ctext%7Btrue%20cost%7D%20%2B%20%5Ctext%7Bchange%20in%20potential%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%202%20%2B%20%28r%27%28x%29%20%2B%20r%27%28y%29%20%2B%20r%27%28z%29%20-%20r%28x%29%20-%20r%28y%29%20-%20r%28z%29%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20r%27%28x%29%20%3D%20r%28z%29%20%26%5Cimplies%20%5Ctext%7Bamortized%20cost%7D%20%5Cle%202%20%2B%20r%27%28y%29%20%2B%20r%27%28z%29%20-%20r%28x%29%20-%20r%28y%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20r%27%28y%29%20%5Cle%20r%27%28x%29%20%5Cland%20-r%28y%29%20%5Cle%20-r%28x%29%20%26%5Cimplies%20%5Ctext%7Bamortized%20cost%7D%20%5Cle%202%20%2B%20r%27%28x%29%20%2B%20r%27%28z%29%20-%202r%28x%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                                \text{amortized cost} &\le \text{true cost} + \text{change in potential} \\
                                &= 2 + (r'(x) + r'(y) + r'(z) - r(x) - r(y) - r(z)) \\
                                r'(x) = r(z) &\implies \text{amortized cost} \le 2 + r'(y) + r'(z) - r(x) - r(y) \\
                                r'(y) \le r'(x) \land -r(y) \le -r(x) &\implies \text{amortized cost} \le 2 + r'(x) + r'(z) - 2r(x)
                            \end{aligned}")\

    To show that ![2 + r'(x) + r'(z) - 2r(x) \\le 3(r'(x) -
    r(x))](http://chart.apis.google.com/chart?cht=tx&chl=2%20%2B%20r%27%28x%29%20%2B%20r%27%28z%29%20-%202r%28x%29%20%5Cle%203%28r%27%28x%29%20-%20r%28x%29%29 "2 + r'(x) + r'(z) - 2r(x) \le 3(r'(x) - r(x))"),
    it is enough to show that ![2 \\le 2r'(x) - r(x) -
    r'(z)](http://chart.apis.google.com/chart?cht=tx&chl=2%20%5Cle%202r%27%28x%29%20-%20r%28x%29%20-%20r%27%28z%29 "2 \le 2r'(x) - r(x) - r'(z)").

    \
    ![\\begin{aligned} \\forall x, y \> 0 \\land x+y \\le 1 &:
    \\text{Range}(\\log x + \\log y) = (-\\infty, -2] \\\\ \\implies
    \\forall a + b \\le c &\\to \\log{\\left(\\frac{a}{c}\\right)} +
    \\log{\\left(\\frac{b}{c}\\right)} \\le -2 \\\\ D(x) + D'(z) \\le
    D'(x) &\\implies \\log(D(x)+ \\log(D'(z)) \\le 2 \\log(D'(x)) - 2
    \\\\ r(x) + r'(z) &\\le 2r'(x) - 2 \\\\ 2 &\\le 2r'(x) - r(x) -
    r'(z)
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cforall%20x%2C%20y%20%3E%200%20%5Cland%20x%2By%20%5Cle%201%20%26%3A%20%5Ctext%7BRange%7D%28%5Clog%20x%20%2B%20%5Clog%20y%29%20%3D%20%28-%5Cinfty%2C%20-2%5D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cimplies%20%5Cforall%20a%20%2B%20b%20%5Cle%20c%20%26%5Cto%20%5Clog%7B%5Cleft%28%5Cfrac%7Ba%7D%7Bc%7D%5Cright%29%7D%20%2B%20%5Clog%7B%5Cleft%28%5Cfrac%7Bb%7D%7Bc%7D%5Cright%29%7D%20%5Cle%20-2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20D%28x%29%20%2B%20D%27%28z%29%20%5Cle%20D%27%28x%29%20%26%5Cimplies%20%5Clog%28D%28x%29%2B%20%5Clog%28D%27%28z%29%29%20%5Cle%202%20%5Clog%28D%27%28x%29%29%20-%202%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20r%28x%29%20%2B%20r%27%28z%29%20%26%5Cle%202r%27%28x%29%20-%202%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%202%20%26%5Cle%202r%27%28x%29%20-%20r%28x%29%20-%20r%27%28z%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                                \forall x, y > 0 \land x+y \le 1 &: \text{Range}(\log x + \log y) = (-\infty, -2] \\
                                \implies \forall a + b \le c &\to \log{\left(\frac{a}{c}\right)} + \log{\left(\frac{b}{c}\right)} \le -2 \\
                                D(x) + D'(z) \le D'(x) &\implies \log(D(x)+ \log(D'(z)) \le 2 \log(D'(x)) - 2 \\
                                r(x) + r'(z) &\le 2r'(x) - 2 \\
                                2 &\le 2r'(x) - r(x) - r'(z)
                            \end{aligned}")\

    Thus the amortized cost of case 1 is ![\\le 3(r'(x) -
    r(x))](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%203%28r%27%28x%29%20-%20r%28x%29%29 "\le 3(r'(x) - r(x))").

-   Case 2 is incredibly similar to case 1 with minor (ordering)
    modifications.

Without proof[^10^](#fn10), we claim that a tree
![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") root
![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t") and node
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x"), the amortized
cost of `splay(x)` is:

\
![\\begin{aligned} A O(\\text{splay}) &\\le 3(r(t) - r(x)) + 1 \\\\
&\\in O(\\log{\\frac{D(t)}{D(x)}}) \\\\ &= O(\\log n)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20A%20O%28%5Ctext%7Bsplay%7D%29%20%26%5Cle%203%28r%28t%29%20-%20r%28x%29%29%20%2B%201%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cin%20O%28%5Clog%7B%5Cfrac%7BD%28t%29%7D%7BD%28x%29%7D%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20O%28%5Clog%20n%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    A O(\text{splay}) &\le 3(r(t) - r(x)) + 1 \\
                    &\in O(\log{\frac{D(t)}{D(x)}}) \\
                    &= O(\log n)
                \end{aligned}")\

Let ![r\_i =
r(x)](http://chart.apis.google.com/chart?cht=tx&chl=r_i%20%3D%20r%28x%29 "r_i = r(x)")
after the ![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i")th
step of the splay. So ![r\_0 =
r(x)](http://chart.apis.google.com/chart?cht=tx&chl=r_0%20%3D%20r%28x%29 "r_0 = r(x)"),
and ![r\_k =
r(t)](http://chart.apis.google.com/chart?cht=tx&chl=r_k%20%3D%20r%28t%29 "r_k = r(t)")
(where ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") is the
final step). Thus the overall amortized cost of splay is:

\
![\\begin{aligned} A O(\\text{splay}) &= 1 + \\sum\_{i=1}\^{k} 3(r\_i -
r\_{i-1}) \\\\ &= 3(r\_k - r\_0) + 1
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20A%20O%28%5Ctext%7Bsplay%7D%29%20%26%3D%201%20%2B%20%5Csum_%7Bi%3D1%7D%5E%7Bk%7D%203%28r_i%20-%20r_%7Bi-1%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%203%28r_k%20-%20r_0%29%20%2B%201%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    A O(\text{splay}) &= 1 + \sum_{i=1}^{k} 3(r_i - r_{i-1}) \\
                    &= 3(r_k - r_0) + 1
                \end{aligned}")\

We know that the cost of walking down the tree in each operation is
![\\le](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle "\le") the
cost of the ensuing splay. Thus, we know the amortized cost of `insert`,
`search`, and `delete` in a splay tree is ![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)").

We briefly touched in class that `insert` and `delete` both modify
potential, but this is still covered by the ![\\log
n](http://chart.apis.google.com/chart?cht=tx&chl=%5Clog%20n "\log n")
work to walk to the inserted and deleted value.

Union-Find Problem {#cha:union_find_problem}
==================

Connected components in a graph are essentially the components where two
can reach each other.

We want to find all connected components, and identify which component a
given vertex is in. Let’s make this efficient.

In general, we assume we are given a graph
![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G") with
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") vertexes and
![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m") edges. We then
need to respond to two queries:

find
:   are vertexes
    ![a](http://chart.apis.google.com/chart?cht=tx&chl=a "a") and
    ![b](http://chart.apis.google.com/chart?cht=tx&chl=b "b") in the
    same component?

union
:   connect the components which vertexes
    ![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c") and
    ![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d") lie in.

Using depth-first search, it takes
![O(n+m)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%2Bm%29 "O(n+m)")
time to perform `find`, and
![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)")
time to perform `union`.

Dynamic Graph Connectivity {#sec:dynamic_graph_connectivity}
--------------------------

For many data structures, we can get much faster runtime by maintaining
(and later updating) results as the underlying data changes.

Examples of where this is useful:

-   Social networks as relationships are added and deleted.

-   Minimum spanning tree[^11^](#fn11)

-   Kruskal’s Algorithm[^12^](#fn12)

Union-Find Data Structure {#sec:union_find_data_structure}
-------------------------

We want to maintain a collection of disjoint sets then evaluate:

Union![(A, B)](http://chart.apis.google.com/chart?cht=tx&chl=%28A%2C%20B%29 "(A, B)")
:   unites (modifies) the two sets
    ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") and
    ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") to be in
    the same set.

Find![(e)](http://chart.apis.google.com/chart?cht=tx&chl=%28e%29 "(e)")
:   which set contains
    ![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e")?

If we analyze Kruskal’s algorithm using union-find data structure, we
get:

\
![\\begin{aligned} \\mbox{sort} + 2m \\mbox{Finds} + n \\mbox{Unions}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmbox%7Bsort%7D%20%2B%202m%20%5Cmbox%7BFinds%7D%20%2B%20n%20%5Cmbox%7BUnions%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \mbox{sort} + 2m \mbox{Finds} + n \mbox{Unions}
                \end{aligned}")\

Sort takes ![O(m \\log m) = O(m \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%20%5Clog%20m%29%20%3D%20O%28m%20%5Clog%20n%29 "O(m \log m) = O(m \log n)")
time[^13^](#fn13), so we want the finds and unions to work in ![\\le O
(m \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20O%20%28m%20%5Clog%20n%29 "\le O (m \log n)")
to have a speedy algorithm.

Define ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") as the
number of elements, and
![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m") as the number
of operations. For all implementations, the number of unions ![\\le n -
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20n%20-%201 "\le n - 1").

### Implementation With an Array {#sub:implementation_with_an_array}

Using an array
![S[1...n]](http://chart.apis.google.com/chart?cht=tx&chl=S%5B1...n%5D "S[1...n]"),
where
![S[i]](http://chart.apis.google.com/chart?cht=tx&chl=S%5Bi%5D "S[i]")
contains the name of a set containing
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i").

Find
:   ![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)")

Union
:   ![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")
    worst case

To make this marginally faster, we can maintain a set for each set as
well. Thus, `union(A, B)` will update
![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") for the
smaller set. Since each element changes its set name ![\\le \\log
n](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%5Clog%20n "\le \log n")
times, the overall cost of all unions is ![\\le O(n \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20O%28n%20%5Clog%20n%29 "\le O(n \log n)").

The cost of ![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m")
operations is thus ![O(m + n \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%20%2B%20n%20%5Clog%20n%29 "O(m + n \log n)").
With this implementation, this is the best possible if the number of
finds is ![\\Omega(n \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=%5COmega%28n%20%5Clog%20n%29 "\Omega(n \log n)").

Thus in this case, we get ![O((n+m) \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%28n%2Bm%29%20%5Clog%20n%29 "O((n+m) \log n)")
for Kruskal’s algorithm.

### A Better Implementation {#sub:a_better_implementation}

In the case that the number of finds is small, the array-based
union-find implementation is horrible.

When we represent each set as a tree, life becomes much better.

Union
:   is implemented as merging the smaller tree as a child to the root of
    the larger tree. See Figure [fig:union~f~ind~u~nion] for a pictorial
    visualization.

Find
:   is implemented by traversing up the tree from the node, then
    returning the name of the root node. After traversing upwards, we
    perform path compression by setting the parent of all vertexes in
    the path to be the root of this tree. See
    Figure [fig:union~f~ind~f~ind] for a pictorial visualization.

![Union Operation in the Union-Find Data
Structure](images/union_find_union.png "fig:") [fig:union~f~ind~u~nion]

![Find Operation in the Union-Find Data
Structure](images/union_find_find.png "fig:") [fig:union~f~ind~f~ind]

We determine the smaller tree by keeping track of the “rank” of a tree -
the height if there was no path compression. When `union`-ing a smaller
![r\_2](http://chart.apis.google.com/chart?cht=tx&chl=r_2 "r_2") onto a
larger ![r\_1](http://chart.apis.google.com/chart?cht=tx&chl=r_1 "r_1"),
the the new rank is ![\\max\\{r\_1,
r\_2+1\\}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmax%5C%7Br_1%2C%20r_2%2B1%5C%7D "\max\{r_1, r_2+1\}").

Analysis of the Union-Find Data Structure {#sec:analysis_of_the_union_find_data_structure}
-----------------------------------------

The implementation is simple, but the analysis is hard. In \`75, Tarjan
proved that the cost of
![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m") operations is
![\\Theta(m \\alpha(m,
n))](http://chart.apis.google.com/chart?cht=tx&chl=%5CTheta%28m%20%5Calpha%28m%2C%20n%29%29 "\Theta(m \alpha(m, n))")
time[^14^](#fn14).

We will prove the slightly higher bound of ![O(m \\log\^\*
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%20%5Clog%5E%2A%20n%29 "O(m \log^* n)")
time for ![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m")
operations[^15^](#fn15).

We know that the cost of `find(v)` is the same as the distance from
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") to the root.
In a nutshell, we will charge some to the `find`, and some to the nodes
along the path from
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") to the root,
then sum it up.

We claim (without proof) that:

1.  ![\\text{rank}(v) \<
    \\text{rank}(\\text{parent}(v))](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctext%7Brank%7D%28v%29%20%3C%20%5Ctext%7Brank%7D%28%5Ctext%7Bparent%7D%28v%29%29 "\text{rank}(v) < \text{rank}(\text{parent}(v))").

2.  The number of vertexes of rank
    ![r](http://chart.apis.google.com/chart?cht=tx&chl=r "r") is ![\\le
    \\frac{n}{2\^r}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%5Cfrac%7Bn%7D%7B2%5Er%7D "\le \frac{n}{2^r}")
    in size[^16^](#fn16).

In our analysis, we divide vertexes into groups based on their rank. A
vertex of rank ![r](http://chart.apis.google.com/chart?cht=tx&chl=r "r")
goes in a group number
![\\log\^\*(r)](http://chart.apis.google.com/chart?cht=tx&chl=%5Clog%5E%2A%28r%29 "\log^*(r)").
Thus a group ![g](http://chart.apis.google.com/chart?cht=tx&chl=g "g")
contain the ranks ![2\\uparrow(g-1) + 1, 2\\uparrow(g-1) + 2, \\ldots,
2\\uparrow
g](http://chart.apis.google.com/chart?cht=tx&chl=2%5Cuparrow%28g-1%29%20%2B%201%2C%202%5Cuparrow%28g-1%29%20%2B%202%2C%20%5Cldots%2C%202%5Cuparrow%20g "2\uparrow(g-1) + 1, 2\uparrow(g-1) + 2, \ldots, 2\uparrow g").
For group ![g](http://chart.apis.google.com/chart?cht=tx&chl=g "g"), the
number different ranks
![c(g)+1](http://chart.apis.google.com/chart?cht=tx&chl=c%28g%29%2B1 "c(g)+1")
in ![g](http://chart.apis.google.com/chart?cht=tx&chl=g "g") is ![\\le 2
\\uparrow
g](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%202%20%5Cuparrow%20g "\le 2 \uparrow g").

Since the largest rank in a structures can be
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"), the number of
groups must be ![\\le \\log\^\*
n](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%5Clog%5E%2A%20n "\le \log^* n").

We want to find the charge for `find(v)`: For each vertex
![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") on the path
from ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") to the
root:

-   if ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") has a
    parent and grandparent, and
    ![\\text{group](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctext%7Bgroup "\text{group")(u)![}
    =
    \\text{group](http://chart.apis.google.com/chart?cht=tx&chl=%7D%20%3D%20%5Ctext%7Bgroup "} = \text{group")()![}](http://chart.apis.google.com/chart?cht=tx&chl=%7D "}"),
    then charge 1 to
    ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u").

-   Otherwise, charge 1 to `find(v)`.

Thus the total charge to
![\\text{find](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctext%7Bfind "\text{find")(v)![}
\\le \\log\^\* n +
1](http://chart.apis.google.com/chart?cht=tx&chl=%7D%20%5Cle%20%5Clog%5E%2A%20n%20%2B%201 "} \le \log^* n + 1"),
since the group changes ![\\le \\log\^\*n -
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%5Clog%5E%2An%20-%201 "\le \log^*n - 1")
times, and ![2](http://chart.apis.google.com/chart?cht=tx&chl=2 "2")
more for the root and it’s child.

We now need to determine the charge to individual nodes.

If a vertex ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") in
group ![g](http://chart.apis.google.com/chart?cht=tx&chl=g "g") is
charged, then path compression will give it a new parent of higher rank.
Therefore a ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") in
group ![g](http://chart.apis.google.com/chart?cht=tx&chl=g "g") is
charged
![c(g)](http://chart.apis.google.com/chart?cht=tx&chl=c%28g%29 "c(g)")
times until its parent is in a higher group. We know that ![c(g) \\le 2
\\uparrow
g](http://chart.apis.google.com/chart?cht=tx&chl=c%28g%29%20%5Cle%202%20%5Cuparrow%20g "c(g) \le 2 \uparrow g").

The total charge to all nodes in a group
![g](http://chart.apis.google.com/chart?cht=tx&chl=g "g") is:

\
![\\begin{aligned} (\\text{number of ranks in \$g\$})(\\text{number of
nodes in \$g\$}) &= c(g)N(g) \\\\ N(g) &\\le \\sum\_{r =
2\\uparrow(g-1)+1}\^{2 \\uparrow g} \\frac{n}{2\^r} \\\\ &\\le
\\frac{n}{2\^{2 \\uparrow(g-1)+1}} \\sum\_{i=0}\^\\infty \\frac{1}{2\^i}
\\\\ &\\le \\frac{n}{2 \\uparrow g} \\\\ \\implies c(g)N(g) &\\le n
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%28%5Ctext%7Bnumber%20of%20ranks%20in%20%24g%24%7D%29%28%5Ctext%7Bnumber%20of%20nodes%20in%20%24g%24%7D%29%20%26%3D%20c%28g%29N%28g%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20N%28g%29%20%26%5Cle%20%5Csum_%7Br%20%3D%202%5Cuparrow%28g-1%29%2B1%7D%5E%7B2%20%5Cuparrow%20g%7D%20%5Cfrac%7Bn%7D%7B2%5Er%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20%5Cfrac%7Bn%7D%7B2%5E%7B2%20%5Cuparrow%28g-1%29%2B1%7D%7D%20%5Csum_%7Bi%3D0%7D%5E%5Cinfty%20%5Cfrac%7B1%7D%7B2%5Ei%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20%5Cfrac%7Bn%7D%7B2%20%5Cuparrow%20g%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cimplies%20c%28g%29N%28g%29%20%26%5Cle%20n%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    (\text{number of ranks in $g$})(\text{number of nodes in $g$}) &= c(g)N(g) \\
                    N(g) &\le \sum_{r = 2\uparrow(g-1)+1}^{2 \uparrow g} \frac{n}{2^r} \\
                    &\le \frac{n}{2^{2 \uparrow(g-1)+1}} \sum_{i=0}^\infty \frac{1}{2^i} \\
                    &\le \frac{n}{2 \uparrow g} \\
                    \implies c(g)N(g) &\le n
                \end{aligned}")\

Thus the total charge to all nodes is ![n \\log\^\*
n](http://chart.apis.google.com/chart?cht=tx&chl=n%20%5Clog%5E%2A%20n "n \log^* n").

For Kruskal’s algorithm, we find the total charge to `finds` and `nodes`
as:

\
![\\begin{aligned} O(m (\\log\^\*n + 1) + n \\log\^\* n) &= O(m
\\log\^\* n)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%28m%20%28%5Clog%5E%2An%20%2B%201%29%20%2B%20n%20%5Clog%5E%2A%20n%29%20%26%3D%20O%28m%20%5Clog%5E%2A%20n%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    O(m (\log^*n + 1) + n \log^* n) &= O(m \log^* n)
                \end{aligned}")\

Not bad.

Geometric Data Structures {#cha:geometric_data_structures}
=========================

So far data structures have been implemented with comparable keys.

When working in higher dimensions, we have two main problem types:

-   Find points inside a region

-   Find regions containing a point

Range Search {#sec:range_search}
------------

By preprocessing
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") points in
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") dimensions, so
we can handle range queries. In 2D, this would be querying for points
contained within a rectangle.

We have 3 main measures for range search methods:

P
:   the preprocessing time

S
:   the space taken for preprocessing

Q
:   the query time

U
:   the update time (only some algorithms can have updated data)

### Range Queries for ![k=1](http://chart.apis.google.com/chart?cht=tx&chl=k%3D1 "k=1") {#sub:range_queries_for_k_1}

When ![k=1](http://chart.apis.google.com/chart?cht=tx&chl=k%3D1 "k=1"),
we sort data and use binary searches. Thus we have:

P
:   ![O(n \\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Clog%20n%29 "O(n \log n)")

S
:   ![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")

Q
:   ![O(\\log n +
    t)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%20%2B%20t%29 "O(\log n + t)"),
    where ![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t") is
    the output size.

U
:   ![O(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")

### Range Queries for ![k=2](http://chart.apis.google.com/chart?cht=tx&chl=k%3D2 "k=2") {#sub:range_queries_for_k_2}

We have a few cool implementations, most of which are covered in CS240.

#### Quad Tree {#ssub:quad_tree}

Divide squares into four subsquares, repeat until each square has ![(0,
1)](http://chart.apis.google.com/chart?cht=tx&chl=%280%2C%201%29 "(0, 1)")
points.

#### ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")d-Tree {#ssub:kd_tree}

Divide points in half vertically then horizontally (then recurse).

P
:   ![O(n \\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Clog%20n%29 "O(n \log n)")

S
:   ![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")

Q
:   ![\\Theta(\\sqrt{n} +
    t)](http://chart.apis.google.com/chart?cht=tx&chl=%5CTheta%28%5Csqrt%7Bn%7D%20%2B%20t%29 "\Theta(\sqrt{n} + t)"),
    where ![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t") is
    the output size.

#### Range Trees {#ssub:range_trees}

See the subsection on Range trees below.

### Range Trees for ![k=2](http://chart.apis.google.com/chart?cht=tx&chl=k%3D2 "k=2") {#sub:range_trees_for_k_2}

A ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")th dimension
range tree improves
![Q](http://chart.apis.google.com/chart?cht=tx&chl=Q "Q") at the expense
of ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S"). It uses a
binary search tree across one dimension, where each internal node has an
additional
![n-1](http://chart.apis.google.com/chart?cht=tx&chl=n-1 "n-1")-dimension
range tree.

A
![k=1](http://chart.apis.google.com/chart?cht=tx&chl=k%3D1 "k=1")-dimension
range tree is a sorted list.

P
:   sort by ![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x"),
    then sort by
    ![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y") and do
    some work - ![O(n \\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Clog%20n%29 "O(n \log n)")

S
:   each point occurs in ![\\log
    n](http://chart.apis.google.com/chart?cht=tx&chl=%5Clog%20n "\log n")
    of the
    sorted-by-![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y")
    lists - ![O(n \\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Clog%20n%29 "O(n \log n)")

Q
:   search for the
    ![x\_l](http://chart.apis.google.com/chart?cht=tx&chl=x_l "x_l") and
    ![x\_r](http://chart.apis.google.com/chart?cht=tx&chl=x_r "x_r") in
    ![O(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")
    time. For all children of paths to
    ![x\_l](http://chart.apis.google.com/chart?cht=tx&chl=x_l "x_l") and
    ![x\_r](http://chart.apis.google.com/chart?cht=tx&chl=x_r "x_r"), we
    search the ![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y")
    list - ![O(\\log\^2 n +
    t)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%5E2%20n%20%2B%20t%29 "O(\log^2 n + t)")

#### Fractional Cascading {#ssub:fractional_cascading}

We can improve ![Q](http://chart.apis.google.com/chart?cht=tx&chl=Q "Q")
to ![O(\\log n +
t)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%20%2B%20t%29 "O(\log n + t)")
by using a technique called fractional cascading.

Generally, we keep a pointer from each element in the
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x")’s list to the
corresponding element in
![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y")’s list. This
gives us ![Q = (\\log n +
t)](http://chart.apis.google.com/chart?cht=tx&chl=Q%20%3D%20%28%5Clog%20n%20%2B%20t%29 "Q = (\log n + t)"),
since we binary search for ![y\_U,
y\_L](http://chart.apis.google.com/chart?cht=tx&chl=y_U%2C%20y_L "y_U, y_L")
in the list of root and follow pointers.

Point Location {#sec:point_location}
--------------

Given a set of disjoint regions in a
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")-dimensional
space, we want to quickly respond to queries that query the location
they are in. This can help with queries like: which city is coordinate
![(a,b)](http://chart.apis.google.com/chart?cht=tx&chl=%28a%2Cb%29 "(a,b)")
in? Where is the nearest Tim Hortons? etc.

### Point Location for ![k=1](http://chart.apis.google.com/chart?cht=tx&chl=k%3D1 "k=1") Dimension {#sub:point_location_for_k_1_dimension}

In ![1](http://chart.apis.google.com/chart?cht=tx&chl=1 "1")d, we use a
balanced binary search tree.

P
:   ![O(n \\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Clog%20n%29 "O(n \log n)")

S
:   ![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")

Q
:   ![O(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")

### Point Location for ![k=2](http://chart.apis.google.com/chart?cht=tx&chl=k%3D2 "k=2") dimensions {#sub:point_location_for_k_2_dimensions}

We can divide the entire space into slabs by adding a vertical line at
every point.

Then given a query point
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x"), find the
correct slab (![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)"))
then binary search by
![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y") (![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")).

Q
:   ![O(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")

S
:   ![\\Theta(n\^2)](http://chart.apis.google.com/chart?cht=tx&chl=%5CTheta%28n%5E2%29 "\Theta(n^2)")
    (ew)

#### Less Space Through Persistent Data Structures {#ssub:less_space_through_persistent_data_structures}

Given that in one slab to the next, very few changes, we only need to
make a BST for the leftmost slab and update for subsequent slabs.

The total number of updates to the BST is
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)"),
since every segment is inserted and deleted exactly once.

If we update a BST and search it in the past, this idea is called a
“persistent data structure”.

Partial persistence
:   allows queries in the past and only the present be changed.

Full persistence
:   allows queries and changes at any point in time.

Using Driscoll, …, Tarjan \`89, we can add partial persistence to any
data structure.

This gives us a planar point location of:

P
:   ![O(n \\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Clog%20n%29 "O(n \log n)")

S
:   ![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")

Q
:   ![O(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")

In an awesome way, this runs in the same time as the initial 1D problem.

Randomized Algorithms {#cha:randomized_algorithms}
=====================

Algorithms that use random numbers have their and/or their depend on
random numbers. This forces us to use amortized (expected) analysis.

Practicaly speaking, it gets us easier and faster algorithms.
Theoretically speaking, it’s openwhether randomization helps for Pvs NP,
but we’ll see an example where it’ll help a tiny bit.

In previous classes, we’ve seen QuickSort[^17^](#fn17) and SkipLists.

We define randomized algorithms as ones that execute either method
`rand[1, ..., n]` or `rand[0, 1]`, both of which run in
![O(1)](http://chart.apis.google.com/chart?cht=tx&chl=O%281%29 "O(1)")
time[^18^](#fn18).

Thus, the running time for fixed input depends on random numbers - i.e.
a .

A few definitions are necessary:

Sample Space
:   is the space of all possible outcomes (for fixed input).

Random Variables
:   map the sample space to real numbers (at runtime).

We need to rely on some stats for the upcoming parts. See
Section [sec:expected~v~alues~s~tatistics] for expected knowledge.

We set the function
![T(I)](http://chart.apis.google.com/chart?cht=tx&chl=T%28I%29 "T(I)")
as the time it takes depending on the random variable
![I](http://chart.apis.google.com/chart?cht=tx&chl=I "I"). Obviously, we
set
![E(T(I))](http://chart.apis.google.com/chart?cht=tx&chl=E%28T%28I%29%29 "E(T(I))")
as the expected runtime across all possible values of
![I](http://chart.apis.google.com/chart?cht=tx&chl=I "I").

We then say that the
function[^19^](#fn19)![T(n)](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29 "T(n)")
is the maximum of
![E(T(I))](http://chart.apis.google.com/chart?cht=tx&chl=E%28T%28I%29%29 "E(T(I))")
across all ![I](http://chart.apis.google.com/chart?cht=tx&chl=I "I")’s.

\
![\\begin{aligned} T(n) &= \\max\_{|I| = n} E(T(I))
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%28n%29%20%26%3D%20%5Cmax_%7B%7CI%7C%20%3D%20n%7D%20E%28T%28I%29%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                T(n) &= \max_{|I| = n} E(T(I))
            \end{aligned}")\

Selection {#sec:selection}
---------

Given a set of ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")
numbers ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S"), we’d
like to return the
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")-th smallest
element of ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S").

For example:

-   ![k =
    1](http://chart.apis.google.com/chart?cht=tx&chl=k%20%3D%201 "k = 1")
    is the min

-   ![k =
    2](http://chart.apis.google.com/chart?cht=tx&chl=k%20%3D%202 "k = 2")
    is the 2nd min

-   ![k =
    n](http://chart.apis.google.com/chart?cht=tx&chl=k%20%3D%20n "k = n")
    is the max

-   ![k = {\\left \\lfloor \\frac{n}{2} \\right \\rfloor
    }](http://chart.apis.google.com/chart?cht=tx&chl=k%20%3D%20%7B%5Cleft%20%5Clfloor%20%5Cfrac%7Bn%7D%7B2%7D%20%5Cright%20%5Crfloor%20%7D "k = {\left \lfloor \frac{n}{2} \right \rfloor }")
    is the median

Let’s implement QuickSelect:

        def QuickSelect(S, k):
            n = |S|
            if n < constant
                Sort(S)
                return kth element
            i = rand(1...n)
            partion S into:
            L = {s : s < S[i]}
            M = {s : s == S[i]}
            R = {s : s > S[i]}
            if k < |L| return QuickSelect(L, k)
            if k <= |L| + m return s[i]
            return QuickSelect(B, k - (|L| + |M|))
                    

This is worst-case
![O(n\^2)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E2%29 "O(n^2)")
when pivot is always the min or the max, but it often isn’t the
worst-case.

We can do more detailed analysis to find the expected time of finding it
on a set ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") of
size ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n").

In other words, we want
![E(T(n))](http://chart.apis.google.com/chart?cht=tx&chl=E%28T%28n%29%29 "E(T(n))"),
where
![T(n)](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29 "T(n)")
is a random variable runtime of QuickSelect on a set of size
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n").

We have recursive calls on sets of size
![\\ell](http://chart.apis.google.com/chart?cht=tx&chl=%5Cell "\ell") or
![n -
\\ell](http://chart.apis.google.com/chart?cht=tx&chl=n%20-%20%5Cell "n - \ell").
For an upper bound, assume that
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") lies in the
larger (worse) half of the recursion. In other words, we assume that ![k
\\le
\\frac{n}{4}](http://chart.apis.google.com/chart?cht=tx&chl=k%20%5Cle%20%5Cfrac%7Bn%7D%7B4%7D "k \le \frac{n}{4}")
or ![k \\ge
\\frac{3n}{4}](http://chart.apis.google.com/chart?cht=tx&chl=k%20%5Cge%20%5Cfrac%7B3n%7D%7B4%7D "k \ge \frac{3n}{4}").
Thus the recursion is ![\\le
T(\\frac{3n}{4})](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20T%28%5Cfrac%7B3n%7D%7B4%7D%29 "\le T(\frac{3n}{4})").

Assuming that ![T(i) \\le
T(j)](http://chart.apis.google.com/chart?cht=tx&chl=T%28i%29%20%5Cle%20T%28j%29 "T(i) \le T(j)")
for ![i \\le
j](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cle%20j "i \le j"),
we get:

\
![\\begin{aligned} E(T(n)) &\\le
\\frac{1}{2}E\\left(T\\left(\\frac{3n}{4}\\right)\\right) +
\\frac{1}{2}E\\left(T\\left(n - 1\\right)\\right) + O(n) \\\\
f\\left(n\\right) &\\le \\frac{1}{2}f\\left(\\frac{3n}{4}\\right) +
\\frac{1}{2}f\\left(n - 1\\right) + O(n)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28T%28n%29%29%20%26%5Cle%20%5Cfrac%7B1%7D%7B2%7DE%5Cleft%28T%5Cleft%28%5Cfrac%7B3n%7D%7B4%7D%5Cright%29%5Cright%29%20%2B%20%5Cfrac%7B1%7D%7B2%7DE%5Cleft%28T%5Cleft%28n%20-%201%5Cright%29%5Cright%29%20%2B%20O%28n%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%5Cleft%28n%5Cright%29%20%26%5Cle%20%5Cfrac%7B1%7D%7B2%7Df%5Cleft%28%5Cfrac%7B3n%7D%7B4%7D%5Cright%29%20%2B%20%5Cfrac%7B1%7D%7B2%7Df%5Cleft%28n%20-%201%5Cright%29%20%2B%20O%28n%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    E(T(n)) &\le \frac{1}{2}E\left(T\left(\frac{3n}{4}\right)\right) + \frac{1}{2}E\left(T\left(n - 1\right)\right) + O(n) \\
                    f\left(n\right) &\le \frac{1}{2}f\left(\frac{3n}{4}\right) + \frac{1}{2}f\left(n - 1\right) + O(n)
                \end{aligned}")\

We can prove by induction that ![f(n) =
O(n)](http://chart.apis.google.com/chart?cht=tx&chl=f%28n%29%20%3D%20O%28n%29 "f(n) = O(n)").

Random V.S. Non-Randomized Algorithms {#sec:random_v_s_non_randomized_algorithms}
-------------------------------------

1960 Hoare QuickSelect has ![3n +
o(n)](http://chart.apis.google.com/chart?cht=tx&chl=3n%20%2B%20o%28n%29 "3n + o(n)")
expected comparisons\
1973 BFPRT created a non-randomized selection in
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")
time, with ![5.43n +
o(n)](http://chart.apis.google.com/chart?cht=tx&chl=5.43n%20%2B%20o%28n%29 "5.43n + o(n)")
comparisons. This is the same with respect to
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)"),
but different constant than randomized algorithms.\
1975 Floyd Rivest created a randomized algorithm that takes ![1.5n +
o(n)](http://chart.apis.google.com/chart?cht=tx&chl=1.5n%20%2B%20o%28n%29 "1.5n + o(n)")
expected comparisons.\
1989 Munro & Cunto proved that any ralgorithm takes at least
![1.5n](http://chart.apis.google.com/chart?cht=tx&chl=1.5n "1.5n")
expected comparisons.\
1985 [???] proved a lower bound of
![2n](http://chart.apis.google.com/chart?cht=tx&chl=2n "2n") comparisons
for non-randomized algorithms. Randomization probably helps.\

Currently, our best non-randomized bounds are:

[h]

  Bound         Year   \# comparisons
  ------------- ------ -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  Upper Bound   1999   2.95n
  Lower Bound   2001   ![(2 + \\varepsilon) n](http://chart.apis.google.com/chart?cht=tx&chl=%282%20%2B%20%5Cvarepsilon%29%20n "(2 + \varepsilon) n"), ![\\varepsilon = 2\^{-80}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cvarepsilon%20%3D%202%5E%7B-80%7D "\varepsilon = 2^{-80}")

Lower Bound on Median {#sec:lower_bound_on_median}
---------------------

**Theorem:**[^20^](#fn20) Finding the median of
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") elements takes
![\\ge
1.5n](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%201.5n "\ge 1.5n")
comparisons in the worst case.

**Proof:**[^21^](#fn21)

Let ![L = \\{\\text{elements } \<
m\\}](http://chart.apis.google.com/chart?cht=tx&chl=L%20%3D%20%5C%7B%5Ctext%7Belements%20%7D%20%3C%20m%5C%7D "L = \{\text{elements } < m\}"),
and ![M = \\{\\text{elements } \>
m\\}](http://chart.apis.google.com/chart?cht=tx&chl=M%20%3D%20%5C%7B%5Ctext%7Belements%20%7D%20%3E%20m%5C%7D "M = \{\text{elements } > m\}").
So that each set has
![\\frac{n-1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7Bn-1%7D%7B2%7D "\frac{n-1}{2}")
elements.

We claim that the number of
![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") vs
![H](http://chart.apis.google.com/chart?cht=tx&chl=H "H") comparisons
must be ![\\ge
\\frac{n-1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20%5Cfrac%7Bn-1%7D%7B2%7D "\ge \frac{n-1}{2}")
in the worst case.

We set it up so the adversary answers the comparisons that our algorithm
queries. Our adversary consistently answers by “setting” elements to
![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") and
![H](http://chart.apis.google.com/chart?cht=tx&chl=H "H") at all
times.[^22^](#fn22) We can now create an adversary strategy:

    def compare(x, y):
        if x and y have been seen before:
            return result of comparison
        if one of (x, y) have been seen:
            put the unseen one in the other set
        if neither are set:
            put x in L, y in H
                    

An adversary must stop when ![\\max(|L|, |H|) =
\\frac{n-1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmax%28%7CL%7C%2C%20%7CH%7C%29%20%3D%20%5Cfrac%7Bn-1%7D%7B2%7D "\max(|L|, |H|) = \frac{n-1}{2}"),
so they can force at most
![\\frac{n-1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7Bn-1%7D%7B2%7D "\frac{n-1}{2}")
comparisons.

Since there are always ![\\ge
n-1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20n-1 "\ge n-1")
![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") vs
![H](http://chart.apis.google.com/chart?cht=tx&chl=H "H") comparisons,
and the adversary can force an additional ![\\ge
\\frac{n-1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20%5Cfrac%7Bn-1%7D%7B2%7D "\ge \frac{n-1}{2}")
![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") vs
![H](http://chart.apis.google.com/chart?cht=tx&chl=H "H") comparisons,
the overall algorithm must make ![\\ge
1.5n](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%201.5n "\ge 1.5n")
comparisons in the worst case.

### ![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)") Non-Randomized Selection Algorithm {#sub:on_non_randomized_selection_algorithm}

The idea here is that we divide sets of
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") elements into
groups of 5, then find the median of each group. We then execute a
recursive call to find a median of medians
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P"). This
guarantees ![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P")
between
![\\frac{3n}{10}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B3n%7D%7B10%7D "\frac{3n}{10}")
and
![\\frac{7n}{10}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B7n%7D%7B10%7D "\frac{7n}{10}")
in rank. We get the recurrence:

\
![\\begin{aligned} T(n) &= T\\left(\\frac{n}{5}\\right) +
T\\left(\\frac{7n}{10}\\right) + O(n)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%28n%29%20%26%3D%20T%5Cleft%28%5Cfrac%7Bn%7D%7B5%7D%5Cright%29%20%2B%20T%5Cleft%28%5Cfrac%7B7n%7D%7B10%7D%5Cright%29%20%2B%20O%28n%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        T(n) &= T\left(\frac{n}{5}\right) + T\left(\frac{7n}{10}\right) + O(n)
                    \end{aligned}")\

We can prove that ![T(n) =
O(n)](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%3D%20O%28n%29 "T(n) = O(n)").[^23^](#fn23)

For more information, look up the [“median of
medians”](https://en.wikipedia.org/wiki/Median_of_medians) algorithm
online.

Primality Testing {#cha:primality_testing}
=================

Randomized Algorithm Types {#sec:randomized_algorithm_types}
--------------------------

There are two kinds of randomized algorithms:

### Las Vegas Type Algorithms {#sub:las_vegas}

Las Vegas algorithms always return the correct output, and have good
expected runtime. An example of this type of algorithm is quicksort.

We can convert Las Vegas to Monte Carlo algorithms by stopping after
some time and outputting a junk answer.

### Monte Carlo Type Algorithms {#sub:monte_carlo_type}

Monte Carlo algorithms are quick with a high probability of success, and
have a good guaranteed runtime.

If we have a fast correctness test we can convert Monte Carlo algorithms
to Las Vegas algorithms, repeating the algorithm if output isn’t
correct.

Primality Testing Using a Monte Carlo Algorithm {#sec:primality_testing_using_a_monte_carlo_algorithm}
-----------------------------------------------

Given an odd number
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"), is
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")
composite?[^24^](#fn24) Phrased this way, we have a decision problem in
NP, which is verifying `YES` answers.

It is important to know that while the input is
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"), the input
size is
![\\log(n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Clog%28n%29 "\log(n)")
– the number of bits used expressing
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"). Thus trial
division
(![O(\\sqrt{n})](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Csqrt%7Bn%7D%29 "O(\sqrt{n})")
time) is not poly-time.[^25^](#fn25)

We use the following theorem to help us with our solutions:

### Fermat’s Little Theorem {#sub:fermat_s_little_theorem}

If ![p](http://chart.apis.google.com/chart?cht=tx&chl=p "p") is prime,
then ![\\forall 0 \< a \<
p](http://chart.apis.google.com/chart?cht=tx&chl=%5Cforall%200%20%3C%20a%20%3C%20p "\forall 0 < a < p"):
![a\^{p-1} \\equiv 1 \\mod
p](http://chart.apis.google.com/chart?cht=tx&chl=a%5E%7Bp-1%7D%20%5Cequiv%201%20%5Cmod%20p "a^{p-1} \equiv 1 \mod p").

We can prove this by showing:

\
![\\begin{aligned} a\^p(p-1)! \\equiv (p-1)! \\mod p \\\\ a\^p \\equiv 1
\\mod p
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20a%5Ep%28p-1%29%21%20%5Cequiv%20%28p-1%29%21%20%5Cmod%20p%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20a%5Ep%20%5Cequiv%201%20%5Cmod%20p%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        a^p(p-1)! \equiv (p-1)! \mod p \\
                        a^p \equiv 1 \mod p
                    \end{aligned}")\

The contrapositive[^26^](#fn26) states that whenever ![a\^{n-1} \\not
\\equiv 1 \\mod
n](http://chart.apis.google.com/chart?cht=tx&chl=a%5E%7Bn-1%7D%20%5Cnot%20%5Cequiv%201%20%5Cmod%20n "a^{n-1} \not \equiv 1 \mod n")
doesn’t hold for ![0 \< a \<
n](http://chart.apis.google.com/chart?cht=tx&chl=0%20%3C%20a%20%3C%20n "0 < a < n"),
then ![a](http://chart.apis.google.com/chart?cht=tx&chl=a "a") is a
*Fermat Witness* to
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") being
composite.

### Prime-Testing {#sub:prime_testing}

The idea is to test
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") being
composite using randomly-generated
![a](http://chart.apis.google.com/chart?cht=tx&chl=a "a") in ![[1,
\\ldots,
n-1]](http://chart.apis.google.com/chart?cht=tx&chl=%5B1%2C%20%5Cldots%2C%20n-1%5D "[1, \ldots, n-1]")
for being a Fermat witness.

If it is, then yes
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is composite.
If it isn’t, then maybe
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is prime.

The bad news is that there are composite numbers Fermat
witnesses[^27^](#fn27).

Where ![n-1 = 2\^t
u](http://chart.apis.google.com/chart?cht=tx&chl=n-1%20%3D%202%5Et%20u "n-1 = 2^t u")
(for an odd ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u")),
we need a that ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")
is prime. We define ![a \\in [1,
n-1]](http://chart.apis.google.com/chart?cht=tx&chl=a%20%5Cin%20%5B1%2C%20n-1%5D "a \in [1, n-1]")
as a strong witness of
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") being
composite if for some ![0 \\le i \<
t](http://chart.apis.google.com/chart?cht=tx&chl=0%20%5Cle%20i%20%3C%20t "0 \le i < t"),
![k = 2\^i
u](http://chart.apis.google.com/chart?cht=tx&chl=k%20%3D%202%5Ei%20u "k = 2^i u"):

\
![\\begin{aligned} a\^k \\not \\equiv 1 , -1 \\mod n \\\\ a\^{2k}
\\equiv 1 \\mod n
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20a%5Ek%20%5Cnot%20%5Cequiv%201%20%2C%20-1%20%5Cmod%20n%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20a%5E%7B2k%7D%20%5Cequiv%201%20%5Cmod%20n%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        a^k \not \equiv 1 , -1 \mod n \\
                        a^{2k} \equiv 1 \mod n
                    \end{aligned}")\

In CLRS, they prove that if
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is prime,
there are no strong witnesses; they also prove that if
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is composite,
there are ![\\ge
\\frac{n-1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20%5Cfrac%7Bn-1%7D%7B2%7D "\ge \frac{n-1}{2}")
strong witnesses.

### Implementation {#sub:implementation}

    witness (a , n):
    u = n - 1 % 2
    t = log((n - 1) / u) // base 2
    x[0] =  a ^ u mod n
    for i = 1 ... t:
        x[i] = x[i-1]^2 mod n
        if (x[i] == 1 and x[i-1] != 1 and x[i-1] != n - 1):
            return true // a is a strong witness to n being composite
    return x[t] != 1 // a is a Fermat witness to n being composite
                        

The runtime of this algorithm is polynomial in ![\\log
n](http://chart.apis.google.com/chart?cht=tx&chl=%5Clog%20n "\log n").

### Miller-Rabin Algorithm {#sub:miller_rabin_algorithm}

The idea of this algorithm is to test
![s](http://chart.apis.google.com/chart?cht=tx&chl=s "s") times that
random numbers aren’t witnesses to
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") being
composite.

    isComposite(n):
        for i = 1 ... s:
            x = rand(1...n-1)
            if (witness(x, n)):
                return YES // n is composite
        return MAYBE // n is prime
                        

If ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is prime,
the algorithm is always correct. IF
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is composite
however, we can tabulate the probability it is unsure:

\
![\\begin{aligned} Pr\\{ \\text{Alg outputs \\textsc{maybe}}\\} &=
Pr\\left\\{ \\cap\_{j=1}\^s \\left\\{\\text{at trial \$j\$, \$x\$ is not
a strong witness } \\right\\} \\right\\} \\\\ &= \\frac{1}{2\^s}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Pr%5C%7B%20%5Ctext%7BAlg%20outputs%20%5Ctextsc%7Bmaybe%7D%7D%5C%7D%20%26%3D%20Pr%5Cleft%5C%7B%20%5Ccap_%7Bj%3D1%7D%5Es%20%5Cleft%5C%7B%5Ctext%7Bat%20trial%20%24j%24%2C%20%24x%24%20is%20not%20a%20strong%20witness%20%7D%20%5Cright%5C%7D%20%5Cright%5C%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7B2%5Es%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        Pr\{ \text{Alg outputs \textsc{maybe}}\} &= Pr\left\{ \cap_{j=1}^s \left\{\text{at trial $j$, $x$ is not a strong witness } \right\} \right\} \\
                        &= \frac{1}{2^s}
                    \end{aligned}")\

This is a Monte-Carlo algorithm with a [^28^](#fn28).

Complexity Classes {#sec:complexity_classes}
------------------

We can define a number of decision classes:

P
:   are the decision problems solvable in polynomial time. These are
    also known as the class of languages
    ![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") accepted
    in polynomial time.

NP
:   are the class of languages
    ![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") accepted
    in non-deterministic polynomial time. These are also known as the
    decision problems that can be in polynomial time[^29^](#fn29).

There are a few[^30^](#fn30) openproblems about this[^31^](#fn31):

\
![\\begin{aligned} {\\textsc{NP}\\xspace}&\\stackrel{?}{=}
\\textsc{co-np} \\\\ {\\textsc{P}\\xspace}&\\stackrel{?}{=}
{\\textsc{NP}\\xspace}\\\\ {\\textsc{P}\\xspace}&\\stackrel{?}{=}
{\\textsc{NP}\\xspace}\\cup \\textsc{co-np} \\\\
{\\textsc{P}\\xspace}&\\stackrel{?}{=} \\textsc{rp} \\\\ \\textsc{rp}
&\\stackrel{?}{=}
{\\textsc{NP}\\xspace}\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D%26%5Cstackrel%7B%3F%7D%7B%3D%7D%20%5Ctextsc%7Bco-np%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Ctextsc%7BP%7D%5Cxspace%7D%26%5Cstackrel%7B%3F%7D%7B%3D%7D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Ctextsc%7BP%7D%5Cxspace%7D%26%5Cstackrel%7B%3F%7D%7B%3D%7D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D%5Ccup%20%5Ctextsc%7Bco-np%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Ctextsc%7BP%7D%5Cxspace%7D%26%5Cstackrel%7B%3F%7D%7B%3D%7D%20%5Ctextsc%7Brp%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctextsc%7Brp%7D%20%26%5Cstackrel%7B%3F%7D%7B%3D%7D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D%5Cend%7Baligned%7D "\begin{aligned}
                    {\textsc{NP}\xspace}&\stackrel{?}{=} \textsc{co-np} \\
                    {\textsc{P}\xspace}&\stackrel{?}{=} {\textsc{NP}\xspace}\\
                    {\textsc{P}\xspace}&\stackrel{?}{=} {\textsc{NP}\xspace}\cup \textsc{co-np} \\
                    {\textsc{P}\xspace}&\stackrel{?}{=} \textsc{rp} \\
                    \textsc{rp} &\stackrel{?}{=} {\textsc{NP}\xspace}\end{aligned}")\

### Randomized Polynomial Time, One Sided Monte-Carlo {#sub:randomized_polynomial_time_one_sided_monte_carlo}

The rp class of problems is the class of languages that have a
randomized algorithm
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") running in
worst-case polynomial time such that for any input
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x"):

\
![\\begin{aligned} x \\in L \\implies Pr[\\text{\$A(x)\$ accepts}] &
\\ge \\frac{1}{2} \\\\ x \\not \\in L \\implies Pr[\\text{\$A(x)\$
accepts}] & = 0
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20x%20%5Cin%20L%20%5Cimplies%20Pr%5B%5Ctext%7B%24A%28x%29%24%20accepts%7D%5D%20%26%20%5Cge%20%5Cfrac%7B1%7D%7B2%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20x%20%5Cnot%20%5Cin%20L%20%5Cimplies%20Pr%5B%5Ctext%7B%24A%28x%29%24%20accepts%7D%5D%20%26%20%3D%200%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        x \in L \implies Pr[\text{$A(x)$ accepts}] & \ge \frac{1}{2} \\
                        x \not \in L \implies Pr[\text{$A(x)$ accepts}] & = 0
                    \end{aligned}")\

In other words, the algorithm always returns no for input
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x") that don’t
match, and *sometimes* returns yes for
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x") that match
[^32^](#fn32).

We know that ![{\\textsc{P}\\xspace}\\subseteq
\\textsc{rp}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%5Csubseteq%20%5Ctextsc%7Brp%7D "{\textsc{P}\xspace}\subseteq \textsc{rp}"),
since the probabilities that Pproblems will accept and decline are 0 and
1 respectively.

Supposing language
![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") is in rp, i.e.
there is a randomized algorithm
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") that fits the
definitions of rp.
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") depends on
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x") and random
choices. If we think of the random choices as a string
![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y") of random
bits, we write ![A(x,
y)](http://chart.apis.google.com/chart?cht=tx&chl=A%28x%2C%20y%29 "A(x, y)")
as applying ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") on
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x") with random
bits ![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y"). Since
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") runs in
polynomial with respect to
![|x|](http://chart.apis.google.com/chart?cht=tx&chl=%7Cx%7C "|x|") (![A
\\in
p(|x|)](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Cin%20p%28%7Cx%7C%29 "A \in p(|x|)")),
we know that the string ![y \\in
p(|x|)](http://chart.apis.google.com/chart?cht=tx&chl=y%20%5Cin%20p%28%7Cx%7C%29 "y \in p(|x|)").
Using ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") as the
verification algorithm and
![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y") as the
certificate, we can show that
![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") is in NP.

### Zero Error Probabilistic Polynomial Time {#sub:zero_error_probabilistic_polynomial_time}

zpp is the class of languages accepted by Las Vegas algorithms with an
expected polynomial runtime.

Note that ![{\\textsc{P}\\xspace}\\subseteq \\textsc{zpp} \\subseteq
\\textsc{rp}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%5Csubseteq%20%5Ctextsc%7Bzpp%7D%20%5Csubseteq%20%5Ctextsc%7Brp%7D "{\textsc{P}\xspace}\subseteq \textsc{zpp} \subseteq \textsc{rp}").

An in-class quiz consisted in proving that ![\\textsc{zpp} =
\\textsc{rp} \\cap
\\text{co-}\\textsc{rp}](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctextsc%7Bzpp%7D%20%3D%20%5Ctextsc%7Brp%7D%20%5Ccap%20%5Ctext%7Bco-%7D%5Ctextsc%7Brp%7D "\textsc{zpp} = \textsc{rp} \cap \text{co-}\textsc{rp}")
is true.

See [here for more
details](https://en.wikipedia.org/wiki/RP_(complexity)) on the co-rp
complexity class.

### Open Questions {#sub:open_questions}

It is openif these containments are proper, or if they can be made more
precise:

\
![\\begin{aligned} {\\textsc{P}\\xspace}\\subseteq \\textsc{rp}
\\subseteq
{\\textsc{NP}\\xspace}\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Ctextsc%7BP%7D%5Cxspace%7D%5Csubseteq%20%5Ctextsc%7Brp%7D%20%5Csubseteq%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D%5Cend%7Baligned%7D "\begin{aligned}
                        {\textsc{P}\xspace}\subseteq \textsc{rp} \subseteq {\textsc{NP}\xspace}\end{aligned}")\

Finger-Printing - Pattern Matching and Polynomial Identities {#cha:finger_printing_for_pattern_matching_and_polynomial_identities}
============================================================

String Equality {#sec:string_equality}
---------------

It’s pretty expensive to compare strings, especially if they’re long,
stored in separate locations, etc. We compare a smaller fingerprint
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x") where
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x") is an
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")-bit binary
number (![x \<
2\^n](http://chart.apis.google.com/chart?cht=tx&chl=x%20%3C%202%5En "x < 2^n")).
For a randomly chosen ![p \\in \\{ 1 \\ldots M
\\}](http://chart.apis.google.com/chart?cht=tx&chl=p%20%5Cin%20%5C%7B%201%20%5Cldots%20M%20%5C%7D "p \in \{ 1 \ldots M \}")[^33^](#fn33),
we can set:

\
![\\begin{aligned} H\_p (x) &= x \\mod p
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20H_p%20%28x%29%20%26%3D%20x%20%5Cmod%20p%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    H_p (x) &= x \mod p
                \end{aligned}")\

While ![x =
y](http://chart.apis.google.com/chart?cht=tx&chl=x%20%3D%20y "x = y")
implies ![H\_p(x) =
H\_p(y)](http://chart.apis.google.com/chart?cht=tx&chl=H_p%28x%29%20%3D%20H_p%28y%29 "H_p(x) = H_p(y)"),
this contrapositive doesn’t hold true if
![p](http://chart.apis.google.com/chart?cht=tx&chl=p "p") divides ![|x -
y|](http://chart.apis.google.com/chart?cht=tx&chl=%7Cx%20-%20y%7C "|x - y|").

With repeated (in)equality testing of
![H\_p(x)](http://chart.apis.google.com/chart?cht=tx&chl=H_p%28x%29 "H_p(x)")
to
![H\_p(y)](http://chart.apis.google.com/chart?cht=tx&chl=H_p%28y%29 "H_p(y)"),
we can build confidence about ![x \\stackrel{?}{=}
y](http://chart.apis.google.com/chart?cht=tx&chl=x%20%5Cstackrel%7B%3F%7D%7B%3D%7D%20y "x \stackrel{?}{=} y").
Our algorithm will know for sure when ![x \\ne
y](http://chart.apis.google.com/chart?cht=tx&chl=x%20%5Cne%20y "x \ne y"),
but it can’t be sure they are equal. Thus this is a Monte-Carlo
Algorithm.

To better analyze our algorithm, we want to define
![Pr\\{\\text{failure}\\}](http://chart.apis.google.com/chart?cht=tx&chl=Pr%5C%7B%5Ctext%7Bfailure%7D%5C%7D "Pr\{\text{failure}\}").
If we define
![\\pi(n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Cpi%28n%29 "\pi(n)")
as the number of primes less than
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"), then
![\\pi(n) \\approx \\frac{n}{\\ln
n}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cpi%28n%29%20%5Capprox%20%5Cfrac%7Bn%7D%7B%5Cln%20n%7D "\pi(n) \approx \frac{n}{\ln n}")[^34^](#fn34).
Another result from number theory dictates that the number of prime
divisors of ![A \<
2\^n](http://chart.apis.google.com/chart?cht=tx&chl=A%20%3C%202%5En "A < 2^n")
is
![\\pi(n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Cpi%28n%29 "\pi(n)").

\
![\\begin{aligned} Pr\\{\\text{failure}\\} &= \\frac{\\text{number of
primes \$p \< M\$ and \$p\$ divides \$|x-y| \< 2\^n\$}}{\\pi(M)} \\\\ &=
\\frac{\\pi(n)}{\\pi(M)}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Pr%5C%7B%5Ctext%7Bfailure%7D%5C%7D%20%26%3D%20%5Cfrac%7B%5Ctext%7Bnumber%20of%20primes%20%24p%20%3C%20M%24%20and%20%24p%24%20divides%20%24%7Cx-y%7C%20%3C%202%5En%24%7D%7D%7B%5Cpi%28M%29%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B%5Cpi%28n%29%7D%7B%5Cpi%28M%29%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    Pr\{\text{failure}\} &= \frac{\text{number of primes $p < M$ and $p$ divides $|x-y| < 2^n$}}{\pi(M)} \\
                    &= \frac{\pi(n)}{\pi(M)}
                \end{aligned}")\

If we pick ![M =
n\^2](http://chart.apis.google.com/chart?cht=tx&chl=M%20%3D%20n%5E2 "M = n^2"),
then we have
![Pr\\{\\text{failure}\\}](http://chart.apis.google.com/chart?cht=tx&chl=Pr%5C%7B%5Ctext%7Bfailure%7D%5C%7D "Pr\{\text{failure}\}"):

\
![\\begin{aligned} Pr\\{\\text{failure}\\} &= \\frac{n}{\\ln n}
\\frac{\\ln n\^2}{n\^2} \\\\ &= \\frac{2}{n}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Pr%5C%7B%5Ctext%7Bfailure%7D%5C%7D%20%26%3D%20%5Cfrac%7Bn%7D%7B%5Cln%20n%7D%20%5Cfrac%7B%5Cln%20n%5E2%7D%7Bn%5E2%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B2%7D%7Bn%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    Pr\{\text{failure}\} &= \frac{n}{\ln n} \frac{\ln n^2}{n^2} \\
                    &= \frac{2}{n}
                \end{aligned}")\

Pattern Matching {#sec:pattern_matching}
----------------

We can use a similar idea as string matching for pattern matching:

Given a test string
![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") and a pattern
string ![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") (where
![|T| =
n](http://chart.apis.google.com/chart?cht=tx&chl=%7CT%7C%20%3D%20n "|T| = n"),
![|P| =
m](http://chart.apis.google.com/chart?cht=tx&chl=%7CP%7C%20%3D%20m "|P| = m")),
does ![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") appear as
a substring of
![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T")?

There’s a straightforward
![O(nm)](http://chart.apis.google.com/chart?cht=tx&chl=O%28nm%29 "O(nm)")
solution[^35^](#fn35).

### Rabin-Karp Algorithm {#sub:rabin_karp_algorithm}

**Rabin-Karp** supplies a simple and efficient randomized algorithm.

Suppose ![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") and
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") are binary
strings. We want to compare the fingerprint of
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") to
fingerprints of successive substrings of
![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T").

Using a “rolling hash”, these fingerprints in
![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") can be
computed very efficiently[^36^](#fn36).

    def hasMatch(text T, text P):
        p = randomPrime(1 ... m)
        compute Hp(P)
        compute Hp(T[1 ... m])
        for i in range(1 ... n-m+1):
            if Hp(P) == Hp(T[i ... i+m-1])
                return PROBABLE_MATCH
        output NO_MATCH
                        

We have the runtime of ![O(n +
m)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%2B%20m%29 "O(n + m)")
arithmetic operations. We are more concerned about the failure rate -
the probability that we output Probable\_Match without there being a
real match. Iff
![p](http://chart.apis.google.com/chart?cht=tx&chl=p "p")
divides[^37^](#fn37) ![|P - T[i \\ldots i+m
-1]|](http://chart.apis.google.com/chart?cht=tx&chl=%7CP%20-%20T%5Bi%20%5Cldots%20i%2Bm%20-1%5D%7C "|P - T[i \ldots i+m -1]|")
for some ![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i"), then
![p](http://chart.apis.google.com/chart?cht=tx&chl=p "p") divides
![\\Pi\_i |P - T[i \\ldots i+m - 1] \\le
2\^{nm}](http://chart.apis.google.com/chart?cht=tx&chl=%5CPi_i%20%7CP%20-%20T%5Bi%20%5Cldots%20i%2Bm%20-%201%5D%20%5Cle%202%5E%7Bnm%7D "\Pi_i |P - T[i \ldots i+m - 1] \le 2^{nm}").

Thus, the following of failure is: (and to recap…)

\
![\\begin{aligned} & \\text{\$p\$ divides } |P - T[i \\ldots i + m - 1]
\\text{ for some \$i\$} \\\\ \\implies & \\text{\$p\$ divides } \\Pi\_i
|P - T[i \\ldots i + m - 1]| \\le 2\^{nm} \\\\ \\implies & Pr\\{
\\text{failure} \\} \\le \\frac{\\pi(nm)}{\\pi(M)}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%20%5Ctext%7B%24p%24%20divides%20%7D%20%7CP%20-%20T%5Bi%20%5Cldots%20i%20%2B%20m%20-%201%5D%20%5Ctext%7B%20for%20some%20%24i%24%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cimplies%20%26%20%5Ctext%7B%24p%24%20divides%20%7D%20%5CPi_i%20%7CP%20-%20T%5Bi%20%5Cldots%20i%20%2B%20m%20-%201%5D%7C%20%5Cle%202%5E%7Bnm%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cimplies%20%26%20Pr%5C%7B%20%5Ctext%7Bfailure%7D%20%5C%7D%20%5Cle%20%5Cfrac%7B%5Cpi%28nm%29%7D%7B%5Cpi%28M%29%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        & \text{$p$ divides } |P - T[i \ldots i + m - 1] \text{ for some $i$} \\
                        \implies & \text{$p$ divides } \Pi_i |P - T[i \ldots i + m - 1]| \le 2^{nm} \\
                        \implies & Pr\{ \text{failure} \} \le \frac{\pi(nm)}{\pi(M)}
                    \end{aligned}")\

Where ![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M") is some
number. We can choose ![M = n\^2
m](http://chart.apis.google.com/chart?cht=tx&chl=M%20%3D%20n%5E2%20m "M = n^2 m"),
then we have:

\
![\\begin{aligned} Pr\\{\\text{failure}\\} &\\le \\frac{nm}{\\ln (nm)}
\\frac{\\ln(n\^2 m)}{n\^2 m} \\\\ &\< \\frac{2}{n}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Pr%5C%7B%5Ctext%7Bfailure%7D%5C%7D%20%26%5Cle%20%5Cfrac%7Bnm%7D%7B%5Cln%20%28nm%29%7D%20%5Cfrac%7B%5Cln%28n%5E2%20m%29%7D%7Bn%5E2%20m%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3C%20%5Cfrac%7B2%7D%7Bn%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        Pr\{\text{failure}\} &\le \frac{nm}{\ln (nm)} \frac{\ln(n^2 m)}{n^2 m} \\
                        &< \frac{2}{n}
                    \end{aligned}")\

i.e. if ![n = 4000 \<
2\^{12}](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3D%204000%20%3C%202%5E%7B12%7D "n = 4000 < 2^{12}")
and ![m = 250 \<
2\^8](http://chart.apis.google.com/chart?cht=tx&chl=m%20%3D%20250%20%3C%202%5E8 "m = 250 < 2^8"),
then ![M = n\^2 m \<
2\^{32}](http://chart.apis.google.com/chart?cht=tx&chl=M%20%3D%20n%5E2%20m%20%3C%202%5E%7B32%7D "M = n^2 m < 2^{32}").
We can use a
![32](http://chart.apis.google.com/chart?cht=tx&chl=32 "32")-bit
fingerprint prime, and the ![Pr\\{\\text{error}\\} \<
10\^{-3}](http://chart.apis.google.com/chart?cht=tx&chl=Pr%5C%7B%5Ctext%7Berror%7D%5C%7D%20%3C%2010%5E%7B-3%7D "Pr\{\text{error}\} < 10^{-3}").

In practice this is slower than Boyer-Moore, but it’s better when you
need to test multiple patterns in one string.

### Verifying Polynomial Identities {#sub:verifying_polynomial_identities}

Given a Vandermonde matrix
![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M"):

\
![\\begin{aligned} M &= \\left[ \\begin{array}{ccccc} 1 & x\_1 & x\_1\^2
& \\ldots & x\_1 \^{n-1} \\\\ \\vdots & \\vdots & \\vdots & \\vdots &
\\vdots \\\\ 1 & x\_n & x\_n\^2 & \\ldots & x\_n \^{n-1} \\end{array}
\\right]
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20M%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%5B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Bccccc%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%201%20%26%20x_1%20%26%20x_1%5E2%20%26%20%5Cldots%20%26%20x_1%20%5E%7Bn-1%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cvdots%20%26%20%5Cvdots%20%26%20%5Cvdots%20%26%20%5Cvdots%20%26%20%5Cvdots%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%201%20%26%20x_n%20%26%20x_n%5E2%20%26%20%5Cldots%20%26%20x_n%20%5E%7Bn-1%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright%5D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    M &=
                    \left[
                        \begin{array}{ccccc}
                            1 & x_1 & x_1^2 & \ldots & x_1 ^{n-1} \\
                            \vdots & \vdots & \vdots & \vdots & \vdots \\
                            1 & x_n & x_n^2 & \ldots & x_n ^{n-1}
                        \end{array}
                    \right]
                \end{aligned}")\

There is the Vandermonde identity: ![\\det(M) = \\Pi\_{j \< i} (x\_i -
x\_j)](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdet%28M%29%20%3D%20%5CPi_%7Bj%20%3C%20i%7D%20%28x_i%20-%20x_j%29 "\det(M) = \Pi_{j < i} (x_i - x_j)").
We can verify this by substituting random values for
variables[^38^](#fn38)[^39^](#fn39)[^40^](#fn40).

### Verifying Polynomial Identities {#sub:verifying_polynomial_identities}

**Theorem**: let ![f(x\_1 \\ldots
x\_n)](http://chart.apis.google.com/chart?cht=tx&chl=f%28x_1%20%5Cldots%20x_n%29 "f(x_1 \ldots x_n)")
be a multivariate polynomial of total degree[^41^](#fn41)
![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d"). If
![f](http://chart.apis.google.com/chart?cht=tx&chl=f "f") is not
identically ![0](http://chart.apis.google.com/chart?cht=tx&chl=0 "0")
and if we choose values ![a\_1 \\ldots
a\_n](http://chart.apis.google.com/chart?cht=tx&chl=a_1%20%5Cldots%20a_n "a_1 \ldots a_n")
for ![x\_1 \\ldots
x\_n](http://chart.apis.google.com/chart?cht=tx&chl=x_1%20%5Cldots%20x_n "x_1 \ldots x_n")
independently and uniformly from a finite set
![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S"), then we claim
![Pr\\{ f(a\_1 \\ldots a\_n) = 0\\} \\le
\\frac{d}{|S|}](http://chart.apis.google.com/chart?cht=tx&chl=Pr%5C%7B%20f%28a_1%20%5Cldots%20a_n%29%20%3D%200%5C%7D%20%5Cle%20%5Cfrac%7Bd%7D%7B%7CS%7C%7D "Pr\{ f(a_1 \ldots a_n) = 0\} \le \frac{d}{|S|}").

For example, if ![S = \\{ 0, \\pm 1, \\pm 2 \\ldots \\pm
d\\}](http://chart.apis.google.com/chart?cht=tx&chl=S%20%3D%20%5C%7B%200%2C%20%5Cpm%201%2C%20%5Cpm%202%20%5Cldots%20%5Cpm%20d%5C%7D "S = \{ 0, \pm 1, \pm 2 \ldots \pm d\}"),
then ![Pr\\{f(a\_1, \\ldots a\_n) = 0 \\} \\le
\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=Pr%5C%7Bf%28a_1%2C%20%5Cldots%20a_n%29%20%3D%200%20%5C%7D%20%5Cle%20%5Cfrac%7B1%7D%7B2%7D "Pr\{f(a_1, \ldots a_n) = 0 \} \le \frac{1}{2}").

**Proof**: We can do this by induction on
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"):

The basic case is when
![n=1](http://chart.apis.google.com/chart?cht=tx&chl=n%3D1 "n=1") single
variable of degree
![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d") implies that
there are ![\\le
d](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20d "\le d")
roots and in general, we can substitute and evaluate..

\
![\\begin{aligned} f(x\_1 \\ldots x\_n) &= \\sum\_{t=0} x\_1\^t g(x\_2
\\ldots x\_n)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28x_1%20%5Cldots%20x_n%29%20%26%3D%20%5Csum_%7Bt%3D0%7D%20x_1%5Et%20g%28x_2%20%5Cldots%20x_n%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    f(x_1 \ldots x_n) &= \sum_{t=0} x_1^t g(x_2 \ldots x_n)
                \end{aligned}")\

### Verifying Matrix Multiplication {#sub:verifying_matrix_multiplication}

Given three matrices
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A"),
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B"), and
![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") that are all
![n \\times
n](http://chart.apis.google.com/chart?cht=tx&chl=n%20%5Ctimes%20n "n \times n")
in size. We want to verify that ![AB =
C](http://chart.apis.google.com/chart?cht=tx&chl=AB%20%3D%20C "AB = C").

While the naive matrix multiplication is
![O(n\^3)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E3%29 "O(n^3)"),
one of the faster multiplication algorithms is
![O(n\^{2.376})](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E%7B2.376%7D%29 "O(n^{2.376})")
by Coppersmith and Winograd in 1990[^42^](#fn42). These are complicated
to implement, and the chance of implementing buggy programs is very
high.

The idea is that by choosing a vector ![x = [x\_1 \\ldots
x\_n]](http://chart.apis.google.com/chart?cht=tx&chl=x%20%3D%20%5Bx_1%20%5Cldots%20x_n%5D "x = [x_1 \ldots x_n]"),
we can quickly verify that ![ABx =
Cx](http://chart.apis.google.com/chart?cht=tx&chl=ABx%20%3D%20Cx "ABx = Cx")
is correct[^43^](#fn43)

        choose each x[i] = rand(0, 1)
        if A(Bx) == C(x):
            return MAYBE
        return NO
                    

We can set the probability of error ![Pr\\{\\text{error}\\} \\le
\\frac{d}{|S|} =
\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=Pr%5C%7B%5Ctext%7Berror%7D%5C%7D%20%5Cle%20%5Cfrac%7Bd%7D%7B%7CS%7C%7D%20%3D%20%5Cfrac%7B1%7D%7B2%7D "Pr\{\text{error}\} \le \frac{d}{|S|} = \frac{1}{2}")
(since ![S = \\{0, 1\\} \\to |S| =
2](http://chart.apis.google.com/chart?cht=tx&chl=S%20%3D%20%5C%7B0%2C%201%5C%7D%20%5Cto%20%7CS%7C%20%3D%202 "S = \{0, 1\} \to |S| = 2")).

This runs in
![O(n\^2)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E2%29 "O(n^2)")
time, and we can repeat it to reduce error.

Linear Programming in Low Dimension {#cha:linear_programming}
===================================

Linear programming is a math (and computational) method for achieving
the best outcome given a model expressed as a series of linear
relationships.

In other words, given a ![d \\times
1](http://chart.apis.google.com/chart?cht=tx&chl=d%20%5Ctimes%201 "d \times 1")-vector
![\\vec{x}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cvec%7Bx%7D "\vec{x}"),
an ![n \\times
d](http://chart.apis.google.com/chart?cht=tx&chl=n%20%5Ctimes%20d "n \times d")
matrix ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A"), a ![1
\\times
d](http://chart.apis.google.com/chart?cht=tx&chl=1%20%5Ctimes%20d "1 \times d")
vector ![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c"), and a
![n \\times
1](http://chart.apis.google.com/chart?cht=tx&chl=n%20%5Ctimes%201 "n \times 1")
vector ![b](http://chart.apis.google.com/chart?cht=tx&chl=b "b"),
maximize ![cx](http://chart.apis.google.com/chart?cht=tx&chl=cx "cx")
while satisfying the constraint ![Ax \\le
b](http://chart.apis.google.com/chart?cht=tx&chl=Ax%20%5Cle%20b "Ax \le b").

Expressed differently, we have
![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d") inequalities
we need to satisfy, and
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") variables
![x\_i : i \\in \\{ 0 \\ldots n
\\}](http://chart.apis.google.com/chart?cht=tx&chl=x_i%20%3A%20i%20%5Cin%20%5C%7B%200%20%5Cldots%20n%20%5C%7D "x_i : i \in \{ 0 \ldots n \}")
while we’re trying to maximize ![\\sum c\_i
x\_i](http://chart.apis.google.com/chart?cht=tx&chl=%5Csum%20c_i%20x_i "\sum c_i x_i").

More in this section can be found on [MR section 9.10.1], or see Chapter
4 of the book Computational Geometry by de Berg, van Kreveld, Overmars
and Schwarzkopf, Springer 2000.

Naive Algorithm {#sec:naive_algorithm}
---------------

In ![2](http://chart.apis.google.com/chart?cht=tx&chl=2 "2")D, each
constraint ![a\_1 x\_1 + a\_2 x\_2 \\le
b](http://chart.apis.google.com/chart?cht=tx&chl=a_1%20x_1%20%2B%20a_2%20x_2%20%5Cle%20b "a_1 x_1 + a_2 x_2 \le b")
is a half-space. As long as the feasible region is non-empty and is
bounded by an inequality[^44^](#fn44), an optimal solution is at a
meeting point of at two lines - a vertex[^45^](#fn45).

This gives us a stupid algorithm: try all ![{n \\choose
d}](http://chart.apis.google.com/chart?cht=tx&chl=%7Bn%20%5Cchoose%20d%7D "{n \choose d}")
sets of vertexes, eliminate infeasible vertexes, then find the maximum
objective value. This gives an ![O({n \\choose d}) =
O(n\^d)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%7Bn%20%5Cchoose%20d%7D%29%20%3D%20O%28n%5Ed%29 "O({n \choose d}) = O(n^d)")
algorithm.

Applications of Linear Programming {#sec:applications_of_linear_programming}
----------------------------------

We can use this to plan menus. With
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") nutrients, we
need ![b\_i](http://chart.apis.google.com/chart?cht=tx&chl=b_i "b_i") of
nutrient ![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i"). With
![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d") foods, each
food ![j](http://chart.apis.google.com/chart?cht=tx&chl=j "j") has a
cost ![c\_j](http://chart.apis.google.com/chart?cht=tx&chl=c_j "c_j")
and an amount
![a\_{i,j}](http://chart.apis.google.com/chart?cht=tx&chl=a_%7Bi%2Cj%7D "a_{i,j}")
of nutrient ![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i").

Defining
![x\_j](http://chart.apis.google.com/chart?cht=tx&chl=x_j "x_j") as the
volume of food ![j](http://chart.apis.google.com/chart?cht=tx&chl=j "j")
purchased, we want to minimize
![cx](http://chart.apis.google.com/chart?cht=tx&chl=cx "cx") while
maintaining that ![Ax \\ge
b](http://chart.apis.google.com/chart?cht=tx&chl=Ax%20%5Cge%20b "Ax \ge b").

History of Linear Programming {#sec:history_of_linear_programming}
-----------------------------

### Simplex Method {#sub:simplex_method}

**Dantzig** introduced the simplex method in the 1940s, spurring the
development of computers. Geometrically, it walks from one vertex of a
feasible region to an adjacent one according to a that dictates which
inequality to remove and which to add. For almost all simplex pivot
rules, we know examples taking exponential time.

The *Hirsch Conjecture* conjects that the diameter of a convex
![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d")-dimension
polyhedron with
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") inequalities
is ![\\le n -
d](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20n%20-%20d "\le n - d").
Sadly, it was disproved in 2012.

open: This doesn’t mean that there is no polynomial (or even linear)
bound.

In general though, the simplex method is in practice.

### Other Algorithms {#sub:other_algorithms}

There have been some polynomial-time algorithms for linear programming:

Katchian
:   discovered the ellipsoid method in 1980.

Karkarkar
:   discovered the interior point method in 1984 (it operates on bit
    representations of numbers).

open: Is there an algorithm that uses the number of arithmetic
operations polynomial in both
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") and
![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d")?

The 1970s and 1980s saw linear programming being used in small (![d=2,
3](http://chart.apis.google.com/chart?cht=tx&chl=d%3D2%2C%203 "d=2, 3"))
dimensions.

Uses of this were finding the best line fitting points, and whether a
cast can be removed from a mold[^46^](#fn46).

Finally, *Megiddo* found an algorithm that runs in
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")
when ![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d") is
fixed[^47^](#fn47).

Randomized Incremental Linear Programming Algorithm {#sec:randomized_incremental_linear_programming_algorithm}
---------------------------------------------------

We’re going to examine Seidel’s Randomized Incremental Linear
Programming Algorithm.

The idea is that we want to add half-planes
![h\_i](http://chart.apis.google.com/chart?cht=tx&chl=h_i "h_i") one by
one, updating the optimal solution vertex
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") every time.

When we add
![h\_i](http://chart.apis.google.com/chart?cht=tx&chl=h_i "h_i"), there
are two cases:

1.  In the case that ![v \\in
    h\_i](http://chart.apis.google.com/chart?cht=tx&chl=v%20%5Cin%20h_i "v \in h_i"),
    we have no work to do.

2.  In the case that ![v \\not \\in
    h\_i](http://chart.apis.google.com/chart?cht=tx&chl=v%20%5Cnot%20%5Cin%20h_i "v \not \in h_i"),
    we need to find a new optimum. We know that the new optimum will
    line on
    ![\\ell\_i](http://chart.apis.google.com/chart?cht=tx&chl=%5Cell_i "\ell_i"),
    a line the
    ![h\_i](http://chart.apis.google.com/chart?cht=tx&chl=h_i "h_i")
    plane. So we solve the
    ![1](http://chart.apis.google.com/chart?cht=tx&chl=1 "1")-dimensional
    LP problem along line
    ![\\ell\_i](http://chart.apis.google.com/chart?cht=tx&chl=%5Cell_i "\ell_i").

    The 1D LP (lp1) algorithm runs as follows: (Where
    ![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") is a set
    of rays in 1D)

        LP_1(L):
            find and return lowest upper bound on x
                            

    lp\_1 runs in
    ![O(|L|)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%7CL%7C%29 "O(|L|)").

    Then, we can implement
    ![LP\_2(H)](http://chart.apis.google.com/chart?cht=tx&chl=LP_2%28H%29 "LP_2(H)"),
    ![H = \\{h\_1 \\ldots
    h\_n\\}](http://chart.apis.google.com/chart?cht=tx&chl=H%20%3D%20%5C%7Bh_1%20%5Cldots%20h_n%5C%7D "H = \{h_1 \ldots h_n\}")
    as follows:

        LP_2(H):
            shuffle H
            v = point at infinity
            for i = 1 ... n: // add H[i]
                if v is not in H[i]:
                    v = LP_1(intersect(H[1 ... i-1]), L[i])
                            

    Since lp\_1![=
    O(i)](http://chart.apis.google.com/chart?cht=tx&chl=%3D%20O%28i%29 "= O(i)")
    in this implementation, then it runs in worst-case
    ![O(n\^2)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E2%29 "O(n^2)").

    We can calculate the expected runtime using **backwards
    analysis**[^48^](#fn48):

    After adding
    ![h\_i](http://chart.apis.google.com/chart?cht=tx&chl=h_i "h_i"),
    suppose the new optimum is vertex
    ![v'](http://chart.apis.google.com/chart?cht=tx&chl=v%27 "v'") is at
    the intersection of
    ![h'](http://chart.apis.google.com/chart?cht=tx&chl=h%27 "h'"), and
    ![h''](http://chart.apis.google.com/chart?cht=tx&chl=h%27%27 "h''").

    Given that we have
    ![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") lines,
    halfplane
    ![h\_i](http://chart.apis.google.com/chart?cht=tx&chl=h_i "h_i") is
    equally likely to be any one of them.

    We did work for
    ![h\_i](http://chart.apis.google.com/chart?cht=tx&chl=h_i "h_i")
    when we call lp\_1, but only if ![h\_i =
    h'](http://chart.apis.google.com/chart?cht=tx&chl=h_i%20%3D%20h%27 "h_i = h'")
    or ![h\_i =
    h''](http://chart.apis.google.com/chart?cht=tx&chl=h_i%20%3D%20h%27%27 "h_i = h''").
    Since
    ![h\_i](http://chart.apis.google.com/chart?cht=tx&chl=h_i "h_i") is
    equally likely to be any of them, we know:

    \
    ![\\begin{aligned} Pr\\{ h\_i \\in \\{h', h''\\} \\} &= \\frac{2}{i}
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Pr%5C%7B%20h_i%20%5Cin%20%5C%7Bh%27%2C%20h%27%27%5C%7D%20%5C%7D%20%26%3D%20%5Cfrac%7B2%7D%7Bi%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                            Pr\{ h_i \in \{h', h''\} \} &= \frac{2}{i}
                        \end{aligned}")\

    Thus we know that the expected total work when calling lp\_1 is:

    \
    ![\\begin{aligned} \\sum\_{i=1}\^n \\frac{2}{i} O(i) &= O(n)
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Csum_%7Bi%3D1%7D%5En%20%5Cfrac%7B2%7D%7Bi%7D%20O%28i%29%20%26%3D%20O%28n%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                            \sum_{i=1}^n \frac{2}{i} O(i) &= O(n)
                        \end{aligned}")\

    In higher dimensions, the
    ![\\frac{2}{i}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B2%7D%7Bi%7D "\frac{2}{i}")
    becomes
    ![\\frac{d}{i}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7Bd%7D%7Bi%7D "\frac{d}{i}"),
    since it takes
    ![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d")
    hyperplanes to specify a vertex. Thus, we have the recurrence
    relation:

    \
    ![\\begin{aligned} T\_d(n) &= T\_d(n-1) + \\frac{d}{n} O
    \\left(T\_{d-1}(n) \\right) \\\\ T\_d(n) &= O(d! n)
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T_d%28n%29%20%26%3D%20T_d%28n-1%29%20%2B%20%5Cfrac%7Bd%7D%7Bn%7D%20O%20%5Cleft%28T_%7Bd-1%7D%28n%29%20%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T_d%28n%29%20%26%3D%20O%28d%21%20n%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                            T_d(n) &= T_d(n-1) + \frac{d}{n} O \left(T_{d-1}(n) \right) \\
                            T_d(n) &= O(d! n)
                        \end{aligned}")\

    I think she mentioned in class that we can solve this recurrence by
    proving with
    ![T\_2(n)](http://chart.apis.google.com/chart?cht=tx&chl=T_2%28n%29 "T_2(n)")
    by induction, then proving
    ![T\_d(n)](http://chart.apis.google.com/chart?cht=tx&chl=T_d%28n%29 "T_d(n)")
    by induction.

Randomized Incremental Disc Fitting {#sec:randomized_incremental_disc_fitting}
-----------------------------------

We can use a similar approach to find the smallest enclosing disk for a
set of points:

Given points ![p\_1 \\ldots p\_n \\in
\\mathbf{R}\^d](http://chart.apis.google.com/chart?cht=tx&chl=p_1%20%5Cldots%20p_n%20%5Cin%20%5Cmathbf%7BR%7D%5Ed "p_1 \ldots p_n \in \mathbf{R}^d"),
find the smallest radius disc enclosing all points.

This is not linear programming (since it involves quadratics), but
Megiddo’s approach still works, so there is an
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")
non-randomized algorithm[^49^](#fn49).

We can create a *randomized-incremental* approach as follows:

Given a disc
![S\_{i-1}](http://chart.apis.google.com/chart?cht=tx&chl=S_%7Bi-1%7D "S_{i-1}")
for a solution to
![i-1](http://chart.apis.google.com/chart?cht=tx&chl=i-1 "i-1") points,
add a new point
![p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i "p_i").

If ![p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i "p_i") is
contained in
![S\_{i-1}](http://chart.apis.google.com/chart?cht=tx&chl=S_%7Bi-1%7D "S_{i-1}"),
![S\_i =
S\_{i-1}](http://chart.apis.google.com/chart?cht=tx&chl=S_i%20%3D%20S_%7Bi-1%7D "S_i = S_{i-1}").

If not, we know that
![S\_i](http://chart.apis.google.com/chart?cht=tx&chl=S_i "S_i") goes
through
![p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i "p_i").

Thus, we have a *easier* (or *smaller*) problem: given some points and a
special point
![p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i "p_i"), find
the smallest disc containing all points and with
![p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i "p_i") on a
boundary. The trick for this question is realizing that
![S\_i](http://chart.apis.google.com/chart?cht=tx&chl=S_i "S_i") goes
through both
![p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i "p_i") and
![p\_{\\text{previous
max}}](http://chart.apis.google.com/chart?cht=tx&chl=p_%7B%5Ctext%7Bprevious%20max%7D%7D "p_{\text{previous max}}").
Once we have three fixed points on a disc, we have a unique solution.

![Smallest Disc](images/smallest_disc.png "fig:") [fig:smallest~d~isc]

Using this principle leads to an expected[^50^](#fn50) runtime of
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)").

Randomized Algorithms for Satisfiability (sat) {#cha:randomized_algorithms_for_satisfiability_}
==============================================

Generally, satisfiability is the question that asks that given a boolean
formula with ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")
variables and ![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m")
clauses when expressed in CNF, can we assign truth or false values to
the formula. In the example below with
![E](http://chart.apis.google.com/chart?cht=tx&chl=E "E"), assigning
![x\_1](http://chart.apis.google.com/chart?cht=tx&chl=x_1 "x_1") and
![x\_2](http://chart.apis.google.com/chart?cht=tx&chl=x_2 "x_2")
satisfies the formula:

\
![\\begin{aligned} E &= (x\_1 \\lor x\_2 \\lor x\_3) \\land (x\_1 \\lor
\\lnot x\_2) \\land (\\lnot x\_1 \\lor \\lnot x\_2 \\lor \\lnot x\_3)
\\land (x\_2 \\lor \\lnot x\_3) \\\\ x\_1 &= \\text{\\textsc{true}} \\\\
x\_3 &= \\text{\\textsc{false}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%20%26%3D%20%28x_1%20%5Clor%20x_2%20%5Clor%20x_3%29%20%5Cland%20%28x_1%20%5Clor%20%5Clnot%20x_2%29%20%5Cland%20%28%5Clnot%20x_1%20%5Clor%20%5Clnot%20x_2%20%5Clor%20%5Clnot%20x_3%29%20%5Cland%20%28x_2%20%5Clor%20%5Clnot%20x_3%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20x_1%20%26%3D%20%5Ctext%7B%5Ctextsc%7Btrue%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20x_3%20%26%3D%20%5Ctext%7B%5Ctextsc%7Bfalse%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                E &= (x_1 \lor x_2 \lor x_3) \land (x_1 \lor \lnot x_2) \land (\lnot x_1 \lor \lnot x_2 \lor \lnot x_3) \land (x_2 \lor \lnot x_3) \\
                x_1 &= \text{\textsc{true}} \\
                x_3 &= \text{\textsc{false}}
            \end{aligned}")\

The 3-sat algorithm is an NP-variant where all clauses have
![3](http://chart.apis.google.com/chart?cht=tx&chl=3 "3") distinct
literals. The 2-sat algorithm can be solved in polynomial time (in fact,
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")
time).

We can apply this to everything, as it helps with quantified boolean
formulae. sat is a case of one (implicit)
![\\exists](http://chart.apis.google.com/chart?cht=tx&chl=%5Cexists "\exists")
quantifier.

Techniques for sat {#sec:techniques_for_sat}
------------------

There are heuristics that help us “resolve” different clauses. In fact,
we can solve 3-SAT (in a non-obvious way) in
![O(1.5\^n)](http://chart.apis.google.com/chart?cht=tx&chl=O%281.5%5En%29 "O(1.5^n)")
time using deterministic algorithms instead of the obvious ![O(2\^n
\\text{poly}(n,
m))](http://chart.apis.google.com/chart?cht=tx&chl=O%282%5En%20%5Ctext%7Bpoly%7D%28n%2C%20m%29%29 "O(2^n \text{poly}(n, m))").

Using randomized algorithms, we’re going to get better than
![O(1.5\^n)](http://chart.apis.google.com/chart?cht=tx&chl=O%281.5%5En%29 "O(1.5^n)")
for 3-SAT[^51^](#fn51).

We are unlikely to get randomized polynomial time algorithms, since this
implies randomized poly-time for all problems in NP. (eek)

Randomized SAT Solving {#sec:randomized_sat_solving}
----------------------

The idea is that we’re going to be given an input
![E](http://chart.apis.google.com/chart?cht=tx&chl=E "E") in CNF, then
we’re going to “hill climb” to better values. This algorithm is called
Papadimitrion’s algorithm (\`91).

        randomly assign T/F assignment A
        for i = 1...t:
            if A satisfies E return YES
            pick a random unsatisfied clause C
            randomly pick a literal x in C
            flip x's value
        return NO (maybe)
                    

We want to choose
![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t") and determine
the error probability.

Errors occur when
![E](http://chart.apis.google.com/chart?cht=tx&chl=E "E") is satisfiable
and we return no.

Suppose
![A\^\*](http://chart.apis.google.com/chart?cht=tx&chl=A%5E%2A "A^*") is
a truth value assignment that satisfies
![E](http://chart.apis.google.com/chart?cht=tx&chl=E "E"). For
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") as the number
of variables with same value in
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") and
![A\^\*](http://chart.apis.google.com/chart?cht=tx&chl=A%5E%2A "A^*"),
we can say that if
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") reaches
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"), then ![A =
A\^\*](http://chart.apis.google.com/chart?cht=tx&chl=A%20%3D%20A%5E%2A "A = A^*")
and the algorithm outputs YES.

When we re-assign the value of the variable, we know that
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") goes up or
down by ![1](http://chart.apis.google.com/chart?cht=tx&chl=1 "1").

### Randomized Walk on a Line {#sub:randomized_walk_on_a_line}

To do this analysis, we need to know about random walks on lines.

Start at a randomly chosen
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i"), each step
moves right (`i++`) with probability
![\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B2%7D "\frac{1}{2}")
and left (`i--`) with probability
![\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B2%7D "\frac{1}{2}").
When ![i=0](http://chart.apis.google.com/chart?cht=tx&chl=i%3D0 "i=0"),
we always go right. When
![i=n](http://chart.apis.google.com/chart?cht=tx&chl=i%3Dn "i=n"), we
terminate.

The question can now be phrased as: What are the expected number of
steps to get to
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")?

Alternatively, we can analyze this as a Markov chain, or a finite
automaton with probabilistic state movements.

We’re now looking for the expected number of steps to get from
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") to
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") - denoted
![t\_i](http://chart.apis.google.com/chart?cht=tx&chl=t_i "t_i").

\
![\\begin{aligned} t\_n &= 0 \\\\ t\_0 &= 1 + t\_1 \\\\ t\_i &= 1 +
t\_{i-1} \\frac{1}{2} + t\_{i+1} \\frac{1}{2}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20t_n%20%26%3D%200%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20t_0%20%26%3D%201%20%2B%20t_1%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20t_i%20%26%3D%201%20%2B%20t_%7Bi-1%7D%20%5Cfrac%7B1%7D%7B2%7D%20%2B%20t_%7Bi%2B1%7D%20%5Cfrac%7B1%7D%7B2%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        t_n &= 0 \\
                        t_0 &= 1 + t_1 \\
                        t_i &= 1 + t_{i-1} \frac{1}{2} + t_{i+1} \frac{1}{2}
                    \end{aligned}")\

This is awkward for induction, but if we rearrange it, it’s pretty
smooth:

\
![\\begin{aligned} t\_i + t\_{i+1} &= 2 (t\_{i-1} - t\_{i}) \\\\ d\_i &=
t\_i + t\_{i+1} \\\\ d\_0 &= t\_0 - t\_1 \\\\ &= 1 \\\\ d\_i &= 2 +
d\_{i - 1} \\\\ &= 1 + 2i
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20t_i%20%2B%20t_%7Bi%2B1%7D%20%26%3D%202%20%28t_%7Bi-1%7D%20-%20t_%7Bi%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20d_i%20%26%3D%20t_i%20%2B%20t_%7Bi%2B1%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20d_0%20%26%3D%20t_0%20-%20t_1%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20d_i%20%26%3D%202%20%2B%20d_%7Bi%20-%201%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201%20%2B%202i%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        t_i + t_{i+1} &= 2 (t_{i-1} - t_{i}) \\
                        d_i &= t_i + t_{i+1} \\
                        d_0 &= t_0 - t_1 \\
                        &= 1 \\
                        d_i &= 2 + d_{i - 1} \\
                        &= 1 + 2i
                    \end{aligned}")\

If we substitute this for
![t\_i](http://chart.apis.google.com/chart?cht=tx&chl=t_i "t_i"), we
get:

\
![\\begin{aligned} t\_i &= d\_i + t\_{i + 1} \\\\ t\_n &= 0 \\\\ t\_i &=
\\sum\_{j=1}\^{n-1} d\_J \\\\ &= \\sum\_{j=1}\^{n-1} (1 + 2j) \\\\ &=
n-1 + \\sum\_{j=1}\^{n-1} j \\\\ &= (n - i) + n(n-1) - i (i - 1) \\\\ &=
n\^2 - i\^2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20t_i%20%26%3D%20d_i%20%2B%20t_%7Bi%20%2B%201%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20t_n%20%26%3D%200%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20t_i%20%26%3D%20%5Csum_%7Bj%3D1%7D%5E%7Bn-1%7D%20d_J%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_%7Bj%3D1%7D%5E%7Bn-1%7D%20%281%20%2B%202j%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20n-1%20%2B%20%5Csum_%7Bj%3D1%7D%5E%7Bn-1%7D%20j%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%28n%20-%20i%29%20%2B%20n%28n-1%29%20-%20i%20%28i%20-%201%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20n%5E2%20-%20i%5E2%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        t_i &= d_i + t_{i + 1} \\
                        t_n &= 0 \\
                        t_i &= \sum_{j=1}^{n-1} d_J \\
                        &= \sum_{j=1}^{n-1} (1 + 2j) \\
                        &= n-1 + \sum_{j=1}^{n-1} j \\
                        &= (n - i) + n(n-1) - i (i - 1) \\
                        &= n^2 - i^2
                    \end{aligned}")\

The maximum is ![t\_0 =
n\^2](http://chart.apis.google.com/chart?cht=tx&chl=t_0%20%3D%20n%5E2 "t_0 = n^2"),
and ![t\_i \\le
n\^2](http://chart.apis.google.com/chart?cht=tx&chl=t_i%20%5Cle%20n%5E2 "t_i \le n^2").

### Finding Error in our Approximation {#sub:finding_error_in_our_approximation}

For Papadimitrion’s solution to 2-sat, we can model the number of steps
as a random walk on a line. In this representation, we say
![t\_i](http://chart.apis.google.com/chart?cht=tx&chl=t_i "t_i") is a
state where ![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i")
variables are “set correctly”, and assume the worst case scenario of
only one assignment being correct.

In a clause ![C = (\\alpha \\lor
\\beta)](http://chart.apis.google.com/chart?cht=tx&chl=C%20%3D%20%28%5Calpha%20%5Clor%20%5Cbeta%29 "C = (\alpha \lor \beta)")
being modified was not satisfied, then one of
![\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha "\alpha")
or
![\\beta](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbeta "\beta")
must be true in the optimal solution. If only one needs to be inverted,
we pick the correct one
![\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B2%7D "\frac{1}{2}")
the time. If both need to be inverted, we pick the correct one every
time. So we can say that the probability that
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") increases is
![\\ge
\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20%5Cfrac%7B1%7D%7B2%7D "\ge \frac{1}{2}").

By strategically picking the value of
![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t"), we can easily
determine the expected number of repeats. Using Markov’s inequality
(which can be found in Section [sec:markov~si~nequality]):

Supposing ![X \\ge
0](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Cge%200 "X \ge 0")
and ![E(X) =
\\mu](http://chart.apis.google.com/chart?cht=tx&chl=E%28X%29%20%3D%20%5Cmu "E(X) = \mu"),
then ![\\Pr\\{ X \\ge c \\mu\\} \\le
\\frac{1}{c}](http://chart.apis.google.com/chart?cht=tx&chl=%5CPr%5C%7B%20X%20%5Cge%20c%20%5Cmu%5C%7D%20%5Cle%20%5Cfrac%7B1%7D%7Bc%7D "\Pr\{ X \ge c \mu\} \le \frac{1}{c}")
for a constant
![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c"). In our case,
![\\mu =
n\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu%20%3D%20n%5E2 "\mu = n^2"),
so we choose ![c =
2](http://chart.apis.google.com/chart?cht=tx&chl=c%20%3D%202 "c = 2").

\
![\\begin{aligned} \\Pr \\{ \\text{\\\# steps} \> 2n\^2 \\} &\<
\\frac{1}{2}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5CPr%20%5C%7B%20%5Ctext%7B%5C%23%20steps%7D%20%3E%202n%5E2%20%5C%7D%20%26%3C%20%5Cfrac%7B1%7D%7B2%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \Pr \{ \text{\# steps} > 2n^2 \} &< \frac{1}{2}
                    \end{aligned}")\

So set ![t =
2n\^2](http://chart.apis.google.com/chart?cht=tx&chl=t%20%3D%202n%5E2 "t = 2n^2"),
then ![\\Pr\\{\\text{error}\\} \<
\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5CPr%5C%7B%5Ctext%7Berror%7D%5C%7D%20%3C%20%5Cfrac%7B1%7D%7B2%7D "\Pr\{\text{error}\} < \frac{1}{2}").

From this we know that the runtime is not
![O(n\^2)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E2%29 "O(n^2)"),
but it actually is ![O(n\^2 \\cdot poly(n,
m))](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E2%20%5Ccdot%20poly%28n%2C%20m%29%29 "O(n^2 \cdot poly(n, m))")
time.

### Papadimitrion’s Algorithm in Higher Dimensions {#sub:papadimitrion_s_algorithm_in_higher_dimensions}

For a given clause ![C = (\\alpha \\lor \\beta \\lor
\\gamma)](http://chart.apis.google.com/chart?cht=tx&chl=C%20%3D%20%28%5Calpha%20%5Clor%20%5Cbeta%20%5Clor%20%5Cgamma%29 "C = (\alpha \lor \beta \lor \gamma)"),
if ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") does not
satisfy ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C"), but
![A\^\*](http://chart.apis.google.com/chart?cht=tx&chl=A%5E%2A "A^*")
does with ![\\alpha =
T](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha%20%3D%20T "\alpha = T").

\
![\\begin{aligned} \\Pr(\\text{Algorithm flips \$\\alpha\$}) &=
\\frac{1}{3} \\\\ \\Pr(\\text{\$i\$ increases}) &\\ge \\frac{1}{3}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5CPr%28%5Ctext%7BAlgorithm%20flips%20%24%5Calpha%24%7D%29%20%26%3D%20%5Cfrac%7B1%7D%7B3%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5CPr%28%5Ctext%7B%24i%24%20increases%7D%29%20%26%5Cge%20%5Cfrac%7B1%7D%7B3%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \Pr(\text{Algorithm flips $\alpha$}) &= \frac{1}{3} \\
                        \Pr(\text{$i$ increases}) &\ge \frac{1}{3}
                    \end{aligned}")\

So we analyze a random walk on a line:

\
![\\begin{aligned} \\Pr(\\text{i goes to \$i+1\$}) &= \\frac{1}{3} \\\\
\\Pr(\\text{i goes to \$i-1\$}) &= \\frac{1}{3}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5CPr%28%5Ctext%7Bi%20goes%20to%20%24i%2B1%24%7D%29%20%26%3D%20%5Cfrac%7B1%7D%7B3%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5CPr%28%5Ctext%7Bi%20goes%20to%20%24i-1%24%7D%29%20%26%3D%20%5Cfrac%7B1%7D%7B3%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \Pr(\text{i goes to $i+1$}) &= \frac{1}{3} \\
                        \Pr(\text{i goes to $i-1$}) &= \frac{1}{3}
                    \end{aligned}")\

Using Markov’s inequality as before, we are expected to take ![\\approx
2\^n](http://chart.apis.google.com/chart?cht=tx&chl=%5Capprox%202%5En "\approx 2^n")
steps to get to
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"), the final
value[^52^](#fn52).

### Schöning’s Algorithm {#sub:sch_ning_s_algorithm}

Schöning (\`99) gives two improvements to the algorithm:

-   Start with a random assignment
    ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A")

-   An increasing number of trials is not helpful if we’ve taken many
    steps without reaching
    ![A\^\*](http://chart.apis.google.com/chart?cht=tx&chl=A%5E%2A "A^*").
    We’re probably stuck near or at
    ![0](http://chart.apis.google.com/chart?cht=tx&chl=0 "0"), so lets
    pick a “new” random
    ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A").

<!-- -->

    schoning(E):
        for i = 1...s:
            randomly pick A
            repeat t = 1...3n:
                if A satisfies E output YES
                else
                    pick unsatisfied clause C
                    randomly flip a variable in C
        output NO-MAYBE
                        

In the inner loop, the probability of error is ![\\Pr(\\text{error})
\\lesssim 1 - \\left( \\frac{3}{4}
\\right)\^n](http://chart.apis.google.com/chart?cht=tx&chl=%5CPr%28%5Ctext%7Berror%7D%29%20%5Clesssim%201%20-%20%5Cleft%28%20%5Cfrac%7B3%7D%7B4%7D%20%5Cright%29%5En "\Pr(\text{error}) \lesssim 1 - \left( \frac{3}{4} \right)^n").

When we set ![S = c \\left( \\frac{3}{4}
\\right)\^n](http://chart.apis.google.com/chart?cht=tx&chl=S%20%3D%20c%20%5Cleft%28%20%5Cfrac%7B3%7D%7B4%7D%20%5Cright%29%5En "S = c \left( \frac{3}{4} \right)^n"),
the probability of error ![\\Pr(\\text{error}) \\lesssim (1 - \\left(
\\frac{3}{4} \\right)\^n)\^{c \\left(\\frac{4}{3}
\\right)\^n}](http://chart.apis.google.com/chart?cht=tx&chl=%5CPr%28%5Ctext%7Berror%7D%29%20%5Clesssim%20%281%20-%20%5Cleft%28%20%5Cfrac%7B3%7D%7B4%7D%20%5Cright%29%5En%29%5E%7Bc%20%5Cleft%28%5Cfrac%7B4%7D%7B3%7D%20%5Cright%29%5En%7D "\Pr(\text{error}) \lesssim (1 - \left( \frac{3}{4} \right)^n)^{c \left(\frac{4}{3} \right)^n}").

From calculus, we know that ![\\left( 1 - \\frac{1}{a} \\right)\^a \\le
\\frac{1}{e}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cleft%28%201%20-%20%5Cfrac%7B1%7D%7Ba%7D%20%5Cright%29%5Ea%20%5Cle%20%5Cfrac%7B1%7D%7Be%7D "\left( 1 - \frac{1}{a} \right)^a \le \frac{1}{e}"),
so the probability of error is ![\\Pr(\\text{error}) \\lesssim
\\frac{1}{e\^c}](http://chart.apis.google.com/chart?cht=tx&chl=%5CPr%28%5Ctext%7Berror%7D%29%20%5Clesssim%20%5Cfrac%7B1%7D%7Be%5Ec%7D "\Pr(\text{error}) \lesssim \frac{1}{e^c}").

The bottom line is that we get ![\\Pr(\\text{error}) \\le
\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5CPr%28%5Ctext%7Berror%7D%29%20%5Cle%20%5Cfrac%7B1%7D%7B2%7D "\Pr(\text{error}) \le \frac{1}{2}"),
with runtime ![O\\left( \\left(\\frac{4}{3} \\right)\^n n
\\right)](http://chart.apis.google.com/chart?cht=tx&chl=O%5Cleft%28%20%5Cleft%28%5Cfrac%7B4%7D%7B3%7D%20%5Cright%29%5En%20n%20%5Cright%29 "O\left( \left(\frac{4}{3} \right)^n n \right)").
While this is exponential, it does beat the best known non-randomized
algorithm that we know.

Minimum Spanning Trees {#cha:minimum_spanning_trees}
======================

The problem mst can be expressed as follows:

> Given an undirected graph ![G = (V,
> E)](http://chart.apis.google.com/chart?cht=tx&chl=G%20%3D%20%28V%2C%20E%29 "G = (V, E)")
> with edge weights ![w : E \\to
> \\mathbf{R}\^+](http://chart.apis.google.com/chart?cht=tx&chl=w%20%3A%20E%20%5Cto%20%5Cmathbf%7BR%7D%5E%2B "w : E \to \mathbf{R}^+"),
> find a minimum-weight spanning tree.

In other words, find the tree on the graph that reaches all vertexes
such that has the minimal total of edge weight in the tree.

Let’s assume that edge weights are distinct[^53^](#fn53).

We can generate this problem to a spanning forest of disconnected
graph[^54^](#fn54) There are two basic rules:

Inclusion Rule
:   The inclusion rule dictates that for a given vertex
    ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v"), if
    ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v")’s minimum
    weight incident edge[^55^](#fn55) is ![e =
    vu](http://chart.apis.google.com/chart?cht=tx&chl=e%20%3D%20vu "e = vu"),
    then ![vu \\in
    \\textsc{mst}(G)](http://chart.apis.google.com/chart?cht=tx&chl=vu%20%5Cin%20%5Ctextsc%7Bmst%7D%28G%29 "vu \in \textsc{mst}(G)").
    Since we know this, we can the vertexes
    ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") and
    ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") into each
    other creating a vertex
    ![v'](http://chart.apis.google.com/chart?cht=tx&chl=v%27 "v'"), and
    continue the process with a smaller graph. For every vertex
    ![r](http://chart.apis.google.com/chart?cht=tx&chl=r "r") which has
    an edge to both
    ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") and
    ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u"), we just
    add the smaller of the two edges to
    ![v'](http://chart.apis.google.com/chart?cht=tx&chl=v%27 "v'").

Exclusion Rule
:   The exclusion rule dictates that for a given cycle
    ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") with
    maximum weight edge
    ![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e"), then ![e
    \\not \\in
    \\textsc{mst}(G)](http://chart.apis.google.com/chart?cht=tx&chl=e%20%5Cnot%20%5Cin%20%5Ctextsc%7Bmst%7D%28G%29 "e \not \in \textsc{mst}(G)").
    We may delete
    ![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e") and
    continue.

While basically all mst algorithms work under these rules, we can’t get
the MST without contraction.

In this analysis,
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is the number
of vertexes, and
![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m") is the number
of edges.

Kruskal’s Algorithm (\`56) {#sec:kruskal_s_algorithm_}
--------------------------

Kruskal’s Algorithm uses the inclusion rule.

        mst(G)
            repeat:
                e = (u, v) = minimumWeightEdge(G)
                T += uv
                contract(G, e)
            end
                    

By sorting edges by weight, then using union-find to find the new
vertexes connected to edges after contraction, this algorithm takes
![O(m \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%20%5Clog%20n%29 "O(m \log n)")
time.

Prim’s Algorithm (\`57) {#sec:prim_s_algorithm_57}
-----------------------

        mst(G):
            S = randomVertexFrom(G.V)
            repeat:
                e = minimumWeightEdgeFrom(S)
                T += e
                contract(G, e)
                S.put(e.from)
                S.put(e.to)
                    

Implementing with a heap takes ![O(m \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%20%5Clog%20n%29 "O(m \log n)")
time. Implementing with a Fibonacci Heap takes ![O(n \\log n +
m)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Clog%20n%20%2B%20m%29 "O(n \log n + m)")
time, which is linear when ![m \> n \\log
n](http://chart.apis.google.com/chart?cht=tx&chl=m%20%3E%20n%20%5Clog%20n "m > n \log n").

Borvka’s Algorithm (\`26) {#sec:borukva_s_algorithm_26}
-------------------------

The idea is that we want to apply the inclusion rule to all vertexes at
once. We’ll actually just apply it until every vertex is a contracted
one, and the resultant number of vertexes is ![\\le
\\frac{n}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%5Cfrac%7Bn%7D%7B2%7D "\le \frac{n}{2}").

### Borvka Step {#sub:baruvka_step}

The is that we want to ensure every vertex is part of at least one
merge.

        baruvka(G):
            unmark all vertexes
            for each v in V:
                if v is unmarked:
                    find minimum weight edge e=vu
                    add e to T, contract v to u
                    mark u
            return T
                        

For each vertex
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v"), the Borvka
Step checks ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v")’s
minimum weight edge, and contracts ![v \\to
u](http://chart.apis.google.com/chart?cht=tx&chl=v%20%5Cto%20u "v \to u"),
which takes
![O(\\text{deg}(v))](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Ctext%7Bdeg%7D%28v%29%29 "O(\text{deg}(v))")
time. Thus, the entire step takes:

\
![\\begin{aligned} O\\left(\\sum\_v \\text{deg}(v) \\right) &= O(m)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%5Cleft%28%5Csum_v%20%5Ctext%7Bdeg%7D%28v%29%20%5Cright%29%20%26%3D%20O%28m%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        O\left(\sum_v \text{deg}(v) \right) &= O(m)
                    \end{aligned}")\

The step reduces the graph to ![\\le
\\frac{n}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%5Cfrac%7Bn%7D%7B2%7D "\le \frac{n}{2}")
vertexes.

### Borvka’s Algorithm {#sub:baruvka_s_algorithm}

The idea is to repeat the Borvka Step until only one vertex is left.

Since there are going to be ![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")
reductions, the total time is ![O(m \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%20%5Clog%20n%29 "O(m \log n)").
This isn’t as fast in practice as Prim, but it’s much simpler to
implement.

History of MST Algorithms {#sec:history_of_mst_algorithms}
-------------------------

-   In \`75, Yao, Cheriton, and Tarjan found a ![O(m \\log \\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%20%5Clog%20%5Clog%20n%29 "O(m \log \log n)")
    algorithm.

-   In \`85, Fredman and Tarjan found a ![O(m \\log\^\*
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%20%5Clog%5E%2A%20n%29 "O(m \log^* n)")
    algorithm.

-   In \`87, Chazelle found an ![O(m
    \\alpha(n))](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%20%5Calpha%28n%29%29 "O(m \alpha(n))")
    algorithm.

open: Is there a linear time (![O(n +
m)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%2B%20m%29 "O(n + m)"))
algorithm?

Karger’s Algorithm (\`93) {#sec:karger_s_algorithm_}
-------------------------

Karger gave a Las-Vegas MST algorithm with linear expected run time. The
idea of his algorithm is to use random sampling, the exclusion rule, and
recursion.

We want the algorithm
![\\textsc{mst}(E)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctextsc%7Bmst%7D%28E%29 "\textsc{mst}(E)")
to return the mst of each connected component of ![G=(V,
E)](http://chart.apis.google.com/chart?cht=tx&chl=G%3D%28V%2C%20E%29 "G=(V, E)").

        MST(E):
            take a random subset R <= E of size |R| = r // chosen later: r=2n
            T = MST(R)
            for each edge uv in E, do:
                if uv is not in T and uv is heavier than all edges in the uv path in T:
                    classify uv as heavy
                else:
                    classify uv as light and replace uv with e in T
            E = E - heavy edges
            return MST(E)
                    

This is correct by the exclusion rule. If we added a new edge ![e =
uv](http://chart.apis.google.com/chart?cht=tx&chl=e%20%3D%20uv "e = uv")
to the sample ![R](http://chart.apis.google.com/chart?cht=tx&chl=R "R"):

-   If ![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e") is
    heavy, ![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T")
    does not change.

-   If ![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e") is
    light, we would’ve updated
    ![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") to use
    ![uv](http://chart.apis.google.com/chart?cht=tx&chl=uv "uv").

Additionally ![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T")
is the mst of the entire graph iff all edges not in
![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") are heavy.

We can classify edges and verify if
![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") is a mst of
the entire graph in
![O(m)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%29 "O(m)")
time[^56^](#fn56).

### Sampling Lemma {#sub:sampling_lemma}

We propose that the number of light edges ![E(\\text{\\\# light edges})
\\le
\\frac{mn}{r}](http://chart.apis.google.com/chart?cht=tx&chl=E%28%5Ctext%7B%5C%23%20light%20edges%7D%29%20%5Cle%20%5Cfrac%7Bmn%7D%7Br%7D "E(\text{\# light edges}) \le \frac{mn}{r}").
Since there are
![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m") edges, this is
enough to show that ![\\Pr(\\text{e is light})
\\le\\frac{n}{r}](http://chart.apis.google.com/chart?cht=tx&chl=%5CPr%28%5Ctext%7Be%20is%20light%7D%29%20%5Cle%5Cfrac%7Bn%7D%7Br%7D "\Pr(\text{e is light}) \le\frac{n}{r}").

We can prove this by working backwards: Consider ![R' = R \\cup
\\{e\\}](http://chart.apis.google.com/chart?cht=tx&chl=R%27%20%3D%20R%20%5Ccup%20%5C%7Be%5C%7D "R' = R \cup \{e\}"),
where ![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e") is a
random element of
![R'](http://chart.apis.google.com/chart?cht=tx&chl=R%27 "R'"). By the
notes above, ![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e")
is light with respect to
![R](http://chart.apis.google.com/chart?cht=tx&chl=R "R") if and only if
![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e") is in the
![\\textsc{mst}(R')](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctextsc%7Bmst%7D%28R%27%29 "\textsc{mst}(R')")
(which has ![\\le
n-1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20n-1 "\le n-1")
edges). So
![\\Pr(\\text{](http://chart.apis.google.com/chart?cht=tx&chl=%5CPr%28%5Ctext%7B "\Pr(\text{")e![
is light}) \\le \\frac{n-1}{|R'|} \<
\\frac{n}{r}](http://chart.apis.google.com/chart?cht=tx&chl=%20is%20light%7D%29%20%5Cle%20%5Cfrac%7Bn-1%7D%7B%7CR%27%7C%7D%20%3C%20%5Cfrac%7Bn%7D%7Br%7D " is light}) \le \frac{n-1}{|R'|} < \frac{n}{r}").

### Analysis of Expected Runtime {#sub:analysis_of_expected_runtime}

We have the following recursion:

\
![\\begin{aligned} T(m, n) &= \\text{recursive call on \$R\$} +
\\text{time to classify} + \\text{recursive call to find the MST of
\$E\$-heavy} \\\\ T(m, n) &= T(r, n) + O(m + n) + T\\left(\\frac{mn}{r},
n\\right)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%28m%2C%20n%29%20%26%3D%20%5Ctext%7Brecursive%20call%20on%20%24R%24%7D%20%2B%20%5Ctext%7Btime%20to%20classify%7D%20%2B%20%5Ctext%7Brecursive%20call%20to%20find%20the%20MST%20of%20%24E%24-heavy%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%28m%2C%20n%29%20%26%3D%20T%28r%2C%20n%29%20%2B%20O%28m%20%2B%20n%29%20%2B%20T%5Cleft%28%5Cfrac%7Bmn%7D%7Br%7D%2C%20n%5Cright%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        T(m, n) &= \text{recursive call on $R$} + \text{time to classify} + \text{recursive call to find the MST of $E$-heavy} \\
                        T(m, n) &= T(r, n) + O(m + n) + T\left(\frac{mn}{r}, n\right)
                    \end{aligned}")\

With ![r =
2n](http://chart.apis.google.com/chart?cht=tx&chl=r%20%3D%202n "r = 2n"),
this becomes:

\
![\\begin{aligned} T(m, n) &= T(2n, n) + O(m + n) +
T\\left(\\frac{mn}{2n}, n\\right) \\\\ T(m, n) &= T(2n, n) +
T\\left(\\frac{m}{2}, n\\right) + O(m + n)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%28m%2C%20n%29%20%26%3D%20T%282n%2C%20n%29%20%2B%20O%28m%20%2B%20n%29%20%2B%20T%5Cleft%28%5Cfrac%7Bmn%7D%7B2n%7D%2C%20n%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%28m%2C%20n%29%20%26%3D%20T%282n%2C%20n%29%20%2B%20T%5Cleft%28%5Cfrac%7Bm%7D%7B2%7D%2C%20n%5Cright%29%20%2B%20O%28m%20%2B%20n%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        T(m, n) &= T(2n, n) + O(m + n) + T\left(\frac{mn}{2n}, n\right) \\
                        T(m, n) &= T(2n, n) + T\left(\frac{m}{2}, n\right) + O(m + n)
                    \end{aligned}")\

The final idea, (attributed to Karger, Klein, and Tarjan in \`94) is on
each recursive call to do 3 Borvka steps first. This reduces
![\\text{\\\# vertexes} \\le
\\frac{n}{8}](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctext%7B%5C%23%20vertexes%7D%20%5Cle%20%5Cfrac%7Bn%7D%7B8%7D "\text{\# vertexes} \le \frac{n}{8}")
with ![O(n +
m)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%2B%20m%29 "O(n + m)")
work. For some constant
![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d"), we have:

\
![\\begin{aligned} T(m, n) \\le T\\left(\\frac{n}{4},
\\frac{n}{8}\\right) + T\\left(\\frac{m}{2}, \\frac{n}{8}\\right) +
d(m+n)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%28m%2C%20n%29%20%5Cle%20T%5Cleft%28%5Cfrac%7Bn%7D%7B4%7D%2C%20%5Cfrac%7Bn%7D%7B8%7D%5Cright%29%20%2B%20T%5Cleft%28%5Cfrac%7Bm%7D%7B2%7D%2C%20%5Cfrac%7Bn%7D%7B8%7D%5Cright%29%20%2B%20d%28m%2Bn%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        T(m, n) \le T\left(\frac{n}{4}, \frac{n}{8}\right) + T\left(\frac{m}{2}, \frac{n}{8}\right) + d(m+n)
                    \end{aligned}")\

Proving that ![T(m, n) \\le c(m +
n)](http://chart.apis.google.com/chart?cht=tx&chl=T%28m%2C%20n%29%20%5Cle%20c%28m%20%2B%20n%29 "T(m, n) \le c(m + n)")
for some constant
![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c") is sufficient
to prove ![T(m, n) \\in O(n +
m)](http://chart.apis.google.com/chart?cht=tx&chl=T%28m%2C%20n%29%20%5Cin%20O%28n%20%2B%20m%29 "T(m, n) \in O(n + m)").
We implicitly assume that the base case has been proven, and prove the
inductive step:

\
![\\begin{aligned} T(m, n) &\\le c\\left(\\frac{n}{4} +
\\frac{n}{8}\\right) + c\\left(\\frac{m}{2} + \\frac{n}{8}\\right) +
d\\left(m + n\\right) \\\\ &= \\left(\\frac{c}{2} + d\\right) n +
\\left(\\frac{c}{2} + d \\right) m \\\\ &\\le c(n+m) \\text{ as long as
\$\\frac{c}{2} + d \\le c\$}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%28m%2C%20n%29%20%26%5Cle%20c%5Cleft%28%5Cfrac%7Bn%7D%7B4%7D%20%2B%20%5Cfrac%7Bn%7D%7B8%7D%5Cright%29%20%2B%20c%5Cleft%28%5Cfrac%7Bm%7D%7B2%7D%20%2B%20%5Cfrac%7Bn%7D%7B8%7D%5Cright%29%20%2B%20d%5Cleft%28m%20%2B%20n%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cleft%28%5Cfrac%7Bc%7D%7B2%7D%20%2B%20d%5Cright%29%20n%20%2B%20%5Cleft%28%5Cfrac%7Bc%7D%7B2%7D%20%2B%20d%20%5Cright%29%20m%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20c%28n%2Bm%29%20%5Ctext%7B%20as%20long%20as%20%24%5Cfrac%7Bc%7D%7B2%7D%20%2B%20d%20%5Cle%20c%24%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        T(m, n) &\le c\left(\frac{n}{4} + \frac{n}{8}\right) + c\left(\frac{m}{2} + \frac{n}{8}\right) + d\left(m + n\right) \\
                                &= \left(\frac{c}{2} + d\right) n + \left(\frac{c}{2} + d \right) m \\
                                &\le c(n+m) \text{ as long as $\frac{c}{2} + d \le c$}
                    \end{aligned}")\

So the expected runtime is
![O(m+n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%2Bn%29 "O(m+n)").

Approximation Algorithms {#cha:approximation_algorithms}
========================

Recall ![{\\textsc{P}\\xspace}\\stackrel{?}{=}
{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%5Cstackrel%7B%3F%7D%7B%3D%7D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}\stackrel{?}{=} {\textsc{NP}\xspace}").

We have a set ![{\\textsc{P}\\xspace}\\subseteq
{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%5Csubseteq%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}\subseteq {\textsc{NP}\xspace}"),
and another set ![{\\textsc{NP-complete}\\xspace}\\subseteq
{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BNP-complete%7D%5Cxspace%7D%5Csubseteq%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{NP-complete}\xspace}\subseteq {\textsc{NP}\xspace}"),
where NP-completeare the hardest problems in NP. There are a few
problems in NPthat are not in Pand not known to be in
NP-complete(factoring, graph isomorphism, etc).

It is openif there exist poly-time correct algorithms to solve
NP-completeproblems.

Ladner proved that:

> If ![{\\textsc{P}\\xspace}\\not =
> {\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%5Cnot%20%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}\not = {\textsc{NP}\xspace}"),
> then there are infinitely many problems in the space between Pand
> NP-complete.

It seems like we must either give up correctness, or speed.

And thus, approximation algorithms are born. For optimization problems,
these algorithms guarantee that their result is *close to* the optimal
solution.

Concerning Approximation Algorithms {#sec:concerning_approximation_algorithms}
-----------------------------------

An algorithm finds in polynomial-time a solution that is close to the
optimal, either in terms of ratio or in constant difference.

#### Edge-Coloring in a Graph {#ssub:edge_coloring_in_a_graph}

Given a graph ![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G"),
color the edges such that if two edges are incident[^57^](#fn57), they
have different colors.

A variant of this problem is NP-complete:

> Given ![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G") and
> ![k \\in
> \\mathbf{N}](http://chart.apis.google.com/chart?cht=tx&chl=k%20%5Cin%20%5Cmathbf%7BN%7D "k \in \mathbf{N}"),
> can you edge color
> ![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G") with
> ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") colors?

Vizing’s Theorem states that for the maximum degree across all vertexes
in a graph
![\\Delta](http://chart.apis.google.com/chart?cht=tx&chl=%5CDelta "\Delta"),
![\\Delta \\le \\text{minimum number of colors} \\le \\Delta +1
](http://chart.apis.google.com/chart?cht=tx&chl=%5CDelta%20%5Cle%20%5Ctext%7Bminimum%20number%20of%20colors%7D%20%5Cle%20%5CDelta%20%2B1%20 "\Delta \le \text{minimum number of colors} \le \Delta +1 ").

Furthermore, there exists a polynomial-time algorithm to color any graph
with
![\\Delta+1](http://chart.apis.google.com/chart?cht=tx&chl=%5CDelta%2B1 "\Delta+1")
colors.

Since the algorithm exists, we can approximate within
![+1](http://chart.apis.google.com/chart?cht=tx&chl=%2B1 "+1") of the
optsolution.

This type of approximation (constant additive) is rare, since we usually
get a good ratio of approxto opt.

#### Vertex Cover {#ssub:vertex_cover}

Given a graph ![G = (V,
E)](http://chart.apis.google.com/chart?cht=tx&chl=G%20%3D%20%28V%2C%20E%29 "G = (V, E)"),
find a minimum-size - a set ![U \\subseteq
V](http://chart.apis.google.com/chart?cht=tx&chl=U%20%5Csubseteq%20V "U \subseteq V")
such that every edge has at least one endpoint in
![U](http://chart.apis.google.com/chart?cht=tx&chl=U "U").

We can use this kind of algorithm to monitor all links in a network.

The decision version of Vertex-Cover is NP-complete. Where Independent
set is the question to find the maximum set of vertexes where no two are
joined by an edge, there is a reduction this way:

\
![\\begin{aligned} \\textsc{3sat} \\le\_p \\text{independent set}
\\le\_p \\text{vertex cover}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctextsc%7B3sat%7D%20%5Cle_p%20%5Ctext%7Bindependent%20set%7D%20%5Cle_p%20%5Ctext%7Bvertex%20cover%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \textsc{3sat} \le_p \text{independent set} \le_p \text{vertex cover}
                    \end{aligned}")\

The argument for reduction between vertex cover and independent set is
that ![U \\subseteq
V](http://chart.apis.google.com/chart?cht=tx&chl=U%20%5Csubseteq%20V "U \subseteq V")
is a minimum vertex cover if and only if ![V -
U](http://chart.apis.google.com/chart?cht=tx&chl=V%20-%20U "V - U") is a
maximum independent set.

The existence of an approximation algorithm for vertex cover that’s good
within an additive constant (as for edge coloring) implies P= NP.

Greedy Algorithm for Max Vertex Cover {#sec:greedy_algorithm_for_max_vertex_cover}
-------------------------------------

    maxCover(V):
        C = [];
        while true:
            if no edges remain: break;
            C.append(vertex of max degree)
            remove covered edges
                    

We will show that ![|C| \\le O(\\log n)
|{\\textsc{opt}\\xspace}|](http://chart.apis.google.com/chart?cht=tx&chl=%7CC%7C%20%5Cle%20O%28%5Clog%20n%29%20%7C%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%7C "|C| \le O(\log n) |{\textsc{opt}\xspace}|").

Exercise for reader (not in notes): Show that the greedy algorithm can
give ![\\frac{|C|}{|{\\textsc{opt}\\xspace}|} \\in \\Omega (\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B%7CC%7C%7D%7B%7C%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%7C%7D%20%5Cin%20%5COmega%20%28%5Clog%20n%29 "\frac{|C|}{|{\textsc{opt}\xspace}|} \in \Omega (\log n)").

Set Cover Problem {#sec:set_cover_problem}
-----------------

The max vertex problem is a subset of the Set Cover problem.

Given a collection of sets ![S\_1, S\_2, \\ldots,
S\_k](http://chart.apis.google.com/chart?cht=tx&chl=S_1%2C%20S_2%2C%20%5Cldots%2C%20S_k "S_1, S_2, \ldots, S_k")
where ![S\_i \\subseteq [1,
n]](http://chart.apis.google.com/chart?cht=tx&chl=S_i%20%5Csubseteq%20%5B1%2C%20n%5D "S_i \subseteq [1, n]").
Find a minimum sized set ![C \\subseteq [1,
n]](http://chart.apis.google.com/chart?cht=tx&chl=C%20%5Csubseteq%20%5B1%2C%20n%5D "C \subseteq [1, n]")
such that for all ![i \\in [1,
n]](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cin%20%5B1%2C%20n%5D "i \in [1, n]"),
![i \\in
S\_j](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cin%20S_j "i \in S_j")
for some ![j \\in
C](http://chart.apis.google.com/chart?cht=tx&chl=j%20%5Cin%20C "j \in C").

In the real world, this works as follows:

> Where sets
> ![S\_i](http://chart.apis.google.com/chart?cht=tx&chl=S_i "S_i") are a
> type of pizza, and set elements
> ![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e") are
> individual people. An element ![e \\in
> S\_i](http://chart.apis.google.com/chart?cht=tx&chl=e%20%5Cin%20S_i "e \in S_i")
> means that the person eats that type of pizza. We want to find the
> minimum number of pizza types to feed all people.

### Vertex vs Set Cover {#sub:vertex_vs_set_cover}

We can show that vertex cover is a special case of Set Cover: Elements
![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e") of our sets
are edges in the graph, and sets correspond to vertexes in our graph.

Since every element in our vertex cover is in exactly two of our sets, a
A Set Cover that every element is in exactly two of our sets allows us
to transform our Set Cover problem into a vertex cover.

### Greedy Approximation Algorithm for Set Cover {#sub:greedy_approximation_algorithm_for_set_cover}

The idea is to iteratively choose the set that has the most yet
uncovered elements.

    setCover(S[] s):
        C = []
        while there are uncovered elements:
            S[i] = a set that covers the max number of uncovered elements
            C.append(i)
                        

We claim that ![|C| = {\\textsc{approx}\\xspace}\\le O(\\log n)
{\\textsc{opt}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7CC%7C%20%3D%20%7B%5Ctextsc%7Bapprox%7D%5Cxspace%7D%5Cle%20O%28%5Clog%20n%29%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D "|C| = {\textsc{approx}\xspace}\le O(\log n) {\textsc{opt}\xspace}"),
where optis the minimum number of sets to cover all elements.

This proof is taken from Vazirani’s book[^58^](#fn58), which is a
simpler proof than the one presented in CLRS.

We distribute the cost (1) of choosing a set
![S\_i](http://chart.apis.google.com/chart?cht=tx&chl=S_i "S_i") over
the newly covered elements. Let
![c(e)](http://chart.apis.google.com/chart?cht=tx&chl=c%28e%29 "c(e)")
represent the cost of adding element
![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e").

We define ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") as
the maximum size set, since it is the first one chosen. For a defined
element ![e \\in
S](http://chart.apis.google.com/chart?cht=tx&chl=e%20%5Cin%20S "e \in S"),
we define ![c(e) =
\\frac{1}{|S|}](http://chart.apis.google.com/chart?cht=tx&chl=c%28e%29%20%3D%20%5Cfrac%7B1%7D%7B%7CS%7C%7D "c(e) = \frac{1}{|S|}").
We know that ![|S| \>
](http://chart.apis.google.com/chart?cht=tx&chl=%7CS%7C%20%3E%20 "|S| > ")
the average number of elements per set in the optsolution. We also know
that the average number of elements
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") per set in the
optsolution is ![\\ge
\\frac{n}{{\\textsc{opt}\\xspace}}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20%5Cfrac%7Bn%7D%7B%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%7D "\ge \frac{n}{{\textsc{opt}\xspace}}").
This implies that for the first set we have:

\
![\\begin{aligned} c(e) &\\le \\frac{{\\textsc{opt}\\xspace}}{n}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20c%28e%29%20%26%5Cle%20%5Cfrac%7B%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%7D%7Bn%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        c(e) &\le \frac{{\textsc{opt}\xspace}}{n}
                    \end{aligned}")\

More generally, let the ordering ![e\_1, e\_2, \\ldots, e\_i, \\ldots
e\_n](http://chart.apis.google.com/chart?cht=tx&chl=e_1%2C%20e_2%2C%20%5Cldots%2C%20e_i%2C%20%5Cldots%20e_n "e_1, e_2, \ldots, e_i, \ldots e_n")
be an ordering of elements as they are covered (we expect many ties).

We define that the number elements newly covered by
![S'](http://chart.apis.google.com/chart?cht=tx&chl=S%27 "S'") as
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k"). For a given
![e\_i \\in
S'](http://chart.apis.google.com/chart?cht=tx&chl=e_i%20%5Cin%20S%27 "e_i \in S'"),
we know that the number of elements uncovered prior to
![S'](http://chart.apis.google.com/chart?cht=tx&chl=S%27 "S'") being
chosen must be ![\\ge n - i +
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20n%20-%20i%20%2B%201 "\ge n - i + 1").

Since the set picked is the one with the maximal
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k"), we know that
it must be ![\\ge
\\textsc{avg}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20%5Ctextsc%7Bavg%7D "\ge \textsc{avg}")
on the range ![j \\ge
i](http://chart.apis.google.com/chart?cht=tx&chl=j%20%5Cge%20i "j \ge i")
covered by opt. We know that ![\\textsc{avg} \\ge
\\frac{n-i+1}{{\\textsc{opt}\\xspace}}](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctextsc%7Bavg%7D%20%5Cge%20%5Cfrac%7Bn-i%2B1%7D%7B%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%7D "\textsc{avg} \ge \frac{n-i+1}{{\textsc{opt}\xspace}}"),
since any lower would mean that there are more than optsets chosen in
the optsolution. Thus, ![k \\ge
\\frac{n-i+1}{{\\textsc{opt}\\xspace}}](http://chart.apis.google.com/chart?cht=tx&chl=k%20%5Cge%20%5Cfrac%7Bn-i%2B1%7D%7B%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%7D "k \ge \frac{n-i+1}{{\textsc{opt}\xspace}}"),
which implies that ![c(e\_i) \\le
\\frac{{\\textsc{opt}\\xspace}}{n-i+1}](http://chart.apis.google.com/chart?cht=tx&chl=c%28e_i%29%20%5Cle%20%5Cfrac%7B%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%7D%7Bn-i%2B1%7D "c(e_i) \le \frac{{\textsc{opt}\xspace}}{n-i+1}").

\
![\\begin{aligned} \\text{number of sets chosen by greedy} &=
\\sum\_{i=1}\^n c(e\_i) \\\\ &\\in O(\\log n)
{\\textsc{opt}\\xspace}\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7Bnumber%20of%20sets%20chosen%20by%20greedy%7D%20%26%3D%20%5Csum_%7Bi%3D1%7D%5En%20c%28e_i%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cin%20O%28%5Clog%20n%29%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%5Cend%7Baligned%7D "\begin{aligned}
                        \text{number of sets chosen by greedy} &= \sum_{i=1}^n c(e_i) \\
                        &\in O(\log n) {\textsc{opt}\xspace}\end{aligned}")\

Thus, the number of sets chosen by the greedy is within a factor of
![O(\\log n)
{\\textsc{opt}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D "O(\log n) {\textsc{opt}\xspace}").

Linear Programs and Randomization {#cha:linear_programs_and_randomization}
=================================

Vertex Cover {#sec:vertex_cover}
------------

Please recall the definition of the vertex cover problem on page , and
the approximation within ![O(\\log n)
{\\textsc{opt}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D "O(\log n) {\textsc{opt}\xspace}")
presented on page .

### Constant-Factor Approximation for Vertex Cover {#sub:constant_factor_approximation_for_vertex_cover}

There’s a “stupid” approximation algorithm for vertex cover that’s
better than the greedy algorithm.

    vertex_cover(E, V):
        C = {}
        while E != {}:
            (u, v) = E.remove_random()
            e = {u, v}
            C.append(e)
            E.remove_connected_to([u, v])
        return C
                        

Since we pick the set of edges is a matching[^59^](#fn59). Where
![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M") is the set of
edges we pick, we know that ![|C| =
2|M|](http://chart.apis.google.com/chart?cht=tx&chl=%7CC%7C%20%3D%202%7CM%7C "|C| = 2|M|").
We also know that ![|M| \\le
{\\textsc{opt}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7CM%7C%20%5Cle%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D "|M| \le {\textsc{opt}\xspace}"),
since every matching edge needs its own vertex in the optvertex cover.

Thus, our “stupid” greedy algorithm has ![|C| = 2|M| \\le 2
{\\textsc{opt}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7CC%7C%20%3D%202%7CM%7C%20%5Cle%202%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D "|C| = 2|M| \le 2 {\textsc{opt}\xspace}"),
and thus gives us an approximation factor of 2.

#### Best Approximation Factor Known for Vertex Cover {#ssub:best_approximation_factor_known_for_vertex_cover}

The best approximation factor known for the Vertex Cover problem is 2.

#### Weighted Vertex Cover {#ssub:weighted_vertex_cover}

> Given weights on vertices ![w : V \\to
> \\mathbf{R}\^+](http://chart.apis.google.com/chart?cht=tx&chl=w%20%3A%20V%20%5Cto%20%5Cmathbf%7BR%7D%5E%2B "w : V \to \mathbf{R}^+"),
> find the vertex cover
> ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") of minimum
> weight ![\\sum\_{v \\in C}
> w(v)](http://chart.apis.google.com/chart?cht=tx&chl=%5Csum_%7Bv%20%5Cin%20C%7D%20w%28v%29 "\sum_{v \in C} w(v)").

In fact, we can express this as an integer linear program.

Create a variable
![x(v)](http://chart.apis.google.com/chart?cht=tx&chl=x%28v%29 "x(v)")
for each ![v \\in
V](http://chart.apis.google.com/chart?cht=tx&chl=v%20%5Cin%20V "v \in V").

\
![\\begin{aligned} x(v) = \\left\\{ \\begin{array}{lr} 1 & : v \\in C
\\\\ 0 & : v \\notin C \\end{array} \\right.
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20x%28v%29%20%3D%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%201%20%26%20%3A%20v%20%5Cin%20C%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%200%20%26%20%3A%20v%20%5Cnotin%20C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        x(v) = \left\{
                            \begin{array}{lr}
                                1 & : v \in C \\
                                0 & : v \notin C
                            \end{array}
                        \right.
                    \end{aligned}")\

Now we’re trying to find the solution to the following linear program:

\
![\\begin{aligned} \\min \\sum\_{v \\in V} w(v) x(v)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmin%20%5Csum_%7Bv%20%5Cin%20V%7D%20w%28v%29%20x%28v%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \min \sum_{v \in V} w(v) x(v)
                    \end{aligned}")\

Given the constraints that ![\\forall e \\in E : e = (u, v) : x(u) +
x(v) \\ge
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cforall%20e%20%5Cin%20E%20%3A%20e%20%3D%20%28u%2C%20v%29%20%3A%20x%28u%29%20%2B%20x%28v%29%20%5Cge%201 "\forall e \in E : e = (u, v) : x(u) + x(v) \ge 1"),
and bounding the values of
![x()](http://chart.apis.google.com/chart?cht=tx&chl=x%28%29 "x()") to
be ![x(v) \\in \\{0,
1\\}](http://chart.apis.google.com/chart?cht=tx&chl=x%28v%29%20%5Cin%20%5C%7B0%2C%201%5C%7D "x(v) \in \{0, 1\}").

The solutions to this integer linear program are exactly minimum-weight
vertex covers. While Integer Linear Programs (ILP) are
NP-complete[^60^](#fn60), relaxing the constraints to be non-integer
Linear Program (LP) allows us to use the simplex method (Refex to
Subsection [sub:simplex~m~ethod]). To use simplex, we can relax ![x(v)
\\in \\{0,
1\\}](http://chart.apis.google.com/chart?cht=tx&chl=x%28v%29%20%5Cin%20%5C%7B0%2C%201%5C%7D "x(v) \in \{0, 1\}")
to ![x(v) \\in [0,
1]](http://chart.apis.google.com/chart?cht=tx&chl=x%28v%29%20%5Cin%20%5B0%2C%201%5D "x(v) \in [0, 1]").

Suppose that
![\\bar{x}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7Bx%7D "\bar{x}")
is an optional solution to the linear program. Let ![C\_{\\textsc{LP}} =
\\{ v \\in V : \\bar{x}(v) \\ge \\frac{1}{2}
\\}](http://chart.apis.google.com/chart?cht=tx&chl=C_%7B%5Ctextsc%7BLP%7D%7D%20%3D%20%5C%7B%20v%20%5Cin%20V%20%3A%20%5Cbar%7Bx%7D%28v%29%20%5Cge%20%5Cfrac%7B1%7D%7B2%7D%20%5C%7D "C_{\textsc{LP}} = \{ v \in V : \bar{x}(v) \ge \frac{1}{2} \}").
Our linear program guarantees that ![\\bar{x}(u) + \\bar{x}(v) \\ge
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7Bx%7D%28u%29%20%2B%20%5Cbar%7Bx%7D%28v%29%20%5Cge%201 "\bar{x}(u) + \bar{x}(v) \ge 1"),
so at least one of ![u,
v](http://chart.apis.google.com/chart?cht=tx&chl=u%2C%20v "u, v") has
![\\bar{x}(-) \\ge
\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7Bx%7D%28-%29%20%5Cge%20%5Cfrac%7B1%7D%7B2%7D "\bar{x}(-) \ge \frac{1}{2}"),
and that vertex is definitely in
![C\_{\\textsc{LP}}](http://chart.apis.google.com/chart?cht=tx&chl=C_%7B%5Ctextsc%7BLP%7D%7D "C_{\textsc{LP}}").
Then
![C\_{\\textsc{LP}}](http://chart.apis.google.com/chart?cht=tx&chl=C_%7B%5Ctextsc%7BLP%7D%7D "C_{\textsc{LP}}")
is a vertex cover.

Starting with the premise that ![{\\textsc{opt}\\xspace}=
{\\textsc{opt}\\xspace}\\text{ to } \\textsc{ILP} \\ge
{\\textsc{opt}\\xspace}\\text{ to }
\\textsc{LP}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%3D%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%5Ctext%7B%20to%20%7D%20%5Ctextsc%7BILP%7D%20%5Cge%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%5Ctext%7B%20to%20%7D%20%5Ctextsc%7BLP%7D "{\textsc{opt}\xspace}= {\textsc{opt}\xspace}\text{ to } \textsc{ILP} \ge {\textsc{opt}\xspace}\text{ to } \textsc{LP}"),
since the lp allows more solutions, so the optdecreases. Given that
![\\bar{x}(-)](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7Bx%7D%28-%29 "\bar{x}(-)")
is the optsolution to the LP, we have:

\
![\\begin{aligned} {\\textsc{opt}\\xspace}&= \\sum w(v) \\bar{x}(v) \\\\
&\\ge \\sum\_{v \\in V : \\bar{x}(v) \\ge 0.5} w(v) \\bar{x}(v) \\\\
&\\ge \\sum\_{v \\in V : \\bar{x}(v) \\ge 0.5} w(v) \\frac{1}{2} \\\\ &=
\\frac{1}{2} \\sum\_{v \\in V : \\bar{x}(v) \\ge 0.5} w(v) \\\\ &=
\\frac{1}{2} w(C\_{\\textsc{LP}})
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%26%3D%20%5Csum%20w%28v%29%20%5Cbar%7Bx%7D%28v%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20%5Csum_%7Bv%20%5Cin%20V%20%3A%20%5Cbar%7Bx%7D%28v%29%20%5Cge%200.5%7D%20w%28v%29%20%5Cbar%7Bx%7D%28v%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20%5Csum_%7Bv%20%5Cin%20V%20%3A%20%5Cbar%7Bx%7D%28v%29%20%5Cge%200.5%7D%20w%28v%29%20%5Cfrac%7B1%7D%7B2%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7B2%7D%20%5Csum_%7Bv%20%5Cin%20V%20%3A%20%5Cbar%7Bx%7D%28v%29%20%5Cge%200.5%7D%20w%28v%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7B2%7D%20w%28C_%7B%5Ctextsc%7BLP%7D%7D%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        {\textsc{opt}\xspace}&= \sum w(v) \bar{x}(v) \\
                        &\ge \sum_{v \in V : \bar{x}(v) \ge 0.5} w(v) \bar{x}(v) \\
                        &\ge \sum_{v \in V : \bar{x}(v) \ge 0.5} w(v) \frac{1}{2} \\
                        &= \frac{1}{2} \sum_{v \in V : \bar{x}(v) \ge 0.5} w(v) \\
                        &= \frac{1}{2} w(C_{\textsc{LP}})
                    \end{aligned}")\

So ![{\\textsc{opt}\\xspace}\\ge \\frac{1}{2}
w(C\_{\\textsc{LP}})](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%5Cge%20%5Cfrac%7B1%7D%7B2%7D%20w%28C_%7B%5Ctextsc%7BLP%7D%7D%29 "{\textsc{opt}\xspace}\ge \frac{1}{2} w(C_{\textsc{LP}})")
or ![w(C\_{\\textsc{LP}}) \\le 2
{\\textsc{opt}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=w%28C_%7B%5Ctextsc%7BLP%7D%7D%29%20%5Cle%202%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D "w(C_{\textsc{LP}}) \le 2 {\textsc{opt}\xspace}").

Set Cover Problem {#sec:set_cover_problem}
-----------------

> Given a collection of sets ![S\_1, S\_2, \\ldots
> S\_k](http://chart.apis.google.com/chart?cht=tx&chl=S_1%2C%20S_2%2C%20%5Cldots%20S_k "S_1, S_2, \ldots S_k"),
> where ![S\_i \\subseteq \\{1, \\ldots, n
> \\}](http://chart.apis.google.com/chart?cht=tx&chl=S_i%20%5Csubseteq%20%5C%7B1%2C%20%5Cldots%2C%20n%20%5C%7D "S_i \subseteq \{1, \ldots, n \}"),
> find a minimum size set of sets such that every element is covered.

In other words, find ![C \\subseteq \\{ 1, \\ldots,
k\\}](http://chart.apis.google.com/chart?cht=tx&chl=C%20%5Csubseteq%20%5C%7B%201%2C%20%5Cldots%2C%20k%5C%7D "C \subseteq \{ 1, \ldots, k\}")
such that ![\\forall i \\in \\{1, \\ldots,
n\\}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cforall%20i%20%5Cin%20%5C%7B1%2C%20%5Cldots%2C%20n%5C%7D "\forall i \in \{1, \ldots, n\}"),
![i \\in
S\_j](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cin%20S_j "i \in S_j")
for some ![j \\in
C](http://chart.apis.google.com/chart?cht=tx&chl=j%20%5Cin%20C "j \in C").

For a Set Cover, the greedy algorithm gives ![\\le O(\\log n)
{\\textsc{opt}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20O%28%5Clog%20n%29%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D "\le O(\log n) {\textsc{opt}\xspace}")
(refer to
Subsection [sub:greedy~a~pproximation~a~lgorithm~f~or~s~et~c~over]).

There’s something that’s marginally better. Define
![f](http://chart.apis.google.com/chart?cht=tx&chl=f "f") as the maximum
number of sets any single element
![e](http://chart.apis.google.com/chart?cht=tx&chl=e "e") is contained
in. For vertex cover, the elements are edges, and the sets are edges
incident to a vertex
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v").
![f](http://chart.apis.google.com/chart?cht=tx&chl=f "f") for vertex
cover is 2, so it is a special case of Set Cover.

There is a polynomial time approximation algorithm using linear
programming and duality for Set Cover that gives a solution of ![\\le f
{\\textsc{opt}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20f%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D "\le f {\textsc{opt}\xspace}"),
which is an approximation factor
![f](http://chart.apis.google.com/chart?cht=tx&chl=f "f").

Depending on the difference between ![\\log
n](http://chart.apis.google.com/chart?cht=tx&chl=%5Clog%20n "\log n")
and ![f](http://chart.apis.google.com/chart?cht=tx&chl=f "f"), one may
be factor.

Later, we will prove that Set Cover has no constant factor approximation
in polynomial time unless ![{\\textsc{P}\\xspace}=
{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}= {\textsc{NP}\xspace}").

#### Approximation For Minimization and Maximization Problems {#ssub:approximation_for_minimization_and_maximization_problems}

A
![\\rho](http://chart.apis.google.com/chart?cht=tx&chl=%5Crho "\rho")-approximization
algorithm for a minimization problem guarantees that ![A(I) \\le \\rho
{\\textsc{opt}\\xspace}(I)](http://chart.apis.google.com/chart?cht=tx&chl=A%28I%29%20%5Cle%20%5Crho%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28I%29 "A(I) \le \rho {\textsc{opt}\xspace}(I)"),
so ![\\rho \\ge
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Crho%20%5Cge%201 "\rho \ge 1").

A
![\\rho](http://chart.apis.google.com/chart?cht=tx&chl=%5Crho "\rho")-approximization
algorithm for a maximization problem guarantees that ![A(I) \\ge \\rho
{\\textsc{opt}\\xspace}(I)](http://chart.apis.google.com/chart?cht=tx&chl=A%28I%29%20%5Cge%20%5Crho%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28I%29 "A(I) \ge \rho {\textsc{opt}\xspace}(I)"),
so ![\\rho \\le
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Crho%20%5Cle%201 "\rho \le 1").

Some texts use
![\\frac{1}{\\rho}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B%5Crho%7D "\frac{1}{\rho}")
for maximization problems. CLRS doesn’t do max, and Vazirani uses the
convention here.

#### Max-Cut Problem {#ssub:max_cut_problem}

The Max Cut problem is a sub-type of the Set Cover problem.

> Given a graph ![G = (V,
> E)](http://chart.apis.google.com/chart?cht=tx&chl=G%20%3D%20%28V%2C%20E%29 "G = (V, E)"),
> partition ![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V")
> into ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S"), ![V -
> S](http://chart.apis.google.com/chart?cht=tx&chl=V%20-%20S "V - S") to
> maximize the number of edges with one end in
> ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") and another
> end in ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S").

We define
![c(S)](http://chart.apis.google.com/chart?cht=tx&chl=c%28S%29 "c(S)")
as the size of cut[^61^](#fn61) for
![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S"), ![V -
S](http://chart.apis.google.com/chart?cht=tx&chl=V%20-%20S "V - S").

Without proof, the (decision version of the) Max-Cut problem is
NP-complete, but the minimum cut can be found in polynomial time.

An approximation for Max Cut is as follows:

    max_cut(G):
        S = V.any_subset()
        while vertexes can be moved to increse c(S):
            move a vertex to increase c(S)
                        

Given that we can increase
![c(S)](http://chart.apis.google.com/chart?cht=tx&chl=c%28S%29 "c(S)")
at most ![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m")
times[^62^](#fn62), we must have a polynomial time algorithm.

Define the number of edges inside
![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") as
![e(s)](http://chart.apis.google.com/chart?cht=tx&chl=e%28s%29 "e(s)"),
and the number of edges from
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") to
![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") as
![d\_S(v)](http://chart.apis.google.com/chart?cht=tx&chl=d_S%28v%29 "d_S(v)"),
and the number of edges from
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") to
![V-S](http://chart.apis.google.com/chart?cht=tx&chl=V-S "V-S") as
![d\_{V-S}(v)](http://chart.apis.google.com/chart?cht=tx&chl=d_%7BV-S%7D%28v%29 "d_{V-S}(v)").
At the end of the algorithm, ![\\forall v \\in
S](http://chart.apis.google.com/chart?cht=tx&chl=%5Cforall%20v%20%5Cin%20S "\forall v \in S"),
![d\_S(v) \\le
d\_{V-S}(v)](http://chart.apis.google.com/chart?cht=tx&chl=d_S%28v%29%20%5Cle%20d_%7BV-S%7D%28v%29 "d_S(v) \le d_{V-S}(v)"),
otherwise we would move it.

\
![\\begin{aligned} \\sum\_{v \\in S} d\_{V - S}(v) &\\ge \\sum\_{v \\in
S} d\_S(v) \\\\ \\implies 2e(S) &\\le c(S) \\\\
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Csum_%7Bv%20%5Cin%20S%7D%20d_%7BV%20-%20S%7D%28v%29%20%26%5Cge%20%5Csum_%7Bv%20%5Cin%20S%7D%20d_S%28v%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cimplies%202e%28S%29%20%26%5Cle%20c%28S%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \sum_{v \in S} d_{V - S}(v) &\ge \sum_{v \in S} d_S(v) \\
                        \implies 2e(S) &\le c(S) \\
                    \end{aligned}")\

Similarly ![\\forall v \\in
V-S](http://chart.apis.google.com/chart?cht=tx&chl=%5Cforall%20v%20%5Cin%20V-S "\forall v \in V-S"):
Thus:

\
![\\begin{aligned} d\_{V-S}(v) &\\le d\_{S}(v) \\\\ \\sum\_{v \\in V-S}
d\_{V-S}(v) &\\le \\sum\_{v \\in V-S} d\_S(v) \\\\ \\implies 2e(V-S)
&\\le c(S)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20d_%7BV-S%7D%28v%29%20%26%5Cle%20d_%7BS%7D%28v%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Csum_%7Bv%20%5Cin%20V-S%7D%20d_%7BV-S%7D%28v%29%20%26%5Cle%20%5Csum_%7Bv%20%5Cin%20V-S%7D%20d_S%28v%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cimplies%202e%28V-S%29%20%26%5Cle%20c%28S%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        d_{V-S}(v) &\le d_{S}(v) \\
                        \sum_{v \in V-S} d_{V-S}(v) &\le \sum_{v \in V-S} d_S(v) \\
                        \implies 2e(V-S) &\le c(S)
                    \end{aligned}")\

Since ![m = e(S) + e(V-S) +
c(S)](http://chart.apis.google.com/chart?cht=tx&chl=m%20%3D%20e%28S%29%20%2B%20e%28V-S%29%20%2B%20c%28S%29 "m = e(S) + e(V-S) + c(S)"),
we can say:

\
![\\begin{aligned} m &= e(S) + e(V-S) + c(S) \\\\ 2m &= 2e(S) + 2e(V-S)
+ 2c(S) \\\\ &\\le c(S) + c(S) + 2c(S) \\\\ &= 4c(S)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20m%20%26%3D%20e%28S%29%20%2B%20e%28V-S%29%20%2B%20c%28S%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%202m%20%26%3D%202e%28S%29%20%2B%202e%28V-S%29%20%2B%202c%28S%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20c%28S%29%20%2B%20c%28S%29%20%2B%202c%28S%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%204c%28S%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        m &= e(S) + e(V-S) + c(S) \\
                        2m &= 2e(S) + 2e(V-S) + 2c(S) \\
                        &\le c(S) + c(S) + 2c(S) \\
                        &= 4c(S)
                    \end{aligned}")\

Thus ![m \\le 2
c(S)](http://chart.apis.google.com/chart?cht=tx&chl=m%20%5Cle%202%20c%28S%29 "m \le 2 c(S)"),
which means we have an approximation factor of
![\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B2%7D "\frac{1}{2}").

#### Random Algorithm for Max Cut Problem {#ssub:random_algorithm_for_max_cut_problem}

    max_cut(G):
        pick S at random
                        

We can do this analysis:

\
![\\begin{aligned} E[c(S)] &= E\\left[ \\sum\_{e \\in E} \\sigma(e)
\\right] \\\\ \\sigma(e) &= \\left\\{ \\begin{array}{lr} 1 :& \\text{ if
\$e\$ in cut }\\\\ 0 :& \\text{ otherwise } \\end{array} \\right. \\\\
E[c(S)] &= \\sum\_{e \\in E} E[\\sigma(e)] \\\\ &= \\sum\_{e \\in E}
\\frac{1}{2} \\\\ &= \\frac{m}{2}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%5Bc%28S%29%5D%20%26%3D%20E%5Cleft%5B%20%5Csum_%7Be%20%5Cin%20E%7D%20%5Csigma%28e%29%20%5Cright%5D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Csigma%28e%29%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%201%20%3A%26%20%5Ctext%7B%20if%20%24e%24%20in%20cut%20%7D%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%200%20%3A%26%20%5Ctext%7B%20otherwise%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%5Bc%28S%29%5D%20%26%3D%20%5Csum_%7Be%20%5Cin%20E%7D%20E%5B%5Csigma%28e%29%5D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_%7Be%20%5Cin%20E%7D%20%5Cfrac%7B1%7D%7B2%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7Bm%7D%7B2%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        E[c(S)] &= E\left[ \sum_{e \in E} \sigma(e) \right] \\
                        \sigma(e) &=
                            \left\{
                                \begin{array}{lr}
                                    1 :& \text{ if $e$ in cut }\\
                                    0 :& \text{ otherwise }
                                \end{array}
                            \right. \\
                        E[c(S)] &= \sum_{e \in E} E[\sigma(e)] \\
                        &= \sum_{e \in E} \frac{1}{2} \\
                        &= \frac{m}{2}
                    \end{aligned}")\

By doing this repeatedly, we can get a
![O(n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%29 "O(n)")-time
algorithm with a
![\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B2%7D "\frac{1}{2}")
approximation factor.

#### State of the Art in Max Cut {#ssub:state_of_the_art_in_max_cut}

The best known approximation factor for Max Cut is
![0.878](http://chart.apis.google.com/chart?cht=tx&chl=0.878 "0.878")
(unattributed).

Max SAT {#cha:max_sat}
=======

> Given a set of
> ![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m") clauses in
> CNF in ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")
> boolean variables ![X = \\{x\_1, \\ldots,
> x\_n\\}](http://chart.apis.google.com/chart?cht=tx&chl=X%20%3D%20%5C%7Bx_1%2C%20%5Cldots%2C%20x_n%5C%7D "X = \{x_1, \ldots, x_n\}"),
> find a boolean assignment to variables to make a maximum number of
> clauses true.

The decision version of this problem is NP-complete, since it’s just the
usual sat problem. For clauses of size ![\\le
2](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%202 "\le 2"), it
is still NP-complete. For problems with clauses are size 2, deciding if
can be satisfied is in P[^63^](#fn63).

Algorithm for Max-SAT {#sec:algorithm_for_max_sat}
---------------------

The algorithm is to pick the truth assignment at random.

We know that for any clause
![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c") containing
![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t") different
variables, we want to determine the probability that
![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c") is satisfied:

\
![\\begin{aligned} \\textsc{Pr}(\\text{\$c\$ is satisfied}) &= 1 -
\\textsc{Pr}{\\text{\$c\$ is not satisfied}} \\\\ &= 1 - \\frac{1}{2\^t}
\\\\ &\\ge (1 - \\frac{1}{2}) \\\\ &= \\frac{1}{2}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctextsc%7BPr%7D%28%5Ctext%7B%24c%24%20is%20satisfied%7D%29%20%26%3D%201%20-%20%5Ctextsc%7BPr%7D%7B%5Ctext%7B%24c%24%20is%20not%20satisfied%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201%20-%20%5Cfrac%7B1%7D%7B2%5Et%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20%281%20-%20%5Cfrac%7B1%7D%7B2%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7B2%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \textsc{Pr}(\text{$c$ is satisfied}) &= 1 - \textsc{Pr}{\text{$c$ is not satisfied}} \\
                    &= 1 - \frac{1}{2^t} \\
                    &\ge (1 - \frac{1}{2}) \\
                    &= \frac{1}{2}
                \end{aligned}")\

Thus the expected number of clauses satisfied is ![\\ge \\frac{1}{2}
m](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20%5Cfrac%7B1%7D%7B2%7D%20m "\ge \frac{1}{2} m").

We know that ![{\\textsc{opt}\\xspace}\\le
m](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%5Cle%20m "{\textsc{opt}\xspace}\le m"),
so the expected approxfactor is
![\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B2%7D "\frac{1}{2}").

Facts about the Max-SAT problem {#sec:facts_about_the_max_sat_problem}
-------------------------------

By the probabilistic method[^64^](#fn64), there always exists a truth
value assignment that satisfies at least half the clauses.

The proof is essentially that since the expected value of a random
variable is
![\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha "\alpha"),
then there is at least one value for the variable that has value ![\\ge
\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20%5Calpha "\ge \alpha").

Improved Algorithm for Max-Sat {#sec:improved_approximation_algorithm_for_the_max_sat}
------------------------------

By formulating this as an ILP problem, we can solve this using a LP
relaxation (Similar to the Weighted Vertex Cover solution on Page ) and
“randomized rounding” techniques.

Make variables
![x\_i](http://chart.apis.google.com/chart?cht=tx&chl=x_i "x_i"), ![i
\\in [1,
n]](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cin%20%5B1%2C%20n%5D "i \in [1, n]")
for each boolean variable
![a\_i](http://chart.apis.google.com/chart?cht=tx&chl=a_i "a_i"), and
![y\_i](http://chart.apis.google.com/chart?cht=tx&chl=y_i "y_i"), ![i
\\in [1,
m]](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cin%20%5B1%2C%20m%5D "i \in [1, m]")
for each clause.

We want to maximize ![\\sum\_i
y\_i](http://chart.apis.google.com/chart?cht=tx&chl=%5Csum_i%20y_i "\sum_i y_i").

We have one constraint per clause:

\
![\\begin{aligned} c\_1 = (\\bar{a\_1} \\lor a\_2) &\\to y\_1 \\le (1 -
x\_1) + x\_2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20c_1%20%3D%20%28%5Cbar%7Ba_1%7D%20%5Clor%20a_2%29%20%26%5Cto%20y_1%20%5Cle%20%281%20-%20x_1%29%20%2B%20x_2%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    c_1 = (\bar{a_1} \lor a_2) &\to y_1 \le (1 - x_1) + x_2
                \end{aligned}")\

And we have the LP relaxation constraints:

\
![\\begin{aligned} 0 \\le &x\_i \\le 1 : i \\in [1, n] \\\\ 0 \\le &y\_i
\\le 1 : i \\in [1, m]
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%200%20%5Cle%20%26x_i%20%5Cle%201%20%3A%20i%20%5Cin%20%5B1%2C%20n%5D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%200%20%5Cle%20%26y_i%20%5Cle%201%20%3A%20i%20%5Cin%20%5B1%2C%20m%5D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    0 \le &x_i \le 1 : i \in [1, n] \\
                    0 \le &y_i \le 1 : i \in [1, m]
                \end{aligned}")\

Using the PLP approximation, we solve for
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x")’s.

Then, we set our truth values ![A = \\{ a\_0, \\ldots,
a\_n\\}](http://chart.apis.google.com/chart?cht=tx&chl=A%20%3D%20%5C%7B%20a_0%2C%20%5Cldots%2C%20a_n%5C%7D "A = \{ a_0, \ldots, a_n\}")
as follows:

\
![\\begin{aligned} a\_i &= \\left\\{ \\begin{array}{lr} 1 :& \\text{
with probability \$x\_i\$ }\\\\ 0 :& \\text{ otherwise } \\end{array}
\\right.
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20a_i%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%201%20%3A%26%20%5Ctext%7B%20with%20probability%20%24x_i%24%20%7D%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%200%20%3A%26%20%5Ctext%7B%20otherwise%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    a_i &=
                        \left\{
                            \begin{array}{lr}
                                1 :& \text{ with probability $x_i$ }\\
                                0 :& \text{ otherwise }
                            \end{array}
                        \right.
                \end{aligned}")\

#### Analysis of Randomized Max 2-sat {#ssub:analysis_of_randomized_max_2_sat}

We have a given ![c\_2 = (a\_1 \\lor
a\_2)](http://chart.apis.google.com/chart?cht=tx&chl=c_2%20%3D%20%28a_1%20%5Clor%20a_2%29 "c_2 = (a_1 \lor a_2)").
In a LP solution, ![y \\le x\_1 +
x\_2](http://chart.apis.google.com/chart?cht=tx&chl=y%20%5Cle%20x_1%20%2B%20x_2 "y \le x_1 + x_2").
Then we have:

\
![\\begin{aligned} \\text{Pr}(\\text{\$c\_2\$ is satisfied}) &=
\\text{Pr}(a\_1 = 1 \\lor a\_2 = 1) \\\\ &= x\_1 + x\_2 - x\_1 x\_2 \\\\
&\\ge x\_1 + x\_2 - \\left( \\frac{x\_1 + x\_2}{2} \\right)\^2 \\\\
&\\ge y\_2 - \\frac{y\_2\^2}{4} \\\\ &\\ge y\_2 - \\frac{y\_2}{4} \\\\
&= \\frac{3}{4} y\_2 \\\\ \\text{Pr}(\\text{\$c\_2\$ is satisfied})
&\\ge \\frac{3}{4} y\_2 \\\\ E[\\textsc{num of clauses satisfied}] &\\ge
\\frac{3}{4} \\sum\_i y\_i \\\\ &= \\frac{3}{4}
{\\textsc{opt}\\xspace}\_{\\textsc{lp}} \\ge \\frac{3}{4}
{\\textsc{opt}\\xspace}\_{\\textsc{ilp}} \\ge \\frac{3}{4}
{\\textsc{opt}\\xspace}\_{\\textsc{MAX SAT}} \\\\
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7BPr%7D%28%5Ctext%7B%24c_2%24%20is%20satisfied%7D%29%20%26%3D%20%5Ctext%7BPr%7D%28a_1%20%3D%201%20%5Clor%20a_2%20%3D%201%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20x_1%20%2B%20x_2%20-%20x_1%20x_2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20x_1%20%2B%20x_2%20-%20%5Cleft%28%20%5Cfrac%7Bx_1%20%2B%20x_2%7D%7B2%7D%20%5Cright%29%5E2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20y_2%20-%20%5Cfrac%7By_2%5E2%7D%7B4%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20y_2%20-%20%5Cfrac%7By_2%7D%7B4%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B3%7D%7B4%7D%20y_2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7BPr%7D%28%5Ctext%7B%24c_2%24%20is%20satisfied%7D%29%20%26%5Cge%20%5Cfrac%7B3%7D%7B4%7D%20y_2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%5B%5Ctextsc%7Bnum%20of%20clauses%20satisfied%7D%5D%20%26%5Cge%20%5Cfrac%7B3%7D%7B4%7D%20%5Csum_i%20y_i%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B3%7D%7B4%7D%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%7B%5Ctextsc%7Blp%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cge%20%5Cfrac%7B3%7D%7B4%7D%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%7B%5Ctextsc%7Bilp%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cge%20%5Cfrac%7B3%7D%7B4%7D%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%7B%5Ctextsc%7BMAX%20SAT%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \text{Pr}(\text{$c_2$ is satisfied}) &= \text{Pr}(a_1 = 1 \lor a_2 = 1) \\
                        &= x_1 + x_2 - x_1 x_2 \\
                        &\ge x_1 + x_2 - \left( \frac{x_1 + x_2}{2} \right)^2 \\
                        &\ge y_2 - \frac{y_2^2}{4} \\
                        &\ge y_2 - \frac{y_2}{4} \\
                        &= \frac{3}{4} y_2 \\
                        \text{Pr}(\text{$c_2$ is satisfied}) &\ge \frac{3}{4} y_2 \\
                        E[\textsc{num of clauses satisfied}] &\ge \frac{3}{4} \sum_i y_i \\
                        &= \frac{3}{4} {\textsc{opt}\xspace}_{\textsc{lp}}
                        \ge \frac{3}{4} {\textsc{opt}\xspace}_{\textsc{ilp}}
                        \ge \frac{3}{4} {\textsc{opt}\xspace}_{\textsc{MAX SAT}} \\
                    \end{aligned}")\

Thus, we expect the number of clauses satisfied to be ![\\ge
\\frac{3}{4}
{\\textsc{opt}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20%5Cfrac%7B3%7D%7B4%7D%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D "\ge \frac{3}{4} {\textsc{opt}\xspace}").

#### Analysis of Randomized Max SAT {#ssub:analysis_of_randomized_max_sat}

We won’t do the analysis, but it shows that this method is better for
small clauses, and the algorithm described in
Section [sec:algorithm~f~or~m~ax~s~at] is better for large clauses.

Max-Sat Retrospective {#sec:max_sat_retrospective}
---------------------

The best-known max-sat algorithm is by Goemans & Williamson \`94, and is
a ![0.878](http://chart.apis.google.com/chart?cht=tx&chl=0.878 "0.878")
approximation factor[^65^](#fn65).

We also know that there is no approximation factor ![\\ge
0.942](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%200.942 "\ge 0.942"),
unless ![{\\textsc{P}\\xspace}=
{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}= {\textsc{NP}\xspace}").

So far, we’ve seen:

-   metricTSP - Saw a 2-approximation, but know of a 1.5-approximation

-   Vertex Cover - 2-approximation

-   Set Cover - ![O(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")

-   Max cut -
    ![\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B2%7D "\frac{1}{2}")

-   Max SAT -
    ![\\frac{3}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B3%7D%7B2%7D "\frac{3}{2}")

Polynomial-Time Approximation Scheme {#sec:polynomial_time_approximation_scheme}
------------------------------------

These types of algorithms are ones where we can get arbitrarily close to
![1](http://chart.apis.google.com/chart?cht=tx&chl=1 "1").

Though most of the details on these are in the next lesson (Chapter 16),
we will go into a few proofs now.

Without proof, it is presented that:

> Polynomial-time
> ![\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha "\alpha")-approximation
> for the Independent set problem implies a polynomial-time
> ![\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha "\alpha")-approximation
> for Max 3-sat.

### Reduction Preserving Constant Factor Approximation {#sub:reduction_preserving_constant_factor_approximation}

In \`92, this breakthrough result was published:

> If Max 3-sat has a ptas, then ![{\\textsc{P}\\xspace}=
> {\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}= {\textsc{NP}\xspace}").

Joined with the previous theorem, then there is no ptasfor the
independent set unless ![{\\textsc{P}\\xspace}=
{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}= {\textsc{NP}\xspace}").

Proving this:

Given a Max 3-SAT formula
![F](http://chart.apis.google.com/chart?cht=tx&chl=F "F"), we want to
transform it into an independent set problem as a polynomial-time
reduction ![\\text{Max } 3-\\textsc{sat} \\le\_p \\text{Independent
Set}](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctext%7BMax%20%7D%203-%5Ctextsc%7Bsat%7D%20%5Cle_p%20%5Ctext%7BIndependent%20Set%7D "\text{Max } 3-\textsc{sat} \le_p \text{Independent Set}").
While doing this, we want to preserve the approximation factor.

A clause ![c = (x\_1 \\lor \\bar{x\_2} \\lor
x\_3)](http://chart.apis.google.com/chart?cht=tx&chl=c%20%3D%20%28x_1%20%5Clor%20%5Cbar%7Bx_2%7D%20%5Clor%20x_3%29 "c = (x_1 \lor \bar{x_2} \lor x_3)")
becomes a triangle, and an edge between ![(x\_i,
\\bar{x\_i})](http://chart.apis.google.com/chart?cht=tx&chl=%28x_i%2C%20%5Cbar%7Bx_i%7D%29 "(x_i, \bar{x_i})")
for all occurences of the inversion in the SAT problem. This can be seen
in Figure [fig:indep~s~et~t~raingle].

![Independent Set from a Triangle](images/indep_set_traingle.png "fig:")
[fig:indep~s~et~t~raingle]

There truth value assignment that satisfies all
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") clauses iff
there is an independent set of
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") vertices.

In particular, ![{\\textsc{opt}\\xspace}\_\\text{Max 3-\\textsc{sat}}(F)
= {\\textsc{opt}\\xspace}\_\\text{Ind. Set}
(G)](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctext%7BMax%203-%5Ctextsc%7Bsat%7D%7D%28F%29%20%3D%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctext%7BInd.%20Set%7D%20%28G%29 "{\textsc{opt}\xspace}_\text{Max 3-\textsc{sat}}(F) = {\textsc{opt}\xspace}_\text{Ind. Set} (G)"),
and a polynomial time approximation for algorithm for Ind. Set that
gives ![A\_\\text{Ind. Set}(G) \\ge \\alpha
{\\textsc{opt}\\xspace}\_\\text{Ind.
Set}(G)](http://chart.apis.google.com/chart?cht=tx&chl=A_%5Ctext%7BInd.%20Set%7D%28G%29%20%5Cge%20%5Calpha%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctext%7BInd.%20Set%7D%28G%29 "A_\text{Ind. Set}(G) \ge \alpha {\textsc{opt}\xspace}_\text{Ind. Set}(G)")
implies a polynomial-time approximation algorithm for the max-sat that
gives ![A\_\\text{Max 3-\\textsc{sat}}(F) \\ge \\alpha
{\\textsc{opt}\\xspace}\_\\text{Max
3-\\textsc{sat}}(F)](http://chart.apis.google.com/chart?cht=tx&chl=A_%5Ctext%7BMax%203-%5Ctextsc%7Bsat%7D%7D%28F%29%20%5Cge%20%5Calpha%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctext%7BMax%203-%5Ctextsc%7Bsat%7D%7D%28F%29 "A_\text{Max 3-\textsc{sat}}(F) \ge \alpha {\textsc{opt}\xspace}_\text{Max 3-\textsc{sat}}(F)").

### Reduction Preserving Constant Factor Approximation, With a Different Constant {#sub:reduction_preserving_constant_factor_approximation_with_a_different_constant}

We give an example where a reduction provides constant-factor
approximation, but not the same constant.

We allude that the example here is a “gap-preserving reduction”, but we
won’t learn more about it in this course.

We’d like to show how a polynomial-time ![(1 +
\\varepsilon)](http://chart.apis.google.com/chart?cht=tx&chl=%281%20%2B%20%5Cvarepsilon%29 "(1 + \varepsilon)")-approximation
for Vertex Cover implies a polynomial-time ![(1 - 5
\\varepsilon)](http://chart.apis.google.com/chart?cht=tx&chl=%281%20-%205%20%5Cvarepsilon%29 "(1 - 5 \varepsilon)")-approximation
for Max 3-sat.

From this, we make the observations:

-   With the breakthrough result from earlier, we now know that there’s
    no ptasfor vertex cover (unless ![{\\textsc{P}\\xspace}=
    {\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}= {\textsc{NP}\xspace}")).

-   We have a 2-approximation for Vertex Cover, but this promises us a
    ![(1-5)](http://chart.apis.google.com/chart?cht=tx&chl=%281-5%29 "(1-5)")-approximation,
    which is vacuous (and therefor it doesn’t apply).

To prove our theorem, we need a reduction Max 3-sat
![\\le](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle "\le")
vertex cover with a good approximation factor preservation.

Using the above, we can reduce Max 3-sat
![\\le](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle "\le") Ind.
Set, plus the idea that
![U](http://chart.apis.google.com/chart?cht=tx&chl=U "U") is an Ind. Set
iff ![V-U](http://chart.apis.google.com/chart?cht=tx&chl=V-U "V-U") is a
vertex cover.

While this idea doesn’t give a good approximation factor in general, but
we only need it for graphs that come from Max 3-sat. From earlier,
picking random truth values for Max 3-sat, so
![{\\textsc{opt}\\xspace}\_{\\textsc{sat}} \\ge
\\frac{1}{2}m](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%7B%5Ctextsc%7Bsat%7D%7D%20%5Cge%20%5Cfrac%7B1%7D%7B2%7Dm "{\textsc{opt}\xspace}_{\textsc{sat}} \ge \frac{1}{2}m").

![A\_\\textsc{vc} \\le (1 + \\varepsilon)
{\\textsc{opt}\\xspace}\_\\textsc{vc}](http://chart.apis.google.com/chart?cht=tx&chl=A_%5Ctextsc%7Bvc%7D%20%5Cle%20%281%20%2B%20%5Cvarepsilon%29%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctextsc%7Bvc%7D "A_\textsc{vc} \le (1 + \varepsilon) {\textsc{opt}\xspace}_\textsc{vc}")
by assumption.

By reduction, we get the approximate polynomial-time for Max 3-sat
“![A\_\\textsc{sat}](http://chart.apis.google.com/chart?cht=tx&chl=A_%5Ctextsc%7Bsat%7D "A_\textsc{sat}")”.

\
![\\begin{aligned} A\_\\textsc{sat} &= 3m - A\_\\textsc{vc} \\\\
{\\textsc{opt}\\xspace}\_\\textsc{sat} &= 3m -
{\\textsc{opt}\\xspace}\_\\textsc{vc}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20A_%5Ctextsc%7Bsat%7D%20%26%3D%203m%20-%20A_%5Ctextsc%7Bvc%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctextsc%7Bsat%7D%20%26%3D%203m%20-%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctextsc%7Bvc%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        A_\textsc{sat} &= 3m - A_\textsc{vc} \\
                        {\textsc{opt}\xspace}_\textsc{sat} &= 3m - {\textsc{opt}\xspace}_\textsc{vc}
                    \end{aligned}")\

We want to prove that ![A\_\\textsc{sat} \\ge (1 - 5 \\varepsilon)
{\\textsc{opt}\\xspace}\_\\textsc{sat}](http://chart.apis.google.com/chart?cht=tx&chl=A_%5Ctextsc%7Bsat%7D%20%5Cge%20%281%20-%205%20%5Cvarepsilon%29%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctextsc%7Bsat%7D "A_\textsc{sat} \ge (1 - 5 \varepsilon) {\textsc{opt}\xspace}_\textsc{sat}").

From the above, we can reduce:

\
![\\begin{aligned} A\_\\textsc{sat} &= 3m - A\_\\textsc{vc} \\\\ &\\ge
3m - (1 + \\varepsilon) {\\textsc{opt}\\xspace}\_\\textsc{vc} \\\\ &= 3m
- (1+ \\varepsilon)(3m - {\\textsc{opt}\\xspace}\_\\textsc{sat}) \\\\ &=
{\\textsc{opt}\\xspace}\_\\textsc{sat} - \\varepsilon m + \\varepsilon
{\\textsc{opt}\\xspace}\_\\textsc{sat} \\\\ &\\ge
{\\textsc{opt}\\xspace}\_\\textsc{sat} - \\varepsilon 6
{\\textsc{opt}\\xspace}\_\\textsc{sat} + \\varepsilon
{\\textsc{opt}\\xspace}\_\\textsc{sat} \\\\ &=
{\\textsc{opt}\\xspace}\_\\textsc{sat} (1 - 5 \\varepsilon)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20A_%5Ctextsc%7Bsat%7D%20%26%3D%203m%20-%20A_%5Ctextsc%7Bvc%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%203m%20-%20%281%20%2B%20%5Cvarepsilon%29%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctextsc%7Bvc%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%203m%20-%20%281%2B%20%5Cvarepsilon%29%283m%20-%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctextsc%7Bsat%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctextsc%7Bsat%7D%20-%20%5Cvarepsilon%20m%20%2B%20%5Cvarepsilon%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctextsc%7Bsat%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctextsc%7Bsat%7D%20-%20%5Cvarepsilon%206%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctextsc%7Bsat%7D%20%2B%20%5Cvarepsilon%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctextsc%7Bsat%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D_%5Ctextsc%7Bsat%7D%20%281%20-%205%20%5Cvarepsilon%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        A_\textsc{sat} &= 3m - A_\textsc{vc} \\
                        &\ge 3m - (1 + \varepsilon) {\textsc{opt}\xspace}_\textsc{vc} \\
                        &= 3m - (1+ \varepsilon)(3m - {\textsc{opt}\xspace}_\textsc{sat}) \\
                        &= {\textsc{opt}\xspace}_\textsc{sat} - \varepsilon m + \varepsilon {\textsc{opt}\xspace}_\textsc{sat} \\
                        &\ge {\textsc{opt}\xspace}_\textsc{sat} - \varepsilon 6 {\textsc{opt}\xspace}_\textsc{sat} + \varepsilon {\textsc{opt}\xspace}_\textsc{sat} \\
                        &= {\textsc{opt}\xspace}_\textsc{sat} (1 - 5 \varepsilon)
                    \end{aligned}")\

Geometric Packing PTAS {#cha:geometric_packing_ptas}
======================

We’re going to look at packing problems.

Set Packing {#sec:set_packing}
-----------

We can express set packing through the following statement:

> Given elements ![\\{1, \\ldots,
> n\\}](http://chart.apis.google.com/chart?cht=tx&chl=%5C%7B1%2C%20%5Cldots%2C%20n%5C%7D "\{1, \ldots, n\}")
> and sets ![\\{S\_1, \\ldots,
> S\_k\\}](http://chart.apis.google.com/chart?cht=tx&chl=%5C%7BS_1%2C%20%5Cldots%2C%20S_k%5C%7D "\{S_1, \ldots, S_k\}"),
> with ![S\_i \\subseteq [1,
> n]](http://chart.apis.google.com/chart?cht=tx&chl=S_i%20%5Csubseteq%20%5B1%2C%20n%5D "S_i \subseteq [1, n]").
> Find the maximum set of
> ![S\_i](http://chart.apis.google.com/chart?cht=tx&chl=S_i "S_i") such
> that no two sets intersect.

There’s a graph version of the same problem:

> Given a graph ![G = (V,
> E)](http://chart.apis.google.com/chart?cht=tx&chl=G%20%3D%20%28V%2C%20E%29 "G = (V, E)"),
> find a maximum size subset ![U \\subseteq
> V](http://chart.apis.google.com/chart?cht=tx&chl=U%20%5Csubseteq%20V "U \subseteq V")
> such that no edge ![e = (u,
> v)](http://chart.apis.google.com/chart?cht=tx&chl=e%20%3D%20%28u%2C%20v%29 "e = (u, v)")
> has both endpoints in
> ![U](http://chart.apis.google.com/chart?cht=tx&chl=U "U").

The largest Indep. Set (See the definition of this problem inside
Section [sec:vertex~c~over]) is a special case of set packing, where all
edges incident to vertex
![v\_i](http://chart.apis.google.com/chart?cht=tx&chl=v_i "v_i") is the
set ![S\_i](http://chart.apis.google.com/chart?cht=tx&chl=S_i "S_i").

The independent set problem is NP-complete, and we can turn general set
packing into the independent set problem, therefore set packing is
NP-complete.

In fact, there is no
![n\^{1-\\varepsilon}](http://chart.apis.google.com/chart?cht=tx&chl=n%5E%7B1-%5Cvarepsilon%7D "n^{1-\varepsilon}")-approximation
ratio for independent set, unless ![{\\textsc{P}\\xspace}=
{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}= {\textsc{NP}\xspace}").

Geometric Set Packing With Squares {#sec:geometric_set_packing_with_squares}
----------------------------------

> Given ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") unit
> squares in the plane. Find the maximum number of squares such that no
> two intersect.

### Simple Constant Factor Approximation For Packing Unit Squares {#sub:simple_constant_factor_approximation_for_packing_unit_squares}

    pick_non_intersecting(S[] squares):
        ans = []
        while (|S| != 0):
            sq = s.random()
            s.remove_intersecting(sq)
            ans.append(sq)
        return ans
                        

This is a
![\\frac{1}{4}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B4%7D "\frac{1}{4}")-approximation
algorithm because at one square chosen by
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") intersects at
most four squares in opt.

Thus, each square of
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") intersects
![\\le
4](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%204 "\le 4")
squares of opt. Therefore ![{\\textsc{opt}\\xspace}\\le 4
A](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%5Cle%204%20A "{\textsc{opt}\xspace}\le 4 A").

### Grid Approximation Algorithm {#sub:grid_approximation_algorithm}

If we represent squares by their center points, and put down a unit grid
with the “even” squares, we can get the set of points from each of the
shaded squares.

Let ![R\_0](http://chart.apis.google.com/chart?cht=tx&chl=R_0 "R_0") be
the set of shaded squares. In fact, we can define:

\
![\\begin{aligned} R\_0 &= \\{ (x, y) : {\\left \\lfloor x \\right
\\rfloor } \\text{ is even}, {\\left \\lfloor y \\right \\rfloor }
\\text{ is even}\\} \\\\ R\_1 &= \\{ (x, y) : {\\left \\lfloor x \\right
\\rfloor } \\text{ is odd}, {\\left \\lfloor y \\right \\rfloor }
\\text{ is even}\\} \\\\ R\_2 &= \\{ (x, y) : {\\left \\lfloor x \\right
\\rfloor } \\text{ is even}, {\\left \\lfloor y \\right \\rfloor }
\\text{ is odd}\\} \\\\ R\_3 &= \\{ (x, y) : {\\left \\lfloor x \\right
\\rfloor } \\text{ is odd}, {\\left \\lfloor y \\right \\rfloor }
\\text{ is odd}\\}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20R_0%20%26%3D%20%5C%7B%20%28x%2C%20y%29%20%3A%20%7B%5Cleft%20%5Clfloor%20x%20%5Cright%20%5Crfloor%20%7D%20%5Ctext%7B%20is%20even%7D%2C%20%7B%5Cleft%20%5Clfloor%20y%20%5Cright%20%5Crfloor%20%7D%20%5Ctext%7B%20is%20even%7D%5C%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20R_1%20%26%3D%20%5C%7B%20%28x%2C%20y%29%20%3A%20%7B%5Cleft%20%5Clfloor%20x%20%5Cright%20%5Crfloor%20%7D%20%5Ctext%7B%20is%20odd%7D%2C%20%7B%5Cleft%20%5Clfloor%20y%20%5Cright%20%5Crfloor%20%7D%20%5Ctext%7B%20is%20even%7D%5C%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20R_2%20%26%3D%20%5C%7B%20%28x%2C%20y%29%20%3A%20%7B%5Cleft%20%5Clfloor%20x%20%5Cright%20%5Crfloor%20%7D%20%5Ctext%7B%20is%20even%7D%2C%20%7B%5Cleft%20%5Clfloor%20y%20%5Cright%20%5Crfloor%20%7D%20%5Ctext%7B%20is%20odd%7D%5C%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20R_3%20%26%3D%20%5C%7B%20%28x%2C%20y%29%20%3A%20%7B%5Cleft%20%5Clfloor%20x%20%5Cright%20%5Crfloor%20%7D%20%5Ctext%7B%20is%20odd%7D%2C%20%7B%5Cleft%20%5Clfloor%20y%20%5Cright%20%5Crfloor%20%7D%20%5Ctext%7B%20is%20odd%7D%5C%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        R_0 &= \{ (x, y) : {\left \lfloor x \right \rfloor } \text{ is even}, {\left \lfloor y \right \rfloor } \text{ is even}\} \\
                        R_1 &= \{ (x, y) : {\left \lfloor x \right \rfloor } \text{ is odd}, {\left \lfloor y \right \rfloor } \text{ is even}\} \\
                        R_2 &= \{ (x, y) : {\left \lfloor x \right \rfloor } \text{ is even}, {\left \lfloor y \right \rfloor } \text{ is odd}\} \\
                        R_3 &= \{ (x, y) : {\left \lfloor x \right \rfloor } \text{ is odd}, {\left \lfloor y \right \rfloor } \text{ is odd}\}
                    \end{aligned}")\

The best way to show this is through a figure. Refer to
Figure [fig:grid~a~pprox~a~lg] for a pictorial example.

![Grid Approximation Algorithm](images/grid_approx_alg.png "fig:")
[fig:grid~a~pprox~a~lg]

The algorithm is to take one point from each shaded square ![R\_0 \\cap
P](http://chart.apis.google.com/chart?cht=tx&chl=R_0%20%5Ccap%20P "R_0 \cap P"),
if there is one.

    grid_approx_alg(P Point[]):
        for i = 0...3:
            Q[i] = opt solution R_i.intersect(P)
        return max(Q)
                        

We know that ![|Q| \\ge \\frac{1}{4} \\sum
|Q\_i|](http://chart.apis.google.com/chart?cht=tx&chl=%7CQ%7C%20%5Cge%20%5Cfrac%7B1%7D%7B4%7D%20%5Csum%20%7CQ_i%7C "|Q| \ge \frac{1}{4} \sum |Q_i|"),
since we have ![\\max \\ge
\\text{avg}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmax%20%5Cge%20%5Ctext%7Bavg%7D "\max \ge \text{avg}").

\
![\\begin{aligned} {\\textsc{opt}\\xspace}&= \\sum\_{i=0}\^3 |
{\\textsc{opt}\\xspace}\\cap R\_i| \\\\ &\\le \\sum\_{i=0}\^3 |Q\_i|
\\\\ &\\le 4|Q|
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%26%3D%20%5Csum_%7Bi%3D0%7D%5E3%20%7C%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%5Ccap%20R_i%7C%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20%5Csum_%7Bi%3D0%7D%5E3%20%7CQ_i%7C%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%204%7CQ%7C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        {\textsc{opt}\xspace}&= \sum_{i=0}^3 | {\textsc{opt}\xspace}\cap R_i| \\
                        &\le \sum_{i=0}^3 |Q_i| \\
                        &\le 4|Q|
                    \end{aligned}")\

Thus, ![|Q| \\ge \\frac{1}{4}
{\\textsc{opt}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7CQ%7C%20%5Cge%20%5Cfrac%7B1%7D%7B4%7D%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D "|Q| \ge \frac{1}{4} {\textsc{opt}\xspace}").

### Arbitrary Grid Approximation Algorithm {#sub:arbitrary_grid_approximation_algorithm}

It turns out that we can get arbitrarily close to an approximation
factor of 1, using a “shifting grid” approach[^66^](#fn66)

We pick a ![k \\ge
2](http://chart.apis.google.com/chart?cht=tx&chl=k%20%5Cge%202 "k \ge 2"),
and let ![R\_{i,
j}](http://chart.apis.google.com/chart?cht=tx&chl=R_%7Bi%2C%20j%7D "R_{i, j}")
be defined as:

\
![\\begin{aligned} R\_{i, j} &= \\{ (x, y): {\\left \\lfloor x \\right
\\rfloor } \\% k \\not = i, {\\left \\lfloor y \\right \\rfloor } \\% k
\\not = j \\}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20R_%7Bi%2C%20j%7D%20%26%3D%20%5C%7B%20%28x%2C%20y%29%3A%20%7B%5Cleft%20%5Clfloor%20x%20%5Cright%20%5Crfloor%20%7D%20%5C%25%20k%20%5Cnot%20%3D%20i%2C%20%7B%5Cleft%20%5Clfloor%20y%20%5Cright%20%5Crfloor%20%7D%20%5C%25%20k%20%5Cnot%20%3D%20j%20%5C%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        R_{i, j} &= \{ (x, y): {\left \lfloor x \right \rfloor } \% k \not = i, {\left \lfloor y \right \rfloor } \% k \not = j \}
                    \end{aligned}")\

Over ![i \\in [0,
k-1]](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cin%20%5B0%2C%20k-1%5D "i \in [0, k-1]")
and ![j \\in [0,
k-1]](http://chart.apis.google.com/chart?cht=tx&chl=j%20%5Cin%20%5B0%2C%20k-1%5D "j \in [0, k-1]").
Refer to Figure [] for
![k=3](http://chart.apis.google.com/chart?cht=tx&chl=k%3D3 "k=3").

![Arbitrary Grid Approximation
Algorithm](images/arbitrary_grid_approx_alg.png "fig:")
[fig:arbitrary~g~rid~a~pprox~a~lg]

Note that our points lie in a ![n\\cdot
n](http://chart.apis.google.com/chart?cht=tx&chl=n%5Ccdot%20n "n\cdot n")
square without loss of generality.

For a given ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k"),
the number of black squares is ![\\le \\frac{n}{k} \\cdot \\frac{n}{k} =
\\frac{n\^2}{k\^2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%5Cfrac%7Bn%7D%7Bk%7D%20%5Ccdot%20%5Cfrac%7Bn%7D%7Bk%7D%20%3D%20%5Cfrac%7Bn%5E2%7D%7Bk%5E2%7D "\le \frac{n}{k} \cdot \frac{n}{k} = \frac{n^2}{k^2}").

Also, the number of points we can choose in a single black square is
![\\le (k -
1)\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%28k%20-%201%29%5E2 "\le (k - 1)^2").

Since each set of black squares is independent, we can solve the problem
optimally for ![R\_{i,j} \\cap
P](http://chart.apis.google.com/chart?cht=tx&chl=R_%7Bi%2Cj%7D%20%5Ccap%20P "R_{i,j} \cap P")
in polynomial time by trying all possible subsets of ![\\le
(k-1)\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%28k-1%29%5E2 "\le (k-1)^2")
points. There are
![O(n\^{(k-1)\^2})](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E%7B%28k-1%29%5E2%7D%29 "O(n^{(k-1)^2})")
possible subsets per square.

The algorithm is as follows:

    arbitrary_grid_approximation_algorithm(P, k):
        for i=[0, k-1]:
            for j=[0, k-1]:
                Q[i][j] = R[i][j].intersect(P)
        return max(Q)
                        

\
![\\begin{aligned} \\max &\\ge \\text{avg} \\\\ \\implies |Q| \\ge
\\frac{1}{k\^2} \\sum\_{i,j=0}\^{k-1} Q\_{i, j}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmax%20%26%5Cge%20%5Ctext%7Bavg%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cimplies%20%7CQ%7C%20%5Cge%20%5Cfrac%7B1%7D%7Bk%5E2%7D%20%5Csum_%7Bi%2Cj%3D0%7D%5E%7Bk-1%7D%20Q_%7Bi%2C%20j%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \max &\ge \text{avg} \\
                        \implies |Q| \ge \frac{1}{k^2} \sum_{i,j=0}^{k-1} Q_{i, j}
                    \end{aligned}")\

Since each point is in
![(k-1)\^2](http://chart.apis.google.com/chart?cht=tx&chl=%28k-1%29%5E2 "(k-1)^2")
of the
![R\_{i,j}](http://chart.apis.google.com/chart?cht=tx&chl=R_%7Bi%2Cj%7D "R_{i,j}")’s,
then we have:

\
![\\begin{aligned} (k-1)\^2 {\\textsc{opt}\\xspace}&= \\sum\_{i,j} |
{\\textsc{opt}\\xspace}\\cap R\_{i, j} | \\\\ &\\le \\sum\_{i, j} |
Q\_{i, j} | \\\\ &\\le k\^2 | Q |
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%28k-1%29%5E2%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%26%3D%20%5Csum_%7Bi%2Cj%7D%20%7C%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%5Ccap%20R_%7Bi%2C%20j%7D%20%7C%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20%5Csum_%7Bi%2C%20j%7D%20%7C%20Q_%7Bi%2C%20j%7D%20%7C%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20k%5E2%20%7C%20Q%20%7C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        (k-1)^2 {\textsc{opt}\xspace}&= \sum_{i,j} | {\textsc{opt}\xspace}\cap R_{i, j} | \\
                        &\le \sum_{i, j} | Q_{i, j} | \\
                        &\le k^2 | Q |
                    \end{aligned}")\

So we have ![|Q| \\ge
\\frac{(k-1)\^2}{k\^2}{\\textsc{opt}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7CQ%7C%20%5Cge%20%5Cfrac%7B%28k-1%29%5E2%7D%7Bk%5E2%7D%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D "|Q| \ge \frac{(k-1)^2}{k^2}{\textsc{opt}\xspace}")
with a runtime ![O(k\^2
n\^{(k-1)\^2})](http://chart.apis.google.com/chart?cht=tx&chl=O%28k%5E2%20n%5E%7B%28k-1%29%5E2%7D%29 "O(k^2 n^{(k-1)^2})").

PTAS-like Definitions {#sec:ptas_like_definitions}
---------------------

You’d think that using these for so long, we would’ve defined this stuff
already:

Approximation Scheme
:   an algorithm
    ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A"), input
    ![I](http://chart.apis.google.com/chart?cht=tx&chl=I "I") and
    parameter
    ![\\varepsilon](http://chart.apis.google.com/chart?cht=tx&chl=%5Cvarepsilon "\varepsilon").

    -   For min problem: ![A(I, \\varepsilon) \\le (1 + \\varepsilon)
        {\\textsc{opt}\\xspace}(I)](http://chart.apis.google.com/chart?cht=tx&chl=A%28I%2C%20%5Cvarepsilon%29%20%5Cle%20%281%20%2B%20%5Cvarepsilon%29%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28I%29 "A(I, \varepsilon) \le (1 + \varepsilon) {\textsc{opt}\xspace}(I)")

    -   For max problem: ![A(I, \\varepsilon) \\ge (1 - \\varepsilon)
        {\\textsc{opt}\\xspace}(I)](http://chart.apis.google.com/chart?cht=tx&chl=A%28I%2C%20%5Cvarepsilon%29%20%5Cge%20%281%20-%20%5Cvarepsilon%29%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28I%29 "A(I, \varepsilon) \ge (1 - \varepsilon) {\textsc{opt}\xspace}(I)")

Polynomial Time Approximation Scheme (PTAS)
:   an algorithm
    ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") that for
    each fixed
    ![\\varepsilon](http://chart.apis.google.com/chart?cht=tx&chl=%5Cvarepsilon "\varepsilon"),
    ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") runs in
    Ptime in ![n =
    |I|](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3D%20%7CI%7C "n = |I|").
    e.g.
    ![O(n\^\\frac{1}{\\varepsilon})](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E%5Cfrac%7B1%7D%7B%5Cvarepsilon%7D%29 "O(n^\frac{1}{\varepsilon})").

Fully Polynomial Time Approximation Scheme (FPTAS)
:   an algorithm
    ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") that runs
    in Ptime in ![n =
    |I|](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3D%20%7CI%7C "n = |I|")
    and
    ![\\frac{1}{\\varepsilon}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B%5Cvarepsilon%7D "\frac{1}{\varepsilon}").
    e.g. ![O(\\frac{1}{\\varepsilon}\^2
    n\^3)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Cfrac%7B1%7D%7B%5Cvarepsilon%7D%5E2%20n%5E3%29 "O(\frac{1}{\varepsilon}^2 n^3)").

For the algorithm described in
Subsection [sub:arbitrary~g~rid~a~pproximation~a~lgorithm], the
approximation factor ![\\frac{(k-1)\^2}{k\^2} = 1 - \\frac{2k -
1}{k\^2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B%28k-1%29%5E2%7D%7Bk%5E2%7D%20%3D%201%20-%20%5Cfrac%7B2k%20-%201%7D%7Bk%5E2%7D "\frac{(k-1)^2}{k^2} = 1 - \frac{2k - 1}{k^2}"),
so ![\\varepsilon = \\frac{2k -
1}{k\^2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cvarepsilon%20%3D%20%5Cfrac%7B2k%20-%201%7D%7Bk%5E2%7D "\varepsilon = \frac{2k - 1}{k^2}").

The runtime is ![O(k\^2
n\^{(k-1)\^2})](http://chart.apis.google.com/chart?cht=tx&chl=O%28k%5E2%20n%5E%7B%28k-1%29%5E2%7D%29 "O(k^2 n^{(k-1)^2})").
We have ![\\varepsilon \< \\frac{2k}{k} =
\\frac{2}{k}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cvarepsilon%20%3C%20%5Cfrac%7B2k%7D%7Bk%7D%20%3D%20%5Cfrac%7B2%7D%7Bk%7D "\varepsilon < \frac{2k}{k} = \frac{2}{k}"),
so ![k \<
\\frac{2}{\\varepsilon}](http://chart.apis.google.com/chart?cht=tx&chl=k%20%3C%20%5Cfrac%7B2%7D%7B%5Cvarepsilon%7D "k < \frac{2}{\varepsilon}").
Also we have ![(k-1)\^2 \< k\^2 \<
\\frac{4}{\\varepsilon\^2}](http://chart.apis.google.com/chart?cht=tx&chl=%28k-1%29%5E2%20%3C%20k%5E2%20%3C%20%5Cfrac%7B4%7D%7B%5Cvarepsilon%5E2%7D "(k-1)^2 < k^2 < \frac{4}{\varepsilon^2}").
So we have the overall runtime in ![O(\\frac{1}{\\varepsilon\^2} n
\^{\\frac{4}{\\varepsilon\^2}})](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Cfrac%7B1%7D%7B%5Cvarepsilon%5E2%7D%20n%20%5E%7B%5Cfrac%7B4%7D%7B%5Cvarepsilon%5E2%7D%7D%29 "O(\frac{1}{\varepsilon^2} n ^{\frac{4}{\varepsilon^2}})").
Thus this is a ptasbut not a fptas.

Bin Packing PTAS {#cha:bin_packing_ptas}
================

Bin packing is a cool problem.

Bin Packing Description and Variants {#sec:bin_packing_description_and_variants}
------------------------------------

> Given ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")
> numbers[^67^](#fn67) ![S = \\{s\_1, \\ldots,
> s\_n\\}](http://chart.apis.google.com/chart?cht=tx&chl=S%20%3D%20%5C%7Bs_1%2C%20%5Cldots%2C%20s_n%5C%7D "S = \{s_1, \ldots, s_n\}"),
> and ![s\_i \\in [0,
> 1]](http://chart.apis.google.com/chart?cht=tx&chl=s_i%20%5Cin%20%5B0%2C%201%5D "s_i \in [0, 1]").
> Pack ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") into
> the minimal number of unit bins possible.

This problem is NP-hard, since it generalizes the partition problem:

> Given ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") as
> above, we can we split
> ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") into two
> bins ![U](http://chart.apis.google.com/chart?cht=tx&chl=U "U") and
> ![S-U](http://chart.apis.google.com/chart?cht=tx&chl=S-U "S-U") such
> that:
>
> \
> ![\\begin{aligned} \\sum\_{s \\in U} s &= \\sum\_{s \\in S-U} s
> \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Csum_%7Bs%20%5Cin%20U%7D%20s%20%26%3D%20%5Csum_%7Bs%20%5Cin%20S-U%7D%20s%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
>                         \sum_{s \in U} s &= \sum_{s \in S-U} s
>                     \end{aligned}")\

There are two variants to this problem:

Online
:   numbers in ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S")
    arrive one at a time and must be inserted to bins immediately.

Offline
:   all numbers in
    ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") arrive
    simultaneously.

First-Fit Bin Packing {#sec:first_fit_bin_packing}
---------------------

The first-fit algorithm is really simple:

> Insert the element into the first bin that fits it.

Due to the algorithm’s simplicity, this can be done online.

Let ![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m") be the
number of bins used by first fit. Since no two bins are ![\\le
\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%5Cfrac%7B1%7D%7B2%7D "\le \frac{1}{2}")
full, then at least ![m -
1](http://chart.apis.google.com/chart?cht=tx&chl=m%20-%201 "m - 1") bins
are ![\>
\\frac{1}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%3E%20%5Cfrac%7B1%7D%7B2%7D "> \frac{1}{2}").

\
![\\begin{aligned} \\frac{1}{2} (m-1) \< \\sum s\_i \\\\ &\\le
{\\textsc{opt}\\xspace}\\\\ m &\< 2{\\textsc{opt}\\xspace}+ 1
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B1%7D%7B2%7D%20%28m-1%29%20%3C%20%5Csum%20s_i%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20m%20%26%3C%202%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%2B%201%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \frac{1}{2} (m-1) < \sum s_i \\
                    &\le {\textsc{opt}\xspace}\\
                    m &< 2{\textsc{opt}\xspace}+ 1
                \end{aligned}")\

So ![m \\le 2
{\\textsc{opt}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=m%20%5Cle%202%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D "m \le 2 {\textsc{opt}\xspace}").

We state without proof that the first fit algorithm uses ![\\le 1.7
{\\textsc{opt}\\xspace}+
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%201.7%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%2B%201 "\le 1.7 {\textsc{opt}\xspace}+ 1")
bins, and this is tight[^68^](#fn68).

First Fit Decreasing Bin Packing {#sec:first_fit_decreasing_bin_packing}
--------------------------------

An off-line algorithm allows us to sort our input in a decreasing order.

First-fit decreasing sorts
![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") descending,
then applies the first fit algorithm.

We have the asymptotic ration of ![\\frac{11}{9} =
1.22](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B11%7D%7B9%7D%20%3D%201.22 "\frac{11}{9} = 1.22"),
which is tight.

PTAS for offline Bin Packing {#sec:ptas_for_offline_bin_packing}
----------------------------

For any constant ![\\varepsilon \>
0](http://chart.apis.google.com/chart?cht=tx&chl=%5Cvarepsilon%20%3E%200 "\varepsilon > 0"),
there is a polynomial-time algorithm
![A'](http://chart.apis.google.com/chart?cht=tx&chl=A%27 "A'")that uses
![\\le (1 + \\varepsilon){\\textsc{opt}\\xspace}+
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%281%20%2B%20%5Cvarepsilon%29%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%2B%201 "\le (1 + \varepsilon){\textsc{opt}\xspace}+ 1")
bins.

The “![+1](http://chart.apis.google.com/chart?cht=tx&chl=%2B1 "+1")
bins” is crucial:

> Prove that 2 bins there is no Ptime approximation algorithm with an
> approximation factor of ![\<
> 1.5](http://chart.apis.google.com/chart?cht=tx&chl=%3C%201.5 "< 1.5")
> (unless ![{\\textsc{P}\\xspace}=
> {\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}= {\textsc{NP}\xspace}")).

The algorithm
![A'](http://chart.apis.google.com/chart?cht=tx&chl=A%27 "A'") is built
from two cases:

1.  ![\\forall i: s\_i \\ge
    \\delta](http://chart.apis.google.com/chart?cht=tx&chl=%5Cforall%20i%3A%20s_i%20%5Cge%20%5Cdelta "\forall i: s_i \ge \delta"),
    and there are only
    ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") possible
    values of
    ![s\_i](http://chart.apis.google.com/chart?cht=tx&chl=s_i "s_i") for
    constant ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")
    and
    ![\\delta](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta "\delta").

    We can solve exactly through brute force enumeration.

    There are ![\\le
    \\frac{1}{\\delta}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%5Cfrac%7B1%7D%7B%5Cdelta%7D "\le \frac{1}{\delta}")
    items in each bin, so there are
    ![k\^\\frac{1}{\\delta}](http://chart.apis.google.com/chart?cht=tx&chl=k%5E%5Cfrac%7B1%7D%7B%5Cdelta%7D "k^\frac{1}{\delta}")
    ways to fill each bin. Given that there are ![\\le
    n](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20n "\le n")
    bins, where each bin has
    ![k\^\\frac{1}{\\delta}](http://chart.apis.google.com/chart?cht=tx&chl=k%5E%5Cfrac%7B1%7D%7B%5Cdelta%7D "k^\frac{1}{\delta}")
    choices. Overall, we have
    ![O(n\^{k\^\\frac{1}{\\delta}})](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E%7Bk%5E%5Cfrac%7B1%7D%7B%5Cdelta%7D%7D%29 "O(n^{k^\frac{1}{\delta}})"),
    which is polynomial for fixed
    ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") and
    ![\\delta](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta "\delta"),
    but huge.

    Apparently we can do better with ILP algorithms.

2.  ![\\forall i: s\_i \\ge
    \\delta](http://chart.apis.google.com/chart?cht=tx&chl=%5Cforall%20i%3A%20s_i%20%5Cge%20%5Cdelta "\forall i: s_i \ge \delta")
    for some constant
    ![\\delta](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta "\delta").

    We convert this to the first case by rounding.

    Sort values of
    ![s\_i](http://chart.apis.google.com/chart?cht=tx&chl=s_i "s_i")
    ascending, and chop every
    ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") values of
    ![s\_i](http://chart.apis.google.com/chart?cht=tx&chl=s_i "s_i")
    (![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") is chosen
    later).

    Create a set with modified input rounded up to the nearest
    ![s\_{\\frac{ni}{k}}](http://chart.apis.google.com/chart?cht=tx&chl=s_%7B%5Cfrac%7Bni%7D%7Bk%7D%7D "s_{\frac{ni}{k}}"):

    \
    ![\\begin{aligned} S\^+ &= \\{ s\_{\\frac{n}{k}}, \\ldots
    s\_\\frac{n}{k}, s\_{\\frac{2n}{k}}, \\ldots s\_\\frac{2n}{k},
    \\ldots s\_{n}, \\ldots s\_n \\}
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20S%5E%2B%20%26%3D%20%5C%7B%20s_%7B%5Cfrac%7Bn%7D%7Bk%7D%7D%2C%20%5Cldots%20s_%5Cfrac%7Bn%7D%7Bk%7D%2C%20s_%7B%5Cfrac%7B2n%7D%7Bk%7D%7D%2C%20%5Cldots%20s_%5Cfrac%7B2n%7D%7Bk%7D%2C%20%5Cldots%20s_%7Bn%7D%2C%20%5Cldots%20s_n%20%5C%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                                S^+ &= \{ s_{\frac{n}{k}}, \ldots s_\frac{n}{k}, s_{\frac{2n}{k}}, \ldots s_\frac{2n}{k}, \ldots s_{n}, \ldots s_n \}
                            \end{aligned}")\

    In other words, there are
    ![\\frac{n}{k}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7Bn%7D%7Bk%7D "\frac{n}{k}")
    of
    ![s\_{\\frac{n}{k}}](http://chart.apis.google.com/chart?cht=tx&chl=s_%7B%5Cfrac%7Bn%7D%7Bk%7D%7D "s_{\frac{n}{k}}").

    We then apply part 1 to
    ![S\^+](http://chart.apis.google.com/chart?cht=tx&chl=S%5E%2B "S^+").

    If we define
    ![S\^-](http://chart.apis.google.com/chart?cht=tx&chl=S%5E- "S^-")
    similarly to
    ![S\^+](http://chart.apis.google.com/chart?cht=tx&chl=S%5E%2B "S^+")
    but instead rounding down instead of up, then we have:

    \
    ![\\begin{aligned} {\\textsc{opt}\\xspace}(S\^-) &\\le
    {\\textsc{opt}\\xspace}(S) \\\\ {\\textsc{opt}\\xspace}(S\^+) &\\le
    {\\textsc{opt}\\xspace}(S\^-) + \\frac{n}{k} \\\\ &\\le
    {\\textsc{opt}\\xspace}(S) + \\frac{n}{k}
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%5E-%29%20%26%5Cle%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%5E%2B%29%20%26%5Cle%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%5E-%29%20%2B%20%5Cfrac%7Bn%7D%7Bk%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%29%20%2B%20%5Cfrac%7Bn%7D%7Bk%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                                {\textsc{opt}\xspace}(S^-) &\le {\textsc{opt}\xspace}(S) \\
                                {\textsc{opt}\xspace}(S^+) &\le {\textsc{opt}\xspace}(S^-) + \frac{n}{k} \\
                                &\le {\textsc{opt}\xspace}(S) + \frac{n}{k}
                            \end{aligned}")\

    Now ![n \\delta \\le \\sum s\_i \\le
    {\\textsc{opt}\\xspace}(S)](http://chart.apis.google.com/chart?cht=tx&chl=n%20%5Cdelta%20%5Cle%20%5Csum%20s_i%20%5Cle%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%29 "n \delta \le \sum s_i \le {\textsc{opt}\xspace}(S)"),
    so ![n \\le
    \\frac{{\\textsc{opt}\\xspace}(S)}{\\delta}](http://chart.apis.google.com/chart?cht=tx&chl=n%20%5Cle%20%5Cfrac%7B%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%29%7D%7B%5Cdelta%7D "n \le \frac{{\textsc{opt}\xspace}(S)}{\delta}").

    \
    ![\\begin{aligned} {\\textsc{opt}\\xspace}(S\^+) &\\le
    {\\textsc{opt}\\xspace}(S) +
    \\frac{{\\textsc{opt}\\xspace}(S)}{k\\delta} \\\\ &=
    {\\textsc{opt}\\xspace}(S) + \\left( 1 + \\frac{1}{k \\delta}
    \\right)
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%5E%2B%29%20%26%5Cle%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%29%20%2B%20%5Cfrac%7B%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%29%7D%7Bk%5Cdelta%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%29%20%2B%20%5Cleft%28%201%20%2B%20%5Cfrac%7B1%7D%7Bk%20%5Cdelta%7D%20%5Cright%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                                {\textsc{opt}\xspace}(S^+) &\le {\textsc{opt}\xspace}(S) + \frac{{\textsc{opt}\xspace}(S)}{k\delta} \\
                                &= {\textsc{opt}\xspace}(S) + \left( 1 + \frac{1}{k \delta} \right)
                            \end{aligned}")\

    If we set ![k =
    \\frac{1}{\\delta\^2}](http://chart.apis.google.com/chart?cht=tx&chl=k%20%3D%20%5Cfrac%7B1%7D%7B%5Cdelta%5E2%7D "k = \frac{1}{\delta^2}"),
    then ![{\\textsc{opt}\\xspace}(S\^+) \\le opt(S)(1 +
    \\delta)](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%5E%2B%29%20%5Cle%20opt%28S%29%281%20%2B%20%5Cdelta%29 "{\textsc{opt}\xspace}(S^+) \le opt(S)(1 + \delta)").

The final algorithm uses case 2 to pack all
![s\_i](http://chart.apis.google.com/chart?cht=tx&chl=s_i "s_i")’s where
![s\_i \\ge
\\delta](http://chart.apis.google.com/chart?cht=tx&chl=s_i%20%5Cge%20%5Cdelta "s_i \ge \delta"),
then use first fit to pack the remaining
![s\_i](http://chart.apis.google.com/chart?cht=tx&chl=s_i "s_i")’s in
the empty spaces of all bins.

### Analysis of the PTAS {#sub:analysis_of_the_ptas}

Our goal is to prove that ![A \\le (1 + \\varepsilon)
{\\textsc{opt}\\xspace}+
1](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Cle%20%281%20%2B%20%5Cvarepsilon%29%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%2B%201 "A \le (1 + \varepsilon) {\textsc{opt}\xspace}+ 1").

If the second part does not use new bins, then it’s ok to use ![\\delta
=
\\varepsilon](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta%20%3D%20%5Cvarepsilon "\delta = \varepsilon").

Otherwise, we have use
![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m") bins in our
algorithm.

Only the last bin can have size ![\\le 1 -
\\delta](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%201%20-%20%5Cdelta "\le 1 - \delta"),
otherwise first fit wouldn’t have filled the last bin. Then:

\
![\\begin{aligned} \\sum s\_i \\ge (m-1)(1-\\delta) \\\\ m \\le
\\frac{\\sum s\_i}{1-\\delta} + 1 \\le
\\frac{{\\textsc{opt}\\xspace}(S)}{1 - \\delta} + 1
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Csum%20s_i%20%5Cge%20%28m-1%29%281-%5Cdelta%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20m%20%5Cle%20%5Cfrac%7B%5Csum%20s_i%7D%7B1-%5Cdelta%7D%20%2B%201%20%5Cle%20%5Cfrac%7B%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%29%7D%7B1%20-%20%5Cdelta%7D%20%2B%201%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \sum s_i \ge (m-1)(1-\delta) \\
                        m \le \frac{\sum s_i}{1-\delta} + 1 \le \frac{{\textsc{opt}\xspace}(S)}{1 - \delta} + 1
                    \end{aligned}")\

If we choose ![\\frac{1}{1-\\delta} = 1 +
\\varepsilon](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B1-%5Cdelta%7D%20%3D%201%20%2B%20%5Cvarepsilon "\frac{1}{1-\delta} = 1 + \varepsilon"),
then we have ![\\delta = \\frac{\\varepsilon}{1 +
\\varepsilon}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta%20%3D%20%5Cfrac%7B%5Cvarepsilon%7D%7B1%20%2B%20%5Cvarepsilon%7D "\delta = \frac{\varepsilon}{1 + \varepsilon}")
and ![m \\le (1 + \\varepsilon) {\\textsc{opt}\\xspace}(S) +
1](http://chart.apis.google.com/chart?cht=tx&chl=m%20%5Cle%20%281%20%2B%20%5Cvarepsilon%29%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%29%20%2B%201 "m \le (1 + \varepsilon) {\textsc{opt}\xspace}(S) + 1")
as desired.

The runtime is as follows:

\
![\\begin{aligned} O(n\^{k\^\\frac{1}{\\delta}}) &= O\\left(n\^ {\\left(
\\frac{(1 + \\varepsilon)\^2}{\\varepsilon} \\right)
\^\\frac{1+\\varepsilon}{\\varepsilon}} \\right)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20O%28n%5E%7Bk%5E%5Cfrac%7B1%7D%7B%5Cdelta%7D%7D%29%20%26%3D%20O%5Cleft%28n%5E%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Cleft%28%20%5Cfrac%7B%281%20%2B%20%5Cvarepsilon%29%5E2%7D%7B%5Cvarepsilon%7D%20%5Cright%29%20%5E%5Cfrac%7B1%2B%5Cvarepsilon%7D%7B%5Cvarepsilon%7D%7D%0A%5Cright%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        O(n^{k^\frac{1}{\delta}}) &= O\left(n^                        {\left( \frac{(1 + \varepsilon)^2}{\varepsilon} \right) ^\frac{1+\varepsilon}{\varepsilon}}
\right)
                    \end{aligned}")\

Improvements for Bin Packing Algorithms {#sec:improvements_for_bin_packing_algorithms}
---------------------------------------

Karmarkar and Karp in \`82 created an asymptotic ![(1 +
\\varepsilon)](http://chart.apis.google.com/chart?cht=tx&chl=%281%20%2B%20%5Cvarepsilon%29 "(1 + \varepsilon)")-approximation
that runs in ![O\\left( \\left(\\frac{1}{\\varepsilon} \\right)\^8 n
\\log n
\\right)](http://chart.apis.google.com/chart?cht=tx&chl=O%5Cleft%28%20%5Cleft%28%5Cfrac%7B1%7D%7B%5Cvarepsilon%7D%20%5Cright%29%5E8%20n%20%5Clog%20n%20%5Cright%29 "O\left( \left(\frac{1}{\varepsilon} \right)^8 n \log n \right)")
time. This is an example of a FPTAS.

It is openif we can get ![n\_\\text{bins} \\le
{\\textsc{opt}\\xspace}(S) +
O(1)](http://chart.apis.google.com/chart?cht=tx&chl=n_%5Ctext%7Bbins%7D%20%5Cle%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28S%29%20%2B%20O%281%29 "n_\text{bins} \le {\textsc{opt}\xspace}(S) + O(1)")
in Ptime.

Knapsack FPTAS {#cha:knapsack_fptas}
==============

Problem Background {#sec:problem_background}
------------------

> Give objects ![1 \\ldots
> n](http://chart.apis.google.com/chart?cht=tx&chl=1%20%5Cldots%20n "1 \ldots n"),
> each with size ![s\_i \\in
> \\mathbf{N}](http://chart.apis.google.com/chart?cht=tx&chl=s_i%20%5Cin%20%5Cmathbf%7BN%7D "s_i \in \mathbf{N}")
> and profit ![p\_i \\in
> \\mathbf{N}](http://chart.apis.google.com/chart?cht=tx&chl=p_i%20%5Cin%20%5Cmathbf%7BN%7D "p_i \in \mathbf{N}"),
> given knapsack capacity
> ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") find ![K
> \\subseteq \\{1, \\ldots, n
> \\}](http://chart.apis.google.com/chart?cht=tx&chl=K%20%5Csubseteq%20%5C%7B1%2C%20%5Cldots%2C%20n%20%5C%7D "K \subseteq \{1, \ldots, n \}")
> such that ![\\sum\_{i \\in K} s\_i \\le
> B](http://chart.apis.google.com/chart?cht=tx&chl=%5Csum_%7Bi%20%5Cin%20K%7D%20s_i%20%5Cle%20B "\sum_{i \in K} s_i \le B")
> while maximizing ![\\sum\_{i \\in K}
> p\_i](http://chart.apis.google.com/chart?cht=tx&chl=%5Csum_%7Bi%20%5Cin%20K%7D%20p_i "\sum_{i \in K} p_i").

The decision version of this problem is NP-complete[^69^](#fn69).

Pseudo-Polynomial Time Algorithm for Knapsack with DP {#sec:pseudo_polynomial_time_algorithm_for_knapsack_with_dp}
-----------------------------------------------------

We want to find a solution to the knapsack problem using a DP solution.

A subproblem ![S(i,
p)](http://chart.apis.google.com/chart?cht=tx&chl=S%28i%2C%20p%29 "S(i, p)")
is defined as the minimum size of the subset of items in ![[1,
i]](http://chart.apis.google.com/chart?cht=tx&chl=%5B1%2C%20i%5D "[1, i]")
with profit of exactly
![p](http://chart.apis.google.com/chart?cht=tx&chl=p "p").

Our algorithm is as follows:

    knapsack_dp(S[] s, P[] p, B):
        p_max = max(P)
        sums = [n][p_max];
        for p = [1, p_max]:
            if (p == p[1]):
                sums[1][p] = p[1]
            else:
                sums[1][p] = infinity
        for i = [2, n]:
            for p = [1, p_max]:
                sums[i][p] = min(sums[i-1][p], sums[i-1][p-p[i]] + s[i])
        return max p such that sums[n][p] <= B
                    

The runtime of this is ![O(n
\\verb|p\_max|)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Cverb%7Cp_max%7C%29 "O(n \verb|p_max|)"),
which is ![O(n\^2
\\max\_i(p\_i))](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E2%20%5Cmax_i%28p_i%29%29 "O(n^2 \max_i(p_i))").

This algorithm is pseudo-polynomial time, since the runtime depends on
the largest
![p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i "p_i"), not on
the size of
![p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i "p_i")’s,
which is
![\\log(p\_i)](http://chart.apis.google.com/chart?cht=tx&chl=%5Clog%28p_i%29 "\log(p_i)")
bits.

Some NP-completeproblems don’t have pseudo-polynomial time algorithms
(unless ![{\\textsc{P}\\xspace}=
{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}= {\textsc{NP}\xspace}")).
For example, tsp is still NP-completewith
![0-1](http://chart.apis.google.com/chart?cht=tx&chl=0-1 "0-1") weights,
since it still can be reduced to the Hamiltonian cycle problem.

FPTAS for the Knapsack Problem {#sec:fptas_for_the_knapsack_problem}
------------------------------

The idea is that if
![p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i "p_i") is few
bits, then the pseudo-polynomial time algorithm runs in polynomial time
![O(n\^2 \\max\_i
(p\_i))](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E2%20%5Cmax_i%20%28p_i%29%29 "O(n^2 \max_i (p_i))").
So let’s round
![p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i "p_i")’s to
have few bits.

Run the following algorithm for a value of
![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t"):

    knapsack_fptas(epsilon, S[] s, P[] p_initial, B):
        t = ...
        P[] p = new P[p_initial.length]
        for i = [0, p_initial.length]:
            p[i] = floor(p_initial[i]/t)
        return knapsack_dp(s, p, B)
                    

Suppose the result returns ![K(t) \\subseteq [1,
n]](http://chart.apis.google.com/chart?cht=tx&chl=K%28t%29%20%5Csubseteq%20%5B1%2C%20n%5D "K(t) \subseteq [1, n]").
![K(t)](http://chart.apis.google.com/chart?cht=tx&chl=K%28t%29 "K(t)")
is feasible, since ![\\sum\_{i \\in K(t)} s\_i \\le
B](http://chart.apis.google.com/chart?cht=tx&chl=%5Csum_%7Bi%20%5Cin%20K%28t%29%7D%20s_i%20%5Cle%20B "\sum_{i \in K(t)} s_i \le B").

We need to analyze ![P(K(t)) = \\sum\_{i \\in K(t)}
p\_i](http://chart.apis.google.com/chart?cht=tx&chl=P%28K%28t%29%29%20%3D%20%5Csum_%7Bi%20%5Cin%20K%28t%29%7D%20p_i "P(K(t)) = \sum_{i \in K(t)} p_i")
compared to ![P(K\^\*) =
{\\textsc{opt}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=P%28K%5E%2A%29%20%3D%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D "P(K^*) = {\textsc{opt}\xspace}").

We know that ![p\_i - t \< tp'\_i \\le
p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i%20-%20t%20%3C%20tp%27_i%20%5Cle%20p_i "p_i - t < tp'_i \le p_i").
Then we have:

\
![\\begin{aligned} \\sum\_{i \\in K(t)} p\_i &\\ge \\sum\_{i \\in K(t)}
tp'\_i \\\\ &\\ge \\sum\_{i \\in K\^\*} tp'\_i \\\\ &\\ge \\sum\_{i \\in
K\^\*}(p\_i - t) \\\\ &= \\sum\_{i \\in K\^\*}p\_i - t|K\^\*| \\\\ &\\ge
{\\textsc{opt}\\xspace}- t|K\^\*| \\\\ &\\ge {\\textsc{opt}\\xspace}- tn
\\\\ &= {\\textsc{opt}\\xspace}\\left(1 -
\\frac{tn}{{\\textsc{opt}\\xspace}}\\right) \\\\ &\\ge
{\\textsc{opt}\\xspace}\\left( 1 - \\frac{tn}{\\max\_i (p\_i)} \\right)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Csum_%7Bi%20%5Cin%20K%28t%29%7D%20p_i%20%26%5Cge%20%5Csum_%7Bi%20%5Cin%20K%28t%29%7D%20tp%27_i%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20%5Csum_%7Bi%20%5Cin%20K%5E%2A%7D%20tp%27_i%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20%5Csum_%7Bi%20%5Cin%20K%5E%2A%7D%28p_i%20-%20t%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_%7Bi%20%5Cin%20K%5E%2A%7Dp_i%20-%20t%7CK%5E%2A%7C%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D-%20t%7CK%5E%2A%7C%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D-%20tn%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%5Cleft%281%20-%20%5Cfrac%7Btn%7D%7B%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%7D%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%5Cleft%28%201%20-%20%5Cfrac%7Btn%7D%7B%5Cmax_i%20%28p_i%29%7D%20%5Cright%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \sum_{i \in K(t)} p_i &\ge \sum_{i \in K(t)} tp'_i \\
                    &\ge \sum_{i \in K^*} tp'_i \\
                    &\ge \sum_{i \in K^*}(p_i - t) \\
                    &= \sum_{i \in K^*}p_i - t|K^*| \\
                    &\ge {\textsc{opt}\xspace}- t|K^*| \\
                    &\ge {\textsc{opt}\xspace}- tn \\
                    &= {\textsc{opt}\xspace}\left(1 - \frac{tn}{{\textsc{opt}\xspace}}\right) \\
                    &\ge {\textsc{opt}\xspace}\left( 1 - \frac{tn}{\max_i (p_i)} \right)
                \end{aligned}")\

We want ![\\ge {\\textsc{opt}\\xspace}(1 -
\\varepsilon)](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%281%20-%20%5Cvarepsilon%29 "\ge {\textsc{opt}\xspace}(1 - \varepsilon)"),
so we choose ![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t")
such that ![\\varepsilon = \\frac{tn}{\\max\_i
(p\_i)}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cvarepsilon%20%3D%20%5Cfrac%7Btn%7D%7B%5Cmax_i%20%28p_i%29%7D "\varepsilon = \frac{tn}{\max_i (p_i)}"),
and ![t = \\frac{\\varepsilon \\max\_i
p\_i}{n}](http://chart.apis.google.com/chart?cht=tx&chl=t%20%3D%20%5Cfrac%7B%5Cvarepsilon%20%5Cmax_i%20p_i%7D%7Bn%7D "t = \frac{\varepsilon \max_i p_i}{n}").

The runtime is in ![O(n\^2 \\max\_i
(p'\_i))](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E2%20%5Cmax_i%20%28p%27_i%29%29 "O(n^2 \max_i (p'_i))").
We know that:

\
![\\begin{aligned} p'\_i &= {\\left \\lfloor \\frac{p\_i}{t} \\right
\\rfloor } \\\\ &= {\\left \\lfloor \\frac{n p\_i}{\\varepsilon \\max\_i
(p\_i)} \\right \\rfloor } \\\\ &\\le \\frac{n}{\\varepsilon}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20p%27_i%20%26%3D%20%7B%5Cleft%20%5Clfloor%20%5Cfrac%7Bp_i%7D%7Bt%7D%20%5Cright%20%5Crfloor%20%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%7B%5Cleft%20%5Clfloor%20%20%5Cfrac%7Bn%20p_i%7D%7B%5Cvarepsilon%20%5Cmax_i%20%28p_i%29%7D%20%5Cright%20%5Crfloor%20%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%20%5Cfrac%7Bn%7D%7B%5Cvarepsilon%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    p'_i &= {\left \lfloor \frac{p_i}{t} \right \rfloor } \\
                    &= {\left \lfloor  \frac{n p_i}{\varepsilon \max_i (p_i)} \right \rfloor } \\
                    &\le \frac{n}{\varepsilon}
                \end{aligned}")\

Thus, the runtime is ![O(n\^3
\\frac{1}{\\varepsilon})](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E3%20%5Cfrac%7B1%7D%7B%5Cvarepsilon%7D%29 "O(n^3 \frac{1}{\varepsilon})"),
which means it’s a FPTAS.

### Comments on the State-of-the-Art {#sub:comments_on_the_state_of_the_art}

The best known algorithm has the runtime ![O(n \\log
\\frac{1}{\\varepsilon} + \\left( \\frac{1}{\\varepsilon}
\\right)\^4)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Clog%20%5Cfrac%7B1%7D%7B%5Cvarepsilon%7D%20%2B%20%5Cleft%28%20%5Cfrac%7B1%7D%7B%5Cvarepsilon%7D%20%5Cright%29%5E4%29 "O(n \log \frac{1}{\varepsilon} + \left( \frac{1}{\varepsilon} \right)^4)").
The general idea is to separate it into large profit items and small
profit items, then to use the large ones first.

### FPTAS and Pseudo-Polynomial Time Algorithms {#sub:fptas_and_pseudo_polynomial_time_algorithms}

Though we’ve shown that for the knapsack problem, having a
pseudo-polynomial time algorithm
![\\to](http://chart.apis.google.com/chart?cht=tx&chl=%5Cto "\to")
FPTAS, it’s not known (i.e. it’s open) that this is true in general.

Garey & Johnson in \`78 proved that if a problem has a
FPTAS[^70^](#fn70), then there must exist a pseudo-polynomial time
algorithm for the problem.

The idea is that with a minimization problem and a obj function that’s
integer-valued (this is the technical assumption, I’m not sure what it
means), and a bound of ![{\\textsc{opt}\\xspace}\< q
(|I\_\\text{unary}|)](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%3C%20q%20%28%7CI_%5Ctext%7Bunary%7D%7C%29 "{\textsc{opt}\xspace}< q (|I_\text{unary}|)"),
where
![I\_\\text{unary}](http://chart.apis.google.com/chart?cht=tx&chl=I_%5Ctext%7Bunary%7D "I_\text{unary}")
is the input with numbers expressed in unary and
![q](http://chart.apis.google.com/chart?cht=tx&chl=q "q") is some
polynomial.

Suppose our algorithm
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") is a FPTAS
with runtime ![p(|I|,
\\frac{1}{\\varepsilon})](http://chart.apis.google.com/chart?cht=tx&chl=p%28%7CI%7C%2C%20%5Cfrac%7B1%7D%7B%5Cvarepsilon%7D%29 "p(|I|, \frac{1}{\varepsilon})")
and ![A(I) \\le (1 + \\varepsilon)
{\\textsc{opt}\\xspace}(I)](http://chart.apis.google.com/chart?cht=tx&chl=A%28I%29%20%5Cle%20%281%20%2B%20%5Cvarepsilon%29%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28I%29 "A(I) \le (1 + \varepsilon) {\textsc{opt}\xspace}(I)").

Picking that
![\\varepsilon](http://chart.apis.google.com/chart?cht=tx&chl=%5Cvarepsilon "\varepsilon")
small enough to get the opt, we can argue that this is
pseudo-polynomial.

\
![\\begin{aligned} \\varepsilon &= \\frac{1}{q(|I\_\\text{unary}|)} \\\\
A(I) &\\le (1 + \\varepsilon){\\textsc{opt}\\xspace}(I) \\\\ &\<
{\\textsc{opt}\\xspace}(I) + 1
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cvarepsilon%20%26%3D%20%5Cfrac%7B1%7D%7Bq%28%7CI_%5Ctext%7Bunary%7D%7C%29%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20A%28I%29%20%26%5Cle%20%281%20%2B%20%5Cvarepsilon%29%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28I%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3C%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28I%29%20%2B%201%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \varepsilon &= \frac{1}{q(|I_\text{unary}|)} \\
                        A(I) &\le (1 + \varepsilon){\textsc{opt}\xspace}(I) \\
                        &< {\textsc{opt}\xspace}(I) + 1
                    \end{aligned}")\

Since our obj function is integer valued, we can make the argument that
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") must give the
optsolution.

Thus, the runtime is ![p(|I|, \\frac{1}{\\varepsilon}) = p(|I|,
q(|I\_\\text{unary}|))](http://chart.apis.google.com/chart?cht=tx&chl=p%28%7CI%7C%2C%20%5Cfrac%7B1%7D%7B%5Cvarepsilon%7D%29%20%3D%20p%28%7CI%7C%2C%20q%28%7CI_%5Ctext%7Bunary%7D%7C%29%29 "p(|I|, \frac{1}{\varepsilon}) = p(|I|, q(|I_\text{unary}|))"),
which is pseudo-polynomial time.

Hardness of Approximation {#cha:hardness_of_approximation}
=========================

In general, some NP-completeproblems can be approximated in different
manners.

Listed from hardest to easiest, we have:

-   ![O(n\^\\varepsilon)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E%5Cvarepsilon%29 "O(n^\varepsilon)")
    - factor

-   ![O(n \\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Clog%20n%29 "O(n \log n)")
    - factor (Set Cover)

-   Constant factor (Vertex Cover, Euclidean TSP)

-   ptas(Packing Unit Squares, Bin Packing)

-   fptas(knapsack)

If the positive results give an approximation algorithm, then negative
results give that it’s hardest.

We can show that a ptasfor vertex cover existing implies that
![{\\textsc{P}\\xspace}=
{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}= {\textsc{NP}\xspace}").

For the Max-3SAT problem, we know through reductions that a ptasfor
either vertex cover or Independent Set implies that there must be a
ptasfor Max-3SAT, since there are reductions preserving good
approximations.

A New Definition of NP {#sec:a_new_definition_of_np}
----------------------

Earlier, we defined NPas a set of decision problems verifiable in Pgiven
a certificate of polynomial size.

If we think about this as a game between the prover
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") (who finds the
certificate) and the verifier
![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V") (verifies the
problem), then we can get some edge by talking about how much
![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V") asks
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") and how much
![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V") guesses
randomly.

An interactive proof system is essentially what we’re building.
![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V") asks
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") about parts of
the proof, and guesses[^71^](#fn71) some others.

### Graph Isomorphism {#sub:graph_isomorphism}

> Given 2 graphs
> ![G\_1](http://chart.apis.google.com/chart?cht=tx&chl=G_1 "G_1") and
> ![G\_2](http://chart.apis.google.com/chart?cht=tx&chl=G_2 "G_2"), can
> you relabel
> ![G\_1](http://chart.apis.google.com/chart?cht=tx&chl=G_1 "G_1") to
> get ![G\_2](http://chart.apis.google.com/chart?cht=tx&chl=G_2 "G_2")?

Graph isomorphism is in NP, but it is openif it is in Por in
NP-complete.

For the ![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V"), we
can pick one of
![G\_1](http://chart.apis.google.com/chart?cht=tx&chl=G_1 "G_1") or
![G\_2](http://chart.apis.google.com/chart?cht=tx&chl=G_2 "G_2") at
random, and ask
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") about which
one we relabeled.

-   If ![G\_1 \\not=
    G\_2](http://chart.apis.google.com/chart?cht=tx&chl=G_1%20%5Cnot%3D%20G_2 "G_1 \not= G_2"),
    then the prover can answer correctly.

-   If ![G\_1 =
    G\_2](http://chart.apis.google.com/chart?cht=tx&chl=G_1%20%3D%20G_2 "G_1 = G_2"),
    then the prover can’t do better than 50% right.

Thus ![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V") runs many
trials to verify ![G\_1 \\not=
G\_2](http://chart.apis.google.com/chart?cht=tx&chl=G_1%20%5Cnot%3D%20G_2 "G_1 \not= G_2")
with high probability.

This is a restricted instance, since there are no rounds and only one
prover[^72^](#fn72).

### Probabilistically Checkable Proofs {#sub:probabilistically_checkable_proofs}

Given a result to a decision problem, we have a game between the Prover
and Verifier.

-   Prover writes the “proof”.

-   The Verifier is a randomized algorithm that “checks” the proof and
    answers yes or no.

If the statement is true, then there is (always?) a proof that makes
![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V") (always?)
answer yes.

If the statement is false, then
![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V") must answer no
with ![\\text{Pr} \\ge
\\frac{3}{4}](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctext%7BPr%7D%20%5Cge%20%5Cfrac%7B3%7D%7B4%7D "\text{Pr} \ge \frac{3}{4}"),
no matter the proof given.

If we limit ![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V") to
![O(f(n))](http://chart.apis.google.com/chart?cht=tx&chl=O%28f%28n%29%29 "O(f(n))")
random bits, and
![O(g(n))](http://chart.apis.google.com/chart?cht=tx&chl=O%28g%28n%29%29 "O(g(n))"),
then we define pcp as follows:

> ![\\textsc{pcp}[f,
> g]](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctextsc%7Bpcp%7D%5Bf%2C%20g%5D "\textsc{pcp}[f, g]")
> is the class of decision problems with Probabilistically Checkable
> Proof where ![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V")
> uses
> ![O(f(n))](http://chart.apis.google.com/chart?cht=tx&chl=O%28f%28n%29%29 "O(f(n))")
> random bits, and
> ![O(g(n))](http://chart.apis.google.com/chart?cht=tx&chl=O%28g%28n%29%29 "O(g(n))")
> bits of the proof.

We have ![\\textsc{pcp}[0, \\text{poly}(n)] =
{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctextsc%7Bpcp%7D%5B0%2C%20%5Ctext%7Bpoly%7D%28n%29%5D%20%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "\textsc{pcp}[0, \text{poly}(n)] = {\textsc{NP}\xspace}"),
and ![\\textsc{pcp}[0, 0] =
{\\textsc{P}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctextsc%7Bpcp%7D%5B0%2C%200%5D%20%3D%20%7B%5Ctextsc%7BP%7D%5Cxspace%7D "\textsc{pcp}[0, 0] = {\textsc{P}\xspace}").

### PCP Theorem {#sub:pcp_theorem}

The “PCP Theorem” is by (Aurora, Lund, Motwani, Sudan, and Szegedy in
\`92). It states that:

\
![\\begin{aligned} {\\textsc{NP}\\xspace}&= \\textsc{pcp}[\\log n, 1].
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D%26%3D%20%5Ctextsc%7Bpcp%7D%5B%5Clog%20n%2C%201%5D.%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        {\textsc{NP}\xspace}&= \textsc{pcp}[\log n, 1].
                    \end{aligned}")\

Essentially, ![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V")
uses to choose to look at the proof.

Proving ![\\textsc{pcp}[\\log n, 1] \\subseteq {\\textsc{NP}\\xspace}=
\\textsc{pcp}[0,
\\text{poly}(n)]](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctextsc%7Bpcp%7D%5B%5Clog%20n%2C%201%5D%20%5Csubseteq%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D%3D%20%5Ctextsc%7Bpcp%7D%5B0%2C%20%5Ctext%7Bpoly%7D%28n%29%5D "\textsc{pcp}[\log n, 1] \subseteq {\textsc{NP}\xspace}= \textsc{pcp}[0, \text{poly}(n)]")
is not hard, since the verifier only needs to eliminate randomness and
tries all possible random strings of ![O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20n%29 "O(\log n)")
bits. It then looks at
![n\^k](http://chart.apis.google.com/chart?cht=tx&chl=n%5Ek "n^k") bits
of the proof.

The other direction is hard.

### Implications of the PCP Theorem to Hardness of Approximation {#sub:implications_of_the_pcp_theorem_to_hardness_of_approximation}

From the pcp theorem, we know that a ptasfor Max 3-SAT implies that
![{\\textsc{P}\\xspace}=
{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}= {\textsc{NP}\xspace}").

Using ![{\\textsc{NP}\\xspace}= \\textsc{pcp}[\\log n,
1]](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BNP%7D%5Cxspace%7D%3D%20%5Ctextsc%7Bpcp%7D%5B%5Clog%20n%2C%201%5D "{\textsc{NP}\xspace}= \textsc{pcp}[\log n, 1]"),
we can take any problem in
![{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{NP}\xspace}")
and the ![\\textsc{pcp}[\\log n,
1]](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctextsc%7Bpcp%7D%5B%5Clog%20n%2C%201%5D "\textsc{pcp}[\log n, 1]")
verifier’s algorithm for it.

The algorithm depends on the input bits ![x\_1, \\ldots,
x\_n](http://chart.apis.google.com/chart?cht=tx&chl=x_1%2C%20%5Cldots%2C%20x_n "x_1, \ldots, x_n"),
the proof bits ![y\_1, \\ldots,
y\_t](http://chart.apis.google.com/chart?cht=tx&chl=y_1%2C%20%5Cldots%2C%20y_t "y_1, \ldots, y_t")
(for ![t \\in
O(\\text{poly}(n))](http://chart.apis.google.com/chart?cht=tx&chl=t%20%5Cin%20O%28%5Ctext%7Bpoly%7D%28n%29%29 "t \in O(\text{poly}(n))")),
and the random bits ![r\_1, \\ldots,
r\_k](http://chart.apis.google.com/chart?cht=tx&chl=r_1%2C%20%5Cldots%2C%20r_k "r_1, \ldots, r_k")
(for ![k \\in O(\\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=k%20%5Cin%20O%28%5Clog%20n%29 "k \in O(\log n)")).

We can reduce any[^73^](#fn73) algorithm to a Boolean 3-SAT formula.

Using variables for ![y\_1, \\ldots,
y\_t](http://chart.apis.google.com/chart?cht=tx&chl=y_1%2C%20%5Cldots%2C%20y_t "y_1, \ldots, y_t"),
we can choose the formula ![F(x, y,
r)](http://chart.apis.google.com/chart?cht=tx&chl=F%28x%2C%20y%2C%20r%29 "F(x, y, r)")
to capture the verifier’s algorithm.

Let ![F(x, y) = \\land\_{r} F(x, y,
r)](http://chart.apis.google.com/chart?cht=tx&chl=F%28x%2C%20y%29%20%3D%20%5Cland_%7Br%7D%20F%28x%2C%20y%2C%20r%29 "F(x, y) = \land_{r} F(x, y, r)").

Since ![r](http://chart.apis.google.com/chart?cht=tx&chl=r "r") is
polynomial size, we can say the following:

-   if ![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x") is yes
    input, then there exists a
    ![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y") such that
    all ![F(x, y,
    x)](http://chart.apis.google.com/chart?cht=tx&chl=F%28x%2C%20y%2C%20x%29 "F(x, y, x)")
    are satisfied and thus ![F(x,
    y)](http://chart.apis.google.com/chart?cht=tx&chl=F%28x%2C%20y%29 "F(x, y)")
    is satisfied.

-   if ![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x") is no
    input, then for any
    ![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y"), at most
    ![\\frac{1}{4}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B4%7D "\frac{1}{4}")
    of the ![F(x, y,
    x)](http://chart.apis.google.com/chart?cht=tx&chl=F%28x%2C%20y%2C%20x%29 "F(x, y, x)")
    are satisfied, and at most a fraction of the clauses of ![F(x,
    y)](http://chart.apis.google.com/chart?cht=tx&chl=F%28x%2C%20y%29 "F(x, y)")
    can be satisfied.

By having a gap when
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x") is a no input
between optand “all”, we can detect this gap with a good approximation
algorithm.

Online Algorithms {#cha:online_algorithms}
=================

Given a sequence of requests, our algorithm must handle each request as
it comes. This is the usual scenario for data structures, but we will
study situations where it makes sense to compare with complete
solutions.

-   Bin packing: (first vs best fit)

-   Splay Trees - dynamic optimality conjecture

-   Paging (LRU and LFU)

-   Ski rental - rental is \$30, but purchasing skiis is \$300.

Robots Finding Doors {#sec:robots_finding_doors}
--------------------

Suppose we have a robot an unknown distance
![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d") away from a
door in an unknown direction.

In an optroute, we can provide a solution in length
![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d").

### Algorithm 0 {#sub:algorithm_0}

    find_door_0():
        i = 0
        while (true):
            i++
            go i steps right
            go 2i steps left
            go i steps right
            if seen_door():
                goto door
                        

This takes ![4(\\sum\_i\^{d-1}) +
d](http://chart.apis.google.com/chart?cht=tx&chl=4%28%5Csum_i%5E%7Bd-1%7D%29%20%2B%20d "4(\sum_i^{d-1}) + d")
steps if the door is on the right, and ![4(\\sum\_i\^{d-1}) +
3d](http://chart.apis.google.com/chart?cht=tx&chl=4%28%5Csum_i%5E%7Bd-1%7D%29%20%2B%203d "4(\sum_i^{d-1}) + 3d")
steps if the door is on the left, so this runs in
![\\theta(d\^2)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta%28d%5E2%29 "\theta(d^2)")
time.

### Algorithm 1 {#sub:algorithm_1}

    find_door_1():
        i=0
        while (true):
            i++
            if i is odd:
                go 2^i steps right
                go 2^i steps left
            else: // (i is even)
                go 2^i steps left
                go 2^i steps right
                        

If ![2\^i \\le d \\le
2\^{i+1}](http://chart.apis.google.com/chart?cht=tx&chl=2%5Ei%20%5Cle%20d%20%5Cle%202%5E%7Bi%2B1%7D "2^i \le d \le 2^{i+1}"),
then the distance travelled is ![\\le 2\\sum\_j\^{i+1} j\^2 +
d](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%202%5Csum_j%5E%7Bi%2B1%7D%20j%5E2%20%2B%20d "\le 2\sum_j^{i+1} j^2 + d").
Thus the distance travelled ![\\le 2 (2\^{i+2} - 1) + d \\le 2 (4d + 1)
+ d \\le
9d](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%202%20%282%5E%7Bi%2B2%7D%20-%201%29%20%2B%20d%20%5Cle%202%20%284d%20%2B%201%29%20%2B%20d%20%5Cle%209d "\le 2 (2^{i+2} - 1) + d \le 2 (4d + 1) + d \le 9d").

Since we know the distance travelled is
![9d](http://chart.apis.google.com/chart?cht=tx&chl=9d "9d"), then we
have what we call a competitive ratio of
![9](http://chart.apis.google.com/chart?cht=tx&chl=9 "9").

### Algorithm 2 {#sub:algorithm_2}

This is a randomized version of the algorithm.

Flip a coin to choose th initial direction - ![f \\in \\{0,
1\\}](http://chart.apis.google.com/chart?cht=tx&chl=f%20%5Cin%20%5C%7B0%2C%201%5C%7D "f \in \{0, 1\}").

Then we do the algorithm described in Section [sub:algorithm~1~]. The
odd/even test becomes ![i \\mod 2 =
f](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cmod%202%20%3D%20f "i \mod 2 = f"),
and we now get to see the expected distance travelled:

\
![\\begin{aligned} 2(\\sum\_j 2\^j) + \\frac{1}{2} 2(2\^{i+1}) + d \\\\
&= 2(2\^{i+1} - 1) + 2(2\^{i+1}) + d \\\\ &\\le 2(2d - 1) + 2d + d \\\\
&\\le 7d
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%202%28%5Csum_j%202%5Ej%29%20%2B%20%5Cfrac%7B1%7D%7B2%7D%202%282%5E%7Bi%2B1%7D%29%20%2B%20d%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%202%282%5E%7Bi%2B1%7D%20-%201%29%20%2B%202%282%5E%7Bi%2B1%7D%29%20%2B%20d%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%202%282d%20-%201%29%20%2B%202d%20%2B%20d%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cle%207d%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        2(\sum_j 2^j) + \frac{1}{2} 2(2^{i+1}) + d \\
                        &= 2(2^{i+1} - 1) + 2(2^{i+1}) + d \\
                        &\le 2(2d - 1) + 2d + d \\
                        &\le 7d
                    \end{aligned}")\

We have a competitive ratio of
![7](http://chart.apis.google.com/chart?cht=tx&chl=7 "7") in this case.

### Algorithm 3 {#sub:algorithm_3}

The best randomized algorithm has a competitive ratio of
![4.592](http://chart.apis.google.com/chart?cht=tx&chl=4.592 "4.592").
Let’s take a look at it.

For a value of ![r](http://chart.apis.google.com/chart?cht=tx&chl=r "r")
chosen below, do the following algorithm:

    find_door_3():
        f = random_bit()
        x = random_float(0, 1)
        i = 0
        while (true):
            if i %2 = f:
                walk r^{i+x} right
                walk r^{i-x} left
            else:
                walk r^{i+x} left
                walk r^{i-x} right
            ++i
                        

It can be shown that the expected distance travelled ![\\le
\\frac{r+1}{\\ln r} +
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%5Cfrac%7Br%2B1%7D%7B%5Cln%20r%7D%20%2B%201 "\le \frac{r+1}{\ln r} + 1"),
which is minimized when ![r =
3.59](http://chart.apis.google.com/chart?cht=tx&chl=r%20%3D%203.59 "r = 3.59"),
giving the distance
![4.59d](http://chart.apis.google.com/chart?cht=tx&chl=4.59d "4.59d").

This is the best known approximation factor.

### Further Expansion {#sub:further_expansion}

This becomes harder in 2D, as a robot is trying to find an unknown shape
in a plane.

Auction Strategies {#sec:auction_strategies}
------------------

There is an item of value
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B"), and the
auction bids occur one at a time. These bids are more like offers, since
the algorithm must accept or reject bids immediately as they arrive. All
bids are positive nonzero integers.

We want ![A(\\sigma) \\ge c {\\textsc{opt}\\xspace}(\\sigma) +
b](http://chart.apis.google.com/chart?cht=tx&chl=A%28%5Csigma%29%20%5Cge%20c%20%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28%5Csigma%29%20%2B%20b "A(\sigma) \ge c {\textsc{opt}\xspace}(\sigma) + b"),
where ![c \\le
1](http://chart.apis.google.com/chart?cht=tx&chl=c%20%5Cle%201 "c \le 1").

If the number of bids is unknown, then the algorithm must accept the
first bid, or else ![\\frac{A}{{\\textsc{opt}\\xspace}} =
0](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7BA%7D%7B%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%7D%20%3D%200 "\frac{A}{{\textsc{opt}\xspace}} = 0").

Supposing the number of bids is known, the algorithm accepts the first
bid above some threshold
![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T"), otherwise it
accepts the last bid.

Supposing the maximum bid is ![M \\le
B](http://chart.apis.google.com/chart?cht=tx&chl=M%20%5Cle%20B "M \le B"),
then ![{\\textsc{opt}\\xspace}=
M](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%3D%20M "{\textsc{opt}\xspace}= M").

If ![T =
2](http://chart.apis.google.com/chart?cht=tx&chl=T%20%3D%202 "T = 2")
and ![M \\ge
2](http://chart.apis.google.com/chart?cht=tx&chl=M%20%5Cge%202 "M \ge 2"),
![\\frac{2}{M} \\ge
\\frac{2}{B}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B2%7D%7BM%7D%20%5Cge%20%5Cfrac%7B2%7D%7BB%7D "\frac{2}{M} \ge \frac{2}{B}").
If ![T =
1](http://chart.apis.google.com/chart?cht=tx&chl=T%20%3D%201 "T = 1")
and ![M =
1](http://chart.apis.google.com/chart?cht=tx&chl=M%20%3D%201 "M = 1"),
then ![\\frac{1}{1} =
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B1%7D%20%3D%201 "\frac{1}{1} = 1").
It’s best to have the highest
![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") possible.

### Deterministic ![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") Threshold {#sub:t_threshold}

If we set ![T = {\\left \\lfloor \\sqrt{B} \\right \\rfloor
}](http://chart.apis.google.com/chart?cht=tx&chl=T%20%3D%20%7B%5Cleft%20%5Clfloor%20%5Csqrt%7BB%7D%20%5Cright%20%5Crfloor%20%7D "T = {\left \lfloor \sqrt{B} \right \rfloor }"),
we claim that the competitive ratio is
![\\frac{1}{\\sqrt{B}}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B%5Csqrt%7BB%7D%7D "\frac{1}{\sqrt{B}}").

If ![M\> {\\left \\lfloor \\sqrt{B} \\right \\rfloor
}](http://chart.apis.google.com/chart?cht=tx&chl=M%3E%20%7B%5Cleft%20%5Clfloor%20%5Csqrt%7BB%7D%20%5Cright%20%5Crfloor%20%7D "M> {\left \lfloor \sqrt{B} \right \rfloor }"),
then in the worst case
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") accepts
![{\\left \\lfloor \\sqrt{B} \\right \\rfloor } +
1](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Cleft%20%5Clfloor%20%5Csqrt%7BB%7D%20%5Cright%20%5Crfloor%20%7D%20%2B%201 "{\left \lfloor \sqrt{B} \right \rfloor } + 1").
The competitive ratio is ![\\frac{{\\left \\lfloor \\sqrt{B} \\right
\\rfloor } + 1}{M} \\ge \\frac{{\\left \\lfloor \\sqrt{B} \\right
\\rfloor } + 1}{B} \\ge
\\frac{1}{\\sqrt{B}}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B%7B%5Cleft%20%5Clfloor%20%5Csqrt%7BB%7D%20%5Cright%20%5Crfloor%20%7D%20%2B%201%7D%7BM%7D%20%5Cge%20%5Cfrac%7B%7B%5Cleft%20%5Clfloor%20%5Csqrt%7BB%7D%20%5Cright%20%5Crfloor%20%7D%20%2B%201%7D%7BB%7D%20%5Cge%20%5Cfrac%7B1%7D%7B%5Csqrt%7BB%7D%7D "\frac{{\left \lfloor \sqrt{B} \right \rfloor } + 1}{M} \ge \frac{{\left \lfloor \sqrt{B} \right \rfloor } + 1}{B} \ge \frac{1}{\sqrt{B}}").

If ![M \\le {\\left \\lfloor \\sqrt{B} \\right \\rfloor
}](http://chart.apis.google.com/chart?cht=tx&chl=M%20%5Cle%20%7B%5Cleft%20%5Clfloor%20%5Csqrt%7BB%7D%20%5Cright%20%5Crfloor%20%7D "M \le {\left \lfloor \sqrt{B} \right \rfloor }"),
then the algorithm accepts the last bid. In the worst case, that bid is
![1](http://chart.apis.google.com/chart?cht=tx&chl=1 "1"), so the
competive ratio is
![\\frac{1}{\\sqrt{B}}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B%5Csqrt%7BB%7D%7D "\frac{1}{\sqrt{B}}").

In either case, the competitive ratio is
![\\frac{1}{\\sqrt{B}}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B%5Csqrt%7BB%7D%7D "\frac{1}{\sqrt{B}}").

### Random ![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") Threshold {#sub:random_threshold}

Choose a random
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i") threshold from
![i \\in [i, \\log
B]](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cin%20%5Bi%2C%20%5Clog%20B%5D "i \in [i, \log B]"),
then set ![T =
2\^i](http://chart.apis.google.com/chart?cht=tx&chl=T%20%3D%202%5Ei "T = 2^i").

The worst case is that no bid is occurs ![\\ge
2\^i](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%202%5Ei "\ge 2^i"),
so ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") gets
![0](http://chart.apis.google.com/chart?cht=tx&chl=0 "0").

We want to prove the expected competitive ratio is ![\\ge O\\left(
\\frac{1}{\\log b}
\\right)](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20O%5Cleft%28%20%5Cfrac%7B1%7D%7B%5Clog%20b%7D%20%5Cright%29 "\ge O\left( \frac{1}{\log b} \right)").

Suppose that ![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M")
is the max bid, so ![{\\textsc{opt}\\xspace}=
M](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%3D%20M "{\textsc{opt}\xspace}= M").

Suppose that ![2\^k \\le M \<
2\^{k+1}](http://chart.apis.google.com/chart?cht=tx&chl=2%5Ek%20%5Cle%20M%20%3C%202%5E%7Bk%2B1%7D "2^k \le M < 2^{k+1}").
The probability that we choose
![i=k](http://chart.apis.google.com/chart?cht=tx&chl=i%3Dk "i=k") is
![\\frac{1}{\\log
B}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B%5Clog%20B%7D "\frac{1}{\log B}").

For ![i =
k](http://chart.apis.google.com/chart?cht=tx&chl=i%20%3D%20k "i = k"),
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") gets ![\\ge
2\^k \\ge
\\frac{M}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%202%5Ek%20%5Cge%20%5Cfrac%7BM%7D%7B2%7D "\ge 2^k \ge \frac{M}{2}").

Thus the expected value for the algorithm is ![\\ge \\frac{M}{2 \\log
B}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20%5Cfrac%7BM%7D%7B2%20%5Clog%20B%7D "\ge \frac{M}{2 \log B}").
Then, ![\\frac{A}{{\\textsc{opt}\\xspace}} \\ge \\frac{1}{2 \\log
B}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7BA%7D%7B%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%7D%20%5Cge%20%5Cfrac%7B1%7D%7B2%20%5Clog%20B%7D "\frac{A}{{\textsc{opt}\xspace}} \ge \frac{1}{2 \log B}").

Paging {#cha:paging}
======

An online algorithm is
![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c")-competitive if
there exists a constant
![b](http://chart.apis.google.com/chart?cht=tx&chl=b "b") such that
![A(\\sigma) \\le c{\\textsc{opt}\\xspace}(\\sigma) +
b](http://chart.apis.google.com/chart?cht=tx&chl=A%28%5Csigma%29%20%5Cle%20c%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%28%5Csigma%29%20%2B%20b "A(\sigma) \le c{\textsc{opt}\xspace}(\sigma) + b").

We define the paging problem as follows:

> We are given a “cache” of fast memory that holds
> ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") elements,
> and a “disk” of slow memory that holds ![n \>\>
> k](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3E%3E%20k "n >> k")
> pages.
>
> When a page is requested, if it’s in the cache, we have no problem.
>
> Otherwise, we “page fault” and read the page into the cache at a cost
> of 1, evicting at least one page to do it.
>
> We’d like to choose a page eviction strategy with a minimal cost.

Optimum Offline Strategy {#sec:optimum_offline_strategy}
------------------------

The optimum strategy is to evict the page with the next request furthest
in the future. The proof is done from the observation that we can modify
any optimum solution to this one, decision by decision.

Online Cache Strategies {#sec:online_cache_strategies}
-----------------------

FIFO
:   - first in first out

LRU
:   - least recently used

LFU
:   - least frequently used

### LRU vs FIFO {#sub:lru_vs_fifo}

Despite LRU being better than FIFO in practice, both LRU and FIFO have
competitive ratio
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k").

We can prove this by dividing a request sequence into phases. A phase
stops just before the
![k+1](http://chart.apis.google.com/chart?cht=tx&chl=k%2B1 "k+1")th
different page is requested.

The algorithms use ![\\le
k](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20k "\le k")
swaps per page, since LRU and FIFO will not evict a page used in that
single phase. We know that optmust evict ![\\ge
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%201 "\ge 1") page
per phase, because there are
![k+1](http://chart.apis.google.com/chart?cht=tx&chl=k%2B1 "k+1")
distinct pages involved. Thus, we have
![\\frac{A}{{\\textsc{opt}\\xspace}} \\le
k](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7BA%7D%7B%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%7D%20%5Cle%20k "\frac{A}{{\textsc{opt}\xspace}} \le k"),
plus an additive constant for a partial phase at an end of a request
sequence.

### Limitations of Deterministic Selection {#sub:limitations_of_deterministic_selection}

We’d like to prove that any deterministic algorithm has competitive
ratio ![\\ge
k](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20k "\ge k").

If ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") is the
cache size, and the number of pages is
![k+1](http://chart.apis.google.com/chart?cht=tx&chl=k%2B1 "k+1"), and
the adversary can always supply a sequence of length
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") asking for the
page known not to be in the cache.

Since there are
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") swaps in a
sequence of length
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"), and we know
that a perfect solution subjected to this adversary would use
![\\frac{n}{k}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7Bn%7D%7Bk%7D "\frac{n}{k}")
swaps, because each time it evicts, it must be good for the next
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") requests.

Then we have ![\\frac{A}{{\\textsc{opt}\\xspace}} \\ge
k](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7BA%7D%7B%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%7D%20%5Cge%20k "\frac{A}{{\textsc{opt}\xspace}} \ge k")
for all deterministic algorithms.

### Randomized Page Swapping Algorithm {#sub:randomized_page_swapping_algorithm}

This randomized algorithm is attributed to Fiat in \`91.

    serve(p):
        p.makeRecent()
        if !cache.contains(p):
            if all pages are recent
                pages.all.makeNotRecent()
            evict a random non-recent page
                        

Without proof, the expected competitive ratio is ![\\Theta(\\log
k)](http://chart.apis.google.com/chart?cht=tx&chl=%5CTheta%28%5Clog%20k%29 "\Theta(\log k)"),
which is the best possible for randomized algorithms, assuming the
adversary does not see the random choices.

![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")-Server Problem {#sec:k_server_problem}
------------------------------------------------------------------------

The problem formulation is as follows:

> There are ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")
> servers to service requests in metric space at points ![\\{p\_1,
> \\ldots,
> p\_n\\}](http://chart.apis.google.com/chart?cht=tx&chl=%5C%7Bp_1%2C%20%5Cldots%2C%20p_n%5C%7D "\{p_1, \ldots, p_n\}").
>
> When a request for
> ![p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i "p_i")
> occurs, if a server is at
> ![p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i "p_i"),
> fine.
>
> Otherwise, move a server from its location
> (![p\_j](http://chart.apis.google.com/chart?cht=tx&chl=p_j "p_j")) to
> ![p\_i](http://chart.apis.google.com/chart?cht=tx&chl=p_i "p_i") at
> cost ![d(p\_j,
> p\_i)](http://chart.apis.google.com/chart?cht=tx&chl=d%28p_j%2C%20p_i%29 "d(p_j, p_i)").
>
> We’d like to serve requests in a given order while minimizing the
> total distance.

Paging is a special case of this algorithm where ![d(p\_i, p\_j) =
1](http://chart.apis.google.com/chart?cht=tx&chl=d%28p_i%2C%20p_j%29%20%3D%201 "d(p_i, p_j) = 1")
for all ![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i"),
![j](http://chart.apis.google.com/chart?cht=tx&chl=j "j").

Without proof, we state that the offline algorithm can solve the problem
in poly-time.

### Greedy Online Algorithm {#sub:greedy_online_algorithm}

Given that all points are in 2D, our heuristic is to move the closest
server to the point.

This unboundedly bad, as a sequence of ![(p\_1, p\_2, p\_1, p\_2,
\\ldots)](http://chart.apis.google.com/chart?cht=tx&chl=%28p_1%2C%20p_2%2C%20p_1%2C%20p_2%2C%20%5Cldots%29 "(p_1, p_2, p_1, p_2, \ldots)")
will take more time than necessary.

It is open[^74^](#fn74) if there is a
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")-competitive
algorithm that solves the problem, in any dimension.

The best known algorithm is
![(2k-1)](http://chart.apis.google.com/chart?cht=tx&chl=%282k-1%29 "(2k-1)")-competitive
(\`94).

### ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")-Competitive Algorithm for Points on a Line {#sub:k_competitive_algorithm_for_points_on_a_line}

For points on a line, we split up requests
![r\_i](http://chart.apis.google.com/chart?cht=tx&chl=r_i "r_i") into
three types:

1.  If ![r\_i](http://chart.apis.google.com/chart?cht=tx&chl=r_i "r_i")
    is to the right of all servers, move the rightmost server right.

2.  If ![r\_i](http://chart.apis.google.com/chart?cht=tx&chl=r_i "r_i")
    is to the left of all servers, move the leftmost server left.

3.  If ![r\_i](http://chart.apis.google.com/chart?cht=tx&chl=r_i "r_i")
    is between two servers
    ![s\_a](http://chart.apis.google.com/chart?cht=tx&chl=s_a "s_a"),
    ![s\_b](http://chart.apis.google.com/chart?cht=tx&chl=s_b "s_b"),
    move them both towards
    ![r\_i](http://chart.apis.google.com/chart?cht=tx&chl=r_i "r_i"),
    stopping both when one reaches the request.

If multiple servers arrive at the same location, break ties arbitrarily.

We present that (without proof) this algorithm is
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")-competitive.

Fixed Parameter Tractable Algorithms I {#cha:fixed_parameter_tractable_algorithms_i}
======================================

We know that NP-completeproblems seem to only have exponential time
algorithms, but we’d like to classify “how exponential” these problems
are.

Completing Problems with Fixed Parameters {#sec:completing_problems_with_fixed_parameters}
-----------------------------------------

When solving the Vertex Cover problem to find ![C \\subseteq
V](http://chart.apis.google.com/chart?cht=tx&chl=C%20%5Csubseteq%20V "C \subseteq V")
such that every edge has at least one end point in
![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C").

Say that ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") is
the minimum size vertex cover, and
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") is known.

We try to find all subsets of
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") vertices ![{n
\\choose k} O(n\^k) = O({n \\choose k} n\^k) = O(k
n\^{k+1})](http://chart.apis.google.com/chart?cht=tx&chl=%7Bn%20%5Cchoose%20k%7D%20O%28n%5Ek%29%20%3D%20O%28%7Bn%20%5Cchoose%20k%7D%20n%5Ek%29%20%3D%20O%28k%20n%5E%7Bk%2B1%7D%29 "{n \choose k} O(n^k) = O({n \choose k} n^k) = O(k n^{k+1})"),
which is polynomial time for constant
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k").

The same idea works for both clique and independent set but not for
graph coloring[^75^](#fn75).

A feel for Fixed Parameter Tractable Algorithms {#sec:a_feel_for_fixed_parameter_tractable_algorithms}
-----------------------------------------------

While
![O(n\^k)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5Ek%29 "O(n^k)")
is not exponential, it’s still pretty bad.

We’d much prefer ![O(f(k)
n\^c)](http://chart.apis.google.com/chart?cht=tx&chl=O%28f%28k%29%20n%5Ec%29 "O(f(k) n^c)")
for some polynomial
![f(k)](http://chart.apis.google.com/chart?cht=tx&chl=f%28k%29 "f(k)")
independent of ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")
and some constant
![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c") independent of
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k"). Even better
would be ![O(f(k) +
n\^c)](http://chart.apis.google.com/chart?cht=tx&chl=O%28f%28k%29%20%2B%20n%5Ec%29 "O(f(k) + n^c)").

### FPTA for Vertex Cover {#sub:fpta_for_vertex_cover}

We want to build a FPTA for Vertex Cover by branching on all
possibilities that for ![e = (u,
v)](http://chart.apis.google.com/chart?cht=tx&chl=e%20%3D%20%28u%2C%20v%29 "e = (u, v)"),
either ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") or
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") is in
![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") (where
![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") is the cover).

At each tree, we pick an uncovered edge to branch on.

    vertex_cover(E, V, k):
        if E == {} return true
        if k == 0 return false
        pick e = E.random()
        (u, v) = e
        return vertex_cover(E.without_incident(u), V-u, k-1)
            || vertex_cover(E.without_incident(v), V-v, k-1)
                        

The tree has depth
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k"), so we take
time ![O(2\^k
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%282%5Ek%20n%29 "O(2^k n)").

By modifying the algorithm, we can trivially find the vertex cover
itself.

### Kernelization {#sub:kernelization}

If we wanted to, we can improve the Vertex Cover technique to ![O(f(k) +
n\^c)](http://chart.apis.google.com/chart?cht=tx&chl=O%28f%28k%29%20%2B%20n%5Ec%29 "O(f(k) + n^c)")
using kernelization.

Essentially, if there exists a vertex
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") with
![\\text{deg}(v) \>
k](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctext%7Bdeg%7D%28v%29%20%3E%20k "\text{deg}(v) > k"),
then ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") must be
in the cover ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C"),
otherwise we’d need all neighbors of
![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") (of which
there are
![\>k](http://chart.apis.google.com/chart?cht=tx&chl=%3Ek ">k")) to be
in ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C").

    vertex_cover_kernelized(E, V, k):
        c_2 = all vertexes with deg(v) > k
        k_2 = k - |C_2|
        V_2 = V - C_2
        E_2 = E.without_any_incident(C_2).remove_isolated()
        if |V_2| > 2k^2
            return false
        return VC(E_2, V_2, k_2)
                        

The actual vertex cover is ![C' \\cup \\textsc{VC}(E', V',
k')](http://chart.apis.google.com/chart?cht=tx&chl=C%27%20%5Ccup%20%5Ctextsc%7BVC%7D%28E%27%2C%20V%27%2C%20k%27%29 "C' \cup \textsc{VC}(E', V', k')")
We know that the maximum degree in
![V'](http://chart.apis.google.com/chart?cht=tx&chl=V%27 "V'") is ![\\le
k](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20k "\le k"). If
![(V',
E')](http://chart.apis.google.com/chart?cht=tx&chl=%28V%27%2C%20E%27%29 "(V', E')")
has a vertex cover of size ![\\le
k](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20k "\le k"),
then ![V'](http://chart.apis.google.com/chart?cht=tx&chl=V%27 "V'") has
![\\le
k\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20k%5E2 "\le k^2")
edges. So ![|E'| \\le
2k\^2](http://chart.apis.google.com/chart?cht=tx&chl=%7CE%27%7C%20%5Cle%202k%5E2 "|E'| \le 2k^2"),
which is not very big.

The idea of kernalization is due to Prof. J. Buss in \`93.

The call to vc takes ![O(2\^k |E'|) = O(2\^k 2
k\^2)](http://chart.apis.google.com/chart?cht=tx&chl=O%282%5Ek%20%7CE%27%7C%29%20%3D%20O%282%5Ek%202%20k%5E2%29 "O(2^k |E'|) = O(2^k 2 k^2)"),
and finding
![C'](http://chart.apis.google.com/chart?cht=tx&chl=C%27 "C'") takes
![O(m +
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%20%2B%20n%29 "O(m + n)")
time. Thus, the total run time is ![O(2\^k k\^2 + m +
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%282%5Ek%20k%5E2%20%2B%20m%20%2B%20n%29 "O(2^k k^2 + m + n)").

Defining Fixed Parameter Tractable Algorithms {#sec:defining_fixed_parameter_tractable_algorithms}
---------------------------------------------

A problem is (FPT) in parameter
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") if it has an
algorithm[^76^](#fn76) with runtime ![O(f(k)
n\^c)](http://chart.apis.google.com/chart?cht=tx&chl=O%28f%28k%29%20n%5Ec%29 "O(f(k) n^c)"),
wher ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is the
input size,
![f(k)](http://chart.apis.google.com/chart?cht=tx&chl=f%28k%29 "f(k)")
is independent of
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"), and
![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c") is a constant
independent of
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k").

Given a FPT problem, we can get an algorithm with runtime ![O(f'(k) +
n\^{c'})](http://chart.apis.google.com/chart?cht=tx&chl=O%28f%27%28k%29%20%2B%20n%5E%7Bc%27%7D%29 "O(f'(k) + n^{c'})").
This is neither deep, indicative on how to construct this, nor useful,
but is interesting.

### Common Parameter Examples {#sub:common_parameter_examples}

We can pick a few types of examples of parameters:

-   Value of the optsolution

-   Maximum degree of the graph

-   Dimension for geometric problems

-   Genus of a graph[^77^](#fn77)

Refer to Chapter 23 for many FPTA examples.

Randomized FPT Algorithm for ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")-Path {#sec:randomized_fpt_algorithm_for_k_path}
-------------------------------------------------------------------------------------------

> Given graph ![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G"),
> ![k \\in
> \\mathbf{N}](http://chart.apis.google.com/chart?cht=tx&chl=k%20%5Cin%20%5Cmathbf%7BN%7D "k \in \mathbf{N}"),
> and a starting vertex
> ![s](http://chart.apis.google.com/chart?cht=tx&chl=s "s") and an end
> vertex ![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t"), find
> a simple[^78^](#fn78) ![s \\to
> t](http://chart.apis.google.com/chart?cht=tx&chl=s%20%5Cto%20t "s \to t")
> path with ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")
> internal vertexes.

In general, this is a NP-hardproblem, since if ![k =
n-2](http://chart.apis.google.com/chart?cht=tx&chl=k%20%3D%20n-2 "k = n-2"),
we’re asking for a Hamiltonian Path ![s \\to
t](http://chart.apis.google.com/chart?cht=tx&chl=s%20%5Cto%20t "s \to t").

With the power of randomness, we can save the day!

Randomly color all vertexes into
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") different
colors. Then look only for paths that use all
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") colors.

The algorithm will always say “no” correctly, since it will never find a
simple ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k")-path
within the coloring.

If there does exist a simple path
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P"), we can say
the following:

\
![\\begin{aligned} \\text{Pr}(\\text{P is colorful}) &= \\frac{k!}{k\^k}
\\\\ &\\ge \\frac{\\left( \\frac{k}{e} \\right)\^k}{k\^k} \\\\ &=
\\frac{1}{e\^k}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7BPr%7D%28%5Ctext%7BP%20is%20colorful%7D%29%20%26%3D%20%5Cfrac%7Bk%21%7D%7Bk%5Ek%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20%5Cfrac%7B%5Cleft%28%20%5Cfrac%7Bk%7D%7Be%7D%20%5Cright%29%5Ek%7D%7Bk%5Ek%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7Be%5Ek%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \text{Pr}(\text{P is colorful}) &= \frac{k!}{k^k} \\
                    &\ge \frac{\left( \frac{k}{e} \right)^k}{k^k} \\
                    &= \frac{1}{e^k}
                \end{aligned}")\

So the algorithm is correct when it says “yes” with a probability ![\\ge
\\frac{1}{e\^k}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20%5Cfrac%7B1%7D%7Be%5Ek%7D "\ge \frac{1}{e^k}").

Defining ![p =
\\frac{1}{e\^k}](http://chart.apis.google.com/chart?cht=tx&chl=p%20%3D%20%5Cfrac%7B1%7D%7Be%5Ek%7D "p = \frac{1}{e^k}"),
then we can say:

Since ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") is
correct with Probability ![\\ge
p](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20p "\ge p"),
then after
![\\frac{1}{p}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7Bp%7D "\frac{1}{p}")
repetitions, the probability of failure is

\
![\\begin{aligned} (1 - p)\^{\\frac{1}{p}} &\< (e\^{-p}) \^ \\frac{1}{p}
\\\\ &= \\frac{1}{e}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%281%20-%20p%29%5E%7B%5Cfrac%7B1%7D%7Bp%7D%7D%20%26%3C%20%28e%5E%7B-p%7D%29%20%5E%20%5Cfrac%7B1%7D%7Bp%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7Be%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    (1 - p)^{\frac{1}{p}} &< (e^{-p}) ^ \frac{1}{p} \\
                    &= \frac{1}{e}
                \end{aligned}")\

In our case, repeating
![e\^k](http://chart.apis.google.com/chart?cht=tx&chl=e%5Ek "e^k") times
gives us the probability of error ![\\le
\\frac{1}{e}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%5Cfrac%7B1%7D%7Be%7D "\le \frac{1}{e}").

Finding a colorful path for a given ordering is easy, so we find all of
them.

The runtime of setting up and searching orderings is ![O(k!
m)](http://chart.apis.google.com/chart?cht=tx&chl=O%28k%21%20m%29 "O(k! m)"),
so the final runtime is ![O(e\^k 2\^k
m)](http://chart.apis.google.com/chart?cht=tx&chl=O%28e%5Ek%202%5Ek%20m%29 "O(e^k 2^k m)"),
with a probability of error of ![\\le
\\frac{1}{e}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20%5Cfrac%7B1%7D%7Be%7D "\le \frac{1}{e}").

Fixed Parameter Tractable Algorithms II {#cha:fixed_parameter_tractable_algorithms_ii}
=======================================

The Independent set problem is expressed as follows:

> Given a graph
> ![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G"), does it
> have an independent set[^79^](#fn79) ![\\ge
> k](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%20k "\ge k")?

The brute-force time is ![O(n\^k
(n+m))](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5Ek%20%28n%2Bm%29%29 "O(n^k (n+m))"),
where there are
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") subsets of
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") vertexes. The
brute-force solution FPT.

In fact, it is openif there is a FPTA for Independent Set (and this
parameter), and it’s also openif existence of a FPTA implies
![{\\textsc{P}\\xspace}=
{\\textsc{NP}\\xspace}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Ctextsc%7BP%7D%5Cxspace%7D%3D%20%7B%5Ctextsc%7BNP%7D%5Cxspace%7D "{\textsc{P}\xspace}= {\textsc{NP}\xspace}").

FPTA for Independent Set {#sec:fpta_for_independent_set}
------------------------

The general idea is to use a parameter for a FPTA that measures the
“tree-ness” of our graph.

### Independent Set on a Tree {#sub:independent_set_on_a_tree}

We want to find the independent set on a tree.

We define the recursive functions
![IS(v)](http://chart.apis.google.com/chart?cht=tx&chl=IS%28v%29 "IS(v)")
and
![IS'(V)](http://chart.apis.google.com/chart?cht=tx&chl=IS%27%28V%29 "IS'(V)"),
which are the maximum weight of the independent set of the subtree
rooted at ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") that
do
(![IS(v)](http://chart.apis.google.com/chart?cht=tx&chl=IS%28v%29 "IS(v)"))
or do not
(![IS'(v)](http://chart.apis.google.com/chart?cht=tx&chl=IS%27%28v%29 "IS'(v)"))
include ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v").

We can even put weights on vertexes as
![w(v)](http://chart.apis.google.com/chart?cht=tx&chl=w%28v%29 "w(v)").

    ind_set_tree(V):
        for v = V.leaves:
            IS_2[v] = 0
            IS[v] = w(v)
        for v in V.vertexes-in-leaf-to-root-order:
            // where v_i are the children of v...
            IS_2[v] = sum_i(IS[v_i])
            IS[v]  = max(w(v) + sum_i(IS_2[v_i]), IS_2[v])
        return IS[root]
                        

### Independent Set on Graphs that are “Almost” Trees {#sub:independent_set_on_graphs_that_are_almost_trees}

#### Series Parallel Graphs {#ssub:series_parallel_graphs}

A Series-Parallel graph (SP) is defined recursively as:

-   A single edge connecting two vertexes.

-   Two parallel SP graphs sharing the same start and end vertexes.

-   Two SP graphs connected in series.

Refer to Figure [fig:sp~c~omposition] for an example.

![Composition of SP Graphs](images/sp_composition.png "fig:")
[fig:sp~c~omposition]

We can find the Independent set in series parallel graph by dynamic
programming based on the maximum independent set for all permutations
containing or not containing
![s](http://chart.apis.google.com/chart?cht=tx&chl=s "s") or
![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t").

### Decomposing Series Parallel Graphs {#sub:decomposing_series_parallel_graphs}

We can model the decomposition of a SP as a tree.

Vertexes that represent a parallel decomposition are a 2-tuple of ![(s,
t)](http://chart.apis.google.com/chart?cht=tx&chl=%28s%2C%20t%29 "(s, t)").
Vertexes that represent a series decomposition are a 3-tuple of ![(s,
v\_\\text{middle},
t)](http://chart.apis.google.com/chart?cht=tx&chl=%28s%2C%20v_%5Ctext%7Bmiddle%7D%2C%20t%29 "(s, v_\text{middle}, t)").
Edges in the graph appear as leaf vertexes.

We have two properties:

1.  If ![e = (u,
    v)](http://chart.apis.google.com/chart?cht=tx&chl=e%20%3D%20%28u%2C%20v%29 "e = (u, v)")
    is an edge of
    ![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G") then
    ![u](http://chart.apis.google.com/chart?cht=tx&chl=u "u") and
    ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") trivially
    appear together in a tree node.

2.  Every vertex
    ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") of
    ![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G")
    corresponds to a sub-tree
    ![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T").

### Generalization to General Graphs {#sub:generalization_to_general_graphs}

The concept of Tree-Width was created by Robertson & Seymour as part of
the “Graph Minors Project”, the result of 20 papers, totaling around 500
pages.

We want to represent a graph as a tree, and have properties 1 and 2 from
above.

I believe that we define bags as a 2-or-3-tuple of a vertex.

The width of a decomposition is the size of the largest bag in the tree
- 1.

The tree width of
![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G") is the minimum
width of any tree decomposition, which is ![\\le n -
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20n%20-%201 "\le n - 1").

And we only need ![\\le
n](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20n "\le n") bags
in any tree decomposition.

Finding the tree-width of a graph is NP-hard, but there is a FPT
algorithm ![O(2\^{O(k\^3}
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%282%5E%7BO%28k%5E3%7D%20n%29 "O(2^{O(k^3} n)").

### Graphs of Tree Width {#sub:graphs_of_tree_width}

The maximum weight of the independent set in a graph of a tree-width
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") can be found
in time ![O(2\^k
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%282%5Ek%20n%29 "O(2^k n)").

The idea of the proof is to use DP to the tree upwards.

For each bag ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B")
of size ![\\le k +
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%20k%20%2B%201 "\le k + 1")
we find for each subset ![A \\subseteq
B](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Csubseteq%20B "A \subseteq B")
(there are
![O(2\^k)](http://chart.apis.google.com/chart?cht=tx&chl=O%282%5Ek%29 "O(2^k)")
of them), a maximum weight independent set including
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") (excluding ![B
- a](http://chart.apis.google.com/chart?cht=tx&chl=B%20-%20a "B - a"))
in the subtree rooted at
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B").

### Other Problems FPT in Tree-Width {#sub:other_problems_fpt_in_tree_width}

-   3-Coloring

-   Minimum coloring

-   Hamiltonian cycle (apparently it’s even more complicated)

### Hardness Results of FPT Problems {#sub:hardness_results_of_fpt_problems}

All relative results are of the form: A FPT algorithm existing for
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") implies there
is a FPT algorithm for
![Y](http://chart.apis.google.com/chart?cht=tx&chl=Y "Y"), and is proved
through a reduction that preserves the parameter and the FPT.

Sample Algorithms {#cha:sample_algorithms}
=================

QuickSort {#sec:quicksort}
---------

We have data ![S = \\{ s\_1 \\ldots s\_n
\\}](http://chart.apis.google.com/chart?cht=tx&chl=S%20%3D%20%5C%7B%20s_1%20%5Cldots%20s_n%20%5C%7D "S = \{ s_1 \ldots s_n \}").

    def QuickSort(S):
        if n == 0 or n == 1:
            return S
        i = random(1, n)
        L = {s_j : s_j < s_i}
        M = {s_j : s_j = s_i}
        R = {s_j : s_j > s_i}
        return QuickSort(L).append(M).append(QuickSort(R))
                

In the worst case, this runs in ![T(n) = T(n-1) + O(n) =
O(n\^2)](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%3D%20T%28n-1%29%20%2B%20O%28n%29%20%3D%20O%28n%5E2%29 "T(n) = T(n-1) + O(n) = O(n^2)")
time.

We “expect” the pivot to be in the middle, so ![|L| = |B| =
\\frac{n}{2}](http://chart.apis.google.com/chart?cht=tx&chl=%7CL%7C%20%3D%20%7CB%7C%20%3D%20%5Cfrac%7Bn%7D%7B2%7D "|L| = |B| = \frac{n}{2}")
and ![T(n) = 2 T(\\frac{n}{2}) + O(n) = O(n \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%3D%202%20T%28%5Cfrac%7Bn%7D%7B2%7D%29%20%2B%20O%28n%29%20%3D%20O%28n%20%5Clog%20n%29 "T(n) = 2 T(\frac{n}{2}) + O(n) = O(n \log n)").[^80^](#fn80)

More formally, we’ll analyze randomized QuickSort with recursive calls
of ![T(\\ell) + T(n - \\ell -
1)](http://chart.apis.google.com/chart?cht=tx&chl=T%28%5Cell%29%20%2B%20T%28n%20-%20%5Cell%20-%201%29 "T(\ell) + T(n - \ell - 1)").

By random choice of pivot,
![\\ell](http://chart.apis.google.com/chart?cht=tx&chl=%5Cell "\ell") is
equally likely to be each of ![\\{0 \\ldots
n-1\\}](http://chart.apis.google.com/chart?cht=tx&chl=%5C%7B0%20%5Cldots%20n-1%5C%7D "\{0 \ldots n-1\}"),
each with a
![\\Pr(\\frac{1}{n})](http://chart.apis.google.com/chart?cht=tx&chl=%5CPr%28%5Cfrac%7B1%7D%7Bn%7D%29 "\Pr(\frac{1}{n})").
Then, we get:

\
![\\begin{aligned} T(n) &= \\frac{1}{n} \\left(\\sum\^{n-1}\_{\\ell = 0}
T(\\ell) + T(n - \\ell - 1)\\right) + O(n) \\\\ &= \\frac{2}{n}
\\left(\\sum\^{n-1}\_{\\ell = 0} T(\\ell)\\right) + O(n)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%28n%29%20%26%3D%20%5Cfrac%7B1%7D%7Bn%7D%20%5Cleft%28%5Csum%5E%7Bn-1%7D_%7B%5Cell%20%3D%200%7D%20T%28%5Cell%29%20%2B%20T%28n%20-%20%5Cell%20-%201%29%5Cright%29%20%2B%20O%28n%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B2%7D%7Bn%7D%20%5Cleft%28%5Csum%5E%7Bn-1%7D_%7B%5Cell%20%3D%200%7D%20T%28%5Cell%29%5Cright%29%20%2B%20O%28n%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                T(n) &= \frac{1}{n} \left(\sum^{n-1}_{\ell = 0} T(\ell) + T(n - \ell - 1)\right) + O(n) \\
                &= \frac{2}{n} \left(\sum^{n-1}_{\ell = 0} T(\ell)\right) + O(n)
            \end{aligned}")\

Using a proof by induction, we arrive at ![T(n) = O(n \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=T%28n%29%20%3D%20O%28n%20%5Clog%20n%29 "T(n) = O(n \log n)"),
which means that we can expect quicksort to take ![O(n \\log
n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%20%5Clog%20n%29 "O(n \log n)")
time[^81^](#fn81).

Math Review {#cha:math_review}
===========

Expected Values - Statistics {#sec:expected_values_statistics}
----------------------------

The expected value of the random variable
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") is
![E(X)](http://chart.apis.google.com/chart?cht=tx&chl=E%28X%29 "E(X)").
For discrete ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X"),
we know:

\
![\\begin{aligned} E(X) &= \\sum\_x xPr\\{X = x\\}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%29%20%26%3D%20%5Csum_x%20xPr%5C%7BX%20%3D%20x%5C%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                E(X) &= \sum_x xPr\{X = x\}
            \end{aligned}")\

For any ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") and
![Y](http://chart.apis.google.com/chart?cht=tx&chl=Y "Y"), we know that:

\
![\\begin{aligned} E(X + Y) &= E(X) + E(Y)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%20%2B%20Y%29%20%26%3D%20E%28X%29%20%2B%20E%28Y%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                E(X + Y) &= E(X) + E(Y)
            \end{aligned}")\

For a constant
![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c"), we know:

\
![\\begin{aligned} E(cX) &= cE(X)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28cX%29%20%26%3D%20cE%28X%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                E(cX) &= cE(X)
            \end{aligned}")\

If ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") and
![Y](http://chart.apis.google.com/chart?cht=tx&chl=Y "Y") are
independent random variables, we know:

\
![\\begin{aligned} Pr\\{X = x \\text{ and } Y = y\\} &= Pr\\{X = x\\}
Pr\\{Y = y\\} \\\\ E(XY) &= E(X) E(Y)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Pr%5C%7BX%20%3D%20x%20%5Ctext%7B%20and%20%7D%20Y%20%3D%20y%5C%7D%20%26%3D%20Pr%5C%7BX%20%3D%20x%5C%7D%20Pr%5C%7BY%20%3D%20y%5C%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28XY%29%20%26%3D%20E%28X%29%20E%28Y%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                Pr\{X = x \text{ and } Y = y\} &= Pr\{X = x\} Pr\{Y = y\} \\
                E(XY) &= E(X) E(Y)
            \end{aligned}")\

More details are in CLRS.

Markov’s Inequality {#sec:markov_s_inequality}
-------------------

If the random variable ![X \\ge
0](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Cge%200 "X \ge 0")
and ![E(X) =
\\mu](http://chart.apis.google.com/chart?cht=tx&chl=E%28X%29%20%3D%20%5Cmu "E(X) = \mu"),
then ![\\Pr\\{ X \\ge c \\mu \\} \\le
\\frac{1}{c}](http://chart.apis.google.com/chart?cht=tx&chl=%5CPr%5C%7B%20X%20%5Cge%20c%20%5Cmu%20%5C%7D%20%5Cle%20%5Cfrac%7B1%7D%7Bc%7D "\Pr\{ X \ge c \mu \} \le \frac{1}{c}")
for a constant
![c](http://chart.apis.google.com/chart?cht=tx&chl=c "c").

\
![\\begin{aligned} \\mu &= E(X) \\\\ &= \\sum x \\Pr(X = x) \\\\ &\\ge
\\sum\_{x \\ge c \\mu} x \\Pr(X = x) \\\\ &\\ge c \\mu \\sum\_{x \\ge c
\\mu} \\Pr(X = x) \\\\ &= \\Pr(X \\ge c \\mu) \\\\ \\Pr(X \\ge c \\mu)
&\\le \\frac{\\mu}{c \\mu} \\\\ &= \\frac{1}{c}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmu%20%26%3D%20E%28X%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum%20x%20%5CPr%28X%20%3D%20x%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20%5Csum_%7Bx%20%5Cge%20c%20%5Cmu%7D%20x%20%5CPr%28X%20%3D%20x%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Cge%20c%20%5Cmu%20%5Csum_%7Bx%20%5Cge%20c%20%5Cmu%7D%20%5CPr%28X%20%3D%20x%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5CPr%28X%20%5Cge%20c%20%5Cmu%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5CPr%28X%20%5Cge%20c%20%5Cmu%29%20%26%5Cle%20%5Cfrac%7B%5Cmu%7D%7Bc%20%5Cmu%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7Bc%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                \mu &= E(X) \\
                &= \sum x \Pr(X = x) \\
                &\ge \sum_{x \ge c \mu} x \Pr(X = x) \\
                &\ge c \mu \sum_{x \ge c \mu} \Pr(X = x) \\
                &= \Pr(X \ge c \mu) \\
                \Pr(X \ge c \mu) &\le \frac{\mu}{c \mu} \\
                &= \frac{1}{c}
            \end{aligned}")\

This proof can be found on page 5 of the Lecture 11 notes.

Logic {#sec:logic}
-----

### Contrapositive {#sub:contrapositive}

The contrapositive is defined as ![(A \\implies B) \\implies (\\lnot B
\\implies \\lnot
A)](http://chart.apis.google.com/chart?cht=tx&chl=%28A%20%5Cimplies%20B%29%20%5Cimplies%20%28%5Clnot%20B%20%5Cimplies%20%5Clnot%20A%29 "(A \implies B) \implies (\lnot B \implies \lnot A)").

### Conjunctive Normal Form (CNF) {#sub:conjunctive_normal_form_}

Given a boolean formula, CNF is the form:

\
![\\begin{aligned} E &= (x\_1 \\lor x\_2 \\lor x\_3) \\land (x\_1 \\lor
\\lnot x\_2) \\land (\\lnot x\_1 \\lor \\lnot x\_2 \\lor \\lnot x\_3)
\\land (x\_2 \\lor \\lnot x\_3)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%20%26%3D%20%28x_1%20%5Clor%20x_2%20%5Clor%20x_3%29%20%5Cland%20%28x_1%20%5Clor%20%5Clnot%20x_2%29%20%5Cland%20%28%5Clnot%20x_1%20%5Clor%20%5Clnot%20x_2%20%5Clor%20%5Clnot%20x_3%29%20%5Cland%20%28x_2%20%5Clor%20%5Clnot%20x_3%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    E &= (x_1 \lor x_2 \lor x_3) \land (x_1 \lor \lnot x_2) \land (\lnot x_1 \lor \lnot x_2 \lor \lnot x_3) \land (x_2 \lor \lnot x_3)
                \end{aligned}")\

* * * * *

1.  A tour is a traversal ordering of vertexes in a graph[↩](#fnref1)

2.  A Eulerian Tour is a tour that goes through each vertex exactly once
    and returns to the first vertex.[↩](#fnref2)

3.  A complete graph is one where there exists an edge between all
    vertexes in the graph.[↩](#fnref3)

4.  An approximation for this would solve the Hamiltonian-Cycle decision
    problem in Ptime. The Hamiltonian Cycle decision problem is known to
    be NP-complete.[↩](#fnref4)

5.  There is a
    ![(1.5)](http://chart.apis.google.com/chart?cht=tx&chl=%281.5%29 "(1.5)")-approximation
    algorithm, but the minimum bound is
    ![1.0045](http://chart.apis.google.com/chart?cht=tx&chl=1.0045 "1.0045").[↩](#fnref5)

6.  There is an
    ![(\\epsilon+1)](http://chart.apis.google.com/chart?cht=tx&chl=%28%5Cepsilon%2B1%29 "(\epsilon+1)")-solution
    for an ![\\forall \\epsilon \>
    0](http://chart.apis.google.com/chart?cht=tx&chl=%5Cforall%20%5Cepsilon%20%3E%200 "\forall \epsilon > 0"),
    but time grows as
    ![\\epsilon](http://chart.apis.google.com/chart?cht=tx&chl=%5Cepsilon "\epsilon")
    decreases. This is a [Polynomial Time Approximation
    Scheme](https://en.wikipedia.org/wiki/Polynomial-time_approximation_scheme).
    See Chapter TODO for PTASs.[↩](#fnref6)

7.  We know this, since ![m =
    O(n\^2)](http://chart.apis.google.com/chart?cht=tx&chl=m%20%3D%20O%28n%5E2%29 "m = O(n^2)")
    implies that ![\\log m = O(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Clog%20m%20%3D%20O%28%5Clog%20n%29 "\log m = O(\log n)"),
    within a constant[↩](#fnref7)

8.  All properties in this list can be proved by induction.[↩](#fnref8)

9.  TODO: is the amortized time different?[↩](#fnref9)

10. scraig postulates that this can be proved with a telescoping
    sum[↩](#fnref10)

11. This is a special case of **Incremental Dynamic
    Connectivity**.[↩](#fnref11)

12. Greedy algorithm that orders edges by weight, then adds them slowly
    into a tree (if an edge creates a cycle, don’t add it). We end up
    with a minimum spanning tree.[↩](#fnref12)

13. Since ![m \\le
    n\^2](http://chart.apis.google.com/chart?cht=tx&chl=m%20%5Cle%20n%5E2 "m \le n^2"),
    we have ![O(\\log m) = O(\\log
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28%5Clog%20m%29%20%3D%20O%28%5Clog%20n%29 "O(\log m) = O(\log n)")[↩](#fnref13)

14. ![\\alpha(m,
    n)](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha%28m%2C%20n%29 "\alpha(m, n)")
    is the inverse Ackerman function. It is very slow growing, and is
    ![\\le
    5](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle%205 "\le 5")
    for all practical purposes.[↩](#fnref14)

15. ![\\log\^\*
    n](http://chart.apis.google.com/chart?cht=tx&chl=%5Clog%5E%2A%20n "\log^* n")
    is essentially the minimum number of times
    ![log(n)](http://chart.apis.google.com/chart?cht=tx&chl=log%28n%29 "log(n)")
    needs to be recursively called in order for
    ![\\log(\\log(\\ldots(n))) \\le
    1](http://chart.apis.google.com/chart?cht=tx&chl=%5Clog%28%5Clog%28%5Cldots%28n%29%29%29%20%5Cle%201 "\log(\log(\ldots(n))) \le 1").
    The inverse of this is ![2\\uparrow
    n](http://chart.apis.google.com/chart?cht=tx&chl=2%5Cuparrow%20n "2\uparrow n"),
    which is ![2](http://chart.apis.google.com/chart?cht=tx&chl=2 "2")
    exponentiated with itself
    ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n")
    times.[↩](#fnref15)

16. This is because a vertex of rank
    ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") has ![n
    \\ge
    2\^r](http://chart.apis.google.com/chart?cht=tx&chl=n%20%5Cge%202%5Er "n \ge 2^r")
    descendants, and vertexes of rank
    ![r](http://chart.apis.google.com/chart?cht=tx&chl=r "r") have
    disjoint descendants.[↩](#fnref16)

17. See the QuickSort details in Section  [sec:quicksort][↩](#fnref17)

18. We can get the first method using the second.[↩](#fnref18)

19. ![I](http://chart.apis.google.com/chart?cht=tx&chl=I "I") and
    ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") are
    different types, and polymorphism works in pseudocode.[↩](#fnref19)

20. Blum et al. \`75[↩](#fnref20)

21. This proof type is an adversary proof.[↩](#fnref21)

22. We’re effectively trying to find the worst case scenario, played out
    by an adversary. Stick to the plot, foo![↩](#fnref22)

23. This can probably be done using induction, but it isn’t
    noted.[↩](#fnref23)

24. In other words, is
    ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") not
    prime?[↩](#fnref24)

25. In 2002, Agrawal, Kayal, and Saxena published a poly-time
    non-randomized algorithm to test primality known as the [AKS
    Primality
    Test](https://en.wikipedia.org/wiki/AKS_primality_test).[↩](#fnref25)

26. Contrapositive notes can be found at
    [sub:contrapositive].[↩](#fnref26)

27. The numbers without Fermat witnesses are called . The first
    ![3](http://chart.apis.google.com/chart?cht=tx&chl=3 "3") are
    ![561](http://chart.apis.google.com/chart?cht=tx&chl=561 "561"),
    ![1105](http://chart.apis.google.com/chart?cht=tx&chl=1105 "1105"),
    ![1729](http://chart.apis.google.com/chart?cht=tx&chl=1729 "1729").[↩](#fnref27)

28. This means that for a decision problem, only one of YES or NO can be
    wrong.[↩](#fnref28)

29. i.e. the yes answers can be verified in poly-time.[↩](#fnref29)

30. okay, maybe “many”[↩](#fnref30)

31. The classes rp and co-np are defined later.[↩](#fnref31)

32. Though the specification is that the probability must be ![\\ge
    0.5](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%200.5 "\ge 0.5"),
    repeated random tests can increase the probability for lower values.
    A better constraint is that the probability that
    ![A(x)](http://chart.apis.google.com/chart?cht=tx&chl=A%28x%29 "A(x)")
    accepts must be non-zero.[↩](#fnref32)

33. ![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M") is chosen
    later[↩](#fnref33)

34. This is a prime number theorem.[↩](#fnref34)

35. We have a few other methods:\
    Using finite automata, we have ![O(m|\\Sigma| +
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%28m%7C%5CSigma%7C%20%2B%20n%29 "O(m|\Sigma| + n)")
    non-randomized algorithms, where
    ![\\Sigma](http://chart.apis.google.com/chart?cht=tx&chl=%5CSigma "\Sigma")
    is the size of the alphabet.\
    Using Knuth-Morris-Pratt or Boyer-Moore algorithms, we have
    ![O(n+m)](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%2Bm%29 "O(n+m)")
    non-randomized algorithms.[↩](#fnref35)

36. ![H\_p(T[i+1 \\ldots i+m]) = (2 H\_p(T[i \\ldots i+m - 1]) - T[i]
    2\^m + T[i + m]) \\mod p
    ](http://chart.apis.google.com/chart?cht=tx&chl=H_p%28T%5Bi%2B1%20%5Cldots%20i%2Bm%5D%29%20%3D%20%282%20H_p%28T%5Bi%20%5Cldots%20i%2Bm%20-%201%5D%29%20-%20T%5Bi%5D%202%5Em%20%2B%20T%5Bi%20%2B%20m%5D%29%20%5Cmod%20p%20 "H_p(T[i+1 \ldots i+m]) = (2 H_p(T[i \ldots i+m - 1]) - T[i] 2^m + T[i + m]) \mod p ")[↩](#fnref36)

37. Where ![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") and
    ![T[\\ldots]](http://chart.apis.google.com/chart?cht=tx&chl=T%5B%5Cldots%5D "T[\ldots]")
    are viewed as binary numbers[↩](#fnref37)

38. There exists a efficient algorithm for computing
    determinants.[↩](#fnref38)

39. Can compute modulo prime[↩](#fnref39)

40. There’s a theorem for equality that’s useful, but that type of test
    comes up in symbolic math programs[↩](#fnref40)

41. e.g. ![f(x\_1, x\_2, x\_3) = x\_1 x\_2\^3 + x\_3\^2 + x\_1
    x\_2](http://chart.apis.google.com/chart?cht=tx&chl=f%28x_1%2C%20x_2%2C%20x_3%29%20%3D%20x_1%20x_2%5E3%20%2B%20x_3%5E2%20%2B%20x_1%20x_2 "f(x_1, x_2, x_3) = x_1 x_2^3 + x_3^2 + x_1 x_2")
    has total degree
    ![4](http://chart.apis.google.com/chart?cht=tx&chl=4 "4").[↩](#fnref41)

42. There are slight improvements since, notably Williams finding
    ![O(n\^{2.3727})](http://chart.apis.google.com/chart?cht=tx&chl=O%28n%5E%7B2.3727%7D%29 "O(n^{2.3727})").[↩](#fnref42)

43. By the previous part, this is a degree 1
    (![d=1](http://chart.apis.google.com/chart?cht=tx&chl=d%3D1 "d=1"))
    multivariate polynomial.[↩](#fnref43)

44. If there is no inequality bounding this, then the optimal solution
    occurs at ![\\pm
    \\infty](http://chart.apis.google.com/chart?cht=tx&chl=%5Cpm%20%5Cinfty "\pm \infty").[↩](#fnref44)

45. It’s important to note that the optimal solution may not be
    unique.[↩](#fnref45)

46. de Berg et al. used 3D linear programming to achieve
    this[↩](#fnref46)

47. Actually, this algorithm runs in ![O(2\^{2\^d}
    n)](http://chart.apis.google.com/chart?cht=tx&chl=O%282%5E%7B2%5Ed%7D%20n%29 "O(2^{2^d} n)"),
    but the “linear” growth of
    ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is the
    object[↩](#fnref47)

48. The idea of this kind of analysis is to consider the situation after
    an element has been added, and note that it is a random element
    among the set added so far.[↩](#fnref48)

49. That of course depends badly on
    ![d](http://chart.apis.google.com/chart?cht=tx&chl=d "d").[↩](#fnref49)

50. TODO: Why isn’t this guaranteed?[↩](#fnref50)

51. By concentrating on 2-SAT then broadening our scope to
    3-SAT.[↩](#fnref51)

52. Analysis omitted from course slides.[↩](#fnref52)

53. If they aren’t, we only need to break ties
    consistently.[↩](#fnref53)

54. I have no clue what this means.[↩](#fnref54)

55. An incident edge to
    ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v") is an edge
    between ![v](http://chart.apis.google.com/chart?cht=tx&chl=v "v")
    and another vertex.[↩](#fnref55)

56. In class, she alluded that this is complicated, and didn’t go any
    further. At the bottom of her notes though, there is a link to [A
    CMU grad course’s
    (link)](https://www.cs.cmu.edu/afs/cs.cmu.edu/academic/class/15750-s01/www/notes/lect0208)
    explanation of the matter.[↩](#fnref56)

57. Two edges are incident if they share a vertex.[↩](#fnref57)

58. This seems to be the only reference to Vazirani in her notes, but
    she mentions in class that he visited UWaterloo a while ago and
    showed her a misprint in the subtitle of an old version of his
    book.[↩](#fnref58)

59. A matching ![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M")
    is a set of edges such that no two share a common
    vertex.[↩](#fnref59)

60. There is no proof given, and Chapter [cha:linear~p~rogramming]
    doesn’t deal with this type of problem.[↩](#fnref60)

61. That is, the number of edges cut.[↩](#fnref61)

62. As usual, ![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m")
    is the number of edges.[↩](#fnref62)

63. To prove that it is NP-complete, we only need to reduce 3-sat to Max
    2-sat, just turn ![(x \\lor y \\lor
    z)](http://chart.apis.google.com/chart?cht=tx&chl=%28x%20%5Clor%20y%20%5Clor%20z%29 "(x \lor y \lor z)")
    into about 10 2-sat clauses such that ![(x \\lor y \\lor
    z)](http://chart.apis.google.com/chart?cht=tx&chl=%28x%20%5Clor%20y%20%5Clor%20z%29 "(x \lor y \lor z)")
    is satisfied if about 7 of the 2-sat clauses are
    satisfied.[↩](#fnref63)

64. Not explained in class, but apparently there are many powerful
    consequences.[↩](#fnref64)

65. Yes, this is the same factor as Max-Cut, as denoted on page
     [ssub:state~o~f~t~he~a~rt~i~n~m~ax~c~ut][↩](#fnref65)

66. Discovered by Hochbaum & Maas, \`85.[↩](#fnref66)

67. I don’t know why she used
    ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S"), given
    that it usually denotes a set. Oh well.[↩](#fnref67)

68. Being tight means that we’ve proved that it’s
    ![\\le1.7](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle1.7 "\le1.7"),
    and have infinitely many examples where the algorithm gives this
    ratio, effectively proving the approximation uses ![=
    1.7{\\textsc{opt}\\xspace}+
    1](http://chart.apis.google.com/chart?cht=tx&chl=%3D%201.7%7B%5Ctextsc%7Bopt%7D%5Cxspace%7D%2B%201 "= 1.7{\textsc{opt}\xspace}+ 1")
    bins.[↩](#fnref68)

69. This can be proved by reducing subset sum to knapsack or
    partition.[↩](#fnref69)

70. Apparently they made some technical assumptions as
    well.[↩](#fnref70)

71. ![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") does not
    infer, but guesses randomly.[↩](#fnref71)

72. Apparently there are instances where more than one prover is
    necessary, but I can’t think of any.[↩](#fnref72)

73. Maybe any NP-complete?[↩](#fnref73)

74. Since 1988, the time is apparently nigh[↩](#fnref74)

75. Given a graph, is it 3-colorable is NP-complete, so we still run
    into that issue.[↩](#fnref75)

76. The algorithm is a Fixed-Parameter Tractable Algorithm
    (FPTA).[↩](#fnref76)

77. Apparently, this means 0 for planar graphs, and 1 for embeddable on
    a torus without crossing edges.[↩](#fnref77)

78. Don’t repeat vertexes.[↩](#fnref78)

79. of vertexes that share no edges[↩](#fnref79)

80. In this case, we use “expectations” that the input is “average”,
    which is not amortized analysis. Better analysis is
    below.[↩](#fnref80)

81. In CLRS, there is nice analysis without recurrence
    relations.[↩](#fnref81)
