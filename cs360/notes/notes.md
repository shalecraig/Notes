---
generator: pandoc
title: CS 360 Term Notes
...

Introduction
============

Countable and Uncountable sets
------------------------------

When talking about the size of a set, they can be infinite or finite.
When talking about an order, sets can be countable (i.e. enumerable) or
uncountable (i.e. innumerable).

Iff some set ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A")
is enumerable, then there must exist an invertible function
![f](http://chart.apis.google.com/chart?cht=tx&chl=f "f") such that
![f:\\mathbbold{N} \\to
A](http://chart.apis.google.com/chart?cht=tx&chl=f%3A%5Cmathbbold%7BN%7D%20%5Cto%20A "f:\mathbbold{N} \to A").

Alphabets, Strings, and Languages
---------------------------------

Alphabets (usually denoted by
![\\Sigma](http://chart.apis.google.com/chart?cht=tx&chl=%5CSigma "\Sigma"))
are sets of unique characters. Strings are ordered sets of (possibly
repeating characters in
![\\Sigma](http://chart.apis.google.com/chart?cht=tx&chl=%5CSigma "\Sigma")).
Languages are defined sets of words.

Regular Languages
=================

Regular Languages
-----------------

Regular Languages are languages recognizable by Regular Expressions.

All finite languages are regular. Not all regular languages are finite.

State Machines
--------------

### DFAs

DFA is short for Deterministic Finite State Machine.

A DFA ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") is a
![5](http://chart.apis.google.com/chart?cht=tx&chl=5 "5")-tuple of
![{\\ensuremath{\\left \\langle Q, \\Sigma, \\delta, q\_0, F \\right
\\rangle
}}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20Q%2C%20%5CSigma%2C%20%5Cdelta%2C%20q_0%2C%20F%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle Q, \Sigma, \delta, q_0, F \right \rangle }}").
Where ![Q](http://chart.apis.google.com/chart?cht=tx&chl=Q "Q") is a set
of possible states,
![\\Sigma](http://chart.apis.google.com/chart?cht=tx&chl=%5CSigma "\Sigma")
is the language,
![\\delta](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta "\delta")
is a transfer function ![\\delta: Q, \\Sigma \\to
Q](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta%3A%20Q%2C%20%5CSigma%20%5Cto%20Q "\delta: Q, \Sigma \to Q").

### NFAs

DFA is short for Non-deterministic Finite State Machine.

A NFA ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") is a
![5](http://chart.apis.google.com/chart?cht=tx&chl=5 "5")-tuple of
![{\\ensuremath{\\left \\langle Q, \\Sigma, \\delta, q\_0, F \\right
\\rangle
}}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20Q%2C%20%5CSigma%2C%20%5Cdelta%2C%20q_0%2C%20F%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle Q, \Sigma, \delta, q_0, F \right \rangle }}").
Where ![Q](http://chart.apis.google.com/chart?cht=tx&chl=Q "Q") is a set
of possible states,
![\\Sigma](http://chart.apis.google.com/chart?cht=tx&chl=%5CSigma "\Sigma")
is the language,
![\\delta](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta "\delta")
is a transfer function ![\\delta: Q, \\Sigma \\to
P(Q)](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta%3A%20Q%2C%20%5CSigma%20%5Cto%20P%28Q%29 "\delta: Q, \Sigma \to P(Q)").
![P(Q)](http://chart.apis.google.com/chart?cht=tx&chl=P%28Q%29 "P(Q)")
is the powerset of
![Q](http://chart.apis.google.com/chart?cht=tx&chl=Q "Q") (i.e. the set
of all subsets of
![Q](http://chart.apis.google.com/chart?cht=tx&chl=Q "Q")).

Equivalence of NFAs and DFAs
----------------------------

NFAs and DFAs are equivalent.

We can change an DFA into a NFA trivially.

We can change a NFA into a DFA through the powerset construction - i.e.
we can define
![\\delta\_{DFA}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta_%7BDFA%7D "\delta_{DFA}")
by calling each ![R \\in
P(Q\_{NFA})](http://chart.apis.google.com/chart?cht=tx&chl=R%20%5Cin%20P%28Q_%7BNFA%7D%29 "R \in P(Q_{NFA})")
a state of our new NFA. Transition functions will be ![R, \\Sigma \\to
Q\_{DFA}](http://chart.apis.google.com/chart?cht=tx&chl=R%2C%20%5CSigma%20%5Cto%20Q_%7BDFA%7D "R, \Sigma \to Q_{DFA}").

Regular Operations
------------------

Given two languages
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") and
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B"), there are
three regular operations:

1.  ![C = A \\cup
    B](http://chart.apis.google.com/chart?cht=tx&chl=C%20%3D%20A%20%5Ccup%20B "C = A \cup B"):

    ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") is defined
    to be the language that accepts any string in
    ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") or
    ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") or both.

2.  ![C = A \\cap
    B](http://chart.apis.google.com/chart?cht=tx&chl=C%20%3D%20A%20%5Ccap%20B "C = A \cap B"):

    ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") is defined
    to be the language that accepts any string in both
    ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A")
    ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B").

3.  ![C =
    A\^\*](http://chart.apis.google.com/chart?cht=tx&chl=C%20%3D%20A%5E%2A "C = A^*"):

    ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") is defined
    to be the language that accepts any string in ![\\{ \\varepsilon \\}
    \\cup A \\cup AA \\cup AAA \\cup
    \\ldots](http://chart.apis.google.com/chart?cht=tx&chl=%5C%7B%20%5Cvarepsilon%20%5C%7D%20%5Ccup%20A%20%5Ccup%20AA%20%5Ccup%20AAA%20%5Ccup%20%5Cldots "\{ \varepsilon \} \cup A \cup AA \cup AAA \cup \ldots")

    ![\\varepsilon](http://chart.apis.google.com/chart?cht=tx&chl=%5Cvarepsilon "\varepsilon")
    is the empty string.

Closure Properties of Regular Languages
---------------------------------------

Given that ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") and
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") are regular:

1.  ![A \\cup
    B](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Ccup%20B "A \cup B")
    is regular

2.  ![A \\cap
    B](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Ccap%20B "A \cap B")
    is regular

3.  ![A\^\*](http://chart.apis.google.com/chart?cht=tx&chl=A%5E%2A "A^*")
    is regular

Regular Expressions and Their Equivalence with NFAs and DFAs
------------------------------------------------------------

Regular expressions describe the same languages as NFAs/DFAs:

Regular expressions can be turned into NFA’s trivially. NFAs can
describe the same languages as DFAs, so that reduction works.

Transitions in DFAs can be reduced to Regular Expressions by forcing
transitions to have Regular Expressions, then removing state diagrams
until a Regular Expression appears.

Techniques for Proving Certain Languages are Non-Regular
--------------------------------------------------------

We can use a few techniques to prove certain languages are non-regular,
but the main one seems to be that the pumping lemma holds for every
regular language.

The states:

For every a Regular Language
![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L"), there is a
![p \\ge
1](http://chart.apis.google.com/chart?cht=tx&chl=p%20%5Cge%201 "p \ge 1")
such that every ![w \\in
L](http://chart.apis.google.com/chart?cht=tx&chl=w%20%5Cin%20L "w \in L")
where ![|w| \\ge
p](http://chart.apis.google.com/chart?cht=tx&chl=%7Cw%7C%20%5Cge%20p "|w| \ge p")
can be written as ![w =
xyz](http://chart.apis.google.com/chart?cht=tx&chl=w%20%3D%20xyz "w = xyz").
Where the following holds:

-   ![|y| \\ge
    1](http://chart.apis.google.com/chart?cht=tx&chl=%7Cy%7C%20%5Cge%201 "|y| \ge 1")

-   ![|xy| \\le
    p](http://chart.apis.google.com/chart?cht=tx&chl=%7Cxy%7C%20%5Cle%20p "|xy| \le p")

-   for all ![i \\ge
    0](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cge%200 "i \ge 0"),
    ![xy\^iz \\in
    L](http://chart.apis.google.com/chart?cht=tx&chl=xy%5Eiz%20%5Cin%20L "xy^iz \in L")

i.e. every Regular Language
![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") has a pumping
length ![p](http://chart.apis.google.com/chart?cht=tx&chl=p "p") such
that every string
![w](http://chart.apis.google.com/chart?cht=tx&chl=w "w") where
![|w|\\ge
p](http://chart.apis.google.com/chart?cht=tx&chl=%7Cw%7C%5Cge%20p "|w|\ge p")
must have a portion that can be repeated indefinitely (or removed
altogether).

Further Discussion of Regular Languages, Finite Automata, and Regular Expressions
---------------------------------------------------------------------------------

TODO: Not sure what we did here.

Context-Free Grammars and Languages
===================================

Context-Free Grammars and Languages
-----------------------------------

A context-free grammar
![G](http://chart.apis.google.com/chart?cht=tx&chl=G "G") defines a
context-free language
![L(G)](http://chart.apis.google.com/chart?cht=tx&chl=L%28G%29 "L(G)").

CFG’s are defined as a 4-tuple ![G = (V, \\Sigma, R,
S)](http://chart.apis.google.com/chart?cht=tx&chl=G%20%3D%20%28V%2C%20%5CSigma%2C%20R%2C%20S%29 "G = (V, \Sigma, R, S)"),
where:

-   ![V](http://chart.apis.google.com/chart?cht=tx&chl=V "V") is a
    finite set of non-terminal characters.

-   ![\\Sigma](http://chart.apis.google.com/chart?cht=tx&chl=%5CSigma "\Sigma")
    is a set of terminal characters that make up the language. As a
    rule, ![V \\cap \\Sigma =
    \\varnothing](http://chart.apis.google.com/chart?cht=tx&chl=V%20%5Ccap%20%5CSigma%20%3D%20%5Cvarnothing "V \cap \Sigma = \varnothing").

-   ![R](http://chart.apis.google.com/chart?cht=tx&chl=R "R") is a
    relation ![R: V \\to (V \\cup
    \\Sigma)\^\*](http://chart.apis.google.com/chart?cht=tx&chl=R%3A%20V%20%5Cto%20%28V%20%5Ccup%20%5CSigma%29%5E%2A "R: V \to (V \cup \Sigma)^*").

-   ![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") is the
    start variable (or start symbol. By definition, ![S \\in
    V](http://chart.apis.google.com/chart?cht=tx&chl=S%20%5Cin%20V "S \in V").

For example, this is a context-free grammar that accepts all strings
that are odd length and contain a
![1](http://chart.apis.google.com/chart?cht=tx&chl=1 "1") in the middle:

\
![\\begin{aligned} S &\\to USU | 1 \\\\ U &\\to 0 | 1 \\\\
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20S%20%26%5Cto%20USU%20%7C%201%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20U%20%26%5Cto%200%20%7C%201%20%5C%5C%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            S &\to USU | 1 \\
            U &\to 0 | 1 \\
        \end{aligned}")\

Every regular language can be expressed by a CFG.

Parse Trees and Ambiguity
-------------------------

Parse trees are simple, and they are ambiguous.

For example, how many ways are there to parse `x+++x`? It’s probably
defined in the language spec, but a CFG may mess up interpreting this
line of code.

More Examples of Context-Free Grammars
--------------------------------------

I can’t believe we spent a full class on this. It’s simple.

Normal forms for CFGs
---------------------

[Chomsky Normal Form](http://en.wikipedia.org/wiki/Chomsky_normal_form)
is a form of writing CFGs. All CFGs can be written in CNF.

A grammar is said to be in CNF if all production rules are in the form:

\
![\\begin{aligned} A &\\to BC \\\\ A &\\to \\alpha \\\\ A &\\to
\\varepsilon
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20A%20%26%5Cto%20BC%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20A%20%26%5Cto%20%5Calpha%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20A%20%26%5Cto%20%5Cvarepsilon%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            A &\to BC \\
            A &\to \alpha \\
            A &\to \varepsilon
        \end{aligned}")\

Where ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") and
![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") are
nonterminal symbols, are not
![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S"),
![\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha "\alpha")
is a terminal symbol. Of course,
![\\varepsilon](http://chart.apis.google.com/chart?cht=tx&chl=%5Cvarepsilon "\varepsilon")
is the empty string.

Closure Properties for CFLs
---------------------------

Context-Free Languages are closed under the following operations:
(Assume that ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A"),
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") are in CFL)

1.  ![A \\cup
    B](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Ccup%20B "A \cup B")

2.  ![AB](http://chart.apis.google.com/chart?cht=tx&chl=AB "AB")

3.  ![\\text{reverse}(A)](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctext%7Breverse%7D%28A%29 "\text{reverse}(A)")

4.  ![A\^\*](http://chart.apis.google.com/chart?cht=tx&chl=A%5E%2A "A^*")

![\\mathsf{A}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmathsf%7BA%7D "\mathsf{A}"),
![A \\cap
B](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Ccap%20B "A \cap B"),
![A \\setminus
B](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Csetminus%20B "A \setminus B")
are not CFLs.

Techniques for Proving Certain Languages are Non-Context-Free
-------------------------------------------------------------

We can use a few techniques to prove certain languages are
non-Context-Free, but the main one is the pumping lemma holds for every
Context-Free language.

The states:

For every a Context-Free Language
![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L"), there exists
a ![p \\ge
1](http://chart.apis.google.com/chart?cht=tx&chl=p%20%5Cge%201 "p \ge 1")
such that for every ![w \\in
L](http://chart.apis.google.com/chart?cht=tx&chl=w%20%5Cin%20L "w \in L")
where ![|w| \\ge
p](http://chart.apis.google.com/chart?cht=tx&chl=%7Cw%7C%20%5Cge%20p "|w| \ge p")
can be written as ![w =
uvxyz](http://chart.apis.google.com/chart?cht=tx&chl=w%20%3D%20uvxyz "w = uvxyz").
Where the following holds:

-   ![|vxy| \\le
    p](http://chart.apis.google.com/chart?cht=tx&chl=%7Cvxy%7C%20%5Cle%20p "|vxy| \le p")

-   ![vx \\ne
    \\varepsilon](http://chart.apis.google.com/chart?cht=tx&chl=vx%20%5Cne%20%5Cvarepsilon "vx \ne \varepsilon")

-   For all ![i \\ge
    0](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cge%200 "i \ge 0"),
    ![uv\^ixy\^iz \\in
    L](http://chart.apis.google.com/chart?cht=tx&chl=uv%5Eixy%5Eiz%20%5Cin%20L "uv^ixy^iz \in L").

i.e. every Context-Free Language
![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") has a pumping
length ![p](http://chart.apis.google.com/chart?cht=tx&chl=p "p") such
that every string
![w](http://chart.apis.google.com/chart?cht=tx&chl=w "w") where ![|w|
\\ge
p](http://chart.apis.google.com/chart?cht=tx&chl=%7Cw%7C%20%5Cge%20p "|w| \ge p")
must have a rule (or chain of rules) such that indefinitely (or removed
altogether).

Further Discussion of Context-Free Languages and Grammars
---------------------------------------------------------

TODO: Not sure what we did here.

Turing Machines
===============

Pushdown Automata
-----------------

A machine that has a stack and reads input from a tape. It can recognize
a superset of Context-Free Languages.

A Pushdown Automata can be expressed as a 7-tuple:

\
![\\begin{aligned} M = {\\ensuremath{\\left \\langle Q, \\Sigma,
\\Gamma, \\delta, q\_0, Z, F \\right \\rangle }}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20M%20%3D%20%7B%5Censuremath%7B%5Cleft%20%5Clangle%20Q%2C%20%5CSigma%2C%20%5CGamma%2C%20%5Cdelta%2C%20q_0%2C%20Z%2C%20F%20%5Cright%20%5Crangle%20%7D%7D%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            M = {\ensuremath{\left \langle Q, \Sigma, \Gamma, \delta, q_0, Z, F \right \rangle }}
        \end{aligned}")\

Where:

-   ![Q](http://chart.apis.google.com/chart?cht=tx&chl=Q "Q") is a
    finite set of states.

-   ![\\Sigma](http://chart.apis.google.com/chart?cht=tx&chl=%5CSigma "\Sigma")
    is the alphabet.

-   ![\\Gamma](http://chart.apis.google.com/chart?cht=tx&chl=%5CGamma "\Gamma")
    is the stack alphabet. It’s the set of symbols that can go on the
    stack.

-   ![q\_0 \\in
    Q](http://chart.apis.google.com/chart?cht=tx&chl=q_0%20%5Cin%20Q "q_0 \in Q")
    is the start state.

-   ![Z \\in
    \\Gamma](http://chart.apis.google.com/chart?cht=tx&chl=Z%20%5Cin%20%5CGamma "Z \in \Gamma")
    is the initial stack symbol. It’s the initial value in the stack.

-   ![F \\subseteq
    Q](http://chart.apis.google.com/chart?cht=tx&chl=F%20%5Csubseteq%20Q "F \subseteq Q")
    is the set of accepting states.

-   ![\\delta](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta "\delta")
    is the transition function that operates as follows:

    -   Pop ![\\alpha \\in
        \\Gamma](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha%20%5Cin%20%5CGamma "\alpha \in \Gamma")
        from the stack.

    -   Read input ![r \\in (\\Sigma \\cup \\{ \\varepsilon
        \\})](http://chart.apis.google.com/chart?cht=tx&chl=r%20%5Cin%20%28%5CSigma%20%5Ccup%20%5C%7B%20%5Cvarepsilon%20%5C%7D%29 "r \in (\Sigma \cup \{ \varepsilon \})").

    -   See current state is ![q \\in
        Q](http://chart.apis.google.com/chart?cht=tx&chl=q%20%5Cin%20Q "q \in Q").

    -   Move to a new state ![q' \\in
        Q](http://chart.apis.google.com/chart?cht=tx&chl=q%27%20%5Cin%20Q "q' \in Q").

    -   Push a new variable on the stack: ![\\alpha' \\in
        \\Gamma](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha%27%20%5Cin%20%5CGamma "\alpha' \in \Gamma").

    i.e. ![\\delta: \\Gamma \\times (\\Sigma \\cup \\{ \\varepsilon \\})
    \\times Q \\to Q \\times
    \\Gamma\^\*](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta%3A%20%5CGamma%20%5Ctimes%20%28%5CSigma%20%5Ccup%20%5C%7B%20%5Cvarepsilon%20%5C%7D%29%20%5Ctimes%20Q%20%5Cto%20Q%20%5Ctimes%20%5CGamma%5E%2A "\delta: \Gamma \times (\Sigma \cup \{ \varepsilon \}) \times Q \to Q \times \Gamma^*")

The Turing machine model
------------------------

Turing Machines are similar to PDAs but aren’t exactly the same thing.
Turing-machines consist of an infinitely long tape, a tape head, a state
register and a function.

More formally, Turing Machines can be specified by a 7-Tuple:

\
![\\begin{aligned} M = {\\ensuremath{\\left \\langle Q, \\Gamma, b,
\\Sigma, \\delta, q\_0, F \\right \\rangle }}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20M%20%3D%20%7B%5Censuremath%7B%5Cleft%20%5Clangle%20Q%2C%20%5CGamma%2C%20b%2C%20%5CSigma%2C%20%5Cdelta%2C%20q_0%2C%20F%20%5Cright%20%5Crangle%20%7D%7D%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            M = {\ensuremath{\left \langle Q, \Gamma, b, \Sigma, \delta, q_0, F \right \rangle }}
        \end{aligned}")\

Where:

1.  ![Q](http://chart.apis.google.com/chart?cht=tx&chl=Q "Q") is a set
    of states

2.  ![\\Gamma](http://chart.apis.google.com/chart?cht=tx&chl=%5CGamma "\Gamma")
    is the tape alphabet. Basically what the tape can store.

3.  ![b \\in
    \\Gamma](http://chart.apis.google.com/chart?cht=tx&chl=b%20%5Cin%20%5CGamma "b \in \Gamma")
    is the blank symbol. It’s the “initial” value of most of the tape.

4.  ![\\Sigma \\in
    \\Gamma](http://chart.apis.google.com/chart?cht=tx&chl=%5CSigma%20%5Cin%20%5CGamma "\Sigma \in \Gamma")
    is the set of input symbols.

5.  ![F \\subseteq
    Q](http://chart.apis.google.com/chart?cht=tx&chl=F%20%5Csubseteq%20Q "F \subseteq Q")
    is the set of accepting states.

6.  ![\\delta: Q \\setminus F \\times \\Gamma \\to Q \\times \\Gamma
    \\times \\{ L, R
    \\}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta%3A%20Q%20%5Csetminus%20F%20%5Ctimes%20%5CGamma%20%5Cto%20Q%20%5Ctimes%20%5CGamma%20%5Ctimes%20%5C%7B%20L%2C%20R%20%5C%7D "\delta: Q \setminus F \times \Gamma \to Q \times \Gamma \times \{ L, R \}").
    ![\\delta](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta "\delta")
    is the transition function. It changes the state, writes to the
    tape, and moves the tape based on based on the value of the tape at
    the current location and starting state.

Variants of Turing Machines
---------------------------

TODO: Not sure what we did here.

Specifications of DTMs
----------------------

TODO: Not sure what we did here.

The Church-Turing thesis
------------------------

Basically, the thesis states that a function is algorithmically
computable if and only if it is computable by a Turing machine.

Encoding schemes
----------------

We can encode anything as a set of 0’s and 1’s by serializing it. For
example, we can denote an encoding of a DTM
![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M") as
![{\\ensuremath{\\left \\langle M \\right \\rangle
}}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20M%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle M \right \rangle }}").

That’s all I believe I need to write.

Decidable and Recognizable Languages
====================================

Decidable and Turing-Recognizable Languages
-------------------------------------------

Turing-Recognizable Languages are languages that can be “recognized” by
a Turing Machine. i.e. A language
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") is said to be
Turing Recognizable if there exists a Turing Machine
![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M") such that
![L(M) =
P](http://chart.apis.google.com/chart?cht=tx&chl=L%28M%29%20%3D%20P "L(M) = P").

Decidable Languages are languages that can be “decided” by a Turing
Machine. i.e. A language
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") is said to be
decidable if there exists a Turing Machine
![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M") such that for
every input string ![r \\in
\\Sigma\^\*](http://chart.apis.google.com/chart?cht=tx&chl=r%20%5Cin%20%5CSigma%5E%2A "r \in \Sigma^*"),
![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M") will halt and
output “accept” or “reject”.

Closure Properties of Decidable and Turing-Recognizable Languages
-----------------------------------------------------------------

Decidable Languages are closed under:

-   Union

-   Intersection

-   Complementation

-   Concatenation

-   Kleene Star

Turing-Recognizable Languages are closed under:

-   Union

-   Intersection

-   Concatenation

-   Kleene Star

Some Decidable Languages
------------------------

-   ![A\_{DFA} = \\{ {\\ensuremath{\\left \\langle B, w \\right \\rangle
    }} | B \\text{is a DFA that accepts input string w}
    \\}](http://chart.apis.google.com/chart?cht=tx&chl=A_%7BDFA%7D%20%3D%20%5C%7B%20%7B%5Censuremath%7B%5Cleft%20%5Clangle%20B%2C%20w%20%5Cright%20%5Crangle%20%7D%7D%20%7C%20B%20%5Ctext%7Bis%20a%20DFA%20that%20accepts%20input%20string%20w%7D%20%5C%7D "A_{DFA} = \{ {\ensuremath{\left \langle B, w \right \rangle }} | B \text{is a DFA that accepts input string w} \}")

-   ![A\_{NFA} = \\{ {\\ensuremath{\\left \\langle B, w \\right \\rangle
    }} | B \\text{is an NFA that accepts input string w}
    \\}](http://chart.apis.google.com/chart?cht=tx&chl=A_%7BNFA%7D%20%3D%20%5C%7B%20%7B%5Censuremath%7B%5Cleft%20%5Clangle%20B%2C%20w%20%5Cright%20%5Crangle%20%7D%7D%20%7C%20B%20%5Ctext%7Bis%20an%20NFA%20that%20accepts%20input%20string%20w%7D%20%5C%7D "A_{NFA} = \{ {\ensuremath{\left \langle B, w \right \rangle }} | B \text{is an NFA that accepts input string w} \}")

-   ![A\_{REX} = \\{ {\\ensuremath{\\left \\langle B, w \\right \\rangle
    }} | B \\text{is a regular expression that accepts input string w}
    \\}](http://chart.apis.google.com/chart?cht=tx&chl=A_%7BREX%7D%20%3D%20%5C%7B%20%7B%5Censuremath%7B%5Cleft%20%5Clangle%20B%2C%20w%20%5Cright%20%5Crangle%20%7D%7D%20%7C%20B%20%5Ctext%7Bis%20a%20regular%20expression%20that%20accepts%20input%20string%20w%7D%20%5C%7D "A_{REX} = \{ {\ensuremath{\left \langle B, w \right \rangle }} | B \text{is a regular expression that accepts input string w} \}")

-   ![E\_{DFA} = \\{ {\\ensuremath{\\left \\langle A \\right \\rangle }}
    | A \\text{is a DFA and } L(A) = \\emptyset
    \\}](http://chart.apis.google.com/chart?cht=tx&chl=E_%7BDFA%7D%20%3D%20%5C%7B%20%7B%5Censuremath%7B%5Cleft%20%5Clangle%20A%20%5Cright%20%5Crangle%20%7D%7D%20%7C%20A%20%5Ctext%7Bis%20a%20DFA%20and%20%7D%20L%28A%29%20%3D%20%5Cemptyset%20%5C%7D "E_{DFA} = \{ {\ensuremath{\left \langle A \right \rangle }} | A \text{is a DFA and } L(A) = \emptyset \}")

-   ![EQ\_{DFA} = \\{ {\\ensuremath{\\left \\langle A, B \\right
    \\rangle }} | A \\text{ and } B \\text{are DFAs and } L(A) = L(B)
    \\}](http://chart.apis.google.com/chart?cht=tx&chl=EQ_%7BDFA%7D%20%3D%20%5C%7B%20%7B%5Censuremath%7B%5Cleft%20%5Clangle%20A%2C%20B%20%5Cright%20%5Crangle%20%7D%7D%20%7C%20A%20%5Ctext%7B%20and%20%7D%20B%20%5Ctext%7Bare%20DFAs%20and%20%7D%20L%28A%29%20%3D%20L%28B%29%20%5C%7D "EQ_{DFA} = \{ {\ensuremath{\left \langle A, B \right \rangle }} | A \text{ and } B \text{are DFAs and } L(A) = L(B) \}")

-   ![A\_{CFG} = \\{ {\\ensuremath{\\left \\langle G, w \\right \\rangle
    }} | G \\text{ is a CFG that generates } w
    \\}](http://chart.apis.google.com/chart?cht=tx&chl=A_%7BCFG%7D%20%3D%20%5C%7B%20%7B%5Censuremath%7B%5Cleft%20%5Clangle%20G%2C%20w%20%5Cright%20%5Crangle%20%7D%7D%20%7C%20G%20%5Ctext%7B%20is%20a%20CFG%20that%20generates%20%7D%20w%20%5C%7D "A_{CFG} = \{ {\ensuremath{\left \langle G, w \right \rangle }} | G \text{ is a CFG that generates } w \}")

-   ![A\_{CFG} = \\{ {\\ensuremath{\\left \\langle G, w \\right \\rangle
    }} | G \\text{ is a CFG that generates } w
    \\}](http://chart.apis.google.com/chart?cht=tx&chl=A_%7BCFG%7D%20%3D%20%5C%7B%20%7B%5Censuremath%7B%5Cleft%20%5Clangle%20G%2C%20w%20%5Cright%20%5Crangle%20%7D%7D%20%7C%20G%20%5Ctext%7B%20is%20a%20CFG%20that%20generates%20%7D%20w%20%5C%7D "A_{CFG} = \{ {\ensuremath{\left \langle G, w \right \rangle }} | G \text{ is a CFG that generates } w \}")

-   ![E\_{CFG} = \\{ {\\ensuremath{\\left \\langle G \\right \\rangle }}
    | G \\text{ is a CFG and } L(G) = \\emptyset
    \\}](http://chart.apis.google.com/chart?cht=tx&chl=E_%7BCFG%7D%20%3D%20%5C%7B%20%7B%5Censuremath%7B%5Cleft%20%5Clangle%20G%20%5Cright%20%5Crangle%20%7D%7D%20%7C%20G%20%5Ctext%7B%20is%20a%20CFG%20and%20%7D%20L%28G%29%20%3D%20%5Cemptyset%20%5C%7D "E_{CFG} = \{ {\ensuremath{\left \langle G \right \rangle }} | G \text{ is a CFG and } L(G) = \emptyset \}")

-   ![EQ\_{CFG} = \\{ {\\ensuremath{\\left \\langle G, H \\right
    \\rangle }} | G \\text{ and } H \\text{are DFAs and } L(G) = L(H)
    \\}](http://chart.apis.google.com/chart?cht=tx&chl=EQ_%7BCFG%7D%20%3D%20%5C%7B%20%7B%5Censuremath%7B%5Cleft%20%5Clangle%20G%2C%20H%20%5Cright%20%5Crangle%20%7D%7D%20%7C%20G%20%5Ctext%7B%20and%20%7D%20H%20%5Ctext%7Bare%20DFAs%20and%20%7D%20L%28G%29%20%3D%20L%28H%29%20%5C%7D "EQ_{CFG} = \{ {\ensuremath{\left \langle G, H \right \rangle }} | G \text{ and } H \text{are DFAs and } L(G) = L(H) \}")

-   Every context-free language is decidable.

A Non-Turing-Recognizable Language
----------------------------------

TODO: In this portion, I believe that we did the Halting Problem. Need
to verify.

Undecidability of the Halting Problem
-------------------------------------

Given a description of an arbitrary computer program, decide whether the
program finishes running or continues forever. In other words, given a
program and an input, please decide if the program eventually halts when
run with that input? (or will it run forever)

Suppose a solution to the halting problem
![H](http://chart.apis.google.com/chart?cht=tx&chl=H "H") “accepts”
input ![H(P,
I)](http://chart.apis.google.com/chart?cht=tx&chl=H%28P%2C%20I%29 "H(P, I)")
if and only if ![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P")
halts on ![I](http://chart.apis.google.com/chart?cht=tx&chl=I "I").
Otherwise, it will always “reject”.

Now we define the code
![Z](http://chart.apis.google.com/chart?cht=tx&chl=Z "Z") as follows:

                Program(String x):
                    if Halt(x, x):
                        Loop forever
                    else:
                        Halt
            

This is a pretty simple program, but if we run
![Z](http://chart.apis.google.com/chart?cht=tx&chl=Z "Z") with input
![Z](http://chart.apis.google.com/chart?cht=tx&chl=Z "Z"), we have
impossible conclusions:

-   In the case that
    ![Halt(Z,Z)](http://chart.apis.google.com/chart?cht=tx&chl=Halt%28Z%2CZ%29 "Halt(Z,Z)")
    is true, we will loop forever. This is a contradiction.

-   In the case that
    ![Halt(Z,Z)](http://chart.apis.google.com/chart?cht=tx&chl=Halt%28Z%2CZ%29 "Halt(Z,Z)")
    is false, we will halt. This is a contradiction.

This function ![H](http://chart.apis.google.com/chart?cht=tx&chl=H "H")
cannot exist.

Reductions
----------

One of the easiest ways to prove something is not decidable or not
Turing-Recognizable is to establish a mapping from some other language
you already know to be undecidable or not to be Turing-Recognizable.

We can define
![\\le\_m](http://chart.apis.google.com/chart?cht=tx&chl=%5Cle_m "\le_m")
reductions (i.e. mapping reductions) as follows:

Being able to reduce problem
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") to
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") by using a
mapping reducibility means that a computable function
![f](http://chart.apis.google.com/chart?cht=tx&chl=f "f") exists that
converts instances of
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") to
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B"). If we have
this ![f](http://chart.apis.google.com/chart?cht=tx&chl=f "f") (called a
reduction), we can solve
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") with a solver
for ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B").

We want to find a way to “translate” every problem in
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") to a problem
in ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B").

By finding ![A \\le\_m
B](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Cle_m%20B "A \le_m B")
and knowing some things about
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A"), we know some
things about ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B"):

-   ![A \\le\_m
    B](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Cle_m%20B "A \le_m B")
    and ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") is not
    decidable, then
    ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") is not
    decidable.

-   ![A \\le\_m
    B](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Cle_m%20B "A \le_m B")
    and ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") is not
    Turing-Recognizable, then
    ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") is not
    Turing-Recognizable.

More Undecidable and Non-Turing-Recognizable Languages
------------------------------------------------------

TODO: Not sure what we did here.

Further Discussion of Turing Machines
-------------------------------------

TODO: Not sure what we did here.

Computation Time
================

Time-Bounded Computation
------------------------

TODO: Complete Me

The Time Hierarchy Theorem
--------------------------

I’m relatively sure it goes as follows:

\
![\\begin{aligned} \\mbox{P} \\subseteq \\mbox{NP} \\subseteq
\\mbox{EXPTIME}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cmbox%7BP%7D%20%5Csubseteq%20%5Cmbox%7BNP%7D%20%5Csubseteq%20%5Cmbox%7BEXPTIME%7D%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            \mbox{P} \subseteq \mbox{NP} \subseteq \mbox{EXPTIME}
        \end{aligned}")\

TODO: Complete Me

Boolean Circuits and Their Relationship to Turing Machines
----------------------------------------------------------

Any Turing Machine can be simulated by a boolean circuit, and every
boolean circuit can be simulated by a Turing Machine.

P and EXP
---------

![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") is the class
of decision problems which can be solved by a DTM using a polynomial
amount of computation time. i.e. Polytime or
![P](http://chart.apis.google.com/chart?cht=tx&chl=P "P") time.

![EXP](http://chart.apis.google.com/chart?cht=tx&chl=EXP "EXP") is the
set of all decision problems solvable by a DTM in
![O(2\^{p(n)})](http://chart.apis.google.com/chart?cht=tx&chl=O%282%5E%7Bp%28n%29%7D%29 "O(2^{p(n)})")
time, where
![p(n)](http://chart.apis.google.com/chart?cht=tx&chl=p%28n%29 "p(n)")
is a polynomial function of
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n").

Nondeterministic Turing Machines
--------------------------------

Nondeterministic Turing Machines (NDTMs) are defined as a 6-tuple:

\
![\\begin{aligned} M = (Q, \\Sigma, \\iota, \\sqcup, A, \\delta)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20M%20%3D%20%28Q%2C%20%5CSigma%2C%20%5Ciota%2C%20%5Csqcup%2C%20A%2C%20%5Cdelta%29%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            M = (Q, \Sigma, \iota, \sqcup, A, \delta)
        \end{aligned}")\

Where:

-   ![Q](http://chart.apis.google.com/chart?cht=tx&chl=Q "Q") is a
    finite set of states.

-   ![\\Sigma](http://chart.apis.google.com/chart?cht=tx&chl=%5CSigma "\Sigma")
    is a finite set of symbols (the tape alphabet).

-   ![\\iota \\in
    Q](http://chart.apis.google.com/chart?cht=tx&chl=%5Ciota%20%5Cin%20Q "\iota \in Q")
    is the initial state.

-   ![\\sqcup \\in
    \\Sigma](http://chart.apis.google.com/chart?cht=tx&chl=%5Csqcup%20%5Cin%20%5CSigma "\sqcup \in \Sigma")
    is the blank symbol.

-   ![A \\subseteq
    Q](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Csubseteq%20Q "A \subseteq Q")
    is the set of accepting states.

-   ![\\delta](http://chart.apis.google.com/chart?cht=tx&chl=%5Cdelta "\delta")
    is the transfer function ![Q \\setminus A \\times \\Sigma \\to Q
    \\times \\Sigma \\times \\{ L, R
    \\}](http://chart.apis.google.com/chart?cht=tx&chl=Q%20%5Csetminus%20A%20%5Ctimes%20%5CSigma%20%5Cto%20Q%20%5Ctimes%20%5CSigma%20%5Ctimes%20%5C%7B%20L%2C%20R%20%5C%7D "Q \setminus A \times \Sigma \to Q \times \Sigma \times \{ L, R \}")

The difference between a NDTM (NTM?) and a DTM is that NDTMs inhabit a
set of states instead of a single state. They accept the state if any of
their current states are accepted.

NP
--

We say that ![NP](http://chart.apis.google.com/chart?cht=tx&chl=NP "NP")
is the set of problems that are defined as follows:

\
![\\begin{aligned} \\mbox{NP} &= \\bigcup\_{k \\in \\mathbbold{N}}
\\mbox{NTIME}(n\^k)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cmbox%7BNP%7D%20%26%3D%20%5Cbigcup_%7Bk%20%5Cin%20%5Cmathbbold%7BN%7D%7D%20%5Cmbox%7BNTIME%7D%28n%5Ek%29%0A%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
            \mbox{NP} &= \bigcup_{k \in \mathbbold{N}} \mbox{NTIME}(n^k)
        \end{aligned}")\

Alternatively, we can define using DTMs. A language
![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") is in NP if
and only if there exist polynomials
![p](http://chart.apis.google.com/chart?cht=tx&chl=p "p") and
![q](http://chart.apis.google.com/chart?cht=tx&chl=q "q") and a DTM
![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M") such that: [We
call ![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M") a TODO
what do we call
![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M")?]

-   For all ![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x")
    and ![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y"), the
    machine ![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M")
    runs in time
    ![p(|x|)](http://chart.apis.google.com/chart?cht=tx&chl=p%28%7Cx%7C%29 "p(|x|)")
    on input ![{\\ensuremath{\\left \\langle x, y \\right \\rangle
    }}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20x%2C%20y%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle x, y \right \rangle }}").

-   For all ![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x") in
    ![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L"), there
    exists a string
    ![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y") of length
    ![q(|x|)](http://chart.apis.google.com/chart?cht=tx&chl=q%28%7Cx%7C%29 "q(|x|)"),
    ![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M") accepts
    ![{\\ensuremath{\\left \\langle x, y \\right \\rangle
    }}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20x%2C%20y%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle x, y \right \rangle }}").

-   For all ![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x")
    not in ![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L"),
    there exists a string
    ![y](http://chart.apis.google.com/chart?cht=tx&chl=y "y") of length
    ![q(|x|)](http://chart.apis.google.com/chart?cht=tx&chl=q%28%7Cx%7C%29 "q(|x|)"),
    ![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M") rejects
    ![{\\ensuremath{\\left \\langle x, y \\right \\rangle
    }}](http://chart.apis.google.com/chart?cht=tx&chl=%7B%5Censuremath%7B%5Cleft%20%5Clangle%20x%2C%20y%20%5Cright%20%5Crangle%20%7D%7D "{\ensuremath{\left \langle x, y \right \rangle }}").

We can say that a language
![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") is NP-Complete
if ![L](http://chart.apis.google.com/chart?cht=tx&chl=L "L") is NP and
every ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") in NP is
polynomial time reducible to
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B").

Polynomial-Time Mapping Reductions
----------------------------------

Language ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") is
polynomial time mapping reducible (or simply polytime reducible) to
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B"), written ![A
\\le\_p
B](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Cle_p%20B "A \le_p B")
if a polytime computable function ![f : \\Sigma\^\* \\to
\\Sigma\^\*](http://chart.apis.google.com/chart?cht=tx&chl=f%20%3A%20%5CSigma%5E%2A%20%5Cto%20%5CSigma%5E%2A "f : \Sigma^* \to \Sigma^*")
exists such that for every
![w](http://chart.apis.google.com/chart?cht=tx&chl=w "w"), ![w \\in A
\\leftrightarrow f(w) \\in
B](http://chart.apis.google.com/chart?cht=tx&chl=w%20%5Cin%20A%20%5Cleftrightarrow%20f%28w%29%20%5Cin%20B "w \in A \leftrightarrow f(w) \in B").

If ![A \\le\_p
B](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Cle_p%20B "A \le_p B")
and ![B \\in
P](http://chart.apis.google.com/chart?cht=tx&chl=B%20%5Cin%20P "B \in P"),
then ![A \\in
P](http://chart.apis.google.com/chart?cht=tx&chl=A%20%5Cin%20P "A \in P").

![\\mbox{3SAT}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmbox%7B3SAT%7D "\mbox{3SAT}")
is polytime reducible to
![\\mbox{CLIQUE}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmbox%7BCLIQUE%7D "\mbox{CLIQUE}").
This means that if
![\\mbox{CLIQUE}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmbox%7BCLIQUE%7D "\mbox{CLIQUE}")
is solvable in polynomial time, so is
![\\mbox{3SAT}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmbox%7B3SAT%7D "\mbox{3SAT}").

Set of related notes:

-   If ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") is
    NP-Complete and ![B \\in
    P](http://chart.apis.google.com/chart?cht=tx&chl=B%20%5Cin%20P "B \in P"),
    then P = NP

-   If ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") is
    NP-Complete and ![B \\le\_p
    C](http://chart.apis.google.com/chart?cht=tx&chl=B%20%5Cle_p%20C "B \le_p C")
    for ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") in NP,
    then ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") is
    NP-Complete.

-   3SAT, CLIQUE, SAT, Vertex Cover, HamPath, Subset-SUM are all
    NP-Complete.

The Cook-Levin Theorem
----------------------

The Cook-Levin theorem states that boolean satisfiability is
NP-Complete.

That is, any problem in NP can be reduced to boolean satisfiability in
polynomial time by a deterministic Turing Machine to the problem of
determining whether a Boolean formula is satisfiable.

Further Discussion of Computability and Complexity theory
---------------------------------------------------------
