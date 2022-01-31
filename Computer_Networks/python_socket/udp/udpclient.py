###############
# python udpclient.py 
# usage: python udpclient.py <IP address> <Port number>
##############

import socket
import sys


if (len(sys.argv) < 3): 
    print('usage: python udpclient.py <IP address> <Port number>')
    sys.exit()
# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = (sys.argv[1], int(sys.argv[2]))
userinput = raw_input("Message: ")
message = userinput

try:

    # Send data
    sent = sock.sendto(message, server_address)

    # Receive response
    data, server = sock.recvfrom(4096)
    print >>sys.stderr, 'Received: %s' % data

finally:
    print >>sys.stderr, 'closing socket'
    sock.close()
