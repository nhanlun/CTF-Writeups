# InsideMe (100 pts)

First examine EXIF and metadata of the file but to no avail. Then we examine the file using a hex editor and see that after the EOF of the file there is a RAR file. A teammate recommends `binwalk` to extract the file. After extracting the RAR file, we see that there is a PDF file. But a hex editor tells that it is a gif image, not a PDF. Open the file as an image, we get the flag HCMUS-CTF{1t_is_a_s1mpl3_BinWalk}.

