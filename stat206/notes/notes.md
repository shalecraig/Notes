---
generator: pandoc
title: STAT 206
...

Getting Acquainted with Statistics {#cha:getting_acquainted_with_statistics}
==================================

Definitions {#sec:definitions}
-----------

Empirical Studies are algorithms of the form: *Hypothesi*
![\\to](http://chart.apis.google.com/chart?cht=tx&chl=%5Cto "\to") *Data
Collection*
![\\to](http://chart.apis.google.com/chart?cht=tx&chl=%5Cto "\to")
*Analysis*. For example, we may ask:

> Can people tell if vinyl sounds better than MP3?

Unit
:   is a single element (i.e. model, entity, person, item, etc) of a
    population whose characteristics we are interested in.

Population
:   is the universe of all *Unit*s we are interested in.

Variables
:   are a measurement of the characteristic from a unit.

After some class discussion, we change the question to be as follows:

> Can healthy teens tell if vinyl sounds better than mp3?

In this question, here are the different sections:

Population
:   All healthy teens

Unit
:   A single healthy teen

Variable 1
:   Can the Unit correctly identify the recognized type?

Variable 2
:   Which recording did the Unit believe sounds better?

We define the following other terms:

Categorial Variable:
:   qualitative variable, belongs to
    ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") classes or
    categories.

Discrete Variable:
:   quantitative, countable variable (Integers).

Continuous Variable:
:   quantitative, non-countable (Reals).

Sample:
:   A subset of the population from which measurements are actually
    made.

Sample Error:
:   The error introduced by estimating an entire population’s
    characteristics from a *Sample*.

Study Error:
:   A systematic, *unfixable* error through the sample not accurately
    representing the population.

There are these metrics:

Sample Mean:
:   ![\\bar{x} = \\sum\_{i \\in 1}\^{n}
    x\_i](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7Bx%7D%20%3D%20%5Csum_%7Bi%20%5Cin%201%7D%5E%7Bn%7D%20x_i "\bar{x} = \sum_{i \in 1}^{n} x_i").

Median:
:   (middle point)

    \
    ![\\begin{aligned} x\^\* &= \\left\\{ \\begin{array}{lr}
    x\_{\\frac{n+1}{2}} & : \\text{if \$n\$ is odd} \\\\
    \\frac{x\_{\\frac{n+1}{2}} + x\_{\\frac{n+2}{2}}}{2} & : \\text{if
    \$n\$ is even} \\end{array} \\right.
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20x%5E%2A%20%26%3D%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20x_%7B%5Cfrac%7Bn%2B1%7D%7B2%7D%7D%20%26%20%3A%20%5Ctext%7Bif%20%24n%24%20is%20odd%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7Bx_%7B%5Cfrac%7Bn%2B1%7D%7B2%7D%7D%20%2B%20x_%7B%5Cfrac%7Bn%2B2%7D%7B2%7D%7D%7D%7B2%7D%20%26%20%3A%20%5Ctext%7Bif%20%24n%24%20is%20even%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                            x^* &= \left\{
                                 \begin{array}{lr}
                                   x_{\frac{n+1}{2}} & : \text{if $n$ is odd} \\
                                   \frac{x_{\frac{n+1}{2}} + x_{\frac{n+2}{2}}}{2} & : \text{if $n$ is even}
                                 \end{array}
                               \right.
                        \end{aligned}")\

Sample Variance:
:   ![s\^2 = \\frac{\\sum\_{i=1}\^n (x\_i -
    \\bar{x})\^2}{n-1}](http://chart.apis.google.com/chart?cht=tx&chl=s%5E2%20%3D%20%5Cfrac%7B%5Csum_%7Bi%3D1%7D%5En%20%28x_i%20-%20%5Cbar%7Bx%7D%29%5E2%7D%7Bn-1%7D "s^2 = \frac{\sum_{i=1}^n (x_i - \bar{x})^2}{n-1}")

Standard Deviation:
:   ![s =
    \\sqrt{s\^2}](http://chart.apis.google.com/chart?cht=tx&chl=s%20%3D%20%5Csqrt%7Bs%5E2%7D "s = \sqrt{s^2}")

Range:
:   ![x\_n -
    x\_1](http://chart.apis.google.com/chart?cht=tx&chl=x_n%20-%20x_1 "x_n - x_1")
    (max - min)

There are two different kinds of Statistics:

Descriptive Statistics
:   is summarizing data from a sample both graphically and numerically.

Inferential Statistics
:   uses a sample to generalize results to the entire population.

Probability {#sec:probability}
-----------

Classic probability is usually defined as:

\
![\\begin{aligned} \\frac{\\text{Number of ways event can
occur}}{\\text{Total number of equally likely outcomes}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B%5Ctext%7BNumber%20of%20ways%20event%20can%20occur%7D%7D%7B%5Ctext%7BTotal%20number%20of%20equally%20likely%20outcomes%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \frac{\text{Number of ways event can occur}}{\text{Total number of equally likely outcomes}}
                \end{aligned}")\

Relative Frequency:
:   the proportion of times outcome occurs as a number of trials
    approaches infinity.

Subjective Frequency:
:   estimates of probability based on subjective opinion.

Experiment:
:   is a repeatable phenomenon

Trial:
:   is a single instance of an experiment

Sample Space:
:   is the set of distinct outcomes for an experiment or process where
    only one outcome of the set occurs

    Discrete
    :   sample spaces have countable number of simple event

    Non-Discrete/Continuous
    :   sample spaces have a non-countable number of simple events

Experiment: Flip a coin 3 times.

### Probability Models {#sub:probability_models}

\
![\\begin{aligned} (\\forall A) & (0 \\le P(A) \\le 1)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%28%5Cforall%20A%29%20%26%20%280%20%5Cle%20P%28A%29%20%5Cle%201%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        (\forall A) & (0 \le P(A) \le 1)
                    \end{aligned}")\

If ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") and
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") are *mutually
exclusive* events, then:

\
![\\begin{aligned} P(A \\cup B) &= P(A) + P(B)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28A%20%5Ccup%20B%29%20%26%3D%20P%28A%29%20%2B%20P%28B%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(A \cup B) &= P(A) + P(B)
                    \end{aligned}")\

The distribution for finite sample space ![S = \\{ a\_1, a\_2, a\_3,
\\cdots, a\_n
\\}](http://chart.apis.google.com/chart?cht=tx&chl=S%20%3D%20%5C%7B%20a_1%2C%20a_2%2C%20a_3%2C%20%5Ccdots%2C%20a_n%20%5C%7D "S = \{ a_1, a_2, a_3, \cdots, a_n \}")
and ![P(a\_i) =
\\frac{1}{n}](http://chart.apis.google.com/chart?cht=tx&chl=P%28a_i%29%20%3D%20%5Cfrac%7B1%7D%7Bn%7D "P(a_i) = \frac{1}{n}")
is named *uniform distribution*.

Permutations are ordered choices:

\
![\\begin{aligned} n\^{(r)} &= \\frac{n!}{(n - r)!}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20n%5E%7B%28r%29%7D%20%26%3D%20%5Cfrac%7Bn%21%7D%7B%28n%20-%20r%29%21%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        n^{(r)} &= \frac{n!}{(n - r)!}
                    \end{aligned}")\

Remember: ![0! =
1](http://chart.apis.google.com/chart?cht=tx&chl=0%21%20%3D%201 "0! = 1")

Combinations are unordered choices:

\
![\\begin{aligned} \\dbinom{n}{r} &= \\frac{n!}{r! (n - r)!} \\\\ &=
\\dbinom{n}{(n - r)} \\\\ &= \\dbinom{n-1}{r} + \\dbinom{n-1}{r-1}
\\text{ (Pascal's Rule)}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cdbinom%7Bn%7D%7Br%7D%20%26%3D%20%5Cfrac%7Bn%21%7D%7Br%21%20%28n%20-%20r%29%21%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cdbinom%7Bn%7D%7B%28n%20-%20r%29%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cdbinom%7Bn-1%7D%7Br%7D%20%2B%20%5Cdbinom%7Bn-1%7D%7Br-1%7D%20%5Ctext%7B%20%28Pascal%27s%20Rule%29%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \dbinom{n}{r} &= \frac{n!}{r! (n - r)!} \\
                        &= \dbinom{n}{(n - r)} \\
                        &= \dbinom{n-1}{r} + \dbinom{n-1}{r-1} \text{ (Pascal's Rule)}
                    \end{aligned}")\

**Example:** 4 digits are selected at random, without replacement from
![\\{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
\\}](http://chart.apis.google.com/chart?cht=tx&chl=%5C%7B%200%2C%201%2C%202%2C%203%2C%204%2C%205%2C%206%2C%207%2C%208%2C%209%20%5C%7D "\{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 \}")
to create a number. What is the probability of:

-   ![A=](http://chart.apis.google.com/chart?cht=tx&chl=A%3D "A=") ‘a
    4-digit number is generated’

    Restriction: first digit is not a zero.

    Let’s enumerate the digits:

    1.  9

    2.  9

    3.  8

    4.  7

    Number of combinations is ![9 x
    9\^{(3)}](http://chart.apis.google.com/chart?cht=tx&chl=9%20x%209%5E%7B%283%29%7D "9 x 9^{(3)}").

    Divide by the size of the sample space to get ![P(A) = \\frac{9 x
    9\^{(3)}}{10\^{(4)}}](http://chart.apis.google.com/chart?cht=tx&chl=P%28A%29%20%3D%20%5Cfrac%7B9%20x%209%5E%7B%283%29%7D%7D%7B10%5E%7B%284%29%7D%7D "P(A) = \frac{9 x 9^{(3)}}{10^{(4)}}")

-   ‘a 4-digit even number is generated’

### Compound Probability {#sub:compound_probability}

\
![\\begin{aligned} S &= \\{ a\_1, a\_2, ... a\_n \\} \\\\ C &= \\{ a\_3
\\} \\\\ A &= \\{ a\_1, a\_2 \\} \\\\ B &= \\{ a\_2, a\_n \\} \\\\ A
\\cup B &= \\{ a\_1, a\_2, a\_n \\} \\\\ P(A \\cup B) &= P(A) + P(B) -
P(AB)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20S%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5C%7B%20a_1%2C%20a_2%2C%20...%20a_n%20%5C%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20C%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5C%7B%20a_3%20%5C%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20A%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5C%7B%20a_1%2C%20a_2%20%5C%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20B%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5C%7B%20a_2%2C%20a_n%20%5C%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20A%20%5Ccup%20B%20%20%20%20%26%3D%20%5C%7B%20a_1%2C%20a_2%2C%20a_n%20%5C%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28A%20%5Ccup%20B%29%20%26%3D%20P%28A%29%20%2B%20P%28B%29%20-%20P%28AB%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        S           &= \{ a_1, a_2, ... a_n \} \\
                        C           &= \{ a_3 \} \\
                        A           &= \{ a_1, a_2 \} \\
                        B           &= \{ a_2, a_n \} \\
                        A \cup B    &= \{ a_1, a_2, a_n \} \\
                        P(A \cup B) &= P(A) + P(B) - P(AB)
                    \end{aligned}")\

**Example:** Suppose that for students finishing 2B SE, 24% have an
overall average of 80%, 26% finish with a grade of at least 80% in STAT
206, and 15% have both an overall average and STAT 206 mark greater than
90%.

Let ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") be the
event that a random SE has overall average
![\>80\\%](http://chart.apis.google.com/chart?cht=tx&chl=%3E80%5C%25 ">80\%").
Let ![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") be the
event a random SE student has STAT206 mark
![\>80\\%](http://chart.apis.google.com/chart?cht=tx&chl=%3E80%5C%25 ">80\%").

\
![\\begin{aligned} P(A) &= 0.24 \\\\ P(B) &= 0.26 \\\\ P(A \\cap B) &=
0.15 \\\\ P(A \\cup B) &= P(A) + P(B) - P(A \\cap B) \\\\ &= 0.24 + 0.26
- 0.15 \\\\ &= 0.35 \\\\ P (A \\cap \\bar{B}) &= P (A) - P(A\\cup B)
\\\\ &= 0.24 - 0.15 \\\\ &= 0.09 \\\\ (A \\cap \\bar{B}) \\cup (A \\cap
B) &= A \\\\ P(A \\cap \\bar{B}) + P(A \\cap B) &= P(A)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28A%29%20%26%3D%200.24%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28B%29%20%26%3D%200.26%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28A%20%5Ccap%20B%29%20%26%3D%200.15%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28A%20%5Ccup%20B%29%20%26%3D%20P%28A%29%20%2B%20P%28B%29%20-%20P%28A%20%5Ccap%20B%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.24%20%2B%200.26%20-%200.15%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.35%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%20%28A%20%5Ccap%20%5Cbar%7BB%7D%29%20%26%3D%20P%20%28A%29%20-%20P%28A%5Ccup%20B%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.24%20-%200.15%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.09%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%28A%20%5Ccap%20%5Cbar%7BB%7D%29%20%5Ccup%20%28A%20%5Ccap%20B%29%20%26%3D%20A%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28A%20%5Ccap%20%5Cbar%7BB%7D%29%20%2B%20P%28A%20%5Ccap%20B%29%20%26%3D%20P%28A%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(A) &= 0.24 \\
                        P(B) &= 0.26 \\
                        P(A \cap B) &= 0.15 \\
                        P(A \cup B) &= P(A) + P(B) - P(A \cap B) \\
                        &= 0.24 + 0.26 - 0.15 \\
                        &= 0.35 \\
                        P (A \cap \bar{B}) &= P (A) - P(A\cup B) \\
                        &= 0.24 - 0.15 \\
                        &= 0.09 \\
                        (A \cap \bar{B}) \cup (A \cap B) &= A \\
                        P(A \cap \bar{B}) + P(A \cap B) &= P(A)
                    \end{aligned}")\

### Conditional Probability {#sub:conditional_probability}

The probability of event
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A"), conditional
on the occurrence of event
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B"), denoted by
![P(A|B)](http://chart.apis.google.com/chart?cht=tx&chl=P%28A%7CB%29 "P(A|B)").

\
![\\begin{aligned} P(A|B) &= \\frac{P(AB)}{P(B)} \\\\ P(B) &\\not= 0
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28A%7CB%29%20%26%3D%20%5Cfrac%7BP%28AB%29%7D%7BP%28B%29%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28B%29%20%26%5Cnot%3D%200%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(A|B) &= \frac{P(AB)}{P(B)} \\
                        P(B) &\not= 0
                    \end{aligned}")\

**Example:** Roll 2 dice, 1 red, 1 green,

![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") = “the sum of
the dice is 8”.

![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") = “the red die
is a 3”.

\
![\\begin{aligned} P(A) &= \\frac{5}{36} \\\\ P(B) &= \\frac{6}{36} \\\\
&= \\frac{1}{6} \\\\ P(A \\cap B) &= \\frac{1}{36} \\\\ P(A|B) &=
\\frac{P(AB)}{P(B)} \\\\ &= \\frac{1}{6}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28A%29%20%26%3D%20%5Cfrac%7B5%7D%7B36%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28B%29%20%26%3D%20%5Cfrac%7B6%7D%7B36%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7B6%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28A%20%5Ccap%20B%29%20%26%3D%20%5Cfrac%7B1%7D%7B36%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28A%7CB%29%20%26%3D%20%5Cfrac%7BP%28AB%29%7D%7BP%28B%29%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7B6%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(A) &= \frac{5}{36} \\
                        P(B) &= \frac{6}{36} \\
                             &= \frac{1}{6} \\
                        P(A \cap B) &= \frac{1}{36} \\
                        P(A|B) &= \frac{P(AB)}{P(B)} \\
                               &= \frac{1}{6}
                    \end{aligned}")\

### Independence {#sub:independence}

Two events are said to be independent if and only if (iff):

\
![\\begin{aligned} P(AB) &= P(A) P(B)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28AB%29%20%26%3D%20P%28A%29%20P%28B%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(AB) &= P(A) P(B)
                    \end{aligned}")\

With this knowledge, we know the following:

\
![\\begin{aligned} P(A|B) &= P(A) \\\\ P(B|A) &= P(B)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28A%7CB%29%20%26%3D%20P%28A%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28B%7CA%29%20%26%3D%20P%28B%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(A|B) &= P(A) \\
                        P(B|A) &= P(B)
                    \end{aligned}")\

**Example:** Suppose we have 3 events:
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A"),
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B"),
![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C"). We know that
![P(A) =
0.3](http://chart.apis.google.com/chart?cht=tx&chl=P%28A%29%20%3D%200.3 "P(A) = 0.3"),
![P(\\bar{C}) =
0.25](http://chart.apis.google.com/chart?cht=tx&chl=P%28%5Cbar%7BC%7D%29%20%3D%200.25 "P(\bar{C}) = 0.25"),
![P(A \\cup B) =
0.65](http://chart.apis.google.com/chart?cht=tx&chl=P%28A%20%5Ccup%20B%29%20%3D%200.65 "P(A \cup B) = 0.65"),
![P(B \\cup \\bar{C}) =
0.45](http://chart.apis.google.com/chart?cht=tx&chl=P%28B%20%5Ccup%20%5Cbar%7BC%7D%29%20%3D%200.45 "P(B \cup \bar{C}) = 0.45"),
and that ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") and
![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") are
independent and that
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") and
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") are mutually
exclusive.

We want to find:

-   ![P(B)](http://chart.apis.google.com/chart?cht=tx&chl=P%28B%29 "P(B)")

-   ![P(A \\cup
    C)](http://chart.apis.google.com/chart?cht=tx&chl=P%28A%20%5Ccup%20C%29 "P(A \cup C)")

-   ![P(\\bar{A}
    B)](http://chart.apis.google.com/chart?cht=tx&chl=P%28%5Cbar%7BA%7D%20B%29 "P(\bar{A} B)")

-   ![P(B |
    \\bar{C})](http://chart.apis.google.com/chart?cht=tx&chl=P%28B%20%7C%20%5Cbar%7BC%7D%29 "P(B | \bar{C})")

We have:

\
![\\begin{aligned} P(A\\cup B) &= P(A) + P(B) - P(AB) \\\\ &= P(A) +
P(B) \\\\ &= 0.35 \\\\ P(A \\cup C) &= P(A) + P(C) - P(A \\cap C) \\\\
&= 0.3 + 0.75 - 0.225 \\\\ &= 0.825 \\\\ (\\bar{A}B) \\cup (AB) &= B
\\\\ P(\\bar{A}B) + P(AB) &= P(B) \\\\ P(\\bar{A}B) &= P(B) \\\\ &= 0.35
\\\\ P(B | \\bar{C}) &= \\frac{P(B \\bar{C})}{P(\\bar{C})} \\\\ &=
\\frac{-P(B \\cup \\bar{C}) + P(B) + P(\\bar{C})}{P(\\bar{C})} \\\\ &=
0.6
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28A%5Ccup%20B%29%20%26%3D%20P%28A%29%20%2B%20P%28B%29%20-%20P%28AB%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28A%29%20%2B%20P%28B%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.35%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28A%20%5Ccup%20C%29%20%26%3D%20P%28A%29%20%2B%20P%28C%29%20-%20P%28A%20%5Ccap%20C%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.3%20%2B%200.75%20-%200.225%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.825%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%28%5Cbar%7BA%7DB%29%20%5Ccup%20%28AB%29%20%26%3D%20B%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28%5Cbar%7BA%7DB%29%20%2B%20P%28AB%29%20%26%3D%20P%28B%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28%5Cbar%7BA%7DB%29%20%26%3D%20P%28B%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.35%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28B%20%7C%20%5Cbar%7BC%7D%29%20%26%3D%20%5Cfrac%7BP%28B%20%5Cbar%7BC%7D%29%7D%7BP%28%5Cbar%7BC%7D%29%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B-P%28B%20%5Ccup%20%5Cbar%7BC%7D%29%20%2B%20P%28B%29%20%2B%20P%28%5Cbar%7BC%7D%29%7D%7BP%28%5Cbar%7BC%7D%29%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.6%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(A\cup B) &= P(A) + P(B) - P(AB) \\
                                   &= P(A) + P(B) \\
                                   &= 0.35 \\
                        P(A \cup C) &= P(A) + P(C) - P(A \cap C) \\
                                    &= 0.3 + 0.75 - 0.225 \\
                                    &= 0.825 \\
                        (\bar{A}B) \cup (AB) &= B \\
                        P(\bar{A}B) + P(AB) &= P(B) \\
                        P(\bar{A}B) &= P(B) \\
                        &= 0.35 \\
                        P(B | \bar{C}) &= \frac{P(B \bar{C})}{P(\bar{C})} \\
                                       &= \frac{-P(B \cup \bar{C}) + P(B) + P(\bar{C})}{P(\bar{C})} \\
                                       &= 0.6
                    \end{aligned}")\

### Law of Total Probability {#sub:law_of_total_probability}

For events that form a complete cover of the sample space (with no
“overlap”), we know this identity:

\
![\\begin{aligned} P(B\_iB\_j) = 0 &\\iff i \\ne j \\\\ \\cup\_{i \\in
\\{ 1, \\cdots n \\}} B\_i &= S \\\\ P (A) &= \\sum\_{i = 1}\^{k} P(A |
B\_i) P(B\_i)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28B_iB_j%29%20%3D%200%20%26%5Ciff%20i%20%5Cne%20j%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ccup_%7Bi%20%5Cin%20%5C%7B%201%2C%20%5Ccdots%20n%20%5C%7D%7D%20B_i%20%26%3D%20S%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%20%28A%29%20%26%3D%20%5Csum_%7Bi%20%3D%201%7D%5E%7Bk%7D%20P%28A%20%7C%20B_i%29%20P%28B_i%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(B_iB_j) = 0 &\iff i \ne j \\
                        \cup_{i \in \{ 1, \cdots n \}} B_i &= S \\
                        P (A) &= \sum_{i = 1}^{k} P(A | B_i) P(B_i)
                    \end{aligned}")\

In other words, given that
![B\_k](http://chart.apis.google.com/chart?cht=tx&chl=B_k "B_k") is
mutually exclusive with
![B\_j](http://chart.apis.google.com/chart?cht=tx&chl=B_j "B_j") for any
unequal ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") and
![j](http://chart.apis.google.com/chart?cht=tx&chl=j "j"), then
![P(A)](http://chart.apis.google.com/chart?cht=tx&chl=P%28A%29 "P(A)")
is equal to the sum of
![P(A|B\_j)](http://chart.apis.google.com/chart?cht=tx&chl=P%28A%7CB_j%29 "P(A|B_j)")
multiplied by the probability that
![P(B\_j)](http://chart.apis.google.com/chart?cht=tx&chl=P%28B_j%29 "P(B_j)")
occurs.

**Example:** A game is played by first rolling a 6-sided die and then
flipping a fair coin the number of times shown on the die. What is the
probability that at least one head is flipped?

Let ![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") be the
event that at least
![1](http://chart.apis.google.com/chart?cht=tx&chl=1 "1") head is
flipped. Let
![B\_i](http://chart.apis.google.com/chart?cht=tx&chl=B_i "B_i") be the
event that we roll a
![1](http://chart.apis.google.com/chart?cht=tx&chl=1 "1"), where ![i =
\\{ 1, 2, \\cdots, 6
\\}](http://chart.apis.google.com/chart?cht=tx&chl=i%20%3D%20%5C%7B%201%2C%202%2C%20%5Ccdots%2C%206%20%5C%7D "i = \{ 1, 2, \cdots, 6 \}").
Also, we know that
![\\bar{A}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7BA%7D "\bar{A}")
is “no heads”.

\
![\\begin{aligned} P(\\bar{A}) &= \\sum\_{i = 1}\^6 P(\\bar{A}|B\_i)
P(B\_i) \\\\ &= \\sum\_{i = 1}\^6 \\frac{1}{6} \\frac{1}{2\^i} \\\\ &=
\\frac{1}{6} \\sum\_{i = 1}\^6 \\frac{1}{2\^i} \\\\
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28%5Cbar%7BA%7D%29%20%26%3D%20%5Csum_%7Bi%20%3D%201%7D%5E6%20P%28%5Cbar%7BA%7D%7CB_i%29%20P%28B_i%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_%7Bi%20%3D%201%7D%5E6%20%5Cfrac%7B1%7D%7B6%7D%20%5Cfrac%7B1%7D%7B2%5Ei%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7B6%7D%20%5Csum_%7Bi%20%3D%201%7D%5E6%20%5Cfrac%7B1%7D%7B2%5Ei%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(\bar{A}) &= \sum_{i = 1}^6 P(\bar{A}|B_i) P(B_i) \\
                                   &= \sum_{i = 1}^6 \frac{1}{6} \frac{1}{2^i} \\
                                   &= \frac{1}{6} \sum_{i = 1}^6 \frac{1}{2^i} \\
                    \end{aligned}")\

We can reduce this through the finite geometric series to ![P(\\bar{A})
=
\\frac{63}{384}](http://chart.apis.google.com/chart?cht=tx&chl=P%28%5Cbar%7BA%7D%29%20%3D%20%5Cfrac%7B63%7D%7B384%7D "P(\bar{A}) = \frac{63}{384}").
We get ![P(A) = 1 - P(\\bar{A}) =
0.84](http://chart.apis.google.com/chart?cht=tx&chl=P%28A%29%20%3D%201%20-%20P%28%5Cbar%7BA%7D%29%20%3D%200.84 "P(A) = 1 - P(\bar{A}) = 0.84").[^1^](#fn1)

### Bayes Theorem {#sub:bayes_theorem}

\
![\\begin{aligned} P (B | A) &= \\frac{P(AB)}{P(A)} \\\\ &= \\frac{P(A |
B) P(B)} {P(B) P(A|B) + P(\\bar{B}) P(A|\\bar{B})}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%20%28B%20%7C%20A%29%20%26%3D%20%5Cfrac%7BP%28AB%29%7D%7BP%28A%29%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7BP%28A%20%7C%20B%29%20P%28B%29%7D%20%7BP%28B%29%20P%28A%7CB%29%20%2B%20P%28%5Cbar%7BB%7D%29%20P%28A%7C%5Cbar%7BB%7D%29%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P (B | A) &= \frac{P(AB)}{P(A)} \\
                        &= \frac{P(A | B) P(B)} {P(B) P(A|B) + P(\bar{B}) P(A|\bar{B})}
                    \end{aligned}")\

**Example:** Tests used to diagnose medical conditions are often
imperfect, and give false positive or false negative results. A fairly
cheap blood test for the Human Immunodeficiency Virus (HIV) has the
following characteristics: the false negative rate is 2% and the false
positive rate is 0.5%. Previous studies estimate that around .04% of
Canadian males are infected with HIV. What is the probability that a
Canadian male who tests positive for HIV, actually has the virus?

Let ![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") be the
event that a randomly selected male tests positive. Let
![H](http://chart.apis.google.com/chart?cht=tx&chl=H "H") be the event
that a randomly selected male actually has the virus.

A *False negative* is: Given that you do have the virus, the probability
that the test tells you don’t, is the false negative.

We know:

\
![\\begin{aligned} P(H) &= 0.0004 \\\\ P(\\bar{H}) &= 0.9996 \\\\
P(\\bar{T} | H) &= 0.02 \\\\ P(T | H) &= 0.98 \\\\ P(T | \\bar{H}) &=
0.005 \\\\ P(\\bar{T} | \\bar{H}) &= 0.995 \\\\ P (H | T) &= \\frac{P(T
| H) P(H)} {P(T|H) P(H) + P(T| \\bar{H})P(\\bar{H})} \\\\ &=
\\frac{(0.98) (0.0004)} {(0.98) (0.0004) + (0.0005)(0.9996)} \\\\ &=
0.07\\bar{27} \\sim 7.3\\%
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28H%29%20%26%3D%200.0004%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28%5Cbar%7BH%7D%29%20%26%3D%200.9996%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28%5Cbar%7BT%7D%20%7C%20H%29%20%26%3D%200.02%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28T%20%7C%20H%29%20%26%3D%200.98%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28T%20%7C%20%5Cbar%7BH%7D%29%20%26%3D%200.005%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28%5Cbar%7BT%7D%20%7C%20%5Cbar%7BH%7D%29%20%26%3D%200.995%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%20%28H%20%7C%20T%29%20%26%3D%20%5Cfrac%7BP%28T%20%7C%20H%29%20P%28H%29%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7BP%28T%7CH%29%20P%28H%29%20%2B%20P%28T%7C%20%5Cbar%7BH%7D%29P%28%5Cbar%7BH%7D%29%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B%280.98%29%20%280.0004%29%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%280.98%29%20%280.0004%29%20%2B%20%280.0005%29%280.9996%29%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.07%5Cbar%7B27%7D%20%5Csim%207.3%5C%25%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(H) &= 0.0004 \\
                        P(\bar{H}) &= 0.9996 \\
                        P(\bar{T} | H) &= 0.02 \\
                        P(T | H) &= 0.98 \\
                        P(T | \bar{H}) &= 0.005 \\
                        P(\bar{T} | \bar{H}) &= 0.995 \\
                        P (H | T) &= \frac{P(T | H) P(H)}
                        {P(T|H) P(H) + P(T| \bar{H})P(\bar{H})} \\
                        &= \frac{(0.98) (0.0004)}
                        {(0.98) (0.0004) + (0.0005)(0.9996)} \\
                        &= 0.07\bar{27} \sim 7.3\%
                    \end{aligned}")\

Random Variables {#sec:random_variables}
----------------

A random variable is a function,
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") from the
sample space to the real number:

\
![\\begin{aligned} X : S \\to \\mathbb{R}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20X%20%3A%20S%20%5Cto%20%5Cmathbb%7BR%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    X : S \to \mathbb{R}
                \end{aligned}")\

The **range** of variable
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") denoted
![R(X)](http://chart.apis.google.com/chart?cht=tx&chl=R%28X%29 "R(X)")
is the set of possible value it can take[^2^](#fn2).

### Binary Random Variables {#sub:binary_random_variables}

Can take on only the values
![0](http://chart.apis.google.com/chart?cht=tx&chl=0 "0") or
![1](http://chart.apis.google.com/chart?cht=tx&chl=1 "1").

### Probability Distribution Function {#sub:probability_distribution_function}

The Probability Density Function (*pdf*) of a discrete random variable
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X"), denoted
![f(x)](http://chart.apis.google.com/chart?cht=tx&chl=f%28x%29 "f(x)")
describes the probability that
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") takes on the
value ![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x"):

\
![\\begin{aligned} f(x) &= P (X = x)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28x%29%20%26%3D%20P%20%28X%20%3D%20x%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        f(x) &= P (X = x)
                    \end{aligned}")\

We know these properties:

\
![\\begin{aligned} f(x) &\\ge 0 \\\\ \\sum\_x f(x) &= 1
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28x%29%20%26%5Cge%200%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Csum_x%20f%28x%29%20%26%3D%201%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        f(x) &\ge 0 \\
                        \sum_x f(x) &= 1
                    \end{aligned}")\

### Cumulative Distribution Function {#sub:cumulative_dist}

The cumulative distribution function (*cdf*) of a discrete random
variable ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X"),
denoted
![F(x)](http://chart.apis.google.com/chart?cht=tx&chl=F%28x%29 "F(x)"),
represents the probability that
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") takes on a
value less than or equal to
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x"):

\
![\\begin{aligned} F(X) &= P(X \\le x)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20F%28X%29%20%26%3D%20P%28X%20%5Cle%20x%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        F(X) &= P(X \le x)
                    \end{aligned}")\

### Mean and Expected Value {#sub:mean_and_expected_value}

The **mean**
(![\\mu](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu "\mu")) or
**expected value**
(![E(X)](http://chart.apis.google.com/chart?cht=tx&chl=E%28X%29 "E(X)"))
of a random variable
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") is defined:

\
![\\begin{aligned} \\mu &= E(X) \\\\ &= \\sum\_x xf(x)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmu%20%26%3D%20E%28X%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_x%20xf%28x%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \mu &= E(X) \\
                        &= \sum_x xf(x)
                    \end{aligned}")\

The following properties hold:

\
![\\begin{aligned} E(g(X)) &= \\sum\_x g(x)f(x) \\\\ E(aX + bY) &= aE(X)
+ bE(Y)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28g%28X%29%29%20%26%3D%20%5Csum_x%20g%28x%29f%28x%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28aX%20%2B%20bY%29%20%26%3D%20aE%28X%29%20%2B%20bE%28Y%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        E(g(X)) &= \sum_x g(x)f(x) \\
                        E(aX + bY) &= aE(X) + bE(Y)
                    \end{aligned}")\

The second one holds for any random variables
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X"),
![Y](http://chart.apis.google.com/chart?cht=tx&chl=Y "Y"), and ![a, b
\\in
\\mathbb{R}](http://chart.apis.google.com/chart?cht=tx&chl=a%2C%20b%20%5Cin%20%5Cmathbb%7BR%7D "a, b \in \mathbb{R}")

### Variance {#sub:variance}

The **variance**
(![Var(X)](http://chart.apis.google.com/chart?cht=tx&chl=Var%28X%29 "Var(X)")
or
![\\sigma\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma%5E2 "\sigma^2"))
of a random variable
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") is the
expected squared difference from the mean.

\
![\\begin{aligned} Var(X) &= E((X - E(X))\^2) \\\\ &= \\sum\_x f(x)(x -
\\mu)\^2 \\\\ &= E(X\^2) - E(X)\^2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28X%29%20%26%3D%20E%28%28X%20-%20E%28X%29%29%5E2%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_x%20f%28x%29%28x%20-%20%5Cmu%29%5E2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20E%28X%5E2%29%20-%20E%28X%29%5E2%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        Var(X) &= E((X - E(X))^2) \\
                        &= \sum_x f(x)(x - \mu)^2 \\
                        &= E(X^2) - E(X)^2
                    \end{aligned}")\

We can derive this as follows:

\
![\\begin{aligned} Var(X) &= E\\left( (X - E(X))\^2 \\right) \\\\ &= E (
X\^2 - 2XE(X) + E(X)\^2) \\\\ &= E(X\^2 - E(2E(X)X) + E(E(X)\^2)) \\\\
&= E(X\^2) - E(2 \\mu X) + E(\\mu\^2) \\\\ &= E(X\^2) - 2 \\mu E(X) +
\\mu\^2 \\\\ &= E(X\^2) - 2\\mu\^2 + \\mu\^2 \\\\ &= E(X\^2) - \\mu\^2
\\\\ &= E(X\^2) - E(X)\^2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28X%29%20%26%3D%20E%5Cleft%28%20%28X%20-%20E%28X%29%29%5E2%20%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20E%20%28%20X%5E2%20-%202XE%28X%29%20%2B%20E%28X%29%5E2%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20E%28X%5E2%20-%20E%282E%28X%29X%29%20%2B%20E%28E%28X%29%5E2%29%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20E%28X%5E2%29%20-%20E%282%20%5Cmu%20X%29%20%2B%20E%28%5Cmu%5E2%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20E%28X%5E2%29%20-%202%20%5Cmu%20E%28X%29%20%2B%20%5Cmu%5E2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20E%28X%5E2%29%20-%202%5Cmu%5E2%20%2B%20%5Cmu%5E2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20E%28X%5E2%29%20-%20%5Cmu%5E2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20E%28X%5E2%29%20-%20E%28X%29%5E2%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        Var(X) &= E\left( (X - E(X))^2 \right) \\
                        &= E ( X^2 - 2XE(X) + E(X)^2) \\
                        &= E(X^2 - E(2E(X)X) + E(E(X)^2)) \\
                        &= E(X^2) - E(2 \mu X) + E(\mu^2) \\
                        &= E(X^2) - 2 \mu E(X) + \mu^2 \\
                        &= E(X^2) - 2\mu^2 + \mu^2 \\
                        &= E(X^2) - \mu^2 \\
                        &= E(X^2) - E(X)^2
                    \end{aligned}")\

Where ![E(X\^2) = \\sum\_x x\^2
f(x)](http://chart.apis.google.com/chart?cht=tx&chl=E%28X%5E2%29%20%3D%20%5Csum_x%20x%5E2%20f%28x%29 "E(X^2) = \sum_x x^2 f(x)").

#### Example {#ssub:example}

We can show this with an example about winning the lottery.

Suppose ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") is the
winnings on the lottery, and ![R(X) = \\{ 0, 20, 300
\\}](http://chart.apis.google.com/chart?cht=tx&chl=R%28X%29%20%3D%20%5C%7B%200%2C%2020%2C%20300%20%5C%7D "R(X) = \{ 0, 20, 300 \}").

\
![\\begin{aligned} P(X = 300) &= \\frac{1}{ {12 \\choose 3}} \\\\ &=
\\frac{1}{220} \\\\ P(X = 20) &= \\frac{{3 \\choose 2} {9 \\choose
1}}{{12 \\choose 3}} \\\\ &= \\frac{27}{220} \\\\ P(X = 0) &= 1 - P(X =
300) - P(X = 20) \\\\ &= \\frac{192}{220}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3D%20300%29%20%26%3D%20%5Cfrac%7B1%7D%7B%20%7B12%20%5Cchoose%203%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7B220%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3D%2020%29%20%26%3D%20%5Cfrac%7B%7B3%20%5Cchoose%202%7D%20%7B9%20%5Cchoose%201%7D%7D%7B%7B12%20%5Cchoose%203%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B27%7D%7B220%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3D%200%29%20%26%3D%201%20-%20P%28X%20%3D%20300%29%20-%20P%28X%20%3D%2020%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B192%7D%7B220%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                            P(X = 300) &= \frac{1}{ {12 \choose 3}} \\
                            &= \frac{1}{220} \\
                            P(X = 20) &= \frac{{3 \choose 2} {9 \choose 1}}{{12 \choose 3}} \\
                            &= \frac{27}{220} \\
                            P(X = 0) &= 1 - P(X = 300) - P(X = 20) \\
                            &= \frac{192}{220}
                        \end{aligned}")\

Continuing this example, we can derive expected (average) value of
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X"):

\
![\\begin{aligned} \\mu\_X &= E(X) \\\\ &= \\sum\_{x \\in R(R)} x f(x)
\\\\ &= \\ldots \\\\ &= 3.8181
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmu_X%20%26%3D%20E%28X%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_%7Bx%20%5Cin%20R%28R%29%7D%20x%20f%28x%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cldots%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%203.8181%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                            \mu_X &= E(X) \\
                            &= \sum_{x \in R(R)} x f(x) \\
                            &= \ldots \\
                            &= 3.8181
                        \end{aligned}")\

We can also calculate the variance of the random variable:

\
![\\begin{aligned} Var(X) &= E(X\^2) - E(X)\^2 \\\\ &= 458.6033-
3.8181\^2 \\\\ &= 443.6033
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28X%29%20%26%3D%20E%28X%5E2%29%20-%20E%28X%29%5E2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20458.6033-%203.8181%5E2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20443.6033%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                            Var(X) &= E(X^2) - E(X)^2 \\
                            &= 458.6033- 3.8181^2 \\
                            &= 443.6033
                        \end{aligned}")\

We also know that the standard deviation ![\\sigma = \\sqrt{\\sigma\^2}
=
\\sqrt{Var(X)}](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma%20%3D%20%5Csqrt%7B%5Csigma%5E2%7D%20%3D%20%5Csqrt%7BVar%28X%29%7D "\sigma = \sqrt{\sigma^2} = \sqrt{Var(X)}").

Discrete Probability Distributions {#cha:discrete_probability_distributions}
==================================

To describe and infer from data, we generalize problem types and apply
probability distributions to solve problem.

Bernoulli Distribution {#sec:bernoulli_distribution}
----------------------

For repeated binary trials of an experiment where the probability of
success is the same each trial and outcomes are independent, then we can
use a Bernoulli Distribution to model the data.

We say that ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X")
follows a Bernoulli distribution (![X \\sim
Bernoulli(p)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Bernoulli%28p%29 "X \sim Bernoulli(p)"))
where ![p](http://chart.apis.google.com/chart?cht=tx&chl=p "p") is the
probability of success:

\
![\\begin{aligned} f(x) &= \\left\\{ \\begin{array}{lr} p & : \\text{if
} x = 1 \\\\ (1-p) & : \\text{if } x = 0 \\end{array} \\right.
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28x%29%20%26%3D%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20p%20%26%20%3A%20%5Ctext%7Bif%20%7D%20x%20%3D%201%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%281-p%29%20%26%20%3A%20%5Ctext%7Bif%20%7D%20x%20%3D%200%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                   f(x) &= \left\{
                     \begin{array}{lr}
                       p & : \text{if } x = 1 \\
                       (1-p) & : \text{if } x = 0
                     \end{array}
                   \right.
                \end{aligned}")\

Variance and expected values:

\
![\\begin{aligned} E(X) &= p \\\\ Var(X) &= p (1 - p) = p - p\^2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%29%20%26%3D%20p%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28X%29%20%26%3D%20p%20%281%20-%20p%29%20%3D%20p%20-%20p%5E2%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                      E(X) &= p \\
                      Var(X) &= p (1 - p) = p - p^2
                 \end{aligned}")\

Binomial Distribution {#sec:binomial_distribution}
---------------------

We perform a sequence of
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") independent
Bernoulli trials. Each trial has binary outcomes (“success” vs
“failure”), and each trial is independent and has the same probability
of success.

Let ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") be the
number of successes obtained from
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") Bernoulli
trials, then ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X")
follows a Binomial distribution ![X \\sim Bino(n,
p)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Bino%28n%2C%20p%29 "X \sim Bino(n, p)").

\
![\\begin{aligned} f(x) &= {n \\choose x} p\^x (1-p)\^{n-x} \\\\ x &\\in
[0, 1, \\cdots n]
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28x%29%20%26%3D%20%7Bn%20%5Cchoose%20x%7D%20p%5Ex%20%281-p%29%5E%7Bn-x%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20x%20%26%5Cin%20%5B0%2C%201%2C%20%5Ccdots%20n%5D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    f(x) &= {n \choose x} p^x (1-p)^{n-x} \\
                    x &\in [0, 1, \cdots n]
                \end{aligned}")\

Variance and expected values:

\
![\\begin{aligned} E(X) &= np \\\\ Var(x) &= np(1 - p)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%29%20%26%3D%20np%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28x%29%20%26%3D%20np%281%20-%20p%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    E(X) &= np \\
                    Var(x) &= np(1 - p)
                \end{aligned}")\

#### Example 1 {#ssub:example_1}

If we are measuring the number of successes,

\
![\\begin{aligned} P(\\text{\\\# of successes}) &= P(X = 0) \\\\ &= f(0)
\\\\ &= { n \\choose 0} p\^0 (p - 1)\^{n-0} \\\\ &= (p - 1)\^n
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28%5Ctext%7B%5C%23%20of%20successes%7D%29%20%26%3D%20P%28X%20%3D%200%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20f%280%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%7B%20n%20%5Cchoose%200%7D%20p%5E0%20%28p%20-%201%29%5E%7Bn-0%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%28p%20-%201%29%5En%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(\text{\# of successes}) &= P(X = 0) \\
                        &= f(0) \\
                        &= { n \choose 0} p^0 (p - 1)^{n-0} \\
                        &= (p - 1)^n
                    \end{aligned}")\

#### Example 2 {#ssub:example_2}

Let ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") be the
number of hard drives which fail.

Suppose we have
![30](http://chart.apis.google.com/chart?cht=tx&chl=30 "30") hard
drives, each with an individual probability of failure of
![0.05](http://chart.apis.google.com/chart?cht=tx&chl=0.05 "0.05"). We
can say that ![X \\sim Bino(n=30,
p=0.05)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Bino%28n%3D30%2C%20p%3D0.05%29 "X \sim Bino(n=30, p=0.05)").

We can use this distribution to prove a few things:

\
![\\begin{aligned} P(X\\ge 6) &= 1 - P(X \\le 5) \\\\ &= 1 -
\\sum\_{x=0}\^5 {30 \\choose x} 0.05\^x (1 - 0.05)\^{30 - x}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%5Cge%206%29%20%26%3D%201%20-%20P%28X%20%5Cle%205%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201%20-%20%5Csum_%7Bx%3D0%7D%5E5%20%7B30%20%5Cchoose%20x%7D%200.05%5Ex%20%281%20-%200.05%29%5E%7B30%20-%20x%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(X\ge 6) &= 1 - P(X \le 5) \\
                                  &= 1 - \sum_{x=0}^5 {30 \choose x} 0.05^x (1 - 0.05)^{30 - x}
                    \end{aligned}")\

Binomial Theorem {#sec:binomial_theorem}
----------------

For any integer ![n \>
0](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3E%200 "n > 0")
and real numbers
![a](http://chart.apis.google.com/chart?cht=tx&chl=a "a") and
![b](http://chart.apis.google.com/chart?cht=tx&chl=b "b"):

\
![\\begin{aligned} (a + b)\^n &= \\sum\_{x = 0}\^{n} {n \\choose x} a\^x
b\^{n-x}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%28a%20%2B%20b%29%5En%20%26%3D%20%5Csum_%7Bx%20%3D%200%7D%5E%7Bn%7D%20%7Bn%20%5Cchoose%20x%7D%20a%5Ex%20b%5E%7Bn-x%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    (a + b)^n &= \sum_{x = 0}^{n} {n \choose x} a^x b^{n-x}
                \end{aligned}")\

Exponential Sequences and Series {#sec:exponential_sequences_and_series}
--------------------------------

Sequence representation of
![e\^x](http://chart.apis.google.com/chart?cht=tx&chl=e%5Ex "e^x"):

\
![\\begin{aligned} e\^x &= \\lim\_{n \\to \\infty} (1 + \\frac{x}{n})\^n
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20e%5Ex%20%26%3D%20%5Clim_%7Bn%20%5Cto%20%5Cinfty%7D%20%281%20%2B%20%5Cfrac%7Bx%7D%7Bn%7D%29%5En%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    e^x &= \lim_{n \to \infty} (1 + \frac{x}{n})^n
                \end{aligned}")\

Maclaurin series expansion:

\
![\\begin{aligned} e\^x &= 1 + \\frac{x}{1!} + \\frac{x\^2}{2!} \\\\ &=
\\sum\_{i=0}\^{\\infty} \\frac{x\^i}{i!}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20e%5Ex%20%26%3D%201%20%2B%20%5Cfrac%7Bx%7D%7B1%21%7D%20%2B%20%5Cfrac%7Bx%5E2%7D%7B2%21%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_%7Bi%3D0%7D%5E%7B%5Cinfty%7D%20%5Cfrac%7Bx%5Ei%7D%7Bi%21%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    e^x &= 1 + \frac{x}{1!} + \frac{x^2}{2!} \\
                    &= \sum_{i=0}^{\infty} \frac{x^i}{i!}
                \end{aligned}")\

### Gas-Station Example {#sub:gas_station_example}

\
![\\begin{aligned} E(X) &= np \\\\ &= \\frac{24}{15} \\\\ &= 15 \\\\ P(X
= 10) &= {24 \\choose 10 } (\\frac{15}{24})\^{10} (1 - \\frac{15}{24})\^
14 \\\\ &\\approx 0.019
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%29%20%26%3D%20np%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B24%7D%7B15%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%2015%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3D%2010%29%20%26%3D%20%7B24%20%5Cchoose%2010%20%7D%20%28%5Cfrac%7B15%7D%7B24%7D%29%5E%7B10%7D%20%281%20-%20%5Cfrac%7B15%7D%7B24%7D%29%5E%2014%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Capprox%200.019%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        E(X) &= np \\
                        &= \frac{24}{15} \\
                        &= 15 \\
                        P(X = 10) &= {24 \choose 10 } (\frac{15}{24})^{10} (1 - \frac{15}{24})^ 14 \\
                        &\approx 0.019
                    \end{aligned}")\

Let ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") be the
total number of customers. Let
![Y\_i](http://chart.apis.google.com/chart?cht=tx&chl=Y_i "Y_i") be
Bernoulli![(p)](http://chart.apis.google.com/chart?cht=tx&chl=%28p%29 "(p)"),
1 if there was a customer in the
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i")th hour (![i
\\in
\\{1...24\\}](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cin%20%5C%7B1...24%5C%7D "i \in \{1...24\}")).

\
![\\begin{aligned} X \\sim \\sum\_{i=1}\^{24} Y\_i
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20X%20%5Csim%20%5Csum_%7Bi%3D1%7D%5E%7B24%7D%20Y_i%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        X \sim \sum_{i=1}^{24} Y_i
                    \end{aligned}")\

**How do we make this more accurate?**

-   What if we moved from hours to minutes?

    List ![Z\_i \\sim
    \\text{Bernoulli}(\\frac{15}{1440})](http://chart.apis.google.com/chart?cht=tx&chl=Z_i%20%5Csim%20%5Ctext%7BBernoulli%7D%28%5Cfrac%7B15%7D%7B1440%7D%29 "Z_i \sim \text{Bernoulli}(\frac{15}{1440})"),
    ![i \\in
    \\{1...1440\\}](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cin%20%5C%7B1...1440%5C%7D "i \in \{1...1440\}").

    \
    ![\\begin{aligned} X &= \\sum\_{i=1}\^{1440} Z\_i \\\\ E(X) &=
    \\frac{1440 \* 15}{1440} \\\\ &= 15 \\\\ P(X = 10) &= {1440 \\choose
    10} (\\frac{15}{1440})\^{10} (\\frac{1425}{1440})\^{1440-10}
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20X%20%26%3D%20%5Csum_%7Bi%3D1%7D%5E%7B1440%7D%20Z_i%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%29%20%26%3D%20%5Cfrac%7B1440%20%2A%2015%7D%7B1440%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%2015%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3D%2010%29%20%26%3D%20%7B1440%20%5Cchoose%2010%7D%20%28%5Cfrac%7B15%7D%7B1440%7D%29%5E%7B10%7D%20%28%5Cfrac%7B1425%7D%7B1440%7D%29%5E%7B1440-10%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                                    X &= \sum_{i=1}^{1440} Z_i \\
                                    E(X) &= \frac{1440 * 15}{1440} \\
                                    &= 15 \\
                                    P(X = 10) &= {1440 \choose 10} (\frac{15}{1440})^{10} (\frac{1425}{1440})^{1440-10}
                                \end{aligned}")\

I guess that’s better. **What if we took the limit?**

![\\lambda
=](http://chart.apis.google.com/chart?cht=tx&chl=%5Clambda%20%3D "\lambda =")
15 customers per day. ![X =
](http://chart.apis.google.com/chart?cht=tx&chl=X%20%3D%20 "X = ") the
number of customers

\
![\\begin{aligned} X &\\sim (n, \\frac{\\lambda}{n}) \\\\ \\to f(x) &=
{n \\choose x} (\\frac{\\lambda}{n}) \^ x (1 - \\frac{\\lambda}{n})\^{n
- x} \\\\ \\text{so: }& \\lim\_{n \\to \\infty} {n \\choose x}
(\\frac{\\lambda}{n}) \^ x (1 - \\frac{\\lambda}{n})\^{n - x} \\\\ &=
\\frac{n!}{x! (n-x)\~} \\frac{\\lambda\^x}{n\^x}
(1-\\frac{\\lambda}{n})\^n(1 - \\frac{\\lambda}{n}) \^x \\\\ &=
\\frac{\\lambda \^x e\^ {-\\lambda}}{x!}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20X%20%26%5Csim%20%28n%2C%20%5Cfrac%7B%5Clambda%7D%7Bn%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cto%20f%28x%29%20%26%3D%20%7Bn%20%5Cchoose%20x%7D%20%28%5Cfrac%7B%5Clambda%7D%7Bn%7D%29%20%5E%20x%20%281%20-%20%5Cfrac%7B%5Clambda%7D%7Bn%7D%29%5E%7Bn%20-%20x%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7Bso%3A%20%7D%26%20%5Clim_%7Bn%20%5Cto%20%5Cinfty%7D%20%20%7Bn%20%5Cchoose%20x%7D%20%28%5Cfrac%7B%5Clambda%7D%7Bn%7D%29%20%5E%20x%20%281%20-%20%5Cfrac%7B%5Clambda%7D%7Bn%7D%29%5E%7Bn%20-%20x%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7Bn%21%7D%7Bx%21%20%28n-x%29~%7D%20%5Cfrac%7B%5Clambda%5Ex%7D%7Bn%5Ex%7D%20%281-%5Cfrac%7B%5Clambda%7D%7Bn%7D%29%5En%281%20-%20%5Cfrac%7B%5Clambda%7D%7Bn%7D%29%20%5Ex%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B%5Clambda%20%5Ex%20e%5E%20%7B-%5Clambda%7D%7D%7Bx%21%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        X &\sim (n, \frac{\lambda}{n}) \\
                        \to f(x) &= {n \choose x} (\frac{\lambda}{n}) ^ x (1 - \frac{\lambda}{n})^{n - x} \\
                        \text{so: }& \lim_{n \to \infty}  {n \choose x} (\frac{\lambda}{n}) ^ x (1 - \frac{\lambda}{n})^{n - x} \\
                        &= \frac{n!}{x! (n-x)~} \frac{\lambda^x}{n^x} (1-\frac{\lambda}{n})^n(1 - \frac{\lambda}{n}) ^x \\
                        &= \frac{\lambda ^x e^ {-\lambda}}{x!}
                    \end{aligned}")\

Poisson Distribution {#sec:poisson_distribution}
--------------------

The Poisson Distribution (or Poisson Process) describes a process where
we have guaranteed individuality (that events are guaranteed to occur at
unique times), and homogeneity (events occur at a uniform
rate[^3^](#fn3)
![\\lambda](http://chart.apis.google.com/chart?cht=tx&chl=%5Clambda "\lambda")).

When events occur with an average rate of
![\\lambda](http://chart.apis.google.com/chart?cht=tx&chl=%5Clambda "\lambda")
per unit of time, we use the random variable
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") to represent
the number of events which occur in
![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t") units of time,
then ![X \\sim \\text{Poisson}(\\lambda,
t)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20%5Ctext%7BPoisson%7D%28%5Clambda%2C%20t%29 "X \sim \text{Poisson}(\lambda, t)").
We then have:

\
![\\begin{aligned} f(x) &= \\frac{e\^{-\\lambda t} (\\lambda t)\^x}{x!}
\\\\ E(X) &= \\lambda t \\\\ Var(x) &= \\lambda t
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28x%29%20%26%3D%20%5Cfrac%7Be%5E%7B-%5Clambda%20t%7D%20%28%5Clambda%20t%29%5Ex%7D%7Bx%21%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%29%20%26%3D%20%5Clambda%20t%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28x%29%20%26%3D%20%5Clambda%20t%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    f(x) &= \frac{e^{-\lambda t} (\lambda t)^x}{x!} \\
                    E(X) &= \lambda t \\
                    Var(x) &= \lambda t
                \end{aligned}")\

### 911 Emergency Example {#sub:911_emergency_example}

Suppose that 911 calls follow a Poisson process with an average of 3
calls per minute. Find the probability there will be:

-   6 calls in the next 2.5 minutes

-   2 calls in the next minute, given that 6 calls occur in the next 2.5
    minutes

Start with the first one:

Basically, we have:TODO: complete this.

\
![\\begin{aligned} \\frac {\\sum\_{i=0}\^{6} P(X = i)P(X = 6-i)}{}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%7B%5Csum_%7Bi%3D0%7D%5E%7B6%7D%20P%28X%20%3D%20i%29P%28X%20%3D%206-i%29%7D%7B%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \frac
                        {\sum_{i=0}^{6} P(X = i)P(X = 6-i)}{}
                    \end{aligned}")\

HyperGeometric Distribution {#sec:hypergeometric_distribution}
---------------------------

When we have two distinct object types of
![N](http://chart.apis.google.com/chart?cht=tx&chl=N "N") objects
totaling ![r](http://chart.apis.google.com/chart?cht=tx&chl=r "r")
successes and ![N -
r](http://chart.apis.google.com/chart?cht=tx&chl=N%20-%20r "N - r")
failures, we sample
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") objects
without repetition.

For ![X \\sim Hyper(N, r,
n)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Hyper%28N%2C%20r%2C%20n%29 "X \sim Hyper(N, r, n)"),
where ![R(X) = \\{ 0, \\ldots, \\min(r, n)
\\}](http://chart.apis.google.com/chart?cht=tx&chl=R%28X%29%20%3D%20%5C%7B%20%200%2C%20%5Cldots%2C%20%5Cmin%28r%2C%20n%29%20%5C%7D "R(X) = \{  0, \ldots, \min(r, n) \}"),
we have:

\
![\\begin{aligned} f(x) &= \\frac{{r \\choose x} {N - r \\choose n -
x}}{{N \\choose n}} \\\\ E(X) &= \\frac{nr}{N} \\\\ Var(X) &=
\\frac{nr(N - r)(N - n)}{N\^2 (N - 1)}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28x%29%20%26%3D%20%5Cfrac%7B%7Br%20%5Cchoose%20x%7D%20%7BN%20-%20r%20%5Cchoose%20n%20-%20x%7D%7D%7B%7BN%20%5Cchoose%20n%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%29%20%26%3D%20%5Cfrac%7Bnr%7D%7BN%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28X%29%20%26%3D%20%5Cfrac%7Bnr%28N%20-%20r%29%28N%20-%20n%29%7D%7BN%5E2%20%28N%20-%201%29%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    f(x) &= \frac{{r \choose x} {N - r \choose n - x}}{{N \choose n}} \\
                    E(X) &= \frac{nr}{N} \\
                    Var(X) &= \frac{nr(N - r)(N - n)}{N^2 (N - 1)}
                \end{aligned}")\

Geometric Distribution {#sec:geometric_distribution}
----------------------

When we have repeated Bernoulli trials(see
Section [sec:bernoulli~d~istribution]) until success, we can define the
value of the random variable
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") as ![X \\sim
Geometric(p)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Geometric%28p%29 "X \sim Geometric(p)"),
where ![p](http://chart.apis.google.com/chart?cht=tx&chl=p "p") is the
probability of success.

\
![\\begin{aligned} R(X) &= \\{1, \\ldots \\} \\\\ f(x) &= p(1 - p)\^{x -
1} \\\\ E(X) &+ \\frac{1}{p} \\\\ Var(X) &= \\frac{1 - p}{p\^2} \\\\ P(X
\\le x) &= 1 - P(X \> x) \\\\ &= 1 - (1 - p)\^x
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20R%28X%29%20%26%3D%20%5C%7B1%2C%20%5Cldots%20%5C%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28x%29%20%26%3D%20p%281%20-%20p%29%5E%7Bx%20-%201%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%29%20%26%2B%20%5Cfrac%7B1%7D%7Bp%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28X%29%20%26%3D%20%5Cfrac%7B1%20-%20p%7D%7Bp%5E2%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%5Cle%20x%29%20%26%3D%201%20-%20P%28X%20%3E%20x%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201%20-%20%281%20-%20p%29%5Ex%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    R(X) &= \{1, \ldots \} \\
                    f(x) &= p(1 - p)^{x - 1} \\
                    E(X) &+ \frac{1}{p} \\
                    Var(X) &= \frac{1 - p}{p^2} \\
                    P(X \le x) &= 1 - P(X > x) \\
                        &= 1 - (1 - p)^x
                \end{aligned}")\

Conceptually, we can describe this as
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") is the number
of trials until the first success. In a string of `ffft`[^4^](#fn4), we
have ![P(X = 4) =
(1-p)(1-p)(1-p)p](http://chart.apis.google.com/chart?cht=tx&chl=P%28X%20%3D%204%29%20%3D%20%281-p%29%281-p%29%281-p%29p "P(X = 4) = (1-p)(1-p)(1-p)p").

#### Example {#ssub:example}

Roll up the rim claims that the probability of winning is
![\\frac{1}{6}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B6%7D "\frac{1}{6}").

Since every play is an (almost) unrelated Bernoulli trial, and ![X \\sim
Geometric(1/6)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Geometric%281%2F6%29 "X \sim Geometric(1/6)"),
we can determine the some statistics on prizes.

\
![\\begin{aligned} P(X = 10) &= p(1-p)\^9 \\\\ &= \\frac{1}{6}
(\\frac{5}{6})\^9 \\\\ &= 0.03 \\\\ E(X) &= \\frac{1}{\\frac{1}{6}} \\\\
&= 6
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3D%2010%29%20%26%3D%20p%281-p%29%5E9%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7B6%7D%20%28%5Cfrac%7B5%7D%7B6%7D%29%5E9%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.03%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%29%20%26%3D%20%5Cfrac%7B1%7D%7B%5Cfrac%7B1%7D%7B6%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%206%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(X = 10) &= p(1-p)^9 \\
                        &= \frac{1}{6} (\frac{5}{6})^9 \\
                        &= 0.03 \\
                        E(X) &= \frac{1}{\frac{1}{6}} \\
                        &= 6
                    \end{aligned}")\

Continuous Probability Distributions {#cha:continuous_probability_distributions}
====================================

Continuous Sample Space {#sec:continuous_sample_space}
-----------------------

We want to determine the probability of an event occurring in a sample
space on intervals ![(a,
b)](http://chart.apis.google.com/chart?cht=tx&chl=%28a%2C%20b%29 "(a, b)").
In equally likely events, the probability of being in the interval is
proportional to the length of the interval.

We use the notation ![P((a,
b))](http://chart.apis.google.com/chart?cht=tx&chl=P%28%28a%2C%20b%29%29 "P((a, b))")
to denote the probability that the events occur in the interval.

**Example:**

Given that ![P(S) = P((0, 200)) =
1](http://chart.apis.google.com/chart?cht=tx&chl=P%28S%29%20%3D%20P%28%280%2C%20200%29%29%20%3D%201 "P(S) = P((0, 200)) = 1"),
and ![0 \\le a \< b \\le
200](http://chart.apis.google.com/chart?cht=tx&chl=0%20%5Cle%20a%20%3C%20b%20%5Cle%20200 "0 \le a < b \le 200"),
we can say:

\
![\\begin{aligned} P((a, b)) &= \\frac{b - a}{200}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28%28a%2C%20b%29%29%20%26%3D%20%5Cfrac%7Bb%20-%20a%7D%7B200%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    P((a, b)) &= \frac{b - a}{200}
                \end{aligned}")\

Similarly, given ![0 \\le a \< b \< c \<
d](http://chart.apis.google.com/chart?cht=tx&chl=0%20%5Cle%20a%20%3C%20b%20%3C%20c%20%3C%20d "0 \le a < b < c < d"),
we can say:

\
![\\begin{aligned} P( (a, b) \\cup (c, d)) &= \\frac{(b - a) + (d -
c)}{200}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28%20%28a%2C%20b%29%20%5Ccup%20%28c%2C%20d%29%29%20%26%3D%20%5Cfrac%7B%28b%20-%20a%29%20%2B%20%28d%20-%20c%29%7D%7B200%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    P( (a, b) \cup (c, d)) &= \frac{(b - a) + (d - c)}{200}
                \end{aligned}")\

Continuous Random Variables {#sec:continuous_random_variables}
---------------------------

A random variable
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") is a function
from the sample space
![S](http://chart.apis.google.com/chart?cht=tx&chl=S "S") to real
numbers ![X : S \\to
\\mathbb{R}](http://chart.apis.google.com/chart?cht=tx&chl=X%20%3A%20S%20%5Cto%20%5Cmathbb%7BR%7D "X : S \to \mathbb{R}").
Given that the range of
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") is represented
as
![R(X)](http://chart.apis.google.com/chart?cht=tx&chl=R%28X%29 "R(X)")
is continuous, then individual elements ![x \\in
R(X)](http://chart.apis.google.com/chart?cht=tx&chl=x%20%5Cin%20R%28X%29 "x \in R(X)")
must have ![0](http://chart.apis.google.com/chart?cht=tx&chl=0 "0")
probability:

\
![\\begin{aligned} P(X = x) &= 0 \\\\ P(a \\le X \\le b) &= P(a \< X \<
b)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3D%20x%29%20%26%3D%200%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28a%20%5Cle%20X%20%5Cle%20b%29%20%26%3D%20P%28a%20%3C%20X%20%3C%20b%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    P(X = x) &= 0 \\
                    P(a \le X \le b) &= P(a < X < b)
                \end{aligned}")\

**Example:**

We have a few examples of continuous random variables:

-   Radius of a dart from the center of a dart board.

-   Height of a randomly selected person[^5^](#fn5).

-   Time between events during a Poisson process.

-   Age of a randomly selected person[^6^](#fn6).

Probability Density Function (PDF) {#sec:probability_density_function_pdf}
----------------------------------

The probability density function (pdf) of a continuous random variable
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") denoted
![f\_X(x)](http://chart.apis.google.com/chart?cht=tx&chl=f_X%28x%29 "f_X(x)")
describes the probability that
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") takes on the
value in an interval ![(a, b) \\in
R(X)](http://chart.apis.google.com/chart?cht=tx&chl=%28a%2C%20b%29%20%5Cin%20R%28X%29 "(a, b) \in R(X)").

\
![\\begin{aligned} \\int\_a\^b f(x) dx &= P(a \< X \< b)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cint_a%5Eb%20f%28x%29%20dx%20%26%3D%20P%28a%20%3C%20X%20%3C%20b%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \int_a^b f(x) dx &= P(a < X < b)
                \end{aligned}")\

Proper PDFs on an interval ![(a,
b)](http://chart.apis.google.com/chart?cht=tx&chl=%28a%2C%20b%29 "(a, b)")
require ![\\int\_a\^b f(x) dx =
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Cint_a%5Eb%20f%28x%29%20dx%20%3D%201 "\int_a^b f(x) dx = 1")
and ![f(x) \\ge
0](http://chart.apis.google.com/chart?cht=tx&chl=f%28x%29%20%5Cge%200 "f(x) \ge 0").

#### Example 1 {#ssub:example_1}

Let ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") be the
distance to an accident on a highway.

What is the size of each interval if I preak ![(0,
10)](http://chart.apis.google.com/chart?cht=tx&chl=%280%2C%2010%29 "(0, 10)")
into ![N](http://chart.apis.google.com/chart?cht=tx&chl=N "N") equal
intervals?

\
![\\begin{aligned} \\text{length} &= \\Delta x \\\\ &= \\frac{10}{N}
\\\\ P(0 \< X \< 10) &= P(0 \< X \< 5) + P(5 \< X \< 10) \\\\ &=
\\sum\_{i=1}\^{10} P(i - 1 \< X \< i) \\\\ &= \\sum\_{i=1}\^{10}
\\frac{i - (i - 1)}{200} \\\\ &= \\sum\_{x=1}\^{10} \\frac{1}{200} \\\\
&= \\frac{10}{200} \\\\ &= \\frac{1}{20} \\\\ \\lim\_{N \\to \\infty}
\\int\_0\^{10} \\left( \\frac{1}{200} \\right) dx &= \\left.
\\frac{x}{200} \\right|\_0\^{10} \\\\ &= \\frac{10}{200}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7Blength%7D%20%26%3D%20%5CDelta%20x%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B10%7D%7BN%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%280%20%3C%20X%20%3C%2010%29%20%26%3D%20P%280%20%3C%20X%20%3C%205%29%20%2B%20P%285%20%3C%20X%20%3C%2010%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_%7Bi%3D1%7D%5E%7B10%7D%20P%28i%20-%201%20%3C%20X%20%3C%20i%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_%7Bi%3D1%7D%5E%7B10%7D%20%5Cfrac%7Bi%20-%20%28i%20-%201%29%7D%7B200%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_%7Bx%3D1%7D%5E%7B10%7D%20%5Cfrac%7B1%7D%7B200%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B10%7D%7B200%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7B20%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Clim_%7BN%20%5Cto%20%5Cinfty%7D%20%5Cint_0%5E%7B10%7D%20%5Cleft%28%20%5Cfrac%7B1%7D%7B200%7D%20%5Cright%29%20dx%20%26%3D%20%5Cleft.%20%5Cfrac%7Bx%7D%7B200%7D%20%5Cright%7C_0%5E%7B10%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B10%7D%7B200%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \text{length} &= \Delta x \\
                        &= \frac{10}{N} \\
                        P(0 < X < 10) &= P(0 < X < 5) + P(5 < X < 10) \\
                        &= \sum_{i=1}^{10} P(i - 1 < X < i) \\
                        &= \sum_{i=1}^{10} \frac{i - (i - 1)}{200} \\
                        &= \sum_{x=1}^{10} \frac{1}{200} \\
                        &= \frac{10}{200} \\
                        &= \frac{1}{20} \\
                        \lim_{N \to \infty} \int_0^{10} \left( \frac{1}{200} \right) dx &= \left. \frac{x}{200} \right|_0^{10} \\
                        &= \frac{10}{200}
                    \end{aligned}")\

#### Example 2 {#ssub:example_2}

Solve for ![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") such
that
![f(x)](http://chart.apis.google.com/chart?cht=tx&chl=f%28x%29 "f(x)")
is a proper pdf:

\
![\\begin{aligned} f(x) &= kx\^3 \\\\ R(X) &\\in (3, 9)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28x%29%20%26%3D%20kx%5E3%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20R%28X%29%20%26%5Cin%20%283%2C%209%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        f(x) &= kx^3 \\
                        R(X) &\in (3, 9)
                    \end{aligned}")\

We know that the integral must equal 1:

\
![\\begin{aligned} \\int\_3\^9 f(x) dx &= \\int\_3\^9 k x\^3 dx \\\\ &=
\\left. \\frac{k x\^4}{4} \\right|\_3\^9 \\\\ &= \\frac{k 9\^4}{4} -
\\frac{k 3\^4}{4} \\\\ &= 1 \\\\ \\implies k &= 4
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cint_3%5E9%20f%28x%29%20dx%20%26%3D%20%5Cint_3%5E9%20k%20x%5E3%20dx%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cleft.%20%5Cfrac%7Bk%20x%5E4%7D%7B4%7D%20%5Cright%7C_3%5E9%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7Bk%209%5E4%7D%7B4%7D%20-%20%5Cfrac%7Bk%203%5E4%7D%7B4%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cimplies%20k%20%26%3D%204%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \int_3^9 f(x) dx &= \int_3^9 k x^3 dx \\
                        &= \left. \frac{k x^4}{4} \right|_3^9 \\
                        &= \frac{k 9^4}{4} - \frac{k 3^4}{4} \\
                        &= 1 \\
                        \implies k &= 4
                    \end{aligned}")\

Cumulative Distribution Function (CDF) {#sec:cumulative_distribution_function_cdf}
--------------------------------------

The cumulative distribution function (cdf) of a continuous random
variable ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X")
denoted
![F(x)](http://chart.apis.google.com/chart?cht=tx&chl=F%28x%29 "F(x)")
describes the probability that:

\
![\\begin{aligned} F(x) &= P(X \< x)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20F%28x%29%20%26%3D%20P%28X%20%3C%20x%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    F(x) &= P(X < x)
                \end{aligned}")\

The properties exist:

1.  ![F(- \\infty) =
    0](http://chart.apis.google.com/chart?cht=tx&chl=F%28-%20%5Cinfty%29%20%3D%200 "F(- \infty) = 0")

2.  ![F(\\infty) =
    1](http://chart.apis.google.com/chart?cht=tx&chl=F%28%5Cinfty%29%20%3D%201 "F(\infty) = 1")

3.  ![F(x)](http://chart.apis.google.com/chart?cht=tx&chl=F%28x%29 "F(x)")
    is non-decreasing

Relationship Between PDF and CDF {#sec:relationship_between_pdf_and_cdf}
--------------------------------

\
![\\begin{aligned} \\int\_a\^b f(x)dx &= P(a \< X \< b) \\\\ &= P(X \<
b) - P(X \< a) \\\\ &= F(b) - F(a) \\\\ \\to \\frac{d F(x)}{dx} &= f(x)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cint_a%5Eb%20f%28x%29dx%20%26%3D%20P%28a%20%3C%20X%20%3C%20b%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28X%20%3C%20b%29%20-%20P%28X%20%3C%20a%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20F%28b%29%20-%20F%28a%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cto%20%5Cfrac%7Bd%20F%28x%29%7D%7Bdx%7D%20%26%3D%20f%28x%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \int_a^b f(x)dx &= P(a < X < b) \\
                    &= P(X < b) - P(X < a) \\
                    &= F(b) - F(a) \\
                    \to \frac{d F(x)}{dx} &= f(x)
                \end{aligned}")\

Expected Value {#sec:expected_value}
--------------

The **mean** or **expected value** of a continuous random variable
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") is defined as:

\
![\\begin{aligned} E(X) &= \\int\_x xf(x) dx \\\\ &= \\mu
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%29%20%26%3D%20%5Cint_x%20xf%28x%29%20dx%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cmu%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    E(X) &= \int_x xf(x) dx \\
                    &= \mu
                \end{aligned}")\

For given real numbers
![a](http://chart.apis.google.com/chart?cht=tx&chl=a "a") and
![b](http://chart.apis.google.com/chart?cht=tx&chl=b "b"), random
variables ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") and
![Y](http://chart.apis.google.com/chart?cht=tx&chl=Y "Y"), and a
function
![g(x)](http://chart.apis.google.com/chart?cht=tx&chl=g%28x%29 "g(x)"),
these two properties hold:

\
![\\begin{aligned} E(g(x)) &= \\int\_x g(x) f(x) dx \\\\ E(aX + bY) &= a
E(X) + b E(Y)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28g%28x%29%29%20%26%3D%20%5Cint_x%20g%28x%29%20f%28x%29%20dx%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28aX%20%2B%20bY%29%20%26%3D%20a%20E%28X%29%20%2B%20b%20E%28Y%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    E(g(x)) &= \int_x g(x) f(x) dx \\
                    E(aX + bY) &= a E(X) + b E(Y)
                \end{aligned}")\

Variance {#sec:variance}
--------

Variance is the expected difference from the mean:

\
![\\begin{aligned} Var(X) &= E((X - E(X)\^2)) \\\\ &= \\left(\\int\_x
x\^2 f(x) dx \\right) - \\mu\^2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28X%29%20%26%3D%20E%28%28X%20-%20E%28X%29%5E2%29%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cleft%28%5Cint_x%20x%5E2%20f%28x%29%20dx%20%5Cright%29%20-%20%5Cmu%5E2%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    Var(X) &= E((X - E(X)^2)) \\
                    &= \left(\int_x x^2 f(x) dx \right) - \mu^2
                \end{aligned}")\

Given that
![X\_1](http://chart.apis.google.com/chart?cht=tx&chl=X_1 "X_1") and
![X\_2](http://chart.apis.google.com/chart?cht=tx&chl=X_2 "X_2") are
independent random variables, and ![a , b \\in
\\mathbb{R}](http://chart.apis.google.com/chart?cht=tx&chl=a%20%2C%20b%20%5Cin%20%5Cmathbb%7BR%7D "a , b \in \mathbb{R}"):

\
![\\begin{aligned} Var(a X\_1 + b X\_2) &= a\^2 Var(X\_1) + b\^2
Var(X\_2)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28a%20X_1%20%2B%20b%20X_2%29%20%26%3D%20a%5E2%20Var%28X_1%29%20%2B%20b%5E2%20Var%28X_2%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    Var(a X_1 + b X_2) &= a^2 Var(X_1) + b^2 Var(X_2)
                \end{aligned}")\

Uniform Distribution {#sec:uniform_distribution}
--------------------

In a Uniform Distribution, the probability of any subinterval of the
range is proportional to the length of the interval. Any two
sub-intervals of the same length have the same probability.

For ![a \<
b](http://chart.apis.google.com/chart?cht=tx&chl=a%20%3C%20b "a < b"),
if ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") is
uniformly distributed on the interval ![(a,
b)](http://chart.apis.google.com/chart?cht=tx&chl=%28a%2C%20b%29 "(a, b)"),
then we write ![X \\sim Unif(a,
b)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Unif%28a%2C%20b%29 "X \sim Unif(a, b)"):

\
![\\begin{aligned} f(x) &= \\frac{1}{b - a} \\\\
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28x%29%20%26%3D%20%5Cfrac%7B1%7D%7Bb%20-%20a%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    f(x) &= \frac{1}{b - a} \\
                \end{aligned}")\

For the uniform distribution, we know:

\
![\\begin{aligned} E(X) &= \\frac{b + a}{2} \\\\ Var(X) &= \\frac{(b -
a)\^2}{12}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%29%20%26%3D%20%5Cfrac%7Bb%20%2B%20a%7D%7B2%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28X%29%20%26%3D%20%5Cfrac%7B%28b%20-%20a%29%5E2%7D%7B12%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    E(X) &= \frac{b + a}{2} \\
                    Var(X) &= \frac{(b - a)^2}{12}
                \end{aligned}")\

#### Example 1 {#ssub:example_1}

A factory makes 60cm shoelaces. While they are all between 58-62cm, they
are required to be between 59-61.5cm.

Let ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") be the
length of randomly cut shoelace ![X \\sim Unif(58,
62)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Unif%2858%2C%2062%29 "X \sim Unif(58, 62)")
(![b =
62](http://chart.apis.google.com/chart?cht=tx&chl=b%20%3D%2062 "b = 62"),
![a =
58](http://chart.apis.google.com/chart?cht=tx&chl=a%20%3D%2058 "a = 58")).
Then we have that:

\
![\\begin{aligned} P(X = 60) &= 0 \\\\ f(x) &= \\frac{1}{b-a} \\\\ &=
\\frac{1}{4} \\\\ P(59 \< X \< 61.5) &= \\int\_{59}\^{61.5} f(x)dx \\\\
&= \\int\_{59}\^{61.5} \\frac{1}{4}dx \\\\ &= \\left. \\frac{1}{4}
\\right|\_{59}\^{61.5} \\\\ &= \\frac{2.5}{4}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3D%2060%29%20%26%3D%200%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28x%29%20%26%3D%20%5Cfrac%7B1%7D%7Bb-a%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7B4%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%2859%20%3C%20X%20%3C%2061.5%29%20%26%3D%20%5Cint_%7B59%7D%5E%7B61.5%7D%20f%28x%29dx%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cint_%7B59%7D%5E%7B61.5%7D%20%5Cfrac%7B1%7D%7B4%7Ddx%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cleft.%20%5Cfrac%7B1%7D%7B4%7D%20%5Cright%7C_%7B59%7D%5E%7B61.5%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B2.5%7D%7B4%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(X = 60) &= 0 \\
                        f(x) &= \frac{1}{b-a} \\
                        &= \frac{1}{4} \\
                        P(59 < X < 61.5) &= \int_{59}^{61.5} f(x)dx \\
                        &= \int_{59}^{61.5} \frac{1}{4}dx \\
                        &= \left. \frac{1}{4} \right|_{59}^{61.5} \\
                        &= \frac{2.5}{4}
                    \end{aligned}")\

Let ![Y](http://chart.apis.google.com/chart?cht=tx&chl=Y "Y") be the
number of shoelaces meeting the specifications. We know that
![Y](http://chart.apis.google.com/chart?cht=tx&chl=Y "Y") is
approximated as ![Y \\sim Bin(n = 100, p =
\\frac{2.5}{4})](http://chart.apis.google.com/chart?cht=tx&chl=Y%20%5Csim%20Bin%28n%20%3D%20100%2C%20p%20%3D%20%5Cfrac%7B2.5%7D%7B4%7D%29 "Y \sim Bin(n = 100, p = \frac{2.5}{4})").

Poisson Distribution {#sec:continuous_poisson_distribution}
--------------------

Let ![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") be the
time until the next event from a Poisson Process (see
Section [sec:poisson~d~istribution]) with rate
![\\lambda](http://chart.apis.google.com/chart?cht=tx&chl=%5Clambda "\lambda").
If ![X\_t](http://chart.apis.google.com/chart?cht=tx&chl=X_t "X_t") is
the number of events in
![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t") units of time,
then ![X\_t \\sim Poisson(\\lambda
t)](http://chart.apis.google.com/chart?cht=tx&chl=X_t%20%5Csim%20Poisson%28%5Clambda%20t%29 "X_t \sim Poisson(\lambda t)").

\
![\\begin{aligned} f(t) &= \\lambda e\^{-\\lambda t} \\\\ R(T) &= \\{
(0, \\infty) \\}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28t%29%20%26%3D%20%5Clambda%20e%5E%7B-%5Clambda%20t%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20R%28T%29%20%26%3D%20%5C%7B%20%280%2C%20%5Cinfty%29%20%5C%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    f(t) &= \lambda e^{-\lambda t} \\
                    R(T) &= \{ (0, \infty) \}
                \end{aligned}")\

Exponential Distribution {#sec:exponential_distribution}
------------------------

This describes situations where events occur according to a Poisson
process, and we measure the inter-arrival times between events.

If ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") is the
amount of time until the next event in a Poisson process, then ![X \\sim
Exp(\\theta)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Exp%28%5Ctheta%29 "X \sim Exp(\theta)"):

\
![\\begin{aligned} f(x) &= \\frac{1}{\\theta} e\^{\\frac{-x}{\\theta}}
\\text{, for \$x \> 0\$} \\\\ F(x) &= 1 - e\^{\\frac{-x}{\\theta}} \\\\
E(X) &= \\theta \\\\ Var(X) &= \\theta\^2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28x%29%20%26%3D%20%5Cfrac%7B1%7D%7B%5Ctheta%7D%20e%5E%7B%5Cfrac%7B-x%7D%7B%5Ctheta%7D%7D%20%5Ctext%7B%2C%20for%20%24x%20%3E%200%24%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20F%28x%29%20%26%3D%201%20-%20e%5E%7B%5Cfrac%7B-x%7D%7B%5Ctheta%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%29%20%26%3D%20%5Ctheta%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28X%29%20%26%3D%20%5Ctheta%5E2%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    f(x) &= \frac{1}{\theta} e^{\frac{-x}{\theta}} \text{, for $x > 0$} \\
                    F(x) &= 1 - e^{\frac{-x}{\theta}} \\
                    E(X) &= \theta \\
                    Var(X) &= \theta^2
                \end{aligned}")\

#### Example 1 {#ssub:example_1}

Let ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") be the
time until a light bulb burns out (in days) where the number of burnouts
is 1 every 7 days.

Since the frequency is
![\\frac{1}{7}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B7%7D "\frac{1}{7}"),
we know that the period,
![\\theta](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta "\theta")
is ![7](http://chart.apis.google.com/chart?cht=tx&chl=7 "7").

We can say that ![X \\sim Exp(\\theta =
7)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Exp%28%5Ctheta%20%3D%207%29 "X \sim Exp(\theta = 7)")

\
![\\begin{aligned} P(X = 2) &= 0 \\\\ P(X \> 30.5) &=
\\int\_{30.5}\^\\infty f(x)dx \\\\ &= \\int\_{30.5}\^\\infty
\\frac{1}{7} e\^{\\frac{-x}{7}}dx \\\\ &= \\left. -e\^{\\frac{-x}{7}}
\\right|\_{30.5}\^\\infty \\\\ &= e\^{\\frac{-30.5}{7}} \\\\ &= 0.0128
\\\\ P(X \< 1) &= \\int\_0\^1 \\frac{1}{7} e\^{\\frac{-x}{7}} dx \\\\ &=
0.1331
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3D%202%29%20%26%3D%200%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3E%2030.5%29%20%26%3D%20%5Cint_%7B30.5%7D%5E%5Cinfty%20f%28x%29dx%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cint_%7B30.5%7D%5E%5Cinfty%20%5Cfrac%7B1%7D%7B7%7D%20e%5E%7B%5Cfrac%7B-x%7D%7B7%7D%7Ddx%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cleft.%20-e%5E%7B%5Cfrac%7B-x%7D%7B7%7D%7D%20%5Cright%7C_%7B30.5%7D%5E%5Cinfty%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20e%5E%7B%5Cfrac%7B-30.5%7D%7B7%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.0128%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3C%201%29%20%26%3D%20%5Cint_0%5E1%20%5Cfrac%7B1%7D%7B7%7D%20%20e%5E%7B%5Cfrac%7B-x%7D%7B7%7D%7D%20dx%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.1331%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(X = 2) &= 0 \\
                        P(X > 30.5) &= \int_{30.5}^\infty f(x)dx \\
                        &= \int_{30.5}^\infty \frac{1}{7} e^{\frac{-x}{7}}dx \\
                        &= \left. -e^{\frac{-x}{7}} \right|_{30.5}^\infty \\
                        &= e^{\frac{-30.5}{7}} \\
                        &= 0.0128 \\
                        P(X < 1) &= \int_0^1 \frac{1}{7}  e^{\frac{-x}{7}} dx \\
                        &= 0.1331
                    \end{aligned}")\

Generating Random Samples {#sec:generating_random_samples}
-------------------------

This section was one he covered in class and did not post notes for.

Suppose ![X \\sim Bin(3, 0,
7)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Bin%283%2C%200%2C%207%29 "X \sim Bin(3, 0, 7)").
Then ![f(x) = {3 \\choose x} 0.7\^x
(1-0.7)\^{3-x}](http://chart.apis.google.com/chart?cht=tx&chl=f%28x%29%20%3D%20%7B3%20%5Cchoose%20x%7D%200.7%5Ex%20%281-0.7%29%5E%7B3-x%7D "f(x) = {3 \choose x} 0.7^x (1-0.7)^{3-x}").
As usual, if we define ![F(x) = \\sum\_{i=0}\^x
f(i)](http://chart.apis.google.com/chart?cht=tx&chl=F%28x%29%20%3D%20%5Csum_%7Bi%3D0%7D%5Ex%20f%28i%29 "F(x) = \sum_{i=0}^x f(i)"),
we can build a table of different ranges of
![F(x)](http://chart.apis.google.com/chart?cht=tx&chl=F%28x%29 "F(x)").
By picking random numbers, we can determine which range they fall in and
then back-trace to see what the corresponding
![x](http://chart.apis.google.com/chart?cht=tx&chl=x "x")-value is.

Normal Distribution {#cha:normal_distribution}
===================

We say that random variable
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") has normal
distribution ![X \\sim N(\\mu,
\\sigma\^2)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20N%28%5Cmu%2C%20%5Csigma%5E2%29 "X \sim N(\mu, \sigma^2)")
if the pdf has the form:

\
![\\begin{aligned} f(x) &= \\frac{1}{\\sqrt{2 \\pi \\sigma\^2}}
e\^{\\frac{-1}{2} \\left( \\frac{x - \\mu}{\\sigma} \\right)\^2}, x \\in
\\mathbb{R} \\\\ E(X) &= \\mu \\\\ Var(X) &= \\sigma\^2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20f%28x%29%20%26%3D%20%5Cfrac%7B1%7D%7B%5Csqrt%7B2%20%5Cpi%20%5Csigma%5E2%7D%7D%20e%5E%7B%5Cfrac%7B-1%7D%7B2%7D%20%5Cleft%28%20%5Cfrac%7Bx%20-%20%5Cmu%7D%7B%5Csigma%7D%20%5Cright%29%5E2%7D%2C%20x%20%5Cin%20%5Cmathbb%7BR%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28X%29%20%26%3D%20%5Cmu%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28X%29%20%26%3D%20%5Csigma%5E2%0A%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                f(x) &= \frac{1}{\sqrt{2 \pi \sigma^2}} e^{\frac{-1}{2} \left( \frac{x - \mu}{\sigma} \right)^2}, x \in \mathbb{R} \\
                E(X) &= \mu \\
                Var(X) &= \sigma^2
            \end{aligned}")\

This type of distribution comes up in many different places, this is the
bell curve shape.

Properties {#sec:properties}
----------

If ![X\_1 \\sim N(\\mu\_1,
\\sigma\_1\^2)](http://chart.apis.google.com/chart?cht=tx&chl=X_1%20%5Csim%20N%28%5Cmu_1%2C%20%5Csigma_1%5E2%29 "X_1 \sim N(\mu_1, \sigma_1^2)")
and ![X\_2 \\sim N(\\mu\_2,
\\sigma\_2\^2)](http://chart.apis.google.com/chart?cht=tx&chl=X_2%20%5Csim%20N%28%5Cmu_2%2C%20%5Csigma_2%5E2%29 "X_2 \sim N(\mu_2, \sigma_2^2)")
are independent, and ![a, b, c \\in
\\mathbb{R}](http://chart.apis.google.com/chart?cht=tx&chl=a%2C%20b%2C%20c%20%5Cin%20%5Cmathbb%7BR%7D "a, b, c \in \mathbb{R}"),
the linearity property tells us:

\
![\\begin{aligned} Y &= aX\_1 + bX\_2 + c \\\\ Y &\\sim N(a \\mu\_1 + b
\\mu\_2 + c, a\^2\\sigma\_1\^2 + b\^2 \\sigma\_2\^2)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Y%20%26%3D%20aX_1%20%2B%20bX_2%20%2B%20c%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Y%20%26%5Csim%20N%28a%20%5Cmu_1%20%2B%20b%20%5Cmu_2%20%2B%20c%2C%20a%5E2%5Csigma_1%5E2%20%2B%20b%5E2%20%5Csigma_2%5E2%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    Y &= aX_1 + bX_2 + c \\
                    Y &\sim N(a \mu_1 + b \mu_2 + c, a^2\sigma_1^2 + b^2 \sigma_2^2)
                \end{aligned}")\

If ![X \\sim N(\\mu,
\\sigma\^2)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20N%28%5Cmu%2C%20%5Csigma%5E2%29 "X \sim N(\mu, \sigma^2)"):

\
![\\begin{aligned} Z &= \\frac{X - \\mu}{\\sigma} \\\\ &\\sim N(0, 1)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Z%20%26%3D%20%5Cfrac%7BX%20-%20%5Cmu%7D%7B%5Csigma%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Csim%20N%280%2C%201%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    Z &= \frac{X - \mu}{\sigma} \\
                    &\sim N(0, 1)
                \end{aligned}")\

#### Example 1 {#ssub:example_1}

Let ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") be a
random variable representing a randomly selected student such that ![X
\\sim N(0.75,
0.07\^2)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20N%280.75%2C%200.07%5E2%29 "X \sim N(0.75, 0.07^2)").

What is the probability that they have a mark greater than 80%?

In other words, we’re looking for ![P(X \>
0.8)](http://chart.apis.google.com/chart?cht=tx&chl=P%28X%20%3E%200.8%29 "P(X > 0.8)"):

\
![\\begin{aligned} P(X \> 0.8) &= P(X - 0.75 \> 0.8 - 0.75) \\\\ Z \\sim
N(0, 1) &= P\\left(\\frac{X - 0.75}{0.07} \> \\frac{0.8 -
0.75}{0.07}\\right) \\\\ &= P\\left(Z \> \\frac{0.05}{0.07}\\right) \\\\
&= 1 - P\\left(Z \< \\frac{0.05}{0.07}\\right) \\\\ &= 0.2389
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3E%200.8%29%20%26%3D%20P%28X%20-%200.75%20%3E%200.8%20-%200.75%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Z%20%5Csim%20N%280%2C%201%29%20%26%3D%20P%5Cleft%28%5Cfrac%7BX%20-%200.75%7D%7B0.07%7D%20%3E%20%5Cfrac%7B0.8%20-%200.75%7D%7B0.07%7D%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%5Cleft%28Z%20%3E%20%5Cfrac%7B0.05%7D%7B0.07%7D%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201%20-%20P%5Cleft%28Z%20%3C%20%5Cfrac%7B0.05%7D%7B0.07%7D%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.2389%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(X > 0.8) &= P(X - 0.75 > 0.8 - 0.75) \\
                        Z \sim N(0, 1) &= P\left(\frac{X - 0.75}{0.07} > \frac{0.8 - 0.75}{0.07}\right) \\
                        &= P\left(Z > \frac{0.05}{0.07}\right) \\
                        &= 1 - P\left(Z < \frac{0.05}{0.07}\right) \\
                        &= 0.2389
                    \end{aligned}")\

What’s the probability that a randomly selected student has a mark less
than ![60](http://chart.apis.google.com/chart?cht=tx&chl=60 "60")?

\
![\\begin{aligned} P(X \< 0.6) &= P\\left(\\frac{X-0.75}{0.07} \<
\\frac{0.6-0.75}{0.07}\\right) \\\\ &= P(Z \< -2.14) \\\\ &= P(Z \>
2.14) \\\\ &= 1 - P(Z \< 2.14) \\\\ &= 0.0162
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3C%200.6%29%20%26%3D%20P%5Cleft%28%5Cfrac%7BX-0.75%7D%7B0.07%7D%20%3C%20%5Cfrac%7B0.6-0.75%7D%7B0.07%7D%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28Z%20%3C%20-2.14%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28Z%20%3E%202.14%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201%20-%20P%28Z%20%3C%202.14%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.0162%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(X < 0.6) &= P\left(\frac{X-0.75}{0.07} < \frac{0.6-0.75}{0.07}\right) \\
                        &= P(Z < -2.14) \\
                        &= P(Z > 2.14) \\
                        &= 1 - P(Z < 2.14) \\
                        &= 0.0162
                    \end{aligned}")\

### Standardized Distribution {#sub:standardized_distribution}

Generally speaking,
![Z](http://chart.apis.google.com/chart?cht=tx&chl=Z "Z") is the
Standardized Distribution of the function.

Normal Density {#sec:normal_density}
--------------

The density of a normal
![f(x)](http://chart.apis.google.com/chart?cht=tx&chl=f%28x%29 "f(x)")
is not integrable for finite limits ![a,
b](http://chart.apis.google.com/chart?cht=tx&chl=a%2C%20b "a, b"). We
need to look this up in Normal Distribution Tables, one of which is
available in Appendix [cha:normal~d~istribution~t~able].

Independent Normal Variables {#sec:independent_normal_variables}
----------------------------

Let ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") be the
amount of time that it takes
![A](http://chart.apis.google.com/chart?cht=tx&chl=A "A") to do an
action, and let
![Y](http://chart.apis.google.com/chart?cht=tx&chl=Y "Y") be the amount
of time that it takes
![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") to do an
independent action.

We have ![X \\sim N(50,
100)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20N%2850%2C%20100%29 "X \sim N(50, 100)")
and ![Y \\sim N(52,
64)](http://chart.apis.google.com/chart?cht=tx&chl=Y%20%5Csim%20N%2852%2C%2064%29 "Y \sim N(52, 64)").

By the linearity property, we define ![Z = X -
Y](http://chart.apis.google.com/chart?cht=tx&chl=Z%20%3D%20X%20-%20Y "Z = X - Y"):

\
![\\begin{aligned} Z &\\sim N(50 - 52, \\sqrt{100}\^2 + \\sqrt{64}\^2)
\\\\ &= N(-2, 164)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Z%20%26%5Csim%20N%2850%20-%2052%2C%20%5Csqrt%7B100%7D%5E2%20%2B%20%5Csqrt%7B64%7D%5E2%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20N%28-2%2C%20164%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    Z &\sim N(50 - 52, \sqrt{100}^2 + \sqrt{64}^2) \\
                    &= N(-2, 164)
                \end{aligned}")\

Now can start to solve equations like ![P(X \<
Y)](http://chart.apis.google.com/chart?cht=tx&chl=P%28X%20%3C%20Y%29 "P(X < Y)"):

\
![\\begin{aligned} P(X \< Y) &= P(X - Y \< 0) \\\\ &= P(\\frac{X - Y -
(-2)}{\\sqrt{164}} \< \\frac{0 - (-2)}{\\sqrt{164}}) \\\\ &= P(Z \<
\\frac{2}{\\sqrt{164}}) \\\\ &= P(Z \< 0.16) \\\\ &= 0.5636
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3C%20Y%29%20%26%3D%20P%28X%20-%20Y%20%3C%200%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28%5Cfrac%7BX%20-%20Y%20-%20%28-2%29%7D%7B%5Csqrt%7B164%7D%7D%20%3C%20%5Cfrac%7B0%20-%20%28-2%29%7D%7B%5Csqrt%7B164%7D%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28Z%20%3C%20%5Cfrac%7B2%7D%7B%5Csqrt%7B164%7D%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28Z%20%3C%200.16%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.5636%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    P(X < Y) &= P(X - Y < 0) \\
                    &= P(\frac{X - Y - (-2)}{\sqrt{164}} < \frac{0 - (-2)}{\sqrt{164}}) \\
                    &= P(Z < \frac{2}{\sqrt{164}}) \\
                    &= P(Z < 0.16) \\
                    &= 0.5636
                \end{aligned}")\

Many Independent Normal Variables {#sec:many_independent_normal_variables}
---------------------------------

Let the random variable
![X\_i](http://chart.apis.google.com/chart?cht=tx&chl=X_i "X_i")
represent the price of the
![i\^{\\text{th}}](http://chart.apis.google.com/chart?cht=tx&chl=i%5E%7B%5Ctext%7Bth%7D%7D "i^{\text{th}}")
painting, where all
![X\_i](http://chart.apis.google.com/chart?cht=tx&chl=X_i "X_i") are
independent of
![X\_j](http://chart.apis.google.com/chart?cht=tx&chl=X_j "X_j"). Let
the random variable
![Y](http://chart.apis.google.com/chart?cht=tx&chl=Y "Y") represent the
monthly total of all paintings sold.

\
![\\begin{aligned} Y &= X\_1 + X\_2 + \\ldots + X\_10 \\\\ &=
\\sum\_{i=1}\^{10} X\_i
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Y%20%26%3D%20X_1%20%2B%20X_2%20%2B%20%5Cldots%20%2B%20X_10%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_%7Bi%3D1%7D%5E%7B10%7D%20X_i%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    Y &= X_1 + X_2 + \ldots + X_10 \\
                    &= \sum_{i=1}^{10} X_i
                \end{aligned}")\

We can say that ![X\_i \\sim N(200,
200\^2)](http://chart.apis.google.com/chart?cht=tx&chl=X_i%20%5Csim%20N%28200%2C%20200%5E2%29 "X_i \sim N(200, 200^2)").
Thus we can use by the variables independence that:

\
![\\begin{aligned} Var(Y) &= Var\\left(\\sum\_i X\_i\\right) \\\\ &=
\\sum\_i Var(X\_i) \\\\ &= 400 000
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28Y%29%20%26%3D%20Var%5Cleft%28%5Csum_i%20X_i%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_i%20Var%28X_i%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20400%20000%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    Var(Y) &= Var\left(\sum_i X_i\right) \\
                    &= \sum_i Var(X_i) \\
                    &= 400 000
                \end{aligned}")\

We can also say that the expected value is[^7^](#fn7):

\
![\\begin{aligned} E(Y) &= E\\left(\\sum\_i X\_i\\right) \\\\ &=
\\sum\_i E(X\_i) \\\\ &= 2000
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28Y%29%20%26%3D%20E%5Cleft%28%5Csum_i%20X_i%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_i%20E%28X_i%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%202000%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    E(Y) &= E\left(\sum_i X_i\right) \\
                    &= \sum_i E(X_i) \\
                    &= 2000
                \end{aligned}")\

Thus, ![Y \\sim N(2000, (10)
200\^2)](http://chart.apis.google.com/chart?cht=tx&chl=Y%20%5Csim%20N%282000%2C%20%2810%29%20200%5E2%29 "Y \sim N(2000, (10) 200^2)").

Binomial Approximation {#sec:binomial_approximation}
----------------------

For large ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"), we
can approximate the distribution of samples using a binomial method.

Specifically, if ![np \>
5](http://chart.apis.google.com/chart?cht=tx&chl=np%20%3E%205 "np > 5")
and ![n (1 - p) \>
5](http://chart.apis.google.com/chart?cht=tx&chl=n%20%281%20-%20p%29%20%3E%205 "n (1 - p) > 5")
(i.e. ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is large
and ![0 \< p \<
1](http://chart.apis.google.com/chart?cht=tx&chl=0%20%3C%20p%20%3C%201 "0 < p < 1"))[^8^](#fn8).
Suppose ![X \\sim Bin(n,
p)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Bin%28n%2C%20p%29 "X \sim Bin(n, p)").
Then we define the random variable
![Z](http://chart.apis.google.com/chart?cht=tx&chl=Z "Z") expressed in
terms of ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") and
![p](http://chart.apis.google.com/chart?cht=tx&chl=p "p") as:

\
![\\begin{aligned} Z &= \\frac{X - np}{\\sqrt{np (1 - p)}} \\\\ &\\sim
N(0, 1) \\\\ E(Z) &= np \\\\ Var(Z) &= np(1-p)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Z%20%26%3D%20%5Cfrac%7BX%20-%20np%7D%7B%5Csqrt%7Bnp%20%281%20-%20p%29%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Csim%20N%280%2C%201%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28Z%29%20%26%3D%20np%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28Z%29%20%26%3D%20np%281-p%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    Z &= \frac{X - np}{\sqrt{np (1 - p)}} \\
                    &\sim N(0, 1) \\
                    E(Z) &= np \\
                    Var(Z) &= np(1-p)
                \end{aligned}")\

Since we are using a continuous distribution to approximate the discrete
Binomial distribution, we need to correct some continuities at edges of
the distributions:

\
![\\begin{aligned} P(a \< X) &\\approx P\\left( \\frac{(a + 0.5) -
np}{\\sqrt{np(1 - p)}} \< Z \\right) \\\\ P(X \< b) &\\approx P\\left(
\\frac{(b - 0.5) - np}{\\sqrt{np(1 - p)}} \> Z \\right) \\\\
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28a%20%3C%20X%29%20%26%5Capprox%20P%5Cleft%28%20%5Cfrac%7B%28a%20%2B%200.5%29%20-%20np%7D%7B%5Csqrt%7Bnp%281%20-%20p%29%7D%7D%20%3C%20Z%20%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3C%20b%29%20%26%5Capprox%20P%5Cleft%28%20%5Cfrac%7B%28b%20-%200.5%29%20-%20np%7D%7B%5Csqrt%7Bnp%281%20-%20p%29%7D%7D%20%3E%20Z%20%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    P(a < X) &\approx P\left( \frac{(a + 0.5) - np}{\sqrt{np(1 - p)}} < Z \right) \\
                    P(X < b) &\approx P\left( \frac{(b - 0.5) - np}{\sqrt{np(1 - p)}} > Z \right) \\
                \end{aligned}")\

#### Example 1 {#ssub:example_1}

Suppose we have a random variable
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") defined as ![X
\\sim Bin(200,
0.3](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Bin%28200%2C%200.3 "X \sim Bin(200, 0.3").
What is ![P(X \<
50)](http://chart.apis.google.com/chart?cht=tx&chl=P%28X%20%3C%2050%29 "P(X < 50)")?

Well, we have ![np =
60](http://chart.apis.google.com/chart?cht=tx&chl=np%20%3D%2060 "np = 60"),
![np (1-p) =
42](http://chart.apis.google.com/chart?cht=tx&chl=np%20%281-p%29%20%3D%2042 "np (1-p) = 42").
Since ![np \>
5](http://chart.apis.google.com/chart?cht=tx&chl=np%20%3E%205 "np > 5")
and ![np (1-p) \>
5](http://chart.apis.google.com/chart?cht=tx&chl=np%20%281-p%29%20%3E%205 "np (1-p) > 5"),
we can use the normal approximation!

\
![\\begin{aligned} P(X \< 50) &= P(X \< 50.5) \\\\ &= P(\\frac{X -
60}{\\sqrt{np (1 - p)}} \< \\frac{50.5 - 60}{\\sqrt{np (1 - p)}}) \\\\
&= P(Z \< \\frac{-9.5}{\\sqrt{np(1 - p)}}) \\\\ &= P(Z \< - 1.47) \\\\
&= 1 - P (Z \< 1.47) \\\\ &= 0.0708
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3C%2050%29%20%26%3D%20P%28X%20%3C%2050.5%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28%5Cfrac%7BX%20-%2060%7D%7B%5Csqrt%7Bnp%20%281%20-%20p%29%7D%7D%20%3C%20%5Cfrac%7B50.5%20-%2060%7D%7B%5Csqrt%7Bnp%20%281%20-%20p%29%7D%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28Z%20%3C%20%5Cfrac%7B-9.5%7D%7B%5Csqrt%7Bnp%281%20-%20p%29%7D%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28Z%20%3C%20-%201.47%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201%20-%20P%20%28Z%20%3C%201.47%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.0708%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(X < 50) &= P(X < 50.5) \\
                        &= P(\frac{X - 60}{\sqrt{np (1 - p)}} < \frac{50.5 - 60}{\sqrt{np (1 - p)}}) \\
                        &= P(Z < \frac{-9.5}{\sqrt{np(1 - p)}}) \\
                        &= P(Z < - 1.47) \\
                        &= 1 - P (Z < 1.47) \\
                        &= 0.0708
                    \end{aligned}")\

Similarly:

\
![\\begin{aligned} P(X \> 80) &= P(X \> 79.5) \\\\ &= P(\\frac{X -
60}{\\sqrt{np (1 - p)}} \> \\frac{79.5 - 60}{\\sqrt{np (1 - p)}}) \\\\
&= P(Z \> 3.0) \\\\ &= 1 - P(Z \< 3.0) \\\\ &= 0.0013
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28X%20%3E%2080%29%20%26%3D%20P%28X%20%3E%2079.5%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28%5Cfrac%7BX%20-%2060%7D%7B%5Csqrt%7Bnp%20%281%20-%20p%29%7D%7D%20%3E%20%5Cfrac%7B79.5%20-%2060%7D%7B%5Csqrt%7Bnp%20%281%20-%20p%29%7D%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28Z%20%3E%203.0%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201%20-%20P%28Z%20%3C%203.0%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.0013%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(X > 80) &= P(X > 79.5) \\
                        &= P(\frac{X - 60}{\sqrt{np (1 - p)}} > \frac{79.5 - 60}{\sqrt{np (1 - p)}}) \\
                        &= P(Z > 3.0) \\
                        &= 1 - P(Z < 3.0) \\
                        &= 0.0013
                    \end{aligned}")\

Tutorial Content {#sec:tutorial_content}
----------------

A STAT 206 tutorial on Oct 24, 2013 yielded this information:

### Blackjack Game {#sub:blackjack_game}

We’re going to be examining a simplified version of a blackjack game.

Let ![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") be the
point-value of a random card. Naturally, ![R(X) = \\{ 2, \\ldots, 10, 11
\\}](http://chart.apis.google.com/chart?cht=tx&chl=R%28X%29%20%3D%20%5C%7B%202%2C%20%5Cldots%2C%2010%2C%2011%20%5C%7D "R(X) = \{ 2, \ldots, 10, 11 \}").

[h]

| c || r | r | r | r | r | r | r | r | r | r |
![X](http://chart.apis.google.com/chart?cht=tx&chl=X "X") & 2 & 3 & 4 &
5 & 6 & 7 & 8 & 9 & 10 & 11\
![f(x)](http://chart.apis.google.com/chart?cht=tx&chl=f%28x%29 "f(x)") &
![\\frac{1}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B13%7D "\frac{1}{13}")
&
![\\frac{1}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B13%7D "\frac{1}{13}")
&
![\\frac{1}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B13%7D "\frac{1}{13}")
&
![\\frac{1}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B13%7D "\frac{1}{13}")
&
![\\frac{1}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B13%7D "\frac{1}{13}")
& ![\\frac{1}{13}
](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B13%7D%20 "\frac{1}{13} ")&
![\\frac{1}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B13%7D "\frac{1}{13}")
&
![\\frac{1}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B13%7D "\frac{1}{13}")
&
![\\frac{4}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B4%7D%7B13%7D "\frac{4}{13}")
&
![\\frac{1}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B13%7D "\frac{1}{13}")\
![F(x)](http://chart.apis.google.com/chart?cht=tx&chl=F%28x%29 "F(x)") &
![\\frac{1}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B1%7D%7B13%7D "\frac{1}{13}")
&
![\\frac{2}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B2%7D%7B13%7D "\frac{2}{13}")
&
![\\frac{3}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B3%7D%7B13%7D "\frac{3}{13}")
&
![\\frac{4}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B4%7D%7B13%7D "\frac{4}{13}")
&
![\\frac{5}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B5%7D%7B13%7D "\frac{5}{13}")
& ![\\frac{6}{13}
](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B6%7D%7B13%7D%20 "\frac{6}{13} ")&
![\\frac{7}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B7%7D%7B13%7D "\frac{7}{13}")
&
![\\frac{8}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B8%7D%7B13%7D "\frac{8}{13}")
&
![\\frac{12}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B12%7D%7B13%7D "\frac{12}{13}")
&
![\\frac{13}{13}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cfrac%7B13%7D%7B13%7D "\frac{13}{13}")\

If we find
![F\^{-1}(u)](http://chart.apis.google.com/chart?cht=tx&chl=F%5E%7B-1%7D%28u%29 "F^{-1}(u)"),
we can generate these card values with even probability.

\
![\\begin{aligned} F\^{-1}(u) &= \\left\\{ \\begin{array}{lr} 2 & : u
\\le \\frac{1}{13} \\\\ 3 & : \\frac{1}{13} \< u \\le \\frac{2}{13} \\\\
4 & : \\frac{2}{13} \< u \\le \\frac{3}{13} \\\\ 5 & : \\frac{3}{13} \<
u \\le \\frac{4}{13} \\\\ 6 & : \\frac{4}{13} \< u \\le \\frac{5}{13}
\\\\ 7 & : \\frac{5}{13} \< u \\le \\frac{6}{13} \\\\ 8 & :
\\frac{6}{13} \< u \\le \\frac{7}{13} \\\\ 9 & : \\frac{7}{13} \< u \\le
\\frac{8}{13} \\\\ 10 & : \\frac{8}{13} \< u \\le \\frac{11}{13} \\\\ 11
& : \\frac{11}{13} \< u \\le \\frac{12}{13} \\end{array} \\right.
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20F%5E%7B-1%7D%28u%29%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%5C%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbegin%7Barray%7D%7Blr%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%202%20%26%20%20%3A%20u%20%5Cle%20%5Cfrac%7B1%7D%7B13%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%203%20%26%20%20%3A%20%5Cfrac%7B1%7D%7B13%7D%20%3C%20u%20%5Cle%20%5Cfrac%7B2%7D%7B13%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%204%20%26%20%20%3A%20%5Cfrac%7B2%7D%7B13%7D%20%3C%20u%20%5Cle%20%5Cfrac%7B3%7D%7B13%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%205%20%26%20%20%3A%20%5Cfrac%7B3%7D%7B13%7D%20%3C%20u%20%5Cle%20%5Cfrac%7B4%7D%7B13%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%206%20%26%20%20%3A%20%5Cfrac%7B4%7D%7B13%7D%20%3C%20u%20%5Cle%20%5Cfrac%7B5%7D%7B13%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%207%20%26%20%20%3A%20%5Cfrac%7B5%7D%7B13%7D%20%3C%20u%20%5Cle%20%5Cfrac%7B6%7D%7B13%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%208%20%26%20%20%3A%20%5Cfrac%7B6%7D%7B13%7D%20%3C%20u%20%5Cle%20%5Cfrac%7B7%7D%7B13%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%209%20%26%20%20%3A%20%5Cfrac%7B7%7D%7B13%7D%20%3C%20u%20%5Cle%20%5Cfrac%7B8%7D%7B13%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%2010%20%26%20%3A%20%5Cfrac%7B8%7D%7B13%7D%20%3C%20u%20%5Cle%20%5Cfrac%7B11%7D%7B13%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%2011%20%26%20%3A%20%5Cfrac%7B11%7D%7B13%7D%20%3C%20u%20%5Cle%20%5Cfrac%7B12%7D%7B13%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Barray%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright.%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        F^{-1}(u) &=
                            \left\{
                                \begin{array}{lr}
                                    2 &  : u \le \frac{1}{13} \\
                                    3 &  : \frac{1}{13} < u \le \frac{2}{13} \\
                                    4 &  : \frac{2}{13} < u \le \frac{3}{13} \\
                                    5 &  : \frac{3}{13} < u \le \frac{4}{13} \\
                                    6 &  : \frac{4}{13} < u \le \frac{5}{13} \\
                                    7 &  : \frac{5}{13} < u \le \frac{6}{13} \\
                                    8 &  : \frac{6}{13} < u \le \frac{7}{13} \\
                                    9 &  : \frac{7}{13} < u \le \frac{8}{13} \\
                                    10 & : \frac{8}{13} < u \le \frac{11}{13} \\
                                    11 & : \frac{11}{13} < u \le \frac{12}{13}
                                \end{array}
                            \right.
                    \end{aligned}")\

Given that dealers stay if hand ![\\ge
17](http://chart.apis.google.com/chart?cht=tx&chl=%5Cge%2017 "\ge 17"),
we want to find a few probabilities.

1.  Suppose the dealer gets ![(K,
    6)](http://chart.apis.google.com/chart?cht=tx&chl=%28K%2C%206%29 "(K, 6)").
    Find ![P(B |(K,
    G))](http://chart.apis.google.com/chart?cht=tx&chl=P%28B%20%7C%28K%2C%20G%29%29 "P(B |(K, G))").
    (![B](http://chart.apis.google.com/chart?cht=tx&chl=B "B") is the
    event where the dealer “busts”).

    \
    ![\\begin{aligned} P(B | (K, 6)) &= \\sum\_{i=2}\^{11} P(B | (K, 6,
    i)) P(i) \\\\ &= \\left(\\sum\_{i=2}\^{5} 0 P(i) \\right) +
    \\sum\_{i=6}\^{10} 1 P(i) \\\\ &= \\frac{8}{13}
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28B%20%7C%20%28K%2C%206%29%29%20%26%3D%20%5Csum_%7Bi%3D2%7D%5E%7B11%7D%20P%28B%20%7C%20%28K%2C%206%2C%20i%29%29%20P%28i%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cleft%28%5Csum_%7Bi%3D2%7D%5E%7B5%7D%200%20P%28i%29%20%5Cright%29%20%2B%20%5Csum_%7Bi%3D6%7D%5E%7B10%7D%201%20P%28i%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B8%7D%7B13%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                                    P(B | (K, 6)) &= \sum_{i=2}^{11} P(B | (K, 6, i)) P(i) \\
                                    &= \left(\sum_{i=2}^{5} 0 P(i) \right) + \sum_{i=6}^{10} 1 P(i) \\
                                    &= \frac{8}{13}
                                \end{aligned}")\

2.  Suppose the dealer gets ![(J,
    4)](http://chart.apis.google.com/chart?cht=tx&chl=%28J%2C%204%29 "(J, 4)").
    Find… TODO: I don’t know what this is asking. Let
    ![C](http://chart.apis.google.com/chart?cht=tx&chl=C "C") be the
    event of 21 or a blackjack.

    \
    ![\\begin{aligned} P(C | (J, 4)) &= P(C | J, 4, 7) P(7) + P(C | (J,
    4, 2)) P(2) + P(C | J, 4, A)P(A) \\\\ &= P(7) + P(2)P(5) + P(A) +
    P(A)P(A)P(5) \\\\ &= \\frac{1}{13} + \\frac{1}{13\^2} +
    \\frac{1}{13\^2} + \\frac{1}{13\^3}
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28C%20%7C%20%28J%2C%204%29%29%20%26%3D%20P%28C%20%7C%20J%2C%204%2C%207%29%20P%287%29%20%2B%20P%28C%20%7C%20%28J%2C%204%2C%202%29%29%20P%282%29%20%2B%20P%28C%20%7C%20J%2C%204%2C%20A%29P%28A%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%287%29%20%2B%20P%282%29P%285%29%20%2B%20P%28A%29%20%2B%20P%28A%29P%28A%29P%285%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B1%7D%7B13%7D%20%2B%20%5Cfrac%7B1%7D%7B13%5E2%7D%20%2B%20%5Cfrac%7B1%7D%7B13%5E2%7D%20%2B%20%5Cfrac%7B1%7D%7B13%5E3%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                                    P(C | (J, 4)) &= P(C | J, 4, 7) P(7) + P(C | (J, 4, 2)) P(2) + P(C | J, 4, A)P(A) \\
                                    &= P(7) + P(2)P(5) + P(A) + P(A)P(A)P(5) \\
                                    &= \frac{1}{13} + \frac{1}{13^2} + \frac{1}{13^2} + \frac{1}{13^3}
                                \end{aligned}")\

3.  Suppos the player follows the dealer’s strategy. What is
    ![P(\\text{player
    wins})](http://chart.apis.google.com/chart?cht=tx&chl=P%28%5Ctext%7Bplayer%20wins%7D%29 "P(\text{player wins})")?

    \
    ![\\begin{aligned} P(w) &= \\sum\_{i = 17}\^{21} P(w | p = i) P(P =
    i) \\\\ &= \\sum\_{i = 17}\^{21} P(p = i) [0.29 + D \< i] \\\\ &=
    0.415
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28w%29%20%26%3D%20%5Csum_%7Bi%20%3D%2017%7D%5E%7B21%7D%20P%28w%20%7C%20p%20%3D%20i%29%20P%28P%20%3D%20i%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Csum_%7Bi%20%3D%2017%7D%5E%7B21%7D%20P%28p%20%3D%20i%29%20%5B0.29%20%2B%20D%20%3C%20i%5D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.415%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                                    P(w) &= \sum_{i = 17}^{21} P(w | p = i) P(P = i) \\
                                         &= \sum_{i = 17}^{21} P(p = i) [0.29 + D < i] \\
                                         &= 0.415
                                \end{aligned}")\

    I’m not sure what happened there either.

4.  Players arrive in a Poisson process at a rate of 1 player per
    minute. After the first player arrives, the dealer either waits 3
    minutes or until 5 players sit down. Given that the bet is \$1 per
    person, what is the net winnings of the dealer?

Sampling Distribution {#cha:sampling_distribution}
=====================

We want to be able to draw statistical conclusions about a
**population**. We are limited to a sample because we do not have
resources available to adequately measure the entire population. By
wisely selecting a **sample** of the population, and measuring the
**variable** interest, we try to build statistical conclusions with
reasonable confidence. We use **random sampling** to ensure the sample
accurately represents the population.

**Statistics** are functions of the random sample (RS) which are used to
learn about model parameters.

Since sampling is random, the statistics representing them are
semi-random as well. We describe this randomness using a **sampling
distribution**.

Simple Random Sampling (SRS) {#sec:simple_random_sampling_srs}
----------------------------

Simple random sampling is the most basic form of random sampling. It
involves querying each unit in the population with an equal probability.

Stratified Random Sampling {#sec:stratified_random_sampling}
--------------------------

With simple random sampling, we divide a population of size
![N](http://chart.apis.google.com/chart?cht=tx&chl=N "N") into
![K](http://chart.apis.google.com/chart?cht=tx&chl=K "K") distinct
buckets[^9^](#fn9), each with
![N\_i](http://chart.apis.google.com/chart?cht=tx&chl=N_i "N_i")
items[^10^](#fn10) (![i = 1 \\ldots
K](http://chart.apis.google.com/chart?cht=tx&chl=i%20%3D%201%20%5Cldots%20K "i = 1 \ldots K"))

We then take a simple random sample of size
![n\_i](http://chart.apis.google.com/chart?cht=tx&chl=n_i "n_i") from
each strata such that:

\
![\\begin{aligned} n &= \\sum\_{i=1}\^K n\_i
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20n%20%26%3D%20%5Csum_%7Bi%3D1%7D%5EK%20n_i%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    n &= \sum_{i=1}^K n_i
                \end{aligned}")\

We can select
![n\_i](http://chart.apis.google.com/chart?cht=tx&chl=n_i "n_i") using a
few different methods:

Equal Allocation
:   sets ![n\_i =
    \\frac{N}{K}](http://chart.apis.google.com/chart?cht=tx&chl=n_i%20%3D%20%5Cfrac%7BN%7D%7BK%7D "n_i = \frac{N}{K}")
    - all strata have equally sized queries.

Proportional Allocation
:   sets ![n\_i = \\frac{n
    N\_i}{K}](http://chart.apis.google.com/chart?cht=tx&chl=n_i%20%3D%20%5Cfrac%7Bn%20N_i%7D%7BK%7D "n_i = \frac{n N_i}{K}")
    - all stratas have queries proportional to their size.

Optimal (Neyman) Allocation
:   is where each sample is weighted by the strata variance.

In stratified sampling, we have increased benefit over simple random
sampling when groups are more distinct. This ensures all groups are
represented in the sample.

Cluster Sampling {#sec:cluster_sampling}
----------------

When a population is divided into
![M](http://chart.apis.google.com/chart?cht=tx&chl=M "M") natural
clusters that are each justifiably a microcosm of the entire population,
and a simple random sample of
![m](http://chart.apis.google.com/chart?cht=tx&chl=m "m") clusters is
selected. From each selected cluster, a simple random sample of size
![n\_i =
\\frac{n}{m}](http://chart.apis.google.com/chart?cht=tx&chl=n_i%20%3D%20%5Cfrac%7Bn%7D%7Bm%7D "n_i = \frac{n}{m}")
is taken.

By only selecting a few clusters, we reduce data acquisition cost, which
makes this economically efficient compared to a simple random sampling.

A few examples:

-   High-school students would have strata by grade with clusters in
    every school.

-   Voters in federal election would cluster by city or by riding.

-   UW Students can be arranged into strata by faculty.

Probability Distributions {#sec:probability_distributions}
-------------------------

A random sample of size
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") is taken from
an infinite population, it is a set of independent and identically
distributed (iid) random variables ![\\{ X\_1, \\ldots, X\_n
\\}](http://chart.apis.google.com/chart?cht=tx&chl=%5C%7B%20X_1%2C%20%5Cldots%2C%20X_n%20%5C%7D "\{ X_1, \ldots, X_n \}").

Where each random variable has the same probability distribution
![f\_i(x)](http://chart.apis.google.com/chart?cht=tx&chl=f_i%28x%29 "f_i(x)"),
mean
![\\mu\_i](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu_i "\mu_i")
and variance
![\\sigma\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma%5E2 "\sigma^2"),
we can get these statistics:

\
![\\begin{aligned} T &= h(X\_1, \\ldots, X\_n) \\\\ \\bar{X} &=
\\frac{1}{n} \\sum\_{i=1}\^n X\_i \\\\ S\^2 &= \\frac{1}{n-1}
\\sum\_{i=1}\^n (X\_i - \\bar{X})\^2 \\\\ X\_{(1)} &= \\min\_i (X\_i)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%20%26%3D%20h%28X_1%2C%20%5Cldots%2C%20X_n%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbar%7BX%7D%20%26%3D%20%5Cfrac%7B1%7D%7Bn%7D%20%5Csum_%7Bi%3D1%7D%5En%20X_i%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20S%5E2%20%26%3D%20%5Cfrac%7B1%7D%7Bn-1%7D%20%5Csum_%7Bi%3D1%7D%5En%20%28X_i%20-%20%5Cbar%7BX%7D%29%5E2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20X_%7B%281%29%7D%20%26%3D%20%5Cmin_i%20%28X_i%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    T &= h(X_1, \ldots, X_n) \\
                    \bar{X} &= \frac{1}{n} \sum_{i=1}^n X_i \\
                    S^2 &= \frac{1}{n-1} \sum_{i=1}^n (X_i - \bar{X})^2 \\
                    X_{(1)} &= \min_i (X_i)
                \end{aligned}")\

Where ![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") is
[unknown],
![\\bar{X}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7BX%7D "\bar{X}")
is the mean,
![S\^2](http://chart.apis.google.com/chart?cht=tx&chl=S%5E2 "S^2") is
the standard deviation, and
![X\_{(1)}](http://chart.apis.google.com/chart?cht=tx&chl=X_%7B%281%29%7D "X_{(1)}")
is the minimum. The sampling distribution of a statistic represents the
probability distribution which describes the randomness of the
statistic.

#### Example 1 {#ssub:example_1}

Let the random variable
![X\_i](http://chart.apis.google.com/chart?cht=tx&chl=X_i "X_i")
represent the number of hours that student a randomly sampled student
slept last night. Take a simple random sampling of size ![n =
3](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3D%203 "n = 3").
We define
![X\_1](http://chart.apis.google.com/chart?cht=tx&chl=X_1 "X_1"),
![X\_2](http://chart.apis.google.com/chart?cht=tx&chl=X_2 "X_2"),
![X\_3](http://chart.apis.google.com/chart?cht=tx&chl=X_3 "X_3").

The sample mean is also a random variable ![\\bar{X} = \\frac{X\_1 +
X\_2 +
X\_3}{3}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7BX%7D%20%3D%20%5Cfrac%7BX_1%20%2B%20X_2%20%2B%20X_3%7D%7B3%7D "\bar{X} = \frac{X_1 + X_2 + X_3}{3}").

Given ![x\_1 =
7](http://chart.apis.google.com/chart?cht=tx&chl=x_1%20%3D%207 "x_1 = 7"),
![x\_2 =
8](http://chart.apis.google.com/chart?cht=tx&chl=x_2%20%3D%208 "x_2 = 8"),
![x\_3 =
8.5](http://chart.apis.google.com/chart?cht=tx&chl=x_3%20%3D%208.5 "x_3 = 8.5"),
we have ![X\_{(1)} =
7](http://chart.apis.google.com/chart?cht=tx&chl=X_%7B%281%29%7D%20%3D%207 "X_{(1)} = 7"),
![\\bar{x} =
\\frac{23.5}{3}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7Bx%7D%20%3D%20%5Cfrac%7B23.5%7D%7B3%7D "\bar{x} = \frac{23.5}{3}"),
and ![S\^2 =
0.58](http://chart.apis.google.com/chart?cht=tx&chl=S%5E2%20%3D%200.58 "S^2 = 0.58").

### Probability Distributions of Random Samples {#sub:probability_distributions_of_random_samples}

For a set of random independent variables
![X\_i](http://chart.apis.google.com/chart?cht=tx&chl=X_i "X_i") being
sampled with individual expected value ![E(X\_i) =
\\mu](http://chart.apis.google.com/chart?cht=tx&chl=E%28X_i%29%20%3D%20%5Cmu "E(X_i) = \mu")
and individual variance ![Var(X\_i) =
\\sigma\^2](http://chart.apis.google.com/chart?cht=tx&chl=Var%28X_i%29%20%3D%20%5Csigma%5E2 "Var(X_i) = \sigma^2"):

\
![\\begin{aligned} E(\\bar{X}) &= \\mu \\\\ Var(\\bar{X}) &=
\\frac{\\sigma\^2}{n} \\\\ \\bar{X} &\\sim N(\\mu,
\\frac{\\sigma\^2}{n})
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28%5Cbar%7BX%7D%29%20%26%3D%20%5Cmu%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28%5Cbar%7BX%7D%29%20%26%3D%20%5Cfrac%7B%5Csigma%5E2%7D%7Bn%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbar%7BX%7D%20%26%5Csim%20N%28%5Cmu%2C%20%5Cfrac%7B%5Csigma%5E2%7D%7Bn%7D%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        E(\bar{X}) &= \mu \\
                        Var(\bar{X}) &= \frac{\sigma^2}{n} \\
                        \bar{X} &\sim N(\mu, \frac{\sigma^2}{n})
                    \end{aligned}")\

#### Example 1 {#ssub:example_1}

Suppose we hade bread weight ![X\_i \\sim N(805,
16)](http://chart.apis.google.com/chart?cht=tx&chl=X_i%20%5Csim%20N%28805%2C%2016%29 "X_i \sim N(805, 16)").

Then ![n =
5](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3D%205 "n = 5"),
![\\bar{X} = \\sum\_{i=1}\^5
\\frac{X\_i}{5}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7BX%7D%20%3D%20%5Csum_%7Bi%3D1%7D%5E5%20%5Cfrac%7BX_i%7D%7B5%7D "\bar{X} = \sum_{i=1}^5 \frac{X_i}{5}"),
and ![\\bar{X} \\sim N(805,
\\frac{16}{5})](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7BX%7D%20%5Csim%20N%28805%2C%20%5Cfrac%7B16%7D%7B5%7D%29 "\bar{X} \sim N(805, \frac{16}{5})").

What is the probability that the average bread weight sampled is less
than 800g?

\
![\\begin{aligned} P(\\bar{X} \< 800) &= P(\\frac{\\bar{X} -
805}{\\sqrt{16/5}} \< \\frac{800 - 805}{\\sqrt{16/5}}) \\\\ &= P(Z \<
\\frac{-5}{\\sqrt{16/5}}) \\\\ &= 1 - P(Z \< 2.8) \\\\ &= 0.0026
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28%5Cbar%7BX%7D%20%3C%20800%29%20%26%3D%20P%28%5Cfrac%7B%5Cbar%7BX%7D%20-%20805%7D%7B%5Csqrt%7B16%2F5%7D%7D%20%3C%20%5Cfrac%7B800%20-%20805%7D%7B%5Csqrt%7B16%2F5%7D%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28Z%20%3C%20%5Cfrac%7B-5%7D%7B%5Csqrt%7B16%2F5%7D%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201%20-%20P%28Z%20%3C%202.8%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.0026%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                            P(\bar{X} < 800) &= P(\frac{\bar{X} - 805}{\sqrt{16/5}} < \frac{800 - 805}{\sqrt{16/5}}) \\
                            &= P(Z < \frac{-5}{\sqrt{16/5}}) \\
                            &= 1 - P(Z < 2.8) \\
                            &= 0.0026
                        \end{aligned}")\

### Probability Distributions of Normal Samples {#sub:probability_distributions_of_normal_samples}

For ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") iid
![X\_i](http://chart.apis.google.com/chart?cht=tx&chl=X_i "X_i") with
![N(\\mu,
\\sigma\^2)](http://chart.apis.google.com/chart?cht=tx&chl=N%28%5Cmu%2C%20%5Csigma%5E2%29 "N(\mu, \sigma^2)")
distribution:

\
![\\begin{aligned} \\bar{X} &\\sim N \\left(\\mu, \\frac{\\sigma\^2}{n}
\\right)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbar%7BX%7D%20%26%5Csim%20N%20%5Cleft%28%5Cmu%2C%20%5Cfrac%7B%5Csigma%5E2%7D%7Bn%7D%20%5Cright%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \bar{X} &\sim N \left(\mu, \frac{\sigma^2}{n} \right)
                    \end{aligned}")\

Central Limit Theorem {#sec:central_limit_theorem}
---------------------

If ![X\_i](http://chart.apis.google.com/chart?cht=tx&chl=X_i "X_i") is a
random variable with ![E(X\_i) =
\\mu](http://chart.apis.google.com/chart?cht=tx&chl=E%28X_i%29%20%3D%20%5Cmu "E(X_i) = \mu")
and ![Var(X\_i) =
\\sigma\^2](http://chart.apis.google.com/chart?cht=tx&chl=Var%28X_i%29%20%3D%20%5Csigma%5E2 "Var(X_i) = \sigma^2"),
then for large values of
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"), the number of
elements[^11^](#fn11):

\
![\\begin{aligned} Z &= \\frac{\\sqrt{n}(\\bar{X} - \\mu)}{\\sigma} \\\\
&\\sim N(0, 1)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Z%20%26%3D%20%5Cfrac%7B%5Csqrt%7Bn%7D%28%5Cbar%7BX%7D%20-%20%5Cmu%29%7D%7B%5Csigma%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Csim%20N%280%2C%201%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    Z &= \frac{\sqrt{n}(\bar{X} - \mu)}{\sigma} \\
                    &\sim N(0, 1)
                \end{aligned}")\

#### Example 1 {#ssub:example_1}

For example, we’re going to look at light-bulbs. ![X\_i \\sim
Exp(\\theta =
7)](http://chart.apis.google.com/chart?cht=tx&chl=X_i%20%5Csim%20Exp%28%5Ctheta%20%3D%207%29 "X_i \sim Exp(\theta = 7)")
for ![i \\in [1,
40]](http://chart.apis.google.com/chart?cht=tx&chl=i%20%5Cin%20%5B1%2C%2040%5D "i \in [1, 40]").
The light-bulbs have a ![\\lambda = \\frac{1}{7\\text{
days}}](http://chart.apis.google.com/chart?cht=tx&chl=%5Clambda%20%3D%20%5Cfrac%7B1%7D%7B7%5Ctext%7B%20days%7D%7D "\lambda = \frac{1}{7\text{ days}}").

\
![\\begin{aligned} \\theta &= \\frac{1}{\\lambda} \\\\ &= 7 \\text{
days} \\\\ \\implies E(X\_i) &= \\theta \\\\ &= 7 \\\\ Var(X\_i) &=
\\theta\^2 \\\\ &= 7\^2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctheta%20%26%3D%20%5Cfrac%7B1%7D%7B%5Clambda%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%207%20%5Ctext%7B%20days%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cimplies%20E%28X_i%29%20%26%3D%20%5Ctheta%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%207%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28X_i%29%20%26%3D%20%5Ctheta%5E2%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%207%5E2%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \theta &= \frac{1}{\lambda} \\
                        &= 7 \text{ days} \\
                        \implies E(X_i) &= \theta \\
                        &= 7 \\
                        Var(X_i) &= \theta^2 \\
                        &= 7^2
                    \end{aligned}")\

By CLT, we know that ![Z = \\frac{\\bar{X} - 7}{7/\\sqrt{40}} \\sim N(0,
1)](http://chart.apis.google.com/chart?cht=tx&chl=Z%20%3D%20%5Cfrac%7B%5Cbar%7BX%7D%20-%207%7D%7B7%2F%5Csqrt%7B40%7D%7D%20%5Csim%20N%280%2C%201%29 "Z = \frac{\bar{X} - 7}{7/\sqrt{40}} \sim N(0, 1)").

What is the probability that 40 light-bulbs will last for a year?

\
![\\begin{aligned} P(\\sum\_{i=1}\^{40} X\_i \> 365) &= P(\\bar{X} \>
\\frac{365}{40}) \\\\ &= P(\\frac{\\bar{X} - 7}{7 / \\sqrt{40}} \>
\\frac{\\frac{365}{40} - 7}{{7 / \\sqrt{40}}}) \\\\ &= P(Z \> 1.92) \\\\
&= 1 - P(Z \< 1.92) \\\\ &= 0.0274
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28%5Csum_%7Bi%3D1%7D%5E%7B40%7D%20X_i%20%3E%20365%29%20%26%3D%20P%28%5Cbar%7BX%7D%20%3E%20%5Cfrac%7B365%7D%7B40%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28%5Cfrac%7B%5Cbar%7BX%7D%20-%207%7D%7B7%20%2F%20%5Csqrt%7B40%7D%7D%20%3E%20%5Cfrac%7B%5Cfrac%7B365%7D%7B40%7D%20-%207%7D%7B%7B7%20%2F%20%5Csqrt%7B40%7D%7D%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28Z%20%3E%201.92%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201%20-%20P%28Z%20%3C%201.92%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.0274%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(\sum_{i=1}^{40} X_i > 365) &= P(\bar{X} > \frac{365}{40}) \\
                        &= P(\frac{\bar{X} - 7}{7 / \sqrt{40}} > \frac{\frac{365}{40} - 7}{{7 / \sqrt{40}}}) \\
                        &= P(Z > 1.92) \\
                        &= 1 - P(Z < 1.92) \\
                        &= 0.0274
                    \end{aligned}")\

How many light bulbs do we need for the probability of them lasting to
be 99%?

\
![\\begin{aligned} P(\\sum\_{i=1}\^{n} X\_i \> 365) &= P(\\bar{X} \>
\\frac{365}{n}) \\\\ &= P(\\frac{\\bar{X}-7}{7/\\sqrt{n}} \>
\\frac{\\frac{365}{n}-7}{7/\\sqrt{n}}) \\\\ &= P(Z \>
\\frac{\\frac{365}{n}-7}{7/\\sqrt{n}}) \\\\ &= P(Z \> c) \\\\ &= 0.99
\\\\ \\text{Solving for \$c\$ by inverting/etc, we get: } c&=-2.33 \\\\
\\implies n &= 72
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%20X_i%20%3E%20365%29%20%26%3D%20P%28%5Cbar%7BX%7D%20%3E%20%5Cfrac%7B365%7D%7Bn%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28%5Cfrac%7B%5Cbar%7BX%7D-7%7D%7B7%2F%5Csqrt%7Bn%7D%7D%20%3E%20%5Cfrac%7B%5Cfrac%7B365%7D%7Bn%7D-7%7D%7B7%2F%5Csqrt%7Bn%7D%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28Z%20%3E%20%5Cfrac%7B%5Cfrac%7B365%7D%7Bn%7D-7%7D%7B7%2F%5Csqrt%7Bn%7D%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20P%28Z%20%3E%20c%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.99%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Ctext%7BSolving%20for%20%24c%24%20by%20inverting%2Fetc%2C%20we%20get%3A%20%7D%20c%26%3D-2.33%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cimplies%20n%20%26%3D%2072%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(\sum_{i=1}^{n} X_i > 365) &= P(\bar{X} > \frac{365}{n}) \\
                        &= P(\frac{\bar{X}-7}{7/\sqrt{n}} > \frac{\frac{365}{n}-7}{7/\sqrt{n}}) \\
                        &= P(Z > \frac{\frac{365}{n}-7}{7/\sqrt{n}}) \\
                        &= P(Z > c) \\
                        &= 0.99 \\
                        \text{Solving for $c$ by inverting/etc, we get: } c&=-2.33 \\
                        \implies n &= 72
                    \end{aligned}")\

Confidence Intervals I {#cha:confidence_intervals_i}
======================

Point Estimation {#sec:point_estimation}
----------------

Consider a random sample of size ![n = \\{X\_1, \\ldots, X\_n
\\}](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3D%20%5C%7BX_1%2C%20%5Cldots%2C%20X_n%20%5C%7D "n = \{X_1, \ldots, X_n \}").

An appropriate probability model is selected for the experiment.

Given that the probability function for
![X\_i](http://chart.apis.google.com/chart?cht=tx&chl=X_i "X_i") depends
on an unknown parameter
![\\hat{\\theta}](http://chart.apis.google.com/chart?cht=tx&chl=%5Chat%7B%5Ctheta%7D "\hat{\theta}"),
an estimator of
![\\theta](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta "\theta")
is a statistic defined as a function of the random sample:

\
![\\begin{aligned} \\hat{\\theta} &= h(X\_1, \\ldots, X\_n)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Chat%7B%5Ctheta%7D%20%26%3D%20h%28X_1%2C%20%5Cldots%2C%20X_n%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \hat{\theta} &= h(X_1, \ldots, X_n)
                \end{aligned}")\

Unbiased Estimator {#sec:unbiased_estimator}
------------------

Since some estimators are biased, the standard deviation of an estimator
is called its standard error:

\
![\\begin{aligned} SE(\\hat{\\theta}) &= \\sqrt{Var(\\theta)}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20SE%28%5Chat%7B%5Ctheta%7D%29%20%26%3D%20%5Csqrt%7BVar%28%5Ctheta%29%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    SE(\hat{\theta}) &= \sqrt{Var(\theta)}
                \end{aligned}")\

Estimators are unbiased if the expected value is the parameter being
estimated. This means:

\
![\\begin{aligned} E(\\hat{\\theta}) &= \\theta \\\\ SE(\\hat{\\theta})
&= 0
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28%5Chat%7B%5Ctheta%7D%29%20%26%3D%20%5Ctheta%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20SE%28%5Chat%7B%5Ctheta%7D%29%20%26%3D%200%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    E(\hat{\theta}) &= \theta \\
                    SE(\hat{\theta}) &= 0
                \end{aligned}")\

### Proving the Normal Distribution {#sub:proving_the_normal_distribution}

Suppose that ![X\_i \\sim N(\\mu,
\\sigma)](http://chart.apis.google.com/chart?cht=tx&chl=X_i%20%5Csim%20N%28%5Cmu%2C%20%5Csigma%29 "X_i \sim N(\mu, \sigma)"),
show that the sample mean
![\\bar{X}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7BX%7D "\bar{X}")
and sample variance
![S\^2](http://chart.apis.google.com/chart?cht=tx&chl=S%5E2 "S^2") are
unbiased estimators of
![\\mu](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu "\mu") and
![\\sigma\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma%5E2 "\sigma^2").

\
![\\begin{aligned} \\bar{X} &= \\frac{1}{n} \\sum\_{i = 1}\^{n} X\_i
\\\\ S\^2 &= \\frac{1}{n-1} \\sum\_{i=1}\^n (X\_i - \\bar{X})\^2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbar%7BX%7D%20%26%3D%20%5Cfrac%7B1%7D%7Bn%7D%20%5Csum_%7Bi%20%3D%201%7D%5E%7Bn%7D%20X_i%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20S%5E2%20%26%3D%20%5Cfrac%7B1%7D%7Bn-1%7D%20%5Csum_%7Bi%3D1%7D%5En%20%28X_i%20-%20%5Cbar%7BX%7D%29%5E2%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \bar{X} &= \frac{1}{n} \sum_{i = 1}^{n} X_i \\
                        S^2 &= \frac{1}{n-1} \sum_{i=1}^n (X_i - \bar{X})^2
                    \end{aligned}")\

Statistical Inference {#sec:statistical_inference}
---------------------

In order to statistically infer things, we need to quantify the sample
error first.

We do this using confidence intervals, and hypothesis tests.

### Confidence Interval {#sub:confidence_interval}

We can define the probability
![\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha "\alpha")
as the probability that a random interval doesn’t contain the true value
of the parameter.

Then ![(1-
\\alpha)\\%](http://chart.apis.google.com/chart?cht=tx&chl=%281-%20%5Calpha%29%5C%25 "(1- \alpha)\%")
is the confidence in an interval for a parameter
![\\theta](http://chart.apis.google.com/chart?cht=tx&chl=%5Ctheta "\theta").
This confidence is calculated by observing a random interval ![(L(X),
U(X))](http://chart.apis.google.com/chart?cht=tx&chl=%28L%28X%29%2C%20U%28X%29%29 "(L(X), U(X))")
such that:

\
![\\begin{aligned} P(L(X) \< \\theta \< U(X)) &= 1 - \\alpha
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20P%28L%28X%29%20%3C%20%5Ctheta%20%3C%20U%28X%29%29%20%26%3D%201%20-%20%5Calpha%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        P(L(X) < \theta < U(X)) &= 1 - \alpha
                    \end{aligned}")\

It’s important that this ends on the interval ![(L(X),
U(X))](http://chart.apis.google.com/chart?cht=tx&chl=%28L%28X%29%2C%20U%28X%29%29 "(L(X), U(X))")
which are random.

We generally set
![L(X)](http://chart.apis.google.com/chart?cht=tx&chl=L%28X%29 "L(X)")
and
![U(X)](http://chart.apis.google.com/chart?cht=tx&chl=U%28X%29 "U(X)"),
then observe the value of the parameter over the interval.

After observing the interval
![L(X)](http://chart.apis.google.com/chart?cht=tx&chl=L%28X%29 "L(X)")
and
![U(X)](http://chart.apis.google.com/chart?cht=tx&chl=U%28X%29 "U(X)"),
our confidence of the interval is
![1-\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=1-%5Calpha "1-\alpha").

### Normal Confidence Interval for Known ![\\sigma](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma "\sigma") and Unknown ![\\mu](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu "\mu") {#sub:normal_confidence_interval}

For normally distributed identically distributed sample of size
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"), ![X\_i \\sim
N(\\mu,
\\sigma\_0\^2)](http://chart.apis.google.com/chart?cht=tx&chl=X_i%20%5Csim%20N%28%5Cmu%2C%20%5Csigma_0%5E2%29 "X_i \sim N(\mu, \sigma_0^2)"),
with a known
![\\sigma\_0\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma_0%5E2 "\sigma_0^2")
and unknown
![\\mu](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu "\mu").

The pivotal quantity:

\
![\\begin{aligned} Z &= \\frac{\\bar{X} - \\mu}{\\sigma\_0 / \\sqrt{n}}
\\\\ &\\sim N(0, 1)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Z%20%26%3D%20%5Cfrac%7B%5Cbar%7BX%7D%20-%20%5Cmu%7D%7B%5Csigma_0%20%2F%20%5Csqrt%7Bn%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Csim%20N%280%2C%201%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        Z &= \frac{\bar{X} - \mu}{\sigma_0 / \sqrt{n}} \\
                        &\sim N(0, 1)
                    \end{aligned}")\

A
![(1-\\alpha)\\%](http://chart.apis.google.com/chart?cht=tx&chl=%281-%5Calpha%29%5C%25 "(1-\alpha)\%")
confidence interval for
![\\mu](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu "\mu") is
given by:

\
![\\begin{aligned} \\mu &= \\bar{x} \\pm z\_{1 - \\frac{\\alpha}{2}}
\\frac{\\sigma\_0}{\\sqrt{n}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmu%20%26%3D%20%5Cbar%7Bx%7D%20%5Cpm%20z_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%5Cfrac%7B%5Csigma_0%7D%7B%5Csqrt%7Bn%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \mu &= \bar{x} \pm z_{1 - \frac{\alpha}{2}} \frac{\sigma_0}{\sqrt{n}}
                    \end{aligned}")\

Where
![z\_\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=z_%5Calpha "z_\alpha")
is the
![\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha "\alpha")-quantile
- a value such that ![P(Z \< z\_\\alpha) =
\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=P%28Z%20%3C%20z_%5Calpha%29%20%3D%20%5Calpha "P(Z < z_\alpha) = \alpha").

The **margin of error** for the confidence interval is the distance
between the point estimated and the ends of the interval. It’s
effectively measured by how “off” a confidence interval can be. In the
![1-\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=1-%5Calpha "1-\alpha")
case a few lines prior, the confidence interval is:

\
![\\begin{aligned} z\_{1 - \\frac{\\alpha}{2}}
\\frac{\\sigma\_0}{\\sqrt{n}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20z_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%5Cfrac%7B%5Csigma_0%7D%7B%5Csqrt%7Bn%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        z_{1 - \frac{\alpha}{2}} \frac{\sigma_0}{\sqrt{n}}
                    \end{aligned}")\

It is important to note that when solving for a size
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") that gives a
requested confidence interval, it is important to round up (and be
over-precise) than to round down (and be under-precise).

#### Example 1 {#ssub:example_1}

Suppose we have ![\\sigma\_0\^2 = 1 500
000](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma_0%5E2%20%3D%201%20500%20000 "\sigma_0^2 = 1 500 000"),
and want a 95% confidence interval. We have measured ![\\bar{x} = 70
000](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7Bx%7D%20%3D%2070%20000 "\bar{x} = 70 000")
across ![n =
100](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3D%20100 "n = 100")
samples.

Since ![1 - \\alpha =
.95](http://chart.apis.google.com/chart?cht=tx&chl=1%20-%20%5Calpha%20%3D%20.95 "1 - \alpha = .95"),
we must have ![\\alpha =
0.05](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha%20%3D%200.05 "\alpha = 0.05").

Then we have ![z\_{1 - \\frac{\\alpha}{2}} =
z\_{0.95}](http://chart.apis.google.com/chart?cht=tx&chl=z_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%3D%20z_%7B0.95%7D "z_{1 - \frac{\alpha}{2}} = z_{0.95}").
Plugging into ![P(Z \< z\_{0.95}) =
0.95](http://chart.apis.google.com/chart?cht=tx&chl=P%28Z%20%3C%20z_%7B0.95%7D%29%20%3D%200.95 "P(Z < z_{0.95}) = 0.95"),
we get ![z\_{0.95} =
1.645](http://chart.apis.google.com/chart?cht=tx&chl=z_%7B0.95%7D%20%3D%201.645 "z_{0.95} = 1.645").

We have the margin of error as ![1.645 \\sqrt{\\frac{1 500 000}{100}} =
201.47](http://chart.apis.google.com/chart?cht=tx&chl=1.645%20%5Csqrt%7B%5Cfrac%7B1%20500%20000%7D%7B100%7D%7D%20%3D%20201.47 "1.645 \sqrt{\frac{1 500 000}{100}} = 201.47").

That means that a 90% confidence interval for the measured variable is
given by ![(70 000 - 201.97, 70 000 + 201.97) = (69798.03,
70201.97)](http://chart.apis.google.com/chart?cht=tx&chl=%2870%20000%20-%20201.97%2C%2070%20000%20%2B%20201.97%29%20%3D%20%2869798.03%2C%2070201.97%29 "(70 000 - 201.97, 70 000 + 201.97) = (69798.03, 70201.97)").

### Binomial Confidence Interval {#sub:binomial_confidence_interval}

When ![X\_i \\sim Bin(n,
p)](http://chart.apis.google.com/chart?cht=tx&chl=X_i%20%5Csim%20Bin%28n%2C%20p%29 "X_i \sim Bin(n, p)")[^12^](#fn12),
we know that ![E(X\_i) =
p](http://chart.apis.google.com/chart?cht=tx&chl=E%28X_i%29%20%3D%20p "E(X_i) = p")
and the variance is ![Var(X\_i) = p(1 -
p)](http://chart.apis.google.com/chart?cht=tx&chl=Var%28X_i%29%20%3D%20p%281%20-%20p%29 "Var(X_i) = p(1 - p)").

We can estimate the probability of success as:

\
![\\begin{aligned} \\hat{p} &= \\frac{X}{n} \\\\ &= \\frac{
\\sum\_{i=1}\^n x\_i}{n} \\\\ &= \\bar{\\alpha} \\\\ \\implies
E(\\hat{p}) &= p \\\\ Var(\\hat{p}) &= \\frac{Var(X\_i)}{n} \\\\ &=
\\frac{p(1-p)}{n}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Chat%7Bp%7D%20%26%3D%20%5Cfrac%7BX%7D%7Bn%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7B%20%5Csum_%7Bi%3D1%7D%5En%20x_i%7D%7Bn%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cbar%7B%5Calpha%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cimplies%20E%28%5Chat%7Bp%7D%29%20%26%3D%20p%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28%5Chat%7Bp%7D%29%20%26%3D%20%5Cfrac%7BVar%28X_i%29%7D%7Bn%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cfrac%7Bp%281-p%29%7D%7Bn%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \hat{p} &= \frac{X}{n} \\
                        &= \frac{ \sum_{i=1}^n x_i}{n} \\
                        &= \bar{\alpha} \\
                        \implies E(\hat{p}) &= p \\
                        Var(\hat{p}) &= \frac{Var(X_i)}{n} \\
                        &= \frac{p(1-p)}{n}
                    \end{aligned}")\

Using the binomial approximation, if ![n\\hat{p} \>
5](http://chart.apis.google.com/chart?cht=tx&chl=n%5Chat%7Bp%7D%20%3E%205 "n\hat{p} > 5")
and ![n (1 - \\hat{p}) \>
5](http://chart.apis.google.com/chart?cht=tx&chl=n%20%281%20-%20%5Chat%7Bp%7D%29%20%3E%205 "n (1 - \hat{p}) > 5"),
then by the central limit theorem (see
Section [sec:central~l~imit~t~heorem]):

\
![\\begin{aligned} Z &= \\frac{\\hat{p} - p}{\\sqrt{p (1 - p) / n}} \\\\
&\\sim N(0, 1)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Z%20%26%3D%20%5Cfrac%7B%5Chat%7Bp%7D%20-%20p%7D%7B%5Csqrt%7Bp%20%281%20-%20p%29%20%2F%20n%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Csim%20N%280%2C%201%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        Z &= \frac{\hat{p} - p}{\sqrt{p (1 - p) / n}} \\
                        &\sim N(0, 1)
                    \end{aligned}")\

An approximate
![(1-\\alpha)\\%](http://chart.apis.google.com/chart?cht=tx&chl=%281-%5Calpha%29%5C%25 "(1-\alpha)\%")
confidence interval for the percentage
![p](http://chart.apis.google.com/chart?cht=tx&chl=p "p") is given by:

\
![\\begin{aligned} \\hat{p} \\pm z\_{1 - \\frac{\\alpha}{2}}
\\sqrt{\\frac{\\hat{p}(1 - \\hat{p})}{n}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Chat%7Bp%7D%20%5Cpm%20z_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%5Csqrt%7B%5Cfrac%7B%5Chat%7Bp%7D%281%20-%20%5Chat%7Bp%7D%29%7D%7Bn%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                        \hat{p} \pm z_{1 - \frac{\alpha}{2}} \sqrt{\frac{\hat{p}(1 - \hat{p})}{n}}
                    \end{aligned}")\

#### Example 1 {#ssub:example_1}

Given that ![X =
18](http://chart.apis.google.com/chart?cht=tx&chl=X%20%3D%2018 "X = 18")
students prefer smarties over M&Ms out of the ![n =
87](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3D%2087 "n = 87")
asked, and we want to have ![\\alpha =
0.1](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha%20%3D%200.1 "\alpha = 0.1"),
we have:

\
![\\begin{aligned} \\hat{p} &= \\frac{18}{87} \\\\ &= 0.2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Chat%7Bp%7D%20%26%3D%20%5Cfrac%7B18%7D%7B87%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%200.2%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                            \hat{p} &= \frac{18}{87} \\
                            &= 0.2
                        \end{aligned}")\

Solving for
![z\_{\\ldots}](http://chart.apis.google.com/chart?cht=tx&chl=z_%7B%5Cldots%7D "z_{\ldots}"):

\
![\\begin{aligned} z\_{1 - \\frac{\\alpha}{2}} &= z\_{0.95} \\\\ &=
1.645
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20z_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%26%3D%20z_%7B0.95%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%201.645%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                            z_{1 - \frac{\alpha}{2}} &= z_{0.95} \\
                            &= 1.645
                        \end{aligned}")\

Thus, our bounds of
![p](http://chart.apis.google.com/chart?cht=tx&chl=p "p") within
![\\alpha =
1](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha%20%3D%201 "\alpha = 1")
is:

\
![\\begin{aligned} p &\\in (0.2 - 1.645 \\sqrt{\\frac{(0.2)(0.8)}{87}},
0.2 + 1.645 \\sqrt{\\frac{(0.2)(0.8)}{87}}) \\\\ &= (13, 27)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20p%20%26%5Cin%20%280.2%20-%201.645%20%5Csqrt%7B%5Cfrac%7B%280.2%29%280.8%29%7D%7B87%7D%7D%2C%200.2%20%2B%201.645%20%5Csqrt%7B%5Cfrac%7B%280.2%29%280.8%29%7D%7B87%7D%7D%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%2813%2C%2027%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                            p &\in (0.2 - 1.645 \sqrt{\frac{(0.2)(0.8)}{87}}, 0.2 + 1.645 \sqrt{\frac{(0.2)(0.8)}{87}}) \\
                            &= (13, 27)
                        \end{aligned}")\

Thus ![(13,
27)](http://chart.apis.google.com/chart?cht=tx&chl=%2813%2C%2027%29 "(13, 27)")%
of students prefer smarties over M&Ms.

Chi-Squared Distribution {#sec:chi_squared_distribution}
------------------------

If ![X\_1, \\ldots,
X\_k](http://chart.apis.google.com/chart?cht=tx&chl=X_1%2C%20%5Cldots%2C%20X_k "X_1, \ldots, X_k")
are independent, standard normal random variables ![\\sim N(0,
1)](http://chart.apis.google.com/chart?cht=tx&chl=%5Csim%20N%280%2C%201%29 "\sim N(0, 1)"),
then the sum of their squares ![Q = \\sum\_{i=1}\^k
Z\_i\^2](http://chart.apis.google.com/chart?cht=tx&chl=Q%20%3D%20%5Csum_%7Bi%3D1%7D%5Ek%20Z_i%5E2 "Q = \sum_{i=1}^k Z_i^2")
is distributed according to the chi-squared distribution with
![k](http://chart.apis.google.com/chart?cht=tx&chl=k "k") degrees of
freedom:

\
![\\begin{aligned} Q &\\sim \\chi\^2[k]
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Q%20%26%5Csim%20%5Cchi%5E2%5Bk%5D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    Q &\sim \chi^2[k]
                \end{aligned}")\

Since the pdf of
![\\chi\^2[k]](http://chart.apis.google.com/chart?cht=tx&chl=%5Cchi%5E2%5Bk%5D "\chi^2[k]")
is not integrable, we use the
![\\chi\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Cchi%5E2 "\chi^2")
table to calculate probabilities. See Appendix [cha:chi~s~quared~t~able]
for the table.

When ![R \\sim
\\chi\^2[n]](http://chart.apis.google.com/chart?cht=tx&chl=R%20%5Csim%20%5Cchi%5E2%5Bn%5D "R \sim \chi^2[n]"),
then:

\
![\\begin{aligned} E(R) &= n \\\\ Var(R) &= 2n
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20E%28R%29%20%26%3D%20n%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Var%28R%29%20%26%3D%202n%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    E(R) &= n \\
                    Var(R) &= 2n
                \end{aligned}")\

If ![R\_1 \\sim
\\chi\^2[n\_1]](http://chart.apis.google.com/chart?cht=tx&chl=R_1%20%5Csim%20%5Cchi%5E2%5Bn_1%5D "R_1 \sim \chi^2[n_1]")
is independent of ![R\_2 \\sim
\\chi\^2[n\_2]](http://chart.apis.google.com/chart?cht=tx&chl=R_2%20%5Csim%20%5Cchi%5E2%5Bn_2%5D "R_2 \sim \chi^2[n_2]"),
then:

\
![\\begin{aligned} R\_1 + R\_2 \\sim \\chi\^2[n\_1 + n\_2]
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20R_1%20%2B%20R_2%20%5Csim%20%5Cchi%5E2%5Bn_1%20%2B%20n_2%5D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    R_1 + R_2 \sim \chi^2[n_1 + n_2]
                \end{aligned}")\

That is, the sum of two random independent variables is equal to the sum
of their probability distribution functions.

Sample Variance {#sec:sample_variance}
---------------

If ![X\_1, \\ldots,
X\_n](http://chart.apis.google.com/chart?cht=tx&chl=X_1%2C%20%5Cldots%2C%20X_n "X_1, \ldots, X_n")
are independent, standard normal random variables ![\\sim N(\\mu,
\\sigma\^2)](http://chart.apis.google.com/chart?cht=tx&chl=%5Csim%20N%28%5Cmu%2C%20%5Csigma%5E2%29 "\sim N(\mu, \sigma^2)"),
and the sample variance is:

\
![\\begin{aligned} S\^2 &= \\frac{1}{n-1} \\sum\_{i=1}\^n (X\_i -
\\bar{X})\^2
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20S%5E2%20%26%3D%20%5Cfrac%7B1%7D%7Bn-1%7D%20%5Csum_%7Bi%3D1%7D%5En%20%28X_i%20-%20%5Cbar%7BX%7D%29%5E2%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                     S^2 &= \frac{1}{n-1} \sum_{i=1}^n (X_i - \bar{X})^2
                 \end{aligned}")\

For ![S\^2](http://chart.apis.google.com/chart?cht=tx&chl=S%5E2 "S^2")
is independent of
![\\bar{X}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7BX%7D "\bar{X}"),
we have:

\
![\\begin{aligned} \\frac{(n-1) S\^2}{\\sigma\^2} &\\sim \\chi\^2[n-1]
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B%28n-1%29%20S%5E2%7D%7B%5Csigma%5E2%7D%20%26%5Csim%20%5Cchi%5E2%5Bn-1%5D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                     \frac{(n-1) S^2}{\sigma^2} &\sim \chi^2[n-1]
                 \end{aligned}")\

Normal Confidence Intervals for known ![\\sigma\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma%5E2 "\sigma^2") and Unknown ![\\mu](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu "\mu") {#sec:normal_confidence_intervals_for_sigma_squared}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Using
![\\chi\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Cchi%5E2 "\chi^2")
distributions, we can help find the variance in a distribution.

For a normally distributed iid with ![X\_i \\sim N(\\mu,
\\sigma\^2)](http://chart.apis.google.com/chart?cht=tx&chl=X_i%20%5Csim%20N%28%5Cmu%2C%20%5Csigma%5E2%29 "X_i \sim N(\mu, \sigma^2)")
of size ![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n"), we
have:

The Pivotal Quantity:

\
![\\begin{aligned} \\frac{(n-1)S\^2}{\\sigma\^2} &\\sim \\chi\^2[n - 1]
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B%28n-1%29S%5E2%7D%7B%5Csigma%5E2%7D%20%26%5Csim%20%5Cchi%5E2%5Bn%20-%201%5D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \frac{(n-1)S^2}{\sigma^2} &\sim \chi^2[n - 1]
                \end{aligned}")\

A ![(1 -
\\alpha)\\%](http://chart.apis.google.com/chart?cht=tx&chl=%281%20-%20%5Calpha%29%5C%25 "(1 - \alpha)\%")
confidence interval for
![\\sigma\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma%5E2 "\sigma^2")
is given by:

\
![\\begin{aligned} \\sigma\^2 &= \\left(
\\frac{(n-1)S\^2}{\\chi\_{1-\\frac{\\alpha}{2}}\^2 [n - 1]},
\\frac{(n-1)S\^2}{\\chi\_{\\frac{\\alpha}{2}}\^2 [n - 1]} \\right)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Csigma%5E2%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%28%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B%28n-1%29S%5E2%7D%7B%5Cchi_%7B1-%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%5E2%20%5Bn%20-%201%5D%7D%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B%28n-1%29S%5E2%7D%7B%5Cchi_%7B%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%5E2%20%5Bn%20-%201%5D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \sigma^2 &=
                    \left(
                        \frac{(n-1)S^2}{\chi_{1-\frac{\alpha}{2}}^2 [n - 1]},
                        \frac{(n-1)S^2}{\chi_{\frac{\alpha}{2}}^2 [n - 1]}
                    \right)
                \end{aligned}")\

Where ![\\chi\_\\alpha\^2
[n-1]](http://chart.apis.google.com/chart?cht=tx&chl=%5Cchi_%5Calpha%5E2%20%5Bn-1%5D "\chi_\alpha^2 [n-1]")
is the value from the Chi-Squared table (See
Appendix [cha:chi~s~quared~t~able]) such that ![P(S \< \\chi\_\\alpha\^2
[n-1]) =
\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=P%28S%20%3C%20%5Cchi_%5Calpha%5E2%20%5Bn-1%5D%29%20%3D%20%5Calpha "P(S < \chi_\alpha^2 [n-1]) = \alpha").

Student ![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t")-Distribution {#sec:student_t_distribution}
------------------------------------------------------------------------------

If ![Z \\sim N(0,
1)](http://chart.apis.google.com/chart?cht=tx&chl=Z%20%5Csim%20N%280%2C%201%29 "Z \sim N(0, 1)")
is independent of ![S \\sim
\\chi\^2[n]](http://chart.apis.google.com/chart?cht=tx&chl=S%20%5Csim%20%5Cchi%5E2%5Bn%5D "S \sim \chi^2[n]"),
and

\
![\\begin{aligned} T &= \\frac{Z}{\\sqrt{\\frac{S}{n}}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%20%26%3D%20%5Cfrac%7BZ%7D%7B%5Csqrt%7B%5Cfrac%7BS%7D%7Bn%7D%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    T &= \frac{Z}{\sqrt{\frac{S}{n}}}
                \end{aligned}")\

Then ![T](http://chart.apis.google.com/chart?cht=tx&chl=T "T") has a
Students t-distribution with
![n](http://chart.apis.google.com/chart?cht=tx&chl=n "n") degrees of
freedom.

\
![\\begin{aligned} T &\\sim t[n]
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%20%26%5Csim%20t%5Bn%5D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    T &\sim t[n]
                \end{aligned}")\

The pdf of the
![t[n]](http://chart.apis.google.com/chart?cht=tx&chl=t%5Bn%5D "t[n]")
distribution is not integrable, so we use the
![t](http://chart.apis.google.com/chart?cht=tx&chl=t "t")-table to
calculate probabilities. This can be found in
Appendix [cha:student~tr~eference~t~able].

Normal Confidence Intervals for Unknown ![\\sigma](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma "\sigma") and Known ![\\mu](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu "\mu") {#sec:normal_confidence_intervals_for_unknown_}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

In the case that an iid sample ![X\_i \\sim N(\\mu,
\\sigma)](http://chart.apis.google.com/chart?cht=tx&chl=X_i%20%5Csim%20N%28%5Cmu%2C%20%5Csigma%29 "X_i \sim N(\mu, \sigma)"),
with
![\\sigma](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma "\sigma")
unknown.

\
![\\begin{aligned} T &= \\frac{\\bar{X} - \\mu}{\\frac{S}{\\sqrt{n}}}
\\\\ &\\sim t[n-1]
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20T%20%26%3D%20%5Cfrac%7B%5Cbar%7BX%7D%20-%20%5Cmu%7D%7B%5Cfrac%7BS%7D%7B%5Csqrt%7Bn%7D%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Csim%20t%5Bn-1%5D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    T &= \frac{\bar{X} - \mu}{\frac{S}{\sqrt{n}}} \\
                    &\sim t[n-1]
                \end{aligned}")\

A ![(1 -
\\alpha)\\%](http://chart.apis.google.com/chart?cht=tx&chl=%281%20-%20%5Calpha%29%5C%25 "(1 - \alpha)\%")
confidence interval for
![\\mu](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu "\mu") is
given by:

\
![\\begin{aligned} \\mu &= \\bar{x} \\pm t\_{1 -
\\frac{\\alpha}{2}}[n-1] \\frac{s}{\\sqrt{n}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmu%20%26%3D%20%5Cbar%7Bx%7D%20%5Cpm%20t_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%5Bn-1%5D%20%5Cfrac%7Bs%7D%7B%5Csqrt%7Bn%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \mu &= \bar{x} \pm t_{1 - \frac{\alpha}{2}}[n-1] \frac{s}{\sqrt{n}}
                \end{aligned}")\

Where
![t\_\\alpha[n-1]](http://chart.apis.google.com/chart?cht=tx&chl=t_%5Calpha%5Bn-1%5D "t_\alpha[n-1]")
is the
![\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha "\alpha")-quantile
of the
![t-](http://chart.apis.google.com/chart?cht=tx&chl=t- "t-")distribution
with ![n-1](http://chart.apis.google.com/chart?cht=tx&chl=n-1 "n-1")
degrees of freedom, ![P(T \< t\_\\alpha[n-1]) =
\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=P%28T%20%3C%20t_%5Calpha%5Bn-1%5D%29%20%3D%20%5Calpha "P(T < t_\alpha[n-1]) = \alpha").

#### Example 1 {#ssub:example_1}

In a public transit system, we have ![n =
50](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3D%2050 "n = 50"),
![\\bar{x} =
44](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbar%7Bx%7D%20%3D%2044 "\bar{x} = 44"),
![s\^2 =
25](http://chart.apis.google.com/chart?cht=tx&chl=s%5E2%20%3D%2025 "s^2 = 25")
and a
![\\alpha](http://chart.apis.google.com/chart?cht=tx&chl=%5Calpha "\alpha")
specified as
![0.05](http://chart.apis.google.com/chart?cht=tx&chl=0.05 "0.05").

Let ![X\_i](http://chart.apis.google.com/chart?cht=tx&chl=X_i "X_i") be
the time it takes the
![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i")th person to
commute. Assume ![X\_i \\sim N(\\mu,
\\sigma\^2)](http://chart.apis.google.com/chart?cht=tx&chl=X_i%20%5Csim%20N%28%5Cmu%2C%20%5Csigma%5E2%29 "X_i \sim N(\mu, \sigma^2)").

-   Find ![(1 - \\alpha) =
    95\\%](http://chart.apis.google.com/chart?cht=tx&chl=%281%20-%20%5Calpha%29%20%3D%2095%5C%25 "(1 - \alpha) = 95\%")
    confidence interval for
    ![\\mu](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu "\mu"),
    the mean commute time:

    \
    ![\\begin{aligned} \\mu &= \\bar{x} \\pm t\_{1 -
    \\frac{\\alpha}{2}}[n-1] \\frac{s}{\\sqrt{n}} \\\\ &= (44 \\pm
    2.01\\left( \\frac{5}{\\sqrt{50}} \\right)) \\\\ &= (44 \\pm 1.42)
    \\\\
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmu%20%26%3D%20%5Cbar%7Bx%7D%20%5Cpm%20t_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%5Bn-1%5D%20%5Cfrac%7Bs%7D%7B%5Csqrt%7Bn%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%2844%20%5Cpm%202.01%5Cleft%28%20%5Cfrac%7B5%7D%7B%5Csqrt%7B50%7D%7D%20%5Cright%29%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%2844%20%5Cpm%201.42%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                                    \mu &= \bar{x} \pm t_{1 - \frac{\alpha}{2}}[n-1] \frac{s}{\sqrt{n}} \\
                                    &= (44 \pm 2.01\left( \frac{5}{\sqrt{50}} \right)) \\
                                    &= (44 \pm 1.42) \\
                                \end{aligned}")\

    Thus, a 95% confidence interval for
    ![\\mu](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu "\mu")
    is ![(42.58,
    45.42)](http://chart.apis.google.com/chart?cht=tx&chl=%2842.58%2C%2045.42%29 "(42.58, 45.42)").

-   Find a ![(1 - \\alpha) =
    95\\%](http://chart.apis.google.com/chart?cht=tx&chl=%281%20-%20%5Calpha%29%20%3D%2095%5C%25 "(1 - \alpha) = 95\%")
    confidence interval for commute time variance:

    \
    ![\\begin{aligned} \\sigma\^2 &= \\left(
    \\frac{(n-1)S\^2}{\\chi\_{1-\\frac{\\alpha}{2}}\^2 [n - 1]},
    \\frac{(n-1)S\^2}{\\chi\_{\\frac{\\alpha}{2}}\^2 [n - 1]} \\right)
    \\\\ &= \\left( \\frac{(n-1)S\^2}{67.5}, \\frac{(n-1)S\^2}{34.8}
    \\right) \\\\ &= \\left( 18.15, 35.2 \\right)
    \\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Csigma%5E2%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%28%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B%28n-1%29S%5E2%7D%7B%5Cchi_%7B1-%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%5E2%20%5Bn%20-%201%5D%7D%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B%28n-1%29S%5E2%7D%7B%5Cchi_%7B%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%5E2%20%5Bn%20-%201%5D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%28%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B%28n-1%29S%5E2%7D%7B67.5%7D%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B%28n-1%29S%5E2%7D%7B34.8%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cleft%28%2018.15%2C%2035.2%20%5Cright%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                                    \sigma^2 &=
                                        \left(
                                            \frac{(n-1)S^2}{\chi_{1-\frac{\alpha}{2}}^2 [n - 1]},
                                            \frac{(n-1)S^2}{\chi_{\frac{\alpha}{2}}^2 [n - 1]}
                                        \right) \\
                                    &=
                                        \left(
                                            \frac{(n-1)S^2}{67.5},
                                            \frac{(n-1)S^2}{34.8}
                                        \right) \\
                                    &= \left( 18.15, 35.2 \right)
                                \end{aligned}")\

    Therefore, a 90% confidence interval for
    ![\\sigma](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma "\sigma")
    is[^13^](#fn13) ![(4.26,
    5.93)](http://chart.apis.google.com/chart?cht=tx&chl=%284.26%2C%205.93%29 "(4.26, 5.93)").

Summary {#sec:summary}
-------

For known
![\\sigma\_0\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma_0%5E2 "\sigma_0^2"),
we have the confidence interval on
![\\mu](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu "\mu"):

\
![\\begin{aligned} \\bar{x} \\pm z\_{1 - \\frac{\\alpha}{2}}
\\frac{\\sigma\_0}{\\sqrt{n}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbar%7Bx%7D%20%5Cpm%20z_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%5Cfrac%7B%5Csigma_0%7D%7B%5Csqrt%7Bn%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \bar{x} \pm z_{1 - \frac{\alpha}{2}} \frac{\sigma_0}{\sqrt{n}}
                \end{aligned}")\

For unknown
![\\sigma\_0\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma_0%5E2 "\sigma_0^2"),
we have the confidence interval on
![\\mu](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu "\mu"):

\
![\\begin{aligned} \\bar{x} \\pm t\_{1 - \\frac{\\alpha}{2}}[n-1]
\\frac{s}{\\sqrt{n}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbar%7Bx%7D%20%5Cpm%20t_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%5Bn-1%5D%20%5Cfrac%7Bs%7D%7B%5Csqrt%7Bn%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \bar{x} \pm t_{1 - \frac{\alpha}{2}}[n-1] \frac{s}{\sqrt{n}}
                \end{aligned}")\

The confidence interval of
![\\sigma\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma%5E2 "\sigma^2"):

\
![\\begin{aligned} \\left(
\\frac{(n-1)S\^2}{\\chi\_{1-\\frac{\\alpha}{2}}\^2 [n - 1]},
\\frac{(n-1)S\^2}{\\chi\_{\\frac{\\alpha}{2}}\^2 [n - 1]} \\right)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%28%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B%28n-1%29S%5E2%7D%7B%5Cchi_%7B1-%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%5E2%20%5Bn%20-%201%5D%7D%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B%28n-1%29S%5E2%7D%7B%5Cchi_%7B%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%5E2%20%5Bn%20-%201%5D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \left(
                        \frac{(n-1)S^2}{\chi_{1-\frac{\alpha}{2}}^2 [n - 1]},
                        \frac{(n-1)S^2}{\chi_{\frac{\alpha}{2}}^2 [n - 1]}
                    \right)
                \end{aligned}")\

Confidence interval for
![\\hat{p}](http://chart.apis.google.com/chart?cht=tx&chl=%5Chat%7Bp%7D "\hat{p}"):

\
![\\begin{aligned} \\hat{p} \\pm z\_{1 - \\frac{\\alpha}{2}}
\\sqrt{\\frac{\\hat{p} ( 1 - \\hat{p})}{n}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Chat%7Bp%7D%20%5Cpm%20z_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%5Csqrt%7B%5Cfrac%7B%5Chat%7Bp%7D%20%28%201%20-%20%5Chat%7Bp%7D%29%7D%7Bn%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \hat{p} \pm z_{1 - \frac{\alpha}{2}} \sqrt{\frac{\hat{p} ( 1 - \hat{p})}{n}}
                \end{aligned}")\

Confidence Intervals II {#cha:confidence_intervals_ii}
=======================

We can do more than just the confidence interval of one mean. We can
extract exact confidence intervals for dependent observations, and
approximate confidence intervals for independent observations.

Confidence Intervals for Differences of Means {#sec:confidence_intervals_for_differences_of_means}
---------------------------------------------

With paired observations ![(x\_i,
y\_i)](http://chart.apis.google.com/chart?cht=tx&chl=%28x_i%2C%20y_i%29 "(x_i, y_i)"),
where ![X \\sim N(\\mu\_X,
\\sigma\_X\^2)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20N%28%5Cmu_X%2C%20%5Csigma_X%5E2%29 "X \sim N(\mu_X, \sigma_X^2)")
and ![Y \\sim N(\\mu\_Y,
\\sigma\_Y\^2)](http://chart.apis.google.com/chart?cht=tx&chl=Y%20%5Csim%20N%28%5Cmu_Y%2C%20%5Csigma_Y%5E2%29 "Y \sim N(\mu_Y, \sigma_Y^2)")
are two random variables measured from the same unit of the population.

We want to define a new variable ![D = X - Y \\sim N(\\mu\_D,
\\sigma\_D\^2)](http://chart.apis.google.com/chart?cht=tx&chl=D%20%3D%20X%20-%20Y%20%5Csim%20N%28%5Cmu_D%2C%20%5Csigma_D%5E2%29 "D = X - Y \sim N(\mu_D, \sigma_D^2)")
with the observation that:

\
![\\begin{aligned} d\_i &= x\_i - y\_i \\\\ \\implies E(D) &= E(X - Y) =
E(X) - E(Y) \\\\ &= \\mu\_X - \\mu\_Y
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20d_i%20%26%3D%20x_i%20-%20y_i%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cimplies%20E%28D%29%20%26%3D%20E%28X%20-%20Y%29%20%3D%20E%28X%29%20-%20E%28Y%29%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%5Cmu_X%20-%20%5Cmu_Y%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    d_i &= x_i - y_i \\
                    \implies E(D) &= E(X - Y) = E(X) - E(Y) \\
                    &= \mu_X - \mu_Y
                \end{aligned}")\

Using single mean methods, we get ![(1 -
\\alpha)\\%](http://chart.apis.google.com/chart?cht=tx&chl=%281%20-%20%5Calpha%29%5C%25 "(1 - \alpha)\%")
confidence interval:

\
![\\begin{aligned} \\mu\_d &= \\bar{d} \\pm t\_{1 - \\frac{\\alpha}{2}}
[n-1] \\frac{s\_d}{\\sqrt{n}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmu_d%20%26%3D%20%5Cbar%7Bd%7D%20%5Cpm%20t_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%5Bn-1%5D%20%5Cfrac%7Bs_d%7D%7B%5Csqrt%7Bn%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \mu_d &= \bar{d} \pm t_{1 - \frac{\alpha}{2}} [n-1] \frac{s_d}{\sqrt{n}}
                \end{aligned}")\

A ![(1 -
\\alpha)\\%](http://chart.apis.google.com/chart?cht=tx&chl=%281%20-%20%5Calpha%29%5C%25 "(1 - \alpha)\%")
confidence interval for ![\\mu\_X -
\\mu\_Y](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu_X%20-%20%5Cmu_Y "\mu_X - \mu_Y")
is given by:

\
![\\begin{aligned} \\mu\_X - \\mu\_Y &= (\\bar{x} - \\bar{y}) \\pm t\_{1
- \\frac{\\alpha}{2}} [n-1] \\frac{s\_d}{\\sqrt{n}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmu_X%20-%20%5Cmu_Y%20%26%3D%20%28%5Cbar%7Bx%7D%20-%20%5Cbar%7By%7D%29%20%5Cpm%20t_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%5Bn-1%5D%20%5Cfrac%7Bs_d%7D%7B%5Csqrt%7Bn%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \mu_X - \mu_Y &= (\bar{x} - \bar{y}) \pm t_{1 - \frac{\alpha}{2}} [n-1] \frac{s_d}{\sqrt{n}}
                \end{aligned}")\

Where
![s\_d\^2](http://chart.apis.google.com/chart?cht=tx&chl=s_d%5E2 "s_d^2")
is defined as:

\
![\\begin{aligned} s\_d\^2 &= \\sum\_{i=1}\^n \\frac{(d\_i -
\\bar{d})\^2}{n-1} \\\\ \\bar{d} &= \\bar{x} - \\bar{y}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20s_d%5E2%20%26%3D%20%5Csum_%7Bi%3D1%7D%5En%20%5Cfrac%7B%28d_i%20-%20%5Cbar%7Bd%7D%29%5E2%7D%7Bn-1%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cbar%7Bd%7D%20%26%3D%20%5Cbar%7Bx%7D%20-%20%5Cbar%7By%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    s_d^2 &= \sum_{i=1}^n \frac{(d_i - \bar{d})^2}{n-1} \\
                    \bar{d} &= \bar{x} - \bar{y}
                \end{aligned}")\

Confidence Intervals for Independent Observations {#sec:confidence_intervals_for_independent_observations}
-------------------------------------------------

When we observe random variables
![X\_i](http://chart.apis.google.com/chart?cht=tx&chl=X_i "X_i") and
![Y\_i](http://chart.apis.google.com/chart?cht=tx&chl=Y_i "Y_i")
independently
![n\_X](http://chart.apis.google.com/chart?cht=tx&chl=n_X "n_X") and
![n\_Y](http://chart.apis.google.com/chart?cht=tx&chl=n_Y "n_Y") times
each.

Suppose that ![E(X\_i) =
\\mu\_X](http://chart.apis.google.com/chart?cht=tx&chl=E%28X_i%29%20%3D%20%5Cmu_X "E(X_i) = \mu_X"),
![Var(X\_i) =
\\sigma\_X\^2](http://chart.apis.google.com/chart?cht=tx&chl=Var%28X_i%29%20%3D%20%5Csigma_X%5E2 "Var(X_i) = \sigma_X^2"),
![E(Y\_i) =
\\mu\_Y](http://chart.apis.google.com/chart?cht=tx&chl=E%28Y_i%29%20%3D%20%5Cmu_Y "E(Y_i) = \mu_Y"),
and ![Var(Y\_i) =
\\sigma\_Y\^2](http://chart.apis.google.com/chart?cht=tx&chl=Var%28Y_i%29%20%3D%20%5Csigma_Y%5E2 "Var(Y_i) = \sigma_Y^2").

By central limit theorem, the pivotal quantity is (for large
![n\_X](http://chart.apis.google.com/chart?cht=tx&chl=n_X "n_X"),
![n\_Y](http://chart.apis.google.com/chart?cht=tx&chl=n_Y "n_Y")):

\
![\\begin{aligned} Z = \\frac{(\\bar{X} - \\bar{Y}) - (\\mu\_X -
\\mu\_Y)}{\\sqrt{\\frac{\\sigma\_X\^2}{n\_X} +
\\frac{\\sigma\_Y\^2}{n\_Y}}} &\\sim N(0, 1)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20Z%20%3D%20%5Cfrac%7B%28%5Cbar%7BX%7D%20-%20%5Cbar%7BY%7D%29%20-%20%28%5Cmu_X%20-%20%5Cmu_Y%29%7D%7B%5Csqrt%7B%5Cfrac%7B%5Csigma_X%5E2%7D%7Bn_X%7D%20%2B%20%5Cfrac%7B%5Csigma_Y%5E2%7D%7Bn_Y%7D%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%5Csim%20N%280%2C%201%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    Z = \frac{(\bar{X} - \bar{Y}) - (\mu_X - \mu_Y)}{\sqrt{\frac{\sigma_X^2}{n_X} + \frac{\sigma_Y^2}{n_Y}}}
                    &\sim N(0, 1)
                \end{aligned}")\

An approximate ![(1 -
\\alpha)\\%](http://chart.apis.google.com/chart?cht=tx&chl=%281%20-%20%5Calpha%29%5C%25 "(1 - \alpha)\%")
confidence interval for ![\\mu\_X -
\\mu\_Y](http://chart.apis.google.com/chart?cht=tx&chl=%5Cmu_X%20-%20%5Cmu_Y "\mu_X - \mu_Y")
is:

\
![\\begin{aligned} \\mu\_X - \\mu\_Y &= (\\bar{x} - \\bar{y}) \\pm z\_{1
- \\frac{\\alpha}{2}} \\sqrt{\\frac{\\sigma\_X\^2}{n\_X} +
\\frac{\\sigma\_Y\^2}{n\_Y}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmu_X%20-%20%5Cmu_Y%20%26%3D%20%28%5Cbar%7Bx%7D%20-%20%5Cbar%7By%7D%29%20%5Cpm%20z_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%5Csqrt%7B%5Cfrac%7B%5Csigma_X%5E2%7D%7Bn_X%7D%20%2B%20%5Cfrac%7B%5Csigma_Y%5E2%7D%7Bn_Y%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \mu_X - \mu_Y &= (\bar{x} - \bar{y}) \pm z_{1 - \frac{\alpha}{2}} \sqrt{\frac{\sigma_X^2}{n_X} + \frac{\sigma_Y^2}{n_Y}}
                \end{aligned}")\

Summary {#sec:summary}
-------

For ![X\_i \\sim N(\\mu,
\\sigma)](http://chart.apis.google.com/chart?cht=tx&chl=X_i%20%5Csim%20N%28%5Cmu%2C%20%5Csigma%29 "X_i \sim N(\mu, \sigma)"):

\
![\\begin{aligned} \\mu &= \\bar{x} \\pm t\_{1 - \\frac{\\alpha}{2}}
[n-1] \\frac{s}{\\sqrt{n}} \\\\ \\sigma\^2 &= \\left(
\\frac{(n-1)S\^2}{\\chi\_{1-\\frac{\\alpha}{2}}\^2 [n - 1]},
\\frac{(n-1)S\^2}{\\chi\_{\\frac{\\alpha}{2}}\^2 [n - 1]} \\right)
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmu%20%26%3D%20%5Cbar%7Bx%7D%20%5Cpm%20t_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%5Bn-1%5D%20%5Cfrac%7Bs%7D%7B%5Csqrt%7Bn%7D%7D%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Csigma%5E2%20%26%3D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cleft%28%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B%28n-1%29S%5E2%7D%7B%5Cchi_%7B1-%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%5E2%20%5Bn%20-%201%5D%7D%2C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cfrac%7B%28n-1%29S%5E2%7D%7B%5Cchi_%7B%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%5E2%20%5Bn%20-%201%5D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cright%29%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                                        \mu &= \bar{x} \pm t_{1 - \frac{\alpha}{2}} [n-1] \frac{s}{\sqrt{n}} \\
                    \sigma^2 &=
                        \left(
                            \frac{(n-1)S^2}{\chi_{1-\frac{\alpha}{2}}^2 [n - 1]},
                            \frac{(n-1)S^2}{\chi_{\frac{\alpha}{2}}^2 [n - 1]}
                        \right)
                \end{aligned}")\

For ![X\_i \\sim N(\\mu\_X,
\\sigma\^2\_X)](http://chart.apis.google.com/chart?cht=tx&chl=X_i%20%5Csim%20N%28%5Cmu_X%2C%20%5Csigma%5E2_X%29 "X_i \sim N(\mu_X, \sigma^2_X)"),
![Y\_i \\sim N(\\mu\_Y,
\\sigma\^2\_Y)](http://chart.apis.google.com/chart?cht=tx&chl=Y_i%20%5Csim%20N%28%5Cmu_Y%2C%20%5Csigma%5E2_Y%29 "Y_i \sim N(\mu_Y, \sigma^2_Y)"):

Define ![s\_d](http://chart.apis.google.com/chart?cht=tx&chl=s_d "s_d")
as the standard deviation of the difference of two means,

For paired (dependent) observations:

\
![\\begin{aligned} \\mu\_d &= \\mu\_X - \\mu\_Y \\\\ &= (\\bar{x} -
\\bar(y)) \\pm t\_{1 - \\frac{\\alpha}{2}} [n - 1]
\\frac{s\_d}{\\sqrt{n}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmu_d%20%26%3D%20%5Cmu_X%20-%20%5Cmu_Y%20%5C%5C%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%26%3D%20%28%5Cbar%7Bx%7D%20-%20%5Cbar%28y%29%29%20%5Cpm%20t_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%5Bn%20-%201%5D%20%5Cfrac%7Bs_d%7D%7B%5Csqrt%7Bn%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \mu_d &= \mu_X - \mu_Y \\
                    &= (\bar{x} - \bar(y)) \pm t_{1 - \frac{\alpha}{2}} [n - 1] \frac{s_d}{\sqrt{n}}
                \end{aligned}")\

With large sample sizes, we can use the central limit theorem to show
the distribution. We can also estimate the standard error this way.

We can get the approximate ![(1 -
\\alpha)\\%](http://chart.apis.google.com/chart?cht=tx&chl=%281%20-%20%5Calpha%29%5C%25 "(1 - \alpha)\%")
confidence interval for binomial proportions:

\
![\\begin{aligned} \\hat{p} \\pm z\_{1 - \\frac{\\alpha}{2}}
\\sqrt{\\frac{\\hat{p}(1 - \\hat{p})}{n}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Chat%7Bp%7D%20%5Cpm%20z_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%5Csqrt%7B%5Cfrac%7B%5Chat%7Bp%7D%281%20-%20%5Chat%7Bp%7D%29%7D%7Bn%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \hat{p} \pm z_{1 - \frac{\alpha}{2}} \sqrt{\frac{\hat{p}(1 - \hat{p})}{n}}
                \end{aligned}")\

We can get the approximate confidence interval for the difference
between two means:

\
![\\begin{aligned} \\mu\_X - \\mu\_Y &= (\\bar{x} - \\bar{y}) \\pm z\_{1
- \\frac{\\alpha}{2}} \\sqrt{\\frac{S\_X\^2}{n\_X} +
\\frac{S\_Y\^2}{n\_Y}}
\\end{aligned}](http://chart.apis.google.com/chart?cht=tx&chl=%5Cbegin%7Baligned%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cmu_X%20-%20%5Cmu_Y%20%26%3D%20%28%5Cbar%7Bx%7D%20-%20%5Cbar%7By%7D%29%20%5Cpm%20z_%7B1%20-%20%5Cfrac%7B%5Calpha%7D%7B2%7D%7D%20%5Csqrt%7B%5Cfrac%7BS_X%5E2%7D%7Bn_X%7D%20%2B%20%5Cfrac%7BS_Y%5E2%7D%7Bn_Y%7D%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%5Cend%7Baligned%7D "\begin{aligned}
                    \mu_X - \mu_Y &= (\bar{x} - \bar{y}) \pm z_{1 - \frac{\alpha}{2}} \sqrt{\frac{S_X^2}{n_X} + \frac{S_Y^2}{n_Y}}
                \end{aligned}")\

Normal Distribution Table {#cha:normal_distribution_table}
=========================

Chi-Squared Table {#cha:chi_squared_table}
=================

Student-T Reference Table {#cha:student_t_reference_table}
=========================

* * * * *

1.  He assumes knowledge of these geometric series, but it is not
    necessary to know them. ![S\_n = \\sum\_{i=0}\^{n-1} r\^i = \\frac{1
    -
    r\^n}{1-r}](http://chart.apis.google.com/chart?cht=tx&chl=S_n%20%3D%20%5Csum_%7Bi%3D0%7D%5E%7Bn-1%7D%20r%5Ei%20%3D%20%5Cfrac%7B1%20-%20r%5En%7D%7B1-r%7D "S_n = \sum_{i=0}^{n-1} r^i = \frac{1 - r^n}{1-r}")
    It’s not far from this to see that ![\\lim\_{n\\to \\infty} S\_n =
    \\frac{1}{1-r}](http://chart.apis.google.com/chart?cht=tx&chl=%5Clim_%7Bn%5Cto%20%5Cinfty%7D%20S_n%20%3D%20%5Cfrac%7B1%7D%7B1-r%7D "\lim_{n\to \infty} S_n = \frac{1}{1-r}")
    if ![|r| \<
    1](http://chart.apis.google.com/chart?cht=tx&chl=%7Cr%7C%20%3C%201 "|r| < 1").[↩](#fnref1)

2.  We use upper case variable naming to denote random variables, and
    lower case for the observed value.[↩](#fnref2)

3.  This rate
    ![\\lambda](http://chart.apis.google.com/chart?cht=tx&chl=%5Clambda "\lambda")
    can be assumed to be correct.[↩](#fnref3)

4.  This is the case of three failures then a success.[↩](#fnref4)

5.  No, this doesn’t need to be random[↩](#fnref5)

6.  No, this doesn’t need to be random[↩](#fnref6)

7.  This “unwrapping” operation can always be done.[↩](#fnref7)

8.  These seem so arbitrary to me. No reason for the number 5 was
    presented in class.[↩](#fnref8)

9.  We can call these buckets strata.[↩](#fnref9)

10. ![N\_i](http://chart.apis.google.com/chart?cht=tx&chl=N_i "N_i")
    doesn’t need to be the same for all
    ![i](http://chart.apis.google.com/chart?cht=tx&chl=i "i").[↩](#fnref10)

11. As a rule of thumb, this only works for ![n \>
    25](http://chart.apis.google.com/chart?cht=tx&chl=n%20%3E%2025 "n > 25").[↩](#fnref11)

12. My notes say when ![X \\sim
    Bernoulli(p)](http://chart.apis.google.com/chart?cht=tx&chl=X%20%5Csim%20Bernoulli%28p%29 "X \sim Bernoulli(p)")
    as well, which makes sense since Binomial distributions are just
    repeated Bernoulli trials.[↩](#fnref12)

13. Note that we are not talking about
    ![\\sigma\^2](http://chart.apis.google.com/chart?cht=tx&chl=%5Csigma%5E2 "\sigma^2")[↩](#fnref13)
