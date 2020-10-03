# Quelcome (100pts)

When trying to search for something, the web returns error with the link to http://159.65.13.76:65012/graphql.  
So, we can query the schema of the graphql by concatenating ?query={__chema{types{name}}} to the link.  
However, it returns nothing interesting. 

Therefore, the next step is to query for available functions which we can call. Doing this by concatenating ?query={__schema{queryType{fields{name description}}}} to the link.  
The result is this: {"data":{"__schema":{"queryType":{"fields":[{"name":"trueFlag","description":null}]}}}}.  

Hence, if we call the function trueFlag, we can get the flag from server. Using ?query={trueFlag}, we get the result {"data":{"trueFlag":"HCMUS-CTF{quel_done}"}}.

The flag is HCMUS-CTF{quel_done}.