# [Platinum IV] Agents - 8106 

[문제 링크](https://www.acmicpc.net/problem/8106) 

### 성능 요약

메모리: 2556 KB, 시간: 8 ms

### 분류

그래프 이론, 그리디 알고리즘, 강한 연결 요소

### 제출 일자

2026년 1월 28일 21:06:27

### 문제 설명

<p>The country is overwhelmed by agents from foreign secret services. Not only do they steal secret information, but also spy on each other. We say that an agent A unmasked an agent B, if A collected sufficient documents to arrest an agent B.</p>

<p>Some agents take bribes — for the certain amount of money they are ready to hand over all the documents they have. So when we buy certain agents, we may initiate a chain of arrests (if we arrest an agent we take all his documents) which will lead to a liquidation of all the agents in the country.</p>

<p>Our home counterintelligence provided us with the number of foreign agents in the country, the information who and at what price may be corrupted, as well as what agents unmasked whom. The number of agents is equal to n ≤ 3,000; and they have numbers from 1 to n.</p>

<p>Write a program which:</p>

<ul>
	<li>reads from the standard input information provided by counterintelligence,</li>
	<li>verifies, whether it is possible to initiate a chain of arrests that will lead to a liquidation of all the agents in the country by corrupting some of the agents, and if its possible computes the minimal cost of such corrupting, otherwise finds a number of any agent that cannot be arrested or corrupted,</li>
	<li>writes the result into the standard output.</li>
</ul>

### 입력 

 <p>In the first line of the standard input there is written one integer n. This is the number of all the agents operating in the country, 1 ≤ n ≤ 3,000. In the second line there is written one integer p. This is the number of agents who take bribes, 1 ≤ p ≤ n. In each of the following p lines there are written two integers. The first is the number of an agent and the second is the smallest amount of money he would accept as a bribe — it is not grater then 20,000.</p>

<p>The next line contains one integer r, 1 ≤ r ≤ 8,000. This is the number of pairs (A, B), such that the agent A unmasked the agent B. In the following r lines there are written all these pairs. In each of these lines there are written two different positive integers from the set {1, 2, ..., n} separated by a single space. The first of them is the number of an agent who unmasked another agent, and the second one is the number of an agent that was unmasked.</p>

### 출력 

 <p>In the first line of the standard output there should be written one word: <code>TAK</code> (which means “yes” in Polish) — if it is possible to arrest all the agents operating in the country; or <code>NIE</code> (“no” in Polish) — if otherwise. The second line should contain one positive integer: the minimal cost of corrupting agents whose documents may initiate a chain of arrests that will lead to a liquidation of all the agents in the country, or the number of the agent that cannot be arrested or corrupted. If there are more than one such agent, print the one with the smallest number.</p>

