# State the problme before desribing the solution

Transcript:https://www.microsoft.com/en-us/research/uploads/prod/2016/12/State-the-Problem-Before-Describing-the-Solution.pdf


After several years of writing papers in computer siences, I discovered the basic
expository rule embodied in the title of this note. As obvious as this rule may 
seem, there are fields in which it is seldom obseved. (computer networking is
one example) A typical paper in such a field is organized as follows:
1. A brief informal statement of the problem.
2. the solution
3. A statement and proof of the precise correctness properties satisfied by
the solution.

In order to abide by the rule, the following organization sould instead be
used:

1. A brief informal statement of the problem.
2. the precise correctness conditions required of a solution
3. the solution
4. A proof that the solution satisfies the requisite contitions.

Although it may not be obvious at first glance, there is a profound
difference between these two approaches. In the first, the precise correctness
contitions can be (and usually are) stated in terms of the solution itself.
Some results are proved about the solution, but it is often not clear 
exaclty what problem is being solved. This makes the comparison of two
different solutions rather difficult. With the second approach, one is 
forced to specify the precise problem to be solved independently of the 
menthod used in the solution. This can be a surprisingly difficult and 
enlightening task. It has on several occasions led me to discover that a 
"correct" algorithm did not really accomplish what I wanted it to. I strongly
urge everyone to obseve the rule.

(I am ignoring as unworthy of consideration the disturbingly large number 
of papers that never even attempt a precise statement of what problem they
are solving.
