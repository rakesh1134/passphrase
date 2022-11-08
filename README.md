# passphrase
find password phrase hidden in a text file

start reading the file, and when a number is found it points to the next location. the pointer/number is the number of bytes to move(+/-). if the next location starts with a number move (+/-) again and so on. if location does not start with a number the passphrase is found which is a string of 16 chars starting from that location.
