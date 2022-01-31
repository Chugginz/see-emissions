import socket

 

#hostName    = "example.org"
hostName    = raw_input("Host name:")

 

ipAddress   = socket.gethostbyname(hostName)

print("IP address of the host name {} is: {}".format(hostName, ipAddress))
