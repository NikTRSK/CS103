CSCI 103 Programming Assignment 1, Hailstone, Spring 2015

Name: Nikica Trajkovski

Email Address: trajkovs@usc.edu

NOTE: You can delete the questions, we only need your responses.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

: none.

================================ Questions ==================================

1. Which kind of a loop did you use for the first program? Why?

: I used a while loop, mainly because the loop was supposed to execute until
the condition was true, and I didn't need to use a counter (hence not a
for loop.)

2a. Once you've completed the second program, run hailstats on the following
inputs, and record your results in the table below:

  input range  | minimum length | achieved by | maximum length | achieved by
-----------------------------------------------------------------------------
    50 100     |       6        |      64     |       118      |      97       
   100 200     |       7        |     128     |       124      |     171        
   200 400     |       8        |     256     |       143      |     327        

2b. What pattern do you think there is in the values achieving minimum length?
Can you explain why it holds?

: Minimum lenght is achieved by numbers that are 2^n. It holds because the
algorithm divides even numbers by two and 2^n / 2 is always even (before 
reaching 1.) 

3a. Let X be the smallest integer whose length is greater than 150.
By running your hailstats program several times on carefully chosen inputs,
determine what is the value of X.

X is : 703

3b. Explain, briefly, the way in which you used your hailstats program
(i.e., which inputs you gave it) to find this answer.

:First I knew that the number was greater thatn 400. So I first checked the range
400-600 and then 600-800, which gave the largest lenght of 170. This was the range
that I was looking for. 600-700 gave max lenght of 144, so I checked 700-800. Then,
I searched 700-750 which gave the max lenght for the number 703. I ran another range
(700-702) to make sure that there isn't a smaller number than 703.

================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

: ~ 1 - 1.5 hours.

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

: no.

Do you have any other remarks?

: no.