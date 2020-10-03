# Carveme (228pts)

First, we check the manifest file to see which activity is in this application, we see that only LoginActivity is in the android manifest file.  

In the LoginActivity, we see that the onClickListener call LoginViewModel.login so we move to LoginViewModel.  

Here, we see this login function call LoginRepository.login, hence, we move to LoginRepository.  


This time, the login function call LoginDataSource.login, therefore, we continue to file LoginDataSource.  

Here, the login function call PinChecker.checkPin, so, we move to PinChecker.

Finally, we have something to do. The checkPin function check if the length of the pin is 8 or not, then it performs hash md5 10000 times on that pin to checkl if that is equal to a given hash. If it is equal then this function returns true.

In the login function of LoginDataSource, it calls 2 functions getFirstPart and getSecondPart.  
The getFirstPart contains an encoded base 64 string. Decoding it gives the result HCMUS-CTF{We_found_YOU_  
The getSecondPart query the server our checked pin. So, we have to bruteforce to get the correct pin. The second part of the flag is re@lLy_veee333rY_.  
After that, we find out in the strings.xml a string that is f@bulous_2Up3R_.

Combine all of that result with the extra Secret_@gent} in the LoginDataSource file gives the result HCMUS-CTF{We_found_YOU_re@lLy_veee333rY_f@bulous_2Up3R_Secret_@gent}.

The flag is HCMUS-CTF{We_found_YOU_re@lLy_veee333rY_f@bulous_2Up3R_Secret_@gent}.