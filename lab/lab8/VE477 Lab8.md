# VE477 Lab8

## Ex.1 

1. Linear programming is to depict the complex relationship in real question to simple linear relationship, and find the optimal solution. It is one of the simplest ways to perform optimization, which is that we have finite resources and time, and want to make the most of them.

2. A delivery man has $x$ packages to deliver in a day, with the warehouse location $A$ and $x$ destination $B_1,B_2,…,B_x$. He need to choose the shortest route to save fuel and time. 

   A manager has a max budget $x$ rmb. He wants to buy several tables and chairs, with the total number as much as possible but the number of table should be larger than the number of chairs. 

3. **Standard Form and Slack Form**

   In standard form, all the constraints are inequalities while the constraints are equalizties in slack form. 

   - **Standard Form**

     - Give $n$ real numbers $c_1,c_2,…,c_n$ and $m$ real numbers $b_1,b_2,…,b_m$ 

       Maximize the objective function 

     $$
     \sum_{j=1}^nc_jx_j
     $$

     ​		with the constraints 
     $$
     \begin{align*}
     \sum_{j=1}^na_{ij}x_j &\leq b_i &\text{for } i=1,2,\dots,m\\
     x_j&\geq0 &\text{for }j=1,2,\dots,n
     \end{align*}
     $$

     - Matrix-vector notation 
       $$
       \begin{align*}
       \text{maximize } & c^Tx \\
       \text{subject to } & \mathcal{A}x\leq b\\
       & x\geq 0
       \end{align*}
       $$

   - **Slack Form** 

     For the inequality constraint $\sum_{j=1}^na_{ij}x_j \leq b_i$, introduce a slack variable $s$ by $s= b_i -\sum_{j=1}^na_{ij}x_j , s\geq 0$ . Denote the slack variable of the $i-$th inequality by $x_{n+i}$

     - Given by a tuple $(N,B,A,b,c,v)$ with all variables non-negative 
       $$
       \begin{align*}
       z&=v+\sum_{j\in N}c_jx_j \\
       x_i&=b_i - \sum_{j\in N}a_{ij}x_j \quad \text{for }i\in B
       \end{align*}
       $$

     - Give $c\in R^n, A\in R^{m\times n}, b\in R^m, G\in R^{r\times n}, h\in R^r$
       $$
       \begin{align*}
       &\mathop{min}_{x}c^Tx \\
       \text{subject to } &Ax=b \\
       & Gx \leq h
       \end{align*}
       $$
       

   **How good are they?**

   Just from the definition, recognize that the reason for a linear programming problem could not fit in a standard form includes:

   - The objective is not maximization but minimization, which could be simply reformated. 
   - The constaints is negative, which could be solved by variable replacement. 
   - Equality constraints, also by variable replacement. 

   So all the LP could be expressed in Standard form. This form is more intuitive and easier to understand. However, the simplex algorithm could be applied to the slack form. 

4. Algorithm: Simplex Algorithm, Ellipsoid Algorithm and Karmarkar’s Algorithm. 

   **Simplex Algorithm** 

   The facts guarantees its correctness:

   - The optimal solution will be at a corner
   - No local maxima 

   The procedures:

   1) Start at some corner

   2) Look at all neiboring corners of the current position

   3) Go to the best one among neighbors if it is better than the current 

   4) Return to step 2) until no better solution than the current one 

5. **What is duality**

   Solve the minimum of original problem will be the same as solve the maximum value of duality of the original problem. Following the slack form introduced before, 
   $$
   \begin{align*}
   \text{Original}:& \quad &\mathop{min}_{x}c^Tx \\
   &\text{subject to} &Ax=b \\
   && Gx \leq h \\[2ex]
   \text{Duality Problem:} & \quad &\mathop{min}_{u,v}(-b^Tu-h^Tv) \\
   &\text{subject to} &-A^Tu-G^Tv=c \\
   && v \geq 0 
   \end{align*}
   $$
   

   **Application:** max flow and min cut 

## Ex.2

### Q1

1. in standard form : Maximize $2x_1-3x_2+3x_3$

   subject to 
   $$
   \begin{cases}
   x_1+x_2-x_3 &\leq 7 \\
   -x_1-x_2+x_3&\leq -7\\
   x_1-2x_2+2x_3&\leq4\\
   x_1,x_2,x_3 &\geq0
   \end{cases}
   $$

2. in slack form, Basic Variables $B=\{4,5,6 \}$. Non-Basic Variables $N=\{1,2,3\}$
   $$
   \begin{cases}
   z&=			2x_1-3x_2+3x_3 \\
   x_4&=7-x_1-x_2+x_3\\
   x_5&=-7+x_1+x_2-x_3 \\
   x_6&=4-x_1+2x_2-2x_3
   \end{cases}
   $$
   

### Q2

- Basic solution for $(\bar{x}_1,\bar{x}_2,\bar{x}_3,\bar{x}_4,\bar{x}_5,\bar{x}_6)$ could be $(0,0,0,30,24,36)$ with objective $0$

- Observe for $x_1$, the last constraint is the tightest. Rewrite the last equation for $x_1$ and substitute in other equations, obtain that 
  $$
  \begin{cases}
  z&=	27+\displaystyle\frac{x_2}{4}	+\frac{x_3}{2} - \frac{3x_6}{4} \\[1.5ex]
  x_1&=9-\displaystyle\frac{x_2}{4}-\frac{x_3}{2}-\frac{x_6}{4} \\[1.5ex]
  x_4&=21- \displaystyle\frac{3x_2}{4} - \frac{5x_3}{2}+\frac{x_6}{4} \\[1.5ex]
  x_5&=\displaystyle 6- \displaystyle\frac{3x_2}{2} - 4x_3+\frac{x_6}{2}
  \end{cases}
  $$
  $(9,0,0,21,6,0)$ with objective value $27$

- $$
  \begin{cases}
  z&=	\displaystyle \frac{111}{4}+\frac{x_2}{16}	-\frac{x_5}{8} - \frac{11x_6}{16} \\[1.5ex]
  x_1&=\displaystyle \frac{33}{4}- \frac{x_2}{16}+\frac{x_5}{8}-\frac{5x_6}{16} \\[1.5ex]
  x_3&= \displaystyle\frac{3}{2}- \frac{3x_2}{8} - \frac{x_5}{4}+\frac{x_6}{8} \\[1.5ex]
  x_4&=\displaystyle \frac{69}{4}+ \frac{3x_2}{16} + \frac{5x_5}{8}-\frac{x_6}{16}
  \end{cases}
  $$

  $(\frac{33}{4},0,\frac{3}{2},\frac{69}{4},0,0)$ with objective value $27.75$

- $$
  \begin{cases}
  z&=	\displaystyle28-\frac{x_3}{6}	-\frac{x_5}{6} +\frac{2x_6}{3} \\[1.5ex]
  x_1&=\displaystyle 8+ \frac{x_3}{6}+\frac{x_5}{6}-\frac{x_6}{3} \\[1.5ex]
  x_2&= \displaystyle4- \frac{8x_3}{3} - \frac{2x_5}{3}+\frac{x_6}{3} \\[1.5ex]
  x_4&=\displaystyle18- \frac{x_3}{2} + \frac{x_5}{2}
  \end{cases}
  $$

  $(8,4,0,18,0,0)$ with objective value $28$

In last iteration, all the coefficients are zero, so we have the optimal solution. Maximum is $28$. 



**Reference** 

https://www.cl.cam.ac.uk/teaching/1617/AdvAlgo/lp.pdf

