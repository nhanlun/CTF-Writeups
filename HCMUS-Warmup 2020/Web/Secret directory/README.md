# Secret directory
First, we searched for the open port on server http://159.65.13.76/. Then, we found http://159.65.13.76:1338/, which seems odd. So, we assume this is the secret directory. 

Then, we accessed to http://159.65.13.76:1337/robots.txt according to the hint.

We accessed http://159.65.13.76:1337/flagpassword using command curl -H 'Referer:http://159.65.13.76:1338/flagflagflagflag' http://159.65.13.76:1338/flagpassword in the commandline. It returned the username and password to log in to http://159.65.13.76:1338/flagflagflagflag.

The flag is HCMUS-CTF{1t_1zzzz_Crucial_t0_kn0W_Headers_and_R0b0tz}