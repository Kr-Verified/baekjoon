# [Platinum III] Peaceful Comission - 8032 

[문제 링크](https://www.acmicpc.net/problem/8032) 

### 성능 요약

메모리: 3996 KB, 시간: 12 ms

### 분류

2-sat, 그래프 이론, 강한 연결 요소

### 제출 일자

2026년 2월 11일 08:46:09

### 문제 설명

<p>The Public Peace Commission should be legislated in Parliament of The Democratic Republic of Byteland according to The Very Important Law. Unfortunately one of the obstacles is the fact that some deputies do not get on with some others.</p>

<p>The Commission has to fulfill the following conditions:</p>

<ul>
	<li>Each party has exactly one representative in the Commission,</li>
	<li>If two deputies do not like each other, they cannot both belong to the Commission.</li>
</ul>

<p>Each party has exactly two deputies in the Parliament. All of them are numbered from 1 to 2n. Deputies with numbers 2i -1 and 2i belong to the i-th party.</p>

<p>
Write a program, which:</p>

<ul>
	<li>reads from the standard input the number of parties and the pairs of deputies that are not on friendly terms,</li>
	<li>decides whether it is possible to establish the Commission, and if so, proposes the list of members,</li>
	<li>writes the result to the standard output.</li>
</ul>

### 입력 

 <p>In the first line of the standard input there are two non-negative integers n and m. They denote respectively: the number of parties, 1 ≤ n ≤ 8,000, and the number of pairs of deputies, who do not like each other, 0 ≤ m ≤ 20,000. In each of the following m lines there is written one pair of integers a and b, 1 ≤ a < b ≤ 2n, separated by a single space. It means that the deputies a and b do not like each other.</p>

### 출력 

 <p>The standard output should contain one word NIE (means NO in Polish), if the setting up of the Commission is impossible. In case when setting up of the Commission is possible the standard output should contain n integers from the interval from 1 to 2n, written in the ascending order, indicating numbers of deputies who can form the Commission. Each of these numbers should be written in a separate line. If the Commission can be formed in various ways, your program may write any of them.</p>

