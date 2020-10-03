# Square (100pts)

The problem requires us to find the square root of a in modulo p

    p = 1827641252163435127291
    a = 1519062788083583882193

We notice that p = 1 mod 4, we can use Tonelli-Shanks [algorithm](https://www.geeksforgeeks.org/find-square-root-modulo-p-set-2-shanks-tonelli-algorithm/) to find the square root in modulo p. 
However, we can use the online calculator to solve it faster. We use [this site](http://www.numbertheory.org/php/tonelli.html) to get the password for the zip file

    password = 5273332521634010272
    flag = HCMUS-CTF{I_know_you_are_very_good_at_mathematic}
