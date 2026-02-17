# [Platinum IV] Police Station - 15203 

[문제 링크](https://www.acmicpc.net/problem/15203) 

### 성능 요약

메모리: 197208 KB, 시간: 980 ms

### 분류

그래프 이론, 방향 비순환 그래프, 강한 연결 요소

### 제출 일자

2026년 2월 17일 21:43:11

### 문제 설명

<p>A network of hyperspace highways is built in the galaxy. Each of the highways is a one-directional corridor which connects two planets. Galactic government wants to find a planet on which a police station will be built.</p>

<p>In order for the police to protect the whole galaxy, it must be possible to travel from the police station to every planet in the galaxy using the hyperspace highways network.</p>

<p>It is not necessary that the police can return back to the police station from any planet using the hyperspace highways. The police needs not to hurry on the way back, and so they can use slower ways than highways.</p>

<p>The government does not know how to deal with finding the suitable planet for the police station; therefore, they ask for your help</p>

<p>You are given the network of one-directional hyperspace highways. Find all planets from which it is possible to reach all other planets in the galaxy using some sequence of highways.</p>

### 입력 

 <p>The first line of the input contains two integers $N$ a $M$: the number of planets and the number of highways.</p>

<p>Then, $M$ more lines follow. Each contains two integers $A_i$ and $B_i$: the numbers of planets connected by $i$-th highway. Each of the highways is one-directional and can only be used to travel from the planet $A_i$ to the planet $B_i$.</p>

<ul>
	<li>It holds $1 \leq N, M \leq 10^6$.</li>
	<li>For all $i$it holds $1 \leq A_i, B_i \leq N$ and $A_i \neq B_i$.</li>
	<li>No two highways connect equal planets in the same direction. However, they can connect equal planets in the opposite direction.</li>
	<li>Furthermore, in 30 % of the testcases $N \leq 10^3$ and $M \leq 3 \cdot 10^3$.</li>
</ul>

### 출력 

 <p>Output two lines. The first line should contain the total number of planets which are suitable for the police station. The second line should contain a space-separated list of these planets <strong>in ascending order</strong>.</p>

