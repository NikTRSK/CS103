CSCI 103 Programming Assignment 2, Chroma Key, Fall 2015

Name: Nikica Trajkovsi

Email Address: trajkovs@usc.edu

NOTE: You can delete the questions, we only need your responses.

=============================== Prelab =======================================

Pixel                |    RGB Value     |  Distance from Chroma Key
-------------------------------------------------------------------
Top-left background  | (69 , 140, 20 )  |  n/a
Arm                  | (254, 155, 113)  | 207.6030
Vest                 | (28 , 29 , 24 )  | 118.3976
Shirt                | (251, 216, 248)  | 301.4697

================================== Review ===================================
1. Discuss and justify which pixels you chose to compute the average
background value for method 1. Was there a reason not to choose more or
fewer pixels?

Response 1: I choose the upper left corner. I choose a 50x50 pixel box for the
average. If I were to choose more pixels I would run into the risk of including
pixels that are not green. Through experimentation 50x50 proved to be a good
sample size.

2. For method 1, do some experiments to find the range of distance thresholds
for which the program seems to operate the best. You may use different
thresholds for the two different sample images (Colbert and Bird).
Note: threshold values that are too low will cause certain portions of the
chroma key to stay in the picture; values that are too high will cause parts
of the foreground image to disappear.

Response 2:

  Image                  Min Threshold           Max Threshold
  Colbert range:  from   70              to      76
  Bird range:     from   50              to      71


3. For method 2, explain what you implemented and why.  How did you go about
implementing it? Walk us through a high-level description of what you did in
your code (and use comments in the actual .cpp file to fill in the details).
What other alternatives did you consider either before or after you
implemented your selected method?  What are the relative pros and cons of
these methods? [This question is open-ended!]

Response 3: Initially I looked into seeing if the G value is fixed between the
shades of green. There was however too much variation in the values.
Next, I tried to use the norm (for the vector |RGB|) since it seemed that all the
"greens" will be within this range. However, the result was not what I was hoping
to achieve since the results were highly unpredictable.
Finally while looking at the distances in the assignment documentation, the
threshold values that worked seemed like the statistical concept of standard
deviation. After defining the calculations for the standard deviation I played
around with the sample size to see what will work best. I tried using the
standard deviation for the first 10,15,20,25,30,50 columns as well as the
standard deviation for the whole image. The value of 15 columns seemed to
give the best results. I also tried using a row approach and tried to use a box
(as in method1) but it yielded worse results.

================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

: ~5hrs.

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

: Just figuring out the right approach. I ended up drawing out the problem and
writing out the possible approaches (w/ equations) on paper. That sped up the
development process.

Do you have any other remarks?

: I like how the assignments are starting to get practical (deal with real-world
applications.)
